CC = /bin/g++

OUTPUT_BIN=./bin

IMPL_CFLAGS = -g \
		-Wall \
		 -I/usr/local/include/ \


LDFLAGS = -L/usr/local/lib

LDLIBS = -lpthread\
		 -lopencv_highgui \
		 -lopencv_core \
		-lopencv_imgcodecs \
		 -lopencv_imgproc \
		 -lopencv_videoio \
		 -lopencv_video \
		 -lopencv_videostab 


CFLAGS = ${IMPL_CFLAGS}

CXXFLAGS= ${CFLAGS}

GEN_EXE = example_02-08 \
    example_02-03 \
    example_02-02 \
    example_02-11 \
    example_02-10 \
    example_02-06 \
    example_02-05 \
    example_02-04 \
    example_02-07 \
    example_02-01 \
    example_02-09 \



EXE=${GEN_EXE}
all : ${EXE}
	mv ${GEN_EXE} ${OUTPUT_BIN}

allgen : ${GEN_EXE}

clean:
	${RM} ${EXE} *.o


${EXE}:
