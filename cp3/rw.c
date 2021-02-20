//
// Created by zz on 2021/2/20.
//

#include "../lib/apue.h"
#include <fcntl.h>

#define BUFFSIZE 1024

void read_t() {
    char buf[BUFFSIZE];
    int fd = open("./xx.txt", O_RDWR|O_APPEND|O_CREAT, 0777);
    int n;
    while ( (n = read(fd, buf, 10)) > 0 ) {
        printf("%s\n", buf);
    }

}

int main() {
    read_t();
}