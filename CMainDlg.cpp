// CMainDlg.cpp : implementation file
//

#include "pch.h"
#include "test1.h"
#include "afxdialogex.h"
#include "CMainDlg.h"


// CMain dialog

IMPLEMENT_DYNAMIC(CMain, CDialog)

CMain::CMain(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MAIN_DIALOG, pParent)
{

}

CMain::~CMain()
{
}

void CMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMain, CDialog)
END_MESSAGE_MAP()


// CMain message handlers
