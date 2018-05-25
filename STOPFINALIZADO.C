#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
	int tiempo,puntuacion=0;
	char ultimaletra;
	char nombre[25],apellido[25],color[25],animal[25],pais[25],marca[25];
	int crono=60-tiempo;
	tiempo=0;
	while(1)
	{
		printf("¿Estas preparado...?");
		ultimaletra='a'+(rand()%26);
		printf("La letra es:%c\n",ultimaletra);
		printf("Date prisa,solo tienes 60 segundos!!");
		printf("(Nombre,apellido,color,animal,pais y marca)");
		while(tiempo<=60){
			tiempo=tiempo+1;
			printf(""+crono);
		}
		printf("¡¡Se acabo el tiempo,valida tus respuestas!!");
		printf("Nombre:");
		scanf("%s",&nombre);
		printf("Apellido:");
		scanf("%s",&apellido);
		printf("Color:");
		scanf("%s",&color);
		printf("Animal:");
		scanf("%s",&animal);
		printf("Pais:");
		scanf("%s",&pais);
		printf("Marca:");
		scanf("%s",&marca);
		if(strchr(nombre,0)==ultimaletra){
			puntuacion=puntuacion+1;
		}
	    if(strchr(apellido,0)==ultimaletra){
			puntuacion=puntuacion+1;
		}
	    if(strchr(color,0)==ultimaletra){
			puntuacion=puntuacion+1;
		}
	    if(strchr(animal,0)==ultimaletra){
			puntuacion=puntuacion+1;
		}
	    if(strchr(pais,0)==ultimaletra){
			puntuacion=puntuacion+1;
		}
		if(strchr(marca,0)==ultimaletra){
			puntuacion=puntuacion+1;
		}
		printf("Tu puntuacion total es:%i\n",puntuacion);
		printf("Pulsa enter para empezar otra ronda:");
		scanf("%s",&nombre);	
	}
	return 0;
}
