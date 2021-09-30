#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){
    int temp = x;
    if ( temp < 0 ) {
        return false;
    }
    int y = 0;
    while ( temp > 0 ) {
        y = y*10 + temp%10;
        temp /= 10;
    }
    return ( x == y ) ? true : false;
}

int main(){
    bool x = isPalindrome(121);
    printf("%d\n", x);
}

