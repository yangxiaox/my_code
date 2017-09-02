/*************************************************************************
	> File Name: 7.20.6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月20日 星期四 16时58分24秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#define APP_KEY "haizeix"
#define USER_NAME "yangxiaoxu"

int verify_app_key(char *str) {
    int len1 = strlen(APP_KEY);
    int len2 = strlen(str);
    if (len2 < len1) {
        return 0;
    }
    str += (len2 - len1);
    return (strcmp(str, APP_KEY) == 0);
}

int verify_user_name(char **env) {

    while (*env != NULL) {
        if (strncmp("USER=", *env, 5) == 0) {
            char *user_name_str = (*env) + 5;
            if (strcmp(USER_NAME, user_name_str) == 0) {
                return 1;
            }
            return 0;
        }
        ++env;
    }
    return 0;
} 

int main(int argc, char *argv[], char **env) {
    if (!verify_app_key(argv[0])) {
        printf("app key verify error!\n");
        return 0;
    }
    if (!verify_user_name(env)) {
        printf("user name verify error!\n");
        return 0;
    }
    printf("function is running......\n");
    return 0;
}
