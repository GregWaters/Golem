# Simple makefile, not intended to be too terribly efficient

all:
	$(CXX) src/*.cpp -O3 -flto $(shell pkg-config.exe gmpxx --cflags --libs) -o golem
	./golem
