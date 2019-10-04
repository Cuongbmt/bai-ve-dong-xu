
// vdxView.h : interface of the CvdxView class
//

#pragma once
#include"Dongxu.h"
#include"Hinhtron.h"

class CvdxView : public CView
{
protected: // create from serialization only
	CvdxView();
	DECLARE_DYNCREATE(CvdxView)

// Attributes
public:
	CvdxDoc* GetDocument() const;
	
// Operations
public:
	Hinhtron Dongxu1,Dongxu2;
	Dongxu SPDongxu1, SPDongxu2;
	CPoint p1, p2;
	int S, P;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CvdxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in vdxView.cpp
inline CvdxDoc* CvdxView::GetDocument() const
   { return reinterpret_cast<CvdxDoc*>(m_pDocument); }
#endif

