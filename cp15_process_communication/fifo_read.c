//
// Created by zz on 2021/8/6.
//

#include "../lib/apue.h"
#include <errno.h>
#include <fcntl.h>

#define FIFO_NAME "/tmp/my_fifo"

int main() {
    // 只读方式打开管道
    int pipe_fd = open(FIFO_NAME, O_RDONLY);
    if (pipe_fd == -1) {
        printf("open fifo error: %s \n", strerror(errno));
        return 0;
    }

    char buf[1024];
    memset(&buf, '\0', 1024);

    // 从管道中读取数据
    int n = read(pipe_fd, buf, 1024);
    if (n < 0) {
        printf("read data from fifo error: %s \n", strerror(errno));
        return 0;
    }

    printf("process %d read from fifo: %s \n", getpid(), buf);
}

