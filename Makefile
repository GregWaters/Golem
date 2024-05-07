# Simple makefile, not intended to be too terribly efficient

all:
	$(CXX) src/*.cpp -I include -O3 -flto $(shell pkg-config.exe gmpxx --cflags --libs) -o golem

profile:
	$(CXX) src/*.cpp -pg -I include -O3 -flto $(shell pkg-config.exe gmpxx --cflags --libs) -o golem
	./golem