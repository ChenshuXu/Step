// LineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Step.h"
#include "LineDlg.h"
#include "afxdialogex.h"


// CLineDlg dialog

IMPLEMENT_DYNAMIC(CLineDlg, CDialog)

CLineDlg::CLineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LINEDLG, pParent)
	, m_fmx(0)
	, m_fmy(0)
	, m_tox(0)
	, m_toy(0)
{

}

CLineDlg::~CLineDlg()
{
}

void CLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FMX, m_fmx);
	DDX_Text(pDX, IDC_FMY, m_fmy);
	DDX_Text(pDX, IDC_TOX, m_tox);
	DDX_Text(pDX, IDC_TOY, m_toy);
}


BEGIN_MESSAGE_MAP(CLineDlg, CDialog)
END_MESSAGE_MAP()


// CLineDlg message handlers
