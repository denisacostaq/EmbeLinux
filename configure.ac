#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#configure.ac
AC_PREREQ([2.69])
AC_INIT([hello-libtool],[0.0.2], [denisacostaq@gmail.com], [hello_libtool], [http://embelinux.blogspot.com/2013/])
AM_INIT_AUTOMAKE([1.10.1])


AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

LT_INIT

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET


# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([
	Makefile
	lib/Makefile
	headers/Makefile
	lib/libmatX.pc])

AC_OUTPUT
