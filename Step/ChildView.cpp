
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Step.h"
#include "ChildView.h"
#include "LineDlg.h"
#include "StarDlg.h"

#define _USE_MATH_DEFINES
#include <cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_linefmx = 0.5;
	m_linefmy = 0.5;
	m_linetox = 0.2;
	m_linetoy = 0.55;

	mX = 0;
	mY = 0;
	mLength = 0.5;
	mAngle = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_SAVEBMPFILE, &CChildView::OnFileSavebmpfile)
	ON_COMMAND(ID_STEPSTUFF_LINEENDTO0, &CChildView::OnStepstuffLineendto0)
	ON_COMMAND(ID_STEPSTUFF_LINEDIALOG, &CChildView::OnStepstuffLinedialog)
	ON_COMMAND(ID_STEPSTUFF_SEVENPOINTSTARDIALOG, &CChildView::OnStepstuffSevenpointstardialog)
	ON_COMMAND(ID_STEPSTUFF_ROTATE15DEGREES, &CChildView::OnStepstuffRotate15degrees)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!COpenGLWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}



void CChildView::OnGLDraw(CDC* pDC)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int width, height;
	GetSize(width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, // left
		1.0, // right
		0.0, // bottom
		GLdouble(height) / GLdouble(width), // top
		1.0, // near
		-1.0); // far

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	glColor3d(1., 0., 0.);

	/*
	glBegin(GL_POLYGON);
	glVertex2d(0.25, 0.25);
	glVertex2d(0.75, 0.25);
	glVertex2d(0.75, 0.75);
	glVertex2d(0.25, 0.75);
	glEnd();
	*/
	glBegin(GL_LINES);
	glVertex2d(0.1, 0.1);
	glVertex2d(0.8, 0.22);
	glVertex2d(0.78, 0.9);
	glVertex2d(0.2, 0.9);
	glEnd();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor3d(0., 0., 1.);

	glBegin(GL_LINES);
	glVertex2d(m_linefmx, m_linefmy);
	glVertex2d(m_linetox, m_linetoy);
	glEnd();
	

	// calculate the points
	long double internal_angle = 2 * M_PI / 7;
	long double rect_internal_angle = M_PI / 2;
	long double oa = (mLength / 2) / sin(77.143 / 180 * M_PI);
	long double rad_angle = mAngle * M_PI / 180;

	// Heptagram
	mAx = sin(rad_angle) * oa;
	mAy = cos(rad_angle) * oa;

	mBx = sin(internal_angle + rad_angle) * oa;
	mBy = cos(internal_angle + rad_angle) * oa;

	mCx = sin(internal_angle * 2 + rad_angle) * oa;
	mCy = cos(internal_angle * 2 + rad_angle) * oa;

	mDx = sin(internal_angle * 3 + rad_angle) * oa;
	mDy = cos(internal_angle * 3 + rad_angle) * oa;

	mEx = sin(internal_angle * 4 + rad_angle) * oa;
	mEy = cos(internal_angle * 4 + rad_angle) * oa;

	mFx = sin(internal_angle * 5 + rad_angle) * oa;
	mFy = cos(internal_angle * 5 + rad_angle) * oa;

	mGx = sin(internal_angle * 6 + rad_angle) * oa;
	mGy = cos(internal_angle * 6 + rad_angle) * oa;

	// Rectangular
	long double oh = sqrt((mLength/2)*(mLength/2) + oa * oa);
	double mHx1 = (mLength / 2);
	double mHy1 = oa;
	mHx = mHx1 * cos(-rad_angle) - sin(-rad_angle) * mHy1;
	mHy = mHx1 * sin(-rad_angle) + cos(-rad_angle) * mHy1;

	double mIx1 = (mLength / 2);
	double mIy1 = -oa * cos(internal_angle / 2);
	mIx = cos(-rad_angle) * mIx1 - sin(-rad_angle) * mIy1;
	mIy = sin(-rad_angle) * mIx1 + cos(-rad_angle) * mIy1;

	double mJx1 = -(mLength / 2);
	double mJy1 = -oa * cos(internal_angle / 2);
	mJx = cos(-rad_angle) * mJx1 - sin(-rad_angle) * mJy1;
	mJy = sin(-rad_angle) * mJx1 + cos(-rad_angle) * mJy1;

	double mKx1 = -(mLength / 2);
	double mKy1 = oa;
	mKx = mKx1 * cos(-rad_angle) - sin(-rad_angle) * mKy1;
	mKy = mKx1 * sin(-rad_angle) + cos(-rad_angle) * mKy1;

	
	mAx = mAx + 0.5 + mX;
	mAy = mAy + 0.5 + mY;
	mBx = mBx + 0.5 + mX;
	mBy = mBy + 0.5 + mY;
	mCx = mCx + 0.5 + mX;
	mCy = mCy + 0.5 + mY;
	mDx = mDx + 0.5 + mX;
	mDy = mDy + 0.5 + mY;
	mEx = mEx + 0.5 + mX;
	mEy = mEy + 0.5 + mY;
	mFx = mFx + 0.5 + mX;
	mFy = mFy + 0.5 + mY;
	mGx = mGx + 0.5 + mX;
	mGy = mGy + 0.5 + mY;
	mHx = mHx + 0.5 + mX;
	mHy = mHy + 0.5 + mY;
	mIx = mIx + 0.5 + mX;
	mIy = mIy + 0.5 + mY;
	mJx = mJx + 0.5 + mX;
	mJy = mJy + 0.5 + mY;
	mKx = mKx + 0.5 + mX;
	mKy = mKy + 0.5 + mY;
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor3d(0., 1., 0.);

	glBegin(GL_LINES);
	// line AD
	glVertex2d(mAx, mAy);
	glVertex2d(mDx, mDy);
	// Line AE
	glVertex2d(mAx, mAy);
	glVertex2d(mEx, mEy);
	// Line BF
	glVertex2d(mBx, mBy);
	glVertex2d(mFx, mFy);
	// Line BE
	glVertex2d(mBx, mBy);
	glVertex2d(mEx, mEy);
	// Line CG
	glVertex2d(mCx, mCy);
	glVertex2d(mGx, mGy);
	// Line CF
	glVertex2d(mCx, mCy);
	glVertex2d(mFx, mFy);
	// Line DG
	glVertex2d(mDx, mDy);
	glVertex2d(mGx, mGy);
	glEnd();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor3d(1., 0., 0.);

	glBegin(GL_LINES);
	// Line HI
	glVertex2d(mHx, mHy);
	glVertex2d(mIx, mIy);
	// Line IJ
	glVertex2d(mIx, mIy);
	glVertex2d(mJx, mJy);
	// Line JK
	glVertex2d(mJx, mJy);
	glVertex2d(mKx, mKy);
	// Line KH
	glVertex2d(mKx, mKy);
	glVertex2d(mHx, mHy);
	glEnd();

}


void CChildView::OnFileSavebmpfile()
{
	// TODO: Add your command handler code here
	OnSaveImage();
}


void CChildView::OnStepstuffLineendto0()
{
	// TODO: Add your command handler code here
	m_linetox = 0.1;
	m_linetoy = 0.1;

	Invalidate();
}


void CChildView::OnStepstuffLinedialog()
{
	// TODO: Add your command handler code here
	CLineDlg dlg;

	dlg.m_fmx = m_linefmx;
	dlg.m_fmy = m_linefmy;
	dlg.m_tox = m_linetox;
	dlg.m_toy = m_linetoy;

	if (dlg.DoModal() == IDOK)
	{
		m_linefmx = dlg.m_fmx;
		m_linefmy = dlg.m_fmy;
		m_linetox = dlg.m_tox;
		m_linetoy = dlg.m_toy;

		Invalidate();
	}
}


void CChildView::OnStepstuffSevenpointstardialog()
{
	// TODO: Add your command handler code here
	CStarDlg dlg;

	dlg.m_x = mX;
	dlg.m_y = mY;
	dlg.m_length = mLength;
	dlg.m_angle = mAngle;

	if (dlg.DoModal() == IDOK)
	{
		mX = dlg.m_x;
		mY = dlg.m_y;
		mLength = dlg.m_length;
		mAngle = dlg.m_angle;

		Invalidate();
	}
}


void CChildView::OnStepstuffRotate15degrees()
{
	// TODO: Add your command handler code here
	mAngle += 15;

	Invalidate();
}
