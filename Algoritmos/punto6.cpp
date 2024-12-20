//
// Created by Angel on 14/12/24.
//

#include "punto6.h"

int point6(int n) {
    if (n < 4) {
        return 10;
    }
    int a = 1;
    int i;
    for (i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int k = n;
            while (k>=1) {
                a = a+2;
                k = k/3;
            }
        }
    }
    int b = 10;
    while (b>3) {
        if (i % 2 == 0) {
            a = a+3*point6(n/3)+5*point6(n/5);
        }
        else {
            a = a+3*point6(n/3);
        }
        b = b-1;
    }
    return a;
}
