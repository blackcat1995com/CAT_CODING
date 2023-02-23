#include "pch.h"
#include "framework.h"
#include "Cat.h"

LL MyCat::ReadInt(HANDLE hProcess, int lpBaseAddress, int nBytes) {

	BOOL ret;

	if (nBytes == 1) {
		char num;
		ret = ::ReadProcessMemory(hProcess, (LPCVOID)lpBaseAddress, (LPVOID)&num, nBytes, NULL);
		if (ret)
			return num;
		else
			return 0;
	}
	else if (nBytes == 4) {
		int num;
		ret = ::ReadProcessMemory(hProcess, (LPCVOID)lpBaseAddress, (LPVOID)&num, nBytes, NULL);
		if (ret)
			return num;
		else
			return 0;
	}
	else if (nBytes == 8) {
		long long num;
		ret = ::ReadProcessMemory(hProcess, (LPCVOID)lpBaseAddress, (LPVOID)&num, nBytes, NULL);
		if (ret)
			return num;
		else
			return 0;
	}

	return 0;

}

BOOL MyCat::WriteInt(HANDLE hProcess, int lpBaseAddress, int lpBuffer, int nBytes) {

	if (nBytes == 1) {
		BOOL ret = ::WriteProcessMemory(hProcess, (LPVOID)lpBaseAddress, (LPCVOID)lpBuffer, nBytes, NULL);
		return ret;
	}
	else if (nBytes == 4) {
		BOOL ret = ::WriteProcessMemory(hProcess, (LPVOID)lpBaseAddress, (LPCVOID)lpBuffer, nBytes, NULL);
		return ret;
	}
	else if (nBytes == 8) {
		BOOL ret = ::WriteProcessMemory(hProcess, (LPVOID)lpBaseAddress, (LPCVOID)lpBuffer, nBytes, NULL);
		return ret;
	}
	return 0;
}


// 读取指定内存数据
BOOL MyCat::ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize) {
	int ret = ::ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, NULL);
	return ret;
}

// 向指定内存写入数据
void MyCat::WriteMemory(HANDLE hProcess, void* value, DWORD valueSize, ...) {
	if (value == NULL || valueSize == 0 || hProcess == NULL) return;

	DWORD tempValue = 0;

	va_list addresses;
	va_start(addresses, valueSize);
	DWORD offset = 0;
	DWORD lastAddress = 0;
	while ((offset = va_arg(addresses, DWORD)) != -1) {
		lastAddress = tempValue + offset;
		::ReadProcessMemory(hProcess, (LPCVOID)lastAddress, &tempValue, sizeof(DWORD), NULL);
	}
	va_end(addresses);

	::WriteProcessMemory(hProcess, (LPVOID)lastAddress, value, valueSize, NULL);
}

void MyCat::WriteMemory(HANDLE hProcess, void* value, DWORD valueSize, DWORD address) {
	MyCat::WriteMemory(hProcess, value, valueSize, address, -1);
}

