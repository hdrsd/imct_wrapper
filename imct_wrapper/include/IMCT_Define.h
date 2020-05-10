#pragma once

enum
{
	ERROR_FAILED_FUNCTION		  = -1,
	ERROR_SUCCESS_FUNCTION		  = 1,	
	ERROR_ACCESS_DENIED_FUNCTION  = 2, // The specified COM-port is in use
	ERROR_FILE_NOT_FOUND_FUNCTION = 3, // The specified COM-port does not exist
};

enum 
{ 
	X_AXIS = 1,	
	Y_AXIS = 2,	
	Z_AXIS = 3, 
	U_AXIS = 4,	
	A_AXIS = 5, 
	B_AXIS = 6,
	C_AXIS = 7, 
	D_AXIS = 8,	
};

//I-CODE �Լ��� ��� �Ҷ�, ���� �ޱ� ���� ��ɾ� 
#define		CMD_I_CODE_DATA_BOARD_SELECT						0x61  //* ���� ����
#define		CMD_I_CODE_DATA_COORDINATE							0xc0  //* ��ǥ�� ����
#define		CMD_I_CODE_DATA_CONTROL_VELOCITY_SET				0xc1  //* �ӵ� ����(��ġ����)
#define		CMD_I_CODE_DATA_CONTROL_POSITION					0xc2  //* ��ġ ���� 
#define		CMD_I_CODE_DATA_CONTROL_POSITION_NO_END				0xc7  //* ��ġ ���� NO END
#define		CMD_I_CODE_DATA_CONTINUE_POSITIVE_VELOCITY			0xc3  //* ������ �ӵ����� 
#define		CMD_I_CODE_DATA_CONTINUE_NEGATIVE_VELOCITY			0xc4  //* ������ �ӵ����� 
#define		CMD_I_CODE_DATA_INTERPOLL_VELOCITY_SET				0xc5  //* �ӵ� ����(��������)
#define		CMD_I_CODE_DATA_INTERPOLL_LINEAR					0xc6  //* �������� 
#define		CMD_I_CODE_DATA_INTERPOLL_CIRCULAR_CW				0xc8  //* ��ȣ ���� CW
#define		CMD_I_CODE_DATA_INTERPOLL_CIRCULAR_CCW				0xca  //* ��ȣ ���� CCW
#define		CMD_I_CODE_DATA_INTERPOLL_HELICALL_CW				0xcc  //* Helical ���� CW
#define		CMD_I_CODE_DATA_INTERPOLL_HELICALL_CCW				0xce  //* Helical ���� CCW
#define		CMD_I_CODE_DATA_STOP								0x9f  //* STOP
#define		CMD_I_CODE_DATA_HOME								0x9e  //* HOME
#define		CMD_I_CODE_DATA_ENCODER_CLEAR						0xa1  //* ENCODER CLEAR
#define		CMD_I_CODE_DATA_NEXT_STEP_DELAY						0xd0  //* Next Step
#define		CMD_I_CODE_DATA_NEXT_STEP_JMP						0xd1  //* Next Step
#define		CMD_I_CODE_DATA_NEXT_STEP_IJMP						0xd2  //* Next Step
#define		CMD_I_CODE_DATA_NEXT_STEP_CJMP						0xd3  //* Next Step
#define		CMD_I_CODE_DATA_LOOP_START							0xd4  //* Loop
#define		CMD_I_CODE_DATA_LOOP_END							0xdb  //* Loop End
#define		CMD_I_CODE_DATA_OUTPUT_BYTE							0xd5  //* OutPut Port ���� 
#define		CMD_I_CODE_DATA_OUTPUT_BIT							0xd6  //* OutPut Port ����
#define		CMD_I_CODE_DATA_COUNTER								0xd7  //* COUNTER	
#define		CMD_I_CODE_DATA_TEACHING_MOVE						0xd8  //* TEACHING MOVE
#define		CMD_I_CODE_DATA_PALLET_INDEX						0xd9  //* PALLET INDEX
#define		CMD_I_CODE_DATA_PALLET_MOVE							0xda  //* PALLET MOVE

//I-CODE  - I-CODE ���� ���� �� ���� ����
#define		CMD_I_CODE_DATA_SEND_START							0xdc  //* I-Code ���� ���� 
#define		CMD_I_CODE_DATA_SEND_END							0xdd  //* I-Code ���� END
