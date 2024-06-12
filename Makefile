all:
	mkdir -p bin/
	$(CXX) src/*.c -Iinclude -O2 -o bin/golem
