#pragma once
#include "afxdialogex.h"


// CMyDialog 对话框

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMyDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	// 重写初始化方法
	virtual BOOL OnInitDialog();
public:
	CString m_editv_show_wnd_title;
	afx_msg void OnBnClickedBtnGetWndTitle();
	CString m_editv_show_process_handle;
	afx_msg void OnBnClickedBtnGetProcessHandle();
	afx_msg void OnBnClickedBtnMaxWnd();
	afx_msg void OnBnClickedBtnMinWnd();
	afx_msg void OnBnClickedBtnStartGame();
	afx_msg void OnBnClickedBtnReadCoin();
	CString m_editv_show_read_coin;
	afx_msg void OnBnClickedBtnChangeCoin();
	CString m_editv_change_coin;
};

extern "C" __declspec(dllexport) void ShowDialog();