#pragma once
#include "afxdialogex.h"


// CMain dialog

class CMain : public CDialog
{
	DECLARE_DYNAMIC(CMain)

public:
	CMain(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMain();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
