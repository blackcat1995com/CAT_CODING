
// llkDlg.cpp: 实现文件
//

#include "pch.h"
#include "CatFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

POINT old_pos;
int delay_time = 0;

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


// CllkDlg 对话框



CllkDlg::CllkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LLK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_CatIcon);
}

void CllkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TopWindow, m_topwindow);
	DDX_Control(pDX, IDC_ClearCountDown, m_clearcountdown);
	DDX_Control(pDX, IDC_IsChangeSpeed, m_changesliderspeed);
	DDX_Control(pDX, IDC_SLIDER1, m_clickspeed);
	DDX_Control(pDX, IDC_ClickSeed, m_clickspeed);
}

BEGIN_MESSAGE_MAP(CllkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AutoStart, &CllkDlg::OnBnClickedAutostart)
	ON_BN_CLICKED(IDC_TopWindow, &CllkDlg::OnBnClickedTopwindow)
	ON_BN_CLICKED(IDC_ClearCountDown, &CllkDlg::OnBnClickedClearcountdown)
	ON_BN_CLICKED(IDC_ClearOnePair, &CllkDlg::OnBnClickedClearonepair)
	
	ON_BN_CLICKED(IDC_AutoPlay, &CllkDlg::OnBnClickedAutoplay)
	ON_BN_CLICKED(IDC_IsChangeSpeed, &CllkDlg::OnBnClickedIschangespeed)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_ClickSeed, &CllkDlg::OnNMReleasedcaptureClickseed)
END_MESSAGE_MAP()


// CllkDlg 消息处理程序

BOOL CllkDlg::OnInitDialog()
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
	m_clickspeed.SetRange(50, 500);
	m_clickspeed.SetPos(200);
	m_clickspeed.EnableWindow(FALSE);
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CllkDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CllkDlg::OnPaint()
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
HCURSOR CllkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ----------------------------------------------------------------------------------------------------

// 消除一对棋子

BOOL clearOnePair() {
	init();
	// 遍历第一个棋子
	for (int x1 = 0; x1 < 11; x1++) {
		for (int y1 = 0; y1 < 19; y1++) {
			// 遍历第二个棋子
			for (int x2 = x1; x2 < 11; x2++) {
				for (int y2 = 0; y2 < 19; y2++) {
					if (chess_data[x1][y1] > 0 && chess_data[x2][y2] > 0 && (chess_data[x1][y1] == chess_data[x2][y2]) && (!(x1 == x2 && y1 == y2))) {
						p1.x = x1;
						p1.y = y1;
						p2.x = x2;
						p2.y = y2;
						// 判断两个点是否满足消除需求
						if (checkTeoPointsIsClear(p1, p2)) {
							clickTwoPoints(p1, p2);
						
							return TRUE;
						}
						
					}
				}
			}
		}
	}

	return FALSE;
}


void CllkDlg::OnBnClickedAutostart()
{
	init();
	// 设置游戏窗口置顶
	cat->SetWindowTop(game_hwnd);
	// 保存鼠标原来位置
	cat->GetCursorPos(&old_pos);
	cat->MoveTo(652 + game_rect.left, 566 + game_rect.top);
	cat->Delay(10);
	cat->LeftClick();
	
	// 还原鼠标位置
	cat->Delay(10);
	cat->MoveTo(old_pos.x, old_pos.y);
}


void CllkDlg::OnBnClickedTopwindow()
{
	init();
	UpdateData(TRUE);
	if (m_topwindow.GetCheck()) {
		cat->SetWindowTop(game_hwnd);
	}
}


void CllkDlg::OnBnClickedClearcountdown()
{
	init();
	if (m_clearcountdown.GetCheck()) {
		cat->SetTimer(COUNT_DOWN_TIMER_ID, 3 * 1000, countDownTimerProc);
	}
	else {
		cat->KillTimer(COUNT_DOWN_TIMER_ID);
	}
}


// 单消棋子
void CllkDlg::OnBnClickedClearonepair()
{

	cat->GetCursorPos(&old_pos);
	clearOnePair();
	cat->MoveTo(old_pos.x, old_pos.y);
}




// 自动挂机 剩余棋子数 00184DC0
void CllkDlg::OnBnClickedAutoplay()
{
	init();
	int chess_num = cat->ReadInt(process_hwnd, (LPCVOID)0x00184DC0, 4);
	while (chess_num) {
		clearOnePair();
		chess_num = cat->ReadInt(process_hwnd, (LPCVOID)0x00184DC0, 4);
	}
}


// 是否开启挂机速度调节
void CllkDlg::OnBnClickedIschangespeed()
{
	if (m_changesliderspeed.GetCheck())
		m_clickspeed.EnableWindow(TRUE);
	else
		m_clickspeed.EnableWindow(FALSE);
}


void CllkDlg::OnNMReleasedcaptureClickseed(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);
	init();
	delay_time = m_clickspeed.GetPos();
	int chess_num = cat->ReadInt(process_hwnd, (LPCVOID)0x00184DC0, 4);
	while (chess_num) {
		clearOnePair();
		cat->Delay(550 - delay_time);
		chess_num = cat->ReadInt(process_hwnd, (LPCVOID)0x00184DC0, 4);
	}
	*pResult = 0;
}
