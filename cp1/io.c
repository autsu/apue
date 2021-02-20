//
// Created by zz on 2021/1/5.
//

// 从 stdin 读到 stdout

#include "../lib/apue.h"
#define BUFFSIZE 4096

int main() {
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("write error");
        }
    }

    if (n < 0) {
        err_sys("io error");
    }
    exit(0);
}