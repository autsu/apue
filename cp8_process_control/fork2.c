//
// Created by zz on 2021/3/26.
//

// 仅用来做 fork 的一些测试，备注未必正确

#include "../lib/apue.h"

void test() {
    int n = 123;
    char *hl = "qweqwr";
    pid_t pid;

    // 只会输出一次
    printf("in\n");

    // 子父进程执行顺序不一定，可能父先也可能子先
    if ( (pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {     // 父进程
        printf("parent running...\n");
        printf("parent n: %d, h1: %s\n", n, hl);
        printf("=========================\n");
    } else if (pid > 0) {   // 子进程
        // 子进程会在创建处接着执行，不会回到函数的首行，比如第 15 行的 printf 只会输出一次
        // 子进程会共享父进程的一部分空间 TODO （哪些部分？）
        n = 555;
        printf("child running...\n");
        printf("child n: %d, hl: %s\n", n, hl);
        printf("=========================\n");
    }
    // 子进程对变量所做的改变并不影响父进程中该变量的值
    printf("final n: %d\n", n);
}

int main() {
    test();
}