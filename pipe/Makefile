include ../Makefile.inc

GEN_EXE=Sample \
		Test \
		fifoserver \
		fifoclient \
		pipe \
		pipe_in_out

EXE=${GEN_EXE}

all : ${EXE}

allgen : ${GEN_EXE}

clean:
	${RM} ${EXE} *.o fifo


${EXE}:
