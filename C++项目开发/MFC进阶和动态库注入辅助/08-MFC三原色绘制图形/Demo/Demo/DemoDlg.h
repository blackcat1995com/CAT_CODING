﻿
// DemoDlg.h: 头文件
//

#pragma once


// CDemoDlg 对话框
class CDemoDlg : public CDialogEx
{
// 构造
public:
	CDemoDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMO_DIALOG };
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
	CButton m_cbx_red;
	CButton m_cbx_green;
	CButton m_cbx_blue;
	CButton m_radio_rect;
	CButton m_radio_circle;
	afx_msg void OnBnClickedCbxRed();
	afx_msg void OnBnClickedCbxGreen();
	afx_msg void OnBnClickedCbxBlue();
	afx_msg void OnBnClickedRadioRect();
	afx_msg void OnBnClickedRadioCircle();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
