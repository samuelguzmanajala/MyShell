cmake_minimum_required(VERSION 3.17)
project(MyShell C)

set(CMAKE_C_STANDARD 11)

add_executable(MyShell
        #my_cat.c
        #myshell0.c
        #my_grep.c)
        #my_shell.c
        commandsC/my_grep.c commandsH/my_grep.h
        #my_shell_original.c
        myShell0.c myShell0.h commandsC/my_cp.c commandsH/my_cp.h commandsC/my_help.c commandsH/my_help.h commandsC/my_cp2.c commandsH/my_cp2.h commandsC/my_mv.c commandsH/my_mv.h commandsC/my_cat.c commandsH/my_cat.h commandsC/my_ls.c commandsH/my_ls.h commandsC/my_man.c commandsH/my_man.h commandsC/game.c commandsH/game.h myShell0.c commandsC/test.c commandsH/test.h)

target_link_libraries(MyShell readline)