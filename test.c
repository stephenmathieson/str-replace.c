
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "src/str-replace.h"


void test_single_match() {
  assert(0 == strcmp("goodbye world",
    str_replace("hello world", "hello", "goodbye"))
  );
}

void test_no_matches() {
  assert(0 == strcmp("hello world",
    str_replace("hello world", "foo", "bar"))
  );
}

void test_multiple_matches() {
  assert(0 ==
    strcmp("She lived in a small house with a small garage on the outskirts of a small city.",
      str_replace("She lived in a big house with a big garage on the outskirts of a big city.",
                  "big",
                  "small")
    )
  );
}

void test_null_str() {
  assert(NULL == str_replace(NULL, "foo", "bar"));
}

int main(int argc, char **argv) {
  test_single_match();
  test_no_matches();
  test_multiple_matches();

  return 0;
}
