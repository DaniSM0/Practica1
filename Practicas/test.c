#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned char uint16;
typedef unsigned char uint32;
void main()
{
	uint8 u8valor= 0x0; 
	uint16 u16valor= 0x0;
	uint32 u32valor= 0x0;
	uint8 u8bits;
	uint8 u8ope;
	printf("Escoga el tamaño de su variable 8, 16 o 32 bits: ");
	scanf("%d", &u8bits);
	printf("\nEl numero que escogio fue %d\n", u8bits);
	if (u8bits==8|| u8bits==16|| u8bits==32)
	{
		printf("Seleccione una operacion\n1)Operacion OR\n2)Operacion AND\n3)Operacion XOR\n");
		scanf("%d", &u8ope);
		if (u8ope >= 1 && u8ope <= 3)
			printf("La operacion es acpetada\n");
		else 
			printf("Error: la opción escogida no se encuentra en las opciones"); 
	}
	else 
		printf("La variable debe de ser de 8, 16 o 32 bits");
}
