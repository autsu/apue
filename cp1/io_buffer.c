//
// Created by zz on 2021/2/19.
//

#include "../lib/apue.h"

//  clang -o iobuffer io_buffer.c ../lib/apue.c

int main() {
    int c;
    while ( (c = getc(stdin) ) != EOF ) {
        if (putc(c, stdout) == EOF) {
            err_sys("output error!");
        }
    }

    if (ferror(stdin)) {
        err_sys("input error!");
    }

    exit(0);
}
