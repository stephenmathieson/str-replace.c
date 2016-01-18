
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "str-replace.h"
#include "describe/describe.h"

int
main() {
  describe("str_replace") {
    it("should replace single matches") {
      char *replaced = str_replace("hello world", "hello", "goodbye");
      assert_str_equal("goodbye world", replaced);
      free(replaced);
    }

    it("should replace multiple matches") {
      char small[] = "She lived in a small house "
                     "with a small garage on the "
                     "outskirts of a small city.";
      char big[] = "She lived in a big house with "
                   "a big garage on the outskirts "
                   "of a big city.";
      char *replaced = str_replace(big, "big", "small");
      assert_str_equal(small, replaced);
      free(replaced);
    }

    it("should return a copy of the string when provided no matches") {
      char str[] = "hello world";
      char *replaced = str_replace(str, "foo", "bar");
      assert_str_equal(str, replaced);
      str[1] = 'z';
      assert_str_not_equal(str, replaced);
      free(replaced);
    }
  }

  return assert_failures();
}
