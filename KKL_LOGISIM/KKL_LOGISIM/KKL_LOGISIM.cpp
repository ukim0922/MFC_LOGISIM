
// KKL_LOGISIM.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "KKL_LOGISIM.h"
#include "MainFrm.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKKL_LOGISIMApp

BEGIN_MESSAGE_MAP(CKKL_LOGISIMApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CKKL_LOGISIMApp::OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, &CKKL_LOGISIMApp::OnFileNew)
END_MESSAGE_MAP()


// CKKL_LOGISIMApp 생성

CKKL_LOGISIMApp::CKKL_LOGISIMApp()
{
	// TODO: 아래 응용 프로그램 ID 문자열을 고유 ID 문자열로 바꾸십시오(권장).
	// 문자열에 대한 서식: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("KKL_LOGISIM.AppID.NoVersion"));

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}

// 유일한 CKKL_LOGISIMApp 개체입니다.

CKKL_LOGISIMApp theApp;


// CKKL_LOGISIMApp 초기화

BOOL CKKL_LOGISIMApp::InitInstance()
{
	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// RichEdit 컨트롤을 사용하려면  AfxInitRichEdit2()가 있어야 합니다.	
	// AfxInitRichEdit2();

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 응용 프로그램 마법사에서 생성된 응용 프로그램"));


	// 주 창을 만들기 위해 이 코드에서는 새 프레임 창 개체를
	// 만든 다음 이를 응용 프로그램의 주 창 개체로 설정합니다.
	CMDIFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// 주 MDI 프레임 창을 만듭니다.
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// 공유 MDI 메뉴 및 액셀러레이터 키 테이블의 로드를 시도합니다.
	//TODO: 추가 멤버 변수를 추가하고 응용 프로그램에 필요한 추가 메뉴 형식에 대한
	//	호출을 로드합니다.
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_KKL_LOGISIMTYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_KKL_LOGISIMTYPE));




	// 주 창이 초기화되었으므로 이를 표시하고 업데이트합니다.
	pFrame->ShowWindow(m_nCmdShow);
	pFrame->UpdateWindow();

	return TRUE;
}

int CKKL_LOGISIMApp::ExitInstance()
{
	//TODO: 추가한 추가 리소스를 처리합니다.
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	return CWinApp::ExitInstance();
}

// CKKL_LOGISIMApp 메시지 처리기

void CKKL_LOGISIMApp::OnFileNew() 
{
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);
	// 새 MDI 자식 창을 만듭니다.
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_KKL_LOGISIMTYPE, m_hMDIMenu, m_hMDIAccel);
}

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// 대화 상자를 실행하기 위한 응용 프로그램 명령입니다.
void CKKL_LOGISIMApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CKKL_LOGISIMApp 메시지 처리기



