#include <limits.h>
#include <stdio.h>
#include <float.h>

int main() {
	char char_type;
	int int_type;
	long long_type;
	signed char signed_char_type;
	short short_int_type;
	unsigned char unsigned_char_type;
	unsigned int unsigned_int_type;
	unsigned long unsigned_long_type;
	unsigned short unsigned_short_type;
	float float_type;
	double double_type;
	printf("Get size \n");
	printf("Size of character is: %llu \n", sizeof(char_type));
	printf("Size of integer is: %llu \n", sizeof(int_type));
	printf("Size of long is: %llu \n", sizeof(long_type));
	printf("Size of signed character is: %llu \n", sizeof(signed_char_type));
	printf("Size of short is: %llu \n", sizeof(short_int_type));
	printf("Size of unsigned character is: %llu \n", sizeof(unsigned_char_type));
	printf("Size of unsigned integer is: %llu \n", sizeof(unsigned_int_type));
	printf("Size of unsigned long is: %llu \n", sizeof(unsigned_long_type));
	printf("Size of unsigned short is: %llu \n", sizeof(unsigned_short_type));
	printf("Size of float is: %llu \n", sizeof(float_type));
	printf("Size of double is: %llu \n", sizeof(double_type));
	printf("Using Library \n");
	printf("Maximum value of char is: %d \n", CHAR_MAX);
	printf("Minimum value of char is: %d \n", CHAR_MIN);
	printf("Maximum value of int is: %d \n", INT_MAX);
	printf("Minimum value of int is: %d \n", INT_MIN);
	printf("Maximum value of long int is: %ld \n", LONG_MAX);
       	printf("Minimum value of long int is: %ld \n", LONG_MIN);
	printf("Maximum value of signed char is: %d \n", SCHAR_MAX);
	printf("Minimum value of signed char is: %d \n", SCHAR_MIN);
	printf("Maximum value of short int is: %d \n", SHRT_MAX);
	printf("Minimum value of short int is: %d \n", SHRT_MIN);
	printf("Maximum value of unsigned char is: %d \n", UCHAR_MAX);
       	printf("Maximum value of unsigned int is: %d \n", UINT_MAX);
	printf("Maximum value of unsigned long is: %lu \n", ULONG_MAX);
	printf("Maximum value of unsigned short is: %d \n", USHRT_MAX);
	printf("Maximum value of float is: %g \n", FLT_MAX);
	printf("Minimum value of float is: %f \n", FLT_MIN);
	printf("Maximum value of double is: %g \n", DBL_MAX);
	printf("Minimum value of double is: %f \n", DBL_MIN);
}
	
	
