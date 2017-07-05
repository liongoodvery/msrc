include ../Makefile.inc

GEN_EXE=Sample Test
GUN_EXE= readfile
EXE=${GEN_EXE} ${GUN_EXE}



all : ${EXE}

allgen : ${GEN_EXE}

clean:
	${RM} ${EXE} *.o


${EXE}:
readfile.o:
	$(CC) ${GNU_CFLAGS} -o readfile.o -c readfile.c
