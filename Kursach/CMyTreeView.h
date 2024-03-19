#pragma once
#include <afxcview.h>
#include "CGaikaDlg.h"
#include "CShaibaDlg.h"
#include "CSalnikDlg.h"
// Просмотр CMyTreeView
class CKursachDoc;
class CMyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyTreeView();
	
public:
	CKursachDoc* m_pDoc;
	CButton Start;
	
	HTREEITEM m_hShaiba, m_hGaika, m_hSalnik, m_hSborka;
	
	double dSalT, d1SalT, d2SalT, RezSalT, D1SalT, DSalT, D2SalT, B1SalT, lSalT;
	double dGaiT, RezGaiT, DGaiT, SGaiT, lGaiT, dShT, DshT, sShT;
	
	int iddSalT, idd1SalT, idd2SalT, idRezSalT, idD1SalT, idDSalT, idD2SalT, idB1SalT, idlSalT;
	int iddGaiT, idRezGaiT, idDGaiT, idSGaiT, idlGaiT, iddShT, idDshT, idsShT;
	void FillTree();
	
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	
};


