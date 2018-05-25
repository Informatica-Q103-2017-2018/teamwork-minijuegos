#include<stdio.h>
#include<windows.h>
 
int main()
{
   int m=0, s=0, h=0;
    while(1)
	{
      if(s==60)
	  {
        s=s+1;
        m++;
        break;
        if(m==60)
		{
           m=0;
           h++;
           if(h==24)
		   {
              h=0;
            }
         }
      }
      printf("%d:%d:%d",h,m,s);
      s++;
      Sleep(1000); //esta duerme el programa por 1 segundo esta proviene de windows
      system("cls");//esta funcion tambien puede provenir de de stdlib
    }
  getchar();
  return 0;
}
