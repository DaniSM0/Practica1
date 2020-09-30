#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned char uint16;
typedef unsigned char uint32;


void main()
{
	uint32 u32NumBits=0;
	uint32 u32ope=4;

	printf("Escoga el tamaño de su variable 8, 16 o 32 bits: ");
	scanf("%d", &u32NumBits);
	
	if (u32NumBits == 8 || u32NumBits == 16 || u32NumBits == 32)
	{
		while (u32ope > 3)
		{
		    printf("Seleccione una operacion\n1)Operacion OR\n2)Operacion AND\n3)Operacion XOR\n");
		    scanf("%d", &u32ope);
		    if (u32ope >= 1 && u32ope <= 3)
			    printf("La operacion es aceptada\n");
		    else 
			    printf("Error: la operacion escogida no se encuentra en las opciones"); 
	    }
	}
	    else 
		    printf("La variable debe de ser de 8, 16 o 32 bits");
}
