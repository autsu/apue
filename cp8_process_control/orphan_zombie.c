//
// Created by zz on 2021/3/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

// 孤儿进程和僵尸进程

// 孤儿进程 demo1
void orphan() {
    pid_t pid;

    if ( (pid = fork()) < 0) {
        perror("fork error");
        exit(1);
    }

    if (pid == 0) {     // 子进程
        printf("当前执行的是子进程\n");
        // 输出子进程 pid 和父进程的 pid
        // Output: pid: 16930 ppid: 16929
        printf("pid: %d ppid: %d\n", getpid(), getppid());
        printf("5s 后成为 孤儿进程\n");
        // 睡眠 5s 保证父进程先退出，成为孤儿进程
        sleep(5);
        // Output: pid: 16930 ppid: 1
        // 此时 ppid 为 1，即 init 进程，代表已经被收养了
        printf("pid: %d ppid: %d\n", getpid(), getppid());
        printf("子进程结束\n");
    } else {    // 父进程
        printf("当前执行的是父进程\n");
        // 父进程睡眠1s，保证子进程输出进程id
        sleep(1);
        printf("父进程结束\n");
    }
    exit(0);
}

// 僵尸进程 demo1
void zombie1() {
    pid_t pid;

    if ( (pid = fork()) < 0) {
        perror("fork error");
        exit(1);
    } else if (pid == 0) {
        printf("child process run.\n");
        printf("child process exit.\n");
        exit(0);    // 子进程先退出，成为僵尸进程
    } else {
        printf("parent process run.\n");
        printf("parent process sleep 5s.\n");
        sleep(5);   // 等待子进程先退出
        system("ps -o pid,ppid,state,tty,command"); // 输出进程信息
        // Output:
        // PID    PPID STAT TTY      COMMAND
        // 31881 31880 Z+   ttys012  (orphan_zombie)
        // Z+ 代表僵尸进程
        printf("parent process exit.\n");
    }
}

void zombie2() {
    pid_t pid;

    // 循环 fork，造成多个僵尸进程
    // Output:
    // PID    PPID STAT TTY      COMMAND
    // 33794 33793 Z+   ttys012  (orphan_zombie)
    // 33827 33793 Z+   ttys012  (orphan_zombie)
    // 33861 33793 Z+   ttys012  (orphan_zombie)
    while (1) {
        if ( (pid = fork()) < 0) {
            perror("fork error");
            exit(1);
        } else if (pid == 0) {
            printf("child process run.\n");
            printf("child process exit.\n");
            exit(0);    // 子进程先退出，成为僵尸进程
        } else {
            // 父进程休眠20s继续创建子进程
            sleep(20);
            continue;
        }
    }
    exit(0);
}

void deal_zombie_by_signal() {
    
}

int main() {
    //orphan();
    //zombie1();
    zombie2();
}
