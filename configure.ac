AC_INIT([libOMX_Core], [1.0.0], [ddompe@gmail.com])
AM_INIT_AUTOMAKE([1.11 foreign])

AM_SILENT_RULES([yes])

AC_PROG_CC
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

# Initialize libtool
LT_PREREQ([2.2])
LT_INIT([disable-static])

AC_ARG_VAR([EZSDKDIR], [path for the ezsdk location])
AC_ARG_WITH(ezsdkdir,
    [AS_HELP_STRING([--with-ezsdkdir=<path>],
        [Set the path for the ezsdk])],
    [AC_MSG_NOTICE([Setting the ezsdkdir "$withval"])
     AC_SUBST([EZSDKDIR],[$withval])
    ]
)

if test -z $EZSDKDIR ; then
  AC_MSG_ERROR([you need to provide the path for the EZSDK installation dir!])
fi

if ! test -f $EZSDKDIR/Rules.make ; then
  AC_MSG_ERROR([Can not find Rules.make in the EZSDK installation directory provided ($EZSDKDIR/Rules.make)])
fi

# Find out what version of OMX components we have
OMXVERSION=`basename $EZSDKDIR/component-sources/omx_* | sed "s/omx_//"`
AC_SUBST(OMXVERSION,$OMXVERSION)

AC_CONFIG_FILES([Makefile libOMX_Core.pc])
AC_OUTPUT
