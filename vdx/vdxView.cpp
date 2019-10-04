
// vdxView.cpp : implementation of the CvdxView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "vdx.h"
#endif

#include "vdxDoc.h"
#include "vdxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CvdxView

IMPLEMENT_DYNCREATE(CvdxView, CView)

BEGIN_MESSAGE_MAP(CvdxView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CvdxView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CvdxView construction/destruction

CvdxView::CvdxView()
{
	// TODO: add construction code here
	Dongxu1.thietlap(200, 100, 300, 200);
	Dongxu2.thietlap(230, 130, 270, 170);

}

CvdxView::~CvdxView()
{
}

BOOL CvdxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CvdxView drawing

void CvdxView::OnDraw(CDC* /*pDC*/)
{
	CvdxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	 CClientDC pDC(this);
	

	
	
	
	// TODO: add draw code for native data here
}


// CvdxView printing


void CvdxView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CvdxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CvdxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CvdxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CvdxView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CvdxView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CvdxView diagnostics

#ifdef _DEBUG
void CvdxView::AssertValid() const
{
	CView::AssertValid();
}

void CvdxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CvdxDoc* CvdxView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CvdxDoc)));
	return (CvdxDoc*)m_pDocument;
}
#endif //_DEBUG


// CvdxView message handlers


void CvdxView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//int down = 1;

	p1.x = point.x;
	p1.y = point.y;

	

	CView::OnLButtonDown(nFlags, point);
}


void CvdxView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p2.x = point.x;
	p2.y = point.y;
	CClientDC pDC(this);

	/*CPen *pen4;
	pen4 = new CPen(PS_SOLID, 1, RGB(255, 255, 25));
	CPen *oldpen4;
	oldpen4 = pDC.SelectObject(pen4);//chon but ve*/

	Dongxu1.thietlap(p1.x, p1.y, p2.x, p2.y);
	Dongxu2.thietlap(p1.x+30, p1.y+30, p2.x-30, p2.y-30);
	Dongxu1.vehinh(&pDC);
	Dongxu2.vehinh(&pDC);
	
	SPDongxu1.thietlap(p1.x, p1.y, p2.x, p2.y);
	SPDongxu2.thietlap(p1.x + 30, p1.y + 30, p2.x - 30, p2.y - 30);

	
	
	CString S, P;
	 S.Format(_T("  Dien tich dong xu la : %f"), SPDongxu1.dientich() - SPDongxu2.dientich());
	P.Format(_T("  Chu vi dong xu la : %f"), SPDongxu1.chuvi() - SPDongxu2.chuvi());
	pDC.TextOutW(50, 20, S);
	pDC.TextOutW(300, 20, P);
	CView::OnLButtonUp(nFlags, point);
}
