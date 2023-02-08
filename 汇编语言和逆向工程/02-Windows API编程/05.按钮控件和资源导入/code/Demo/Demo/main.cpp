#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <cstdio>
#include "resource.h"

// 自定义窗口过程回调函数
LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	
	switch (Msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CREATE: {
		LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
		/*HWND hBtn1 = CreateWindowA(TEXT("button"), TEXT("按钮"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			30, 30, 217, 46, hwnd, (HMENU)1001, pcs->hInstance, NULL);*/
		HWND hBtn1 = CreateWindowA(TEXT("button"), NULL, WS_CHILD | WS_VISIBLE | BS_BITMAP,
			30, 30, 217, 46, hwnd, (HMENU)1001, pcs->hInstance, NULL);

		HBITMAP hBmp1 = LoadBitmap(pcs->hInstance, MAKEINTRESOURCE(IDB_Btn1));
		LRESULT ret = SendMessageA(hBtn1, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp1);

		HWND hBtn2 = CreateWindowA(TEXT("button"), TEXT("按钮"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			30, 80, 217, 46, hwnd, (HMENU)1011, pcs->hInstance, NULL);
		HWND hBtn3 = CreateWindowA(TEXT("button"), TEXT("按钮"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			30, 130, 217, 46, hwnd, (HMENU)1012, pcs->hInstance, NULL);

		HWND hBtn4 = CreateWindowA(TEXT("button"), TEXT("按钮"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
			30, 200, 217, 46, hwnd, (HMENU)1021, pcs->hInstance, NULL);
		HWND hBtn5 = CreateWindowA(TEXT("button"), TEXT("按钮"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
			30, 250, 217, 46, hwnd, (HMENU)1022, pcs->hInstance, NULL);

	}
	case WM_COMMAND: {
		WORD id = LOWORD(wParam);
		WORD code = HIWORD(wParam);
		HWND hCtr1 = (HWND)lParam;
		if (id == 1001 && code == BN_CLICKED)
			MessageBoxA(NULL, TEXT("普通按钮被单击"), TEXT("cat"), MB_OK);
		else if (id == 1021 && code == BN_CLICKED) {
			MessageBoxA(NULL, TEXT("多选按钮被单击"), TEXT("cat"), MB_OK);
			if (SendMessageA(hCtr1, BM_GETCHECK, 0, 0) == BST_CHECKED)
				MessageBoxA(NULL, TEXT("第一个多选按钮被选中"), TEXT("cat"), MB_OK);
			else if(SendMessageA(hCtr1, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
				MessageBoxA(NULL, TEXT("第一个多选按钮未被选中"), TEXT("cat"), MB_OK);
		}
	}
	}

	return DefWindowProcA(hwnd, Msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	// 注册窗口类
	WNDCLASS wnd;

	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;

	wnd.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_CAT));
	wnd.lpfnWndProc = MyWindowProc;
	wnd.lpszClassName = TEXT("blackcat");
	wnd.lpszMenuName = NULL;
	wnd.style = CS_HREDRAW;
	wnd.hInstance = hInstance;

	RegisterClassA(&wnd);

	// 创建窗口 返回之前发送 WM_CREATE
	HWND hwnd = CreateWindowA(
		TEXT("blackcat"),
		TEXT("黑猫编程"),
		WS_OVERLAPPEDWINDOW,
		100, 100, 300, 340, NULL, NULL, hInstance, NULL
	);

	// 显示窗口
	ShowWindow(hwnd, nShowCmd);

	// 更新窗口
	UpdateWindow(hwnd);

	// 消息循环 收到 WM_QUIT 退出
	MSG msg;
	while (GetMessageA(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

	return 0;
}