
//
// str-replace.c
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#include <stdlib.h>
#include <string.h>
#include "str-copy.h"
#include "str-replace.h"

/*
 * Replace all occurances of `sub` with `replace` in `str`
 */

char *str_replace(char *str, char *sub, char *replace) {
  char *pos = str;
  int occurrences = 0;

  // find all occurrences
  while ((pos = strstr(pos, sub))) {
    pos += strlen(sub);
    occurrences++;
  }

  if (occurrences == 0) {
    char *result = str_copy(str);
    return result;
  }

  int size = (
        strlen(str)
      - (strlen(sub) * occurrences)
      + strlen(replace) * occurrences
    ) + 1;

  char *result = (char *) malloc(size);
  if (NULL == result) return NULL;
  pos = str;
  char *current;
  while ((current = strstr(pos, sub))) {
    int len = current - pos;
    strncat(result, pos, len);
    strncat(result, replace, strlen(replace));
    pos = current + strlen(sub);
  }

  if (pos != (str + strlen(str))) {
    strncat(result, pos, (str - pos));
  }

  return result;
}
