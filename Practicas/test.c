#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;


void main()
{
	uint32 u32NumBits=0;
	uint32 u32Ope=4;
	uint32 u32CorVar=0;

	printf("Escoga el tamano de su variable 8, 16 o 32 bits: ");
	scanf("%d", &u32NumBits);
	
	if (u32NumBits == 8 || u32NumBits == 16 || u32NumBits == 32)
	{
		while (u32Ope > 3 )
		{
		    printf("Seleccione una operacion\n");
		    printf("1)Operacion OR\n");
		    printf("2)Operacion AND\n");
		    printf("3)Operacion XOR\n");
		    scanf("%d", &u32Ope);
		    if (u32Ope >= 1 && u32Ope <= 3)
		    {
			    printf("Corrimiento para la operacion: ");
			    scanf("%d", &u32CorVar);
			    if (u32CorVar > u32NumBits)
			    	printf("Error: El numero es mayor al numero de bits");
			    else 
			    {
			    	printf("Realizar la operación");
			    }
			}
		    else 
			    printf("Error: la operacion escogida no se encuentra en las opciones"); 
	    }
	}
	    else 
		    printf("La variable debe de ser de 8, 16 o 32 bits");
}
