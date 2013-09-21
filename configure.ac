#configure.ac
AC_PREREQ([2.69])
AC_INIT([hola-mundo],[0.0.1], [denisacostaq@gmail.com], [hola_mundo], [http://embelinux.blogspot.de/2013/09/autotools1-hola-mundo-la-autotools.html])
AM_INIT_AUTOMAKE([1.10.1])


AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INTLTOOL([0.50.2-2])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([locale.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

# i18n
#--------------------------
GETTEXT_PACKAGE=hola-mundo
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE",[The gettext package])
ALL_LINGUAS="es fr"
AM_GLIB_GNU_GETTEXT

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	po/Makefile.in])

AC_OUTPUT
