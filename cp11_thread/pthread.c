//
// Created by zz on 2021/3/6.
//

#include "../lib/apue.h"
#include <pthread.h>

pthread_t ntid;

void printids(const char *s) {
    pid_t pid;  // 进程 id
    pthread_t tid;  // 线程 id

    pid = getpid(); // 获取进程 id
    tid = pthread_self(); // 获取线程 id
    printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long )pid,
           (unsigned long )tid, (unsigned long )tid);

}

void *thr_fn(void *args) {
    printids("new thread: ");
    return (void*)0;
}

int main() {
    int err;

    //
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
}
