
#include <pthread.h>

static void *func(void *arg) { pthread_exit(0); }
pthread_mutex_t lockA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lockB = PTHREAD_MUTEX_INITIALIZER;
int main(int argc, char *argv[]) {

  pthread_t t1;
  pthread_t t2;
  pthread_mutex_lock(&lockA);
  pthread_create(&t1, NULL, func, NULL);

  pthread_join(t1, NULL);
}
