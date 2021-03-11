//
// Created by zz on 2021/3/6.
//

#include "../lib/apue.h"

//    Output:
//          ./fork
//          a write to stdout
//          before fork
//          pid = 14206, glob = 7, var = 89
//          pid = 14205, glob = 6, var = 88
//
//          ./fork > temp.out
//          cat temp.out
//          a write to stdout
//          before fork
//          pid = 14781, glob = 7, var = 89
//          before fork
//          pid = 14780, glob = 6, var = 88
//
//    执行 ./fork 时，printf() 连接的是终端设备 stdout，是行缓冲的，当遇到换行符时
//    就会被冲洗，所以 before fork 只会输出一次
//
//    执行 ./fork > temp.out 是重定向方式，此时的 printf() 是全缓冲的，不会被冲洗，
//    会保存在缓冲区中，当 fork 创建子进程时，将父进程数据空间（包括缓冲区）复制到子进程，
//    也就是说，父子进程的缓冲区中都有一份 "before fork"，所以最后的重定向文件中会有两
//    个 before fork


int globvar = 6;     // 初始化数据中的外部变量
char buf[] = "a write to stdout\n";

int main() {
    int var;    // 栈上的变量
    pid_t pid;

    var = 88;
    // write() 是不带缓冲的，所以尽管有两个进程，但只会在 stdout 输出一次
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1) {
        err_sys("write error");
    }
    printf("before fork\n");

    // 子进程和父进程会继续执行 fork 调用后的指令
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    // 通过 pid 的返回值，辨识是子进程还是父进程，并通过条件判断执行各自的任务
    } else if (pid == 0) {        // fork 返回 0 说明是子进程
        globvar++;               // 修改变量
        var++;
    } else {                    // fork 返回大于 0 说明是父进程
        sleep(2);   // 这是父进程的任务
    }

    // Output:
    // pid = 14206, glob = 7, var = 89 （子进程）
    // pid = 14205, glob = 6, var = 88 （父进程）
    // 子进程中的修改不会影响父进程的数据（写时复制）
    printf("pid = %ld, glob = %d, var = %d\n", (long) getpid(), globvar, var);
    exit(0);
}

