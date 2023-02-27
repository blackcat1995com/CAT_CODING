#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <cstdio>

// 自定义窗口过程回调函数
LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	
	static int cnt1 = 0, cnt2 = 0;
	char str[64];

	switch (Msg) {

	case WM_NCCREATE:
		SetWindowTextA(hwnd, TEXT("blackcat1995.com"));
		sprintf(str, "WM_NCCREATE消息\n");
		OutputDebugStringA(str);
		return TRUE;

	case WM_CREATE:
		sprintf(str, "WM_CREATE消息\n");
		OutputDebugStringA(str);
		return TRUE;

	case WM_CLOSE:
		sprintf(str, "WM_CLOSE消息\n");
		OutputDebugStringA(str);
		DestroyWindow(hwnd);
		return 0;

	case WM_DESTROY:
		sprintf(str, "WM_DESTROY\n");
		OutputDebugStringA(str);
		PostQuitMessage(0);
		return 0;

	case WM_NCDESTROY:
		sprintf(str, "WM_NCDESTROY\n");
		OutputDebugStringA(str);
		return 0;

	case WM_ERASEBKGND:

		sprintf(str, "第%d次产生WM_ERASEBKGND\n", ++cnt2);
		OutputDebugStringA(str);
		return TRUE;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		sprintf(str, "第%d次产生WM_PAINT\n", ++cnt1);
		OutputDebugStringA(str);
		EndPaint(hwnd, &ps);
		return 0;
	}

	case WM_LBUTTONDOWN:
		//sprintf(str, "鼠标左键按下：%d %d\n", LOWORD(lParam), HIWORD(lParam));
		sprintf(str, "鼠标左键按下：%d %d\n", lParam & 0xffff, lParam >> 16 & 0xffff);
		OutputDebugStringA(str);
		break;
	case WM_KEYDOWN:
		sprintf(str, "按键按下：%X  %c\n", wParam, wParam);
		OutputDebugStringA(str);
		break;
	case WM_SYSKEYDOWN:
		sprintf(str, "系统按键按下：%X  %c\n", wParam, wParam);
		OutputDebugStringA(str);
		break;
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
	wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
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
		100, 100, 300, 300, NULL, NULL, hInstance, NULL
	);

	// 显示窗口
	ShowWindow(hwnd, nShowCmd);

	// 更新窗口
	UpdateWindow(hwnd);

	// 消息循环 收到 WM_QUIT 退出
	MSG msg;
	while (GetMessageA(&msg, hwnd, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

	return 0;
}