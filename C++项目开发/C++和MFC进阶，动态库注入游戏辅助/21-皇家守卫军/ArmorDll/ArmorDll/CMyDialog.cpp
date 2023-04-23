// CMyDialog.cpp: 实现文件
//

#include "pch.h"
#include "ArmorDll.h"
#include "afxdialogex.h"
#include "CMyDialog.h"
#include <TlHelp32.h>

// 全局变量
HWND g_hwnd; // 窗口句柄
DWORD g_pid; // 进程号
HANDLE g_process_handle; // 进程句柄
CString g_title = _T("皇家守卫军-边境");

DWORD g_dw_base_addr;

// 从指定内存读取数据
void ReadMemory(HANDLE hProcess, void* value, DWORD valueSize, ...) {
	if (!value || !valueSize || !hProcess) return;

	DWORD tempValue = 0;
	va_list addresses;

	va_start(addresses, valueSize);

	DWORD offset = 0;
	DWORD lastAddress = 0;
	// g_dw_base_addr, 0x14, 0x308, 0x8C, 0x58, 0x124, -1
	while (~(offset = va_arg(addresses, DWORD))) {
		lastAddress = tempValue + offset;
		::ReadProcessMemory(hProcess, (LPCVOID)lastAddress, &tempValue, sizeof(DWORD), NULL);
	}
	va_end(addresses);

	::ReadProcessMemory(hProcess, (LPCVOID)lastAddress, value, valueSize, NULL);
}

// 向指定内存写入数据
void WriteMemory(HANDLE hProcess, void* value, DWORD valueSize, ...) {
	if (!value || !valueSize || !hProcess) return;

	DWORD tempValue = 0;
	va_list addresses;

	va_start(addresses, valueSize);

	DWORD offset = 0;
	DWORD lastAddress = 0;
	// g_dw_base_addr, 0x14, 0x308, 0x8C, 0x58, 0x124, -1
	while (~(offset = va_arg(addresses, DWORD))) {
		lastAddress = tempValue + offset;
		::ReadProcessMemory(hProcess, (LPCVOID)lastAddress, &tempValue, sizeof(DWORD), NULL);
	}
	va_end(addresses);

	::WriteProcessMemory(hProcess, (LPVOID)lastAddress, value, valueSize, NULL);
}


void WriteMemory(HANDLE hProcess, void* value, DWORD valueSize, DWORD address) {
	WriteMemory(hProcess, value, valueSize, address, -1);
}
// ------------------------------------------------------------

// CMyDialog 对话框

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN_DLG, pParent)
	, m_editv_show_wnd_title(_T(""))
	, m_editv_show_process_handle(_T(""))
	, m_editv_show_read_coin(_T(""))
	, m_editv_change_coin(_T(""))
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SHOW_WND_TITLE, m_editv_show_wnd_title);
	DDX_Text(pDX, IDC_EDIT_SHOW_PROCESS_HANDLE, m_editv_show_process_handle);
	DDX_Text(pDX, IDC_EDIT_SHOW_READ_COIN, m_editv_show_read_coin);
	DDX_Text(pDX, IDC_EDIT_SHOW_CHANGE_COIN, m_editv_change_coin);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_GET_WND_TITLE, &CMyDialog::OnBnClickedBtnGetWndTitle)
	ON_BN_CLICKED(IDC_BTN_GET_PROCESS_HANDLE, &CMyDialog::OnBnClickedBtnGetProcessHandle)
	ON_BN_CLICKED(IDC_BTN_MAX_WND, &CMyDialog::OnBnClickedBtnMaxWnd)
	ON_BN_CLICKED(IDC_BTN_MIN_WND, &CMyDialog::OnBnClickedBtnMinWnd)
	ON_BN_CLICKED(IDC_BTN_START_GAME, &CMyDialog::OnBnClickedBtnStartGame)
	ON_BN_CLICKED(IDC_BTN_READ_COIN, &CMyDialog::OnBnClickedBtnReadCoin)
	ON_BN_CLICKED(IDC_BTN_CHANGE_COIN, &CMyDialog::OnBnClickedBtnChangeCoin)
END_MESSAGE_MAP()


// ----------------------------------------
// 重写初始化方法
BOOL CMyDialog::OnInitDialog() {

	// 加载图标
	HICON icon = AfxGetApp()->LoadIconW(IDI_ICON);
	SetIcon(icon, TRUE);
	SetIcon(icon, FALSE);

	g_hwnd = ::FindWindow(NULL, g_title);
	if (!g_hwnd) {
		MessageBox(_T("获取游戏窗口句柄失败！"), NULL, MB_OK);
		return FALSE;
	}

	//MessageBox(_T("获取游戏窗口句柄成功！"), NULL, MB_OK);
	::GetWindowThreadProcessId(g_hwnd, &g_pid);
	g_process_handle = ::OpenProcess(PROCESS_ALL_ACCESS, NULL, g_pid);

	if (!g_process_handle) {
		MessageBox(_T("获取游戏进程句柄失败！"), NULL, MB_OK);
		return FALSE;
	}

	return TRUE;
}

__declspec(dllexport) void ShowDialog() {
	CMyDialog dlg;
	dlg.DoModal();
}


void CMyDialog::OnBnClickedBtnGetWndTitle()
{
	m_editv_show_wnd_title = g_title;
	UpdateData(FALSE);
}


void CMyDialog::OnBnClickedBtnGetProcessHandle()
{
	CString str;
	str.Format(_T("%x"), g_process_handle);
	m_editv_show_process_handle = str;
	UpdateData(FALSE);
}


void CMyDialog::OnBnClickedBtnMaxWnd()
{
	::SendMessage(g_hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
}


void CMyDialog::OnBnClickedBtnMinWnd()
{
	::SendMessage(g_hwnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}

void CMyDialog::OnBnClickedBtnStartGame()
{
	int x = 400, y = 500;
	LPARAM lParam = MAKEWPARAM(x, y);
	::SendMessage(g_hwnd, WM_LBUTTONDOWN, 0, lParam);
	::SendMessage(g_hwnd, WM_LBUTTONUP, 0, lParam);
}


void CMyDialog::OnBnClickedBtnReadCoin()
{
	
	HANDLE hSnapMoudleShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, g_pid);

	MODULEENTRY32 me32 = { 0 };

	if (hSnapMoudleShot == INVALID_HANDLE_VALUE) {
		MessageBox(_T("创建模块快照失败！"), NULL, MB_OK);
		return;
	}

	me32.dwSize = sizeof MODULEENTRY32;

	if (!Module32First(hSnapMoudleShot, &me32)) {
		MessageBox(_T("列举第一个模块失败！"), NULL, MB_OK);
		CloseHandle(hSnapMoudleShot);
		return;
	}

	CString str_base_addr;
	str_base_addr.Format(_T("%x"), me32.modBaseAddr);

	
	const CHAR* tmp_p;
	CHAR tmp_chs[300];
	::wsprintfA(tmp_chs, "%ls", (LPCTSTR)str_base_addr);
	tmp_p = tmp_chs;
	g_dw_base_addr = strtol(tmp_p, NULL, 16);

	CString str_add_addr = _T("00733A80");  // 00733A80
	DWORD dw_add_addr;
	::wsprintfA(tmp_chs, "%ls", (LPCTSTR)str_add_addr);
	tmp_p = tmp_chs;
	dw_add_addr = strtol(tmp_p, NULL, 16);

	g_dw_base_addr += dw_add_addr;

	
	/*DWORD tmp_value;
	ReadProcessMemory(g_process_handle, (LPCVOID)g_dw_base_addr, &tmp_value, sizeof tmp_value, NULL);
	CString str;
	str.Format(_T("%x"), tmp_value);

	MessageBox(str, NULL, MB_OK);*/

	// "Armor.exe"+00733A80  
	// 偏移：14  308  8C  58  124
	DWORD coin = 0;
	ReadMemory(g_process_handle, &coin, sizeof(coin), g_dw_base_addr, 0x14, 0x308, 0x8C, 0x58, 0x124, -1);

	CString str;
	str.Format(_T("%d"), coin);
	m_editv_show_read_coin = str;
	UpdateData(FALSE);
}


void CMyDialog::OnBnClickedBtnChangeCoin()
{
	UpdateData(TRUE);
	DWORD coin = _wtoi(m_editv_change_coin);
	WriteMemory(g_process_handle, &coin, sizeof(coin), g_dw_base_addr, 0x14, 0x308, 0x8C, 0x58, 0x124, -1);
}
