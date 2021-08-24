#include "../lib/apue.h"
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_NAME "/tmp/my_fifo"

int main() {
    int res = 0;

    // 如果文件不存在，则创建一个管道
    if (access(FIFO_NAME, F_OK) == -1) {
        res = mkfifo(FIFO_NAME, 0777);
        if (res == -1) {
            printf("mkfifo error: %s \n", strerror(errno));
            return 0;
        }
    }

    // 以只写方式打开管道
    int pipe_fd = open(FIFO_NAME, O_WRONLY);
    if (pipe_fd == -1) {
        printf("open fifo error: %s \n", strerror(errno));
        return 0;
    }

    char buf[1024];
    memset(&buf, '\0', 1024);

    strcpy(buf, "Hello, World!");

    // 向 fifo 中写入数据
    int n = write(pipe_fd, buf, sizeof(buf));
    if (n < 0) {
        printf("write data to fifo error: %s \n", strerror(errno));
        return 0;
    }

    printf("process %d write %d bytes to fifo \n", getpid(), n);
}