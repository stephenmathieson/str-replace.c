
SRC = $(wildcard src/*.c)
SRC += $(wildcard deps/*.c)

test: test/test.c $(SRC)
	$(CC) -std=c99 $^ -o test-replace -Ideps -Isrc
	./test-replace

.PHONY: test
