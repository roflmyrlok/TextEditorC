//
// Created by Андрей Трибушной on 23.09.2022.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
            char *p, s[100];
            long n;
            printf("Choose the command: ");
            while (fgets(s, sizeof(s), stdin)) {
                n = strtol(s, &p, 10);
                if (p == s || *p != '\n') {
                    printf("Must be an integer: ");
                } else break;
            }
            if (!(n >= 0 && n <= 7)){
                printf("The command is not implemented! \n");
                continue;
            }
            printf("%ld\n", n);
        }
}
