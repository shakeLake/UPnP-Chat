// Copyright (C) 2022 Intel Corporation.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QNATIVEIPCKEY_H
#define QNATIVEIPCKEY_H

#include <QtCore/qglobal.h>
#include <QtCore/qtcore-config.h>

#if QT_CONFIG(sharedmemory) || QT_CONFIG(systemsemaphore)
#  include <QtCore/qstring.h>
#  include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QNativeIpcKeyPrivate;
class QNativeIpcKey
{
    Q_GADGET_EXPORT(Q_CORE_EXPORT)
public:
    enum class Type : quint16 {
        // 0 is reserved for the invalid type
        // keep 1 through 0xff free, except for SystemV
        SystemV = 0x51,         // 'Q'

        PosixRealtime = 0x100,
        Windows,
    };
    Q_ENUM(Type)

    static constexpr Type DefaultTypeForOs =
#ifdef Q_OS_WIN
            Type::Windows
#else
            Type::PosixRealtime
#endif
            ;
    static Type legacyDefaultTypeForOs() noexcept;

    explicit constexpr QNativeIpcKey(Type type = DefaultTypeForOs) noexcept
        : d()
    {
        typeAndFlags.type = type;
    }

    Q_IMPLICIT QNativeIpcKey(const QString &k, Type type = DefaultTypeForOs)
        : d(), key(k)
    {
        typeAndFlags.type = type;
    }

    QNativeIpcKey(const QNativeIpcKey &other)
        : d(other.d), key(other.key)
    {
        if (isSlowPath())
            copy_internal(other);
    }

    QNativeIpcKey(QNativeIpcKey &&other) noexcept
        : d(other.d), key(std::move(other.key))
    {
        if (isSlowPath())
            move_internal(std::move(other));
    }

    ~QNativeIpcKey()
    {
        if (isSlowPath())
            destroy_internal();
    }

    QNativeIpcKey &operator=(const QNativeIpcKey &other)
    {
        if (isSlowPath() || other.isSlowPath())
            return assign_internal(other);
        d = other.d;
        key = other.key;
        return *this;
    }

    QT_MOVE_ASSIGNMENT_OPERATOR_IMPL_VIA_PURE_SWAP(QNativeIpcKey)
    void swap(QNativeIpcKey &other)
    {
        qt_ptr_swap(d, other.d);
        key.swap(other.key);
    }

    bool isEmpty() const
    {
        return key.isEmpty();
    }

    bool isValid() const
    {
        return type() != Type{};
    }

    constexpr Type type() const noexcept
    {
        if (isSlowPath())
            return type_internal();
        return typeAndFlags.type;
    }

    constexpr void setType(Type type)
    {
        if (isSlowPath())
            return setType_internal(type);
        typeAndFlags.type = type;
    }

    QString nativeKey() const noexcept
    { return key; }
    void setNativeKey(const QString &newKey)
    { key = newKey; }

    Q_CORE_EXPORT QString toString() const;
    Q_CORE_EXPORT static QNativeIpcKey fromString(const QString &string);

private:
    struct TypeAndFlags {
        quint16 isExtended : 1;
        Type type : 15;
        quint16 reserved;
    };

    // Bit 0: if set, holds a pointer (with the LSB set); if clear, holds the
    // the TypeAndFlags structure.
    union {
        QNativeIpcKeyPrivate *d = nullptr;
        TypeAndFlags typeAndFlags;
        static_assert(sizeof(typeAndFlags) <= sizeof(d));
    };

    QString key;

    constexpr bool isSlowPath() const noexcept
    { return Q_UNLIKELY(typeAndFlags.isExtended); }

    friend bool operator==(const QNativeIpcKey &lhs, const QNativeIpcKey &rhs) noexcept
    {
        if (lhs.key != rhs.key)
            return false;
        if (lhs.d == rhs.d)
            return true;
        if (lhs.isSlowPath() && rhs.isSlowPath())
            return compare_internal(lhs, rhs) == 0;
        return lhs.d == rhs.d;
    }
    friend bool operator!=(const QNativeIpcKey &lhs, const QNativeIpcKey &rhs) noexcept
    {
        return !(lhs == rhs);
    }

    Q_CORE_EXPORT void copy_internal(const QNativeIpcKey &other);
    Q_CORE_EXPORT void move_internal(QNativeIpcKey &&other) noexcept;
    Q_CORE_EXPORT QNativeIpcKey &assign_internal(const QNativeIpcKey &other);
    Q_CORE_EXPORT void destroy_internal() noexcept;
    Q_DECL_PURE_FUNCTION Q_CORE_EXPORT Type type_internal() const noexcept;
    Q_CORE_EXPORT void setType_internal(Type);
    Q_DECL_PURE_FUNCTION Q_CORE_EXPORT static int
    compare_internal(const QNativeIpcKey &lhs, const QNativeIpcKey &rhs) noexcept;

#ifdef Q_OS_DARWIN
    Q_DECL_CONST_FUNCTION Q_CORE_EXPORT static Type defaultTypeForOs_internal() noexcept;
#endif
};

// not a shared type, exactly, but this works too
Q_DECLARE_SHARED(QNativeIpcKey)

inline auto QNativeIpcKey::legacyDefaultTypeForOs() noexcept -> Type
{
#if defined(Q_OS_WIN)
    return Type::Windows;
#elif defined(QT_POSIX_IPC)
    return Type::PosixRealtime;
#elif defined(Q_OS_DARWIN)
    return defaultTypeForOs_internal();
#else
    return Type::SystemV;
#endif
}

#endif // QT_CONFIG(sharedmemory) || QT_CONFIG(systemsemaphore)

QT_END_NAMESPACE

#endif // QNATIVEIPCKEY_H
