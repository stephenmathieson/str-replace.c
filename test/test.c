
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "str-replace.h"
#include "describe.h"

int main() {
  describe("str-replace", {
    it("should replace single matches", {
      assert_str_equal("goodbye world",
           str_replace("hello world", "hello", "goodbye"));
    });
    it("should replace multiple matches", {
      char small[] = "She lived in a small house "
                     "with a small garage on the "
                     "outskirts of a small city.";
      char big[] = "She lived in a big house with "
                   "a big garage on the outskirts "
                   "of a big city.";

      assert_str_equal(small, str_replace(big, "big", "small"));
    });
    it("should return a copy of the string when provided no matches", {
      char str[] = "hello world";
      char *replaced = str_replace(str, "foo", "bar");
      assert_str_equal(str, replaced);
      str[1] = 'z';
      assert_str_not_equal(str, replaced);
    });
  });
  return assert_failures();
}
