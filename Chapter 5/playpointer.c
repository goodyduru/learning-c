#include <stdio.h>

void change_array_value(int arr[]) {
    arr[5] = 8;
}

void cannot_change(int val) {
    val = 12;
}

void can_change(int *p) {
    *p = 20;
}

int main() {
    int x = 1, y = 2, z[10];
    int *ip, *jp;

    ip = &x;
    jp = ip;
    printf("ip is: %d\n", *ip);
    printf("jp is: %d\n", *jp);
    y = *ip;
    printf("y is: %d\n", y);
    *ip = 0;
    printf("ip is: %d\n", *ip);
    printf("jp is: %d\n", *jp);
    printf("x is: %d\n", x);
    printf("y is: %d\n", y);
    ip = &z[5];
    printf("ip is: %d\n", *ip);
    change_array_value(z);
    printf("ip is: %d\n", *ip);

    cannot_change(z[5]);
    printf("z[5] is: %d\n", z[5]);
    printf("ip is %d\n", *ip);

    can_change(ip);
    printf("z[5] is: %d\n", z[5]);
    printf("ip is %d\n", *ip);

    jp = z+5;
    printf("jp is %d\n", *jp);

    z[8] = 6;
    jp += 3;
    printf("jp is %d\n", *jp);

    ip = jp;
    z[8] = 12;
    printf("ip is %d\n", *ip);
    printf("jp is %d\n", *jp);

    ip = z+5;
    printf("ip is %d\n", *ip);
    printf("(ip+3) is %d\n", *(ip+3));

    printf("z[2] is %d\n", z[2]);
    can_change(z+2);
    printf("z[2] is %d\n", z[2]);

    int i = 0;
    while ( i < 4 ) {
        printf("Incrementing ip: %d\n", *ip++);
        i++;
    }

    z[9] = 30;
    printf("ip is %d\n", *ip);
}