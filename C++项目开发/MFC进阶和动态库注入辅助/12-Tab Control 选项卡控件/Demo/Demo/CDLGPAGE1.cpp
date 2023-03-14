// CDLGPAGE1.cpp: 实现文件
//

#include "pch.h"
#include "Demo.h"
#include "afxdialogex.h"
#include "CDLGPAGE1.h"


// CDLGPAGE1 对话框

IMPLEMENT_DYNAMIC(CDLGPAGE1, CDialogEx)

CDLGPAGE1::CDLGPAGE1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_PAGE1, pParent)
{

}

CDLGPAGE1::~CDLGPAGE1()
{
}

void CDLGPAGE1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDLGPAGE1, CDialogEx)
END_MESSAGE_MAP()


// CDLGPAGE1 消息处理程序
