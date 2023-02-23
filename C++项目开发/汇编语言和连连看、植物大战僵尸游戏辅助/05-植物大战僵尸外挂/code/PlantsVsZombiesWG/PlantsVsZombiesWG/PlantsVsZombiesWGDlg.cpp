
// PlantsVsZombiesWGDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "PlantsVsZombiesWG.h"
#include "PlantsVsZombiesWGDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HANDLE g_process_handle;	// 游戏进程句柄
HANDLE g_monitor_thread;
BOOL is_collect_sun;

// 向指定内存写入数据
void WriteMemory(HANDLE hProcess, void* value, DWORD valueSize, ...) {
	if (value == NULL || valueSize == 0 || hProcess == NULL) return;

	DWORD tempValue = 0;

	va_list addresses;
	va_start(addresses, valueSize);
	DWORD offset = 0;
	DWORD lastAddress = 0;
	while ((offset = va_arg(addresses, DWORD)) != -1) {
		lastAddress = tempValue + offset;
		::ReadProcessMemory(hProcess, (LPCVOID)lastAddress, &tempValue, sizeof(DWORD), NULL);
	}
	va_end(addresses);

	::WriteProcessMemory(hProcess, (LPVOID)lastAddress, value, valueSize, NULL);
}

void WriteMemory(HANDLE hProcess, void* value, DWORD valueSize, DWORD address) {
	WriteMemory(hProcess, value, valueSize, address, -1);
}

// 线程函数
DWORD WINAPI monitorThreadProc(LPVOID lpParameter) {
	while (TRUE) {
		HWND game_hwnd = ::FindWindowA(NULL, "植物大战僵尸中文版");
		if (!game_hwnd) {
			::MessageBoxA(NULL, "植物大战僵尸游戏未打开", "错误", MB_OK);
		}
		else if (!g_process_handle) {
			DWORD pid;
			::GetWindowThreadProcessId(game_hwnd, &pid);
			g_process_handle = ::OpenProcess(PROCESS_ALL_ACCESS, NULL, pid);
		}

		WriteMemory(g_process_handle, &is_collect_sun, sizeof(is_collect_sun), 0x6A9EC0, 0x768, 0xe4, 0x50, -1);
		
		::Sleep(1000);
	}

	return 0;
}
	
// 提升权限函数
BOOL ImproveAccessPrivilege()
{
	HANDLE tokenHandle;
	LUID privilegeValue;

	if (!::OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &tokenHandle)) return FALSE;

	if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &privilegeValue))
	{
		::CloseHandle(tokenHandle);
		return FALSE;
	}

	TOKEN_PRIVILEGES privileges;
	privileges.PrivilegeCount = 1;
	privileges.Privileges[0].Luid = privilegeValue;
	privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!::AdjustTokenPrivileges(tokenHandle, FALSE, &privileges, sizeof(privileges), NULL, NULL))
	{
		::CloseHandle(tokenHandle);
		return FALSE;
	}

	return TRUE;
}



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


// CPlantsVsZombiesWGDlg 对话框



CPlantsVsZombiesWGDlg::CPlantsVsZombiesWGDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PLANTSVSZOMBIESWG_DIALOG, pParent)
	, m_edit_sun_value(_T(""))
	, m_edit_money_value(_T(""))
	, m_edit_plantX(_T(""))
	, m_edit_plantY(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlantsVsZombiesWGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Edit_Show_Sun, m_edit_sun_value);
	DDX_Text(pDX, IDC_Edit_Show_Money, m_edit_money_value);
	DDX_Control(pDX, IDC_Check_Auto_Collect, m_check_auto_collect);
	DDX_Control(pDX, IDC_Check_Kill, m_check_kill);
	DDX_Control(pDX, IDC_Check_Plants_NoDeath, m_check_plabts_no_death);
	DDX_Control(pDX, IDC_Check_Run_InBG, m_check_run_inbg);
	DDX_Control(pDX, IDC_Check_Plants_NoCD, m_check_plants_nocd);
	DDX_Control(pDX, IDC_Check_BigMouse_NoCD, m_check_bigmouse_nocd);
	DDX_Text(pDX, IDC_Edit_plantX, m_edit_plantX);
	DDX_Text(pDX, IDC_Edit_plantY, m_edit_plantY);
	//  DDX_CBString(pDX, IDC_Cbx_Plants_Type, m_cbx_choose_plant);
	DDX_Control(pDX, IDC_Cbx_Plants_Type, m_cbx_choose_plant);
}

BEGIN_MESSAGE_MAP(CPlantsVsZombiesWGDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Btn_Set_Sun, &CPlantsVsZombiesWGDlg::OnBnClickedBtnSetSun)
	ON_BN_CLICKED(IDC_Btn_Set_money, &CPlantsVsZombiesWGDlg::OnBnClickedBtnSetmoney)
	ON_BN_CLICKED(IDC_Check_Auto_Collect, &CPlantsVsZombiesWGDlg::OnBnClickedCheckAutoCollect)
	ON_BN_CLICKED(IDC_Check_Kill, &CPlantsVsZombiesWGDlg::OnBnClickedCheckKill)
	ON_BN_CLICKED(IDC_Check_Plants_NoDeath, &CPlantsVsZombiesWGDlg::OnBnClickedCheckPlantsNodeath)
	ON_BN_CLICKED(IDC_Check_Run_InBG, &CPlantsVsZombiesWGDlg::OnBnClickedCheckRunInbg)
	ON_BN_CLICKED(IDC_Check_Plants_NoCD, &CPlantsVsZombiesWGDlg::OnBnClickedCheckPlantsNocd)
	ON_BN_CLICKED(IDC_Check_BigMouse_NoCD, &CPlantsVsZombiesWGDlg::OnBnClickedCheckBigmouseNocd)
	ON_BN_CLICKED(IDC_Btn_Rand_Put_Plants, &CPlantsVsZombiesWGDlg::OnBnClickedBtnRandPutPlants)
	ON_CBN_SELCHANGE(IDC_Cbx_Plants_Type, &CPlantsVsZombiesWGDlg::OnCbnSelchangeCbxPlantsType)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CPlantsVsZombiesWGDlg 消息处理程序

BOOL CPlantsVsZombiesWGDlg::OnInitDialog()
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
	ImproveAccessPrivilege();
	g_monitor_thread = ::CreateThread(NULL, NULL, monitorThreadProc, NULL, NULL, NULL);

	// 阳光初始值
	m_edit_sun_value = "8000";
	m_edit_money_value = "9999";
	m_edit_plantX = "5";
	m_edit_plantY = "4";

	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPlantsVsZombiesWGDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPlantsVsZombiesWGDlg::OnPaint()
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
HCURSOR CPlantsVsZombiesWGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPlantsVsZombiesWGDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	// CDialogEx::OnOK();
}


// 设置阳光值
void CPlantsVsZombiesWGDlg::OnBnClickedBtnSetSun()
{
	UpdateData(TRUE);

	int sun_value = _ttoi(m_edit_sun_value);
	WriteMemory(g_process_handle, &sun_value, sizeof(sun_value), 0x6A9EC0, 0x768, 0x5560, -1);
}


// 设置金币值
void CPlantsVsZombiesWGDlg::OnBnClickedBtnSetmoney()
{
	UpdateData(TRUE);
	int money_value = _ttoi(m_edit_money_value);
	WriteMemory(g_process_handle, &money_value, sizeof(money_value), 0x6A9EC0, 0x82C, 0x28, -1);
}


// 自动收集阳光
void CPlantsVsZombiesWGDlg::OnBnClickedCheckAutoCollect()
{
	if (m_check_auto_collect.GetCheck()) is_collect_sun = 1;
	// else is_collect_sun = 0;
}


// 秒杀僵尸
void CPlantsVsZombiesWGDlg::OnBnClickedCheckKill()
{
	DWORD address1 = 0x53130F;	// 普通僵尸
	DWORD address2 = 0x531044;	// 戴帽子僵尸
	DWORD address3 = 0x530CB1;	// 铁丝网僵尸

	if (m_check_kill.GetCheck()) {
		
		BYTE data1[] = { 0x29, 0xff, 0x90, 0x90 };
		WriteMemory(g_process_handle, data1, sizeof(data1), address1);

		BYTE data2[] = { 0x29, 0xc9 };
		WriteMemory(g_process_handle, data2, sizeof(data2), address2);

		BYTE data3[] = { 0x90, 0x90 };
		WriteMemory(g_process_handle, data3, sizeof(data3), address3);
		/*::WriteProcessMemory(g_process_handle, (LPVOID)0x53130F, (LPCVOID)&data1[0], 1, NULL);
		::WriteProcessMemory(g_process_handle, (LPVOID)0x531310, (LPCVOID)&data1[1], 1, NULL);
		::WriteProcessMemory(g_process_handle, (LPVOID)0x531311, (LPCVOID)&data1[2], 1, NULL);
		::WriteProcessMemory(g_process_handle, (LPVOID)0x531312, (LPCVOID)&data1[3], 1, NULL);*/
	}
	else {
		BYTE data1[] = { 0x2b, 0x7c, 0x24, 0x20 };
		WriteMemory(g_process_handle, data1, sizeof(data1), address1);

		BYTE data2[] = { 0x2b, 0xc8 };
		WriteMemory(g_process_handle, data2, sizeof(data2), address2);

		BYTE data3[] = { 0x75, 0x17 };
		WriteMemory(g_process_handle, data3, sizeof(data3), address3);
	}
}

// 植物不死
void CPlantsVsZombiesWGDlg::OnBnClickedCheckPlantsNodeath()
{
	DWORD address1 = 0x52FCF0;
	DWORD address2 = 0x46D7A6;
	DWORD address3 = 0x45EC63;
	DWORD address4 = 0x46CFEB;
	if (m_check_plabts_no_death.GetCheck()) {
		BYTE data1[] = { 0x90, 0x90, 0x90, 0x90 };
		WriteMemory(g_process_handle, data1, sizeof(data1), address1);

		BYTE data2[] = { 0x90, 0x90, 0x90 };
		WriteMemory(g_process_handle, data2, sizeof(data2), address2);

		BYTE data3[] = { 0x90, 0x90, 0x90, 0x90 };
		WriteMemory(g_process_handle, data3, sizeof(data3), address3);

		BYTE data4[] = { 0x90, 0x90, 0x90 };
		WriteMemory(g_process_handle, data4, sizeof(data4), address4);
	}
	else {
		BYTE data1[] = { 0x83, 0x46, 0x40, 0xFC };
		WriteMemory(g_process_handle, data1, sizeof(data1), address1);

		BYTE data2[] = { 0x29, 0x4E, 0X40 };
		WriteMemory(g_process_handle, data2, sizeof(data2), address2);

		BYTE data3[] = { 0x83, 0x46, 0x40, 0xCE };
		WriteMemory(g_process_handle, data3, sizeof(data3), address3);

		BYTE data4[] = { 0x29, 0x50, 0x40 };
		WriteMemory(g_process_handle, data4, sizeof(data4), address4);
	}
}


// 后台运行
void CPlantsVsZombiesWGDlg::OnBnClickedCheckRunInbg()
{
	DWORD address = 0x54E1C2;
	if (m_check_run_inbg.GetCheck()) {
		BYTE data[] = { 0x90, 0x90, 0x90 };
		WriteMemory(g_process_handle, data, sizeof(data), address);
	}
	else {
		BYTE data[] = { 0x0F, 0x95, 0xC0 };
		WriteMemory(g_process_handle, data, sizeof(data), address);
	}
}


void CPlantsVsZombiesWGDlg::OnBnClickedCheckPlantsNocd()
{
	DWORD address = 0x487296;
	if (m_check_plants_nocd.GetCheck()) {
		BYTE data[] = { 0x90, 0x90 };
		WriteMemory(g_process_handle, data, sizeof(data), address);
	}
	else {
		BYTE data[] = { 0x7E, 0x24 };
		WriteMemory(g_process_handle, data, sizeof(data), address);
	}
}


void CPlantsVsZombiesWGDlg::OnBnClickedCheckBigmouseNocd()
{
	DWORD address = 0x46324c;
	if (m_check_bigmouse_nocd.GetCheck()) {
		BYTE data[] = { 0x29, 0xc0, 0x90 };
		WriteMemory(g_process_handle, data, sizeof(data), address);
	}
	else {
		BYTE data[] = { 0x83, 0xc0, 0xff };
		WriteMemory(g_process_handle, data, sizeof(data), address);
	}
}

// ----------------植物全屏种植--------------------
typedef struct PutPlantsNode {
	UINT x, y, id;
}PutPlants, *PPutPlants;

// 无参自定义汇编
__declspec(naked) void asmPutPlants() {
	__asm {
		pushad
		push -1
		push 1
		mov eax,1
		push 2
		mov ebx, ds:[0x6A9EC0]
		mov ebx, ds:[ebx+0x768]
		push ebx
		mov edx, 0x40D120
		call edx
		popad
		ret
	}
}

// 有参自定义汇编
DWORD __stdcall asmPutPlants2(LPVOID lpThreadParam) {
		
	PPutPlants p_param = (PPutPlants)lpThreadParam;
	UINT x = p_param->x;
	UINT y = p_param->y;
	UINT id = p_param->id;
	__asm {
		pushad
		push - 1
		push id
		mov eax, x
		push y
		mov ebx, dword ptr ds: [0x6A9EC0]
		mov ebx, dword ptr ds : [ebx + 0x768]
		push ebx
		mov edx, 0x40D120
		call edx
		popad
	}
	return 0;
}

// 带参数的注入
BOOL injectRemoteThread(LPVOID funcAddr, LPVOID paramAddr, DWORD paramSize) {

	// 函数所需空间
	LPVOID threadFuncAddr = ::VirtualAllocEx(g_process_handle, NULL, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	// 写入函数汇编
	::WriteProcessMemory(g_process_handle, threadFuncAddr, funcAddr, 4096, NULL);

	// 参数所需空间
	LPVOID threadParamAddr = ::VirtualAllocEx(g_process_handle, NULL, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	// 写入参数汇编
	::WriteProcessMemory(g_process_handle, threadParamAddr, paramAddr, paramSize, NULL);
	
	// 执行注入的函数和参数
	HANDLE remoteThreadRet = ::CreateRemoteThread(g_process_handle, NULL, 0, (LPTHREAD_START_ROUTINE)threadFuncAddr, threadParamAddr, 0, NULL);

	BOOL is_sucess = FALSE;
	if (remoteThreadRet) is_sucess = TRUE;

	DWORD threadWaitRet = ::WaitForSingleObject(remoteThreadRet, 0);

	if (WAIT_TIMEOUT == threadWaitRet)
		::CloseHandle(remoteThreadRet);
	else {
		::VirtualFreeEx(g_process_handle, threadFuncAddr, 0, MEM_RELEASE);
		::VirtualFreeEx(g_process_handle, threadParamAddr, 0, MEM_RELEASE);
	}

	return is_sucess;
}

// 组合框选择植物发生改变
void CPlantsVsZombiesWGDlg::OnCbnSelchangeCbxPlantsType()
{
	UpdateData(TRUE);
	UINT x = _ttoi(m_edit_plantX) - 1;
	UINT y = _ttoi(m_edit_plantY) - 1;
	UINT id = m_cbx_choose_plant.GetCurSel() + 1;
	PutPlants param = { x, y, id };

	if (!injectRemoteThread(asmPutPlants2, &param, sizeof(param)))
		::MessageBoxA(NULL, "安放植物失败", "错误", MB_OK);
}

// 范围随机种植
void CPlantsVsZombiesWGDlg::OnBnClickedBtnRandPutPlants()
{
	// 无参注入测试
	/*LPVOID threadAddr = ::VirtualAllocEx(g_process_handle, NULL, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	::WriteProcessMemory(g_process_handle, threadAddr, asmPutPlants, 4096, NULL);
	HANDLE remoteThread = ::CreateRemoteThread(g_process_handle, NULL, 0, (LPTHREAD_START_ROUTINE)threadAddr, NULL, 0, NULL);*/
	UpdateData(TRUE);
	UINT row = _ttoi(m_edit_plantX);
	UINT col = _ttoi(m_edit_plantY);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			PutPlants param = { i, j, rand() % 8 + 1 };
			if (!injectRemoteThread(asmPutPlants2, &param, sizeof(param))) {
				::MessageBoxA(NULL, "安放植物失败", "错误", MB_OK);
				return;
			}
			::Sleep(100);
		}
	}
}


void CPlantsVsZombiesWGDlg::OnClose()
{
	::TerminateThread(g_monitor_thread, 0);
	::CloseHandle(g_monitor_thread);
	::CloseHandle(g_process_handle);

	CDialogEx::OnClose();
}
