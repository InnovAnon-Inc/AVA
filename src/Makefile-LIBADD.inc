# TODO nova
LIBAVA_LIBADD  = -lnova
include $(top_srcdir)/ezparse/src/Makefile-LIBADD.inc
LIBAVA_LIBADD += ../ezparse/src/.libs/libezparse.la $(LIBEZPARSE_LIBADD)
include $(top_srcdir)/restart/src/Makefile-LIBADD.inc
LIBAVA_LIBADD += ../restart/src/.libs/librestart.la $(LIBRESTART_LIBADD)
