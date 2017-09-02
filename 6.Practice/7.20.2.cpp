/*************************************************************************
	> File Name: 7.20.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月20日 星期四 15时19分48秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

union TP {
    unsigned int ip_num;
    char ip_part[4];
};

void print_binary(int x) {
    int t = 32;
    unsigned int i = 0; 
    while (t--) {
        i <<= 1;
        i += (x % 2);
        x >>= 1;
    }
    t = 32;
    while (t--) {
        printf("%d", i%2);
        i >>= 1;
        if(t % 8 == 0)
            printf(" ");
    }
    printf("\n");
    return ;
}

int main() {
    TP ip;
    int a, b, c, d;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    ip.ip_part[3] = a;
    ip.ip_part[2] = b;
    ip.ip_part[1] = c;
    ip.ip_part[0] = d;
    print_binary(a);
    print_binary(b);
    print_binary(c);
    print_binary(d);
    print_binary(ip.ip_num);
    printf("%u\n", ip.ip_num);
    return 0;
}
