//
// Created by zz on 2021/3/15.
//

#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    fd_set rfds;
    struct timeval tv;
    int retval;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    // int select(int maxfd1, fd_set *restrict readfds,
    //            fd_set *restrict writefds, fd_set *restrict exceptfds,
    //            struct timeval *restrict tvptr)
    //
    // 4. tvptr: 指定愿意等待的时间长度，单位为秒和微秒，有以下三种情况：
    //    1. tvptr == NULL
    //    永远等待。如果捕捉到一个信号则中断此无期限等待。当所
    retval = select(1, &rfds, NULL, NULL, &tv);
    if (retval == -1) {
        perror("select()");
    } else if (retval) {
        printf("data is available now.\n");
    } else {
        printf("no data with in five seconds.\n");
    }

    exit(EXIT_SUCCESS);
}


