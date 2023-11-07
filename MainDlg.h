
// MainDlg.h : header file
//
//#if !defined(AFX_P01DLG_H__8EE17CE4_7F23_4D44_8956_41E8FCDE1773__INCLUDED_)
//#define AFX_P01DLG_H__8EE17CE4_7F23_4D44_8956_41E8FCDE1773__INCLUDED_
//
//#if _MSC_VER > 1000
//#pragma once
//#endif // _MSC_VER > 1000
//

#include "CSeconddlg.h"
#pragma once


// CMainDlg dialog
class CMainDlg : public CDialog
{
// Construction
public:
	CMainDlg(CWnd* pParent = nullptr);	// standard constructor

	~CMainDlg() {
		delete m_pdlgScroll;
	}
	CSeconddlg* m_pdlgScroll;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
//#endif