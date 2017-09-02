/*************************************************************************
	> File Name: lf.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月22日 星期六 10时57分47秒
 ************************************************************************/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dirptr = NULL;
    int i = 1;
    struct dirent *entry;
    struct stat *buf;
    if (strcmp(argv[1], "ls") != 0) {
        printf("command error !\n");
        //printf("%s\n", argv[1]);
        exit(1);
    }
    if ((dirptr = opendir("."))==NULL)
    {
        printf("opendir failed!");
        exit(1);        
    } else if (strcmp(argv[2], "-a") == 0) {
        while (entry = readdir(dirptr)) {
            printf("NO.%d %s\t", i, entry->d_name);
            ++i;     
        }
        printf("\n");
        closedir(dirptr);            
    } else if (strcmp(argv[2], "-l") == 0) {
        print("H0")
        while(entry = readdir(dirptr)) {
            printf("H1");
            stat(entry->d_name, buf);
            printf("H");
            printf("NO.%d \t %s \t %d \t %lu \t %u \t %u \t %ld \t %ld\n", i , entry->d_name, buf->st_mode, buf->st_nlink, buf->st_uid, buf->st_gid, buf->st_size, buf->st_ctime);
            ++i;
        }
        closedir(dirptr);
    }
    //printf("xx\n");
    return 0;

}
