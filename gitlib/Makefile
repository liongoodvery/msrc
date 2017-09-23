include ../Makefile.inc

LDFLAGS += -L/home/lion/lib

CFLAGS+= -I/home/lion/git/libgit2/include
GEN_EXE=Test \
		git_clone

LDLIBS += -lgit2 -lz
EXE=${GEN_EXE}

all : ${EXE}

allgen : ${GEN_EXE}

clean:
	${RM} ${EXE} *.o


${EXE}:
