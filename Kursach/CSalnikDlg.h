#pragma once
#include "afxdialogex.h"


// Диалоговое окно CSalnikDlg

class CSalnikDlg : public CDialog
{
	DECLARE_DYNAMIC(CSalnikDlg)

public:
	CSalnikDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CSalnikDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SALNIK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeDMalSalnik();
	afx_msg void OnCbnSelchangeD1MalSalnik();
	afx_msg void OnCbnSelchangeD2MalSalnik();
	afx_msg void OnCbnSelchangeRezbaSalnik();
	afx_msg void OnCbnSelchangeDSalnik();
	afx_msg void OnCbnSelchangeD1Salnik();
	afx_msg void OnCbnSelchangeD2Salnik();
	afx_msg void OnCbnSelchangeB1Salnik();
	afx_msg void OnCbnSelchangeLSalnik();
	CComboBox d_salnik;
	CComboBox d1_salnik;
	CComboBox d2_salnik;
	CComboBox Rezba_salnik;
	CComboBox D_salnik;
	CComboBox D1_salnik;
	CComboBox D2_salnik;
	CComboBox B1_salnik;
	CComboBox l_salnik;
	int d, d1, d2, Rezba, D, D1, D2, B1, l;
	CString dZnach_Salnik;
	CString d1Znach_Salnik;
	CString d2Znach_Salnik;
	CString RezbaZnach_Salnik;
	CString DZnach_Salnik;
	CString D1Znach_Salnik;
	CString D2Znach_Salnik;
	CString B1Znach_Salnik;
	CString lZnach_Salnik;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
