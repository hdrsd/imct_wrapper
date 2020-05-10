#pragma once
/**
@file    IMC_TCP.h
@date    2019/07/03
@author  IMC EHTERNET
@brief
*/
#ifndef __IMC_TCP_H__
#define __IMC_TCP_H__

#ifdef IMC_TCP_EXPORTS
#define DLLFunction __declspec(dllexport)
#else
#define DLLFunction __declspec(dllimport)
#endif

#include "IMCT_Define.h"

#ifdef __cplusplus
extern "C" {
#endif		
		/** @brief  Parameter ���� ����
		�� ��ȣ ��     : X_AXIS = 1,	Y_AXIS = 2,	Z_AXIS = 3, U_AXIS = 4,	A_AXIS = 5, B_AXIS = 6, C_AXIS = 7, D_AXIS = 8
		int nIndex     : �ø��� ��� ��ü ��ȣ(0~128), ��ǰ�� 1�� ���� �� ���, nIndex ���� '0'�� �˴ϴ�.
		int nAxis      : ������ �� ��ȣ(1: X�� , 2: Y�� , 3: Z�� , 4: U��, 5: A�� , 6: B�� , 7: C��, 8: D��)
		int nAxis[8]   : ������ �� ��ȣ �迭
		int nValue     : �� �Լ� �� ���� ���� ����
		int nValue[8]  : �� �Լ� �� ���� ���� ���� �迭
		int &nValue    : �� �Լ� �� ���� ���� ����
		int &nValue[8] : �� �Լ� �� ���� ���� ���� �迭
		char pName[18] : ���� �̸� ���� ���� �迭(�ִ� 18�� ���� �Է� ����)
		*/

		/** @brief  COMMUNICATION ����*/
		DLLFunction int	 IMCT_ETH_INITIALIZE(int &nIndex, char* address, int port);
		DLLFunction int	 IMCT_ETH_UNINITIALIZE(int nIndex);

		//<<< MOTION SCALE ����[�޸� ���� ��]
		DLLFunction	int	IMCT_ETH_SET_CONFIG_PPR(int nIndex, int nAxis, int nValue);	///< SCALE - PPR ���� �Լ�															
		DLLFunction	int	IMCT_ETH_GET_CONFIG_PPR(int nIndex, int nAxis, int &nValue); ///< SCALE - PPR ��� �Լ�						
		DLLFunction	int	IMCT_ETH_SET_CONFIG_UPR(int nIndex, int nAxis, int nValue); ///< SCALE - UPR ���� �Լ�												
		DLLFunction	int	IMCT_ETH_GET_CONFIG_UPR(int nIndex, int nAxis, int &nValue); ///< SCALE - UPR ��� �Լ�											

		//<<< MOTION ��ġ ����
		DLLFunction int	IMCT_ETH_SET_COORDINATE(int nIndex, int nValue);						// ��ǥ�� ���� �Լ�(��� ��ǥ��:0, ���� ��ǥ��:1) [�޸� ���� ��]							
		DLLFunction int	IMCT_ETH_SET_CONTROL_VELOCITY(int nIndex, int nAxis[8], int nValue[8]);	// ���� �ӵ� ���� �Լ� [�޸� ���� �ȵ�]
		DLLFunction int	IMCT_ETH_SET_CONTROL_POSITION(int nIndex, int nAxis[8], int nValue[8]);	// ��ġ END CHECK ���� �Լ�[�޸� ���� �ȵ�]	

		//<<< MOTION ���� ����(2�࿡�� ��� �Ұ�) [�޸� ���� �ȵ�]
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_VELOCITY(int nIndex, int nValue);				// ���� �ӵ� ���� �Լ�	
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_BOARD_SELECT(int nIndex, int nValue);			// ���� ����� Board ����(A Board : 0, B Board : 1), 8�� �ÿ��� ����
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_LINEAR(int nIndex, int nAxis[4], int nValue[4]); // ���� ���� ����  �Լ�				
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_CIRCULAR_CW(int nIndex, int nValue[4]);			// ��ȣ ���� CW���� ���� �Լ�				
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_CIRCULAR_CCW(int nIndex, int nValue[4]);			// ��ȣ ���� CCW���� ���� �Լ�				
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_HELICALL_CW(int nIndex, int nValue[5]);			// Helical ���� CW���� ���� �Լ�					
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_HELICALL_CCW(int nIndex, int nValue[5]);			// Helical ���� CCW���� ���� �Լ�							

		//<<< MOTION �ӵ� ����(��������) [�޸� ���� �ȵ�]
		DLLFunction int	IMCT_ETH_SET_CONTINUE_POSITIVE_VELOCITY(int nIndex, int nAxis[8], int nValue[8]); // ������ ���� ���� �Լ�			
		DLLFunction int	IMCT_ETH_SET_CONTINUE_NEGATIVE_VELOCITY(int nIndex, int nAxis[8], int nValue[8]); // ������ ���� ���� �Լ�			

		//<<< MOTION ���� �Լ�[�޸� ���� �ȵ�]
		DLLFunction	int	IMCT_ETH_SET_COMMON_HOME(int nIndex, int nValue[8]); // (0:Disble, 1:Enable)
		DLLFunction	int	IMCT_ETH_SET_COMMON_STOP(int nIndex, int nValue[8]); // (0:Disble, 1:Enable)	
		DLLFunction int	IMCT_ETH_SET_COMMON_ALARM_CLEAR(int nIndex, int nValue[8]);    // (0:Disble, 1:Enable)				
		DLLFunction int	IMCT_ETH_SET_COMMON_ENCORDER_CLEAR(int nIndex, int nValue[8]); // (0:Disble, 1:Enable)
		DLLFunction int	IMCT_ETH_SET_COMMON_MOTOR_ON(int nIndex, int nValue[8]);  // (1: ON)
		DLLFunction int	IMCT_ETH_SET_COMMON_MOTOR_OFF(int nIndex, int nValue[8]);  // (1: ON)

		DLLFunction int	IMCT_ETH_SET_COMMON_ENCODER_SYNC(int nIndex); ///< Encoder Sync �Լ�(AZ ���)

		//<<< MOTION JOG ���� [�޸� ���� �ȵ�]
		DLLFunction int	IMCT_ETH_SET_COMMON_JOG_CW(int nIndex, int nAxis);  ///< JOG CW ���� ���� �Լ�									 
		DLLFunction int	IMCT_ETH_SET_COMMON_JOG_CCW(int nIndex, int nAxis);	///< JOG CCW ���� ���� �Լ�		
		DLLFunction int	IMCT_ETH_SET_COMMON_JOG_STOP(int nIndex, int nAxis); ///< JOG ����	

		//<<< MOTION ���� �Լ�(ALARM, BUSY ,HOME �Ϸ� ,ENCODER) 
		///< 2�� ���� ��� �Լ�
		DLLFunction int	IMCT_ETH_GET_COMMON_2X_STATUS(int nIndex
			, int nType			 /* nType = 0 (Position) , nType = 1 (Velocity) */
			, int &nInfo		 /* ���� ����: 0: ����, 1: I-Code ������, 2: Emergency ���� */
			, int nBusy[2]		 /* �迭 ���� 0: OFF 1: ON */
			, int nAlarm[2]		 /* �迭 ���� 0: OFF 1: ON */
			, int nLimit_P[2]	 /* �迭 ���� 0: OFF 1: ON */
			, int nLimit_N[2]	 /* �迭 ���� 0: OFF 1: ON */
			, int nHome[2]		 /* �迭 ���� 0: OFF 1: ON */
			, int nSD[2]		 /* �迭 ���� 0: OFF 1: ON */
			, int nInP[2]		 /* �迭 ���� 0: OFF 1: ON */
			, int nTypeValue[2]  /* nType ���ǿ� ���� Position �Ǵ� Velocity �� ���� */
		);

		DLLFunction int	IMCT_ETH_GET_COMMON_4X_STATUS(int nIndex
			, int nType			 /* nType = 0 (Position) , nType = 1 (Velocity) */
			, int &nInfo		 /* ���� ����: 0: ����, 1: I-Code ������, 2: Emergency ���� */
			, int nBusy[4]		 /* �迭 ���� 0: OFF 1: ON */
			, int nAlarm[4]		 /* �迭 ���� 0: OFF 1: ON */
			, int nLimit_P[4]	 /* �迭 ���� 0: OFF 1: ON */
			, int nLimit_N[4]	 /* �迭 ���� 0: OFF 1: ON */
			, int nHome[4]		 /* �迭 ���� 0: OFF 1: ON */
			, int nSD[4]		 /* �迭 ���� 0: OFF 1: ON */
			, int nInP[4]		 /* �迭 ���� 0: OFF 1: ON */
			, int nTypeValue[4]  /* nType ���ǿ� ���� Position �Ǵ� Velocity �� ���� */
		);

		DLLFunction int	IMCT_ETH_GET_COMMON_8X_STATUS(int nIndex
			, int nType			 /* nType = 0 (Position) , nType = 1 (Velocity) */
			, int &nInfo		 /* ���� ����: 0: ����, 1: I-Code ������, 2: Emergency ���� */
			, int nBusy[8]		 /* �迭 ���� 0: OFF 1: ON */
			, int nAlarm[8]		 /* �迭 ���� 0: OFF 1: ON */
			, int nLimit_P[8]	 /* �迭 ���� 0: OFF 1: ON */
			, int nLimit_N[8]	 /* �迭 ���� 0: OFF 1: ON */
			, int nHome[8]		 /* �迭 ���� 0: OFF 1: ON */
			, int nSD[8]		 /* �迭 ���� 0: OFF 1: ON */
			, int nInP[8]		 /* �迭 ���� 0: OFF 1: ON */
			, int nTypeValue[8]  /* nType ���ǿ� ���� Position �Ǵ� Velocity �� ���� */
		);

		//<<< MOTION I/O ����� �Լ� [�޸� ���� ��]
		DLLFunction int	IMCT_ETH_GET_COMMON_INPUT_PORT(int nIndex, int nVaule[8]);	///< INPUT PORT ���� ��� �Լ�	
		DLLFunction int	IMCT_ETH_SET_COMMON_OUTPUT_PORT(int nIndex, int nPort, int nValue[8]);
		DLLFunction int	IMCT_ETH_GET_COMMON_OUTPUT_PORT(int nIndex, int nVaule[8]); ///< OUTPUT PORT ���� ��� �Լ�		

		//<<< MOTION �޸� ���� [�޸� ���� ��]
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_WORKING_MODE(int nIndex, int nAxis, int nAddress, int nValue);  ///< ���� MODE ���� �Լ�								
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_WORKING_MODE(int nIndex, int nAxis, int nAddress, int &nValue);	///< ���� MODE ��� �Լ�										
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_ACC(int nIndex, int nAxis, int nAddress, int nValue);  ///< ���� �ð� ���� �Լ�(ms)									
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_ACC(int nIndex, int nAxis, int nAddress, int &nValue); ///< ���� �ð� ��� �Լ�(ms)														
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_DEC(int nIndex, int nAxis, int nAddress, int nValue); ///< ���� �ð� ���� �Լ�(ms)											
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_DEC(int nIndex, int nAxis, int nAddress, int &nValue);	///< ���� �ð� ��� �Լ�(ms)													
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_START_SPD(int nIndex, int nAxis, int nAddress, int nValue);	///< ���� �ӵ� ���� �Լ�(mm/Sec,��/Sec)									
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_START_SPD(int nIndex, int nAxis, int nAddress, int &nValue); ///< ���� �ӵ� ��� �Լ�(mm/Sec,��/Sec)												
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_RUN_SPD(int nIndex, int nAxis, int nAddress, int nValue); ///< ���� �ӵ� ���� �Լ�(mm/Sec,��/Sec)										
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_RUN_SPD(int nIndex, int nAxis, int nAddress, int &nValue);	///< ���� �ӵ� ��� �Լ�(mm/Sec,��/Sec)												
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_MAG(int nIndex, int nAxis, int nAddress, double dValue); ///< �ӵ� ���� ���� �Լ�(��)											
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_MAG(int nIndex, int nAxis, int nAddress, double &dValue); ///< �ӵ� ���� ��� �Լ�(��)														
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_POSITION(int nIndex, int nAxis, int nAddress, int nValue); ///< �̼۷� ���� �Լ�(Unit,��)										
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_POSITION(int nIndex, int nAxis, int nAddress, int &nValue);	///< �̼۷� ��� �Լ�(Unit,��)			
																													//<<< MOTION �޸� ������ ����		
		DLLFunction	int	IMCT_ETH_SET_MOTION_DATA_START(int nIndex, int nAddress[8]); ///< ��� ���� �Լ�

		//-- INTERLOCK(2���)
		DLLFunction int IMCT_2X_ETH_GET_INTERLOCK_ACC_DEC_TIME(int nAccDecTime, int nStartSpeed, int nRunSpeed, int nManification, double dScale);
		DLLFunction int IMCT_2X_ETH_GET_INTERLOCK_SPEED(int nSpeed, double dScale);
		DLLFunction int IMCT_2X_ETH_GET_INTERLOCK_POSITION(double dPosition, double dScale);

		//-- INTERLOCK(4��, 8���)
		DLLFunction int IMCT_ETH_GET_INTERLOCK_ACC_TIME(int nAccTime, int nStartSpeed, int nRunSpeed, double dScale);
		DLLFunction int IMCT_ETH_GET_INTERLOCK_DEC_TIME(int nDecTime, int nStartSpeed, int nRunSpeed, double dScale);
		DLLFunction int IMCT_ETH_GET_INTERLOCK_SPEED(int nSpeed, double dScale);
		DLLFunction int IMCT_ETH_GET_INTERLOCK_POSITION(double dPosition, double dScale);

		//-- INTERLOCK(����)
		DLLFunction int IMCT_ETH_GET_INTERLOCK_MAGNIFICATION(int nMagnification);

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//<<< ���� �Լ����� ��� ��� ���� �Դϴ�.
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//<<< ȯ�� Parameter
		/** @brief  CONFIG - �ӵ�/��ġ ����� �ӵ� ���� [�޸� ���� ��] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_LINE_S_CUVE_SEL(int nIndex, int nAxis, int nValue); ///< LINE , S-CURVE ���� ���� �Լ�(LINE: 0 , S-CURVE: 4)  
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_LINE_S_CUVE_SEL(int nIndex, int nAxis, int &nValue); ///< LINE , S-CURVE ���� ��� �Լ�(LINE: 0 , S-CURVE: 4)  
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_S_CUV_ACC(int nIndex, int nAxis, int nValue); ///< S-CURVE ���� ���� ���� �Լ�(1~100%)	
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_S_CUV_ACC(int nIndex, int nAxis, int &nValue); ///< S-CURVE ���� ���� ��� �Լ�(1~100%)	 		
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_S_CUV_DEC(int nIndex, int nAxis, int nValue); ///< S-CURVE ���� ���� ���� �Լ�(1~100%)		
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_S_CUV_DEC(int nIndex, int nAxis, int &nValue); ///< S-CURVE ���� ���� ��� �Լ�(1~100%)			
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_ACC(int nIndex, int nAxis, int nValue); ///< ���� �ð� ���� �Լ�(ms)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_ACC(int nIndex, int nAxis, int &nValue); ///< ���� �ð� ��� �Լ�(ms)				
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_DEC(int nIndex, int nAxis, int nValue); ///< ���� �ð� ���� �Լ�(ms)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_DEC(int nIndex, int nAxis, int &nValue); ///< ���� �ð� ��� �Լ�(ms)				
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_START_SPD(int nIndex, int nAxis, int nValue); ///< ���� �ӵ� ���� �Լ�(mm/Sec,��/Sec)		
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_START_SPD(int nIndex, int nAxis, int &nValue); ///< ���� �ӵ� ��� �Լ�(mm/Sec,��/Sec)	
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_RUN_SPD(int nIndex, int nAxis, int nValue); ///< ���� �ӵ� ���� �Լ�(mm/Sec,��/Sec)			
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_RUN_SPD(int nIndex, int nAxis, int &nValue); ///< ���� �ӵ� ��� �Լ�(mm/Sec,��/Sec)
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_MAG(int nIndex, int nAxis, double dValue);	///< �ӵ� ���� ���� �Լ�(��)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_MAG(int nIndex, int nAxis, double &dValue); ///< �ӵ� ���� ��� �Լ�(��)			

		 /** @brief  COMMON CONFIG - ���� ���� �ӵ� ���� [�޸� ���� ��] */
		DLLFunction int	IMCT_ETH_SET_COMMON_CONFIG_INTERPOLL_VELOCITY_ACC(int nIndex, int nValue);	///< ���� �ð� ���� �Լ�(ms)							
		DLLFunction int	IMCT_ETH_GET_COMMON_CONFIG_INTERPOLL_VELOCITY_ACC(int nIndex, int &nValue);	///< ���� �ð� ��� �Լ�(ms)								
		DLLFunction int	IMCT_ETH_SET_COMMON_CONFIG_INTERPOLL_VELOCITY_DEC(int nIndex, int nValue);	///< ���� �ð� ���� �Լ�(ms)							
		DLLFunction int	IMCT_ETH_GET_COMMON_CONFIG_INTERPOLL_VELOCITY_DEC(int nIndex, int &nValue);	///< ���� �ð� ��� �Լ�(ms)								
		DLLFunction int	IMCT_ETH_SET_COMMON_CONFIG_INTERPOLL_VELOCITY_START_SPD(int nIndex, int nValue);  ///< ���� �ӵ� ���� �Լ�(mm/Sec,��/Sec)					
		DLLFunction int	IMCT_ETH_GET_COMMON_CONFIG_INTERPOLL_VELOCITY_START_SPD(int nIndex, int &nValue); ///< ���� �ӵ� ��� �Լ�(mm/Sec,��/Sec)								
		DLLFunction int	IMCT_ETH_SET_COMMON_CONFIG_INTERPOLL_VELOCITY_RUN_SPD(int nIndex, int nValue);  ///< ���� �ӵ� ���� �Լ�(mm/Sec,��/Sec)					
		DLLFunction int	IMCT_ETH_GET_COMMON_CONFIG_INTERPOLL_VELOCITY_RUN_SPD(int nIndex, int &nValue); ///< ���� �ӵ� ��� �Լ�(mm/Sec,��/Sec)	

		/** @brief  CONFIG - HOME �ӵ� ���� [�޸� ���� ��] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_ACC(int nIndex, int nAxis, int nValue); ///< ���� �ð� ���� �Լ�(ms)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_ACC(int nIndex, int nAxis, int &nValue); ///< ���� �ð� ��� �Լ�(ms)				
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_DEC(int nIndex, int nAxis, int nValue); ///< ���� �ð� ���� �Լ�(ms)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_DEC(int nIndex, int nAxis, int &nValue);	///< ���� �ð� ��� �Լ�(ms)				
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_START_SPD(int nIndex, int nAxis, int nValue);	///< ���� �ӵ� ���� �Լ�(mm/Sec,��/Sec)		
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_START_SPD(int nIndex, int nAxis, int &nValue);///< ���� �ӵ� ��� �Լ�(mm/Sec,��/Sec)	
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_RUN_SPD(int nIndex, int nAxis, int nValue); ///< ���� �ӵ� ���� �Լ�(mm/Sec,��/Sec)			
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_RUN_SPD(int nIndex, int nAxis, int &nValue);	///< ���� �ӵ� ��� �Լ�(mm/Sec,��/Sec)
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_MAG(int nIndex, int nAxis, double dValue); ///< �ӵ� ���� ���� �Լ�(��)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_MAG(int nIndex, int nAxis, double &dValue); ///< �ӵ� ���� ��� �Լ�(��)				

		/** @brief  CONFIG - JOG �ӵ� ���� [�޸� ���� ��] */
		DLLFunction int	IMCT_ETH_SET_CONFIG_JOG_ACC(int nIndex, int nAxis, int nValue);	///< ���� �ð� ���� �Լ�(ms)				
		DLLFunction int	IMCT_ETH_GET_CONFIG_JOG_ACC(int nIndex, int nAxis, int &nValue); ///< ���� �ð� ��� �Լ�(ms)				
		DLLFunction int	IMCT_ETH_SET_CONFIG_JOG_DEC(int nIndex, int nAxis, int nValue);	///< ���� �ð� ���� �Լ�(ms)				
		DLLFunction int	IMCT_ETH_GET_CONFIG_JOG_DEC(int nIndex, int nAxis, int &nValue); ///< ���� �ð� ��� �Լ�(ms)				
		DLLFunction int	IMCT_ETH_SET_CONFIG_JOG_START_SPD(int nIndex, int nAxis, int nValue); ///< ���� �ӵ� ���� �Լ�(mm/Sec,��/Sec)		
		DLLFunction int	IMCT_ETH_GET_CONFIG_JOG_START_SPD(int nIndex, int nAxis, int &nValue); ///< ���� �ӵ� ��� �Լ�(mm/Sec,��/Sec)	
		DLLFunction int	IMCT_ETH_SET_CONFIG_JOG_RUN_SPD(int nIndex, int nAxis, int nValue);	///< ���� �ӵ� ���� �Լ�(mm/Sec,��/Sec)			
		DLLFunction int	IMCT_ETH_GET_CONFIG_JOG_RUN_SPD(int nIndex, int nAxis, int &nValue); ///< ���� �ӵ� ��� �Լ�(mm/Sec,��/Sec)
		DLLFunction int	IMCT_ETH_SET_CONFIG_JOG_MAG(int nIndex, int nAxis, double dValue); ///< �ӵ� ���� ���� �Լ�(��)				
		DLLFunction int	IMCT_ETH_GET_CONFIG_JOG_MAG(int nIndex, int nAxis, double &dValue); ///< �ӵ� ���� ��� �Լ�(��)				

		/** @brief  CONFIG - HOME �ɼ� ���� [�޸� ���� ��] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_DIRECTION(int nIndex, int nAxis, int nValue); ///< Home ���� ���� �Լ�						
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_DIRECTION(int nIndex, int nAxis, int &nValue); ///< Home ���� ��� �Լ�	
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_MODE(int nIndex, int nAxis, int nValue); ///< Home ��� ���� �Լ�										
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_MODE(int nIndex, int nAxis, int &nValue); ///< Home ��� ��� �Լ�					
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_OFFSET(int nIndex, int nAxis, int nValue);	///< Home OFFSET ���� �Լ�								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_OFFSET(int nIndex, int nAxis, int &nValue);	///< Home OFFSET ��� �Լ�						
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_SENSOR_LEVEL(int nIndex, int nAxis, int nValue);	///< Home SENSOR LEVEL ���� �Լ�								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_SENSOR_LEVEL(int nIndex, int nAxis, int &nValue);	///< Home SENSOR LEVEL ��� �Լ�				
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_SPEED_PATTERN(int nIndex, int nAxis, int nValue);	///< Home SPEED PATTERN ���� �Լ�								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_SPEED_PATTERN(int nIndex, int nAxis, int &nValue);	///< Home SPEED PATTERN ��� �Լ�				

		/** @brief  CONFIG - ENCORDER ���� [�޸� ���� ��] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_ENCORDER_IN_EXT_SEL(int nIndex, int nAxis, int nValue);	///< ENCODER ����,�ܺ� ���� �Լ�									
		DLLFunction	int	IMCT_ETH_GET_CONFIG_ENCORDER_IN_EXT_SEL(int nIndex, int nAxis, int &nValue); ///< ENCODER ����,�ܺ� ��� �Լ�								
		DLLFunction	int	IMCT_ETH_SET_CONFIG_ENCORDER_MULTIPLYING(int nIndex, int nAxis, int nValue); ///< ENCODER ü���� ���� �Լ�								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_ENCORDER_MULTIPLYING(int nIndex, int nAxis, int &nValue); ///< ENCODER ü���� ��� �Լ�						
		DLLFunction	int	IMCT_ETH_SET_CONFIG_ENCORDER_PPR(int nIndex, int nAxis, int nValue); ///< ENCODER PPR ���� �Լ�														
		DLLFunction	int	IMCT_ETH_GET_CONFIG_ENCORDER_PPR(int nIndex, int nAxis, int &nValue); ///< ENCODER PPR ��� �Լ�					
		DLLFunction	int	IMCT_ETH_SET_CONFIG_ENCORDER_UPR(int nIndex, int nAxis, int nValue); ///< ENCODER UPR ���� �Լ�													
		DLLFunction	int	IMCT_ETH_GET_CONFIG_ENCORDER_UPR(int nIndex, int nAxis, int &nValue); ///< ENCODER UPR ��� �Լ�											

		/** @brief  CONFIG - �޽� ��� ���� ���� [�޸� ���� ��] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_PULSE_OUTPUT_SETTING(int nIndex, int nAxis, int nValue); ///< �޽� ��� ���� ���� �Լ�									
		DLLFunction	int	IMCT_ETH_GET_CONFIG_PULSE_OUTPUT_SETTING(int nIndex, int nAxis, int &nValue); ///< �޽� ��� ���� ��� �Լ�							

		/** @brief  CONFIG - EMRGENCY STOP ���� [�޸� ���� ��] */
		DLLFunction int	IMCT_ETH_SET_CONFIG_EMRGENCY_STOP(int nIndex, int nAxis, int nValue); ///< ��� ���� ���� ���� �Լ�											
		DLLFunction int	IMCT_ETH_GET_CONFIG_EMRGENCY_STOP(int nIndex, int nAxis, int &nValue); ///< ��� ���� ���� ��� �Լ�				

		/** @brief  CONFIG - SOFTWARE LIMIT ���� [�޸� ���� ��] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_SOFTWARE_LIMIT_USE_SEL(int nIndex, int nAxis, int nValue); ///< SOFTWARE LIMIT ��� ���� ���� �Լ�								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_SOFTWARE_LIMIT_USE_SEL(int nIndex, int nAxis, int &nValue);	///< SOFTWARE LIMIT ��� ���� ��� �Լ�					
		DLLFunction	int	IMCT_ETH_SET_CONFIG_SOFTWARE_LIMIT_STOP_TYPE(int nIndex, int nAxis, int nValue); ///< SOFTWARE LIMIT ��, ���� ��� ���� �Լ�									
		DLLFunction	int	IMCT_ETH_GET_CONFIG_SOFTWARE_LIMIT_STOP_TYPE(int nIndex, int nAxis, int &nValue); ///< SOFTWARE LIMIT ��, ���� ��� ��� �Լ�						
		DLLFunction	int	IMCT_ETH_SET_CONFIG_SOFTWARE_LIMIT_NEGATIVE(int nIndex, int nAxis, int nValue); ///< SOFTWARE LIMIT (-)���� ����ġ ���� �Լ�									
		DLLFunction	int	IMCT_ETH_GET_CONFIG_SOFTWARE_LIMIT_NEGATIVE(int nIndex, int nAxis, int &nValue);	///< SOFTWARE LIMIT (-)���� ����ġ ��� �Լ�					
		DLLFunction	int	IMCT_ETH_SET_CONFIG_SOFTWARE_LIMIT_POSITIVE(int nIndex, int nAxis, int nValue); ///< SOFTWARE LIMIT (+)���� ����ġ ���� �Լ�								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_SOFTWARE_LIMIT_POSITIVE(int nIndex, int nAxis, int &nValue);	///< SOFTWARE LIMIT (+)���� ����ġ ��� �Լ�					

		/** @brief  CONFIG - �� ��� ���� [�޸� ���� ��] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_USE_SEL(int nIndex, int nAxis, int nValue); ///< �� ��� ��� ���� ���� �Լ�						
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_USE_SEL(int nIndex, int nAxis, int &nValue);	///< �� ��� ��� ���� ��� �Լ�			
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_LOGIC(int nIndex, int nAxis, int nValue); ///< �� ��� ���� ��� ���� �Լ�							
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_LOGIC(int nIndex, int nAxis, int &nValue); ///< �� ��� ���� ��� ��� �Լ�						
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_WIDTH(int nIndex, int nAxis, int nValue); ///< ����� ���� �Լ�							
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_WIDTH(int nIndex, int nAxis, int &nValue); ///< ����� ��� �Լ�					
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_SOURCE_SEL(int nIndex, int nAxis, int nValue); ///< �� ��� SOURCE ���� ���� �Լ�					
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_SOURCE_SEL(int nIndex, int nAxis, int &nValue); ///< �� ��� SOURCE ���� ��� �Լ�			
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_COUTER_DIRECTION(int nIndex, int nAxis, int nValue);	///< �� ��� ī���� ���� ���� �Լ�						
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_COUTER_DIRECTION(int nIndex, int nAxis, int &nValue); ///< �� ��� ī���� ���� ��� �Լ�
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_COUTER_POSITION(int nIndex, int nAxis, int nValue);	///< �� ��� ī���� �̼۷� ���� �Լ�						
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_COUTER_POSITION(int nIndex, int nAxis, int &nValue); ///< �� ��� ī���� �̼۷� ��� �Լ�

		/** @brief  CONFIG - ���� ī���� ���� [�޸� ���� ��] */
		DLLFunction int	IMCT_ETH_SET_CONFIG_DEVIATION_COUNTER_SETTING_USE_SEL(int nIndex, int nAxis, int nValue); ///< ���� ī���� ��� ���� ���� �Լ�					
		DLLFunction int	IMCT_ETH_GET_CONFIG_DEVIATION_COUNTER_SETTING_USE_SEL(int nIndex, int nAxis, int &nValue); ///< ���� ī���� ��� ���� ��� �Լ�				
		DLLFunction int	IMCT_ETH_SET_CONFIG_DEVIATION_COUNTER_SETTING_STOP_TYPE(int nIndex, int nAxis, int nValue);	///< ���� ī���� ���� ��� ���� �Լ�			
		DLLFunction int	IMCT_ETH_GET_CONFIG_DEVIATION_COUNTER_SETTING_STOP_TYPE(int nIndex, int nAxis, int &nValue); ///< ���� ī���� ���� ��� ��� �Լ�		
		DLLFunction int	IMCT_ETH_SET_CONFIG_DEVIATION_COUNTER_SETTING_COUNTER(int nIndex, int nAxis, int nValue); ///< ���� ī���� ���� �Լ�								
		DLLFunction int	IMCT_ETH_GET_CONFIG_DEVIATION_COUNTER_SETTING_COUNTER(int nIndex, int nAxis, int &nValue); ///< ���� ī���� ��� �Լ�			

		/** @brief  CONFIG - �˶� �߻��� ���� ���� [�޸� ���� ��] */
		DLLFunction int	IMCT_ETH_SET_CONFIG_ALARM_SETTING_USE_SEL(int nIndex, int nAxis, int nValue); ///< �˶� �߻��� ���� ��� ��� ���� ���� �Լ�							
		DLLFunction int	IMCT_ETH_GET_CONFIG_ALARM_SETTING_USE_SEL(int nIndex, int nAxis, int &nValue); ///< �˶� �߻��� ���� ��� ��� ���� ��� �Լ�						
		DLLFunction int	IMCT_ETH_SET_CONFIG_ALARM_SETTING_STOP_TYPE(int nIndex, int nAxis, int nValue); ///< �˶� �߻��� ���� ��� ���� �Լ�									
		DLLFunction int	IMCT_ETH_GET_CONFIG_ALARM_SETTING_STOP_TYPE(int nIndex, int nAxis, int &nValue); ///< �˶� �߻��� ���� ��� ��� �Լ�							

		/** @brief  CONFIG - BACKLISH ���� [�޸� ���� ��] */
		DLLFunction int	IMCT_ETH_SET_CONFIG_BACKLISH_USE_SEL(int nIndex, int nAxis, int nValue); ///< BACKLISH ��� ���� ���� �Լ�										
		DLLFunction int	IMCT_ETH_GET_CONFIG_BACKLISH_USE_SEL(int nIndex, int nAxis, int &nValue); ///< BACKLISH ��� ���� ��� �Լ�					
		DLLFunction int	IMCT_ETH_SET_CONFIG_BACKLISH_COUNTER_SEL(int nIndex, int nAxis, int nValue); ///< BACKLISH ī���� ���� �Լ�								
		DLLFunction int	IMCT_ETH_GET_CONFIG_BACKLISH_COUNTER_SEL(int nIndex, int nAxis, int &nValue); ///< BACKLISH ī���� ��� �Լ�							
		DLLFunction int	IMCT_ETH_SET_CONFIG_BACKLISH_VELOCITY(int nIndex, int nAxis, int nValue); ///< BACKLISH �ӵ� ���� �Լ�										
		DLLFunction int	IMCT_ETH_GET_CONFIG_BACKLISH_VELOCITY(int nIndex, int nAxis, int &nValue); ///< BACKLISH �ӵ� ��� �Լ�									
		DLLFunction int	IMCT_ETH_SET_CONFIG_BACKLISH_POSITION(int nIndex, int nAxis, int nValue); ///< BACKLISH ��ġ ���� �Լ�											
		DLLFunction int	IMCT_ETH_GET_CONFIG_BACKLISH_POSITION(int nIndex, int nAxis, int &nValue); ///< BACKLISH ��ġ ��� �Լ�		

		// COMMON CONFIG- DIGITAL FILLTER [�޸� ���� ��] 
		DLLFunction	int	IMCT_ETH_SET_COMMON_CONFIG_DIGITAL_FILLTER(int nIndex, int nPort, int nPin, int nValue);
		DLLFunction	int	IMCT_ETH_GET_COMMON_CONFIG_DIGITAL_FILLTER(int nIndex, int nPort, int nPin, int &nValue);

		// COMMON CONFIG- DIGITAL FILLTER LOGIC LEVEL[�޸� ���� ��] 
		DLLFunction	int	IMCT_ETH_SET_COMMON_CONFIG_DIGITAL_FILLTER_LOGIC_LEVEL(int nIndex, int nPort, int nPin, int nValue); // 0:B ����, 1: A ����
		DLLFunction	int	IMCT_ETH_GET_COMMON_CONFIG_DIGITAL_FILLTER_LOGIC_LEVEL(int nIndex, int nPort, int nPin, int &nValue);// 0:B ����, 1: A ����	

		// COMMON - Emergency Stop & Clear [�޸� ���� �ȵ�] 
		DLLFunction int	IMCT_ETH_SET_COMMON_EMERGENCY_STOP(int nIndex);  ///< EMERGENCY STOP ���� �Լ�
		DLLFunction int	IMCT_ETH_SET_COMMON_EMERGENCY_CLEAR(int nIndex); ///< EMERGENCY CLEAR ���� �Լ�	

		// MEMORY - I-Code, T-Code �׷� ���� ����[�޸� ���� ��]
		DLLFunction	int	IMCT_ETH_SET_MEMORY_TYPE_SEL(int nIndex, int nValue);  ///< MEMORY TYPE ���� �Լ�							
		DLLFunction	int	IMCT_ETH_GET_MEMORY_TYPE_SEL(int nIndex, int &nValue); ///< MEMORY TYPE ��� �Լ�			
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_COUNT_I_CODE(int nIndex, int nValue);	///< MEMORY I-CODE �� �׷� ���� ���� �Լ�				
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_COUNT_I_CODE(int nIndex, int &nValue);	///< MEMORY I-CODE �� �׷� ���� ��� �Լ�		
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_COUNT_T_CODE(int nIndex, int nValue);	///< MEMORY T-CODE �� �׷� ���� ���� �Լ�			
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_COUNT_T_CODE(int nIndex, int &nValue);	///< MEMORY T-CODE �� �׷� ���� ��� �Լ�			
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_SETTING_I_CODE(int nIndex, int nGroupNo, int GroupSize); ///< MEMORY I-CODE GROUP  ���� �Լ�							
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_SETTING_I_CODE(int nIndex, int nGroupNo, int &nGroupSize); ///< MEMORY I-CODE GROUP  ��� �Լ�											
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_SETTING_T_CODE(int nIndex, int nGroupNo, int GroupSize, int nGroupType); ///< MEMORY T-CODE GROUP ���� �Լ�						
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_SETTING_T_CODE(int nIndex, int nGroupNo, int &GroupSize, int &nGroupType); ///< MEMORY T-CODE GROUP ��� �Լ�										
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_SELECT_I_CODE(int nIndex, int nGroupNo); ///< MEMORY I-CODE GROUP ���� ���� �Լ�							
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_SELECT_I_CODE(int nIndex, int &nGroupNo);	///< MEMORY I-CODE GROUP ���� ��� �Լ�									
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_SELECT_T_CODE(int nIndex, int nGroupNo); ///< MEMORY T-CODE GROUP ���� ���� �Լ�							
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_SELECT_T_CODE(int nIndex, int &nGroupNo);	///< MEMORY T-CODE GROUP ���� ��� �Լ�		
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_NAME_I_CODE(int nIndex, int nGroupNo, char pName[18]); ///< MEMORY I-CODE GROUP �̸� ���� �Լ�							
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_NAME_I_CODE(int nIndex, int nGroupNo, char pName[18]); ///< MEMORY I-CODE GROUP �̸� ��� �Լ�										
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_NAME_T_CODE(int nIndex, int nGroupNo, char pName[18]); ///< MEMORY T-CODE GROUP �̸� ���� �Լ�								
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_NAME_T_CODE(int nIndex, int nGroupNo, char pName[18]); ///< MEMORY T-CODE GROUP �̸� ��� �Լ�		

		// PENDENT	- T-CODE ���� [�޸� ���� ��]
		DLLFunction int	IMCT_ETH_SET_PENDENT_DATA_SEND_START(int nIndex);
		DLLFunction int	IMCT_ETH_SET_PENDENT_DATA(int nIndex, int nAxis[8], int nValue[8]);	///< T-Code ������ �Է�	���� �Լ�	
		DLLFunction int	IMCT_ETH_GET_PENDENT_DATA(int nIndex, int nAddress, int &nEndStatus, int nAxis[8], int nValue[8]);	///< T-Code ������ �Է�	��� �Լ�
		DLLFunction int	IMCT_ETH_SET_PENDENT_PALLET_SETTING(int nIndex, int nAddress, int nValue[8]);	///< PALLET ȯ�� ���� �Լ�							
		DLLFunction int	IMCT_ETH_GET_PENDENT_PALLET_SETTING(int nIndex, int nAddress, int nValue[8]);	///< PALLET ȯ�� ��� �Լ� 	
		DLLFunction int	IMCT_ETH_SET_PENDENT_DATA_SEND_END(int nIndex);	///< T-Code ������ ���� �Ϸ� ����	

		// I-CODE  - I-CODE ��ɾ� ���� [�޸� ���� ��]
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_BOARD_SELECT(int nIndex, int nValue);  ///< Board ���� �Լ�							
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_COORDINATE(int nIndex, int nValue); ///< ��ǥ�� ���� �Լ�								
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_CONTROL_VELOCITY_SET(int nIndex, int nAxis[8], int nValue[8]);	///< ���� �ӵ� ���� �Լ�
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_CONTROL_POSITION(int nIndex, int nAxis[8], int nValue[8]); ///< ��ġ END CHECK ���� �Լ�	
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_CONTROL_POSITION_NO_END(int nIndex, int nAxis[8], int nValue[8]); ///< ��ġ NO END CHECK ���� �Լ�	
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_CONTINUE_POSITIVE_VELOCITY(int nIndex, int nAxis[8], int nValue[8]); ///< ������ ���� ����	�Լ�			
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_CONTINUE_NEGATIVE_VELOCITY(int nIndex, int nAxis[8], int nValue[8]); ///< ������ ���� ����	�Լ�			
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_VELOCITY_SET(int nIndex, int nValue); ///< ���� �ӵ� ���� �Լ�	
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_LINEAR(int nIndex, int nAxis[4], int nValue[4]); ///< ���� ���� ����  �Լ�				
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_CIRCULAR_CW(int nIndex, int nValue[4]); ///< ��ȣ ���� CW���� ����	�Լ�				
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_CIRCULAR_CCW(int nIndex, int nValue[4]); ///< ��ȣ ���� CCW���� ���� �Լ�				
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_HELICALL_CW(int nIndex, int nValue[5]);	///< Helical ���� CW���� ���� �Լ�					
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_HELICALL_CCW(int nIndex, int nValue[5]); ///< Helical ���� CCW���� ���� �Լ�							
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_NEXT_STEP_DELAY(int nIndex, int nValue); ///< NEXT STEP DELAY ���� �Լ�
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_NEXT_STEP_JMP(int nIndex, int nValue); ///< NEXT STEP JMP ����	�Լ�	
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_NEXT_STEP_IJMP(int nIndex, int nPort, int nPin, int nLevel, int nAddress); ///< NEXT STEP IJMP ���� �Լ�	 		
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_NEXT_STEP_CJMP(int nIndex, int nRegister, int nCountNo, int nCompareType, int nAddress); ///< NEXT STEP CJMP ���� �Լ� 		
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_LOOP_START(int nIndex, int nGroup, int nCount); ///< LOOP COUNT ���� �Լ�		
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_LOOP_END(int nIndex, int nGroup); ///< Loop End ���� �Լ�									
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_OUTPUT_BYTE(int nIndex, int nPort, int nValue[8]);	///< OUTPUT PORT BYTE ���� ���� �Լ�							
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_OUTPUT_BIT(int nIndex, int nPort, int nPin, int nLevel); ///< OUTPUT PORT BIT ���� ���� �Լ�										
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_COUNTER(int nIndex, int nRegister, int nAction, int nCountNo);	///< COUNTER ���� �Լ�											
		DLLFunction	int	IMCT_ETH_SET_I_CODE_DATA_TEACHING_MOVE(int nIndex, int nGroupNumber, int nAddress);
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_PALLET_INDEX(int nIndex, int nRegister, int nCountNo, int nValue[3]);	///< PALLET INDEX ���� �Լ�						
		DLLFunction	int	IMCT_ETH_SET_I_CODE_DATA_PALLET_MOVE(int nIndex, int nGroupNumber);

		//I-CODE  - I-CODE ���� ���� �� ���� ���� [�޸� ���� �ȵ�]
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_SEND_START(int nIndex); ///< I-Code Data ���� ���� 	�Լ�									
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_SEND_END(int nIndex); ///< I-Code ���� ���� �Լ� 		

		//I-CODE  - I-CODE ���� ���� [�޸� ���� �ȵ�]
		DLLFunction int	IMCT_ETH_SET_I_CODE_START(int nIndex); ///< I-Code ���� ���� �Լ�		
		DLLFunction int	IMCT_ETH_SET_I_CODE_STOP(int nIndex); ///< I-Code ���� ���� �Լ�
		DLLFunction int	IMCT_ETH_SET_I_CODE_PAUSE(int nIndex); ///< I-Code ���� �Ͻ� ���� �Լ�

		//I-CODE  - I-CODE ���� ����
		DLLFunction int	IMCT_ETH_GET_COMMON_I_CODE_LINE(int nIndex, int &nValue); ///< I-CODE ������ LINE Ȯ��	 �Լ�
		DLLFunction int	IMCT_ETH_GET_COMMON_RECEIVE_I_CODE_DATA(int nIndex, int nAddress, int &nEnd, unsigned char buffer[64]);

		DLLFunction int	IMCT_ETH_GET_COMMON_MOTION_CHECK(int nIndex, int nAxis, int nValue, unsigned char buffer[64]);

		//-- ���� ����
		DLLFunction int	IMCT_ETH_SET_COMMON_BOARD_SELECT(int nIndex, int nValue); // (A Board : 0, B Board : 1)	

		DLLFunction	int	IMCT_ETH_SET_COMMON_BOARD_IO_CHECK(int nIndex, int nValue); ///< Board I/O ���� �Լ�
		DLLFunction	int	IMCT_ETH_GET_COMMON_BOARD_IO_CHECK(int nIndex, int &nStatus, int &nValue); ///< Board I/O ���� ��� �Լ�

		DLLFunction int	IMCT_ETH_GET_COMMON_RESPONSE_CHECK(int nIndex, int &nValue); ///< ������ �۽� ���� ���� Ȯ�� �Լ�	

		DLLFunction int	IMCT_ETH_SET_COMMON_ERROR_CLEAR(int nIndex); ///< Error List Clear �Լ�
		DLLFunction int	IMCT_ETH_GET_COMMON_ERROR_LIST(int nIndex, int nAddress, int &nAxis, int &nError); ///< ERROR ���� Ȯ�� �Լ�

		DLLFunction	int	IMCT_ETH_SET_COMMON_BOARD_INITIALIZE(int nIndex, int nValue);//< BOARD ���� �ʱ�ȭ �Լ�(0: CONFIG , 1: I-DATA)
		DLLFunction	int	IMCT_ETH_GET_COMMON_RESERVE_MOTION_CHECK(int nIndex, int &nReserve);	///< ���� ���� Ȯ�� �Լ�

		DLLFunction	int	IMCT_ETH_GET_COMMON_FIRMWARE_VERSION(int nIndex, char version[24]);	//< �߿��� ���� ����
		//-- INTERLOCK(2��)
		//-- INTERLOCK(4��, 8���)
		DLLFunction int IMCT_ETH_GET_INTERLOCK_S_CURVE_ACC_TIME(int nAccTime, int nSCuveAccPercent, int nStartSpeed, int nRunSpeed, double dScale);
		DLLFunction int IMCT_ETH_GET_INTERLOCK_S_CURVE_DEC_TIME(int nDecTime, int nSCuveDecPercent, int nStartSpeed, int nRunSpeed, double dScale);

		//-- OVERRIDE 
		DLLFunction int	IMCT_ETH_SET_VELOCITY_OVERRIDE(int nIndex, int nAxis[8], int nValue[8]);
		DLLFunction int	IMCT_ETH_SET_POSITION_OVERRIDE(int nIndex, int nAxis[8], int nValue[8]);
	#ifdef __cplusplus
}
#endif

#endif // __IMCT_DLL_H__