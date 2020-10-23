#include "stdio.h"
#include "time.h"

typedef unsigned char uint8; 
typedef unsigned short uint16;
uint8 u8LuchCheck (uint8 *pu8Data, uint8 u8SizeOfList);

void main() 
{
	uint8 au8NumOfCard[16]= {8,2,4,1,3,7,9,2,4,7,9,1,9,7,6,3};
	uint8 u8Check = 0;
	uint8 i;
	printf("Check array\n");
	for(i=0; i<=15; i++)
	{
	printf( "%d ", au8NumOfCard[i]);
	}
	u8Check = u8LuchCheck ( &au8NumOfCard[i], 16);

	if ( u8Check == 0)
	{
		printf("\nLa tarjeta es válida");
	}
	if (u8Check > 0)
	{
		printf("\nLa tarjeta no es válida");
	}
}

uint8 u8LuchCheck (uint8 *pu8Data, uint8 u8SizeOfList)
{
	uint8 i;
	uint8 j;
	uint8 n;
	uint8 residuo;
	uint8 sumatotal = 0 ;
	uint8 modu;
	uint8 valid; 
	uint8 suma= 0;
	uint8 u8Check;

	for( i = 0; i <= 15; i+=2)
	{
		n = *pu8Data; 
		n =2*n;
		*pu8Data = n;
	}
	printf("\nSuma del residuo"); 
	for(i=0; i<=15; i++)
    {
        if (*pu8Data >= 10)
        {
            j = *pu8Data;
            residuo = j % 10;
            suma = residuo + 1;
            *pu8Data = suma;
            printf("%d ", *pu8Data);
        }
        else 
        {
            /*Nothing to do*/
        }
    }
    printf("\nIprimir todo el arreglo\n");
    for(i=0; i<=15; i++)
    {
        printf("%d ", *pu8Data);
    }
    
    printf("\nSuma de todos los números del arreglo\n");
    for(i=0; i<=15; i++)
    {
        sumatotal= *pu8Data + sumatotal; 
    }
    printf("Suma total: %d", sumatotal); 
    u8Check = sumatotal % 10;
    printf("\nEl residuo es: %d", u8Check);

    return u8Check; 

}
