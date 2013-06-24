#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE(cpp-plugin-system,0.1,http://www.anim-it.net)

AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX([clang++ gcc])
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([dl], [dlerror])
PKG_CHECK_MODULES([LIBSIGC], [sigc++-2.0])

# Checks for header files.
AC_CHECK_HEADERS(GL/gl.h GL/glu.h,,
         [AC_CHECK_HEADERS(OpenGL/gl.h OpenGL/glu.h,,
           [echo "OpenGL is mandatory";exit 1])]
)

# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

# Manage plugins build
AC_ARG_ENABLE([plugins],
    [AS_HELP_STRING([--disable-plugins], [Compile Core only])],
    [enable_plugins=$enableval],
    [enable_plugins=yes])

if test "$enable_plugins" = "yes"; then

	AC_CONFIG_SUBDIRS([ Plugins/ExtensionLoader
						Plugins/TestPlugin
						Plugins/LuaScriptingPlugin])
    AC_MSG_RESULT( --- Plugin compilation enabled --- )
else
	AC_MSG_RESULT( --- Plugin compilation disabled --- )
fi

AM_SILENT_RULES([yes])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
