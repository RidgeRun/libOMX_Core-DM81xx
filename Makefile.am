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

BUILT_SOURCES = linker.script libOMX_Core.pc

linker.script: $(srcdir)/linker.script.in
	sed -e "s?@OMX_INSTALL_DIR@?$(OMX_INSTALL_DIR)?" \
	    -e "s?@OSAL_INSTALL_DIR@?$(OSAL_INSTALL_DIR)?" \
	    -e "s?@SYSLINK_INSTALL_DIR@?$(SYSLINK_INSTALL_DIR)?" \
	    -e "s?@FC_INSTALL_DIR@?$(FC_INSTALL_DIR)?" \
	    -e "s?@UIA_INSTALL_DIR@?$(UIA_INSTALL_DIR)?" \
	    -e "s?@LINUXUTILS_INSTALL_DIR@?$(LINUXUTILS_INSTALL_DIR)?" \
	    -e "s?@PLATFORM@?$(TARGETPLATFORM)?" \
	    $< > $@

libOMX_Core.pc: $(srcdir)/libOMX_Core.pc.in
	sed -e "s?@&prefix@?@prefix@?" \
	    -e "s?@&exec_prefix@?@exec_prefix@?" \
	    -e "s?@&libdir@?@libdir@?" \
	    -e "s?@&VERSION@?@VERSION@?" \
	    -e "s?@&OMXVERSION@?@OMXVERSION@?" \
	    -e "s?@OMX_INSTALL_DIR@?$(OMX_INSTALL_DIR)?" \
	    -e "s?@CE_INSTALL_DIR@?$(CE_INSTALL_DIR)?" \
	    -e "s?@FC_INSTALL_DIR@?$(FC_INSTALL_DIR)?" \
	    -e "s?@XDAIS_INSTALL_DIR@?$(XDAIS_INSTALL_DIR)?" \
	    -e "s?@XDC_INSTALL_DIR@?$(XDC_INSTALL_DIR)?" \
	    -e "s?@SYSLINK_INSTALL_DIR@?$(SYSLINK_INSTALL_DIR)?" \
	    -e "s?@KERNEL_INSTALL_DIR@?$(KERNEL_INSTALL_DIR)?g" \
	    $< > $@

clean-local:
	rm -f linker.script
