 /******************************************************************************
 *
 * Module: CAN
 *
 * File Name: CAN.c
 *
 * Description: Source file for the TM4C123GH6PM Microcontroller - CAN driver
 *
 * Author: Khaled Tarek
 *
 *******************************************************************************/


#include "CAN.h"


/************************************************************************************
* Service Name: CAN_init
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Return value: None
* Description: Function to Initialize the CAN module.
************************************************************************************/
void CAN_Init(Can_ConfigType *Config)
{
   switch(Config->InstanceID)
   {

   case CAN0:
        /* START CLOCK FOR CAN INSTANCE ID */
        SYSCTL_RCGC2_R |= Config->InstanceID;
        /* PORT initialized for CAN0 */
        GPIO_Channel_Init(&GPIO_CAN0);
        /* SET BITS IN CANCTL (INORDER TO ACCESS SOME CONFIGURATION REGISTERS) */
        CAN0_CTL_R |= (CAN_CTL_INIT | CAN_CTL_CCE);
        #if (ENABLE_CAN0INT == TRUE)
        /* ENABLE INTERRUPTS FOR CAN0 */
        CAN0_CTL_R |= CAN_CTL_IE ;
        #endif
        /* CONFIGURE BIT TIME (BIT RATE) */
        CAN0_BIT_R |= Config->BitTime.BRP | (Config->BitTime.SJW<<6);
        CAN0_BIT_R |= (Config->BitTime.TSEG1<<8) | (Config->BitTime.TSEG2<<12);
        /* CLEAR INIT BIT */
        CAN0_CTL_R &=~ (CAN_CTL_INIT);
        break;

   case CAN1:
        /* START CLOCK FOR CAN INSTANCE ID */
        SYSCTL_RCGC2_R |= Config->InstanceID;
        /* PORT initialized for CAN1 */
        GPIO_Channel_Init(&GPIO_CAN1);
        /* SET BITS IN CANCTL (INORDER TO ACCESS SOME CONFIGURATION REGISTERS)*/
        CAN1_CTL_R |= CAN_CTL_INIT | CAN_CTL_CCE;
        #if (ENABLE_CAN1INT == TRUE)
        /* ENABLE INTERRUPTS FOR CAN1 */
        CAN1_CTL_R |= CAN_CTL_IE ;
        #endif
        /* CONFIGURE BIT TIME (BIT RATE) */
        CAN1_BIT_R |= Config->BitTime.BRP | (Config->BitTime.SJW<<6);
        CAN1_BIT_R |= (Config->BitTime.TSEG1<<8) | (Config->BitTime.TSEG2<<12);
        /* CLEAR INIT BIT */
        CAN1_CTL_R &= ~CAN_CTL_INIT;
        break;

   default:
       /* REPORT ERROR */
       break;
   }
}

/************************************************************************************
* Service Name: CAN_SetBaudRate
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Return value: None
* Description: Function to set the baudrate of a Device instance in the CAN module.
************************************************************************************/
void CAN_SetBaudRate (CAN_InstanceID InstanceID, BitTime_Configuration *BitTime)
{
    switch(InstanceID)
    {
    case CAN0:
         /* SET BITS IN CANCTL (INORDER TO ACCESS SOME CONFIGURATION REGISTERS) */
         CAN0_CTL_R |= (CAN_CTL_INIT | CAN_CTL_CCE);
         /* CONFIGURE BIT TIME (BIT RATE) */
         CAN0_BIT_R |= (BitTime->BRP) | (BitTime->SJW<<6);
         CAN0_BIT_R |= (BitTime->TSEG1<<8) | (BitTime->TSEG2<<12);
         /* CLEAR INIT BIT */
         CAN0_CTL_R &=~ (CAN_CTL_INIT);
         break;

    case CAN1:
         /* SET BITS IN CANCTL (INORDER TO ACCESS SOME CONFIGURATION REGISTERS)*/
         CAN1_CTL_R |= CAN_CTL_INIT | CAN_CTL_CCE;
         /* CONFIGURE BIT TIME (BIT RATE) */
         CAN1_BIT_R |= (BitTime->BRP) | (BitTime->SJW<<6);
         CAN1_BIT_R |= (BitTime->TSEG1<<8) | (BitTime->TSEG2<<12);
         /* CLEAR INIT BIT */
         CAN1_CTL_R &= ~CAN_CTL_INIT;
         break;

    default:
        /* REPORT ERROR */
        break;
    }
}



/************************************************************************************
* Service Name: CAN_Disable
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Return value: None
* Description: Function to Disable a specific CAN instance
************************************************************************************/
void CAN_Disable(CAN_InstanceID InstanceID)
{
    switch(InstanceID)
    {
    case CAN0:
        /* STOP CLOCK FOR CAN INSTANCE ID */
        SYSCTL_RCGC2_R &= ~InstanceID;
        break;

    case CAN1:
        /* STOP CLOCK FOR CAN INSTANCE ID */
        SYSCTL_RCGC2_R &= ~InstanceID;
         break;

    default:
        /* REPORT ERROR */
        break;
    }
}


/************************************************************************************
* Service Name: CAN_Stop
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Return value: None
* Description: Function to stop a specific CAN instance
************************************************************************************/
void CAN_Stop(CAN_InstanceID InstanceID)
{
    switch(InstanceID)
    {
    case CAN0:
         /* SET BITS IN CANCTL */
         CAN0_CTL_R |= (CAN_CTL_INIT);
         break;

    case CAN1:
         /* SET BITS IN CANCTL */
         CAN1_CTL_R |= (CAN_CTL_INIT);
         break;

    default:
        /* REPORT ERROR */
        break;
    }
}

/************************************************************************************
* Service Name: CAN_Resume
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Return value: None
* Description: Function to resume a specific CAN instance
************************************************************************************/
void CAN_Resume(CAN_InstanceID InstanceID)
{
    switch(InstanceID)
    {
    case CAN0:
        /*From Initialization Mode To Start Transmit */
        CAN0_CTL_R &= ~(CAN_CTL_INIT);
        break;

    case CAN1:
        /*From Initialization Mode To Start Transmit */
        CAN0_CTL_R &= ~(CAN_CTL_INIT);
         break;

    default:
        /* REPORT ERROR */
        break;
    }
}



/************************************************************************************
* Service Name: Can_TxConfig
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Return value: Std_ReturnType
* Description: Function to configure a message object.
************************************************************************************/
void Can_TxConfig( CAN_InstanceID InstanceId, const CAN_MessageConfig* MessageConfig, const uint8 *DataByte )
{

    volatile uint32 *CAN_IF1CMSK_R  = NULL_PTR;
    volatile uint32 *CAN_IF1MSK2_R  = NULL_PTR;
    volatile uint32 *CAN_IF1ARB2_R  = NULL_PTR;
    volatile uint32 *CAN_IF1MCTL_R  = NULL_PTR;
    volatile uint32 *CAN_IF1DA1_R   = NULL_PTR;
    volatile uint32 *CAN_IF1DA2_R   = NULL_PTR;
    volatile uint32 *CAN_IF1DB1_R   = NULL_PTR;
    volatile uint32 *CAN_IF1DB2_R   = NULL_PTR;
    volatile uint32 *CAN_IF1CRQ_R   = NULL_PTR;
    volatile uint32 *CAN_IF1MSK1_R  = NULL_PTR;
    volatile uint32 *CAN_IF1ARB1_R  = NULL_PTR;

    switch(InstanceId)
    {

    case CAN0:
        CAN_IF1CMSK_R = &CAN0_IF1CMSK_R;
        CAN_IF1MSK1_R = &CAN0_IF1MSK1_R;
        CAN_IF1MSK2_R = &CAN0_IF1MSK2_R;
        CAN_IF1ARB1_R = &CAN0_IF1ARB1_R;
        CAN_IF1ARB2_R = &CAN0_IF1ARB2_R;
        CAN_IF1MCTL_R = &CAN0_IF1MCTL_R;
        CAN_IF1DA1_R  = &CAN0_IF1DA1_R;
        CAN_IF1DA2_R  = &CAN0_IF1DA2_R;
        CAN_IF1DB1_R  = &CAN0_IF1DB1_R;
        CAN_IF1DB2_R  = &CAN0_IF1DB2_R;
        CAN_IF1CRQ_R  = &CAN0_IF1CRQ_R;
        break;

    case CAN1:
        CAN_IF1CMSK_R = &CAN1_IF1CMSK_R;
        CAN_IF1MSK1_R = &CAN1_IF1MSK1_R;
        CAN_IF1MSK2_R = &CAN1_IF1MSK2_R;
        CAN_IF1ARB1_R = &CAN1_IF1ARB1_R;
        CAN_IF1ARB2_R = &CAN1_IF1ARB2_R;
        CAN_IF1MCTL_R = &CAN1_IF1MCTL_R;
        CAN_IF1DA1_R  = &CAN1_IF1DA1_R;
        CAN_IF1DA2_R  = &CAN1_IF1DA2_R;
        CAN_IF1DB1_R  = &CAN1_IF1DB1_R;
        CAN_IF1DB2_R  = &CAN1_IF1DB2_R;
        CAN_IF1CRQ_R  = &CAN1_IF1CRQ_R;
        break;
    }

    /* WHILE BUSY BIT IS SET CANIF REGISTERS ARE LOCKED*/
    while(CAN1_IF1CRQ_R & CAN_IF2CRQ_BUSY);

    /* RESET REGISTER */
    *CAN_IF1CMSK_R = 0;
    *CAN_IF1MSK1_R = 0x0000FFFF;
    *CAN_IF1MSK2_R = 0x0000FFFF;
    *CAN_IF1ARB1_R = 0;
    *CAN_IF1ARB2_R = 0;
    *CAN_IF1MCTL_R = 0;
    *CAN_IF1DA1_R  = 0;
    *CAN_IF1DA2_R  = 0;
    *CAN_IF1DB1_R  = 0;
    *CAN_IF1DB2_R  = 0;
    *CAN_IF1CRQ_R  = 0;

    /* START CONFIGURING MESSAGE OBJECT */


    /* SET WRNRD BIT TO SIGNAL A WRITE OPERATION */
    *CAN_IF1CMSK_R |= CAN_IF1CMSK_WRNRD;
    /* SET THE CONTROL AND ARB BITS TO SEND CONTROL AND ARB BITS IN THE MESSAGE */
    *CAN_IF1CMSK_R |= CAN_IF1CMSK_MASK | CAN_IF1CMSK_CONTROL | CAN_IF1CMSK_ARB;
    /* CHOOSE DATA BYTES IN MESSAGE OBJECT TO SEND TO REGISTER */
    *CAN_IF1CMSK_R |= CAN_IF1CMSK_DATAB | CAN_IF1CMSK_DATAA;


    if (MessageConfig->ID_Bits == StandardFormat)
    {
        /* MESSAGE FILTERING ID ( 0 -> ALL MESSAGES PASS )*/
        *CAN_IF1MSK2_R |= (0x000007FF & MessageConfig->AcceptID)  <<2 ;
        /* MESSAGE ID IN [12:2] BITS IN REGISTER */
        *CAN_IF1ARB2_R |= (0x000007FF & MessageConfig->MessageID) <<2 ;
        /* CLEAR THE XTD BIT TO INDICATE A STANDARD IDENTIFIER
         * SET MSGVAL -> MESSAGE VALID AND DIR BIT TO INDICATE TRANSMIT*/
        *CAN_IF1ARB2_R &= ~ CAN_IF1ARB2_XTD;
        *CAN_IF1ARB2_R |= CAN_IF1ARB2_DIR | CAN_IF1ARB2_MSGVAL;
    }

    else if (MessageConfig->ID_Bits == ExtendedFormat)
    {
        /* FIRST 16 BITS THEN THE OTHER 13 BITS USED FOR ACCEPTANCE FILTERING (29 BITS) */
        *CAN_IF1MSK1_R |=  (uint16) MessageConfig->AcceptID;
        /* SHIFT THE [28:16] BITS TO THE START AND TAKE THE FIRST 13 BITS -> TOTAL 29 BITS */
        *CAN_IF1MSK2_R |=  ( CAN_IF1MSK2_IDMSK_M & ( (MessageConfig->AcceptID)>>16) );
        /* SET MXTD TO IDENTIFY THAT ACCEPTANCE FILTERING IS DONE ON 29 BITS */
        *CAN_IF1MSK2_R |= CAN_IF1MSK2_MXTD;
        /* FIRST 16 BITS THEN THE OTHER 13 BITS FOR THE 29 BITS MESSAGE ID */
        *CAN_IF1ARB1_R |=  (uint16) MessageConfig->MessageID;
        *CAN_IF1ARB2_R |=  ( CAN_IF2ARB2_ID_M & ( (MessageConfig->MessageID)>>16) );
        /* SET DIR,MSGVAL,XTD BITS */
        *CAN_IF1ARB2_R |= CAN_IF1ARB2_XTD | CAN_IF1ARB2_DIR | CAN_IF1ARB2_MSGVAL;
    }


    if(MessageConfig->Umask == UMASK_ON)
    {
        /* SET UMASK BIT -> ALLOWS USE MASK FOR ACCEPTANCE FILTERING */
        *CAN_IF1MCTL_R |= CAN_IF1MCTL_UMASK;
    }

    else
    {
        /* CLEAR UMASK BIT -> DISALLOW USE MASK FOR ACCEPTANCE FILTERING */
        *CAN_IF1MCTL_R &= ~CAN_IF1MCTL_UMASK;
    }


    /*  SET EOB BIT   -> SINGLE MESSAGE OBJECT  */
    *CAN_IF1MCTL_R |= CAN_IF1MCTL_EOB;


    if (MessageConfig->RemoteFrame == RemoteFrame_ON )
    {
       /* SET RMTEN BIT -> SETS TXRQST ON RECIEVING A MATCHING FRAME*/
        *CAN_IF1MCTL_R |= CAN_IF1MCTL_RMTEN;
    }

    else
    {
        /* CLEAR RMTEN BIT */
         *CAN_IF1MCTL_R &= ~CAN_IF1MCTL_RMTEN;
    }


    /* CONFIGURE DATA FRAME SIZE (NUMBER OF BYTES) */
    *CAN_IF1MCTL_R |= ( CAN_IF1MCTL_DLC_M &  MessageConfig->DLC);

    #if ENABLE_CAN_RxINT == TRUE
        CAN_IF1MCTL_R |= CAN_IF1MCTL_TXIE;
        switch(Config->InstanceID)
          {
          case CAN0:
              /* ENABLE THE CAN0 INTERRUPT -> REG INT BIT OF CAN0 IS (39-32) 7 */
              NVIC_EN1_REG |= 0x0080;
              /* SPECIFY A PRIOIRTY FOR THE INTERRUPT ( OFFSET OF CAN1 IS 29 )  */
              NVIC_PRI9_REG |= CAN0_PRI <<CAN0_PRI9_0FFSET_M;
               break;

          case CAN1:
              /* ENABLE THE CAN1 INTERRUPT -> REG INT BIT OF CAN1 IS (40-32) 8 */
              NVIC_EN1_REG |= 0x0100;
              /* SPECIFY A PRIOIRTY FOR THE INTERRUPT ( OFFSET OF CAN1 IS 5 ) */
              NVIC_PRI10_REG |= CAN1_PRI <<CAN1_PRI10_0FFSET_M;
              break;
          }
    #endif

    /* Selects one of the 32 message objects in the message RAM for the specified configuration */
    *CAN_IF1CRQ_R  |= (MessageConfig->MsgObjID & CAN_IF1CRQ_MNUM_M);
}



/************************************************************************************
* Service Name: CAN_Transmit
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Return value: None
* Description: Function to update a specific message object.
************************************************************************************/
void CAN_Transmit(CAN_InstanceID InstanceId, const CAN_MessageConfig* MessageConfig, const uint8 *DataByte)
{
    volatile uint32 *CAN_IF1MCTL_R  = NULL_PTR;
    volatile uint32 *CAN_IF1DA1_R   = NULL_PTR;
    volatile uint32 *CAN_IF1DA2_R   = NULL_PTR;
    volatile uint32 *CAN_IF1DB1_R   = NULL_PTR;
    volatile uint32 *CAN_IF1DB2_R   = NULL_PTR;
    volatile uint32 *CAN_IF1CRQ_R   = NULL_PTR;
    volatile uint32 *CAN_IF1MSK1_R  = NULL_PTR;

    switch(InstanceId)
    {

    case CAN0:
        CAN_IF1MSK1_R = &CAN0_IF1MSK1_R;
        CAN_IF1MCTL_R = &CAN0_IF1MCTL_R;
        CAN_IF1DA1_R  = &CAN0_IF1DA1_R;
        CAN_IF1DA2_R  = &CAN0_IF1DA2_R;
        CAN_IF1DB1_R  = &CAN0_IF1DB1_R;
        CAN_IF1DB2_R  = &CAN0_IF1DB2_R;
        CAN_IF1CRQ_R  = &CAN0_IF1CRQ_R;
        break;

    case CAN1:
        CAN_IF1MSK1_R = &CAN1_IF1MSK1_R;
        CAN_IF1MCTL_R = &CAN1_IF1MCTL_R;
        CAN_IF1DA1_R  = &CAN1_IF1DA1_R;
        CAN_IF1DA2_R  = &CAN1_IF1DA2_R;
        CAN_IF1DB1_R  = &CAN1_IF1DB1_R;
        CAN_IF1DB2_R  = &CAN1_IF1DB2_R;
        CAN_IF1CRQ_R  = &CAN1_IF1CRQ_R;
        break;
    }

    /* WHILE BUSY BIT IS SET CANIF REGISTERS ARE LOCKED*/
    while(CAN1_IF1CRQ_R & CAN_IF2CRQ_BUSY);

    /* RESET REGISTERS */
    *CAN_IF1MSK1_R = 0x0000FFFF;
    *CAN_IF1MCTL_R = 0;
    *CAN_IF1CRQ_R  = 0;


    /* SET WRITE DATA  AND SET DATAA AND DATAB TO TRANSFER DATA BYTES TO IF REGISTERS */
    *CAN_IF1MSK1_R |= CAN_IF1CMSK_WRNRD | CAN_IF1CMSK_DATAA | CAN_IF1CMSK_DATAB;

    /* TRANSFER OF DATA BYTES */
    *CAN_IF1DA1_R |=  DataByte[0];
    *CAN_IF1DA1_R |=  (0x0000 | DataByte[1])<<8;
    *CAN_IF1DA2_R |=  DataByte[2];
    *CAN_IF1DA2_R |=  (0x0000 | DataByte[3])<<8;
    *CAN_IF1DB1_R |=  DataByte[4];
    *CAN_IF1DB1_R |=  (0x0000 | DataByte[5])<<8;
    *CAN_IF1DB2_R |=  DataByte[6];
    *CAN_IF1DB2_R |=  (0x0000 | DataByte[7])<<8;


    /* Selects one of the 32 message objects in the message RAM to update for data transfer */
    *CAN_IF1CRQ_R |= (MessageConfig->MsgObjID & CAN_IF1CRQ_MNUM_M);
    /* Transmit Request  */
    *CAN_IF1MCTL_R |= CAN_IF1MCTL_TXRQST | CAN_IF1CMSK_NEWDAT;

    /* Set NEWDATA to indicate update
      *CAN_IF1MCTL_R |=  CAN_IF1CMSK_NEWDAT; */

}


/************************************************************************************
* Service Name: CAN_RxConfig
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Return value: None
* Description: Function to configure a receive message object.
************************************************************************************/
void Can_RxConfig( CAN_InstanceID InstanceId, const CAN_MessageConfig* MessageConfig, uint8 *DataByte )
{
    volatile uint32 *CAN_IF1CMSK_R  = NULL_PTR;
    volatile uint32 *CAN_IF1MSK2_R  = NULL_PTR;
    volatile uint32 *CAN_IF1ARB2_R  = NULL_PTR;
    volatile uint32 *CAN_IF1MCTL_R  = NULL_PTR;
    volatile uint32 *CAN_IF1CRQ_R   = NULL_PTR;
    volatile uint32 *CAN_IF1MSK1_R  = NULL_PTR;
    volatile uint32 *CAN_IF1ARB1_R  = NULL_PTR;

    switch(InstanceId)
    {

    case CAN0:
        CAN_IF1CMSK_R = &CAN0_IF1CMSK_R;
        CAN_IF1MSK1_R = &CAN0_IF1MSK1_R;
        CAN_IF1MSK2_R = &CAN0_IF1MSK2_R;
        CAN_IF1ARB1_R = &CAN0_IF1ARB1_R;
        CAN_IF1ARB2_R = &CAN0_IF1ARB2_R;
        CAN_IF1MCTL_R = &CAN0_IF1MCTL_R;
        CAN_IF1CRQ_R  = &CAN0_IF1CRQ_R;;

        break;

    case CAN1:
        CAN_IF1CMSK_R = &CAN1_IF1CMSK_R;
        CAN_IF1MSK1_R = &CAN1_IF1MSK1_R;
        CAN_IF1MSK2_R = &CAN1_IF1MSK2_R;
        CAN_IF1ARB1_R = &CAN1_IF1ARB1_R;
        CAN_IF1ARB2_R = &CAN1_IF1ARB2_R;
        CAN_IF1MCTL_R = &CAN1_IF1MCTL_R;
        CAN_IF1CRQ_R  = &CAN1_IF1CRQ_R;;
        break;
    }

    /* WHILE BUSY BIT IS SET CANIF REGISTERS ARE LOCKED*/
    while(CAN1_IF1CRQ_R & CAN_IF2CRQ_BUSY);

    /* RESET REGISTER */
    *CAN_IF1CMSK_R = 0;
    *CAN_IF1MSK1_R = 0x0000FFFF;
    *CAN_IF1MSK2_R = 0x0000FFFF;
    *CAN_IF1ARB1_R = 0;
    *CAN_IF1ARB2_R = 0;
    *CAN_IF1MCTL_R = 0;
    *CAN_IF1CRQ_R  = 0;

    /* SET WRNRD BIT TO SIGNAL A WRITE OPERATION IN THE CANIFnCMASK REGISTER */
    *CAN_IF1CMSK_R |= CAN_IF1CMSK_WRNRD;
    /* ENABLE MASK FOR THE ACCEPTED MESSAGES (MESSAGE FILTERTING MASKS) */
    /* SET THE CONTROL AND ARB BITS TO SEND CONTROL AND ARB BITS IN THE MESSAGE */
    *CAN_IF1CMSK_R |= CAN_IF1CMSK_MASK | CAN_IF1CMSK_CONTROL | CAN_IF1CMSK_ARB;
    /* CHOOSE DATA BYTES IN MESSAGE OBJECT TO SEND TO REGISTER */
    *CAN_IF1CMSK_R |= CAN_IF1CMSK_DATAB | CAN_IF1CMSK_DATAA;


    if (MessageConfig->ID_Bits == StandardFormat)
    {
    /* MESSAGE FILTERING ID ( 0 -> ALL MESSAGES PASS )*/
    *CAN_IF1MSK2_R |= (0x000007FF & MessageConfig->AcceptID) << 2 ;
    /* MESSAGE ID IN [12:2] BITS IN REGISTER
     CLEAR MXTD TO IDENTIFY THAT ACCEPTANCE FILTERING IS DONE ON 29 BITS */
    *CAN_IF1MSK2_R &= ~CAN_IF1MSK2_MXTD;
    *CAN_IF1ARB2_R |= (0x000007FF & MessageConfig->MessageID) <<2 ;
    /* CLEAR THE XTD BIT TO INDICATE A STANDARD IDENTIFIER
     * AND DIR BIT TO SPECIFY RECIEVE, SET MSGVAL -> MESSAGE VALID */
    *CAN_IF1ARB2_R &= ~ CAN_IF1ARB2_XTD & ~CAN_IF1ARB2_DIR ;
    *CAN_IF1ARB2_R |= CAN_IF1ARB2_MSGVAL;
    }

    else if (MessageConfig->ID_Bits == ExtendedFormat)
    {
        /* FIRST 16 BITS THEN THE OTHER 13 BITS USED FOR ACCEPTANCE FILTERING (29 BITS) */
        *CAN_IF1MSK1_R |=  (uint16) MessageConfig->AcceptID;
        /* SHIFT THE [28:16] BITS TO THE START AND TAKE THE FIRST 13 BITS -> TOTAL 29 BITS */
        *CAN_IF1MSK2_R |=  ( CAN_IF1MSK2_IDMSK_M & ( (MessageConfig->AcceptID)>>16) );
        /* SET MXTD TO IDENTIFY THAT ACCEPTANCE FILTERING IS DONE ON 29 BITS */
        *CAN_IF1MSK2_R |= CAN_IF1MSK2_MXTD;
        /* FIRST 16 BITS THEN THE OTHER 13 BITS FOR THE 29 BITS MESSAGE ID */
        *CAN_IF1ARB1_R |=  (uint16) MessageConfig->MessageID;
        *CAN_IF1ARB2_R |=  ( CAN_IF2ARB2_ID_M & ( (MessageConfig->MessageID)>>16) );
        /* SET MSGVAL,XTD BITS AND CLEAR DIR BIT TO SPECIFY RECIEVE*/
        *CAN_IF1ARB2_R |= CAN_IF1ARB2_XTD | CAN_IF1ARB2_MSGVAL;
        *CAN_IF1ARB2_R &= ~CAN_IF1ARB2_DIR ;
    }


    /* SET UMASK BIT -> ALLOWS USE OF MASK FOR ACCEPTANCE FILTERING
     * SET EOB BIT FOR SINGLE MESSAGE OBJECT
     * CLEAR RMTEN BIT TO LEAVE THE TXRQST BIT UNCHANGED  */
    *CAN_IF1MCTL_R |= CAN_IF1MCTL_UMASK | CAN_IF1MCTL_EOB;
    *CAN_IF1MCTL_R &= ~CAN_IF1MCTL_RMTEN;
    /* CONFIGURE DATA FRAME SIZE (NUMBER OF BYTES) */
    *CAN_IF1MCTL_R |= ( CAN_IF1MCTL_DLC_M &  MessageConfig->DLC);

    #if ENABLE_CAN_RxINT == TRUE
        CAN_IF1MCTL_R |= CAN_IF1MCTL_RXIE;
        switch(Config->InstanceID)
          {
          case CAN0:
              /* ENABLE THE CAN0 INTERRUPT -> REG INT BIT OF CAN0 IS (39-32) 7 */
              NVIC_EN1_REG |= 0x0080;
              /* SPECIFY A PRIOIRTY FOR THE INTERRUPT ( OFFSET OF CAN1 IS 29 )  */
              NVIC_PRI9_REG |= CAN0_PRI <<CAN0_PRI9_0FFSET_M;
               break;

          case CAN1:
              /* ENABLE THE CAN1 INTERRUPT -> REG INT BIT OF CAN1 IS (40-32) 8 */
              NVIC_EN1_REG |= 0x0100;
              /* SPECIFY A PRIOIRTY FOR THE INTERRUPT ( OFFSET OF CAN1 IS 5 ) */
              NVIC_PRI10_REG |= CAN1_PRI <<CAN1_PRI10_0FFSET_M;
              break;
          }
    #endif

    /* Configures one of the 32 message objects in the message RAM to receive  */
    *CAN_IF1CRQ_R |= (MessageConfig->MsgObjID & CAN_IF1CRQ_MNUM_M);

}


/************************************************************************************
* Service Name: CAN_Receive
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Return value: None
* Description: Function to read from a message object.
************************************************************************************/
void CAN_Receive(CAN_InstanceID InstanceId, const CAN_MessageConfig* MessageConfig, uint8 *DataByte)
{
    volatile uint32 *CAN_IF1MCTL_R  = NULL_PTR;
    volatile uint32 *CAN_IF1DA1_R   = NULL_PTR;
    volatile uint32 *CAN_IF1DA2_R   = NULL_PTR;
    volatile uint32 *CAN_IF1DB1_R   = NULL_PTR;
    volatile uint32 *CAN_IF1DB2_R   = NULL_PTR;
    volatile uint32 *CAN_IF1CRQ_R   = NULL_PTR;
    volatile uint32 *CAN_IF1MSK1_R  = NULL_PTR;

    switch(InstanceId)
    {

    case CAN0:
        CAN_IF1MSK1_R = &CAN0_IF1MSK1_R;
        CAN_IF1MCTL_R = &CAN0_IF1MCTL_R;
        CAN_IF1DA1_R  = &CAN0_IF1DA1_R;
        CAN_IF1DA2_R  = &CAN0_IF1DA2_R;
        CAN_IF1DB1_R  = &CAN0_IF1DB1_R;
        CAN_IF1DB2_R  = &CAN0_IF1DB2_R;
        CAN_IF1CRQ_R  = &CAN0_IF1CRQ_R;
        break;

    case CAN1:
        CAN_IF1MSK1_R = &CAN1_IF1MSK1_R;
        CAN_IF1MCTL_R = &CAN1_IF1MCTL_R;
        CAN_IF1DA1_R  = &CAN1_IF1DA1_R;
        CAN_IF1DA2_R  = &CAN1_IF1DA2_R;
        CAN_IF1DB1_R  = &CAN1_IF1DB1_R;
        CAN_IF1DB2_R  = &CAN1_IF1DB2_R;
        CAN_IF1CRQ_R  = &CAN1_IF1CRQ_R;
        break;
    }

    /* WHILE BUSY BIT IS SET CANIF REGISTERS ARE LOCKED*/
    while(CAN1_IF1CRQ_R & CAN_IF2CRQ_BUSY);

    /* RESET REGISTERS */
    *CAN_IF1MSK1_R = 0x0000FFFF;
    *CAN_IF1MCTL_R = 0;
    *CAN_IF1CRQ_R  = 0;


    /* SET DATAA AND DATAB TO TRANSFER DATA BYTES TO IF REGISTERS */
    *CAN_IF1MSK1_R |=   CAN_IF1CMSK_DATAA | CAN_IF1CMSK_DATAB ;


    /* Selects one of the 32 message objects in the message RAM to read from */
    *CAN_IF1CRQ_R |= (MessageConfig->MsgObjID & CAN_IF1CRQ_MNUM_M);

    switch( MessageConfig->DLC)
    {

    case 0x0:
        /* EMPTY DATA FRAME */
        break;
    case 0x1:
        DataByte[0] = (*CAN_IF1DA1_R);
        break;
    case 0x2:
        DataByte[0] = (*CAN_IF1DA1_R);
        DataByte[1] = (*CAN_IF1DA1_R >>8);
        break;
    case 0x3:
        DataByte[0] = (*CAN_IF1DA1_R);
        DataByte[1] = (*CAN_IF1DA1_R >>8);
        DataByte[2] = (*CAN_IF1DA2_R);
        break;
    case 0x4:
        DataByte[0] = (*CAN_IF1DA1_R);
        DataByte[1] = (*CAN_IF1DA1_R >>8);
        DataByte[2] = (*CAN_IF1DA2_R);
        DataByte[3] = (*CAN_IF1DA2_R >>8);
        break;
    case 0x5:
        DataByte[0] = (*CAN_IF1DA1_R);
        DataByte[1] = (*CAN_IF1DA1_R >>8);
        DataByte[2] = (*CAN_IF1DA2_R);
        DataByte[3] = (*CAN_IF1DA2_R >>8);
        DataByte[4] = (*CAN_IF1DB1_R);
        break;
    case 0x6:
        DataByte[0] = (*CAN_IF1DA1_R);
        DataByte[1] = (*CAN_IF1DA1_R >>8);
        DataByte[2] = (*CAN_IF1DA2_R);
        DataByte[3] = (*CAN_IF1DA2_R >>8);
        DataByte[4] = (*CAN_IF1DB1_R);
        DataByte[5] = (*CAN_IF1DB1_R >>8);
        break;
    case 0x7:
        DataByte[0] = (*CAN_IF1DA1_R);
        DataByte[1] = (*CAN_IF1DA1_R >>8);
        DataByte[2] = (*CAN_IF1DA2_R);
        DataByte[3] = (*CAN_IF1DA2_R >>8);
        DataByte[4] = (*CAN_IF1DB1_R);
        DataByte[5] = (*CAN_IF1DB1_R >>8);
        DataByte[6] = (*CAN_IF1DB2_R);
        break;
    case 0x8:
    default:
        DataByte[0] = (*CAN_IF1DA1_R);
        DataByte[1] = (*CAN_IF1DA1_R >>8);
        DataByte[2] = (*CAN_IF1DA2_R);
        DataByte[3] = (*CAN_IF1DA2_R >>8);
        DataByte[4] = (*CAN_IF1DB1_R);
        DataByte[5] = (*CAN_IF1DB1_R >>8);
        DataByte[6] = (*CAN_IF1DB2_R);
        DataByte[7] = (*CAN_IF1DB2_R >>8);
      break;
    }
    /* CLEAR NEWDAT AS DATA HAS BEEN READ */
    *CAN_IF1MCTL_R &= ~ CAN_IF1CMSK_NEWDAT;
}



/************************************************************************************
* Service Name: CAN_SetTestMode
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Return value: None
* Description: Function to configure mode of the CAN.
************************************************************************************/
void CAN_SetTestMode(CAN_InstanceID InstanceID, ModeConfig Mode)
{
    volatile uint32 *CAN_CTL_R = NULL_PTR;
    volatile uint32 *CAN_TST_R = NULL_PTR;

    switch(InstanceID)
    {
    case CAN0:
        CAN_CTL_R = &CAN0_CTL_R;
        CAN_TST_R = &CAN0_TST_R;
        break;

    case CAN1:
        CAN_CTL_R = &CAN1_CTL_R;
        CAN_TST_R = &CAN1_TST_R;
        break;
    }

    if(Mode == TEST)
    {
        /* ENABLE TEST MODE */
        *CAN_CTL_R |= CAN_CTL_TEST;
    }
    else
    {
        *CAN_CTL_R &= ~CAN_CTL_TEST;
    }

    if(Mode == SILENT)
    {
        /* SILENT MODE */
        *CAN_TST_R  |= CAN_TST_SILENT;
    }
    else
    {
        *CAN_TST_R  &= ~CAN_TST_SILENT;
    }

    if( Mode == LOOPBACK)
    {
        /* LOOPBACK MODE */
        *CAN_TST_R |= CAN_TST_LBACK;
    }
    else
    {
        *CAN_TST_R &= ~CAN_TST_LBACK;
    }


    if (Mode == BASIC)
    {
        /*ENABLE BASIC MODE */
        *CAN_TST_R |= CAN_TST_BASIC;
    }
    else
    {
        *CAN_TST_R &= ~CAN_TST_BASIC;
    }

    if( Mode == LOOPBACKSILENT)
    {
    /* SILENT MODE */
    *CAN_TST_R  |= CAN_TST_SILENT;
    /* LOOPBACK MODE */
    *CAN_TST_R |= CAN_TST_LBACK;
    }

}



