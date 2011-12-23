libOMX library for DM81xx SoC by RidgeRun

The EZSDK provides OMX components in non Linux-friendly format for autotools
or others, so this library takes the components from the EZSDK and creates
and easy to use library with Linux standards (we even provide a pkgconfig file).

You require to patch your EZSDK with the files in the patches directory. These are
small changes that ensure that your libraries will build correctly against the
library when using the flags from the pkgconfig file.

To build all you need to do is to pass the following arguments:
  --with-ezsdkdir to configure the location of the ezsdk directory
  --with-platform to configure which platform to build for (ti814x-evm or ti816x-evm)

This library always target the latest EZSDK, for older EZSDK releases see the
corresponding branch.
