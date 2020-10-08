#include "stdio.h"
#include "GENFUN.h"
#include <time.h> 

void main (void)
{
	uint8 u8Result=0;
	uint8 u8Target='a';
	uint8 au8ListArray[11] = "dani y paty";
	uint8 au8AverList[10] = {1,2,3,4,5,6,7,8,9,10};
	uint16 u16TotAver = 0;
	uint8 u8Char2Set = 32;
	uint8 au8FirstArray[5] = {5,4,3,2,1};
	uint8 au8SecArray[5] = {1,2,3,4,5};
	uint8 au8Graph [10] = {5,7,4,2,1,8,6,4,3,7};
	srand(time(0));

	printf("\nTesting vCaps_On\n");
	printf("Before testing: %s\n", au8ListArray);
	GENFUN_vCapsOn ( &au8ListArray[0], 11);
	printf("After testing: %s\n\n", au8ListArray);
	printf("Testing vCaps_Off\n");
	GENFUN_vCapsOff ( &au8ListArray[0], 11);
	printf("After testing: %s\n\n", au8ListArray);
	printf("Testing GetOccurence\n");
	u8Result = GENFUN_u8GetOccurence ( &au8ListArray[0], u8Target, 11 );
	printf("%d\n\n", u8Result);
	printf("Testing GetAverage\n");
	u16TotAver = GENFUN_u8GetAverage ( &au8AverList[0], 10 );
	printf("After Testing: %d\n\n", u16TotAver);
	printf("Testing MemSet\n");
	GENFUN_u8MemSet ( &au8AverList[0], u8Char2Set, 5 );
	printf("After Testing: %d\n", au8AverList[0]);
	printf("After Testing: %d\n", au8AverList[1]);
	printf("After Testing: %d\n", au8AverList[2]);
	printf("After Testing: %d\n", au8AverList[3]);
	printf("After Testing: %d\n", au8AverList[4]);
	printf("Testing MemCopy\n");
	GENFUN_u8MemCopy ( &au8FirstArray[0], &au8SecArray[0], 5);
	printf("After testing: %d\n", au8SecArray[0]);
	printf("After testing: %d\n", au8SecArray[1]);
	printf("After testing: %d\n", au8SecArray[2]);
	printf("After testing: %d\n", au8SecArray[3]);
	printf("After testing: %d\n", au8SecArray[4]);

	
	//printf("Testing MemCopy\n");
}

void GENFUN_vCapsOn (uint8 *pu8Src, uint8 u8SizeOfList) 
{
	while (u8SizeOfList != 0)
	{
		if(*pu8Src > ASCII_LOW_THRESHOLD_ON && *pu8Src < ASCII_HIGH_THRESHOLD_ON )
		{
			*pu8Src -= ASCII_DIFFERENCE_THRESHOLD; 
		}
		else
		{
			/*Nothing To Do*/
		}
	pu8Src++;
	u8SizeOfList--;
	}	
}


void GENFUN_vCapsOff (uint8 *pu8Src, uint8 u8SizeOfList) 
{
	while (u8SizeOfList !=0 )
	{
		if (  *pu8Src > ASCII_LOW_THRESHOLD_OFF && *pu8Src < ASCII_HIGH_THRESHOLD_OFF)
		{
			*pu8Src += ASCII_DIFFERENCE_THRESHOLD;
		}
		else
		{
			/*Nothing To Do*/
		}
	pu8Src++;
	u8SizeOfList--;
	}
}


uint8 GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList) 
{
	uint8 u8NumTar=0;
	while (u8SizeOfList !=0 )
	{
		if ( *pu8Src == u8Target )
		{
			u8NumTar++;
		}
		else
		{
			/*Nothing To Do*/
		}
		pu8Src++;
		u8SizeOfList--;
	}
	return u8NumTar;
}

uint8 GENFUN_u8GetAverage (uint8 *pu8Src, uint8 u8SizeOfList)
{
	uint16 u16Average=0;
	uint8 u8Elements= u8SizeOfList;
	while ( u8SizeOfList !=0 )
	{
		u16Average += *pu8Src;
		pu8Src++;
		u8SizeOfList--;
	}
	u16Average /= u8Elements;
	return u16Average;
}


void GENFUN_u8MemSet (uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList)
{
	while (u8SizeOfList !=0 )
	{
		*pu8Src = u8Char2Set;
		pu8Src++;
		u8SizeOfList--;
	}
}

void GENFUN_u8MemCopy (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList)
{
	while (u8SizeOfList != 0 )
	{
		*pu8Dest = *pu8Src;
		pu8Src++;
		pu8Dest++;
		u8SizeOfList--;
	}
}

void GENFUN_vSortList (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList)
{

}

void GENFUN_vSoftSignal (uint8 *pu8Src, uint8 *pu8Dest)
{
	uint8 u8Test = 0;
	while ( u8Test )
}

uint8 printRandoms(uint8 lower, uint8 upper,  uint8 count) 
{ 
    uint8 i; 
    uint8 num;
    num = (rand() % (upper - lower + 9)) + lower; 
    //printf("%d \n", num); 
    return num;
} 