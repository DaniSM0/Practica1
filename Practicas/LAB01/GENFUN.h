
/*Data types*/

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

/*Defined*/

#define ASCII_LOW_THRESHOLD_ON       96
#define ASCII_HIGH_THRESHOLD_ON      123
#define ASCII_DIFFERENCE_THRESHOLD   32
#define ASCII_LOW_THRESHOLD_OFF      64
#define ASCII_HIGH_THRESHOLD_OFF     91
#define SIZE_OF_ARRAY                254
#define LIMITE_SUPERIOR_DEL_FILTRO   15
#define LIMITE_INFERIOR_DEL_FILTRO   8

/*Functions Protypers*/

void GENFUN_vCapsOn (uint8 *pu8Src, uint8 u8SizeOfList);
void GENFUN_vCapsOff (uint8 *pu8Src, uint8 u8SizeOfList);
uint8 GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList);
uint8 GENFUN_u8GetAverage (uint8 *pu8Src, uint8 u8SizeOfList);
void GENFUN_u8MemSet (uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList);
void GENFUN_u8MemCopy (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList);
void GENFUN_vSoftSignal (uint8 *pu8Src, uint8 *pu8Dest);
void GENFUN_vFilterSignal (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8MaxVal, uint8 u8MinVal);
uint8 printRandoms(uint8 lower, uint8 upper,  uint8 count);
