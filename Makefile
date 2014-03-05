
SRC  = $(wildcard src/*.c)
SRC += $(wildcard deps/*/*.c)
OBJS = $(SRC:.c=.o)
CFLAGS  = -std=c99 -Ideps -Isrc
CFLAGS += -Wall -Wextra

test: test-replace
	./test-replace

test-replace: test/test.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o test-replace

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm -f test-replace test/test.o $(OBJS)

.PHONY: clean test
