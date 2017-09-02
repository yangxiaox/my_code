/*************************************************************************
	> File Name: oj.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月06日 星期日 08时56分45秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
int main() {
    const char *name_program = "./program";
    const char *name_in = "./in.txt";
    const char *name_out = "./out.txt";
    const char *name_right = "./right.txt";
    //FILE *fin = fopen(name_in, "w");
    run(name_program, name_in, name_out);
    FILE *fpright = fopen(name_right, "r");
    FILE *fpout = fopen(name_out, "r");
    char a, b;
    int i ,j;
    int flage = 1;
    while (flage) {
        i = fscanf(fpright, "%c", &a);
        j = fscanf(fpout, "%c", &b);
        if (i == EOF || j == EOF) break;
        if (a != b) {
            flage = 0;
        }
    }
    if (flage) {
        if (i != EOF || j != EOF) {
            if ((i != EOF && a == '\n') || (j != EOF && b == '\n')) {
                i = fscanf((i != EOF ? fpright : fpout), "%c", &a));
                flage = (i == EOF ? 1 : 0);
            } else {
                flage = 0;
            }
        }
    }
    printf("%s", flage ? "Accept" : "Wrong Answer");

}
