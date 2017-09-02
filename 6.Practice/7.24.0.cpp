/*************************************************************************
	> File Name: 7.24.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月24日 星期一 01时19分18秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("command error !\n");
        exit(1);
    }
    if (argc == 2) {
        //printf("xxx\n");
        if (!strcmp(argv[1], "cd")) {
            int i = 1;
            i = chdir("/home");
            if (i == 0) {
                printf("go to home\n");
                return 0;
            }
        }
        exit(1);
    }
    if (argc > 3) {
        printf("command error !\n");
        exit(1);
    }
    if (argc == 3) {
        if (!strcmp(argv[1], "cd")) {
            //printf("%s\n", argv[2]);
            int i = 1;
            i = chdir(argv[2]);
            //printf("%d\n",i);
            if (i == 0) {
                printf("go to %s\n", argv[2]);
            } else {
                printf("NO is address !\n");
            }
        }
        //printf("yyy\n");
    }
    return 0;
}
