#include "stdio.h"
#include "time.h"

typedef unsigned char uint8; 
typedef unsigned short uint16;
uint8 u8LuchCheck (uint8 *pu8Data, uint8 u8SizeOfList);

void main() 
{
	uint8 au8NumOfCard[16]= {4,1,6,8,8,1,8,8,4,4,4,4,7,1,1,5};
	uint8 u8Check = 0;
	uint8 i;

	//1ro Revisamos el arreglo
	printf("Check array\n");
	for(i=0; i<=15; i++)
	{
	printf( "%d ", au8NumOfCard[i]);
	}
	//2do Mandamos la cadena para la funcion para que realice la lectura
	u8Check = u8LuchCheck ( &au8NumOfCard[0], 16);
	//validamos el valor que nos arrojo la funcion
	if ( u8Check == 0)
	{
		printf("\nLa tarjeta es valida");
	}
	else
	{
		printf("\nLa tarjeta no es valida");
	}
}

uint8 u8LuchCheck (uint8 *pu8Data, uint8 u8SizeOfList)
{
	uint8 i,j,n,residuo,modu,valid,suma=0,sumatotal=0,u8Check;
	
	for( i = 0; i <= 15; i+=2)
	{
		n = *pu8Data; 
		n =2*n;
		*pu8Data = n;			// {10000,2,4,1,3,7,9,2,4,7,9,1,9,7,6,3};
		pu8Data=pu8Data+2;		//  {8,2,4,1,3,7,9,2,4,7,9,1,9,7,6,3};
	}
	for(i=0; i<=15; i++)
	{
		pu8Data--;
	}
	printf("\n " );
	for(i=0; i<=15; i++)
	{
		printf("%d ",*pu8Data );
		pu8Data++;
	}
	for(i=0; i<=15; i++)
	{
		pu8Data--;
	}
	printf("\n " );
	printf("\nSuma del residuo"); 
	printf("\n " );

	for(i=0; i<=15; i++)
    {

        if (*pu8Data >= 10)
        {
            j = *pu8Data;
            residuo = j % 10;
            suma = residuo + 1;
            *pu8Data = suma;          
        }
        else 
        {
            /*Nothing to do*/
        }
        printf("%d ", *pu8Data);
        pu8Data++;
    }
    for(i=0; i<=15; i++)
	{
		pu8Data--;
	}
	printf("\nSuma de todos los numeros del arreglo\n");
    for(i=0; i<=15; i++)
    {
        sumatotal= *pu8Data + sumatotal; 
        pu8Data++;
    }
    
    printf("Suma total: %d", sumatotal); 
    u8Check = sumatotal % 10;
    printf("\nEl residuo es: %d", u8Check);	
	


    return u8Check; 

}
