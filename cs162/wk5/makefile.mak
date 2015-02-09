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

PROGS = wk5_1, wk5_2, wk5_3

#target: dependencies
# rule to build 
#

all: ${PROGS}

wk5_1: wk5_1.cpp
	${CXX} ${CXXFLAGS} wk5_1.cpp -o wk5_1
	
wk5_2: wk5_2.cpp
	${CXX} ${CXXFLAGS} wk5_2.cpp -o wk5_2

wk5_3: wk5_3.cpp
	${CXX} ${CXXFLAGS} wk5_3.cpp -o wk5_3	

clean: 
	rm -f ${PROGS} *.o *~
