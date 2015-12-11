AC_INIT([ops-switchd], [1.0], [bug@foo.org])

AC_CHECK_HEADERS([stdlib.h ltdl.h])
AC_SEARCH_LIBS([lt_dlopen], [ltdl])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 utilities/Makefile
])
AM_INIT_AUTOMAKE([tar-pax])

AC_PROG_CC_C99
AM_PROG_CC_C_O
AC_PROG_CPP
AC_PROG_MKDIR_P
AC_PROG_FGREP
AC_PROG_EGREP

AC_ARG_VAR([PERL], [path to Perl interpreter])
AC_PATH_PROG([PERL], perl, no)
if test "$PERL" = no; then
   AC_MSG_ERROR([Perl interpreter not found in $PATH or $PERL.])
fi

AM_MISSING_PROG([AUTOM4TE], [autom4te])

#AC_USE_SYSTEM_EXTENSIONS
AC_C_BIGENDIAN
AC_SYS_LARGEFILE

LT_INIT([dlopen disable-shared])
LT_CONFIG_LTDL_DIR([libltdl])
LTDL_INIT([installable])

m4_pattern_forbid([LT_INIT]) dnl Make autoconf fail if libtool is missing.

AC_OUTPUT
