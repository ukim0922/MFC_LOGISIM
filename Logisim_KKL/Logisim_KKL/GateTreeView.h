#pragma once

#include "stdafx.h"
// CGateTreeView ���Դϴ�.

class CGateTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CGateTreeView)

protected:
	CGateTreeView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CGateTreeView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg void OnTvnSelchanging(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
};


