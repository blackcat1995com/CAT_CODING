
// PlantsVsZombiesWGDlg.h: 头文件
//

#pragma once


// CPlantsVsZombiesWGDlg 对话框
class CPlantsVsZombiesWGDlg : public CDialogEx
{
// 构造
public:
	CPlantsVsZombiesWGDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLANTSVSZOMBIESWG_DIALOG };
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
	virtual void OnOK();
public:
	CString m_edit_sun_value; 
	afx_msg void OnBnClickedBtnSetSun();
	CString m_edit_money_value;
	afx_msg void OnBnClickedBtnSetmoney();
	CButton m_check_auto_collect;
	afx_msg void OnBnClickedCheckAutoCollect();
	CButton m_check_kill;
	afx_msg void OnBnClickedCheckKill();
	CButton m_check_plabts_no_death;
	afx_msg void OnBnClickedCheckPlantsNodeath();
	CButton m_check_run_inbg;
	afx_msg void OnBnClickedCheckRunInbg();
	afx_msg void OnBnClickedCheckPlantsNocd();
	CButton m_check_plants_nocd;
	CButton m_check_bigmouse_nocd;
	afx_msg void OnBnClickedCheckBigmouseNocd();
	afx_msg void OnBnClickedBtnRandPutPlants();
	CString m_edit_plantX;
	CString m_edit_plantY;
	afx_msg void OnCbnSelchangeCbxPlantsType();

	CComboBox m_cbx_choose_plant;
	afx_msg void OnClose();
};
