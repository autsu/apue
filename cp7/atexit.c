//
// Created by zz on 2021/2/26.
//

#include "../lib/apue.h"

// atexit()
// 用来设置一个程序正常结束前调用的函数. 当程序通过调用 exit() 或从 main 中返回时,
// 参数 function 所指定的函数会先被调用, 然后才真正由 exit() 结束程序.
// exit() 调用这些函数的顺序与它们登记的顺序相反

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

