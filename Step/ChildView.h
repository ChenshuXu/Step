
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "graphics/OpenGLWnd.h"

using namespace std;
using namespace Gdiplus;

// CChildView window

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	void OnGLDraw(CDC* pDC);
	afx_msg void OnFileSavebmpfile();

private:
	double m_linefmx;
	double m_linefmy;
	double m_linetox;
	double m_linetoy;

	double mX;
	double mY;
	double mLength;
	double mAngle;

	double mAx;
	double mAy;
	double mBx;
	double mBy;
	double mCx;
	double mCy;
	double mDx;
	double mDy;
	double mEx;
	double mEy;
	double mFx;
	double mFy;
	double mGx;
	double mGy;
	double mHx;
	double mHy;
	double mIx;
	double mIy;
	double mJx;
	double mJy;
	double mKx;
	double mKy;
	
public:
	afx_msg void OnStepstuffLineendto0();
	afx_msg void OnStepstuffLinedialog();
	afx_msg void OnStepstuffSevenpointstardialog();
	afx_msg void OnStepstuffRotate15degrees();
};

