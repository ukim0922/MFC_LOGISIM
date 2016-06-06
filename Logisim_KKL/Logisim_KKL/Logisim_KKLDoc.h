
// Logisim_KKLDoc.h : CLogisim_KKLDoc Ŭ������ �������̽�
//


#pragma once
#include "LogicEngine.h"
//#include "FilpFlopEngine.h"
#include "Line.h"

class CLogisim_KKLDoc : public CDocument
{
private:
	CPtrList m_Objs;
	LogicEngine* m_Cur;
protected: // serialization������ ��������ϴ�.
	CLogisim_KKLDoc();
	DECLARE_DYNCREATE(CLogisim_KKLDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	CPtrList& getLogicEngine();
	ANDGATE* getAndGates(bool bNew = FALSE);
	ORGATE* getOrGates(bool bNew = FALSE);
	NOTGATE* getNotGates(bool bNew = FALSE);
	NORGATE* getNorGates(bool bNew = FALSE);
	NANDGATE* getNandGates(bool bNew = FALSE);
	XORGATE* getXorGates(bool bNew = FALSE);
	//TFF* getTff(bool bNew = FALSE);
	//DFF* getDff(bool bNew = FALSE);
	//JKFF* getJkff(bool bNew = FALSE);
	//Line* getLine(bool bNew = FALSE);

#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CLogisim_KKLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
