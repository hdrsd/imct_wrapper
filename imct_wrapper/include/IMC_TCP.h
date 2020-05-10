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
		/** @brief  Parameter 공통 정보
		축 번호 값     : X_AXIS = 1,	Y_AXIS = 2,	Z_AXIS = 3, U_AXIS = 4,	A_AXIS = 5, B_AXIS = 6, C_AXIS = 7, D_AXIS = 8
		int nIndex     : 시리얼 통신 객체 번호(0~128), 제품을 1대 연결 할 경우, nIndex 값이 '0'이 됩니다.
		int nAxis      : 선택할 축 번호(1: X축 , 2: Y축 , 3: Z축 , 4: U축, 5: A축 , 6: B축 , 7: C축, 8: D축)
		int nAxis[8]   : 선택할 축 번호 배열
		int nValue     : 각 함수 별 정보 설정 변수
		int nValue[8]  : 각 함수 별 정보 설정 변수 배열
		int &nValue    : 각 함수 별 정보 참조 변수
		int &nValue[8] : 각 함수 별 정보 참조 변수 배열
		char pName[18] : 파일 이름 정보 설정 배열(최대 18개 문자 입력 가능)
		*/

		/** @brief  COMMUNICATION 설정*/
		DLLFunction int	 IMCT_ETH_INITIALIZE(int &nIndex, char* address, int port);
		DLLFunction int	 IMCT_ETH_UNINITIALIZE(int nIndex);

		//<<< MOTION SCALE 설정[메모리 저장 됨]
		DLLFunction	int	IMCT_ETH_SET_CONFIG_PPR(int nIndex, int nAxis, int nValue);	///< SCALE - PPR 설정 함수															
		DLLFunction	int	IMCT_ETH_GET_CONFIG_PPR(int nIndex, int nAxis, int &nValue); ///< SCALE - PPR 얻기 함수						
		DLLFunction	int	IMCT_ETH_SET_CONFIG_UPR(int nIndex, int nAxis, int nValue); ///< SCALE - UPR 설정 함수												
		DLLFunction	int	IMCT_ETH_GET_CONFIG_UPR(int nIndex, int nAxis, int &nValue); ///< SCALE - UPR 얻기 함수											

		//<<< MOTION 위치 제어
		DLLFunction int	IMCT_ETH_SET_COORDINATE(int nIndex, int nValue);						// 좌표계 설정 함수(상대 좌표계:0, 절대 좌표계:1) [메모리 저장 됨]							
		DLLFunction int	IMCT_ETH_SET_CONTROL_VELOCITY(int nIndex, int nAxis[8], int nValue[8]);	// 제어 속도 설정 함수 [메모리 저장 안됨]
		DLLFunction int	IMCT_ETH_SET_CONTROL_POSITION(int nIndex, int nAxis[8], int nValue[8]);	// 위치 END CHECK 제어 함수[메모리 저장 안됨]	

		//<<< MOTION 보간 제어(2축에선 사용 불가) [메모리 저장 안됨]
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_VELOCITY(int nIndex, int nValue);				// 보간 속도 설정 함수	
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_BOARD_SELECT(int nIndex, int nValue);			// 보간 제어시 Board 선택(A Board : 0, B Board : 1), 8축 시에만 적용
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_LINEAR(int nIndex, int nAxis[4], int nValue[4]); // 직선 보간 제어  함수				
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_CIRCULAR_CW(int nIndex, int nValue[4]);			// 원호 보간 CW방향 제어 함수				
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_CIRCULAR_CCW(int nIndex, int nValue[4]);			// 원호 보간 CCW방향 제어 함수				
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_HELICALL_CW(int nIndex, int nValue[5]);			// Helical 보간 CW방향 제어 함수					
		DLLFunction int	IMCT_ETH_SET_INTERPOLL_HELICALL_CCW(int nIndex, int nValue[5]);			// Helical 보간 CCW방향 제어 함수							

		//<<< MOTION 속도 제어(연속제어) [메모리 저장 안됨]
		DLLFunction int	IMCT_ETH_SET_CONTINUE_POSITIVE_VELOCITY(int nIndex, int nAxis[8], int nValue[8]); // 정방향 연속 운전 함수			
		DLLFunction int	IMCT_ETH_SET_CONTINUE_NEGATIVE_VELOCITY(int nIndex, int nAxis[8], int nValue[8]); // 역방향 연속 운전 함수			

		//<<< MOTION 공통 함수[메모리 저장 안됨]
		DLLFunction	int	IMCT_ETH_SET_COMMON_HOME(int nIndex, int nValue[8]); // (0:Disble, 1:Enable)
		DLLFunction	int	IMCT_ETH_SET_COMMON_STOP(int nIndex, int nValue[8]); // (0:Disble, 1:Enable)	
		DLLFunction int	IMCT_ETH_SET_COMMON_ALARM_CLEAR(int nIndex, int nValue[8]);    // (0:Disble, 1:Enable)				
		DLLFunction int	IMCT_ETH_SET_COMMON_ENCORDER_CLEAR(int nIndex, int nValue[8]); // (0:Disble, 1:Enable)
		DLLFunction int	IMCT_ETH_SET_COMMON_MOTOR_ON(int nIndex, int nValue[8]);  // (1: ON)
		DLLFunction int	IMCT_ETH_SET_COMMON_MOTOR_OFF(int nIndex, int nValue[8]);  // (1: ON)

		DLLFunction int	IMCT_ETH_SET_COMMON_ENCODER_SYNC(int nIndex); ///< Encoder Sync 함수(AZ 경우)

		//<<< MOTION JOG 동작 [메모리 저장 안됨]
		DLLFunction int	IMCT_ETH_SET_COMMON_JOG_CW(int nIndex, int nAxis);  ///< JOG CW 방향 동작 함수									 
		DLLFunction int	IMCT_ETH_SET_COMMON_JOG_CCW(int nIndex, int nAxis);	///< JOG CCW 방향 동작 함수		
		DLLFunction int	IMCT_ETH_SET_COMMON_JOG_STOP(int nIndex, int nAxis); ///< JOG 정지	

		//<<< MOTION 상태 함수(ALARM, BUSY ,HOME 완료 ,ENCODER) 
		///< 2축 상태 얻기 함수
		DLLFunction int	IMCT_ETH_GET_COMMON_2X_STATUS(int nIndex
			, int nType			 /* nType = 0 (Position) , nType = 1 (Velocity) */
			, int &nInfo		 /* 상태 정보: 0: 정상, 1: I-Code 동작중, 2: Emergency 상태 */
			, int nBusy[2]		 /* 배열 값이 0: OFF 1: ON */
			, int nAlarm[2]		 /* 배열 값이 0: OFF 1: ON */
			, int nLimit_P[2]	 /* 배열 값이 0: OFF 1: ON */
			, int nLimit_N[2]	 /* 배열 값이 0: OFF 1: ON */
			, int nHome[2]		 /* 배열 값이 0: OFF 1: ON */
			, int nSD[2]		 /* 배열 값이 0: OFF 1: ON */
			, int nInP[2]		 /* 배열 값이 0: OFF 1: ON */
			, int nTypeValue[2]  /* nType 조건에 따라 Position 또는 Velocity 값 참조 */
		);

		DLLFunction int	IMCT_ETH_GET_COMMON_4X_STATUS(int nIndex
			, int nType			 /* nType = 0 (Position) , nType = 1 (Velocity) */
			, int &nInfo		 /* 상태 정보: 0: 정상, 1: I-Code 동작중, 2: Emergency 상태 */
			, int nBusy[4]		 /* 배열 값이 0: OFF 1: ON */
			, int nAlarm[4]		 /* 배열 값이 0: OFF 1: ON */
			, int nLimit_P[4]	 /* 배열 값이 0: OFF 1: ON */
			, int nLimit_N[4]	 /* 배열 값이 0: OFF 1: ON */
			, int nHome[4]		 /* 배열 값이 0: OFF 1: ON */
			, int nSD[4]		 /* 배열 값이 0: OFF 1: ON */
			, int nInP[4]		 /* 배열 값이 0: OFF 1: ON */
			, int nTypeValue[4]  /* nType 조건에 따라 Position 또는 Velocity 값 참조 */
		);

		DLLFunction int	IMCT_ETH_GET_COMMON_8X_STATUS(int nIndex
			, int nType			 /* nType = 0 (Position) , nType = 1 (Velocity) */
			, int &nInfo		 /* 상태 정보: 0: 정상, 1: I-Code 동작중, 2: Emergency 상태 */
			, int nBusy[8]		 /* 배열 값이 0: OFF 1: ON */
			, int nAlarm[8]		 /* 배열 값이 0: OFF 1: ON */
			, int nLimit_P[8]	 /* 배열 값이 0: OFF 1: ON */
			, int nLimit_N[8]	 /* 배열 값이 0: OFF 1: ON */
			, int nHome[8]		 /* 배열 값이 0: OFF 1: ON */
			, int nSD[8]		 /* 배열 값이 0: OFF 1: ON */
			, int nInP[8]		 /* 배열 값이 0: OFF 1: ON */
			, int nTypeValue[8]  /* nType 조건에 따라 Position 또는 Velocity 값 참조 */
		);

		//<<< MOTION I/O 입출력 함수 [메모리 저장 됨]
		DLLFunction int	IMCT_ETH_GET_COMMON_INPUT_PORT(int nIndex, int nVaule[8]);	///< INPUT PORT 상태 얻기 함수	
		DLLFunction int	IMCT_ETH_SET_COMMON_OUTPUT_PORT(int nIndex, int nPort, int nValue[8]);
		DLLFunction int	IMCT_ETH_GET_COMMON_OUTPUT_PORT(int nIndex, int nVaule[8]); ///< OUTPUT PORT 상태 얻기 함수		

		//<<< MOTION 메모리 제어 [메모리 저장 됨]
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_WORKING_MODE(int nIndex, int nAxis, int nAddress, int nValue);  ///< 동작 MODE 설정 함수								
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_WORKING_MODE(int nIndex, int nAxis, int nAddress, int &nValue);	///< 동작 MODE 얻기 함수										
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_ACC(int nIndex, int nAxis, int nAddress, int nValue);  ///< 가속 시간 설정 함수(ms)									
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_ACC(int nIndex, int nAxis, int nAddress, int &nValue); ///< 가속 시간 얻기 함수(ms)														
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_DEC(int nIndex, int nAxis, int nAddress, int nValue); ///< 감속 시간 설정 함수(ms)											
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_DEC(int nIndex, int nAxis, int nAddress, int &nValue);	///< 감속 시간 얻기 함수(ms)													
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_START_SPD(int nIndex, int nAxis, int nAddress, int nValue);	///< 시작 속도 설정 함수(mm/Sec,°/Sec)									
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_START_SPD(int nIndex, int nAxis, int nAddress, int &nValue); ///< 시작 속도 얻기 함수(mm/Sec,°/Sec)												
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_RUN_SPD(int nIndex, int nAxis, int nAddress, int nValue); ///< 운전 속도 설정 함수(mm/Sec,°/Sec)										
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_RUN_SPD(int nIndex, int nAxis, int nAddress, int &nValue);	///< 운전 속도 얻기 함수(mm/Sec,°/Sec)												
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_MAG(int nIndex, int nAxis, int nAddress, double dValue); ///< 속도 배율 설정 함수(배)											
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_MAG(int nIndex, int nAxis, int nAddress, double &dValue); ///< 속도 배율 얻기 함수(배)														
		DLLFunction int	IMCT_ETH_SET_MOTION_DATA_POSITION(int nIndex, int nAxis, int nAddress, int nValue); ///< 이송량 설정 함수(Unit,°)										
		DLLFunction int	IMCT_ETH_GET_MOTION_DATA_POSITION(int nIndex, int nAxis, int nAddress, int &nValue);	///< 이송량 얻기 함수(Unit,°)			
																													//<<< MOTION 메모리 데이터 동작		
		DLLFunction	int	IMCT_ETH_SET_MOTION_DATA_START(int nIndex, int nAddress[8]); ///< 모션 동작 함수

		//-- INTERLOCK(2축용)
		DLLFunction int IMCT_2X_ETH_GET_INTERLOCK_ACC_DEC_TIME(int nAccDecTime, int nStartSpeed, int nRunSpeed, int nManification, double dScale);
		DLLFunction int IMCT_2X_ETH_GET_INTERLOCK_SPEED(int nSpeed, double dScale);
		DLLFunction int IMCT_2X_ETH_GET_INTERLOCK_POSITION(double dPosition, double dScale);

		//-- INTERLOCK(4축, 8축용)
		DLLFunction int IMCT_ETH_GET_INTERLOCK_ACC_TIME(int nAccTime, int nStartSpeed, int nRunSpeed, double dScale);
		DLLFunction int IMCT_ETH_GET_INTERLOCK_DEC_TIME(int nDecTime, int nStartSpeed, int nRunSpeed, double dScale);
		DLLFunction int IMCT_ETH_GET_INTERLOCK_SPEED(int nSpeed, double dScale);
		DLLFunction int IMCT_ETH_GET_INTERLOCK_POSITION(double dPosition, double dScale);

		//-- INTERLOCK(공통)
		DLLFunction int IMCT_ETH_GET_INTERLOCK_MAGNIFICATION(int nMagnification);

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//<<< 이후 함수들은 고급 기능 설정 입니다.
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//<<< 환경 Parameter
		/** @brief  CONFIG - 속도/위치 제어시 속도 설정 [메모리 저장 됨] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_LINE_S_CUVE_SEL(int nIndex, int nAxis, int nValue); ///< LINE , S-CURVE 선택 설정 함수(LINE: 0 , S-CURVE: 4)  
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_LINE_S_CUVE_SEL(int nIndex, int nAxis, int &nValue); ///< LINE , S-CURVE 선택 얻기 함수(LINE: 0 , S-CURVE: 4)  
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_S_CUV_ACC(int nIndex, int nAxis, int nValue); ///< S-CURVE 가속 비율 설정 함수(1~100%)	
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_S_CUV_ACC(int nIndex, int nAxis, int &nValue); ///< S-CURVE 가속 비율 얻기 함수(1~100%)	 		
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_S_CUV_DEC(int nIndex, int nAxis, int nValue); ///< S-CURVE 감속 비율 설정 함수(1~100%)		
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_S_CUV_DEC(int nIndex, int nAxis, int &nValue); ///< S-CURVE 감속 비율 얻기 함수(1~100%)			
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_ACC(int nIndex, int nAxis, int nValue); ///< 가속 시간 설정 함수(ms)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_ACC(int nIndex, int nAxis, int &nValue); ///< 가속 시간 얻기 함수(ms)				
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_DEC(int nIndex, int nAxis, int nValue); ///< 감속 시간 설정 함수(ms)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_DEC(int nIndex, int nAxis, int &nValue); ///< 감속 시간 얻기 함수(ms)				
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_START_SPD(int nIndex, int nAxis, int nValue); ///< 시작 속도 설정 함수(mm/Sec,°/Sec)		
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_START_SPD(int nIndex, int nAxis, int &nValue); ///< 시작 속도 얻기 함수(mm/Sec,°/Sec)	
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_RUN_SPD(int nIndex, int nAxis, int nValue); ///< 운전 속도 설정 함수(mm/Sec,°/Sec)			
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_RUN_SPD(int nIndex, int nAxis, int &nValue); ///< 운전 속도 얻기 함수(mm/Sec,°/Sec)
		DLLFunction	int	IMCT_ETH_SET_CONFIG_CONTROL_VELOCITY_MAG(int nIndex, int nAxis, double dValue);	///< 속도 배율 설정 함수(배)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_CONTROL_VELOCITY_MAG(int nIndex, int nAxis, double &dValue); ///< 속도 배율 얻기 함수(배)			

		 /** @brief  COMMON CONFIG - 보간 제어 속도 설정 [메모리 저장 됨] */
		DLLFunction int	IMCT_ETH_SET_COMMON_CONFIG_INTERPOLL_VELOCITY_ACC(int nIndex, int nValue);	///< 가속 시간 설정 함수(ms)							
		DLLFunction int	IMCT_ETH_GET_COMMON_CONFIG_INTERPOLL_VELOCITY_ACC(int nIndex, int &nValue);	///< 가속 시간 얻기 함수(ms)								
		DLLFunction int	IMCT_ETH_SET_COMMON_CONFIG_INTERPOLL_VELOCITY_DEC(int nIndex, int nValue);	///< 감속 시간 설정 함수(ms)							
		DLLFunction int	IMCT_ETH_GET_COMMON_CONFIG_INTERPOLL_VELOCITY_DEC(int nIndex, int &nValue);	///< 감속 시간 얻기 함수(ms)								
		DLLFunction int	IMCT_ETH_SET_COMMON_CONFIG_INTERPOLL_VELOCITY_START_SPD(int nIndex, int nValue);  ///< 시작 속도 설정 함수(mm/Sec,°/Sec)					
		DLLFunction int	IMCT_ETH_GET_COMMON_CONFIG_INTERPOLL_VELOCITY_START_SPD(int nIndex, int &nValue); ///< 시작 속도 얻기 함수(mm/Sec,°/Sec)								
		DLLFunction int	IMCT_ETH_SET_COMMON_CONFIG_INTERPOLL_VELOCITY_RUN_SPD(int nIndex, int nValue);  ///< 운전 속도 설정 함수(mm/Sec,°/Sec)					
		DLLFunction int	IMCT_ETH_GET_COMMON_CONFIG_INTERPOLL_VELOCITY_RUN_SPD(int nIndex, int &nValue); ///< 운전 속도 얻기 함수(mm/Sec,°/Sec)	

		/** @brief  CONFIG - HOME 속도 설정 [메모리 저장 됨] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_ACC(int nIndex, int nAxis, int nValue); ///< 가속 시간 설정 함수(ms)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_ACC(int nIndex, int nAxis, int &nValue); ///< 가속 시간 얻기 함수(ms)				
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_DEC(int nIndex, int nAxis, int nValue); ///< 감속 시간 설정 함수(ms)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_DEC(int nIndex, int nAxis, int &nValue);	///< 감속 시간 얻기 함수(ms)				
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_START_SPD(int nIndex, int nAxis, int nValue);	///< 시작 속도 설정 함수(mm/Sec,°/Sec)		
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_START_SPD(int nIndex, int nAxis, int &nValue);///< 시작 속도 얻기 함수(mm/Sec,°/Sec)	
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_RUN_SPD(int nIndex, int nAxis, int nValue); ///< 운전 속도 설정 함수(mm/Sec,°/Sec)			
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_RUN_SPD(int nIndex, int nAxis, int &nValue);	///< 운전 속도 얻기 함수(mm/Sec,°/Sec)
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_MAG(int nIndex, int nAxis, double dValue); ///< 속도 배율 설정 함수(배)				
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_MAG(int nIndex, int nAxis, double &dValue); ///< 속도 배율 얻기 함수(배)				

		/** @brief  CONFIG - JOG 속도 설정 [메모리 저장 됨] */
		DLLFunction int	IMCT_ETH_SET_CONFIG_JOG_ACC(int nIndex, int nAxis, int nValue);	///< 가속 시간 설정 함수(ms)				
		DLLFunction int	IMCT_ETH_GET_CONFIG_JOG_ACC(int nIndex, int nAxis, int &nValue); ///< 가속 시간 얻기 함수(ms)				
		DLLFunction int	IMCT_ETH_SET_CONFIG_JOG_DEC(int nIndex, int nAxis, int nValue);	///< 감속 시간 설정 함수(ms)				
		DLLFunction int	IMCT_ETH_GET_CONFIG_JOG_DEC(int nIndex, int nAxis, int &nValue); ///< 감속 시간 얻기 함수(ms)				
		DLLFunction int	IMCT_ETH_SET_CONFIG_JOG_START_SPD(int nIndex, int nAxis, int nValue); ///< 시작 속도 설정 함수(mm/Sec,°/Sec)		
		DLLFunction int	IMCT_ETH_GET_CONFIG_JOG_START_SPD(int nIndex, int nAxis, int &nValue); ///< 시작 속도 얻기 함수(mm/Sec,°/Sec)	
		DLLFunction int	IMCT_ETH_SET_CONFIG_JOG_RUN_SPD(int nIndex, int nAxis, int nValue);	///< 운전 속도 설정 함수(mm/Sec,°/Sec)			
		DLLFunction int	IMCT_ETH_GET_CONFIG_JOG_RUN_SPD(int nIndex, int nAxis, int &nValue); ///< 운전 속도 얻기 함수(mm/Sec,°/Sec)
		DLLFunction int	IMCT_ETH_SET_CONFIG_JOG_MAG(int nIndex, int nAxis, double dValue); ///< 속도 배율 설정 함수(배)				
		DLLFunction int	IMCT_ETH_GET_CONFIG_JOG_MAG(int nIndex, int nAxis, double &dValue); ///< 속도 배율 얻기 함수(배)				

		/** @brief  CONFIG - HOME 옵션 설정 [메모리 저장 됨] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_DIRECTION(int nIndex, int nAxis, int nValue); ///< Home 방향 설정 함수						
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_DIRECTION(int nIndex, int nAxis, int &nValue); ///< Home 방향 얻기 함수	
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_MODE(int nIndex, int nAxis, int nValue); ///< Home 모드 설정 함수										
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_MODE(int nIndex, int nAxis, int &nValue); ///< Home 모드 얻기 함수					
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_OFFSET(int nIndex, int nAxis, int nValue);	///< Home OFFSET 설정 함수								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_OFFSET(int nIndex, int nAxis, int &nValue);	///< Home OFFSET 얻기 함수						
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_SENSOR_LEVEL(int nIndex, int nAxis, int nValue);	///< Home SENSOR LEVEL 설정 함수								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_SENSOR_LEVEL(int nIndex, int nAxis, int &nValue);	///< Home SENSOR LEVEL 얻기 함수				
		DLLFunction	int	IMCT_ETH_SET_CONFIG_HOME_SPEED_PATTERN(int nIndex, int nAxis, int nValue);	///< Home SPEED PATTERN 설정 함수								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_HOME_SPEED_PATTERN(int nIndex, int nAxis, int &nValue);	///< Home SPEED PATTERN 얻기 함수				

		/** @brief  CONFIG - ENCORDER 설정 [메모리 저장 됨] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_ENCORDER_IN_EXT_SEL(int nIndex, int nAxis, int nValue);	///< ENCODER 내부,외부 설정 함수									
		DLLFunction	int	IMCT_ETH_GET_CONFIG_ENCORDER_IN_EXT_SEL(int nIndex, int nAxis, int &nValue); ///< ENCODER 내부,외부 얻기 함수								
		DLLFunction	int	IMCT_ETH_SET_CONFIG_ENCORDER_MULTIPLYING(int nIndex, int nAxis, int nValue); ///< ENCODER 체배율 설정 함수								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_ENCORDER_MULTIPLYING(int nIndex, int nAxis, int &nValue); ///< ENCODER 체배율 얻기 함수						
		DLLFunction	int	IMCT_ETH_SET_CONFIG_ENCORDER_PPR(int nIndex, int nAxis, int nValue); ///< ENCODER PPR 설정 함수														
		DLLFunction	int	IMCT_ETH_GET_CONFIG_ENCORDER_PPR(int nIndex, int nAxis, int &nValue); ///< ENCODER PPR 얻기 함수					
		DLLFunction	int	IMCT_ETH_SET_CONFIG_ENCORDER_UPR(int nIndex, int nAxis, int nValue); ///< ENCODER UPR 설정 함수													
		DLLFunction	int	IMCT_ETH_GET_CONFIG_ENCORDER_UPR(int nIndex, int nAxis, int &nValue); ///< ENCODER UPR 얻기 함수											

		/** @brief  CONFIG - 펄스 출력 형태 설정 [메모리 저장 됨] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_PULSE_OUTPUT_SETTING(int nIndex, int nAxis, int nValue); ///< 펄스 출력 형태 설정 함수									
		DLLFunction	int	IMCT_ETH_GET_CONFIG_PULSE_OUTPUT_SETTING(int nIndex, int nAxis, int &nValue); ///< 펄스 출력 형태 얻기 함수							

		/** @brief  CONFIG - EMRGENCY STOP 설정 [메모리 저장 됨] */
		DLLFunction int	IMCT_ETH_SET_CONFIG_EMRGENCY_STOP(int nIndex, int nAxis, int nValue); ///< 긴급 정지 상태 설정 함수											
		DLLFunction int	IMCT_ETH_GET_CONFIG_EMRGENCY_STOP(int nIndex, int nAxis, int &nValue); ///< 긴급 정지 상태 얻기 함수				

		/** @brief  CONFIG - SOFTWARE LIMIT 설정 [메모리 저장 됨] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_SOFTWARE_LIMIT_USE_SEL(int nIndex, int nAxis, int nValue); ///< SOFTWARE LIMIT 사용 유무 설정 함수								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_SOFTWARE_LIMIT_USE_SEL(int nIndex, int nAxis, int &nValue);	///< SOFTWARE LIMIT 사용 유무 얻기 함수					
		DLLFunction	int	IMCT_ETH_SET_CONFIG_SOFTWARE_LIMIT_STOP_TYPE(int nIndex, int nAxis, int nValue); ///< SOFTWARE LIMIT 시, 정지 방법 설정 함수									
		DLLFunction	int	IMCT_ETH_GET_CONFIG_SOFTWARE_LIMIT_STOP_TYPE(int nIndex, int nAxis, int &nValue); ///< SOFTWARE LIMIT 시, 정지 방법 얻기 함수						
		DLLFunction	int	IMCT_ETH_SET_CONFIG_SOFTWARE_LIMIT_NEGATIVE(int nIndex, int nAxis, int nValue); ///< SOFTWARE LIMIT (-)방향 제한치 설정 함수									
		DLLFunction	int	IMCT_ETH_GET_CONFIG_SOFTWARE_LIMIT_NEGATIVE(int nIndex, int nAxis, int &nValue);	///< SOFTWARE LIMIT (-)방향 제한치 얻기 함수					
		DLLFunction	int	IMCT_ETH_SET_CONFIG_SOFTWARE_LIMIT_POSITIVE(int nIndex, int nAxis, int nValue); ///< SOFTWARE LIMIT (+)방향 제한치 설정 함수								
		DLLFunction	int	IMCT_ETH_GET_CONFIG_SOFTWARE_LIMIT_POSITIVE(int nIndex, int nAxis, int &nValue);	///< SOFTWARE LIMIT (+)방향 제한치 얻기 함수					

		/** @brief  CONFIG - 비교 출력 설정 [메모리 저장 됨] */
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_USE_SEL(int nIndex, int nAxis, int nValue); ///< 비교 출력 사용 유무 설정 함수						
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_USE_SEL(int nIndex, int nAxis, int &nValue);	///< 비교 출력 사용 유무 얻기 함수			
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_LOGIC(int nIndex, int nAxis, int nValue); ///< 비교 출력 로직 방법 설정 함수							
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_LOGIC(int nIndex, int nAxis, int &nValue); ///< 비교 출력 로직 방법 얻기 함수						
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_WIDTH(int nIndex, int nAxis, int nValue); ///< 출력폭 설정 함수							
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_WIDTH(int nIndex, int nAxis, int &nValue); ///< 출력폭 얻기 함수					
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_SOURCE_SEL(int nIndex, int nAxis, int nValue); ///< 비교 출력 SOURCE 선택 설정 함수					
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_SOURCE_SEL(int nIndex, int nAxis, int &nValue); ///< 비교 출력 SOURCE 선택 얻기 함수			
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_COUTER_DIRECTION(int nIndex, int nAxis, int nValue);	///< 비교 출력 카운터 방향 설정 함수						
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_COUTER_DIRECTION(int nIndex, int nAxis, int &nValue); ///< 비교 출력 카운터 방향 얻기 함수
		DLLFunction	int	IMCT_ETH_SET_CONFIG_COMPARE_OUTPUT_SETTING_COUTER_POSITION(int nIndex, int nAxis, int nValue);	///< 비교 출력 카운터 이송량 설정 함수						
		DLLFunction	int	IMCT_ETH_GET_CONFIG_COMPARE_OUTPUT_SETTING_COUTER_POSITION(int nIndex, int nAxis, int &nValue); ///< 비교 출력 카운터 이송량 얻기 함수

		/** @brief  CONFIG - 편차 카운터 설정 [메모리 저장 됨] */
		DLLFunction int	IMCT_ETH_SET_CONFIG_DEVIATION_COUNTER_SETTING_USE_SEL(int nIndex, int nAxis, int nValue); ///< 편차 카운터 사용 유무 설정 함수					
		DLLFunction int	IMCT_ETH_GET_CONFIG_DEVIATION_COUNTER_SETTING_USE_SEL(int nIndex, int nAxis, int &nValue); ///< 편차 카운터 사용 유무 얻기 함수				
		DLLFunction int	IMCT_ETH_SET_CONFIG_DEVIATION_COUNTER_SETTING_STOP_TYPE(int nIndex, int nAxis, int nValue);	///< 편차 카운터 정지 방법 설정 함수			
		DLLFunction int	IMCT_ETH_GET_CONFIG_DEVIATION_COUNTER_SETTING_STOP_TYPE(int nIndex, int nAxis, int &nValue); ///< 편차 카운터 정지 방법 얻기 함수		
		DLLFunction int	IMCT_ETH_SET_CONFIG_DEVIATION_COUNTER_SETTING_COUNTER(int nIndex, int nAxis, int nValue); ///< 편차 카운터 설정 함수								
		DLLFunction int	IMCT_ETH_GET_CONFIG_DEVIATION_COUNTER_SETTING_COUNTER(int nIndex, int nAxis, int &nValue); ///< 편차 카운터 얻기 함수			

		/** @brief  CONFIG - 알람 발생시 정지 설정 [메모리 저장 됨] */
		DLLFunction int	IMCT_ETH_SET_CONFIG_ALARM_SETTING_USE_SEL(int nIndex, int nAxis, int nValue); ///< 알람 발생시 정지 방법 사용 유무 설정 함수							
		DLLFunction int	IMCT_ETH_GET_CONFIG_ALARM_SETTING_USE_SEL(int nIndex, int nAxis, int &nValue); ///< 알람 발생시 정지 방법 사용 유무 얻기 함수						
		DLLFunction int	IMCT_ETH_SET_CONFIG_ALARM_SETTING_STOP_TYPE(int nIndex, int nAxis, int nValue); ///< 알람 발생시 정지 방법 설정 함수									
		DLLFunction int	IMCT_ETH_GET_CONFIG_ALARM_SETTING_STOP_TYPE(int nIndex, int nAxis, int &nValue); ///< 알람 발생시 정지 방법 얻기 함수							

		/** @brief  CONFIG - BACKLISH 설정 [메모리 저장 됨] */
		DLLFunction int	IMCT_ETH_SET_CONFIG_BACKLISH_USE_SEL(int nIndex, int nAxis, int nValue); ///< BACKLISH 사용 유무 설정 함수										
		DLLFunction int	IMCT_ETH_GET_CONFIG_BACKLISH_USE_SEL(int nIndex, int nAxis, int &nValue); ///< BACKLISH 사용 유무 얻기 함수					
		DLLFunction int	IMCT_ETH_SET_CONFIG_BACKLISH_COUNTER_SEL(int nIndex, int nAxis, int nValue); ///< BACKLISH 카운터 설정 함수								
		DLLFunction int	IMCT_ETH_GET_CONFIG_BACKLISH_COUNTER_SEL(int nIndex, int nAxis, int &nValue); ///< BACKLISH 카운터 얻기 함수							
		DLLFunction int	IMCT_ETH_SET_CONFIG_BACKLISH_VELOCITY(int nIndex, int nAxis, int nValue); ///< BACKLISH 속도 설정 함수										
		DLLFunction int	IMCT_ETH_GET_CONFIG_BACKLISH_VELOCITY(int nIndex, int nAxis, int &nValue); ///< BACKLISH 속도 얻기 함수									
		DLLFunction int	IMCT_ETH_SET_CONFIG_BACKLISH_POSITION(int nIndex, int nAxis, int nValue); ///< BACKLISH 위치 설정 함수											
		DLLFunction int	IMCT_ETH_GET_CONFIG_BACKLISH_POSITION(int nIndex, int nAxis, int &nValue); ///< BACKLISH 위치 얻기 함수		

		// COMMON CONFIG- DIGITAL FILLTER [메모리 저장 됨] 
		DLLFunction	int	IMCT_ETH_SET_COMMON_CONFIG_DIGITAL_FILLTER(int nIndex, int nPort, int nPin, int nValue);
		DLLFunction	int	IMCT_ETH_GET_COMMON_CONFIG_DIGITAL_FILLTER(int nIndex, int nPort, int nPin, int &nValue);

		// COMMON CONFIG- DIGITAL FILLTER LOGIC LEVEL[메모리 저장 됨] 
		DLLFunction	int	IMCT_ETH_SET_COMMON_CONFIG_DIGITAL_FILLTER_LOGIC_LEVEL(int nIndex, int nPort, int nPin, int nValue); // 0:B 접점, 1: A 접점
		DLLFunction	int	IMCT_ETH_GET_COMMON_CONFIG_DIGITAL_FILLTER_LOGIC_LEVEL(int nIndex, int nPort, int nPin, int &nValue);// 0:B 접점, 1: A 접점	

		// COMMON - Emergency Stop & Clear [메모리 저장 안됨] 
		DLLFunction int	IMCT_ETH_SET_COMMON_EMERGENCY_STOP(int nIndex);  ///< EMERGENCY STOP 동작 함수
		DLLFunction int	IMCT_ETH_SET_COMMON_EMERGENCY_CLEAR(int nIndex); ///< EMERGENCY CLEAR 동작 함수	

		// MEMORY - I-Code, T-Code 그룹 정보 설정[메모리 저장 됨]
		DLLFunction	int	IMCT_ETH_SET_MEMORY_TYPE_SEL(int nIndex, int nValue);  ///< MEMORY TYPE 설정 함수							
		DLLFunction	int	IMCT_ETH_GET_MEMORY_TYPE_SEL(int nIndex, int &nValue); ///< MEMORY TYPE 얻기 함수			
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_COUNT_I_CODE(int nIndex, int nValue);	///< MEMORY I-CODE 총 그룹 갯수 설정 함수				
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_COUNT_I_CODE(int nIndex, int &nValue);	///< MEMORY I-CODE 총 그룹 갯수 얻기 함수		
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_COUNT_T_CODE(int nIndex, int nValue);	///< MEMORY T-CODE 총 그룹 갯수 설정 함수			
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_COUNT_T_CODE(int nIndex, int &nValue);	///< MEMORY T-CODE 총 그룹 갯수 얻기 함수			
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_SETTING_I_CODE(int nIndex, int nGroupNo, int GroupSize); ///< MEMORY I-CODE GROUP  설정 함수							
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_SETTING_I_CODE(int nIndex, int nGroupNo, int &nGroupSize); ///< MEMORY I-CODE GROUP  얻기 함수											
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_SETTING_T_CODE(int nIndex, int nGroupNo, int GroupSize, int nGroupType); ///< MEMORY T-CODE GROUP 설정 함수						
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_SETTING_T_CODE(int nIndex, int nGroupNo, int &GroupSize, int &nGroupType); ///< MEMORY T-CODE GROUP 얻기 함수										
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_SELECT_I_CODE(int nIndex, int nGroupNo); ///< MEMORY I-CODE GROUP 선택 설정 함수							
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_SELECT_I_CODE(int nIndex, int &nGroupNo);	///< MEMORY I-CODE GROUP 선택 얻기 함수									
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_SELECT_T_CODE(int nIndex, int nGroupNo); ///< MEMORY T-CODE GROUP 선택 설정 함수							
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_SELECT_T_CODE(int nIndex, int &nGroupNo);	///< MEMORY T-CODE GROUP 선택 얻기 함수		
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_NAME_I_CODE(int nIndex, int nGroupNo, char pName[18]); ///< MEMORY I-CODE GROUP 이름 설정 함수							
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_NAME_I_CODE(int nIndex, int nGroupNo, char pName[18]); ///< MEMORY I-CODE GROUP 이름 얻기 함수										
		DLLFunction	int	IMCT_ETH_SET_MEMORY_GROUP_NAME_T_CODE(int nIndex, int nGroupNo, char pName[18]); ///< MEMORY T-CODE GROUP 이름 설정 함수								
		DLLFunction	int	IMCT_ETH_GET_MEMORY_GROUP_NAME_T_CODE(int nIndex, int nGroupNo, char pName[18]); ///< MEMORY T-CODE GROUP 이름 얻기 함수		

		// PENDENT	- T-CODE 관련 [메모리 저장 됨]
		DLLFunction int	IMCT_ETH_SET_PENDENT_DATA_SEND_START(int nIndex);
		DLLFunction int	IMCT_ETH_SET_PENDENT_DATA(int nIndex, int nAxis[8], int nValue[8]);	///< T-Code 데이터 입력	설정 함수	
		DLLFunction int	IMCT_ETH_GET_PENDENT_DATA(int nIndex, int nAddress, int &nEndStatus, int nAxis[8], int nValue[8]);	///< T-Code 데이터 입력	얻기 함수
		DLLFunction int	IMCT_ETH_SET_PENDENT_PALLET_SETTING(int nIndex, int nAddress, int nValue[8]);	///< PALLET 환경 설정 함수							
		DLLFunction int	IMCT_ETH_GET_PENDENT_PALLET_SETTING(int nIndex, int nAddress, int nValue[8]);	///< PALLET 환경 얻기 함수 	
		DLLFunction int	IMCT_ETH_SET_PENDENT_DATA_SEND_END(int nIndex);	///< T-Code 데이터 전송 완료 설정	

		// I-CODE  - I-CODE 명령어 관련 [메모리 저장 됨]
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_BOARD_SELECT(int nIndex, int nValue);  ///< Board 선택 함수							
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_COORDINATE(int nIndex, int nValue); ///< 좌표계 설정 함수								
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_CONTROL_VELOCITY_SET(int nIndex, int nAxis[8], int nValue[8]);	///< 제어 속도 설정 함수
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_CONTROL_POSITION(int nIndex, int nAxis[8], int nValue[8]); ///< 위치 END CHECK 제어 함수	
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_CONTROL_POSITION_NO_END(int nIndex, int nAxis[8], int nValue[8]); ///< 위치 NO END CHECK 제어 함수	
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_CONTINUE_POSITIVE_VELOCITY(int nIndex, int nAxis[8], int nValue[8]); ///< 정방향 연속 운전	함수			
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_CONTINUE_NEGATIVE_VELOCITY(int nIndex, int nAxis[8], int nValue[8]); ///< 역방향 연속 운전	함수			
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_VELOCITY_SET(int nIndex, int nValue); ///< 보간 속도 설정 함수	
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_LINEAR(int nIndex, int nAxis[4], int nValue[4]); ///< 직선 보간 제어  함수				
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_CIRCULAR_CW(int nIndex, int nValue[4]); ///< 원호 보간 CW방향 제어	함수				
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_CIRCULAR_CCW(int nIndex, int nValue[4]); ///< 원호 보간 CCW방향 제어 함수				
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_HELICALL_CW(int nIndex, int nValue[5]);	///< Helical 보간 CW방향 제어 함수					
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_INTERPOLL_HELICALL_CCW(int nIndex, int nValue[5]); ///< Helical 보간 CCW방향 제어 함수							
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_NEXT_STEP_DELAY(int nIndex, int nValue); ///< NEXT STEP DELAY 설정 함수
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_NEXT_STEP_JMP(int nIndex, int nValue); ///< NEXT STEP JMP 설정	함수	
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_NEXT_STEP_IJMP(int nIndex, int nPort, int nPin, int nLevel, int nAddress); ///< NEXT STEP IJMP 설정 함수	 		
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_NEXT_STEP_CJMP(int nIndex, int nRegister, int nCountNo, int nCompareType, int nAddress); ///< NEXT STEP CJMP 설정 함수 		
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_LOOP_START(int nIndex, int nGroup, int nCount); ///< LOOP COUNT 설정 함수		
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_LOOP_END(int nIndex, int nGroup); ///< Loop End 설정 함수									
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_OUTPUT_BYTE(int nIndex, int nPort, int nValue[8]);	///< OUTPUT PORT BYTE 단위 설정 함수							
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_OUTPUT_BIT(int nIndex, int nPort, int nPin, int nLevel); ///< OUTPUT PORT BIT 단위 설정 함수										
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_COUNTER(int nIndex, int nRegister, int nAction, int nCountNo);	///< COUNTER 설정 함수											
		DLLFunction	int	IMCT_ETH_SET_I_CODE_DATA_TEACHING_MOVE(int nIndex, int nGroupNumber, int nAddress);
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_PALLET_INDEX(int nIndex, int nRegister, int nCountNo, int nValue[3]);	///< PALLET INDEX 설정 함수						
		DLLFunction	int	IMCT_ETH_SET_I_CODE_DATA_PALLET_MOVE(int nIndex, int nGroupNumber);

		//I-CODE  - I-CODE 전송 시작 및 전송 종료 [메모리 저장 안됨]
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_SEND_START(int nIndex); ///< I-Code Data 전송 시작 	함수									
		DLLFunction int	IMCT_ETH_SET_I_CODE_DATA_SEND_END(int nIndex); ///< I-Code 전송 종료 함수 		

		//I-CODE  - I-CODE 동작 관련 [메모리 저장 안됨]
		DLLFunction int	IMCT_ETH_SET_I_CODE_START(int nIndex); ///< I-Code 동작 시작 함수		
		DLLFunction int	IMCT_ETH_SET_I_CODE_STOP(int nIndex); ///< I-Code 동작 종료 함수
		DLLFunction int	IMCT_ETH_SET_I_CODE_PAUSE(int nIndex); ///< I-Code 동작 일시 정지 함수

		//I-CODE  - I-CODE 수신 관련
		DLLFunction int	IMCT_ETH_GET_COMMON_I_CODE_LINE(int nIndex, int &nValue); ///< I-CODE 수행중 LINE 확인	 함수
		DLLFunction int	IMCT_ETH_GET_COMMON_RECEIVE_I_CODE_DATA(int nIndex, int nAddress, int &nEnd, unsigned char buffer[64]);

		DLLFunction int	IMCT_ETH_GET_COMMON_MOTION_CHECK(int nIndex, int nAxis, int nValue, unsigned char buffer[64]);

		//-- 공통 응답
		DLLFunction int	IMCT_ETH_SET_COMMON_BOARD_SELECT(int nIndex, int nValue); // (A Board : 0, B Board : 1)	

		DLLFunction	int	IMCT_ETH_SET_COMMON_BOARD_IO_CHECK(int nIndex, int nValue); ///< Board I/O 설정 함수
		DLLFunction	int	IMCT_ETH_GET_COMMON_BOARD_IO_CHECK(int nIndex, int &nStatus, int &nValue); ///< Board I/O 상태 얻기 함수

		DLLFunction int	IMCT_ETH_GET_COMMON_RESPONSE_CHECK(int nIndex, int &nValue); ///< 데이터 송신 정상 여부 확인 함수	

		DLLFunction int	IMCT_ETH_SET_COMMON_ERROR_CLEAR(int nIndex); ///< Error List Clear 함수
		DLLFunction int	IMCT_ETH_GET_COMMON_ERROR_LIST(int nIndex, int nAddress, int &nAxis, int &nError); ///< ERROR 상태 확인 함수

		DLLFunction	int	IMCT_ETH_SET_COMMON_BOARD_INITIALIZE(int nIndex, int nValue);//< BOARD 상태 초기화 함수(0: CONFIG , 1: I-DATA)
		DLLFunction	int	IMCT_ETH_GET_COMMON_RESERVE_MOTION_CHECK(int nIndex, int &nReserve);	///< 예약 동작 확인 함수

		DLLFunction	int	IMCT_ETH_GET_COMMON_FIRMWARE_VERSION(int nIndex, char version[24]);	//< 펌웨어 버전 정보
		//-- INTERLOCK(2축)
		//-- INTERLOCK(4축, 8축용)
		DLLFunction int IMCT_ETH_GET_INTERLOCK_S_CURVE_ACC_TIME(int nAccTime, int nSCuveAccPercent, int nStartSpeed, int nRunSpeed, double dScale);
		DLLFunction int IMCT_ETH_GET_INTERLOCK_S_CURVE_DEC_TIME(int nDecTime, int nSCuveDecPercent, int nStartSpeed, int nRunSpeed, double dScale);

		//-- OVERRIDE 
		DLLFunction int	IMCT_ETH_SET_VELOCITY_OVERRIDE(int nIndex, int nAxis[8], int nValue[8]);
		DLLFunction int	IMCT_ETH_SET_POSITION_OVERRIDE(int nIndex, int nAxis[8], int nValue[8]);
	#ifdef __cplusplus
}
#endif

#endif // __IMCT_DLL_H__