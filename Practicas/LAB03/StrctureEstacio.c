#include "stdio.h"
#include "structs1.h"
#include <stdlib.h>

/* Descripcion 

->Crear un programa que simule un estacionamiento con 5 diferentes secciones 0, 1, 2, 3 o 4. Cada seccion tendra un cupo maximo de carros que sera definido por Defines diferentes. 
->Se tiene que usar un arreglo de estructuras para manejar los estacionamientos, la estructura es la de abajo.
->El programa correra en un ciclo infinito y habra funciones aleatorias que metan y saquen carros de las diferentes secciones.
->El programa debe tener una logica que atienda las peticiones siguientes con funciones:
	*Obtener el numero de espacios disponibles de una seccion (F1)
	*Obtener el numero de espacios no disponibles de una seccion (F2)
	*Obtener ganancias de sección(F3)
	*Registrar vehiculo ingresado(F4)
	*Remover vehiculo(F5)
	*Registrar pago de vehiculo ingresado(F6)
*/

/* Fucniones */
/*
->(F1) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de espacios disponibles de esa seccion
->(F2) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de espacios no disponibles de esa seccion
->(F3) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de dinero acumulada en esa sección
->(F4) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y permita ingresar un vehiculo a esa seccion
->(F5) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y permita retirar un vehiculo de la cuenta de la seccion
->(F6) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y registre el pago por haber ingresado el vehiculo
*/


tstParkingInfo astMyParks[enMaxSectors] = INIT_PARKING_SLOTS;						/*Struct to Use*/

void main ( void )
{
	uint8 u8InputAction = 0;
	tenParkingSectors enSector; 
	uint8 u8ConfirmationFromAction = 0;
	uint8 u8AddCarToOtherFunction = 0;
	while(1)
	{
		fflush(stdin);
		
		printf("Press 1 to -> Read Available Slots\n");
		printf("Press 2 to -> Read Unavailable Slots\n");
		printf("Press 3 to -> Read Earned Money\n");
		printf("Press 4 to -> Enter a Car to a Section\n");
		printf("Press 5 to -> Remove a Car from a Section\n");
		printf("Press 6 to -> Print Parking Ticket\n");

		printf("Enter selection: ");
		scanf("%d", &u8InputAction);
		printf("Action Selected %d\n", u8InputAction );

		printf("Enter Sector from 0 to 4: ");
		scanf("%d", &enSector);
		printf("Sector Selected %d\n", enSector );

		if( enSector < enMaxSectors )
		{
			if( u8InputAction == 1 )
			{
				ShowAvailableSlots( enSector );
			}
			else if( u8InputAction == 2 )
			{
				
				ShowNotAvailableSlots( enSector );
			}
			else if( u8InputAction == 3 )
			{
					ShowEarnedMoney(enSector, u8AddCarToOtherFunction);
			}
			else if( u8InputAction == 4 )
			{
				uint8 u8Add= u8AddCarToSector( enSector );
				u8AddCarToOtherFunction++;
				
			}
			else if ( u8InputAction == 5 )
			{
				uint8 u8Remove =u8RemoveCarFromSector( enSector );
			}
			else
			{
				u8ImportPaymentOfSlot( enSector );
			}
			printf("\n\n");
		}
		else
		{
			/*Not a valid sector*/
		}

	}
}

/*F1*/
void ShowAvailableSlots ( tenParkingSectors enCurrentSector )
{
	if( enCurrentSector == 0 || enCurrentSector == 1 || enCurrentSector == 2 || enCurrentSector == 3 || enCurrentSector == 4)
	{
		if( astMyParks[enCurrentSector].u8AvailableSlots != 0)
		{
			printf("Sector %d has %d available slots", enCurrentSector, astMyParks[enCurrentSector].u8AvailableSlots );
		}
		else
		{
			printf("Sector %d has no avialable slots", enCurrentSector);
		}
	}
}

/*F2*/
void ShowNotAvailableSlots ( tenParkingSectors enCurrentSector )
{
	if( enCurrentSector == 0 || enCurrentSector == 1 || enCurrentSector == 2 || enCurrentSector == 3 || enCurrentSector == 4)
	{
		if (astMyParks[enCurrentSector].u8NotAvailableSlots == 0)
		{
			printf("All spots of sector %d are available", enCurrentSector, astMyParks[enCurrentSector].u8NotAvailableSlots );

		}
		else 
		{
			printf("Sector %d has %d spot/s taken", enCurrentSector, astMyParks[enCurrentSector].u8NotAvailableSlots );
		}
	}
}

/*F3*/
void ShowEarnedMoney ( tenParkingSectors enCurrentSector, uint8 u8AddCarToOtherFunction)
{
	uint32 u32SumOfMoney = 0; 
	if( enCurrentSector == 0 || enCurrentSector == 1 || enCurrentSector == 2 || enCurrentSector == 3 || enCurrentSector == 4)
	{
		if(u8AddCarToOtherFunction >= 1 )
		{
			u32SumOfMoney = u8AddCarToOtherFunction*10; 
			printf("Total: %d in sector %d ", u32SumOfMoney, enCurrentSector);
		}
		else 
		{
			printf("No cars in yet");
		}
	}
	else
	{
		/*Nothing to do*/
	}
}
/*F4*/
uint8 u8AddCarToSector( tenParkingSectors enCurrentSector )
{
	uint8 u8ToSaveAddCar = 0;
	if( enCurrentSector == 0 || enCurrentSector == 1 || enCurrentSector == 2 || enCurrentSector == 3 || enCurrentSector == 4)
	{
		if( astMyParks[enCurrentSector].u8AvailableSlots != 0)
		{
			astMyParks[enCurrentSector].u8AvailableSlots--;
			astMyParks[enCurrentSector].u8NotAvailableSlots++;
			u8ToSaveAddCar = astMyParks[enCurrentSector].u8AvailableSlots;
			printf("Sector %d has now %d spots available", enCurrentSector, astMyParks[enCurrentSector].u8AvailableSlots );
		}
		else
		{
			printf("All slots are taken");
		}
	}
	return u8ToSaveAddCar;
}
/*F5*/
uint8 u8RemoveCarFromSector( tenParkingSectors enCurrentSector )
{
	uint8 Remove=0;
	if( enCurrentSector == 0 || enCurrentSector == 1 || enCurrentSector == 2 || enCurrentSector == 3 || enCurrentSector == 4)
	{
		if( astMyParks[enCurrentSector].u8AvailableSlots != 0 )
		{
			if(astMyParks[enCurrentSector].u8NotAvailableSlots > 0)
			{
				astMyParks[enCurrentSector].u8AvailableSlots++;
				astMyParks[enCurrentSector].u8NotAvailableSlots--;
				printf("Sector %d now has %d spots available", enCurrentSector, astMyParks[enCurrentSector].u8AvailableSlots );
			}
			else
			{
				printf("No cars parked");
			}
		}
		else
		{
			/*Nothing to do*/
		}

	}
	return Remove;
}
/*F6*/
void u8ImportPaymentOfSlot( tenParkingSectors enCurrentSector )
{
	if( enCurrentSector == 0 || enCurrentSector == 1 || enCurrentSector == 2 || enCurrentSector == 3 || enCurrentSector == 4)
	{
		if( astMyParks[enCurrentSector].u8NotAvailableSlots != 0 )
		{
			printf("Thanks for trusting us. Enjoy your stay. Your car is in section %d", enCurrentSector);
		}
		else 
		{
			printf("No cars parked");
		}
	}
}