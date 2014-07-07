CXX?=g++
CXXFLAGS?=-Wall -Wextra -Werror -pedantic -std=c++11
CPPFLAGS=-MMD -I src/includes/
LDFLAGES=
BIN?=flat_set
SRC=src/main.cc
LIB=flat_set.so
OBJ=${SRC:.cc=.o}
OBJFPIC=$(SRC:.cc=.o.fpic)
DEP=${OBJ:.o=.d}
TAR=flat_set.tar.bz2
-include makefile.rules

all : ${BIN}

$(BIN) : ${OBJ}
	${CXX} ${CXXFLAGS} -o $@  $^

$(LIB) : $(OBJFPIC)
	${CXX} -shared -o $@ $^

check : ${BIN}
	./tests/tests.sh

%.o.fpic : %.cc
	${CXX} $(CXXFLAGS) -o $@ -c $< -fPIC

export:
	git archive HEAD --prefix=$(TAR)/ | bzip2 > $(TAR)

clean:
	rm -f ${DEP} ${OBJ} ${BIN} ${OBJFPIC} ${LIB}

distclean:
	rm -f "makefile.rules" ${TAR} ${DEP} ${OBJ} ${BIN} ${OBJFPIC} ${LIB}

.PHONY : clean
-include ${DEP}
