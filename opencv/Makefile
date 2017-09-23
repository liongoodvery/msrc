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

GEN_EXE =  e0201 \
	e0203



EXE=${GEN_EXE}
all : ${EXE}
	mv ${GEN_EXE} ${OUTPUT_BIN}

allgen : ${GEN_EXE}

clean:
	${RM} ${EXE} *.o


${EXE}:
