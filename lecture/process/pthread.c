#include <pthread.h>
#include <stdio.h>
#include <string.h>
void *thread(void *arg) {

  char *message = (char *)arg;
  printf("inside thread\n");
  printf("Message is: %s\n", message);
  return (void *)strlen(message);

  return NULL;
}
int main() {
  pthread_t thread_id;

  pthread_create(&thread_id, NULL, thread, "Hello World");

  void *ans;
  pthread_join(thread_id, &ans);
  long long len = (long long)ans;
  printf("pthread answer is %lld.\n", len);
}
