
CXX = clang++

GEN_EXE=Sample \
        initializer \
        forloop \
        rawstring \
        lambda \
        pair \
        fileio \
        sharedptr \
        vector \
        deque \
        array \
        list \
        set \
        map \
        algo1 \
        algo2 \
        iterator

IMPL_CFLAGS = -std=c++11 \
		-g \
		-Werror \
        -Wall
CPPFLAGS =${IMPL_CFLAGS}

EXE=${GEN_EXE}

all : ${EXE}

allgen : ${GEN_EXE}

clean:
	${RM} ${EXE} *.o core

copy:
	@./copy.sh



${EXE}:
