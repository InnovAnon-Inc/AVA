#include $(top_srcdir)/ezparse/src/Makefile-LIBADD.inc
#include $(top_srcdir)/restart/src/Makefile-LIBADD.inc
include ../../ezparse/src/Makefile-LIBADD.inc
include ../../restart/src/Makefile-LIBADD.inc

# TODO nova
LIBAVA_LIBADD  = -lnova

#if USE_SUBMODULES
#LIBAVA_LIBADD += ../ezparse/src/.libs/libezparse.la $(LIBEZPARSE_LIBADD)
#LIBAVA_LIBADD += ../restart/src/.libs/librestart.la $(LIBRESTART_LIBADD)
#else
LIBAVA_LIBADD += -lezparse $(LIBEZPARSE_LIBADD)
LIBAVA_LIBADD += -lrestart $(LIBRESTART_LIBADD)
#endif
