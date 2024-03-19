#pragma once
#include "afxdialogex.h"


// Диалоговое окно CGaikaDlg

class CShaibaDlg : public CDialog
{
	DECLARE_DYNAMIC(CShaibaDlg)

public:
	CShaibaDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CShaibaDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAIBA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnCbnSelchangeDMalShaiba();
	afx_msg void OnCbnSelchangeDShaiba();
	afx_msg void OnCbnSelchangeSShaiba();
	CComboBox S_Shaiba;
	CComboBox D_Shaiba;
	CComboBox d_Shaiba;
	int S, D, d;
	CString SZnach_Shaiba;
	afx_msg void OnBnClickedOk();
	CString DZnach_Shaiba;
	CString dZnach_Shaiba;
	virtual BOOL OnInitDialog();
};
