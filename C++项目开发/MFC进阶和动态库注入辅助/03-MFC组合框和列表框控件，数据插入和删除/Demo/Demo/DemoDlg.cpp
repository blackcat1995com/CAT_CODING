
// DemoDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "afxdialogex.h"
#include <set>

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
	, m_edit_input_string(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT_STRING, m_edit_input_string);
	DDX_Control(pDX, IDC_CBX, m_cbx);
	DDX_Control(pDX, IDC_LSTBOX, m_lstbox);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD_STRING, &CDemoDlg::OnBnClickedButtonAddString)
	ON_BN_CLICKED(IDC_BUTTON_DEL_STRING, &CDemoDlg::OnBnClickedButtonDelString)
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


std::set<CString> st;
void CDemoDlg::OnBnClickedButtonAddString()
{
	UpdateData(TRUE);

	m_edit_input_string.Trim();
	if (m_edit_input_string.IsEmpty()) {
		AfxMessageBox(_T("请先输入内容"));
		return;
	}

	/*if (st.find(m_edit_input_string) != st.end()) {
		AfxMessageBox(_T("请不要重复插入相同值"));
		return;
	}

	st.insert(m_edit_input_string);*/

	int idx = -1;
	if (m_cbx.FindString(idx, m_edit_input_string) != CB_ERR) {
		AfxMessageBox(_T("请不要重复插入相同值"));
		return;
	}

	m_cbx.AddString(m_edit_input_string);
	m_cbx.SetCurSel(m_cbx.GetCount() - 1);

	m_lstbox.AddString(m_edit_input_string);
	m_lstbox.SetCurSel(m_cbx.GetCount() - 1);

	m_edit_input_string = _T("");
	UpdateData(FALSE);
}


void CDemoDlg::OnBnClickedButtonDelString()
{
	int cbx_idx = m_cbx.GetCurSel();
	if (~cbx_idx) {
		m_cbx.DeleteString(cbx_idx);

		if (cbx_idx == m_cbx.GetCount()) m_cbx.SetCurSel(m_cbx.GetCount() - 1);
		else m_cbx.SetCurSel(cbx_idx);
	}

	int lstbox_count = m_lstbox.GetCount();

	CArray<int> lstbox_sel_idxs;
	lstbox_sel_idxs.SetSize(lstbox_count);

	for (int i = 0; i < lstbox_count; i++) lstbox_sel_idxs[i] = -1;

	m_lstbox.GetSelItems(lstbox_count, lstbox_sel_idxs.GetData());

	for (int i = lstbox_count - 1; i >= 0; i--) {
		/*CString output_string;
		output_string.Format(_T("%d\n"), lstbox_sel_idxs[i]);
		OutputDebugString(output_string);*/
		if (~lstbox_sel_idxs[i])
			m_lstbox.DeleteString(lstbox_sel_idxs[i]);
	}
}
