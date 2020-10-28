#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

void * mandp(int size) {
  void* ret = mm_malloc(size);
  fprintf(stderr, "Malloc'd pointer of size %d at %p\n", size, ret);
  return ret;
}

int main() {
  void * malloc_ptr;
  void *ptr, *ptr2, *ptr3, *ptr4;
  malloc_ptr = malloc(1024);
  mem_init();
  ptr = mandp(sizeof(int) * 4);
  memset(ptr,'A',4*sizeof(int));
  ptr2 = mandp(5 * sizeof(int));
  memset(ptr2,'B',5*sizeof(int));
  ptr3 = mandp(6 * sizeof(int));
  memset(ptr3,'C',6*sizeof(int));
  mm_free(ptr2);
  ptr4 = mandp(2 * sizeof(int));
  memset(ptr4,'D',2*sizeof(int));
  return 0;
}