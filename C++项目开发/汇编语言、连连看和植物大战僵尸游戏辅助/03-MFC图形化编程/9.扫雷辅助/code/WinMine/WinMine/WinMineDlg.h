
// WinMineDlg.h: 头文件
//

#pragma once


// CWinMineDlg 对话框
class CWinMineDlg : public CDialogEx
{
// 构造
public:
	CWinMineDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WINMINE_DIALOG };
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
	afx_msg void OnBnClickedBtnCj();
	afx_msg void OnBnClickedBtnZj();
	afx_msg void OnBnClickedBtnGj();
	afx_msg void OnBnClickedBtnZdy();
	afx_msg void OnBnClickedBtnReadChess();
	afx_msg void OnBnClickedBtnAutoClear();
private:
	CString m_edit_show_data;
};
