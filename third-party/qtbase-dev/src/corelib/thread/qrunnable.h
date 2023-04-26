// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QRUNNABLE_H
#define QRUNNABLE_H

#include <QtCore/qglobal.h>
#include <functional>
#include <type_traits>

QT_BEGIN_NAMESPACE

class Q_CORE_EXPORT QRunnable
{
    bool m_autoDelete = true;

    Q_DISABLE_COPY(QRunnable)
public:
    virtual void run() = 0;

    constexpr QRunnable() noexcept = default;
    virtual ~QRunnable();
#if QT_CORE_REMOVED_SINCE(6, 6)
    static QRunnable *create(std::function<void()> functionToRun);
#endif
    template <typename Callable>
    static QRunnable *create(Callable &&functionToRun);
    bool autoDelete() const { return m_autoDelete; }
    void setAutoDelete(bool autoDelete) { m_autoDelete = autoDelete; }

protected:
    // Type erasure, to only instantiate a non-virtual class per Callable:
    class QGenericRunnableHelperBase
    {
        using OpFn = void(*)(const QGenericRunnableHelperBase *);
        OpFn runFn;
        OpFn destroyFn;
    protected:
        constexpr explicit QGenericRunnableHelperBase(OpFn fn, OpFn del) noexcept : runFn(fn), destroyFn(del) {}
        ~QGenericRunnableHelperBase() = default;
    public:
        void run() { runFn(this); }
        void destroy() { destroyFn(this); }
    };

    template <typename Callable>
    class QGenericRunnableHelper : public QGenericRunnableHelperBase
    {
        Callable m_functionToRun;
    public:
        template <typename UniCallable>
        QGenericRunnableHelper(UniCallable &&functionToRun) noexcept :
              QGenericRunnableHelperBase(
                      [](const QGenericRunnableHelperBase *that) { static_cast<const QGenericRunnableHelper*>(that)->m_functionToRun(); },
                      [](const QGenericRunnableHelperBase *that) { delete static_cast<const QGenericRunnableHelper*>(that); }),
              m_functionToRun(std::forward<UniCallable>(functionToRun))
        {
        }
    };
};

class QGenericRunnable : public QRunnable
{
    QGenericRunnableHelperBase *runHelper;
public:
    QGenericRunnable(QGenericRunnableHelperBase *runner) noexcept: runHelper(runner)
    {
    }
    ~QGenericRunnable() override
    {
        runHelper->destroy();
    }
    void run() override
    {
        runHelper->run();
    }
};

template <typename Callable>
QRunnable *QRunnable::create(Callable &&functionToRun)
{
    return new QGenericRunnable(
            new QGenericRunnableHelper<std::decay_t<Callable>>(
                    std::forward<Callable>(functionToRun)));
}

QT_END_NAMESPACE

#endif
