#include "common.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void* s21_safe_malloc(size_t size) {
  void* ptr = malloc(size);
  if (ptr) memset(ptr, 0, size);
  return ptr;
}
