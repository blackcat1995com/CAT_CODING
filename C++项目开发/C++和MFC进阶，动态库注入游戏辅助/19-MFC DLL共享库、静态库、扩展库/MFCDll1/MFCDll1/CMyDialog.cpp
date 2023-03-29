// CMyDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFCDll1.h"
#include "afxdialogex.h"
#include "CMyDialog.h"


// CMyDialog 对话框

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
END_MESSAGE_MAP()


// CMyDialog 消息处理程序
__declspec(dllexport) void ShowDialog() {
	CMyDialog dlg;
	dlg.DoModal();
}