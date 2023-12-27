/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */



#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_


/***********************************************************************************/
/*  								REGISTERS ADDRESSES							   */
/***********************************************************************************/
#define  TWBR        *((volatile u8*)  0x20)
#define  TWSR        *((volatile u8*)  0x21)
#define  TWAR        *((volatile u8*)  0x22)
#define  TWCR        *((volatile u8*)  0x56)
#define  TWDR        *((volatile u8*)  0x23)
/***********************************************************************************/



/***********************************************************************************/
/*  						TWI Control Register -TWCR							   */
/***********************************************************************************/
#define TWINT     7
#define TWEA      6
#define TWSTA     5
#define TWSTO     4
#define TWWC      3
#define TWEN      2
#define TWIE      0
/***********************************************************************************/




/***********************************************************************************/
/*  				    	TWI Status Register -TWSR							   */
/***********************************************************************************/
#define TWS7      7
#define TWS6      6
#define TWS5      5
#define TWS4      4
#define TWS3      3
#define TWPS1     1
#define TWPS0     0



/***********************************************************************************/
/*  				    	TWI Slave Adress Register -TWAR						   */
/***********************************************************************************/
#define TWGCE     0

/***********************************************************************************/


/*STATUS OF TWSR REGISTER */
#define STARTCONDITION            0x08  //00001000
#define SendSlaveAdressWithWrite  0x18  //00011000
#define SendSlaveAdressWithRead   0x40  //01000000
#define MasterSendData            0x28  //00101000
#define MasterReceieveDataACK     0x50  //01010000
#define MasterReceieveDataNACK    0x58  //01010000
#define RESTART                   0x10  //00010000
#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
