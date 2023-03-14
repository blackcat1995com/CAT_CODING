#pragma once
#include "afxdialogex.h"


// CDLGPAGE1 对话框

class CDLGPAGE1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDLGPAGE1)

public:
	CDLGPAGE1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDLGPAGE1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_PAGE1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
