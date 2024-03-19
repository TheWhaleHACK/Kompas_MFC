// CGaikaDlg.cpp: файл реализации
//

#include "pch.h"
#include "Kursach.h"
#include "afxdialogex.h"
#include "CShaibaDlg.h"



// Диалоговое окно CGaikaDlg

IMPLEMENT_DYNAMIC(CShaibaDlg, CDialog)

CShaibaDlg::CShaibaDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SHAIBA, pParent)
	, SZnach_Shaiba(_T(""))
	, DZnach_Shaiba(_T(""))
	, dZnach_Shaiba(_T(""))
{

}

CShaibaDlg::~CShaibaDlg()
{
}

void CShaibaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_S_SHAIBA, S_Shaiba);
	DDX_Control(pDX, IDC_D_SHAIBA, D_Shaiba);
	DDX_Control(pDX, IDC_D_MAL_SHAIBA, d_Shaiba);
	DDX_CBString(pDX, IDC_S_SHAIBA, SZnach_Shaiba);
	DDX_CBString(pDX, IDC_D_SHAIBA, DZnach_Shaiba);
	DDX_CBString(pDX, IDC_D_MAL_SHAIBA, dZnach_Shaiba);
}


BEGIN_MESSAGE_MAP(CShaibaDlg, CDialog)

	ON_CBN_SELCHANGE(IDC_D_MAL_SHAIBA, &CShaibaDlg::OnCbnSelchangeDMalShaiba)
	ON_CBN_SELCHANGE(IDC_D_SHAIBA, &CShaibaDlg::OnCbnSelchangeDShaiba)
	ON_CBN_SELCHANGE(IDC_S_SHAIBA, &CShaibaDlg::OnCbnSelchangeSShaiba)
	ON_BN_CLICKED(IDOK, &CShaibaDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений CGaikaDlg




void CShaibaDlg::OnCbnSelchangeDMalShaiba()
{
	UpdateData();

	d = d_Shaiba.GetCurSel();

	if (d == 12)
	{
		S = S_Shaiba.SetCurSel(0);
		D = D_Shaiba.SetCurSel(0);
	}
	if (d == 0 || d == 1 || d == 2)
	{
		S = S_Shaiba.SetCurSel(1);
		D = D_Shaiba.SetCurSel(1);
	}
	if (d == 3 || d == 4 || d == 5 || d == 6 || d == 7 || d == 8)
	{
		S = S_Shaiba.SetCurSel(1);
		D = D_Shaiba.SetCurSel(2);
	}
	if (d == 3 || d == 4 || d == 5 || d == 6 || d == 7 || d == 8)
	{
		S = S_Shaiba.SetCurSel(1);
		D = D_Shaiba.SetCurSel(2);
	}
	if (d == 9 || d == 10 || d == 11)
	{
		S = S_Shaiba.SetCurSel(2);
		D = D_Shaiba.SetCurSel(3);
	}
}


void CShaibaDlg::OnCbnSelchangeDShaiba()
{
	UpdateData();

	D = D_Shaiba.GetCurSel();

	if (D == 0)
	{
		d = d_Shaiba.SetCurSel(12);
		S = S_Shaiba.SetCurSel(0);
	}
	if (D == 1)
	{
		d = d_Shaiba.SetCurSel(0);
		S = S_Shaiba.SetCurSel(1);
	}
	if (D == 2)
	{
		d = d_Shaiba.SetCurSel(7);
		S = S_Shaiba.SetCurSel(1);
	}
	if (D == 3)
	{
		d = d_Shaiba.SetCurSel(10);
		S = S_Shaiba.SetCurSel(2);
	}
}


void CShaibaDlg::OnCbnSelchangeSShaiba()
{
	UpdateData();
	
	S = S_Shaiba.GetCurSel();

	if (S == 0)
	{
		d = d_Shaiba.SetCurSel(12);
		D = D_Shaiba.SetCurSel(0);
	}
	if (S == 1)
	{
		d = d_Shaiba.SetCurSel(2);
		D = D_Shaiba.SetCurSel(1);
	}
	if (S == 2)
	{
		d = d_Shaiba.SetCurSel(10);
		D = D_Shaiba.SetCurSel(3);
	}
}


void CShaibaDlg::OnBnClickedOk()
{
	UpdateData(1);
	

	CDialog::OnOK();
}


BOOL CShaibaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	d_Shaiba.SetCurSel(d);
	D_Shaiba.SetCurSel(D);
	S_Shaiba.SetCurSel(S);

	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}
