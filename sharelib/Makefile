include ../Makefile.inc

LIBSRC=math.c
LIBOBJ=$(LIBSRC:.c=.o)
SOFILE=libmath.so

GEN_EXE=Sample Test

EXE=${GEN_EXE}

all : ${EXE}

allgen : ${GEN_EXE}

clean:
	${RM} ${EXE} *.o *.so


lib:math.o
	$(CC) -g  -o $(SOFILE) -shared $(LIBOBJ) 

Test:
	$(CC) -g -o Test  -L. -lmath Test.c

math.o:${LIBSRC}
	$(CC) -g -fPIC -o $(LIBOBJ) -c $(LIBSRC) 
${EXE}:


