CXX = g++ 
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors 
CXXFLAGS += -g 
#CXXFLAGS += -O3 
LDFLAGS = -lboost_date_time

OBJS = f.o g.o lab1-2.o

SRCS = f.cpp g.cpp lab1-2.cpp

HEADERS = f.h g.h

PROGS = lab1-2 pointers

#target: dependencies
# rule to build 
#

all: ${PROGS}

lab1-2: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o lab1-2

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

pointers: pointers.cpp
	${CXX} ${CXXFLAGS} pointers.cpp -o pointers

clean: 
	rm -f ${PROGS} *.o *~
