CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++0x $(DEBUG)
PROGS = lab10
OUTPUTS = 
OBJS = FibonacciNR.o FibonacciR.o lab10.o

all: $(PROGS)

$(PROGS): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS): $(@:.o=.cpp)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	$(RM) $(PROGS) $(OBJS) $(OUTPUTS)
