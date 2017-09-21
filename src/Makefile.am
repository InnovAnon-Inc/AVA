lib_LTLIBRARIES = libava.la
libava_la_SOURCES = ava.c
include_HEADERS = ava.h
#libava_la_CFLAGS =
#libava_la_LDFLAGS = -lnova -lezparse -lm -lrestart
libava_la_LIBADD = -lnova -lezparse -lm -lrestart

bin_PROGRAMS = ava

ava_SOURCES = main.c
ava_LDFLAGS = -lnova -lezparse -lm -lrestart
ava_LDADD = libava.la
#ava_CFLAGS =

AM_CPPFLAGS = -D__STDC_INT64__
