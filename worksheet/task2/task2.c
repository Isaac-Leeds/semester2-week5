/*
 * Sem 2, week 5
 *
 * Portfolio submission: Hexadecimal to Decimal Converter
 * Name: Isaac Marlow
 * ID: jbff0193
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int main(void){
	long decimal=0;
	char hex[9];
	char hexChars[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	printf("Enter a hexadecimal:");

	// if input contains invalid hex digit
	// printf("Error: Invalid Hexadecimal\n");
	scanf("%s",hex);

	int firstValid=9;
	for (int c = 8; c>=0; --c){
		if(hex[c]!=0){
			if(firstValid==9){
				firstValid = c;
			}
			bool validChar = false;
			for (int k = 0; k<16; ++k){
				if(toupper(hex[c])==hexChars[k]){
					validChar = true;
					double placeValue = pow(16,firstValid-c);
					decimal+=k*placeValue;
				}
			}
			if(!validChar){
				printf("Error: Invalid Hexadecimal\n");
				return 0;
			}
		}
	}
	// print the decimal result
	printf("decimal:%ld\n", decimal);
	
	return 0;
}