/*************************************************************************
	> File Name: lf.c.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月21日 星期五 21时12分32秒
 ************************************************************************/

 #include <stdio.h>  
 #include <dirent.h> 
 #include <sys/types.h>

 int main(int argc, char *argv[])  
 {  
    DIR *dirptr = NULL;  
    struct dirent *entry;  
    if((dirptr = opendir(".")) == NULL)  {  
        printf("open dir !\n");  
        return 1;  
    } else {
        while (entry = readdir(dirptr))  {  
            printf("%s\n", entry->d_name);/* 打印出该目录下的所有内容 */  
        }  
    closedir(dirptr);  
    }  
    return 0;  
}  
