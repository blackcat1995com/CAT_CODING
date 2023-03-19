
// WinMineDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "WinMine.h"
#include "WinMineDlg.h"
#include "afxdialogex.h"

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


// CWinMineDlg 对话框



CWinMineDlg::CWinMineDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WINMINE_DIALOG, pParent)
	, m_edit_show_data(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWinMineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Edit_Show_Data, m_edit_show_data);
}

BEGIN_MESSAGE_MAP(CWinMineDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Btn_CJ, &CWinMineDlg::OnBnClickedBtnCj)
	ON_BN_CLICKED(IDC_Btn_ZJ, &CWinMineDlg::OnBnClickedBtnZj)
	ON_BN_CLICKED(IDC_Btn_GJ, &CWinMineDlg::OnBnClickedBtnGj)
	ON_BN_CLICKED(IDC_Btn_ZDY, &CWinMineDlg::OnBnClickedBtnZdy)
	ON_BN_CLICKED(IDC_Btn_Read_Chess, &CWinMineDlg::OnBnClickedBtnReadChess)
	ON_BN_CLICKED(IDC_Btn_Auto_Clear, &CWinMineDlg::OnBnClickedBtnAutoClear)
END_MESSAGE_MAP()


// CWinMineDlg 消息处理程序

BOOL CWinMineDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CWinMineDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWinMineDlg::OnPaint()
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
HCURSOR CWinMineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ---------------------------------------------------

HWND hwnd;
RECT rect;
DWORD pid;
HANDLE process_hwnd;

void init() {
	hwnd = ::FindWindowA(NULL, "扫雷");
	::GetWindowThreadProcessId(hwnd, &pid);
	process_hwnd = ::OpenProcess(PROCESS_ALL_ACCESS, NULL, pid);
	::GetWindowRect(hwnd, &rect);
	/*CString str;
	str.Format("%d %d %d %d\n", rect.left, rect.top, rect.right, rect.bottom);
	OutputDebugStringA(str);*/
}


void CWinMineDlg::OnBnClickedBtnCj()
{
	init();
	if (!hwnd) {
		::MessageBoxA(NULL, "扫雷游戏未打开", "错误", MB_OK);
		return;
	}
	::SendMessageA(hwnd, WM_COMMAND, 0x209, 0);
	m_edit_show_data.Empty();
	UpdateData(FALSE);
}


void CWinMineDlg::OnBnClickedBtnZj()
{
	init();
	if (!hwnd) {
		::MessageBoxA(NULL, "扫雷游戏未打开", "错误", MB_OK);
		return;
	}
	::SendMessageA(hwnd, WM_COMMAND, 0x20A, 0);
	m_edit_show_data.Empty();
	UpdateData(FALSE);
}


void CWinMineDlg::OnBnClickedBtnGj()
{
	init();
	if (!hwnd) {
		::MessageBoxA(NULL, "扫雷游戏未打开", "错误", MB_OK);
		return;
	}
	::SendMessageA(hwnd, WM_COMMAND, 0x20B, 0);
	m_edit_show_data.Empty();
	UpdateData(FALSE);
}


void CWinMineDlg::OnBnClickedBtnZdy()
{
	init();
	if (!hwnd) {
		::MessageBoxA(NULL, "扫雷游戏未打开", "错误", MB_OK);
		return;
	}
	::SendMessageA(hwnd, WM_COMMAND, 0x20C, 0);
	m_edit_show_data.Empty();
	UpdateData(FALSE);
}

int tx, ty, pos_x, pos_y;
POINT pre_pos;
void CWinMineDlg::OnBnClickedBtnReadChess()
{
	m_edit_show_data.Empty();
	init();
	if (!hwnd) {
		::MessageBoxA(NULL, "扫雷游戏未打开", "错误", MB_OK);
		return;
	}

	// 设置窗口置顶
	::SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

	::GetCursorPos(&pre_pos);

	int face_x = rect.left + (rect.right - rect.left) / 2;
	int face_y = rect.top + 75;

	::SetCursorPos(face_x, face_y);
	::Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	::Sleep(10);

	::SetCursorPos(rect.left + 20, rect.top + 110);
	::Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	::Sleep(10);

	::SetCursorPos(pre_pos.x, pre_pos.y);

	::Sleep(1000);

	unsigned char chess_data[24][32] = {};
	::ReadProcessMemory(process_hwnd, (LPCVOID)0x01005361, (LPVOID)&chess_data, 24 * 32, NULL);

	int irow;
	::ReadProcessMemory(process_hwnd, (LPCVOID)0x01005338, (LPVOID)&irow, 4, NULL);

	CString tstr;
	/*str.Format("%d\n", irow);
	OutputDebugStringA(str);*/

	//for (int i = 0; i < irow; i++) {
	//	for (int j = 0; j < 32; j++) {
	//		//if (0x10 == chess_data[i][j]) break;
	//		tstr.Format("%02X  ", chess_data[i][j]);
	//		OutputDebugStringA(tstr);
	//		//m_edit_show_data += tstr;
	//	}
	//	tstr.Format("\n");
	//	OutputDebugStringA(tstr);
	//	//m_edit_show_data += "\r\n";
	//}
	for (int i = 0; i < irow; i++) {
		for (int j = 0; j < 32; j++) {
			if (0x10 == chess_data[i][j]) break;
			tstr.Format("%02X ", chess_data[i][j]);
			m_edit_show_data += tstr;
		}
		m_edit_show_data += "\r\n";
	}

	UpdateData(FALSE);
}

void MoveToAndLeftClick(HWND hwnd, int x, int y) {
	int lparam = (pos_y << 16) + pos_x;
	::SendMessageA(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lparam);
	::SendMessageA(hwnd, WM_LBUTTONUP, 0, lparam);
}

void CWinMineDlg::OnBnClickedBtnAutoClear()
{
	m_edit_show_data.Empty();
	init();
	if (!hwnd) {
		::MessageBoxA(NULL, "扫雷游戏未打开", "错误", MB_OK);
		return;
	}

	unsigned char chess_data[24][32] = {};
	::ReadProcessMemory(process_hwnd, (LPCVOID)0x01005361, (LPVOID)&chess_data, 24 * 32, NULL);

	int irow;
	::ReadProcessMemory(process_hwnd, (LPCVOID)0x01005338, (LPVOID)&irow, 4, NULL);

	tx = 20, ty = 60;
	for (int i = 0; i < irow; i++) {
		for (int j = 0; j < 32; j++) {
			if (0x10 == chess_data[i][j]) break;
			pos_x = tx + j * 16;
			pos_y = ty + i * 16;
			
			if (0x8f != chess_data[i][j])
				MoveToAndLeftClick(hwnd, pos_x, pos_y);
		}
	}
}
