
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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_CBX_ShowStyle, m_cbx_show_style);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADDROW, &CDemoDlg::OnBnClickedBtnAddrow)
	ON_BN_CLICKED(IDC_BTN_DELSELECTED, &CDemoDlg::OnBnClickedBtnDelselected)
	ON_CBN_SELCHANGE(IDC_CBX_ShowStyle, &CDemoDlg::OnCbnSelchangeCbxShowstyle)
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

	m_img_coin_list.Create(32, 32, ILC_COLOR32, 3, 1);
	m_img_coin_list.Add(AfxGetApp()->LoadIconW(IDI_ICON_BTC32));
	m_img_coin_list.Add(AfxGetApp()->LoadIconW(IDI_ICON_LTC32));
	m_img_coin_list.Add(AfxGetApp()->LoadIconW(IDI_ICON_XRP32));

	m_list1.SetImageList(&m_img_coin_list, LVSIL_SMALL);
	m_list1.InsertItem(0, _T("比特币"), 0);
	m_list1.InsertItem(0, _T("莱特币"), 1);
	m_list1.InsertItem(0, _T("瑞波币"), 2);

	m_list1.SetItemState(0, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);

	// List Control 2

	m_list2.InsertColumn(0, _T("第一列"), LVCFMT_LEFT, 218);
	m_list2.InsertColumn(1, _T("第二列"), LVCFMT_LEFT, 218);

	m_icon_file32.Create(32, 32, ILC_COLOR32, 1, 1);
	m_icon_file32.Add(AfxGetApp()->LoadIconW(IDI_ICON_FILE32));

	m_list2.SetImageList(&m_icon_file32, LVSIL_SMALL);

	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_cbx_show_style.SetCurSel(3);

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



void CDemoDlg::OnBnClickedBtnAddrow()
{
	int cnt = m_list2.GetItemCount();

	CString str;
	str.Format(_T("第%d行,第1列"), cnt + 1);
	m_list2.InsertItem(cnt, str, 0);

	str.Format(_T("第%d行,第2列"), cnt + 1);
	m_list2.SetItemText(cnt, 1, str);
}


void CDemoDlg::OnBnClickedBtnDelselected()
{
	int cnt = m_list2.GetItemCount();

	for (int i = cnt; i >= 0; i--) {
		if (m_list2.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
			m_list2.DeleteItem(i);
	}
}


void CDemoDlg::OnCbnSelchangeCbxShowstyle()
{
	DWORD dwStyle;

	switch (m_cbx_show_style.GetCurSel())
	{
	case 0:
		dwStyle = LVS_ICON;
		break;
	case 1:
		dwStyle = LVS_SMALLICON;
		break;
	case 2:
		dwStyle = LVS_LIST;
		break;
	case 3:
		dwStyle = LVS_REPORT;
		break;
	default:
		return;
	}

	m_list2.ModifyStyle(LVS_TYPEMASK, dwStyle);
}
