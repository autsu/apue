//
// Created by zz on 2021/3/12.
//

// 非阻塞 I/O

#include "../lib/apue.h"
#include <errno.h>
#include <fcntl.h>

char buf[500000];

int main(void) {
    int ntowrite, nwrite;   // ntowrite: 读的字节数  nwrite: 写的字节数
    char *ptr;

    // 从标准输入读 500000 字节
    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes\n", ntowrite);

    set_fl(STDOUT_FILENO, O_NONBLOCK);  // 为 stdout 设置 nonblock 文件标识 （非阻塞）

    ptr = buf;
    while (ntowrite > 0) {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, ntowrite);
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

        // 更新偏移量
        if (nwrite > 0) {
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }

    clr_fl(STDOUT_FILENO, O_NONBLOCK);

    exit(0);
}

