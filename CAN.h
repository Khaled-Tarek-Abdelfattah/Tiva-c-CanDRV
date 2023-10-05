 /******************************************************************************
 *
 * Module: CAN
 *
 * File Name: CAN.h
 *
 * Description: Header file for the TM4C123GH6PM Microcontroller - CAN driver
 *
 * Author: Khaled Tarek
 *
 *******************************************************************************/
#ifndef CAN_H_
#define CAN_H_


#include "GPIO_Port.h"
#include "CAN_private.h"
#include "Std_Types.h"
#include "common_macros.h"



/*******************************************************************************
 *                      Configurations                                          *
 *******************************************************************************/

#define ENABLE_CAN0INT FALSE
#define ENABLE_CAN1INT FALSE

#define ENABLE_CAN_TxINT FALSE
#define ENABLE_CAN_RxINT FALSE

#define CAN0_PRI 3
#define CAN1_PRI 3

/* CAN0 PINS */
#define CAN0_PORT 1 // PORTB
#define CAN0Rx_PB4 0x10
#define CAN0Tx_PB5 0x20
#define GPIO_CAN0_PINS (CAN0Rx_PB4 | CAN0Tx_PB5)
#define GPIO_CAN0_PCTL (GPIO_PCTL_PB4_CAN0RX | GPIO_PCTL_PB5_CAN0TX)

/* CAN1 PINS */

#define CAN1_PORT 0
#define CAN1Rx_PA0 0x01
#define CAN1Tx_PA1 0x02
#define GPIO_CAN1_PINS (CAN1Rx_PA0 | CAN1Tx_PA1)
#define GPIO_CAN1_PCTL (GPIO_PCTL_PA0_CAN1RX | GPIO_PCTL_PA1_CAN1TX)



/*******************************************************************************
 *                      MODULE DATA TYPES                                      *
 *******************************************************************************/

typedef enum
{
    TEST,SILENT,LOOPBACK,LOOPBACKSILENT,BASIC
}ModeConfig;


typedef enum
{
    CAN0 = (1<<24), CAN1 = (1<<25)
}CAN_InstanceID;

/* MESSAGE ID FORMAT STD -> 11 BITS OR EXTD-> 29 BITS */
typedef enum
{
    StandardFormat, ExtendedFormat
}MID_Format;


typedef enum {
    MsgObj1 ,
    MsgObj2 ,
    MsgObj3 ,
    MsgObj4 ,
    MsgObj5 ,
    MsgObj6 ,
    MsgObj7 ,
    MsgObj8 ,
    MsgObj9 ,
    MsgObj10, 
    MsgObj11, 
    MsgObj12, 
    MsgObj13, 
    MsgObj14, 
    MsgObj15, 
    MsgObj16, 
    MsgObj17, 
    MsgObj18, 
    MsgObj19, 
    MsgObj20, 
    MsgObj21, 
    MsgObj22, 
    MsgObj23, 
    MsgObj24, 
    MsgObj25, 
    MsgObj26, 
    MsgObj27, 
    MsgObj28, 
    MsgObj29, 
    MsgObj30, 
    MsgObj31, 
    MsgObj32, 
}MessageObjectID;


/* Specify if Message supports remote frame */
typedef enum
{
    RemoteFrame_OFF, RemoteFrame_ON
}RemoteFrame_Config;

typedef enum
{
    UMASK_OFF, UMASK_ON
}UMASK_Config;


typedef struct
{

    /* ACCEPTANCE FILTERING */
    uint32 AcceptID;
    /* MESSAGE IDENTIFIER */
    uint32 MessageID;
    /* LENGTH OF MESSAGE IDENTIFIER */
    MID_Format ID_Bits;
    /* LENGTH OF DATA FRAME */
    uint8 DLC;
    /* ID OF MESSAGE OBJECT */
    MessageObjectID MsgObjID;
    /* Support Remote Frame? */
    RemoteFrame_Config RemoteFrame;
    /* Message object has acceptance filtering? */
    UMASK_Config Umask;

}CAN_MessageConfig;


typedef struct
{
    /* TSEG2 = Phase2 - 1 */
    uint8 TSEG2;
    /* TSEG1 = Prop + Phase1 - 1 */
    uint8 TSEG1;
    /* SJW - 1 */
    uint8 SJW;
    /* BAUD RATE PRESCALER */
    uint8 BRP;

}BitTime_Configuration;


typedef struct
{
    /* CONFIGURE WHICH CAN INSTANCE YOU WANT */
    CAN_InstanceID InstanceID;

    BitTime_Configuration BitTime;

}Can_ConfigType;



/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by CAN and other modules */

extern ChannelConfig GPIO_CAN0;
extern ChannelConfig GPIO_CAN1;
extern BitTime_Configuration BitTime;
extern Can_ConfigType CAN_Configuration;
extern CAN_MessageConfig CAN_MssgConfig;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void CAN_Init(Can_ConfigType *Config);

void CAN_SetBaudRate (CAN_InstanceID InstanceID, BitTime_Configuration *BitTime);

void CAN_Disable(CAN_InstanceID InstanceID);

void CAN_Stop(CAN_InstanceID InstanceID);

void CAN_Resume(CAN_InstanceID InstanceID);

void Can_TxConfig( CAN_InstanceID InstanceId, const CAN_MessageConfig* MessageConfig, const uint8 *DataByte );

void CAN_Transmit(CAN_InstanceID InstanceId, const CAN_MessageConfig* MessageConfig, const uint8 *DataByte);

void Can_RxConfig( CAN_InstanceID InstanceId, const CAN_MessageConfig* MessageConfig, uint8 *DataByte);

void CAN_Receive(CAN_InstanceID InstanceId, const CAN_MessageConfig* MessageConfig, uint8 *DataByte);

void CAN_SetTestMode(CAN_InstanceID InstanceID, ModeConfig Mode);




#endif /* CAN_H_ */
