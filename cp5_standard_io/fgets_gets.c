//
// Created by zz on 2021/3/26.
//

#include "../lib/apue.h"

//
int fgets_demo() {
    char buf[MAXLINE];
    int n;

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        unsigned long read_len = strlen(buf);
        if ( (n = write(STDOUT_FILENO, buf, read_len)) != read_len) {
            err_sys("write error");
        }
    }

    exit(EXIT_SUCCESS);
}

int main() {

}