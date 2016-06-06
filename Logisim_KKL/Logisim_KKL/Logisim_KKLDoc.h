
// Logisim_KKLDoc.h : CLogisim_KKLDoc 클래스의 인터페이스
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
protected: // serialization에서만 만들어집니다.
	CLogisim_KKLDoc();
	DECLARE_DYNCREATE(CLogisim_KKLDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
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

// 구현입니다.
public:
	virtual ~CLogisim_KKLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
