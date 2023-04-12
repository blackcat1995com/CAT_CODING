// CExportFuncDlg.cpp: 实现文件
//

#include "pch.h"
#include "InjectDll.h"
#include "afxdialogex.h"
#include "CExportFuncDlg.h"
#include "InjectDllDlg.h"

#include <dbghelp.h>
#pragma comment(lib, "Dbghelp.lib")

// CExportFuncDlg 对话框

IMPLEMENT_DYNAMIC(CExportFuncDlg, CDialogEx)

CExportFuncDlg::CExportFuncDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_EXPORT_FUN, pParent)
{

}

CExportFuncDlg::~CExportFuncDlg()
{
}

void CExportFuncDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CBX_SELECT_EXPORT_FUNC, m_cbx_ctrl_show_export_funcs);
}


BEGIN_MESSAGE_MAP(CExportFuncDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_EXPORT_FUNC_SELECTED, &CExportFuncDlg::OnBnClickedBtnExportFuncSelected)
END_MESSAGE_MAP()


// ---------------------------------------

BOOL CExportFuncDlg::GetExportDllFunc(WCHAR* szDllFileName, UINT* uNumOfExports, CHAR**& ppszFuncs) {

	// 创建文件句柄
	HANDLE hFile = CreateFile(szDllFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		AfxMessageBox(_T("hFile创建失败！"));
		return FALSE;
	}

	// 创建文件映射句柄
	HANDLE hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
	if (hFileMapping == INVALID_HANDLE_VALUE) {
		AfxMessageBox(_T("hFileMapping创建失败！"));
		CloseHandle(hFile);
		return FALSE;
	}

	// 将文件映射到内存
	LPVOID lpFileBaseAddr = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0);
	if (!lpFileBaseAddr) {
		AfxMessageBox(_T("lpFileBaseAddr创建失败！"));
		CloseHandle(hFileMapping);
		CloseHandle(hFile);
		return FALSE;
	}

	// PE文件NT头 由DOS头偏移指出
	PIMAGE_DOS_HEADER pImg_Dos_Header = (PIMAGE_DOS_HEADER)lpFileBaseAddr;
	PIMAGE_NT_HEADERS pImg_NT_Headers = (PIMAGE_NT_HEADERS)((LONG)pImg_Dos_Header + (LONG)pImg_Dos_Header->e_lfanew);

	// Dll导出文件内容记录在导出表上
	PIMAGE_EXPORT_DIRECTORY pImg_Export_Dir = (PIMAGE_EXPORT_DIRECTORY)pImg_NT_Headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;

	pImg_Export_Dir = (PIMAGE_EXPORT_DIRECTORY)ImageRvaToVa(pImg_NT_Headers, pImg_Dos_Header, (DWORD)pImg_Export_Dir, 0);

	if (!pImg_Export_Dir) {
		AfxMessageBox(_T("pImg_Export_Dir创建失败！"));
		UnmapViewOfFile(lpFileBaseAddr);
		CloseHandle(hFileMapping);
		CloseHandle(hFile);
		return FALSE;
	}

	DWORD** ppdwNames = (DWORD**)pImg_Export_Dir->AddressOfNames;
	ppdwNames = (DWORD**)ImageRvaToVa(pImg_NT_Headers, pImg_Dos_Header, (DWORD)ppdwNames, 0);
	
	if (!ppdwNames) {
		AfxMessageBox(_T("ppdwNames创建失败！"));
		UnmapViewOfFile(lpFileBaseAddr);
		CloseHandle(hFileMapping);
		CloseHandle(hFile);
		return FALSE;
	}
	
	*uNumOfExports = pImg_Export_Dir->NumberOfNames;
	ppszFuncs = new CHAR * [*uNumOfExports];

	for (int i = 0; i < *uNumOfExports; i++) {
		CHAR* szFunc = (PSTR)ImageRvaToVa(pImg_NT_Headers, pImg_Dos_Header, (DWORD)*ppdwNames, 0);
		ppszFuncs[i] = new CHAR[strlen(szFunc) + 1];
		strcpy(ppszFuncs[i], szFunc);
		ppdwNames++;
	}

	UnmapViewOfFile(lpFileBaseAddr);
	CloseHandle(hFileMapping);
	CloseHandle(hFile);

	return TRUE;
}

BOOL CExportFuncDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	UINT uNumOfExports = 0;	// 导出函数数量
	CHAR** ppszFuncs;  // 指向导出函数的指针 *一级指针 **二级指针 指向函数的指针

	GetExportDllFunc(dll_name_path_str.GetBuffer(), &uNumOfExports, ppszFuncs);

	CString str;
	for (int i = 0; i < uNumOfExports; i++) {
		str.Format(_T("%S"), ppszFuncs[i]);
		m_cbx_ctrl_show_export_funcs.AddString(str);
	}

	for (int i = 0; i < uNumOfExports; i++) {
		delete [] ppszFuncs[i];
	}

	delete[] ppszFuncs;

	return TRUE;
}


// 点击确定按钮，将导出函数显示到主界面 列表空间 下标 为2 这一列
void CExportFuncDlg::OnBnClickedBtnExportFuncSelected()
{
	int cbx_sel_idx = m_cbx_ctrl_show_export_funcs.GetCurSel();

	if (cbx_sel_idx < 0) {
		AfxMessageBox(_T("请选择要调用的函数！"));
		return;
	}

	CString str;
	m_cbx_ctrl_show_export_funcs.GetLBText(cbx_sel_idx, str);

	CInjectDllDlg* pDlg = (CInjectDllDlg*)(AfxGetApp()->GetMainWnd());
	pDlg->m_export_func_str = str;

	int pDlg_list_sel_idx = pDlg->m_list_ctrl_show_dlls.GetNextItem(-1, LVIS_SELECTED);
	pDlg->m_list_ctrl_show_dlls.SetItemText(pDlg_list_sel_idx, 2, str);

	OnOK();
}
