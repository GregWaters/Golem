all:
	mkdir -p bin/
	$(CC) src/*.c -Iinclude -O2 -o bin/golem
