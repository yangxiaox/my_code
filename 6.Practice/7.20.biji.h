/*************************************************************************
	> File Name: 7.20.biji.h
	> Author: 
	> Mail: 
	> Created Time: 2017年07月20日 星期四 16时04分23秒
 ************************************************************************/

typedet long long lint;
typedef char * pchar;
//lint 代表 long long


typedet struct __node {
    int x, y;
} Node, *PNode;


typedet int (*func)(int);

int main();


int main(int argc, char *argv[]);
//参数个数  存到字符串数组里面 每个参数都是啥
//字符串数组

int main(int argc, char *argv[], char **env);
//第三个参数环境变量

int main(int n, char *s[]) {
    for (int i = 0; i < n; ++i) {
        printf("%s\n", s[i]);
    }
    return 0;
}

char **env;
*(*(env + 3) + 2);
