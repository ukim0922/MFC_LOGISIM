
// Logisim_KKLDoc.cpp : CLogisim_KKLDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Logisim_KKL.h"
#endif

#include "Logisim_KKLDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLogisim_KKLDoc

IMPLEMENT_DYNCREATE(CLogisim_KKLDoc, CDocument)

BEGIN_MESSAGE_MAP(CLogisim_KKLDoc, CDocument)
END_MESSAGE_MAP()


// CLogisim_KKLDoc ����/�Ҹ�

CLogisim_KKLDoc::CLogisim_KKLDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	m_Cur = NULL;
}

CLogisim_KKLDoc::~CLogisim_KKLDoc()
{
}

BOOL CLogisim_KKLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CLogisim_KKLDoc serialization

void CLogisim_KKLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		POSITION pos = m_Objs.GetHeadPosition();
		while (pos != NULL) {
			((LogicEngine*)m_Objs.GetNext(pos))->serialize(ar);
		}

	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�. 
		int Type;
		LogicEngine *obj = NULL;
		do {
			ar >> Type;

			switch (Type) {
			case AND:
				obj = new ANDGATE(); break;
			case OR:
				obj = new ORGATE(); break;
			case NOT:
				obj = new NOTGATE(); break;
			case NOR:
				obj = new NORGATE(); break;
			case NAND:
				obj = new NANDGATE(); break;
			case XOR:
				obj = new XORGATE(); break;
			/*case D_FF:
				obj = new DFF(); break;
			case T_FF:
				obj = new TFF(); break;
			case JK_FF:
				obj = new JKFF(); break;*/
			}

			obj->deserialize(ar);
			m_Objs.AddTail(obj);

		} while (!ar.IsBufferEmpty());

		((CFrameWnd*)AfxGetMainWnd())->GetActiveView()->Invalidate(TRUE);
	}
}

CPtrList& CLogisim_KKLDoc::getLogicEngine() {
	return m_Objs;
}


ANDGATE* CLogisim_KKLDoc::getAndGates(bool bNew)
{
	if (bNew) {
		m_Cur = new ANDGATE();
		m_Objs.AddTail(m_Cur);

		return (ANDGATE*)m_Cur;
	}
	if (m_Cur != NULL && m_Cur->gatenumber == AND) {
		return (ANDGATE*)m_Cur;
	}

	return NULL;
}
ORGATE* CLogisim_KKLDoc::getOrGates(bool bNew)
{
	if (bNew) {
		m_Cur = new ORGATE();
		m_Objs.AddTail(m_Cur);

		return (ORGATE*)m_Cur;
	}
	if (m_Cur != NULL && m_Cur->gatenumber == OR) {
		return (ORGATE*)m_Cur;
	}

	return NULL;
}
NOTGATE* CLogisim_KKLDoc::getNotGates(bool bNew)
{
	if (bNew) {
		m_Cur = new NOTGATE();
		m_Objs.AddTail(m_Cur);

		return (NOTGATE*)m_Cur;
	}
	if (m_Cur != NULL && m_Cur->gatenumber == NOT) {
		return (NOTGATE*)m_Cur;
	}

	return NULL;
}
NORGATE* CLogisim_KKLDoc::getNorGates(bool bNew)
{
	if (bNew) {
		m_Cur = new NORGATE();
		m_Objs.AddTail(m_Cur);

		return (NORGATE*)m_Cur;
	}
	if (m_Cur != NULL && m_Cur->gatenumber == NOR) {
		return (NORGATE*)m_Cur;
	}

	return NULL;
}
NANDGATE* CLogisim_KKLDoc::getNandGates(bool bNew)
{
	if (bNew) {
		m_Cur = new NANDGATE();
		m_Objs.AddTail(m_Cur);

		return (NANDGATE*)m_Cur;
	}
	if (m_Cur != NULL && m_Cur->gatenumber == NAND) {
		return (NANDGATE*)m_Cur;
	}

	return NULL;
}
XORGATE* CLogisim_KKLDoc::getXorGates(bool bNew)
{
	if (bNew) {
		m_Cur = new XORGATE();
		m_Objs.AddTail(m_Cur);

		return (XORGATE*)m_Cur;
	}
	if (m_Cur != NULL && m_Cur->gatenumber == XOR ) {
		return (XORGATE*)m_Cur;
	}

	return NULL;
}/*
TFF* CLogisim_KKLDoc::getTff(bool bNew)
{
	if (bNew) {
		m_Cur = new TFF();
		m_Objs.AddTail(m_Cur);

		return (TFF*)m_Cur;
	}
	if (m_Cur != NULL && m_Cur->gatenumber == T_FF) {
		return (TFF*)m_Cur;
	}

	return NULL;
}
DFF* CLogisim_KKLDoc::getDff(bool bNew)
{
	if (bNew) {
		m_Cur = new DFF();
		m_Objs.AddTail(m_Cur);

		return (DFF*)m_Cur;
	}
	if (m_Cur != NULL && m_Cur->gatenumber == D_FF) {
		return (DFF*)m_Cur;
	}

	return NULL;
}
JKFF* CLogisim_KKLDoc::getJkff(bool bNew)
{
	if (bNew) {
		m_Cur = new JKFF();
		m_Objs.AddTail(m_Cur);

		return (JKFF*)m_Cur;
	}
	if (m_Cur != NULL && m_Cur->gatenumber == JK_FF) {
		return (JKFF*)m_Cur;
	}

	return NULL;
}*/

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CLogisim_KKLDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CLogisim_KKLDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CLogisim_KKLDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CLogisim_KKLDoc ����

#ifdef _DEBUG
void CLogisim_KKLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLogisim_KKLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CLogisim_KKLDoc ���
