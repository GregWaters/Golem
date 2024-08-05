$(shell mkdir -p bin)

release:
	$(CC) src/*.c -O2 -o bin/golem

debug:
	$(CC) src/*.c -Og -g -o bin/golem