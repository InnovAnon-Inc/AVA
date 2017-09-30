AM_CPPFLAGS = -D__STDC_INT64__

SUBDIRS = ../glitter
AM_CPPFLAGS += -I ../glitter/src

SUBDIRS += ../ezparse
AM_CPPFLAGS += -I ../ezparse/src

LIBAVA_LIBADD  = -lnova
LIBAVA_LIBADD += ../ezparse/src/.libs/libezparse.la $(LIBEZPARSE_LIBADD)
LIBAVA_LIBADD += ../restart/src/.libs/librestart.la $(LIBRESTART_LIBADD)

lib_LTLIBRARIES = libava.la
include_HEADERS = ava.h
libava_la_LIBADD = $(LIBAVA_LIBADD)

bin_PROGRAMS = ava

ava_SOURCES = main.c
ava_LDADD = libava.la $(LIBAVA_LIBADD)
