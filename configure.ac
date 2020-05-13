AC_INIT([libava], [0.0], [laurence.a.maddox@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])

AC_ARG_ENABLE([use-submodules],
    AS_HELP_STRING([--enable-use-submodules], [Enable use submodules]))
AM_CONDITIONAL([USE_SUBMODULES], [test x"$enable_use_submodules" = "xyes"])

AC_CONFIG_MACRO_DIR([m4])
# TODO add libnova
#AC_CONFIG_SUBDIRS([glitter ezparse])

AC_CHECK_HEADERS([stdlib.h string.h time.h])
AC_CHECK_HEADERS([math.h])
#AC_CHECK_HEADERS([watdefs.h,lunar.h,date.h,afuncs.h,riseset3.h])
AC_CHECK_HEADERS([glitter.h])

AC_CHECK_LIB([stdlib],[free,memcpy,memset])
AC_CHECK_LIB([math],[fmod])
#AC_CHECK_LIB([lunar],[look_for_rise_set,fill_planet_data,load_file_into_memory])

#srcdir = @srcdir@
#LIBAVA_LIBADD="`PATH=$(srcdir)src:$PATH libava_config --libs`"
LIBAVA_LIBADD="`PATH=src:$PATH libava_config --libs`"
AC_SUBST(LIBAVA_LIBADD)

#AVA_LIBADD="`PATH=$(srcdir)src:$PATH ava_config --libs`"
AVA_LIBADD="`PATH=src:$PATH ava_config --libs`"
AC_SUBST(AVA_LIBADD)

INNOVANON_WARNINGS([])

AC_OUTPUT
