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
	case WM_CREATE: {
		LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
		HWND hEdit = CreateWindowA("edit", "����һ���༭��", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | WS_VSCROLL | WS_THICKFRAME,
			30, 30, 200, 100, hwnd, (HMENU)3001, pcs->hInstance, NULL);

	}break;

	case WM_COMMAND: {
		WORD id = LOWORD(wParam);
		WORD code = HIWORD(wParam);
		HWND hCtrl = (HWND)lParam;

		if (id == 3001 && code == EN_CHANGE) {
			TCHAR buf[64];
			GetWindowTextA(hCtrl, buf, sizeof buf);
			MessageBoxA(NULL, buf, "cat", MB_OK);
		}
	}break;

	case WM_CTLCOLOREDIT: {
		HDC hdc = (HDC)wParam;
		HWND hCtrl = (HWND)lParam;

		UINT CtrlID = GetWindowLongA(hCtrl, GWL_ID);

		if (CtrlID == 3001) {
			SetTextColor(hdc, RGB(255, 0, 0));
			SetBkMode(hdc, TRANSPARENT);
		}

		return (LRESULT)CreateSolidBrush(RGB(80, 80, 80));
	}
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