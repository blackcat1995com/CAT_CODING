
// DemoDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Demo.h"
#include "DemoDlg.h"
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


// CDemoDlg 对话框



CDemoDlg::CDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEMO_DIALOG, pParent)
	, m_edit_a_value(0)
	, m_edit_b_value(0)
	, m_edit_c_value(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_A, m_edit_a_value);
	DDX_Text(pDX, IDC_EDIT_B, m_edit_b_value);
	DDV_MinMaxInt(pDX, m_edit_b_value, 0, 100);
	DDX_Text(pDX, IDC_EDIT_C, m_edit_c_value);
	DDV_MinMaxInt(pDX, m_edit_c_value, 0, 100);
	DDX_Control(pDX, IDC_EDIT_A, m_edit_a_control);
	DDX_Control(pDX, IDC_EDIT_B, m_edit_b_control);
	DDX_Control(pDX, IDC_EDIT_C, m_edit_c_control);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD1, &CDemoDlg::OnBnClickedButtonAdd1)
	ON_BN_CLICKED(IDC_BUTTON_ADD2, &CDemoDlg::OnBnClickedButtonAdd2)
	ON_BN_CLICKED(IDC_BUTTON_ADD3, &CDemoDlg::OnBnClickedButtonAdd3)
	ON_BN_CLICKED(IDC_BUTTON_ADD4, &CDemoDlg::OnBnClickedButtonAdd4)
	ON_BN_CLICKED(IDC_BUTTON_ADD5, &CDemoDlg::OnBnClickedButtonAdd5)
	ON_BN_CLICKED(IDC_BUTTON_ADD6, &CDemoDlg::OnBnClickedButtonAdd6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDemoDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CDemoDlg 消息处理程序

BOOL CDemoDlg::OnInitDialog()
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

void CDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDemoDlg::OnPaint()
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
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



const int N = 20;
void CDemoDlg::OnBnClickedButtonAdd1()
{
	TCHAR str1[N], str2[N], str3[N];

	GetDlgItem(IDC_EDIT_A)->GetWindowTextW(str1, N);
	GetDlgItem(IDC_EDIT_B)->GetWindowTextW(str2, N);

	int a = _ttoi(str1);
	int b = _ttoi(str2);

	int c = a + b;

	_itow_s(c, str3, 16);

	GetDlgItem(IDC_EDIT_C)->SetWindowTextW(str3);
}


void CDemoDlg::OnBnClickedButtonAdd2()
{
	/*TCHAR str1[N], str2[N], str3[N];

	GetDlgItemText(IDC_EDIT_A, str1, N);
	GetDlgItemText(IDC_EDIT_B, str2, N);*/

	CString str1, str2;
	GetDlgItemText(IDC_EDIT_A, str1);
	GetDlgItemText(IDC_EDIT_B, str2);

	TCHAR* chs1 = new TCHAR[N];
	TCHAR* chs2 = new TCHAR[N];
	TCHAR chs3[N];

	chs1 = str1.GetBuffer(str1.GetLength());
	chs2 = str2.GetBuffer(str2.GetLength());

	int a = _ttoi(chs1);
	int b = _ttoi(chs2);

	int c = a + b;

	_itow_s(c, chs3, 10);
	
	SetDlgItemText(IDC_EDIT_C, chs3);

	str1.ReleaseBuffer(); 
	str2.ReleaseBuffer();
	

	/*int a = _ttoi(str1);
	int b = _ttoi(str2);

	int c = a + b;

	_itow_s(c, str3, 10);

	SetDlgItemText(IDC_EDIT_C, str3);*/

	/*TCHAR chs[N] = _T("Hello");
	CString str;
	str.Format(_T("%s"), chs);
	OutputDebugString(str);*/
}


void CDemoDlg::OnBnClickedButtonAdd3()
{
	int a = GetDlgItemInt(IDC_EDIT_A);
	int b = GetDlgItemInt(IDC_EDIT_B);

	int c = a + b;

	SetDlgItemInt(IDC_EDIT_C, c);
}


void CDemoDlg::OnBnClickedButtonAdd4()
{
	UpdateData(TRUE);

	m_edit_c_value = m_edit_a_value + m_edit_b_value;

	UpdateData(FALSE);
}


void CDemoDlg::OnBnClickedButtonAdd5()
{
	CString str1, str2;
	m_edit_a_control.GetWindowTextW(str1);
	m_edit_b_control.GetWindowTextW(str2);

	// OutputDebugString(str1 + str2);

	// Cstring 转 int
	int a = _ttoi(str1);
	int b = _ttoi(str2);

	int c = a + b;

	// int 转 CString
	CString str3;
	str3.Format(_T("%d"), c);
	m_edit_c_control.SetWindowTextW(str3);
}


void CDemoDlg::OnBnClickedButtonAdd6()
{
	TCHAR chs1[N], chs2[N], chs3[N];

	::SendMessage(GetDlgItem(IDC_EDIT_A)->m_hWnd, WM_GETTEXT, N, (LPARAM)chs1);
	::SendMessage(GetDlgItem(IDC_EDIT_B)->m_hWnd, WM_GETTEXT, N, (LPARAM)chs2);

	int a = _ttoi(chs1);
	int b = _ttoi(chs2);

	int c = a + b;

	_itow_s(c, chs3, 10);

	::SendMessage(GetDlgItem(IDC_EDIT_C)->m_hWnd, WM_SETTEXT, 0, (LPARAM)chs3);
}


void CDemoDlg::OnBnClickedButton7()
{
	TCHAR chs1[N], chs2[N], chs3[N];

	SendDlgItemMessage(IDC_EDIT_A, WM_GETTEXT, N, (LPARAM)chs1);
	SendDlgItemMessage(IDC_EDIT_B, WM_GETTEXT, N, (LPARAM)chs2);

	int a = _ttoi(chs1);
	int b = _ttoi(chs2);

	int c = a + b;

	_itow_s(c, chs3, 10);

	SendDlgItemMessage(IDC_EDIT_C, WM_SETTEXT, 0, (LPARAM)chs3);
}
