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

		HWND hComboBox = CreateWindowA("combobox", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_AUTOHSCROLL | WS_VSCROLL | CBS_SORT,
			30, 30, 200, 60, hwnd, (HMENU)4001, pcs->hInstance, NULL);
		SendMessageA(hComboBox, CB_ADDSTRING, 0, (LPARAM)"C����");
		SendMessageA(hComboBox, CB_ADDSTRING, 0, (LPARAM)"A��ѧ");
		SendMessageA(hComboBox, CB_ADDSTRING, 0, (LPARAM)"BӢ��");
		SendMessageA(hComboBox, CB_ADDSTRING, 0, (LPARAM)"E����");

		SendMessageA(hComboBox, CB_INSERTSTRING, 1, (LPARAM)"D��Ϣѧ");

		SendMessageA(hComboBox, CB_SETCURSEL, 3, 0);

		HWND hListBox = CreateWindowA("listbox", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_AUTOHSCROLL | WS_VSCROLL | CBS_SORT | LBS_NOTIFY,
			30, 150, 200, 60, hwnd, (HMENU)5001, pcs->hInstance, NULL);

		SendMessageA(hListBox, LB_ADDSTRING, 0, (LPARAM)"C����");
		SendMessageA(hListBox, LB_ADDSTRING, 0, (LPARAM)"A��ѧ");
		SendMessageA(hListBox, LB_ADDSTRING, 0, (LPARAM)"BӢ��");
		SendMessageA(hListBox, LB_ADDSTRING, 0, (LPARAM)"E����");

		SendMessageA(hListBox, LB_INSERTSTRING, 1, (LPARAM)"D��Ϣѧ");

		SendMessageA(hListBox, LB_SETCURSEL, 3, 0);

	}break;

	case WM_COMMAND: {
		WORD id = LOWORD(wParam);
		WORD code = HIWORD(wParam);
		HWND hCtrl = (HWND)lParam;

		if (id == 5001 && code == LBN_SELCHANGE) {
			int idx = SendMessageA(hCtrl, LB_GETCURSEL, 0, 0);
			TCHAR buf[64];
			SendMessageA(hCtrl, LB_GETTEXT, idx, (LPARAM)buf);
			MessageBoxA(hwnd, buf, "cat", MB_OK);
		}
	}break;

	case WM_CTLCOLORLISTBOX: {
		HDC hdc = (HDC)wParam;
		HWND hCtrl = (HWND)lParam;

		UINT CtrlID = GetWindowLongA(hCtrl, GWL_ID);

		if (CtrlID == 5001) {
			SetTextColor(hdc, RGB(0, 255, 255));
			SetBkMode(hdc, TRANSPARENT);
			return (LRESULT)CreateSolidBrush(RGB(10, 10, 10));
		}

	}break;
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