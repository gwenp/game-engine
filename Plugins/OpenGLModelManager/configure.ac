#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE(OpenGLModelManager, 1.0, gwenael.pluchon@gmail.com)
AC_CONFIG_SRCDIR([src/OpenGLModelManager.cpp])
AC_CONFIG_HEADERS([config.h])

CXXFLAGS=-g -Wall -pedantic

# Checks for programs.
AC_PROG_CXX([clang++ gcc])
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_CPP
AC_PROG_RANLIB

# Checks for libraries.
AC_CHECK_HEADERS(GL/gl.h GL/glu.h,,
         [AC_CHECK_HEADERS(OpenGL/gl.h OpenGL/glu.h,,
           [echo "OpenGL is mandatory";exit 1])]
)

PKG_CHECK_MODULES([GL], [gl])
PKG_CHECK_MODULES([GLEW], [glew])
PKG_CHECK_MODULES([GLFW], [libglfw])
PKG_CHECK_MODULES([ASSIMP], [assimp])
PKG_CHECK_MODULES([IMAGEMAGICK], [ImageMagick++])

PKG_CHECK_MODULES([LIBSIGC], [sigc++-2.0])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

#AM_SILENT_RULES([yes])

AC_CONFIG_FILES(Makefile)

AC_OUTPUT
