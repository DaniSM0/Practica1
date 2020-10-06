#include "stdio.h"
#include "GENFUN.h"

void main (void)
{
	uint8 u8Result=0;
	uint8 u8Target='a';

	uint8 au8ListArray[11] = "dani y paty";
	printf("Testing vCaps_On\n");
	printf("Before testing: %s\n", au8ListArray);
	GENFUN_vCapsOn ( &au8ListArray[0], 11);
	printf("After testing: %s\n\n", au8ListArray);
	printf("Testing vCaps_Off\n");
	GENFUN_vCapsOff (&au8ListArray[0], 11);
	printf("After testing: %s\n\n", au8ListArray);
	printf("Testing GetOccurence\n");
	u8Result = GENFUN_u8GetOccurence ( &au8ListArray[0], u8Target, 11 );
	printf("%d", u8Result);

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

}