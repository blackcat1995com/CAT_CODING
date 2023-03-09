// CDlgPage1.cpp: 实现文件
//

#include "pch.h"
#include "Demo.h"
#include "afxdialogex.h"
#include "CDlgPage1.h"


// CDlgPage1 对话框

IMPLEMENT_DYNAMIC(CDlgPage1, CDialogEx)

CDlgPage1::CDlgPage1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_PAGE1, pParent)
{

}

CDlgPage1::~CDlgPage1()
{
}

void CDlgPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgPage1, CDialogEx)
END_MESSAGE_MAP()


// CDlgPage1 消息处理程序
