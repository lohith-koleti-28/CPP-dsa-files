#include "gcdlcm.h"
int gcd(int a,int b){
    int r;
    while(a%b !=0){
        r = a%b;
        b=r;
        a=b;
    }
    return b;
}