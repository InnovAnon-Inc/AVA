AM_CPPFLAGS = -D__STDC_INT64__

#include Makefile-LIBADD.inc
dist_bin_SCRIPTS = libava_config ava_config

lib_LTLIBRARIES =
bin_PROGRAM     =

lib_LTLIBRARIES += libava.la
include_HEADERS = ava.h
libava_la_LIBADD = @LIBAVA_LIBADD@

bin_PROGRAMS += ava
#ava_LDADD = libava.la $(LIBAVA_LIBADD)
ava_LDADD = @AVA_LIBADD@
EXTRA_ava_DEPENDENCIES = libava.la
