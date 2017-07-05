# Makefile.inc - common definitions used by all makefiles

LINUX_LIBRT = -lrt
LINUX_LIBDL = -ldl
LINUX_LIBACL = -lacl
LINUX_LIBCRYPT = -lcrypt
LINUX_LIBCAP = -lcap

IMPL_CFLAGS = -std=c99 -D_XOPEN_SOURCE=600 \
		-g \
		-pedantic \
		-Wall \

GNU_CFLAGS = -std=gnu99 -D_XOPEN_SOURCE=600 \
		-g \
		-pedantic \
		-Wall \
		-D_GNU_SOURCE

# link apue library
IMPL_LDLIBS = -lapue -lm

LDLIBS = ${IMPL_LDLIBS}


CFLAGS = ${IMPL_CFLAGS}



RM = rm -f