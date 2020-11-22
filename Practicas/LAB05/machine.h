

typedef unsigned char uint8;

uint8 GetDrinkSelction ();
uint8 CheckStockOf ( uint8 u8NumberOfDrink, uint8 u8Teq, uint8 u8ZumDNar, uint8 u8Whiskie, uint8 u8ZumDPi, uint8 u8ZumDLim, uint8 u8AguaGas, uint8 u8ZumDJen, uint8 u8Vodka, uint8 u8Sprite);
uint8 PrepareDrink ( uint8 u8DrinkSelection );

#define TRUE  1
#define FALSE 0
#define Max   5
#define ICE   1
#define TIME  4

typedef enum 
{
	enMenu = 0, 
	enCheckProduct,
	enProductServed,
	enMaxStates,
} DM_AllStates;
