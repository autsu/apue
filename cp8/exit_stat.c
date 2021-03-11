//
// Created by zz on 2021/3/11.
//

#include "../lib/apue.h"
#include <sys/wait.h>

//

// 使用宏打印进程终止状态的说明
void pr_exit(int status) {
    if (WIFEXITED(status)) {
        // WEXITSTATUS: 对应正常终止状态
        printf("正常终止, 终止状态 = %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {   // WIFSIGNALED: 对应异常终止状态
        printf("异常终止, 信号编号  = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
               WCOREDUMP(status) ? " (核心文件生成)" : "");
#else
               "");
#endif
    } else if (WIFSTOPPED(status)) {
        printf("子进程暂停, 信号编号 = %d\n", WSTOPSIG(status));
    }
}

// Output:
// 正常终止, 终止状态 = 7
// 异常终止, 信号编号  = 6
// 异常终止, 信号编号  = 8
int main(void) {
    pid_t   pid;
    int     status;

// ===================== 模拟正常终止 =======================
    if ( (pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {      // 子进程
        exit(7);    // 正常终止
    }

    // wait 成功会返回进程 ID
    if (wait(&status) != pid) { // wait() 获取子进程终止状态
        err_sys("wait error");
    }
    pr_exit(status);  // 并打印


// ===================== 模拟异常终止中的 abort() =======================
    if ( (pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {  // 子进程
        abort();    // 产生 SIGABRT 信号
    }

    if (wait(&status) != pid) { // 获取子进程终止状态
        err_sys("wait error");
    }
    pr_exit(status);  // 并打印


// ===================== 模拟异常终止中的除以 0 =======================
    if ( (pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {      // 子进程
        status /= 0;    // 除以 0 会产生 SIGFPE 信号
    }

    if (wait(&status) != pid) { // 获取子进程终止状态
        err_sys("wait error");
    }
    pr_exit(status);  // 并打印

    exit(0);
}


