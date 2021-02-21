//
// Created by zz on 2021/2/21.
//

#include <fcntl.h>
#include <stdio.h>
#include "../lib/apue.h"


// fcntl(fd, cmd)
void fcntl_cmd_demo() {
    // flag         hex          bin         dec
    // O_RDWR       0x0002       0010        2
    // O_APPEND     0x0008       1000        8
    // 或运算                     1010        10

    // O_RDONLY     0x0000       0000        0
    // O_APPEND     0x0008       1000        8
    // 或运算                     1000        8

    // O_WRONLY     0x0001       0001        1
    // O_APPEND     0x0008       1000        8
    // 或运算                     1001        9

    /* 其他标识 */
    // O_APPEND     0x0008       1000        8
    // O_NONBLOCK   0x0004       0100        4
    // O_SYNC       0x0080       10000000    128

    // O_CREAT（不参与运算）       0x0200      1000000000      512
    int fd = open("./xx.txt", O_WRONLY|O_APPEND|O_CREAT, 0777);
    printf("fd: %d\n", fd);

    int ffd = fcntl(fd, F_GETFD);
    printf("F_GETFD: %d\n", ffd);

    // 返回的 文件状态标志 是十进制
    int fld = fcntl(fd, F_GETFL);
    printf("F_GETFL: %d\n", fld);   // Output: 10，O_CREAT 不参与运算
    printf("%x\n", O_RDWR|O_APPEND|O_CREAT);    // Output: 20a


}

void get_cmd() {
    int fd = open("./xx.txt", O_RDWR|O_APPEND|O_CREAT, 0777);
    int ftl = fcntl(fd, F_GETFL); // 10 = 1010

    //              hex         bin         dec
    // O_ACCMODE    0x0003      0011        3
    // & O_ACCMODE 作用：取出低二位
    // ftl & O_ACCMODE = 1010 & 0011 = 0010 = 0x0002 = O_RDWR
    switch (ftl & O_ACCMODE) {
        case O_RDWR:
            printf("read write");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDONLY:
            printf("read only");
            break;
        default:
            err_dump("unknown access mode");
    }

    // 获得高位
    // O_APPEND     0x0008       1000        8
    // O_RDONLY|O_APPEND = 1000   O_WRONLY|O_APPEND = 1001  O_RDWR|O_APPEND = 1010
    // 1000 & 1000 = 1000 = 8   1001 & 1000 = 1000 = 8  1010 & 1000 = 1000 = 8
    if (ftl & O_APPEND) {   // 8
        printf(", append\n");
    }
    // O_NONBLOCK   0x0004       0100        4
    if (ftl & O_NONBLOCK) {     // 4
        printf(", nonblock\n");
    }
    // O_SYNC       0x0080       10000000    128
    if (ftl & O_SYNC) {     // 128
        printf(", sync\n");
    }

    printf("&append: %d\n&nonblock: %d\n&sync: %d\n",
           ftl & O_APPEND, ftl & O_NONBLOCK, ftl & O_SYNC);

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC) {
        printf(", sync")
    }
#endif

    putchar('\n');
    exit(0);
}

int main() {
    //fcntl_cmd_demo();
    get_cmd();
}

