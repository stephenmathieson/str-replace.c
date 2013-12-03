
SRC = $(wildcard src/*.c)
SRC += $(wildcard deps/*.c)

test: test.c $(SRC)
	$(CC) -std=c99 $^ -o $@ -Ideps -Isrc
	./test

.PHONY: test
