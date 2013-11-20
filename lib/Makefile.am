#src/Makefile.am
CLEANFILES = *~ *.pc

AM_CPPFLAGS = -I$(top_builddir)/headers

pkgconfigdir = @libdir@/pkgconfig
pkgconfig_DATA = libmatX.pc

lib_LTLIBRARIES = libmatX.la
libmatX_la_SOURCES = \
		matX.cc

libmatX_la_LDFLAGS = -release @VERSION@
