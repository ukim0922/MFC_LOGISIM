#pragma once



// CTreeFormView �� ���Դϴ�.

class CTreeFormView : public CFormView
{
	DECLARE_DYNCREATE(CTreeFormView)

protected:
	CTreeFormView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
};


