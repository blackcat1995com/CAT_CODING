#pragma once
#include "afxdialogex.h"


// CExportFuncDlg 对话框

class CExportFuncDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExportFuncDlg)

public:
	CExportFuncDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CExportFuncDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_EXPORT_FUN };
#endif

protected:
	virtual BOOL OnInitDialog();  // 重写初始化方法

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	BOOL GetExportDllFunc(WCHAR* szDllFileName, UINT* uNumOfExports, CHAR**& ppszFuncs);

	CString dll_name_path_str;  // 获取dll文件路径
	CComboBox m_cbx_ctrl_show_export_funcs;
	afx_msg void OnBnClickedBtnExportFuncSelected();
};
