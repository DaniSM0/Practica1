#include <stdio.h>

typedef unsigned char uint8;
void main()
{
	uint8 u8valor= 0x0; 
	u8valor|= ( 1 << 3 )|(1 << 4);
	printf("La operación OR es: %d\n",u8valor);
	u8valor&=~ ( 1 << 4);
	printf("La operación AND es: %d\n",u8valor);
	u8valor^= ( 1 << 3);
	printf("La operación XOR es: %d\n",u8valor);
 
}
