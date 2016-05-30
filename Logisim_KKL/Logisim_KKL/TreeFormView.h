#pragma once



// CTreeFormView 폼 뷰입니다.

class CTreeFormView : public CFormView
{
	DECLARE_DYNCREATE(CTreeFormView)

protected:
	CTreeFormView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CTreeFormView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TREEFORMVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
};


