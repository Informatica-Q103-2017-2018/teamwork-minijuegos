#include <stdio.h>
#include <stdio.h>
int main()
{
	int segundos=0;
	while(segundos<=60)
	{
		printf("segundos");
		segundos=segundos+1;
		sleep(1000);
	}
	printf("Han pasado 60 segundos");
}
