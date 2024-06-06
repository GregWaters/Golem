# Simple makefile, not intended to be too terribly efficient

all:
	$(CXX) src/*.cpp -I include -O2 -o golem
