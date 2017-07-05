DIRS=test \
	fileio \
	process \
	sharelib \
	pipe \
	shm \
	signal \
	tools \
	thread

all: 	
	@ for dir in ${DIRS}; do (cd $${dir}; ${MAKE}) ; done

allgen: 
	@ for dir in ${DIRS}; do (cd $${dir}; ${MAKE} allgen) ; done

clean: 
	@ for dir in ${DIRS}; do (cd $${dir}; ${MAKE} clean) ; done
