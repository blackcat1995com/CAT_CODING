#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <cstdio>

// �Զ��崰�ڹ��̻ص�����
LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	
	static int cnt1 = 0, cnt2 = 0;
	char str[64];

	switch (Msg) {

	case WM_NCCREATE:
		SetWindowTextA(hwnd, TEXT("blackcat1995.com"));
		sprintf(str, "WM_NCCREATE��Ϣ\n");
		OutputDebugStringA(str);
		return TRUE;

	case WM_CREATE:
		sprintf(str, "WM_CREATE��Ϣ\n");
		OutputDebugStringA(str);
		return TRUE;

	case WM_CLOSE:
		sprintf(str, "WM_CLOSE��Ϣ\n");
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

		sprintf(str, "��%d�β���WM_ERASEBKGND\n", ++cnt2);
		OutputDebugStringA(str);
		return TRUE;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		sprintf(str, "��%d�β���WM_PAINT\n", ++cnt1);
		OutputDebugStringA(str);
		EndPaint(hwnd, &ps);
		return 0;
	}

	case WM_LBUTTONDOWN:
		//sprintf(str, "���������£�%d %d\n", LOWORD(lParam), HIWORD(lParam));
		sprintf(str, "���������£�%d %d\n", lParam & 0xffff, lParam >> 16 & 0xffff);
		OutputDebugStringA(str);
		break;
	case WM_KEYDOWN:
		sprintf(str, "�������£�%X  %c\n", wParam, wParam);
		OutputDebugStringA(str);
		break;
	case WM_SYSKEYDOWN:
		sprintf(str, "ϵͳ�������£�%X  %c\n", wParam, wParam);
		OutputDebugStringA(str);
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
	wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
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
	while (GetMessageA(&msg, hwnd, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

	return 0;
}