//
// Created by zz on 2021/1/5.
//

#include "../lib/apue.h"
#include <dirent.h>

// 编译：gcc -Wall -g -o ls ls.c apue.c
// 运行：./ls [path]
// argc => 命令行参数的个数
// argv[] => 命令行参数的值，argv[0] 是程序运行的全路径名，从 1 开始是每个参数的值
int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        err_quit("usage: ls directory_name");
    }

    if ((dp = opendir(argv[1])) == NULL) {
        err_sys("can't open %s", argv[1]);
    }

    // 读每个目录项
    while ((dirp = readdir(dp)) != NULL) {
        // 打印每个目录项的名字
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}