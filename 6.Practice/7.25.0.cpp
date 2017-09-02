/*************************************************************************
	> File Name: 7.25.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月25日 星期二 10时53分57秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
int main()//正确的
{
         char s[]="/home";
         chdir (s);
         char xxx[1024];//获取当前目录并打印
         getcwd(xxx,1024);
         printf("The current directory is : %s\n",xxx);
}
