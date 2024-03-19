// CMyTreeView.cpp: файл реализации
//

#include "pch.h"
#include "Kursach.h"
#include "CMyTreeView.h"
#include "KursachDoc.h"
#include "KursachView.h"
#include "CGaikaDlg.h"
#include "CShaibaDlg.h"
#include "CSalnikDlg.h"
#include  "string"
#include <cstdlib>
#include <iostream>

// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{
	iddSalT = idd1SalT = idd2SalT = idRezSalT = idD1SalT = idDSalT = idD2SalT = idB1SalT = idlSalT =
	iddGaiT = idRezGaiT = idDGaiT = idSGaiT = idlGaiT = iddShT = idDshT = idsShT = 0;
}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CMyTreeView


int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	// TODO:  Добавьте специализированный код создания

	return 0;
}
void CMyTreeView::FillTree()
{
			
	CTreeCtrl& tree = GetTreeCtrl();

	tree.DeleteAllItems();

	m_hSborka = tree.InsertItem(L"Сборка", -1, -1, NULL, TVI_FIRST);

	m_hGaika = tree.InsertItem(L"Гайга нажимная", -1,-1, m_hSborka, TVI_FIRST);
	m_hSalnik = tree.InsertItem(L"Сальник", -1,-1, m_hSborka, TVI_FIRST);
	m_hShaiba = tree.InsertItem(L"Шайба", -1, -1, m_hSborka, TVI_FIRST);

	
}

void CMyTreeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTreeView::OnLButtonDown(nFlags, point);

	CTreeCtrl& tree = GetTreeCtrl();

	CRect rc;

	tree.GetItemRect(m_hGaika, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_hGaika);

	tree.GetItemRect(m_hSalnik, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_hSalnik);

	tree.GetItemRect(m_hShaiba, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_hShaiba);

	tree.GetItemRect(m_hSborka, &rc, false);
	if (rc.PtInRect(point))
		tree.SelectItem(m_hSborka);

	if (tree.GetSelectedItem() == m_hShaiba)
	{
		m_pDoc->m_bShaiba = TRUE;
		m_pDoc->m_bGaika = FALSE;
		m_pDoc->m_bSalnik = FALSE;
		m_pDoc->m_bSborka = FALSE;
	}
	if (tree.GetSelectedItem() == m_hGaika)
	{
		m_pDoc->m_bShaiba = FALSE;
		m_pDoc->m_bGaika = TRUE;
		m_pDoc->m_bSalnik = FALSE;
		m_pDoc->m_bSborka = FALSE;
	}
	if (tree.GetSelectedItem() == m_hSalnik)
	{
		m_pDoc->m_bShaiba = FALSE;
		m_pDoc->m_bGaika = FALSE;
		m_pDoc->m_bSalnik = TRUE;
		m_pDoc->m_bSborka = FALSE;
	}
	if (tree.GetSelectedItem() == m_hSborka)
	{
		m_pDoc->m_bShaiba = FALSE;
		m_pDoc->m_bGaika = FALSE;
		m_pDoc->m_bSalnik = FALSE;
		m_pDoc->m_bSborka = TRUE;
	}

	m_pDoc->pView->Invalidate();
}

void CMyTreeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CTreeView::OnLButtonDblClk(nFlags, point);

	CTreeCtrl& tree = GetTreeCtrl();

	CRect rc;


	tree.GetItemRect(m_hGaika, &rc, false);
	if (rc.PtInRect(point)) {
		tree.SelectItem(m_hGaika);

		CShaibaDlg dlg1;
		CSalnikDlg dlg2;
		CGaikaDlg dlg3;

		
		if (iddShT == 0)
			dlg1.d = 12;
		if (iddShT == 1)
			dlg1.d = 1;
		if (iddShT == 2)
			dlg1.d = 3;
		if (iddShT == 3)
			dlg1.d = 10;
		dlg1.D = idDshT;
		dlg1.S = idsShT;
		dlg2.d = iddSalT;
		dlg2.D1 = idD1SalT;
		dlg2.D2 = idD2SalT;
		dlg2.D = idDSalT;
		dlg2.B1 = idB1SalT;
		dlg2.l = idlSalT;
		dlg2.Rezba = idRezSalT;
		if (idd1SalT == 3 || idd2SalT == 3)
		{
			dlg2.d1 = 2;
			dlg2.d2 = 2;
		}
		else
		{
			dlg2.d1 = idd1SalT;
			dlg2.d2 = idd2SalT;
		}
		dlg3.d = iddGaiT;
		dlg3.D = idDGaiT;
		dlg3.Rezba = idRezGaiT;
		dlg3.S = idSGaiT;
		if (idsShT == 0)
			dlg1.S = idsShT;
		if (idsShT == 1)
			dlg1.S = idsShT;
		if (idsShT == 2)
			dlg1.S = idsShT;
		if (idsShT == 3)
			dlg1.S = 2;
		dlg3.l = idlGaiT;

		dlg3.DoModal();

		iddGaiT = idRezSalT =idlSalT =idB1SalT =idDSalT =idD2SalT =idD1SalT =idd2SalT =idd1SalT =iddSalT =idsShT = idDshT = iddShT =dlg3.d;
		idDGaiT = dlg3.D;
		idRezGaiT = dlg3.Rezba;
		idSGaiT = dlg3.S;
		idlGaiT = dlg3.l;

		dGaiT = _tstof(dlg3.dZnach_Gaika);
		DGaiT = _tstof(dlg3.DZnach_Gaika);
		RezGaiT = _tstof(dlg3.RezbaZnach_Gaika);
		SGaiT = _tstof(dlg3.SZnach_Gaika);
		lGaiT = _tstof(dlg3.lZnach_Gaika);

		m_pDoc->pView->F = 1;
	}

	tree.GetItemRect(m_hSalnik, &rc, false);
	if (rc.PtInRect(point)) {
		tree.SelectItem(m_hSalnik);

		CShaibaDlg dlg1;
		CSalnikDlg dlg2;
		CGaikaDlg dlg3;
		if (iddShT == 0)
			dlg1.d = 12;
		if (iddShT == 1)
			dlg1.d = 1;
		if (iddShT == 2)
			dlg1.d = 3;
		if (iddShT == 3)
			dlg1.d = 10;
		dlg1.D = idDshT;
		dlg2.d = iddSalT;
		dlg2.D1 = idD1SalT;
		dlg2.D2 = idD2SalT;
		dlg2.D = idDSalT;
		dlg2.B1 = idB1SalT;
		dlg2.l = idlSalT;
		dlg2.Rezba = idRezSalT;
		if (idd1SalT == 3 || idd2SalT == 3)
		{
			dlg2.d1 = 2;
			dlg2.d2 = 2;
		}
		else
		{
			dlg2.d1 = idd1SalT;
			dlg2.d2 = idd2SalT;
		}
		
		dlg3.d = iddGaiT;
		dlg3.D = idDGaiT;
		dlg3.Rezba = idRezGaiT;
		dlg3.l = idlGaiT;
		dlg3.S = idSGaiT;
		if (idsShT == 0)
			dlg1.S = idsShT;
		if (idsShT == 1)
			dlg1.S = idsShT;
		if (idsShT == 2)
			dlg1.S = idsShT;
		if (idsShT == 3)
			dlg1.S = 2;

		dlg2.DoModal();

		dSalT = _tstof(dlg2.dZnach_Salnik);
		d1SalT = _tstof(dlg2.d1Znach_Salnik);
		d2SalT = _tstof(dlg2.d2Znach_Salnik);
		D1SalT = _tstof(dlg2.D1Znach_Salnik);
		D2SalT = _tstof(dlg2.D2Znach_Salnik);
		DSalT = _tstof(dlg2.DZnach_Salnik);
		B1SalT = _tstof(dlg2.B1Znach_Salnik);
		lSalT = _tstof(dlg2.lZnach_Salnik);
		RezSalT = _tstof(dlg2.RezbaZnach_Salnik);

		iddSalT = idsShT = idDshT = iddShT = idlGaiT  = idSGaiT = idRezGaiT = idDGaiT = iddGaiT= dlg2.d;
		idd1SalT = dlg2.d1;
		idd2SalT = dlg2.d2;
		idD1SalT = dlg2.D1;
		idD2SalT = dlg2.D2;
		idDSalT = dlg2.D;
		idB1SalT = dlg2.B1;
		idlSalT = dlg2.l;
		idRezSalT = dlg2.Rezba;

		m_pDoc->pView->F = 1;
	}

	tree.GetItemRect(m_hShaiba, &rc, false);
	if (rc.PtInRect(point)) {
		tree.SelectItem(m_hShaiba);

		CShaibaDlg dlg1;
		CSalnikDlg dlg2;
		CGaikaDlg dlg3;

		if (iddShT == 0)
			dlg1.d = 12;
		if (iddShT == 1)
			dlg1.d = 1;
		if (iddShT == 2)
			dlg1.d = 3;
		if (iddShT == 3)
			dlg1.d = 10;
		
		dlg1.D = idDshT;
		if (idsShT == 0)
			dlg1.S = idsShT;
		if (idsShT == 1)
			dlg1.S = idsShT;
		if (idsShT == 2)
			dlg1.S = idsShT;
		if (idsShT == 3)
			dlg1.S = 2;
		dlg2.d = iddSalT;
		dlg2.D1 = idD1SalT;
		dlg2.D2 = idD2SalT;
		dlg2.D = idDSalT;
		dlg2.B1 = idB1SalT;
		dlg2.l = idlSalT;
		dlg2.Rezba = idRezSalT;
		if (idd1SalT == 3 || idd2SalT == 3)
		{
			dlg2.d1 = 2;
			dlg2.d2 = 2;
		}
		else
		{
			dlg2.d1 = idd1SalT;
			dlg2.d2 = idd2SalT;
		}
		dlg3.d = iddGaiT;
		dlg3.D = idDGaiT;
		dlg3.Rezba = idRezGaiT;
		dlg3.S = idSGaiT;
		dlg3.l = idlGaiT;
		dlg1.DoModal();

		dShT = _tstof(dlg1.dZnach_Shaiba);
		DshT = _tstof(dlg1.DZnach_Shaiba);
		sShT = _tstof(dlg1.SZnach_Shaiba);

		iddShT = dlg1.d;
		idDshT= iddGaiT= idDGaiT = idRezSalT = idRezGaiT= idlSalT= idSGaiT= idlGaiT= iddSalT= idd1SalT= idd2SalT= idD1SalT= idD2SalT= idDSalT= idB1SalT = dlg1.D;
		idsShT = dlg1.S;

		m_pDoc->pView->F = 1;
	}	
}


