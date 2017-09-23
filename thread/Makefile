include ../Makefile.inc

GEN_EXE=Sample \
        Test \
        thread1

LDLIBS+=-lpthread
EXE=${GEN_EXE}

all : ${EXE}

allgen : ${GEN_EXE}

clean:
	${RM} ${EXE} *.o


${EXE}:
