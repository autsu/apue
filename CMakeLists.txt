cmake_minimum_required(VERSION 3.17)
project(unix)

set(CMAKE_CXX_STANDARD 14)

add_executable(unix main.c lib/apue.h cp1/ls.c lib/apue.c cp1/io.c cp1/io_buffer.c cp1/thread.c cp3/lseek.c cp3/rw.c cp3/dup.c cp3/fcntl.c cp4/stat.c cp5/buf.c cp7/atexit.c cp15/pipe.c cp8/fork.c cp8/exec.c cp11/pthread.c cp8/exit_stat.c)