#pragma once

#include "include/IMC_TCP.h"
#include "include/IMCT_Define.h"
#include "include/IMCT_DLL.h"

using namespace System;

namespace imctwrapper {
	public ref class imctWrapper
	{
	public:
		imctWrapper();
		virtual ~imctWrapper();
	private:
		
	public:
		/** @brief  COMMUNICATION 설정*/
		int IMCT_ETH_INITIALIZE(int& nIndex, char* address, int port);
		int	IMCT_ETH_UNINITIALIZE(int nIndex);

	};
}
