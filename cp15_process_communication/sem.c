//
// Created by zz on 2021/8/24.
//

// 使用信号量
#include <semaphore.h>  // 废弃
#include <sys/sem.h>
#include <errno.h>
#include <stdio.h>
#include <strings.h>

int main() {
    // sem_init(); 该方法已废弃

    // int semget(key_t key, int nsems, int semflg);
    // semget 函数用于创建或打开一个信号量集
    //
    // key:信号量键值，可以理解为信号量的唯一性标记。
    // num_sems:信号量的数目，一般为1
    // sem_flags:有两个值，IPC_CREATE和IPC_EXCL，
    // IPC_CREATE表示若信号量已存在，返回该信号量标识符。
    // IPC_EXCL表示若信号量已存在，返回错误。
    //
    // 返回值：相应的信号量标识符，失败返回-1
    int sem_id = semget(IPC_PRIVATE, 1, 0666);
    if (sem_id < 0) {
        fprintf(stderr, "semget error: %s \n", strerror(errno));
        return 0;
    }
    printf("semget successful, sem_id: %d \n", sem_id);


}