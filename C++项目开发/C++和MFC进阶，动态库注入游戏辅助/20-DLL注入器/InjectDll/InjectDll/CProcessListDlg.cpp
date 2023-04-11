// CProcessListDlg.cpp: 实现文件
//

#include "pch.h"
#include "InjectDll.h"
#include "afxdialogex.h"
#include "CProcessListDlg.h"

#include <tlhelp32.h>	// 快照头文件
#include "InjectDllDlg.h"
// CProcessListDlg 对话框

IMPLEMENT_DYNAMIC(CProcessListDlg, CDialogEx)

CProcessListDlg::CProcessListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_PROCESS_LIST, pParent)
{

}

CProcessListDlg::~CProcessListDlg()
{
}

void CProcessListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SHOW_PROCESS, m_list_ctrl_show_process);
}


BEGIN_MESSAGE_MAP(CProcessListDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_GET_PROCESS_LIST, &CProcessListDlg::OnBnClickedBtnGetProcessList)
	ON_BN_CLICKED(IDC_BTN_GET_WND_PROCESS_LIST, &CProcessListDlg::OnBnClickedBtnGetWndProcessList)
	ON_BN_CLICKED(IDC_BTN_CHOOSE_A_PROCESS, &CProcessListDlg::OnBnClickedBtnChooseAProcess)
	ON_BN_CLICKED(IDC_BTN_CLOSE_PROCESS_LIST_DLG, &CProcessListDlg::OnBnClickedBtnCloseProcessListDlg)
END_MESSAGE_MAP()


// ----------------------------------------

BOOL CProcessListDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	m_list_ctrl_show_process.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_SINGLEROW | LVS_EX_GRIDLINES);

	m_list_ctrl_show_process.InsertColumn(0, _T("序号"), LVCFMT_LEFT, 100);
	m_list_ctrl_show_process.InsertColumn(1, _T("名称"), LVCFMT_LEFT, 260);
	m_list_ctrl_show_process.InsertColumn(2, _T("PID"), LVCFMT_LEFT, 100);

	ListProcess();  // 默认列出所有进程

	return TRUE;
}


// 列出所有进程  参数为True表示只列出带有窗口的进程
void CProcessListDlg::ListProcess(BOOL has_wnd) {
	m_list_ctrl_show_process.DeleteAllItems();	// 清空进程列表所有进程

	HANDLE hSnapProcessShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnapProcessShot == INVALID_HANDLE_VALUE) {
		AfxMessageBox(_T("创建进程快照失败！"));
		return;
	}

	PROCESSENTRY32 pe = { 0 };
	pe.dwSize = sizeof pe;

	int i = 0;
	if (!Process32First(hSnapProcessShot, &pe)) {
		AfxMessageBox(_T("没有找到第一个进程！"));
		CloseHandle(hSnapProcessShot);
		return;
	}
	else {
		if (!has_wnd) {
			m_list_ctrl_show_process.InsertItem(i, _T("0"));

			CString str;
			str.Format(_T("%s"), pe.szExeFile);
			m_list_ctrl_show_process.SetItemText(i, 1, str);

			str.Format(_T("%d"), pe.th32ProcessID);
			m_list_ctrl_show_process.SetItemText(i, 2, str);
			i++;
		}
	}

	while (Process32Next(hSnapProcessShot, &pe)) {
		if (!has_wnd) {
			CString str;
			str.Format(_T("%d"), i);
			m_list_ctrl_show_process.InsertItem(i, str);

			str.Format(_T("%s"), pe.szExeFile);
			m_list_ctrl_show_process.SetItemText(i, 1, str);

			str.Format(_T("%d"), pe.th32ProcessID);
			m_list_ctrl_show_process.SetItemText(i, 2, str);
			i++;
		}
		else {
			if (GetHwndByProcessId(pe.th32ProcessID)) {
				CString str;
				str.Format(_T("%d"), i);
				m_list_ctrl_show_process.InsertItem(i, str);

				str.Format(_T("%s"), pe.szExeFile);
				m_list_ctrl_show_process.SetItemText(i, 1, str);

				str.Format(_T("%d"), pe.th32ProcessID);
				m_list_ctrl_show_process.SetItemText(i, 2, str);
				i++;
			}
		}
	}

	CloseHandle(hSnapProcessShot);
}

struct WNDINFO
{
	HWND hWnd;
	DWORD dwPid;
};

// 枚举窗口回调函数
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
	WNDINFO* pInfo = (WNDINFO*)lParam;

	DWORD dwProcessId = 0;
	GetWindowThreadProcessId(hwnd, &dwProcessId);

	if (dwProcessId == pInfo->dwPid) {
		pInfo->hWnd = hwnd;
		return FALSE;
	}

	return TRUE;
}


// 当前pid的进程是否带有窗口
HWND CProcessListDlg::GetHwndByProcessId(DWORD dwProcessId) {
	WNDINFO info = { 0 };
	info.hWnd = NULL;
	info.dwPid = dwProcessId;

	EnumWindows(EnumWindowsProc, (LPARAM)&info);

	return info.hWnd;
}


void CProcessListDlg::OnBnClickedBtnGetProcessList()
{
	ListProcess();  // 默认列出所有进程
}


void CProcessListDlg::OnBnClickedBtnGetWndProcessList()
{
	ListProcess(TRUE);  // 只列出所有窗口进程
}

// 选择一个进程并显示到编辑框
void CProcessListDlg::OnBnClickedBtnChooseAProcess()
{
	int sel_idx = m_list_ctrl_show_process.GetNextItem(-1, LVIS_SELECTED);

	if (sel_idx < 0) {
		AfxMessageBox(_T("你没有选中任何行！"));
		return;
	}

	CString str1 = m_list_ctrl_show_process.GetItemText(sel_idx, 1);
	CString str2 = m_list_ctrl_show_process.GetItemText(sel_idx, 2);

	CInjectDllDlg* pDlg = (CInjectDllDlg*)(AfxGetApp()->GetMainWnd());

	//AfxMessageBox(str1 + " : " + str2);
	pDlg->m_edit_ctrl_show_process.SetWindowTextW(str1 + " : " + str2);
	/*pDlg->m_edit_show_process_value = str1 + " : " + str2;
	UpdateData(FALSE);*/

	OnOK();
}


void CProcessListDlg::OnBnClickedBtnCloseProcessListDlg()
{
	OnOK();
}
