// StarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Step.h"
#include "StarDlg.h"
#include "afxdialogex.h"


// CStarDlg dialog

IMPLEMENT_DYNAMIC(CStarDlg, CDialog)

CStarDlg::CStarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_STARDLG, pParent)
	, m_x(0)
	, m_y(0)
	, m_length(0)
	, m_angle(0)
{

}

CStarDlg::~CStarDlg()
{
}

void CStarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LOCX, m_x);
	DDX_Text(pDX, IDC_LOCY, m_y);
	DDX_Text(pDX, IDC_LENGTH, m_length);
	DDX_Text(pDX, IDC_ROTATE, m_angle);
}


BEGIN_MESSAGE_MAP(CStarDlg, CDialog)
END_MESSAGE_MAP()


// CStarDlg message handlers
