
SRC = $(wildcard src/*.c)
SRC += $(wildcard deps/*.c)

test: test/test.c $(SRC)
	$(CC) -std=c99 $^ -o test-replace -Ideps -Isrc -Wall
	./test-replace

.PHONY: test
