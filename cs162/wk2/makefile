CXX = g++ 
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors 
CXXFLAGS += -g 
#CXXFLAGS += -O3 
LDFLAGS = -lboost_date_time

OBJS = 

SRCS = 

HEADERS = 

PROGS = life

#target: dependencies
# rule to build 
#

all: ${PROGS}

life: life.cpp
	${CXX} ${CXXFLAGS} life.cpp -o life

clean: 
	rm -f ${PROGS} *.o *~
