// CSalnikDlg.cpp: файл реализации
//

#include "pch.h"
#include "Kursach.h"
#include "afxdialogex.h"
#include "CSalnikDlg.h"


// Диалоговое окно CSalnikDlg

IMPLEMENT_DYNAMIC(CSalnikDlg, CDialog)

CSalnikDlg::CSalnikDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SALNIK, pParent)
	, dZnach_Salnik(_T(""))
	, d1Znach_Salnik(_T(""))
	, d2Znach_Salnik(_T(""))
	, RezbaZnach_Salnik(_T(""))
	, DZnach_Salnik(_T(""))
	, D1Znach_Salnik(_T(""))
	, D2Znach_Salnik(_T(""))
	, B1Znach_Salnik(_T(""))
	, lZnach_Salnik(_T(""))
{
	/*d_salnik.SetCurSel(1);*/
}

CSalnikDlg::~CSalnikDlg()
{
}

void CSalnikDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_D_MAL_SALNIK, d_salnik);
	DDX_Control(pDX, IDC_D1_MAL_SALNIK, d1_salnik);
	DDX_Control(pDX, IDC_D2_MAL_SALNIK, d2_salnik);
	DDX_Control(pDX, IDC_REZBA_SALNIK, Rezba_salnik);
	DDX_Control(pDX, IDC_D_SALNIK, D_salnik);
	DDX_Control(pDX, IDC_D1_SALNIK, D1_salnik);
	DDX_Control(pDX, IDC_D2_SALNIK, D2_salnik);
	DDX_Control(pDX, IDC_B1_SALNIK, B1_salnik);
	DDX_Control(pDX, IDC_L_SALNIK, l_salnik);
	DDX_CBString(pDX, IDC_D_MAL_SALNIK, dZnach_Salnik);
	DDX_CBString(pDX, IDC_D1_MAL_SALNIK, d1Znach_Salnik);
	DDX_CBString(pDX, IDC_D2_MAL_SALNIK, d2Znach_Salnik);
	DDX_CBString(pDX, IDC_REZBA_SALNIK, RezbaZnach_Salnik);
	DDX_CBString(pDX, IDC_D_SALNIK, DZnach_Salnik);
	DDX_CBString(pDX, IDC_D1_SALNIK, D1Znach_Salnik);
	DDX_CBString(pDX, IDC_D2_SALNIK, D2Znach_Salnik);
	DDX_CBString(pDX, IDC_B1_SALNIK, B1Znach_Salnik);
	DDX_CBString(pDX, IDC_L_SALNIK, lZnach_Salnik);
}


BEGIN_MESSAGE_MAP(CSalnikDlg, CDialog)
	
	ON_CBN_SELCHANGE(IDC_D_MAL_SALNIK, &CSalnikDlg::OnCbnSelchangeDMalSalnik)
	ON_CBN_SELCHANGE(IDC_D1_MAL_SALNIK, &CSalnikDlg::OnCbnSelchangeD1MalSalnik)
	ON_CBN_SELCHANGE(IDC_D2_MAL_SALNIK, &CSalnikDlg::OnCbnSelchangeD2MalSalnik)
	ON_CBN_SELCHANGE(IDC_REZBA_SALNIK, &CSalnikDlg::OnCbnSelchangeRezbaSalnik)
	ON_CBN_SELCHANGE(IDC_D_SALNIK, &CSalnikDlg::OnCbnSelchangeDSalnik)
	ON_CBN_SELCHANGE(IDC_D1_SALNIK, &CSalnikDlg::OnCbnSelchangeD1Salnik)
	ON_CBN_SELCHANGE(IDC_D2_SALNIK, &CSalnikDlg::OnCbnSelchangeD2Salnik)
	ON_CBN_SELCHANGE(IDC_B1_SALNIK, &CSalnikDlg::OnCbnSelchangeB1Salnik)
	ON_CBN_SELCHANGE(IDC_L_SALNIK, &CSalnikDlg::OnCbnSelchangeLSalnik)
	ON_BN_CLICKED(IDOK, &CSalnikDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений CSalnikDlg




void CSalnikDlg::OnCbnSelchangeDMalSalnik()
{
	UpdateData();

	d = d_salnik.GetCurSel();

	if (d == 0)
	{
		d1 = d1_salnik.SetCurSel(0);
		d2 = d2_salnik.SetCurSel(0);
		Rezba = Rezba_salnik.SetCurSel(0);
		D = D_salnik.SetCurSel(0);
		D1 = D1_salnik.SetCurSel(0);
		D2 = D2_salnik.SetCurSel(0);
		B1 = B1_salnik.SetCurSel(0);
		l = l_salnik.SetCurSel(0);
	}
	if (d == 1)
	{
		d1 = d1_salnik.SetCurSel(1);
		d2 = d2_salnik.SetCurSel(1);
		Rezba = Rezba_salnik.SetCurSel(1);
		D = D_salnik.SetCurSel(1);
		D1 = D1_salnik.SetCurSel(1);
		D2 = D2_salnik.SetCurSel(1);
		B1 = B1_salnik.SetCurSel(1);
		l = l_salnik.SetCurSel(1);
	}
	if (d == 2)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		Rezba = Rezba_salnik.SetCurSel(2);
		D = D_salnik.SetCurSel(2);
		D1= D1_salnik.SetCurSel(2);
		D2 = D2_salnik.SetCurSel(2);
		B1 = B1_salnik.SetCurSel(2);
		l = l_salnik.SetCurSel(2);
	}
	if (d == 3)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		Rezba = Rezba_salnik.SetCurSel(3);
		D = D_salnik.SetCurSel(3);
		D1 = D1_salnik.SetCurSel(3);
		D2 = D2_salnik.SetCurSel(3);
		B1 = B1_salnik.SetCurSel(3);
		l = l_salnik.SetCurSel(3);
	}
}


void CSalnikDlg::OnCbnSelchangeD1MalSalnik()
{
	UpdateData();

	d1 = d1_salnik.GetCurSel();

	if (d1 == 0)
	{
		d = d_salnik.SetCurSel(0);
		d2 = d2_salnik.SetCurSel(0);
		Rezba = Rezba_salnik.SetCurSel(0);
		D = D_salnik.SetCurSel(0);
		D1 = D1_salnik.SetCurSel(0);
		D2 = D2_salnik.SetCurSel(0);
		B1 = B1_salnik.SetCurSel(0);
		l = l_salnik.SetCurSel(0);
	}
	if (d1== 1)
	{
		d = d_salnik.SetCurSel(1);
		d2 = d2_salnik.SetCurSel(1);
		Rezba = Rezba_salnik.SetCurSel(1);
		D = D_salnik.SetCurSel(1);
		D1 = D1_salnik.SetCurSel(1);
		D2 = D2_salnik.SetCurSel(1);
		B1 = B1_salnik.SetCurSel(1);
		l = l_salnik.SetCurSel(1);
	}
	if (d1 == 2)
	{
		d = d_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		Rezba = Rezba_salnik.SetCurSel(2);
		D = D_salnik.SetCurSel(2);
		D1 = D1_salnik.SetCurSel(2);
		D2 = D2_salnik.SetCurSel(2);
		B1 = B1_salnik.SetCurSel(2);
		l = l_salnik.SetCurSel(2);
	}
	
}


void CSalnikDlg::OnCbnSelchangeD2MalSalnik()
{
	UpdateData();

	d2 = d2_salnik.GetCurSel();

	if (d2 == 0)
	{
		d= d_salnik.SetCurSel(0);
		d1 = d1_salnik.SetCurSel(0);
		Rezba = Rezba_salnik.SetCurSel(0);
		D = D_salnik.SetCurSel(0);
		D1 = D1_salnik.SetCurSel(0);
		D2 = D2_salnik.SetCurSel(0);
		B1 = B1_salnik.SetCurSel(0);
		l = l_salnik.SetCurSel(0);
	}
	if (d2 == 1)
	{
		d = d_salnik.SetCurSel(1);
		d1 = d1_salnik.SetCurSel(1);
		Rezba = Rezba_salnik.SetCurSel(1);
		D = D_salnik.SetCurSel(1);
		D1 = D1_salnik.SetCurSel(1);
		D2 = D2_salnik.SetCurSel(1);
		B1 = B1_salnik.SetCurSel(1);
		l = l_salnik.SetCurSel(1);
	}
	if (d2 == 2)
	{
		d = d_salnik.SetCurSel(2);
		d1 = d1_salnik.SetCurSel(2);
		Rezba = Rezba_salnik.SetCurSel(2);
		D = D_salnik.SetCurSel(2);
		D1 = D1_salnik.SetCurSel(2);
		D2 = D2_salnik.SetCurSel(2);
		B1 = B1_salnik.SetCurSel(2);
		l = l_salnik.SetCurSel(2);
	}
}


void CSalnikDlg::OnCbnSelchangeRezbaSalnik()
{
	UpdateData();

	Rezba = Rezba_salnik.GetCurSel();


	if (Rezba == 0)
	{
		d1 = d1_salnik.SetCurSel(0);
		d2 = d2_salnik.SetCurSel(0);
		d = d_salnik.SetCurSel(0);
		D = D_salnik.SetCurSel(0);
		D1 = D1_salnik.SetCurSel(0);
		D2 = D2_salnik.SetCurSel(0);
		B1 = B1_salnik.SetCurSel(0);
		l = l_salnik.SetCurSel(0);
	}
	if (Rezba == 1)
	{
		d1 = d1_salnik.SetCurSel(1);
		d2 = d2_salnik.SetCurSel(1);
		d = d_salnik.SetCurSel(1);
		D = D_salnik.SetCurSel(1);
		D1 = D1_salnik.SetCurSel(1);
		D2 = D2_salnik.SetCurSel(1);
		B1 = B1_salnik.SetCurSel(1);
		l = l_salnik.SetCurSel(1);
	}
	if (Rezba == 2)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(2);
		D = D_salnik.SetCurSel(2);
		D1 = D1_salnik.SetCurSel(2);
		D2 = D2_salnik.SetCurSel(2);
		B1 = B1_salnik.SetCurSel(2);
		l = l_salnik.SetCurSel(2);
	}
	if (Rezba == 3)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(3);
		D = D_salnik.SetCurSel(3);
		D1 = D1_salnik.SetCurSel(3);
		D2 = D2_salnik.SetCurSel(3);
		B1 = B1_salnik.SetCurSel(3);
		l = l_salnik.SetCurSel(3);
	}
}


void CSalnikDlg::OnCbnSelchangeDSalnik()
{
	UpdateData();

	D = D_salnik.GetCurSel();

	if (D == 0)
	{
		d1 = d1_salnik.SetCurSel(0);
		d2 = d2_salnik.SetCurSel(0);
		d = d_salnik.SetCurSel(0);
		Rezba = Rezba_salnik.SetCurSel(0);
		D1 = D1_salnik.SetCurSel(0);
		D2 = D2_salnik.SetCurSel(0);
		B1 = B1_salnik.SetCurSel(0);
		l = l_salnik.SetCurSel(0);
	}
	if (D == 1)
	{
		d1 = d1_salnik.SetCurSel(1);
		d2 = d2_salnik.SetCurSel(1);
		d=d_salnik.SetCurSel(1);
		Rezba  =Rezba_salnik.SetCurSel(1);
		D1 = D1_salnik.SetCurSel(1);
		D2 = D2_salnik.SetCurSel(1);
		B1 = B1_salnik.SetCurSel(1);
		l = l_salnik.SetCurSel(1);
	}
	if (D == 2)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(2);
		Rezba = Rezba_salnik.SetCurSel(2);
		D1 = D1_salnik.SetCurSel(2);
		D2 = D2_salnik.SetCurSel(2);
		B1 = B1_salnik.SetCurSel(2);
		l  =l_salnik.SetCurSel(2);
	}
	if (D == 3)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(3);
		Rezba = Rezba_salnik.SetCurSel(3);
		D1 = D1_salnik.SetCurSel(3);
		D2 = D2_salnik.SetCurSel(3);
		B1 = B1_salnik.SetCurSel(3);
		l = l_salnik.SetCurSel(3);
	}
}


void CSalnikDlg::OnCbnSelchangeD1Salnik()
{
	UpdateData();

	D1 = D1_salnik.GetCurSel();

	if (D1 == 0)
	{
		d1 = d1_salnik.SetCurSel(0);
		d2 = d2_salnik.SetCurSel(0);
		d = d_salnik.SetCurSel(0);
		Rezba = Rezba_salnik.SetCurSel(0);
		D = D_salnik.SetCurSel(0);
		D2 = D2_salnik.SetCurSel(0);
		B1 = B1_salnik.SetCurSel(0);
		l = l_salnik.SetCurSel(0);
	}
	if (D1 == 1)
	{
		d1 = d1_salnik.SetCurSel(1);
		d2 = d2_salnik.SetCurSel(1);
		d = d_salnik.SetCurSel(1);
		Rezba = Rezba_salnik.SetCurSel(1);
		D = D_salnik.SetCurSel(1);
		D2 = D2_salnik.SetCurSel(1);
		B1 = B1_salnik.SetCurSel(1);
		l = l_salnik.SetCurSel(1);
	}
	if (D1 == 2)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(2);
		Rezba = Rezba_salnik.SetCurSel(2);
		D = D_salnik.SetCurSel(2);
		D2 = D2_salnik.SetCurSel(2);
		B1 = B1_salnik.SetCurSel(2);
		l = l_salnik.SetCurSel(2);
	}
	if (D1 == 3)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(3);
		Rezba = Rezba_salnik.SetCurSel(3);
		D = D_salnik.SetCurSel(3);
		D2 = D2_salnik.SetCurSel(3);
		B1 = B1_salnik.SetCurSel(3);
		l = l_salnik.SetCurSel(3);
	}
}


void CSalnikDlg::OnCbnSelchangeD2Salnik()
{
	UpdateData();

	D2 = D2_salnik.GetCurSel();

	if (D2 == 0)
	{
		d1 = d1_salnik.SetCurSel(0);
		d2 = d2_salnik.SetCurSel(0);
		d = d_salnik.SetCurSel(0);
		Rezba = Rezba_salnik.SetCurSel(0);
		D = D_salnik.SetCurSel(0);
		D1 = D1_salnik.SetCurSel(0);
		B1 = B1_salnik.SetCurSel(0);
		l = l_salnik.SetCurSel(0);
	}
	if (D2 == 1)
	{
		d1 = d1_salnik.SetCurSel(1);
		d2 = d2_salnik.SetCurSel(1);
		d = d_salnik.SetCurSel(1);
		Rezba = Rezba_salnik.SetCurSel(1);
		D = D_salnik.SetCurSel(1);
		D1 = D1_salnik.SetCurSel(1);
		B1 = B1_salnik.SetCurSel(1);
		l = l_salnik.SetCurSel(1);
	}
	if (D2 == 2)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(2);
		Rezba = Rezba_salnik.SetCurSel(2);
		D = D_salnik.SetCurSel(2);
		D1 = D1_salnik.SetCurSel(2);
		B1 = B1_salnik.SetCurSel(2);
		l = l_salnik.SetCurSel(2);
	}
	if (D2 == 3)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(3);
		Rezba = Rezba_salnik.SetCurSel(3);
		D = D_salnik.SetCurSel(3);
		D1 = D1_salnik.SetCurSel(3);
		B1 = B1_salnik.SetCurSel(3);
		l = l_salnik.SetCurSel(3);
	}
}


void CSalnikDlg::OnCbnSelchangeB1Salnik()
{
	UpdateData();

	B1 = B1_salnik.GetCurSel();

	if (B1 == 0)
	{
		d1 = d1_salnik.SetCurSel(0);
		d2 = d2_salnik.SetCurSel(0);
		d = d_salnik.SetCurSel(0);
		Rezba = Rezba_salnik.SetCurSel(0);
		D = D_salnik.SetCurSel(0);
		D1 = D1_salnik.SetCurSel(0);
		D2 = D2_salnik.SetCurSel(0);
		l = l_salnik.SetCurSel(0);
	}
	if (B1 == 1)
	{
		d1 = d1_salnik.SetCurSel(1);
		d2 = d2_salnik.SetCurSel(1);
		d = d_salnik.SetCurSel(1);
		Rezba = Rezba_salnik.SetCurSel(1);
		D = D_salnik.SetCurSel(1);
		D1 = D1_salnik.SetCurSel(1);
		D2 = D2_salnik.SetCurSel(1);
		l = l_salnik.SetCurSel(1);
	}
	if (B1 == 2)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(2);
		Rezba = Rezba_salnik.SetCurSel(2);
		D = D_salnik.SetCurSel(2);
		D1 = D1_salnik.SetCurSel(2);
		D2 = D2_salnik.SetCurSel(2);
		l = l_salnik.SetCurSel(2);
	}
	if (B1 == 3)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(3);
		Rezba = Rezba_salnik.SetCurSel(3);
		D = D_salnik.SetCurSel(3);
		D1 = D1_salnik.SetCurSel(3);
		D2 = D2_salnik.SetCurSel(3);
		l = l_salnik.SetCurSel(3);
	}
}


void CSalnikDlg::OnCbnSelchangeLSalnik()
{
	UpdateData();

	l = l_salnik.GetCurSel();

	if (l == 0)
	{
		d1 = d1_salnik.SetCurSel(0);
		d2 = d2_salnik.SetCurSel(0);
		d=  d_salnik.SetCurSel(0);
		Rezba = Rezba_salnik.SetCurSel(0);
		D = D_salnik.SetCurSel(0);
		D1 = D1_salnik.SetCurSel(0);
		D2 = D2_salnik.SetCurSel(0);
		B1 = B1_salnik.SetCurSel(0);
	}
	if (l == 1)
	{
		d1  =d1_salnik.SetCurSel(1);
		d2 = d2_salnik.SetCurSel(1);
		d = d_salnik.SetCurSel(1);
		Rezba = Rezba_salnik.SetCurSel(1);
		D = D_salnik.SetCurSel(1);
		D1 = D1_salnik.SetCurSel(1);
		D2 = D2_salnik.SetCurSel(1);
		B1 = B1_salnik.SetCurSel(1);
	}
	if (l == 2)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d= d_salnik.SetCurSel(2);
		Rezba = Rezba_salnik.SetCurSel(2);
		D = D_salnik.SetCurSel(2);
		D1 = D1_salnik.SetCurSel(2);
		D2 = D2_salnik.SetCurSel(2);
		B1 = B1_salnik.SetCurSel(2);
	}
	if (l == 3)
	{
		d1 = d1_salnik.SetCurSel(2);
		d2 = d2_salnik.SetCurSel(2);
		d = d_salnik.SetCurSel(3);
		Rezba = Rezba_salnik.SetCurSel(3);
		D = D_salnik.SetCurSel(3);
		D1 = D1_salnik.SetCurSel(3);
		D2 = D2_salnik.SetCurSel(3);
		B1 = B1_salnik.SetCurSel(3);
	}
}


void CSalnikDlg::OnBnClickedOk()
{
	UpdateData(1);
	CDialog::OnOK();
}


BOOL CSalnikDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	d_salnik.SetCurSel(d);
	d1_salnik.SetCurSel(d1);
	d2_salnik.SetCurSel(d2);
	Rezba_salnik.SetCurSel(Rezba);
	D_salnik.SetCurSel(D);
	D1_salnik.SetCurSel(D1);
	D2_salnik.SetCurSel(D2);
	B1_salnik.SetCurSel(B1);
	l_salnik.SetCurSel(l);

	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}
