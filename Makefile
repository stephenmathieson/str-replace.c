
SRC     = $(wildcard src/*.c)
SRC    += $(wildcard deps/*/*.c)
CFLAGS  = -std=c99 -Ideps -Isrc
CFLAGS += -Wall -Wextra

test-replace: test/test.c $(SRC)
	$(CC) $(CFLAGS) $^ -o test-replace
	./test-replace

clean:
	rm -f test-replace

.PHONY: clean
