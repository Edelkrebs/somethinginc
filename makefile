SOURCES := $(wildcard src/*.c) $(wildcard src/**/*.c) $(wildcard src/**/**/*.c)

run:
	gcc -o pong $(SOURCES)
	./pong