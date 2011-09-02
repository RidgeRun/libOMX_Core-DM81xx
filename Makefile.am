include @EZSDKDIR@/Rules.make

lib_LTLIBRARIES = libOMX_Core.la
libOMX_Core_la_SOURCES= dummy.c
libOMX_Core_la_LIBADD= -lstdc++ -lm -lrt
libOMX_Core_la_LDFLAGS = -version-info 1:0:0 \
-Wl,--fix-cortex-a8 -Wl,--no-undefined -Wl,-u,OMX_Init -Wl,-u,OMX_Deinit \
-Wl,-u,OMX_ComponentNameEnum -Wl,-u,OMX_GetHandle -Wl,-u,OMX_FreeHandle \
-Wl,-u,OMX_GetRolesOfComponent -pthread -Wl,linker.script

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libOMX_Core.pc

EXTRA_DIST = libOMX_Core.pc.in linker.script.in

BUILT_SOURCES = linker.script

linker.script: $(srcdir)/linker.script.in
	sed -e "s?@OMX_INSTALL_DIR@?$(OMX_INSTALL_DIR)?" \
	    -e "s?@OSAL_INSTALL_DIR@?$(OSAL_INSTALL_DIR)?" \
	    -e "s?@SYSLINK_INSTALL_DIR@?$(SYSLINK_INSTALL_DIR)?" \
	    -e "s?@FC_INSTALL_DIR@?$(FC_INSTALL_DIR)?" \
	    -e "s?@UIA_INSTALL_DIR@?$(UIA_INSTALL_DIR)?" \
	    -e "s?@LINUXUTILS_INSTALL_DIR@?$(LINUXUTILS_INSTALL_DIR)?" \
	    $< > $@

clean-local:
	rm -f linker.script
