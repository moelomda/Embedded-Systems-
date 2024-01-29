/*
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |                                                        KPDCfg.h                                                                                              |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |  Brief Description:                                                                                                                   |
 * |  This header file contains configuration settings for the Keypad Driver.															   |
 * |  Adjust the settings based on your hardware connections and requirements.															   |
 * |																																	   |
 * |  Author: Mohamed Ahmed Fouad Youssef																											   |
 * |  Created on: 07/01/2024, 08:25 PM																									   |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 */
#ifndef KPDCFG_H_
#define KPDCFG_H_
/*
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |                           Configure the Keypad Matrix Size and Number of Keypads                                                  |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * |  To tailor the Keypad Driver to your specific hardware, modify the values of the macros below.                                    |
 * |                                                                                                                                   |
 * |  KDP_COLNUMBER: Specify the number of columns in your keypad. Adjust this value based on your actual hardware setup.              |
 * |                                                                                                                                   |
 * |  KDP_ROWNUMBER: Specify the number of rows in your keypad. Adjust this value based on your actual hardware setup.                 |
 * |                                                                                                                                   |
 * |  KDP_NUMBER: Specify the total number of keypads. Adjust this value based on the number of keypads connected to your system.      |
 * |                                                                                                                                   |
 * |  Ensure that the values align with your hardware configuration to enable accurate keypad scanning.                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------
 */

#define KPD_COLNUMBER 4  
#define KPD_ROWNUMBER 4 
#define KPD_NUMBER    1

/* KPD LIST */
#define  KPD_NUM1 0


#endif /* KPDCFG_H_ */