AC_INIT([libava], [0.0], [laurence.a.maddox@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])
AC_CONFIG_MACRO_DIR([m4])

AC_CHECK_HEADERS([stdlib.h string.h time.h])
AC_CHECK_HEADERS([math.h])
#AC_CHECK_HEADERS([watdefs.h,lunar.h,date.h,afuncs.h,riseset3.h])
AC_CHECK_HEADERS([glitter.h])

AC_CHECK_LIB([stdlib],[free,memcpy,memset])
AC_CHECK_LIB([math],[fmod])
#AC_CHECK_LIB([lunar],[look_for_rise_set,fill_planet_data,load_file_into_memory])

INNOVANON_WARNINGS([])

AC_OUTPUT
