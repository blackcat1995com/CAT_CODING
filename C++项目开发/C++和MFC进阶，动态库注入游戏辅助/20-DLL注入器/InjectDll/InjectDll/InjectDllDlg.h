
// InjectDllDlg.h: 头文件
//

#pragma once


// CInjectDllDlg 对话框
class CInjectDllDlg : public CDialogEx
{
// 构造
public:
	CInjectDllDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INJECTDLL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_export_func_str;
	BOOL InjectRemoteDll(CString full_dll_path, CString func_name, LPCWSTR dll_name_str, DWORD dwPid, BOOL isInject = TRUE);
	BOOL CreateRemoteDll(const CHAR* sz_full_dll_path, const CHAR* sz_func_name, LPCWSTR dll_name_str, DWORD dwPid, BOOL isInject = TRUE);
	BOOL ListProcessModules(DWORD dwPid);
	afx_msg void OnBnClickedBtnSelectProcess();
	CString m_edit_show_process_value;
	CEdit m_edit_ctrl_show_process;
	afx_msg void OnBnClickedBtnListModules();
	CString m_edit_show_process_modules;
	afx_msg void OnBnClickedButton3();
	CListCtrl m_list_ctrl_show_dlls;
	afx_msg void OnBnClickedBtnLoadDll();
	afx_msg void OnBnClickedBtnEnableDll();
	afx_msg void OnBnClickedBtnRemoveDll();
	afx_msg void OnBnClickedBtnClearDll();
	afx_msg void OnBnClickedBtnSetExportFunc();
	afx_msg void OnBnClickedBtnInjectDll();
	afx_msg void OnBnClickedBtnUnloadDll();
};
