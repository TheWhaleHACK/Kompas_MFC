
// KursachView.h: интерфейс класса CKursachView
//

#pragma once
#include "KursachDoc.h"


class CKursachView : public CView
{
protected: // создать только из сериализации
	CKursachView() noexcept;
	DECLARE_DYNCREATE(CKursachView)

// Атрибуты
public:

	CKursachDoc* GetDocument() const;
	CButton Start;
	CString dSalstr, d1Salstr, d2Salstr, RezSalstr, D1Salstr, DSalstr, D2Salstr, B1Salstr, lSalstr, dGaistr, RezGaistr, DGaistr, SGaistr, lGaistr, dShstr, Dshstr, sShstr;
	double dSal, d1Sal, d2Sal, RezSal, D1Sal, DSal, D2Sal, B1Sal, lSal;
	double dGai, RezGai, DGai, SGai, lGai, dSh, Dsh, sSh, dGRez, dSRez, ShagRez, faska;
	bool F = 0;
// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	void StartKompas();

// Реализация
public:
	virtual ~CKursachView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // версия отладки в KursachView.cpp
inline CKursachDoc* CKursachView::GetDocument() const
   { return reinterpret_cast<CKursachDoc*>(m_pDocument); }
#endif

