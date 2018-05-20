#include <stdio.h>
typedef struct
{
char nombre[50], pregunta[50], experiencia[10] , ganar[10];
int matricula, edad;
}
ficha;
int main ()
{
ficha usuario;
char opcion;
FILE *pf;
pf=fopen("alumnos.txt", "wb");
do
{
fflush(stdin);
printf("\nNombre de usuario: ");
gets(usuario.nombre);
printf("¿Has jugado alguna vez?: ");
gets(usuario.pregunta);
printf("\¿Te ves capacitado para pasar la mejor experiencia de tu vida?:");
gets(usuario.experiencia);
printf("Ganarás....? ");
gets(usuario.ganar);
printf("Edad: ");
scanf("%d", &usuario.edad);
printf("Numero de matricula: ");
scanf("%d", &usuario.matricula);
fwrite(&usuario, sizeof(ficha), 1, pf);
fflush(stdin);
printf("\nMas usuarios (s/n)?\n");
scanf("%c", &opcion);
}
while (opcion=='s');
fclose(pf);
return 0;
}


