//
// Created by zz on 2021/3/5.
//

#include "../lib/apue.h"

void pipe_t() {
    int fp[2];
    // pipe()：创建一个管道，经由参数 fd 返回两个文件描述符，fp[0] 为读打开，fp[1] 为写打开
    int err = pipe(fp);
    // 成功返回 0，失败返回 -1
    err == 0 ? printf("ok") : printf("create pipe error");
}

// 通过管道，从父进程传输数据到子进程
void parent_to_child_pipe() {
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) < 0) {
        err_sys("pipe error");
    }
    if ( (pid = fork()) < 0 ) {
        err_sys("fork error");
    } else if (pid > 0) {   // 父进程
        close(fd[0]);    // 因为是 父 -> 子，所以关闭
    }
}

int main() {

}

