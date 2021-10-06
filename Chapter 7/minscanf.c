#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int *ival;
    double *dval;

    va_start(ap, fmt);
    for ( p = fmt; *p; p++ ) {
        if ( *p != '%' ) {
            getchar();
            continue;
        }

        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int*);
                scanf("%d", ival);
                break;
            
            case 'f':
                dval = va_arg(ap, double*);
                scanf("%f", dval);
                break;
            
            case 's':
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            default:
                getchar();
                break;
        }
    }
}

int main() {
    int real;
    float exponent;
    char* str;
    minscanf("%d/%f/%s", &real, &exponent, str);
    printf("%d\n%f\n%s\n", real, exponent, str);
}