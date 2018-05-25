#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<windows.h>
#include <locale.h>//  para las tildes
void wait(int seconds) // Funcion que empieza a contar el tiempo desde que el programa se enciende
{	clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while( clock() < endwait )
    {}
}
time_t start,end;
//doble dif, tiempototal = 0;
int main()
{ 
	clock_t inicio,fin;
	int puntuacion=0;
	char ultimaletra;
	char nombre[25],apellido[25],color[25],animal[25],pais[25],marca[25];
    char *nombre1 = nombre;
	char *apellido1 = apellido;
	char *color1 = color;
	char *animal1 = animal;
	char *pais1 = pais;
	char *marca1 = marca;
	
	//while(1)
	//{
		time(&start); //Empieza a contar el tiempo
		printf("¿Estas preparado...?\n");
		srand(time(NULL));
		ultimaletra='a'+(rand()%(('z'-'a')+1));//La letra la elige el ordenador al azar
		printf("La letra es:%c\n",ultimaletra);
		printf("Date prisa\n");
		
	printf("\nNombre:"); 
	scanf("%s",&nombre);
	inicio=clock();
	printf ( " \n Tiempo transcurrido = % .1f segundos \n " , (inicio)/(double)CLOCKS_PER_SEC);
	printf("\nApellido:");
	scanf("%s",&apellido);
	inicio=clock();
	printf ( " \n Tiempo transcurrido = % .1f segundos \n " , (inicio)/(double)CLOCKS_PER_SEC);
	printf("\nColor:");
	scanf("%s",&color);
	inicio=clock();
	printf ( " \n Tiempo transcurrido = % .1f segundos \n " , (inicio)/(double)CLOCKS_PER_SEC);
	printf("\nAnimal:");
	scanf("%s",&animal);
	inicio=clock();
	printf ( " \n Tiempo transcurrido = % .1f segundos \n " , (inicio)/(double)CLOCKS_PER_SEC);
	printf("\nPais:");
	scanf("%s",&pais);
	inicio=clock();
	printf ( " \n Tiempo transcurrido = % .1f segundos \n " , (inicio)/(double)CLOCKS_PER_SEC);
	printf("\nMarca:");
	scanf("%s",&marca);
    fin=clock();
    printf ( " \n Tiempo transcurrido = % .1f segundos \n " , (fin)/(double)CLOCKS_PER_SEC);
		if(*nombre1 == ultimaletra)
		puntuacion=puntuacion+1;
	if(*apellido1 == ultimaletra)
	puntuacion=puntuacion+1;
	    if(*color1 == ultimaletra)
	puntuacion=puntuacion+1;
	    if(*animal1 == ultimaletra)
	puntuacion=puntuacion+1;
	    if(*pais1 == ultimaletra)
	puntuacion=puntuacion+1;
	    if(*marca1 == ultimaletra)
	puntuacion=puntuacion+1;
	fflush(stdin);
		printf("Tu puntuacion total es:%i\n",puntuacion);
		
	time(&end); //El tiempo se para



return 0;}
