 /******************************************************************************
 *
 * Module: CAN
 *
 * File Name: CAN_PBCfg.c
 *
 * Description: Post Build Configuration Source file for the TM4C123GH6PM Microcontroller - CAN driver
 *
 * Author: Khaled Tarek
 *
 *******************************************************************************/


#include "CAN.h"


/* STRUCTURE USED TO INITILIAZE CAN1 PINS*/

ChannelConfig GPIO_CAN1 = {CAN1_PORT, GPIO_CAN1_PINS, GPIO_CAN1_PCTL, AFSEL_ON, DEN_ON};

/* STRUCTURE USED TO INITILIAZE CAN0 PINS */

ChannelConfig GPIO_CAN0 = {CAN0_PORT, GPIO_CAN0_PINS, GPIO_CAN0_PCTL, AFSEL_ON, DEN_ON};


/* USED TO SET BAUD RATE END OF FILE */
BitTime_Configuration BitTime = {0,3,0,4};

/* USED FOR CAN_INIT {CAN INSTANCE , BitTime Configuration} */
Can_ConfigType CAN_Configuration = {CAN0,  {0,3,0,4} };


/*
 *  ACCEPT ID =0 ( ACCEPT ANY MESSAGE )
 *  MessageID =8
 *  Message ID is 11 bits (Standard Format)
 *  Data Length is 8 bytes
 *  Message Object Address (Mail) is 1
 */
CAN_MessageConfig CAN_MssgConfig = {0, 0x80, StandardFormat, 0x08, MsgObj24, RemoteFrame_ON, UMASK_ON};















