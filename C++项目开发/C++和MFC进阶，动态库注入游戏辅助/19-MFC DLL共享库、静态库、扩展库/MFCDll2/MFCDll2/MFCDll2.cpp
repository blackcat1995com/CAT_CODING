// MFCDll2.cpp: 定义 DLL 的初始化例程。
//

#include "pch.h"
#include "framework.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern "C" CString GetString() {
	return CString("noi.hioier.com");
}
