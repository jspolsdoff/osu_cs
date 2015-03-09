CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++0x $(DEBUG)
PROGS = final
OUTPUTS = 
OBJS = room.o sub.o main.o

all: $(PROGS)

$(PROGS): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS): $(@:.o=.cpp)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	$(RM) $(PROGS) $(OBJS) $(OUTPUTS)
