
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "Logisim_KKL.h"
#include "Logisim_KKLDoc.h"
#include "Logisim_KKLView.h"
#include "TreeFormView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("���� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	//CRect rect;
	//GetClientRect(rect);
	//CSize size1(MulDiv(rect.Width(), 20, 100), ::GetSystemMetrics(SM_CYSCREEN)); // ��(30%)
	//CSize size2(MulDiv(rect.Width(), 80, 100), ::GetSystemMetrics(SM_CYSCREEN)); // ��(70%)
	//
	// create a splitter with 1 row, 2 columns
	if (!m_wndSplitter.CreateStatic(this, 1, 2)) {
		TRACE0("Failed to CreateStatic Splitter \n");
		return FALSE;
	}
	// ����ڰ� ���� CFormView1 �� ������ ��ġ�մϴ�...
	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CTreeFormView), CSize(300,0), pContext)) {
		TRACE0("Failed to create CFormView1 pane \n");
		return FALSE;
	}
	// ����ڰ� ���� CFormView2 �� ������ ��ġ�մϴ�...
	if (!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CLogisim_KKLView), CSize(0,0), pContext)) {
		TRACE0("Failed to create CFormView2 pane \n");
		return FALSE;
	}
	SetActiveView((CView *)m_wndSplitter.GetPane(0, 0));
	return TRUE;
	
	

}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �޽��� ó����

