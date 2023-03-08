
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
	, m_edit_input_string(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT_STRING, m_edit_input_string);
	DDX_Control(pDX, IDC_TREE, m_tree);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &CDemoDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_DEL, &CDemoDlg::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_MODIFY, &CDemoDlg::OnBnClickedBtnModify)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &CDemoDlg::OnTvnSelchangedTree)
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

	m_icon_list.Create(32, 32, ILC_COLOR32, 3, 3);
	UINT icons[] = { IDI_ICON_BTC32, IDI_ICON_LTC32, IDI_ICON_XRP32 };
	for (int i = 0; i < 3; i++) m_icon_list.Add(AfxGetApp()->LoadIconW(icons[i]));

	m_tree.SetImageList(&m_icon_list, LVSIL_NORMAL);

	HTREEITEM root1 = m_tree.InsertItem(_T("root1"), 0, 0);
	HTREEITEM root2 = m_tree.InsertItem(_T("root2"), 1, 1);
	HTREEITEM root3 = m_tree.InsertItem(_T("root3"), 2, 2);

	HTREEITEM sub1 = m_tree.InsertItem(_T("sub1"), 0, 0, root1);

	m_tree.Expand(root1, TVE_EXPAND);
	m_tree.Expand(root2, TVE_EXPAND);
	m_tree.Expand(root3, TVE_EXPAND);
	m_tree.Expand(sub1, TVE_EXPAND);

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



void CDemoDlg::OnBnClickedBtnAdd()
{
	UpdateData(TRUE);

	if (!m_edit_input_string.Trim().GetLength()) {
		AfxMessageBox(_T("请先输入文本内容"));
		return;
	}

	HTREEITEM cur_item = m_tree.GetSelectedItem();

	if (!cur_item) cur_item = TVI_ROOT;
	
	TVINSERTSTRUCT ts = { 0 };

	ts.hParent = cur_item;
	ts.hInsertAfter = TVI_LAST;
	ts.item.pszText = m_edit_input_string.GetBuffer();
	ts.item.mask = TVIF_TEXT | TVIF_IMAGE;
	
	HTREEITEM new_item = m_tree.InsertItem(&ts);
	m_tree.SelectItem(new_item);

	m_tree.EnsureVisible(new_item);

	m_edit_input_string = _T("");
	UpdateData(FALSE);
}


void CDemoDlg::OnBnClickedBtnDel()
{
	HTREEITEM cur_item = m_tree.GetSelectedItem();

	if (!cur_item) {
		AfxMessageBox(_T("请先选择一个要删除的节点"));
		return;
	}

	HTREEITEM hParent = m_tree.GetParentItem(cur_item);
	m_tree.DeleteItem(cur_item);

	m_tree.SelectItem(hParent);

}


void CDemoDlg::OnBnClickedBtnModify()
{
	UpdateData(TRUE);

	HTREEITEM cur_item = m_tree.GetSelectedItem();

	if (!cur_item) {
		AfxMessageBox(_T("请先选择一个要修改的节点"));
		return;
	}

	if (!m_edit_input_string.Trim().GetLength()) {
		AfxMessageBox(_T("请先输入文本内容"));
		return;
	}

	m_tree.SetItemText(cur_item, m_edit_input_string);
}


void CDemoDlg::OnTvnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	
	UpdateData(TRUE);

	HTREEITEM cur_item = m_tree.GetSelectedItem();

	m_edit_input_string = m_tree.GetItemText(cur_item);

	UpdateData(FALSE);

	*pResult = 0;
}
