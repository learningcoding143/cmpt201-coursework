#define _POSIX_C_SOURCE 200809L
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_SIZE 1024
struct header {
  uint64_t size;
  struct header *next;
};
void *sbrk(intptr_t increment);

void print_out(char *format, void *data, size_t data_size);

void print_out(char *format, void *data, size_t data_size) {
  char buf[BUF_SIZE];
  ssize_t len = snprintf(buf, BUF_SIZE, format,
                         data_size == sizeof(uint64_t) ? *(uint64_t *)data
                                                       : *(void **)data);
  if (len < 0) {
    perror("snprintf");
  }
  write(STDOUT_FILENO, buf, len);
};

int main() {
  uint64_t size = 128;
  uint64_t size_full = 256;
  void *current = sbrk(0);

  void *heap = sbrk(size_full);

  printf("%p\n", current);

  // declare blocks
  struct header *myblock = (struct header *)current;
  struct header *myblock2 = (struct header *)current + size;

  // initialize blocks
  myblock->size = size;
  myblock->next = NULL;

  myblock2->size = size;
  myblock2->next = myblock;

  char *data1 = (char *)myblock + sizeof(struct header);
  size_t data_size = size_full - sizeof(struct header);
  memset(data1, 0, data_size);

  char *data2 = (char *)myblock2 + sizeof(struct header);

  memset(data2, 1, data_size);

  print_out("First  Block:              %p\n", current, sizeof(current));
  print_out("Second Block:              %p\n", heap, sizeof(heap));
  print_out("First  Block Size:         %d\n", &size, sizeof(&size));
  print_out("First  Block next:         %p\n", myblock->next,
            sizeof(myblock->next));
  print_out("Second Block Size:         %d\n", &size, sizeof(&size));
  print_out("Second Block next:         %p\n", myblock2->next,
            sizeof(myblock->next));

  for (int i = 0; i < size; i++) {

    print_out("%d\n", myblock[i], sizeof(myblock[i]));
  }

  for (int i = 0; i < size; i++) {

    print_out("%d\n", myblock2[i], sizeof(myblock[i]));
  }
}
