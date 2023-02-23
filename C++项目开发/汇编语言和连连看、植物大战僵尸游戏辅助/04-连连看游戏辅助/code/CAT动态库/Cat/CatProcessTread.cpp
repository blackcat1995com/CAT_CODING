#include "pch.h"
#include "framework.h"
#include "Cat.h"


DWORD MyCat::GetWindowProcessId(HWND hWnd) {
	DWORD process_id;
	DWORD thread_id;
	thread_id = ::GetWindowThreadProcessId(hWnd, &process_id);
	return process_id;
}

HANDLE MyCat::OpenProcess(DWORD dwProcessId) {
	HANDLE process_hwnd = ::OpenProcess(PROCESS_ALL_ACCESS, NULL, dwProcessId);
	return process_hwnd;
}

// 创建线程 
HANDLE MyCat::CreateThread(LPTHREAD_START_ROUTINE  lpStartAddress) {
	HANDLE thread_hwnd = ::CreateThread(NULL, NULL, lpStartAddress, NULL, NULL, NULL);
	return thread_hwnd;
}

