//
// Created by zz on 2021/8/23.
//

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// handler 用来处理接收到的信号
void handler() {
    printf("[parent] receive a SIGINT signal, finish the process!\n");
    exit(0);
}

int main() {
    int pid;

    pid = fork();
    if (pid < 0) {
        printf("fork error!");
        return 0;
    }
    if (pid == 0) { // child
        printf("[child] process id: %d, parent id: %d \n", getpid(), getppid());
        sleep(5);   // 睡眠 5 秒
        // 使用 kill 函数向指定的进程发送一个信号
        // 这里向父进程发送一个 SIGINT 信号
        kill(getppid(), SIGINT);
        printf("[child] send a SIGINT signal\n");
    } else {    // parent
        printf("[parent] process id: %d \n", getpid());
        printf("[parent] wait signal... \n");
        // 注册一个信号处理函数，当捕获到 SIGINT 时，调用 handler 进行处理
        (void) signal(SIGINT, handler);
    }
    sleep(10);  // 等待父子进程执行完毕
}