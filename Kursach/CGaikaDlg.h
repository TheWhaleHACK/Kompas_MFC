#pragma once
#include "afxdialogex.h"
#include "KursachView.h"

// Диалоговое окно CGaikaDlg

class CGaikaDlg : public CDialog
{
	DECLARE_DYNAMIC(CGaikaDlg)

public:
	CGaikaDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CGaikaDlg();
	CKursachView* p;
// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAIKA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnCbnSelchangeDMalGaika();
	afx_msg void OnCbnSelchangeRezbaGaika();
	afx_msg void OnCbnSelchangeDGaika();
	afx_msg void OnCbnSelchangeSGaika();
	afx_msg void OnCbnSelchangeLGaika();
	CComboBox l_Gaika;
	CComboBox S_Gaika;
	CComboBox D_Gaika;
	CComboBox Rezba_Gaika;
	CComboBox d_Gaika;
	int l, S, D, Rezba, d;
	CString dZnach_Gaika;
	CString RezbaZnach_Gaika;
	CString DZnach_Gaika;
	CString SZnach_Gaika;
	CString lZnach_Gaika;
	CString lox;
	afx_msg void OnBnClickedOk();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
};
