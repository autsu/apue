//
// Created by zz on 2021/2/26.
//

#include "../lib/apue.h"

// atexit()
// 用来设置一个程序正常结束前调用的函数. 当程序通过调用exit()或从main 中返回时,
// 参数function 所指定的函数会先被调用, 然后才真正由exit()结束程序.

static void my_exit1(void);
static void my_exit2(void );

// Output:
// main is done
// first exit handler
// first exit handler
// second exit handler
int main() {
    if (atexit(my_exit2) != 0) {
        err_sys("can't register my_exit2");
    }

    if (atexit(my_exit1) != 0) {
        err_sys("can't register my_exit1");
    }

    if (atexit(my_exit1) != 0) {
        err_sys("can't register my_exit1");
    }

    printf("main is done\n");
    return 0;
}

static void my_exit1(void) {
    printf("first exit handler\n");
}

static void my_exit2(void) {
    printf("second exit handler\n");
}

