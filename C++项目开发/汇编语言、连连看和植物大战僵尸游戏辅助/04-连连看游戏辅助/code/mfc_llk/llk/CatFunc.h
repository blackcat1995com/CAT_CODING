#include "pch.h"
#include "framework.h"
#include "llk.h"
#include "llkDlg.h"
#include "afxdialogex.h"
#include "Cat.h"
#include <algorithm>
#pragma comment(lib, "CAT.lib")

Cat * cat = BlackCat();


const LPCTSTR game_caption = TEXT("QQ游戏 - 连连看角色版");
const int COUNT_DOWN = 10000;
const int COUNT_DOWN_TIMER_ID = 1;

HWND game_hwnd;
RECT game_rect;
DWORD process_id;
HANDLE process_hwnd;
BYTE chess_data[11][19];
POINT p1, p2;

void init() {
	game_hwnd = cat->FindWindow(NULL, game_caption);
	cat->GetClientRect(game_hwnd, &game_rect);
	process_id = cat->GetWindowProcessId(game_hwnd);
	process_hwnd = cat->OpenProcess(process_id);
	cat->ReadProcessMemory(process_hwnd, (LPCVOID)0x00199F5C, (LPVOID)&chess_data, 11*19);
}

VOID CALLBACK countDownTimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	cat->WriteInt(process_hwnd, (LPVOID)0x00186AA8, COUNT_DOWN, 4);
}

// 点击两个棋子  每个棋子宽31像素  高35像素
// 第一个棋子 22,192,30,199,宽高(8,7)
void clickTwoPoints(POINT p1, POINT p2) {
	cat->GetClientRect(game_hwnd, &game_rect);
	cat->MoveTo(22 + game_rect.left + p1.y * 31, 192 + game_rect.top + p1.x * 35);
	cat->Delay(1);
	cat->LeftClick();
	cat->Delay(1);
	cat->MoveTo(22 + game_rect.left + p2.y * 31, 192 + game_rect.top + p2.x * 35);
	cat->Delay(1);
	cat->LeftClick();
}

// 判断两个点是否在同一条水平线上连通
BOOL isHorizantal(POINT p1, POINT p2) {
	int y1 = min(p1.y, p2.y);
	int y2 = max(p1.y, p2.y);
	if (p1.x == p2.x) {
		for (int y = y1 + 1; y <= y2 - 1; y++) {
			if (chess_data[p1.x][y] != 0) {
				return FALSE;
			}
		}
	}
	else
		return FALSE;

	return TRUE;
}

// 判断两个点是否在同一条竖直线上连通
BOOL isVertical(POINT p1, POINT p2) {
	int x1 = min(p1.x, p2.x);
	int x2 = max(p1.x, p2.x);
	if (p1.y == p2.y) {
		for (int x = x1 + 1; x <= x2 - 1; x++) {
			if (chess_data[x][p1.y] != 0) {
				return FALSE;
			}
		}
	}
	else
		return FALSE;

	return TRUE;
}

// 检测两个点是否是拐角点连通
BOOL isTurnOnce(POINT p1, POINT p2) {
	if (p1.x != p2.x&&p1.y != p2.y) {
		POINT p3, p4;
		p3.x = p2.x;
		p3.y = p1.y;
		p4.x = p1.x;
		p4.y = p2.y;
		if (chess_data[p3.x][p3.y] == 0) {
			if ((isVertical(p1, p3)) && (isHorizantal(p2, p3)))
				return TRUE;
		}

		if (chess_data[p4.x][p4.y] == 0) {
			if ((isVertical(p2, p4)) && (isHorizantal(p1, p4)))
				return TRUE;
		}

		return FALSE;
	}
	else
		return FALSE;
}

// 检测两个点是否是两个拐角点连通
BOOL isTurnTwice(POINT p1, POINT p2) {
	POINT p;
	// 穿过p1的竖直线
	for (int x = 0; x < 11; x++) {
		p.x = x;
		p.y = p1.y;
		if (isVertical(p, p1) && isTurnOnce(p, p2) && chess_data[p.x][p.y] == 0)
			return TRUE;
	}

	// 穿过p1的水平线
	for (int y = 0; y < 19; y++) {
		p.x = p1.x;
		p.y = y;
		if (isHorizantal(p, p1) && isTurnOnce(p, p2) && chess_data[p.x][p.y] == 0)
			return TRUE;
	}

	// 穿过p2的竖直线
	for (int x = 0; x < 11; x++) {
		p.x = x;
		p.y = p2.y;
		if (isVertical(p, p2) && isTurnOnce(p, p1) && chess_data[p.x][p.y] == 0)
			return TRUE;
	}

	// 穿过p2的水平线
	for (int y = 0; y < 19; y++) {
		p.x = p2.x;
		p.y = y;
		if (isHorizantal(p, p2) && isTurnOnce(p, p1) && chess_data[p.x][p.y] == 0)
			return TRUE;
	}

	return FALSE;
}

// 检测两个相同的棋子是否可以消除
BOOL checkTeoPointsIsClear(POINT p1, POINT p2) {

	// 判断两个点是否在同一条水平线上连通
	if (isHorizantal(p1, p2))
		return TRUE;
	// 判断两个点是否在同一条竖直线上连通
	if (isVertical(p1, p2))
		return TRUE;
	// 检测两个点是否是拐角点连通
	if (isTurnOnce(p1, p2))
		return TRUE;
	// 检测两个点是否是两个拐角点连通
	if (isTurnTwice(p1, p2))
		return TRUE;
	return FALSE;
}