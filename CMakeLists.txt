cmake_minimum_required(VERSION 3.17)
project(MyShell C)

set(CMAKE_C_STANDARD 11)

add_executable(MyShell
        #my_cat.c
        #my_cd2.c
        #myshell0.c
        #my_grep.c)
        #my_shell.c #my_cd.c my_cd.h
        my_shell.c my_grep.c my_grep.h)

target_link_libraries(MyShell readline)