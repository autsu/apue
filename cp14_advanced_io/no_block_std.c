//
// Created by zz on 2021/3/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAXSIZE 1024

extern int errno ;

// read 函数的阻塞和非阻塞的区别
// 读常规文件是不会阻塞的，不管读多少字节，read 一定会在有限的时间内返回。
// 从终端设备或网络读则不一定，如果从终端输入的数据没有换行符，调用 read 读终端设备就会阻塞，
// 如果网络上没有接收到数据包，调用 read 从网络读就会阻塞，至于会阻塞多长时间也是不确定的，
// 如果一直没有数据到达就一直阻塞在那里。同样，写常规文件是不会阻塞的，而向终端设备或网络写则不一定。

// stdin 会阻塞，直到有键盘输入
void block_std() {
    char buf[MAXSIZE];
    int n;

    while ( (n = read(STDIN_FILENO, &buf, MAXSIZE) ) > 0) {
        if (write(STDOUT_FILENO, &buf, n) < n) {
            fprintf(stderr, "write error: \n", errno);
        }
    }

    if (n < 0) {
        fprintf(stderr, "read error: \n", errno);
    }

    exit(0);
}

void no_block_std() {
    // 如果在 open 一个设备时指定了 O_NONBLOCK 标志，read/write 就不会阻塞。
    // 以 read 为例，如果设备暂时没有数据可读就返回 -1，同时置 errno 为
    // EWOULDBLOCK（或者EAGAIN，这两个宏定义的值相同）
    int fd = open(STDIN_FILENO, O_NONBLOCK|O_RDWR, 0777);
    char buf[MAXSIZE];
    int n;

    while ( (n = read(fd, &buf, MAXSIZE)) > 0 ) {
        if (write(STDOUT_FILENO, &buf, n) != n ) {
            fprintf(stderr, "write error: \n", errno);
        }
    }

    if (n < 0) {
        fprintf(stderr, "read error: \n", errno);
    }

    exit(0);
}

int main() {
    //block_std();
    no_block_std();
}

