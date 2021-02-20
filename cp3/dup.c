//
// Created by zz on 2021/2/20.
//

#include "../lib/apue.h"
#include <fcntl.h>

int main() {
    int fd = open("./xx.txt", O_RDWR|O_APPEND|O_CREAT, 0777);
    // 复制文件描述符，新的文件描述符为当前可用的最小值
    int newfd = dup(fd);
    // Output: old fd: 3, new fd2: 4
    printf("old fd: %d, new fd: %d\n", fd, newfd);
    char buf[1024];
    // 新描述符与初始描述符共享同一个文件表项，通过 read 读取内容可以查看
    while (read(newfd, buf, 10) > 0) {
        printf("%s\n", buf);
    }

    char buf1[1024];
    // 复制文件描述符，并指定新描述符为 666
    // 如果 666 文件符已打开，会先将其关闭
    int newfd2 = dup2(fd, 666);
    // Output: old fd: 3, new fd2: 666
    printf("old fd: %d, new fd2: %d\n", fd, newfd2);
    while (read(newfd2, buf1, 10) > 0) {
        printf("%s\n", buf1);
    }
}

