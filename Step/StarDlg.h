#pragma once


// CStarDlg dialog

class CStarDlg : public CDialog
{
	DECLARE_DYNAMIC(CStarDlg)

public:
	CStarDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CStarDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STARDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_x;
	double m_y;
	double m_length;
	double m_angle;
};
