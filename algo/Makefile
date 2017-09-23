include ../Makefile.inc

GEN_EXE=listTest

CFLAGS+=-I./include

EXE=${GEN_EXE}

all : ${EXE}

allgen : ${GEN_EXE}

clean:
	${RM} ${EXE} *.o


listTest: list.o

test:${EXE}
	./listTest
${EXE}:
