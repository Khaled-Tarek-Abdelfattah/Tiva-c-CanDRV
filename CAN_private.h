 /******************************************************************************
 *
 * Module: CAN
 *
 * File Name: CAN_Private.h
 *
 * Description: Register and Preprocessor definition file for the TM4C123GH6PM Microcontroller - CAN driver
 *
 * Author: Khaled Tarek
 *
 *******************************************************************************/


#ifndef CAN_PRIVATE_H_
#define CAN_PRIVATE_H_

#include "Std_Types.h"

//*****************************************************************************
//
// CAN registers (CAN0)
//
//*****************************************************************************
#define CAN0_CTL_R              (*((volatile unsigned long *)0x40040000))
#define CAN0_STS_R              (*((volatile unsigned long *)0x40040004))
#define CAN0_ERR_R              (*((volatile unsigned long *)0x40040008))
#define CAN0_BIT_R              (*((volatile unsigned long *)0x4004000C))
#define CAN0_INT_R              (*((volatile unsigned long *)0x40040010))
#define CAN0_TST_R              (*((volatile unsigned long *)0x40040014))
#define CAN0_BRPE_R             (*((volatile unsigned long *)0x40040018))
#define CAN0_IF1CRQ_R           (*((volatile unsigned long *)0x40040020))
#define CAN0_IF1CMSK_R          (*((volatile unsigned long *)0x40040024))
#define CAN0_IF1MSK1_R          (*((volatile unsigned long *)0x40040028))
#define CAN0_IF1MSK2_R          (*((volatile unsigned long *)0x4004002C))
#define CAN0_IF1ARB1_R          (*((volatile unsigned long *)0x40040030))
#define CAN0_IF1ARB2_R          (*((volatile unsigned long *)0x40040034))
#define CAN0_IF1MCTL_R          (*((volatile unsigned long *)0x40040038))
#define CAN0_IF1DA1_R           (*((volatile unsigned long *)0x4004003C))
#define CAN0_IF1DA2_R           (*((volatile unsigned long *)0x40040040))
#define CAN0_IF1DB1_R           (*((volatile unsigned long *)0x40040044))
#define CAN0_IF1DB2_R           (*((volatile unsigned long *)0x40040048))
#define CAN0_IF2CRQ_R           (*((volatile unsigned long *)0x40040080))
#define CAN0_IF2CMSK_R          (*((volatile unsigned long *)0x40040084))
#define CAN0_IF2MSK1_R          (*((volatile unsigned long *)0x40040088))
#define CAN0_IF2MSK2_R          (*((volatile unsigned long *)0x4004008C))
#define CAN0_IF2ARB1_R          (*((volatile unsigned long *)0x40040090))
#define CAN0_IF2ARB2_R          (*((volatile unsigned long *)0x40040094))
#define CAN0_IF2MCTL_R          (*((volatile unsigned long *)0x40040098))
#define CAN0_IF2DA1_R           (*((volatile unsigned long *)0x4004009C))
#define CAN0_IF2DA2_R           (*((volatile unsigned long *)0x400400A0))
#define CAN0_IF2DB1_R           (*((volatile unsigned long *)0x400400A4))
#define CAN0_IF2DB2_R           (*((volatile unsigned long *)0x400400A8))
#define CAN0_TXRQ1_R            (*((volatile unsigned long *)0x40040100))
#define CAN0_TXRQ2_R            (*((volatile unsigned long *)0x40040104))
#define CAN0_NWDA1_R            (*((volatile unsigned long *)0x40040120))
#define CAN0_NWDA2_R            (*((volatile unsigned long *)0x40040124))
#define CAN0_MSG1INT_R          (*((volatile unsigned long *)0x40040140))
#define CAN0_MSG2INT_R          (*((volatile unsigned long *)0x40040144))
#define CAN0_MSG1VAL_R          (*((volatile unsigned long *)0x40040160))
#define CAN0_MSG2VAL_R          (*((volatile unsigned long *)0x40040164))

//*****************************************************************************
//
// CAN registers (CAN1)
//
//*****************************************************************************
#define CAN1_CTL_R              (*((volatile unsigned long *)0x40041000))
#define CAN1_STS_R              (*((volatile unsigned long *)0x40041004))
#define CAN1_ERR_R              (*((volatile unsigned long *)0x40041008))
#define CAN1_BIT_R              (*((volatile unsigned long *)0x4004100C))
#define CAN1_INT_R              (*((volatile unsigned long *)0x40041010))
#define CAN1_TST_R              (*((volatile unsigned long *)0x40041014))
#define CAN1_BRPE_R             (*((volatile unsigned long *)0x40041018))
#define CAN1_IF1CRQ_R           (*((volatile unsigned long *)0x40041020))
#define CAN1_IF1CMSK_R          (*((volatile unsigned long *)0x40041024))
#define CAN1_IF1MSK1_R          (*((volatile unsigned long *)0x40041028))
#define CAN1_IF1MSK2_R          (*((volatile unsigned long *)0x4004102C))
#define CAN1_IF1ARB1_R          (*((volatile unsigned long *)0x40041030))
#define CAN1_IF1ARB2_R          (*((volatile unsigned long *)0x40041034))
#define CAN1_IF1MCTL_R          (*((volatile unsigned long *)0x40041038))
#define CAN1_IF1DA1_R           (*((volatile unsigned long *)0x4004103C))
#define CAN1_IF1DA2_R           (*((volatile unsigned long *)0x40041040))
#define CAN1_IF1DB1_R           (*((volatile unsigned long *)0x40041044))
#define CAN1_IF1DB2_R           (*((volatile unsigned long *)0x40041048))
#define CAN1_IF2CRQ_R           (*((volatile unsigned long *)0x40041080))
#define CAN1_IF2CMSK_R          (*((volatile unsigned long *)0x40041084))
#define CAN1_IF2MSK1_R          (*((volatile unsigned long *)0x40041088))
#define CAN1_IF2MSK2_R          (*((volatile unsigned long *)0x4004108C))
#define CAN1_IF2ARB1_R          (*((volatile unsigned long *)0x40041090))
#define CAN1_IF2ARB2_R          (*((volatile unsigned long *)0x40041094))
#define CAN1_IF2MCTL_R          (*((volatile unsigned long *)0x40041098))
#define CAN1_IF2DA1_R           (*((volatile unsigned long *)0x4004109C))
#define CAN1_IF2DA2_R           (*((volatile unsigned long *)0x400410A0))
#define CAN1_IF2DB1_R           (*((volatile unsigned long *)0x400410A4))
#define CAN1_IF2DB2_R           (*((volatile unsigned long *)0x400410A8))
#define CAN1_TXRQ1_R            (*((volatile unsigned long *)0x40041100))
#define CAN1_TXRQ2_R            (*((volatile unsigned long *)0x40041104))
#define CAN1_NWDA1_R            (*((volatile unsigned long *)0x40041120))
#define CAN1_NWDA2_R            (*((volatile unsigned long *)0x40041124))
#define CAN1_MSG1INT_R          (*((volatile unsigned long *)0x40041140))
#define CAN1_MSG2INT_R          (*((volatile unsigned long *)0x40041144))
#define CAN1_MSG1VAL_R          (*((volatile unsigned long *)0x40041160))
#define CAN1_MSG2VAL_R          (*((volatile unsigned long *)0x40041164))

//*****************************************************************************
//
// The following are defines for the NVIC configuration
//
//*****************************************************************************

#define INT_CAN0                55          
#define INT_CAN1                56          
#define CAN0_PRI9_0FFSET_M      29
#define CAN1_PRI10_0FFSET_M      5

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_CTL register.
//
//*****************************************************************************
#define CAN_CTL_TEST            0x00000080  
#define CAN_CTL_CCE             0x00000040  
#define CAN_CTL_DAR             0x00000020  
#define CAN_CTL_EIE             0x00000008  
#define CAN_CTL_SIE             0x00000004  
#define CAN_CTL_IE              0x00000002  
#define CAN_CTL_INIT            0x00000001 

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_STS register.
//
//*****************************************************************************
#define CAN_STS_BOFF            0x00000080  
#define CAN_STS_EWARN           0x00000040  
#define CAN_STS_EPASS           0x00000020  
#define CAN_STS_RXOK            0x00000010  
#define CAN_STS_TXOK            0x00000008  
                                            
#define CAN_STS_LEC_M           0x00000007  
#define CAN_STS_LEC_NONE        0x00000000 
#define CAN_STS_LEC_STUFF       0x00000001 
#define CAN_STS_LEC_FORM        0x00000002 
#define CAN_STS_LEC_ACK         0x00000003  
#define CAN_STS_LEC_BIT1        0x00000004  
#define CAN_STS_LEC_BIT0        0x00000005  
#define CAN_STS_LEC_CRC         0x00000006 
#define CAN_STS_LEC_NOEVENT     0x00000007  

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_ERR register.
//
//*****************************************************************************
#define CAN_ERR_RP              0x00008000 
#define CAN_ERR_REC_M           0x00007F00 
#define CAN_ERR_TEC_M           0x000000FF  
#define CAN_ERR_REC_S           8
#define CAN_ERR_TEC_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_BIT register.
//
//*****************************************************************************
#define CAN_BIT_TSEG2_M         0x00007000  
#define CAN_BIT_TSEG1_M         0x00000F00 
#define CAN_BIT_SJW_M           0x000000C0  
#define CAN_BIT_BRP_M           0x0000003F  
#define CAN_BIT_TSEG2_S         12
#define CAN_BIT_TSEG1_S         8
#define CAN_BIT_SJW_S           6
#define CAN_BIT_BRP_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_INT register.
//
//*****************************************************************************
#define CAN_INT_INTID_M         0x0000FFFF  
#define CAN_INT_INTID_NONE      0x00000000  
#define CAN_INT_INTID_STATUS    0x00008000

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_TST register.
//
//*****************************************************************************
#define CAN_TST_RX              0x00000080  
#define CAN_TST_TX_M            0x00000060  
#define CAN_TST_TX_CANCTL       0x00000000 
#define CAN_TST_TX_SAMPLE       0x00000020  
#define CAN_TST_TX_DOMINANT     0x00000040 
#define CAN_TST_TX_RECESSIVE    0x00000060  
#define CAN_TST_LBACK           0x00000010  
#define CAN_TST_SILENT          0x00000008  
#define CAN_TST_BASIC           0x00000004  

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_BRPE register.
//
//*****************************************************************************
#define CAN_BRPE_BRPE_M         0x0000000F  // Baud Rate Prescaler Extension
#define CAN_BRPE_BRPE_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1CRQ register.
//
//*****************************************************************************
#define CAN_IF1CRQ_BUSY         0x00008000  
#define CAN_IF1CRQ_MNUM_M       0x0000003F
#define CAN_IF1CRQ_MNUM_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1CMSK register.
//
//*****************************************************************************
#define CAN_IF1CMSK_WRNRD       0x00000080  
#define CAN_IF1CMSK_MASK        0x00000040  	
#define CAN_IF1CMSK_ARB         0x00000020  	
#define CAN_IF1CMSK_CONTROL     0x00000010 
#define CAN_IF1CMSK_CLRINTPND   0x00000008 
#define CAN_IF1CMSK_NEWDAT      0x00000004  
#define CAN_IF1CMSK_TXRQST      0x00000004  
#define CAN_IF1CMSK_DATAA       0x00000002  
#define CAN_IF1CMSK_DATAB       0x00000001  

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1MSK1 register.
//
//*****************************************************************************
#define CAN_IF1MSK1_IDMSK_M     0x0000FFFF 
#define CAN_IF1MSK1_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1MSK2 register.
//
//*****************************************************************************
#define CAN_IF1MSK2_MXTD        0x00008000  
#define CAN_IF1MSK2_MDIR        0x00004000  
#define CAN_IF1MSK2_IDMSK_M     0x00001FFF  
#define CAN_IF1MSK2_IDMSK_S     0
#define CAN_IF1MSK2_11BITMSK    0x00001FFC  // 11 Bit Message ID Mask
//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1ARB1 register.
//
//*****************************************************************************
#define CAN_IF1ARB1_ID_M        0x0000FFFF  
#define CAN_IF1ARB1_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1ARB2 register.
//
//*****************************************************************************
#define CAN_IF1ARB2_MSGVAL      0x0000800 0
#define CAN_IF1ARB2_XTD         0x00004000  
#define CAN_IF1ARB2_DIR         0x00002000  
#define CAN_IF1ARB2_ID_M        0x00001FFF  
#define CAN_IF1ARB2_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1MCTL register.
//
//*****************************************************************************
#define CAN_IF1MCTL_NEWDAT      0x00008000  
#define CAN_IF1MCTL_MSGLST      0x00004000  
#define CAN_IF1MCTL_INTPND      0x00002000 
#define CAN_IF1MCTL_UMASK       0x00001000 
#define CAN_IF1MCTL_TXIE        0x00000800  
#define CAN_IF1MCTL_RXIE        0x00000400  
#define CAN_IF1MCTL_RMTEN       0x00000200  
#define CAN_IF1MCTL_TXRQST      0x00000100  
#define CAN_IF1MCTL_EOB         0x00000080  
#define CAN_IF1MCTL_DLC_M       0x0000000F  
#define CAN_IF1MCTL_DLC_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DA1 register.
//
//*****************************************************************************
#define CAN_IF1DA1_DATA_M       0x0000FFFF  
#define CAN_IF1DA1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DA2 register.
//
//*****************************************************************************
#define CAN_IF1DA2_DATA_M       0x0000FFFF  
#define CAN_IF1DA2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DB1 register.
//
//*****************************************************************************
#define CAN_IF1DB1_DATA_M       0x0000FFFF  
#define CAN_IF1DB1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF1DB2 register.
//
//*****************************************************************************
#define CAN_IF1DB2_DATA_M       0x0000FFFF 
#define CAN_IF1DB2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2CRQ register.
//
//*****************************************************************************
#define CAN_IF2CRQ_BUSY         0x00008000  
#define CAN_IF2CRQ_MNUM_M       0x0000003F  
#define CAN_IF2CRQ_MNUM_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2CMSK register.
//
//*****************************************************************************
#define CAN_IF2CMSK_WRNRD       0x00000080  
#define CAN_IF2CMSK_MASK        0x00000040 
#define CAN_IF2CMSK_ARB         0x00000020  
#define CAN_IF2CMSK_CONTROL     0x00000010  
#define CAN_IF2CMSK_CLRINTPND   0x00000008  
#define CAN_IF2CMSK_NEWDAT      0x00000004  
#define CAN_IF2CMSK_TXRQST      0x00000004  
#define CAN_IF2CMSK_DATAA       0x00000002  
#define CAN_IF2CMSK_DATAB       0x00000001  

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2MSK1 register.
//
//*****************************************************************************
#define CAN_IF2MSK1_IDMSK_M     0x0000FFFF  
#define CAN_IF2MSK1_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2MSK2 register.
//
//*****************************************************************************
#define CAN_IF2MSK2_MXTD        0x00008000  
#define CAN_IF2MSK2_MDIR        0x00004000 
#define CAN_IF2MSK2_IDMSK_M     0x00001FFF  
#define CAN_IF2MSK2_IDMSK_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2ARB1 register.
//
//*****************************************************************************
#define CAN_IF2ARB1_ID_M        0x0000FFFF  
#define CAN_IF2ARB1_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2ARB2 register.
//
//*****************************************************************************
#define CAN_IF2ARB2_MSGVAL      0x00008000  
#define CAN_IF2ARB2_XTD         0x00004000  
#define CAN_IF2ARB2_DIR         0x00002000 
#define CAN_IF2ARB2_ID_M        0x00001FFF 
#define CAN_IF2ARB2_ID_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2MCTL register.
//
//*****************************************************************************
#define CAN_IF2MCTL_NEWDAT      0x00008000 
#define CAN_IF2MCTL_MSGLST      0x00004000 
#define CAN_IF2MCTL_INTPND      0x00002000  
#define CAN_IF2MCTL_UMASK       0x00001000  
#define CAN_IF2MCTL_TXIE        0x00000800  
#define CAN_IF2MCTL_RXIE        0x00000400  
#define CAN_IF2MCTL_RMTEN       0x00000200  
#define CAN_IF2MCTL_TXRQST      0x00000100  
#define CAN_IF2MCTL_EOB         0x00000080  
#define CAN_IF2MCTL_DLC_M       0x0000000F  
#define CAN_IF2MCTL_DLC_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DA1 register.
//
//*****************************************************************************
#define CAN_IF2DA1_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DA1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DA2 register.
//
//*****************************************************************************
#define CAN_IF2DA2_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DA2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DB1 register.
//
//*****************************************************************************
#define CAN_IF2DB1_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DB1_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_IF2DB2 register.
//
//*****************************************************************************
#define CAN_IF2DB2_DATA_M       0x0000FFFF  // Data
#define CAN_IF2DB2_DATA_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_TXRQ1 register.
//
//*****************************************************************************
#define CAN_TXRQ1_TXRQST_M      0x0000FFFF  // Transmission Request Bits
#define CAN_TXRQ1_TXRQST_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_TXRQ2 register.
//
//*****************************************************************************
#define CAN_TXRQ2_TXRQST_M      0x0000FFFF  // Transmission Request Bits
#define CAN_TXRQ2_TXRQST_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_NWDA1 register.
//
//*****************************************************************************
#define CAN_NWDA1_NEWDAT_M      0x0000FFFF  // New Data Bits
#define CAN_NWDA1_NEWDAT_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_NWDA2 register.
//
//*****************************************************************************
#define CAN_NWDA2_NEWDAT_M      0x0000FFFF  
#define CAN_NWDA2_NEWDAT_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG1INT register.
//
//*****************************************************************************
#define CAN_MSG1INT_INTPND_M    0x0000FFFF 
#define CAN_MSG1INT_INTPND_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG2INT register.
//
//*****************************************************************************
#define CAN_MSG2INT_INTPND_M    0x0000FFFF  
#define CAN_MSG2INT_INTPND_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG1VAL register.
//
//*****************************************************************************
#define CAN_MSG1VAL_MSGVAL_M    0x0000FFFF  
#define CAN_MSG1VAL_MSGVAL_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_O_MSG2VAL register.
//
//*****************************************************************************
#define CAN_MSG2VAL_MSGVAL_M    0x0000FFFF  
#define CAN_MSG2VAL_MSGVAL_S    0




#endif /* CAN_PRIVATE_H_ */
