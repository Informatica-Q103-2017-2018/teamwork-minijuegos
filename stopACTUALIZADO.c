#include <stdio.h>
#include <windows.h>
int main()
{
	int segundos=0;
	while(segundos<=60)
	{
		printf("%d segundos",segundos);
		segundos=segundos+1;
		Sleep(1000);
	}
	printf("Han pasado"+segundos);//60 segundos
	return 0;
}
