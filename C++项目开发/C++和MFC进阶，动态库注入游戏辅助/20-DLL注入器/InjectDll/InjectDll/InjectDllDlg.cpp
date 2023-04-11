
// InjectDllDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "InjectDll.h"
#include "InjectDllDlg.h"
#include "afxdialogex.h"

#include "CProcessListDlg.h"
#include "CExportFuncDlg.h"

#include <tlhelp32.h>	// 快照头文件

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CInjectDllDlg 对话框

CInjectDllDlg::CInjectDllDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INJECTDLL_DIALOG, pParent)
	, m_edit_show_process_value(_T(""))
	, m_edit_show_process_modules(_T(""))
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_CAT_LOGO);
}

void CInjectDllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SHOW_PROCESS, m_edit_show_process_value);
	DDX_Control(pDX, IDC_EDIT_SHOW_PROCESS, m_edit_ctrl_show_process);
	DDX_Text(pDX, IDC_EDIT_SHOW_PROCESS_MODULES, m_edit_show_process_modules);
	DDX_Control(pDX, IDC_LIST_SHOW_DLLS, m_list_ctrl_show_dlls);
}

BEGIN_MESSAGE_MAP(CInjectDllDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SELECT_PROCESS, &CInjectDllDlg::OnBnClickedBtnSelectProcess)
	ON_BN_CLICKED(IDC_BTN_LIST_MODULES, &CInjectDllDlg::OnBnClickedBtnListModules)
	ON_BN_CLICKED(IDC_BTN_LOAD_DLL, &CInjectDllDlg::OnBnClickedBtnLoadDll)
	ON_BN_CLICKED(IDC_BTN_ENABLE_DLL, &CInjectDllDlg::OnBnClickedBtnEnableDll)
	ON_BN_CLICKED(IDC_BTN_REMOVE_DLL, &CInjectDllDlg::OnBnClickedBtnRemoveDll)
	ON_BN_CLICKED(IDC_BTN_CLEAR_DLL, &CInjectDllDlg::OnBnClickedBtnClearDll)
	ON_BN_CLICKED(IDC_BTN_SET_EXPORT_FUNC, &CInjectDllDlg::OnBnClickedBtnSetExportFunc)
END_MESSAGE_MAP()


// CInjectDllDlg 消息处理程序

BOOL CInjectDllDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_list_ctrl_show_dlls.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_SINGLEROW | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
	m_list_ctrl_show_dlls.InsertColumn(0, _T("是否选择"), LVCFMT_LEFT, 100);
	m_list_ctrl_show_dlls.InsertColumn(1, _T("DLL文件路径"), LVCFMT_LEFT, 200);
	m_list_ctrl_show_dlls.InsertColumn(2, _T("调用函数"), LVCFMT_LEFT, 140);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CInjectDllDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CInjectDllDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CInjectDllDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ---------------------------------------------------------

// 点击选择按钮，弹出进程列表窗口
void CInjectDllDlg::OnBnClickedBtnSelectProcess()
{
	CProcessListDlg process_list_dlg;
	process_list_dlg.DoModal();	
}

BOOL CInjectDllDlg::ListProcessModules(DWORD dwPid) {
	HANDLE hSnapModuleShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPid);

	MODULEENTRY32 me32 = { 0 };

	if (hSnapModuleShot == INVALID_HANDLE_VALUE) {
		AfxMessageBox(_T("创建模块快照失败！"));
		return FALSE;
	}

	me32.dwSize = sizeof MODULEENTRY32;

	CString all_str, cur_str;

	int i = 0;
	if (!Module32First(hSnapModuleShot, &me32)) {
		AfxMessageBox(_T("列举第一个模块失败！"));
		CloseHandle(hSnapModuleShot);
		return FALSE;
	}
	else {
		cur_str.Format(_T("%d: %s - 0x%x\r\n"), i++, me32.szModule, me32.modBaseAddr);
		all_str = cur_str;
	}

	while (Module32Next(hSnapModuleShot, &me32)) {
		cur_str.Format(_T("%d: %s - 0x%x\r\n"), i++, me32.szModule, me32.modBaseAddr);
		all_str += cur_str;
	}

	m_edit_show_process_modules = all_str;
	UpdateData(FALSE);

	CloseHandle(hSnapModuleShot);
	return TRUE;
}

// 按钮 列举进程模块及其基址
void CInjectDllDlg::OnBnClickedBtnListModules()
{
	UpdateData(TRUE);

	CString str = m_edit_show_process_value;
	int pos = str.Find(_T(" : "));

	int len = str.Delete(0, pos + 3);

	if (str.IsEmpty()) {
		AfxMessageBox(_T("请确认是否选择了进程！"));
		return;
	}
	
	m_edit_show_process_modules = _T("");
	UpdateData(FALSE);

	DWORD dwPid = _wtoi(str);

	ListProcessModules(dwPid);

}


// 加载Dll
void CInjectDllDlg::OnBnClickedBtnLoadDll()
{
	CString file_str;
	CFileDialog file_dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST, _T("DLL Files(*.dll)|*.dll||"), NULL);

	if (file_dlg.DoModal()) file_str = file_dlg.GetPathName();

	if (file_str.IsEmpty()) return;

	int cnt = m_list_ctrl_show_dlls.GetItemCount();
	m_list_ctrl_show_dlls.InsertItem(cnt, _T(""));
	m_list_ctrl_show_dlls.SetItemText(cnt, 1, file_str);
}


void CInjectDllDlg::OnBnClickedBtnEnableDll()
{
	int cur_sel = m_list_ctrl_show_dlls.GetNextItem(-1, LVIS_SELECTED);

	if (cur_sel < 0) {
		AfxMessageBox(_T("你没有选中任何行！"));
		return;
	}

	if (m_list_ctrl_show_dlls.GetCheck(cur_sel)) m_list_ctrl_show_dlls.SetCheck(cur_sel, FALSE);
	else m_list_ctrl_show_dlls.SetCheck(cur_sel, TRUE);
}


void CInjectDllDlg::OnBnClickedBtnRemoveDll()
{
	int cur_sel = m_list_ctrl_show_dlls.GetNextItem(-1, LVIS_SELECTED);

	if (cur_sel < 0) {
		AfxMessageBox(_T("你没有选中任何行！"));
		return;
	}

	m_list_ctrl_show_dlls.DeleteItem(cur_sel);
}


void CInjectDllDlg::OnBnClickedBtnClearDll()
{
	m_list_ctrl_show_dlls.DeleteAllItems();
}


// 点击设置导出函数按钮，获取dll路径名
void CInjectDllDlg::OnBnClickedBtnSetExportFunc()
{
	int cur_sel = m_list_ctrl_show_dlls.GetNextItem(-1, LVIS_SELECTED);

	if (cur_sel < 0) {
		AfxMessageBox(_T("你没有选中任何行！"));
		return;
	}

	CExportFuncDlg export_func_dlg;
	export_func_dlg.dll_name_path_str = m_list_ctrl_show_dlls.GetItemText(cur_sel, 1);

	//AfxMessageBox(export_func_dlg.dll_name_path_str);
	export_func_dlg.DoModal();
}
