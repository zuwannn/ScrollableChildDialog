#pragma once
#include "afxdialogex.h"


// CSeconddlg dialog

class CSeconddlg : public CDialog
{
	DECLARE_DYNAMIC(CSeconddlg)

public:
	CSeconddlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSeconddlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SECOND_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	HCURSOR m_hCursor1;
	HCURSOR m_hCurSor2;
	CRect m_rcOriginalRect;
	BOOL m_bDragging;
	CPoint m_ptDragPoint;
	int m_nScrollPos;
	int m_nCurHeight;
};
