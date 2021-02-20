//
// Created by zz on 2021/2/19.
//

#include "../lib/apue.h"

void getpid_demo() {
    printf("hello world from process ID %ld\n", (long)getpid());
}



int main() {
    printf("hello world from process ID %ld\n", (long)getpid());
    exit(0);
}