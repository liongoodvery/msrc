include ../Makefile.inc


LDLIBS += ${IMPL_LDLIBS} -lpthread
GEN_EXE=server

EXE=${GEN_EXE}

all : ${EXE}

allgen : ${GEN_EXE}

clean:
	${RM} ${EXE} *.o


${EXE}:
