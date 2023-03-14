#pragma once
#include "afxdialogex.h"


// CDLGPAGE2 对话框

class CDLGPAGE2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDLGPAGE2)

public:
	CDLGPAGE2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDLGPAGE2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_PAGE2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
