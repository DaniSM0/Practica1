
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


/*Functions Protypers*/

void GENFUN_vCapsOn (uint8 *pu8Src, uint8 u8SizeOfList);
void GENFUN_vCapsOff (uint8 *pu8Src, uint8 u8SizeOfList);
uint8 GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList);
uint8 GENFUN_u8GetAverage (uint8 *pu8Src, uint8 u8SizeOfList);
void GENFUN_u8MemSet (uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList);
void GENFUN_u8MemCopy (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList);

