#include <stdlib.h>
#include <time.h>
#include <stdio.h>
 int main(int c,char** s){
 	int i;
 	srand(time(NULL));
	printf("La letra es:%c\n",'a' + rand() %(('z'-'a')+1));	
	return 0;
 }
