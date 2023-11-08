// CSeconddlg.cpp : implementation file
//

#include "pch.h"
#include "test1.h"
#include "afxdialogex.h"
#include "CSeconddlg.h"


// CSeconddlg dialog

IMPLEMENT_DYNAMIC(CSeconddlg, CDialog)

CSeconddlg::CSeconddlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SECOND_DIALOG, pParent)
{

	/*m_nScrollPos = 0;
	m_nCurHeight = 0;*/
	m_bDragging = FALSE;
	Create(IDD_SECOND_DIALOG, pParent);
}

CSeconddlg::~CSeconddlg()
{
}

void CSeconddlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSeconddlg, CDialog)
	ON_WM_KILLFOCUS()
	ON_WM_SIZE()
	ON_WM_VSCROLL()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CSeconddlg message handlers


void CSeconddlg::OnKillFocus(CWnd* pNewWnd)
{
	CDialog::OnKillFocus(pNewWnd);

	// TODO: Add your message handler code here
	EndDrag();
}


void CSeconddlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_nCurHeight = cy;

	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_ALL;
	si.nMin = 0;
	si.nMax = m_rcOriginalRect.Height();
	si.nPage = cy;
	si.nPos = 0;
	SetScrollInfo(SB_VERT, &si, TRUE);
}


void CSeconddlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	int nDelta;
	int nMaxPos = m_rcOriginalRect.Height() - m_nCurHeight;

	switch (nSBCode)
	{
	case SB_LINEDOWN:
		if (m_nScrollPos >= nMaxPos)
			return;

		nDelta = min(max(nMaxPos / 20, 5), nMaxPos - m_nScrollPos);
		break;

	case SB_LINEUP:
		if (m_nScrollPos <= 0)
			return;
		nDelta = -min(max(nMaxPos / 20, 5), m_nScrollPos);
		break;
	case SB_PAGEDOWN:
		if (m_nScrollPos >= nMaxPos)
			return;
		nDelta = min(max(nMaxPos / 10, 5), nMaxPos - m_nScrollPos);
		break;
	case SB_THUMBTRACK:
	case SB_THUMBPOSITION:
		nDelta = (int)nPos - m_nScrollPos;
		break;

	case SB_PAGEUP:
		if (m_nScrollPos <= 0)
			return;
		nDelta = -min(max(nMaxPos / 10, 5), m_nScrollPos);
		break;

	default:
		return;
	}
	m_nScrollPos += nDelta;
	SetScrollPos(SB_VERT, m_nScrollPos, TRUE);
	ScrollWindow(0, -nDelta);
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CSeconddlg::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnCancel();
}


BOOL CSeconddlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	GetWindowRect(m_rcOriginalRect);

	// initial scroll position
	m_nScrollPos = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSeconddlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnOK();
}


void CSeconddlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bDragging)
	{
		int nDelta = m_ptDragPoint.y - point.y;
		m_ptDragPoint = point;

		int nNewPos = m_nScrollPos + nDelta;

		if (nNewPos < 0)
			nNewPos = 0;
		else if (nNewPos > m_rcOriginalRect.Height() - m_nCurHeight)
			nNewPos = m_rcOriginalRect.Height() - m_nCurHeight;

		nDelta = nNewPos - m_nScrollPos;
		m_nScrollPos = nNewPos;

		SetScrollPos(SB_VERT, m_nScrollPos, TRUE);
		ScrollWindow(0, -nDelta);
	}
	CDialog::OnMouseMove(nFlags, point);
}


BOOL CSeconddlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: Add your message handler code here and/or call default
	int nMaxPos = m_rcOriginalRect.Height() - m_nCurHeight;

	if (zDelta < 0)
	{
		if (m_nScrollPos < nMaxPos)
		{
			zDelta = min(max(nMaxPos / 20, 5), nMaxPos - m_nScrollPos);

			m_nScrollPos += zDelta;
			SetScrollPos(SB_VERT, m_nScrollPos, TRUE);
			ScrollWindow(0, -zDelta);
		}
	}
	else
	{
		if (m_nScrollPos > 0)
		{
			zDelta = -min(max(nMaxPos / 20, 5), m_nScrollPos);

			m_nScrollPos += zDelta;
			SetScrollPos(SB_VERT, m_nScrollPos, TRUE);
			ScrollWindow(0, -zDelta);
		}
	}
	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}


BOOL CSeconddlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default

	BOOL bRet = TRUE;

	if (nHitTest == HTCLIENT)
	{
		SetCursor(m_hCursor1);
		bRet = FALSE;
	}
	else
		bRet = CDialog::OnSetCursor(pWnd, nHitTest, message);

	return bRet;
}

void CSeconddlg::EndDrag()
{
	m_bDragging = FALSE;
	ReleaseCapture();
	SetCursor(m_hCursor1);
}