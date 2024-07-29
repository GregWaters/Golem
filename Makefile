all:
	mkdir -p bin/
	$(CC) src/*.c -O2 -o bin/golem
