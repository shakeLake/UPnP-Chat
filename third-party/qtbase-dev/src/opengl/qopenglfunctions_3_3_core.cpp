// Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB)
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
/***************************************************************************
** This file was generated by glgen version 0.1
** Command line was: glgen
**
** glgen is Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB)
**
** This is an auto-generated file.
** Do not edit! All changes made to it will be lost.
**
****************************************************************************/

#include "qopenglfunctions_3_3_core.h"
#include "qopenglcontext.h"

QT_BEGIN_NAMESPACE

/*!
    \class QOpenGLFunctions_3_3_Core
    \inmodule QtOpenGL
    \since 5.1
    \wrapper
    \brief The QOpenGLFunctions_3_3_Core class provides all functions for OpenGL 3.3 core profile.

    This class is a wrapper for functions from OpenGL 3.3 core profile.
    See reference pages on \l {http://www.opengl.org/sdk/docs/}{opengl.org}
    for function documentation.

    \sa QAbstractOpenGLFunctions
*/

QOpenGLFunctions_3_3_Core::QOpenGLFunctions_3_3_Core()
 : QAbstractOpenGLFunctions()
 , d_1_0_Core(nullptr)
 , d_1_1_Core(nullptr)
 , d_1_2_Core(nullptr)
 , d_1_3_Core(nullptr)
 , d_1_4_Core(nullptr)
 , d_1_5_Core(nullptr)
 , d_2_0_Core(nullptr)
 , d_2_1_Core(nullptr)
 , d_3_0_Core(nullptr)
 , d_3_1_Core(nullptr)
 , d_3_2_Core(nullptr)
 , d_3_3_Core(nullptr)
{
}

QOpenGLFunctions_3_3_Core::~QOpenGLFunctions_3_3_Core()
{
    if (d_1_0_Core) {
        d_1_0_Core->refs.deref();
        Q_ASSERT(d_1_0_Core->refs.loadRelaxed());
    }
    if (d_1_1_Core) {
        d_1_1_Core->refs.deref();
        Q_ASSERT(d_1_1_Core->refs.loadRelaxed());
    }
    if (d_1_2_Core) {
        d_1_2_Core->refs.deref();
        Q_ASSERT(d_1_2_Core->refs.loadRelaxed());
    }
    if (d_1_3_Core) {
        d_1_3_Core->refs.deref();
        Q_ASSERT(d_1_3_Core->refs.loadRelaxed());
    }
    if (d_1_4_Core) {
        d_1_4_Core->refs.deref();
        Q_ASSERT(d_1_4_Core->refs.loadRelaxed());
    }
    if (d_1_5_Core) {
        d_1_5_Core->refs.deref();
        Q_ASSERT(d_1_5_Core->refs.loadRelaxed());
    }
    if (d_2_0_Core) {
        d_2_0_Core->refs.deref();
        Q_ASSERT(d_2_0_Core->refs.loadRelaxed());
    }
    if (d_2_1_Core) {
        d_2_1_Core->refs.deref();
        Q_ASSERT(d_2_1_Core->refs.loadRelaxed());
    }
    if (d_3_0_Core) {
        d_3_0_Core->refs.deref();
        Q_ASSERT(d_3_0_Core->refs.loadRelaxed());
    }
    if (d_3_1_Core) {
        d_3_1_Core->refs.deref();
        Q_ASSERT(d_3_1_Core->refs.loadRelaxed());
    }
    if (d_3_2_Core) {
        d_3_2_Core->refs.deref();
        Q_ASSERT(d_3_2_Core->refs.loadRelaxed());
    }
    if (d_3_3_Core) {
        d_3_3_Core->refs.deref();
        Q_ASSERT(d_3_3_Core->refs.loadRelaxed());
    }
}

bool QOpenGLFunctions_3_3_Core::initializeOpenGLFunctions()
{
    if ( isInitialized() )
        return true;

    QOpenGLContext* context = QOpenGLContext::currentContext();

    // If owned by a context object make sure it is current.
    // Also check that current context is capable of resolving all needed functions
    if (((owningContext() && owningContext() == context) || !owningContext())
        && QOpenGLFunctions_3_3_Core::isContextCompatible(context))
    {
        // Associate with private implementation, creating if necessary
        // Function pointers in the backends are resolved at creation time
        QOpenGLVersionFunctionsBackend* d = nullptr;
        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_1_0_CoreBackend::versionStatus());
        d_1_0_Core = static_cast<QOpenGLFunctions_1_0_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_1_1_CoreBackend::versionStatus());
        d_1_1_Core = static_cast<QOpenGLFunctions_1_1_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_1_2_CoreBackend::versionStatus());
        d_1_2_Core = static_cast<QOpenGLFunctions_1_2_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_1_3_CoreBackend::versionStatus());
        d_1_3_Core = static_cast<QOpenGLFunctions_1_3_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_1_4_CoreBackend::versionStatus());
        d_1_4_Core = static_cast<QOpenGLFunctions_1_4_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_1_5_CoreBackend::versionStatus());
        d_1_5_Core = static_cast<QOpenGLFunctions_1_5_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_2_0_CoreBackend::versionStatus());
        d_2_0_Core = static_cast<QOpenGLFunctions_2_0_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_2_1_CoreBackend::versionStatus());
        d_2_1_Core = static_cast<QOpenGLFunctions_2_1_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_3_0_CoreBackend::versionStatus());
        d_3_0_Core = static_cast<QOpenGLFunctions_3_0_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_3_1_CoreBackend::versionStatus());
        d_3_1_Core = static_cast<QOpenGLFunctions_3_1_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_3_2_CoreBackend::versionStatus());
        d_3_2_Core = static_cast<QOpenGLFunctions_3_2_CoreBackend*>(d);
        d->refs.ref();

        d = QAbstractOpenGLFunctionsPrivate::functionsBackend(context, QOpenGLFunctions_3_3_CoreBackend::versionStatus());
        d_3_3_Core = static_cast<QOpenGLFunctions_3_3_CoreBackend*>(d);
        d->refs.ref();

        QAbstractOpenGLFunctions::initializeOpenGLFunctions();
    }
    return isInitialized();
}

bool QOpenGLFunctions_3_3_Core::isContextCompatible(QOpenGLContext *context)
{
    Q_ASSERT(context);
    QSurfaceFormat f = context->format();
    const QPair<int, int> v = qMakePair(f.majorVersion(), f.minorVersion());
    if (v < qMakePair(3, 3))
        return false;

    return true;
}

QOpenGLVersionProfile QOpenGLFunctions_3_3_Core::versionProfile()
{
    QOpenGLVersionProfile v;
    v.setVersion(3, 3);
    v.setProfile(QSurfaceFormat::CoreProfile);
    return v;
}

QT_END_NAMESPACE
