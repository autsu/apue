cmake_minimum_required(VERSION 3.17)
project(unix)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        unix
        main.c
        lib/apue.h
        cp1/ls.c
        lib/apue.c
        cp1/io.c
        cp1/io_buffer.c
        cp1/thread.c
        cp3/lseek.c
        cp3/rw.c
        cp3/dup.c
        cp3/fcntl.c
        cp4/stat.c
        cp5_standard_io/buf.c
        cp7/atexit.c
        cp15_process_communication/unnamed_pipe.c
        cp8_process_control/fork.c
        cp8_process_control/exec.c
        cp11_thread/pthread.c
        cp8_process_control/exit_stat.c
        cp8_process_control/orphan_zombie.c
        cp14_advanced_io/no_block_io.c
        cp14_advanced_io/no_block_std.c
        cp14_advanced_io/select.c
        cp8_process_control/fork2.c
        cp5_standard_io/fgets_gets.c
        cp8_process_control/pid.c
        cp15_process_communication/fifo_write.c
        cp15_process_communication/fifo_read.c
        cp15_process_communication/mq_recv.c
        cp15_process_communication/mq_send.c cp15_process_communication/signal.c cp15_process_communication/sem.c)