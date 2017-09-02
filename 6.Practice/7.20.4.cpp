/*************************************************************************
	> File Name: 7.20.4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月20日 星期四 16时24分09秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main(int n, char *s[]) {
    if (n == 1) return 0;
    for (int i = 1; i < n; ++i) {
        printf("%s\n", s[i]);
    }
    //第一个参数是./a.out
    //以空格为分隔符 
    //想输出空格符的话用“”引起来
    return 0;
}
