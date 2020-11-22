#include <stdio.h>
#include <stdlib.h>
#include "machine.h"
#include <time.h>


void main(void)
{
	DM_AllStates enCurrentState= enMenu;
	uint8 u8DrinkSelection = 0; 
	uint8 u8Stock; 
	uint8 u8Teq = 0;
	uint8 u8Whiskie = 0;
	uint8 u8Vodka = 0;
	uint8 u8ZumDNar = 0; 
	uint8 u8ZumDLim = 0; 
	uint8 u8ZumDPi = 0; 
	uint8 u8AguaGas = 0;
	uint8 u8ZumDJen = 0;  
	uint8 u8Sprite = 0;
	uint8 au8OrderOfDrinks[11]= {0,1,2,3,4,5,6,7,8,9,10};
	//0)inicio 1)hielo 2)tequila 3)whiskie 4)vodka 5)zumo de naranja 6)zumo de limon 7)zumo de piña 8)agua con gas 9)zumo de jengibre 10)sprite

	while (1)
	{
	
		switch ( enCurrentState )
		{
			case enMenu: 
			{
				u8DrinkSelection = GetDrinkSelction();
				if (u8DrinkSelection != 0)
				{
					enCurrentState = enCheckProduct;
				}
				else
				{
					/*Nothing to do*/
				}
				break;
			}
			case enCheckProduct: 
			{
				if( u8DrinkSelection == 1 )
				{
					u8Teq++; 
	   				u8ZumDNar++;
	   				printf("\n teq: %d nara: %d \n", u8Teq, u8ZumDNar);
				}
				if( u8DrinkSelection == 2 )
				{
					u8ZumDPi++; 
	   				u8ZumDNar++;
	   				u8Teq++;
	   				printf("\n teq: %d nar: %d pi: %d\n", u8Teq, u8ZumDNar, u8ZumDPi);
	   			}
	   			if( u8DrinkSelection == 3)
				{
					u8Whiskie++; 
	   				u8ZumDLim++;
	   				u8AguaGas++;
	   				printf("\n whi: %d lim: %d agu: %d\n", u8Whiskie, u8ZumDLim, u8AguaGas);
				}
				if( u8DrinkSelection == 4 )
				{
					u8Whiskie++; 
	   				u8ZumDLim++;
	   				u8ZumDJen++;
	   				printf("\n whi: %d lim: %d jen: %d \n", u8Whiskie, u8ZumDLim, u8ZumDJen);
				}
				if( u8DrinkSelection == 5 )
				{
					u8Vodka++; 
	   				u8ZumDNar++;
	   				u8ZumDPi++;
	   				printf("\n vod: %d nar: %d pi: %d\n", u8Vodka, u8ZumDNar, u8ZumDPi);
				}
				if( u8DrinkSelection == 6 )
				{
					u8Vodka++; 
	   				u8Sprite++;
	   			    printf("\n vod: %d spri: %d \n", u8Vodka, u8Sprite);
	   			}
				u8Stock = CheckStockOf ( u8DrinkSelection, u8Teq, u8ZumDNar, u8Whiskie, u8ZumDPi, u8ZumDLim, u8AguaGas, u8ZumDJen, u8Vodka, u8Sprite);
				if( u8Stock == 1 )
				{
					enCurrentState = enProductServed;
				}
				else
				{
					enCurrentState = enMenu;
				}
				break;
			}
			case enProductServed:
			{ 
				PrepareDrink ( u8DrinkSelection );
				enCurrentState = enMenu;

				break; 
			}
		}
	}
}


uint8 CheckStockOf ( uint8 u8NumberOfDrink, uint8 u8Teq, uint8 u8ZumDNar, uint8 u8Whiskie, uint8 u8ZumDPi, uint8 u8ZumDLim, uint8 u8AguaGas, uint8 u8ZumDJen, uint8 u8Vodka, uint8 u8Sprite)
{
uint8 x, y, z; 
uint8 u8Stock; 

   if( u8NumberOfDrink == 1 )
   {
	   	printf("La bebida contiene: zumo de naranja, tequila");
	   	if ( u8Teq >= Max )
	   	{
	   		x = 0;
	   	}
	   	else
	   	{
	   		x = 1; 
	   	}
	   	if (u8ZumDNar >= Max)
	   	{
	   		y = 0; 
	   	}
	   	else
	   	{
	   		y = 1;
	   	}
	   	if ( x == 1 && y == 1 )
	   	{
	   		u8Stock = 1; 
	   	}
	   	else
	   	{
	   		u8Stock = 0; 
	   		printf("\nNo hay suficiente producto para hacer la bebida");
	   	}
	}
   else if ( u8NumberOfDrink == 2 )
   {
   		printf("La bebida tiene: tequila, zumo de pina, zumo de naranja ");
   		if ( u8Teq >= Max )
	   	{ 
	   		x = 0;
	   	}
	   	else
	   	{
	   		x = 1; 
	   	}
	   	if (u8ZumDNar >= Max)
	   	{
	   		y = 0; 
	   	}
	   	else
	   	{
	   		y = 1;
	   	}
	   	if ( u8ZumDPi >= Max )
	   	{
	   		z = 0;
	   	}
	   	else
	   	{
	   		z = 1; 
	   	}
	   	if ( x == 1 && y == 1 && z == 1 )
	   	{
	   		u8Stock = 1; 
	   	}
	   	else
	   	{
	   		u8Stock = 0; 
	   		printf("\nNo hay suficiente producto para hacer la bebida");
	   	}
   }
   else if ( u8NumberOfDrink == 3 )
   {
   		printf("La bebida tiene: whiskie, zumo de limon, agua con gas ");
   	    if ( u8Whiskie >= Max )
	   	{ 
	   		x = 0;
	   	}
	   	else
	   	{
	   		x = 1; 
	   	}
	   	if (u8ZumDLim >= Max)
	   	{
	   		y = 0; 
	   	}
	   	else
	   	{
	   		y = 1;
	   	}
	   	if ( u8AguaGas >= Max )
	   	{
	   		z = 0;
	   	}
	   	else
	   	{
	   		z = 1; 
	   	}
	   	
	   	if ( x == 1 && y == 1 && z == 1 )
	   	{
	   		u8Stock = 1; 
	   	}
	   	else
	   	{
	   		u8Stock = 0; 
	   		printf("\nNo hay suficiente producto para hacer la bebida");
	   	}
   }
   else if ( u8NumberOfDrink == 4 )
   {
   		printf("La bebida tiene: whiskie, zumo de jengibre, zumo de limon ");
        if ( u8Whiskie >= Max )
	   	{ 
	   		x = 0;
	   	}
	   	else
	   	{
	   		x = 1; 
	   	}
	   	if (u8ZumDLim >= Max)
	   	{
	   		y = 0; 
	   	}
	   	else
	   	{
	   		y = 1;
	   	}
	   	if ( u8ZumDJen >= Max )
	   	{
	   		z = 0;
	   	}
	   	else
	   	{
	   		z = 1; 
	   	}
	   	if ( x == 1 && y == 1 && z == 1 )
	   	{
	   		u8Stock = 1; 
	   	}
	   	else
	   	{
	   		u8Stock = 0; 
	   		printf("\nNo hay suficiente producto para hacer la bebida");
	   	}
   }
   else if ( u8NumberOfDrink == 5 )
   {
   		printf("La bebida tiene: vodka, zumo de naranja, zumo de pina ");
   	    if ( u8Vodka >= Max )
	   	{ 
	   		x = 0;
	   	}
	   	else
	   	{
	   		x = 1; 
	   	}
	   	if (u8ZumDNar >= Max)
	   	{
	   		y = 0; 
	   	}
	   	else
	   	{
	   		y = 1;
	   	}
	   	if ( u8ZumDPi >= Max )
	   	{
	   		z = 0;
	   	}
	   	else
	   	{
	   		z = 1; 
	   	}
	   	if ( x == 1 && y == 1 && z == 1 )
	   	{
	   		u8Stock = 1; 
	   	}
	   	else
	   	{
	   		u8Stock = 0; 
	   		printf("\nNo hay suficiente producto para hacer la bebida");
	   	}
   }
   else
   {
   		printf("La bebida tiene: vodka, sprite");
   	    if ( u8Vodka >= Max )
	   	{
	   		x = 0;
	   	}
	   	else
	   	{
	   		x = 1; 
	   	}
	   	if (u8Sprite >= Max)
	   	{
	   		y = 0; 
	   	}
	   	else
	   	{
	   		y = 1;
	   	}	   	
	   	if ( x == 1 && y == 1 )
	   	{
	   		u8Stock = 1; 
	   	}
	   	else
	   	{
	   		u8Stock = 0; 
	   		printf("\nNo hay suficiente producto para hacer la bebida");
	   	}
   }
 return u8Stock; 
}


uint8 GetDrinkSelction ()
{
	uint8 u8DrinkSelection;
	uint8 u8TryAgain = 0;  
	
	printf("\n\nQue licor le gustaria? \nTEQUILA 1)Sunrise 2)Nieblas del Caribe"); 
	printf("\n\nWHISKIE: 3)Coctel Jack Julep 4)Peniciina");
	printf("\n\nVODKA: 5)Coctel Veracruz 6)Vodka con Sprite\n");
	scanf("%d", &u8DrinkSelection );
	/*if ( u8DrinkSelection != 1 || u8DrinkSelection != 2 || u8DrinkSelection != 3 || u8DrinkSelection != 4 || u8DrinkSelection != 5 || u8DrinkSelection != 6)
		{
			printf("La bebida no se encuentra en las opciones\n");
		}
	    else
		{
		    /*Nothing To Do
		}*/
	return u8DrinkSelection;
}

uint8 PrepareDrink ( uint8 u8DrinkSelection )
{
	uint8 i;
	uint8 t; 
	uint8 n;

	if ( u8DrinkSelection == 1)
	{
		printf("\nEmpezando a hacer bebida\n");
		for( i=0; i<=1; i++)
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i; 
		}
		for( t=0; t<=1; t++)
		{
			printf("Se esta sirviendo el hielo\n");
		}
		printf("\n");
		for( i=n; i<=2; i++) 
		{
		printf("El vaso se encuentra en las posicion %d\n", i);
		n=i; 
		}
		for( t= 0; t<=4; t++)
		{
		printf("Se esta sirviendo tequila\n");
		}
		printf("\n");
		for( i=n; i<=5; i++) 
		{
		printf("El vaso se encuentra en las posicion %d\n", i);
		n=i;
		}
		for( t= 0; t<=4; t++)
		{
			printf("Se esta sirviendo el zumo de naranja\n");
		}
			printf("\n\nDisfrute su bebida");
	}
	else if ( u8DrinkSelection == 2) 
	{
		printf("\nEmpezando a hacer bebida\n");
		for( i=0; i<=1; i++)
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i; 
		}
		for( t=0; t<=1; t++)
		{
			printf("Se esta sirviendo el hielo\n");
		}
		    printf("\n");
		for( i=n; i<=2; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i; 
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo tequila\n");
		}
			printf("\n");
		for( i=n; i<=5; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i;
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo el zumo de naranja\n");
		}
			printf("\n");
		for( i=n; i<=7; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i;
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo el zumo de pina\n");
		}
		printf("\n\nDisfrute su bebida");
	} 
	else if ( u8DrinkSelection == 3)
	{
	    printf("\nEmpezando a hacer bebida\n");
		for( i=0; i<=1; i++)
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i; 
		}
		for( t=0; t<=1; t++)
		{
			printf("Se esta sirviendo el hielo\n");
		}
		    printf("\n");
		for( i=n; i<=3; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i; 
		}
		for( t= 0; t<=4; t++)
		{
			printf("Se esta sirviendo whisky\n");
		}
			printf("\n");
		for( i=n; i<=6; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i;
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo el zumo de limon\n");
		}
			printf("\n");
		for( i=n; i<=8; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i;
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo el agua con gas\n");
		}
		printf("\n\nDisfrute su bebida");
	}
	else if ( u8DrinkSelection == 4)
	{
	    printf("\nEmpezando a hacer bebida\n");
		for( i=0; i<=1; i++)
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i; 
		}
		for( t=0; t<=1; t++)
		{
			printf("Se esta sirviendo el hielo\n");
		}
		    printf("\n");
		for( i=n; i<=3; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i; 
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo whisky\n");
		}
			printf("\n");
		for( i=n; i<=6; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i;
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo el zumo de limon\n");
		}
			printf("\n");
		for( i=n; i<=9; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i;
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo el zumo de jengibre\n");
		}
		printf("\n\nDisfrute su bebida");
	}
	else if ( u8DrinkSelection == 5 )
	{
		printf("\nEmpezando a hacer bebida\n");
		for( i=0; i<=1; i++)
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i; 
		}
		for( t=0; t<=1; t++)
		{
			printf("Se esta sirviendo el hielo\n");
		}
		    printf("\n");
		for( i=n; i<=4; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i; 
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo vodka\n");
		}
			printf("\n");
		for( i=n; i<=5; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i;
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo el zumo de naranja\n");
		}
			printf("\n");
		for( i=n; i<=7; i++) 
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i;
		}
		for( t= 0; t<=3; t++)
		{
			printf("Se esta sirviendo el zumo de pina\n");
		}
		printf("\n\nDisfrute su bebida");
	} 
	else 
	{
		printf("\nEmpezando a hacer bebida\n");
		for( i=0; i<=1; i++)
		{
			printf("El vaso se encuentra en las posicion %d\n", i);
			n=i; 
		}
		for( t=0; t<=1; t++)
		{
			printf("Se esta sirviendo el hielo\n");
		}
		printf("\n");
		for( i=n; i<=4; i++) 
		{
		printf("El vaso se encuentra en las posicion %d\n", i);
		n=i; 
		}
		for( t= 0; t<=4; t++)
		{
		printf("Se esta sirviendo vodka\n");
		}
		printf("\n");
		for( i=n; i<=10; i++) 
		{
		printf("El vaso se encuentra en las posicion %d\n", i);
		n=i;
		}
		for( t= 0; t<=4; t++)
		{
			printf("Se esta sirviendo sprite\n");
		}
			printf("\n\nDisfrute su bebida");
	}

}


//Orden de las bebidas en la máquina. 
//1)hielo 2)tequila 3)whiskie 4)vodka 5)zumo de naranja 6)zumo de limon 7)zumo de piña 8)agua con gas 9)zumo de jengibre 10)sprite
// Sunrise ----> zumo de naranja, tequila
// Nieblas del Caibe ----> zumo de piña, zumo de naranja
//Cóctel Jack Julep ----> whiskie, zumo de limón, agua con gas, hielo
// PeniciLina ---> whiskie, zumo de jengibre, zumo de limon
//Coctel Veracruz ---> vodka, zumo de naranja, zumo de piña
// Vodka con sprite ---> vodka, sprite
//void CheckStockOf ( uint8 u8NumberOfDrink, uint8 u8Teq, uint8 u8Whiskie, uint8 u8Vodka, uint8 u8ZumDNar, uint8 u8ZumDPi, uint8 u8AguaGas, uint8 u8ZumDJen, uint8 u8Sprite, uint8 u8Stock)