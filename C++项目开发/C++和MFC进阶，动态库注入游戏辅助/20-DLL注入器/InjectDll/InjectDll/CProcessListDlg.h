#pragma once
#include "afxdialogex.h"


// CProcessListDlg 对话框

class CProcessListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProcessListDlg)

public:
	CProcessListDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CProcessListDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_PROCESS_LIST };
#endif

protected:
	virtual BOOL OnInitDialog();  // 重写初始化方法
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void ListProcess(BOOL has_wnd = FALSE);
	HWND GetHwndByProcessId(DWORD dwProcessId);
	CListCtrl m_list_ctrl_show_process;
	afx_msg void OnBnClickedBtnGetProcessList();
	afx_msg void OnBnClickedBtnGetWndProcessList();
	afx_msg void OnBnClickedBtnChooseAProcess();
	afx_msg void OnBnClickedBtnCloseProcessListDlg();
};
