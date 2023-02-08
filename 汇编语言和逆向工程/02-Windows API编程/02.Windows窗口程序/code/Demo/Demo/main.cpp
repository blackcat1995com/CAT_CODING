#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <cstdio>
#include <windowsx.h>
#include "resource.h"

// �Զ��崰�ڹ��̻ص�����
LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	
	switch (Msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProcA(hwnd, Msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	// ע�ᴰ����
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

	// �������� ����֮ǰ���� WM_CREATE
	HWND hwnd = CreateWindowA(
		TEXT("blackcat"),
		TEXT("��è���"),
		WS_OVERLAPPEDWINDOW,
		100, 100, 300, 300, NULL, NULL, hInstance, NULL
	);

	// ��ʾ����
	ShowWindow(hwnd, nShowCmd);

	// ���´���
	UpdateWindow(hwnd);

	// ��Ϣѭ�� �յ� WM_QUIT �˳�
	MSG msg;
	while (GetMessageA(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

	return 0;
}