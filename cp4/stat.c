//
// Created by zz on 2021/2/25.
//

#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include "../lib/apue.h"

void stat_demo() {
    struct stat buf;
    int res;
    // stat()：根据给出的 pathname，返回对应的文件信息
    res = stat("./xx.txt", &buf);
    res == 0 ? printf("mode: %d, size: %lld\n", buf.st_mode, buf.st_size) :
    printf("stat() error!");

    // fstat()：根据给出的 文件描述符，返回对应的文件信息
    int fd = open("./xx.txt", O_RDWR, 0777);
    res = fstat(fd, &buf);
    res == 0 ? printf("mode: %d, size: %lld\n", buf.st_mode, buf.st_size) :
               printf("fstat() error!");


    // lstat()：如果 pathname 对应的是一个符号链接，则返回符号链接本身的信息，而不是其所指向文件的信息
    res = lstat("./xx_soft_link", &buf);
    res == 0 ? printf("mode: %d, size: %lld\n", buf.st_mode, buf.st_size) :
    printf("lstat() error!");



//    DIR *dir = opendir("/Users/zz/CLionProjects/apue/cp4/");
//    readdir(dir);
//    if (_fd == -1) {
//        printf("open file error!");
//        return;
//    }
//    printf("fd: %d\n", _fd);
//    res = fstatat(_fd, "/xx.txt", &buf, AT_SYMLINK_NOFOLLOW);
//    res == 0 ? printf("mode: %d, size: %lld\n", buf.st_mode, buf.st_size) :
//    printf("fstatat() error!");

}

// ./stat /etc/passwd /etc /dev/log /dev/tty /var/lib/oprofile/opd_pipe /dev/sr0 /dev/cdrom
void file_type_demo(int argc, char *argv[]) {
    struct stat buf;
    char *ptr;
    int i;

    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);
        if (lstat(argv[i], &buf) < 0) {
            err_ret("lstat error");
            continue;
        }
        if (S_ISREG(buf.st_mode)) {
            ptr = "普通文件";
        } else if (S_ISDIR(buf.st_mode)) {
            ptr = "目录文件";
        } else if (S_ISCHR(buf.st_mode)) {
            ptr = "字符特殊文件";
        } else if (S_ISBLK(buf.st_mode)) {
            ptr = "块特殊文件";
        } else if (S_ISFIFO(buf.st_mode)) {
            ptr = "fifo";
        } else if (S_ISLNK(buf.st_mode)) {
            ptr = "符号链接";
        } else if (S_ISSOCK(buf.st_mode)) {
            ptr = "socket";
        } else {
            ptr = "** unknown mode **";
        }
        printf("%s\n", ptr);
    }
    exit(0);
}

typedef struct {
    char *n;
}STU;

int main(int argc, char *argv[]) {
    //stat_demo();
    file_type_demo(argc, argv);
    DIR *d = opendir("");
    struct dirent *d1 = (struct dirent *) d;

    struct dirent *dr = readdir(d);

    STU s = {};
}

