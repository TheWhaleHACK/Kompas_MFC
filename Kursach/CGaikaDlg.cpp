// CGaikaDlg.cpp: файл реализации
//

#include "pch.h"
#include "Kursach.h"
#include "afxdialogex.h"
#include "CGaikaDlg.h"
#include "KursachView.h"


// Диалоговое окно CGaikaDlg
//class CKursachView;
IMPLEMENT_DYNAMIC(CGaikaDlg, CDialog)

CGaikaDlg::CGaikaDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_GAIKA, pParent)
	, dZnach_Gaika(_T(""))
	, RezbaZnach_Gaika(_T(""))
	, DZnach_Gaika(_T(""))
	, SZnach_Gaika(_T(""))
	, lZnach_Gaika(_T(""))
{

}

CGaikaDlg::~CGaikaDlg()
{
	
}

void CGaikaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_L_GAIKA, l_Gaika);
	DDX_Control(pDX, IDC_S_GAIKA, S_Gaika);
	DDX_Control(pDX, IDC_D_GAIKA, D_Gaika);
	DDX_Control(pDX, IDC_REZBA_GAIKA, Rezba_Gaika);
	DDX_Control(pDX, IDC_D_MAL_GAIKA, d_Gaika);
	DDX_CBString(pDX, IDC_D_MAL_GAIKA, dZnach_Gaika);
	DDX_CBString(pDX, IDC_REZBA_GAIKA, RezbaZnach_Gaika);
	DDX_CBString(pDX, IDC_D_GAIKA, DZnach_Gaika);
	DDX_CBString(pDX, IDC_S_GAIKA, SZnach_Gaika);
	DDX_CBString(pDX, IDC_L_GAIKA, lZnach_Gaika);
}


BEGIN_MESSAGE_MAP(CGaikaDlg, CDialog)
	
	ON_CBN_SELCHANGE(IDC_D_MAL_GAIKA, &CGaikaDlg::OnCbnSelchangeDMalGaika)
	ON_CBN_SELCHANGE(IDC_REZBA_GAIKA, &CGaikaDlg::OnCbnSelchangeRezbaGaika)
	ON_CBN_SELCHANGE(IDC_D_GAIKA, &CGaikaDlg::OnCbnSelchangeDGaika)
	ON_CBN_SELCHANGE(IDC_S_GAIKA, &CGaikaDlg::OnCbnSelchangeSGaika)
	ON_CBN_SELCHANGE(IDC_L_GAIKA, &CGaikaDlg::OnCbnSelchangeLGaika)
	ON_BN_CLICKED(IDOK, &CGaikaDlg::OnBnClickedOk)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// Обработчики сообщений CGaikaDlg





void CGaikaDlg::OnCbnSelchangeDMalGaika()
{
	UpdateData();

	d = d_Gaika.GetCurSel();

	if (d == 0)
	{
		Rezba = Rezba_Gaika.SetCurSel(0);
		D = D_Gaika.SetCurSel(0);
		S = S_Gaika.SetCurSel(0);
		l = l_Gaika.SetCurSel(0);
	}
	if (d == 1)
	{
		Rezba = Rezba_Gaika.SetCurSel(1);
		D = D_Gaika.SetCurSel(1);
		S = S_Gaika.SetCurSel(1);
		l = l_Gaika.SetCurSel(1);
	}
	if (d == 2)
	{
		Rezba = Rezba_Gaika.SetCurSel(2);
		D = D_Gaika.SetCurSel(2);
		S = S_Gaika.SetCurSel(2);
		l = l_Gaika.SetCurSel(2);
	}
	if (d == 3)
	{
		Rezba = Rezba_Gaika.SetCurSel(3);
		D = D_Gaika.SetCurSel(3);
		S = S_Gaika.SetCurSel(3);
		l = l_Gaika.SetCurSel(3);
	}
}


void CGaikaDlg::OnCbnSelchangeRezbaGaika()
{
	UpdateData();

	Rezba = Rezba_Gaika.GetCurSel();
	if (Rezba == 0)
	{
		d = d_Gaika.SetCurSel(0);
		D = D_Gaika.SetCurSel(0);
		S = S_Gaika.SetCurSel(0);
		l = l_Gaika.SetCurSel(0);
	}
	if (Rezba == 1)
	{
		d = d_Gaika.SetCurSel(1);
		D = D_Gaika.SetCurSel(1);
		S = S_Gaika.SetCurSel(1);
		l = l_Gaika.SetCurSel(1);
	}
	if (Rezba == 2)
	{
		d = d_Gaika.SetCurSel(2);
		D = D_Gaika.SetCurSel(2);
		S = S_Gaika.SetCurSel(2);
		l = l_Gaika.SetCurSel(2);
	}
	if (Rezba == 3)
	{
		d = d_Gaika.SetCurSel(3);
		D = D_Gaika.SetCurSel(3);
		S = S_Gaika.SetCurSel(3);
		l = l_Gaika.SetCurSel(3);
	}
}

void CGaikaDlg::OnCbnSelchangeDGaika()
{
	UpdateData();

	D = D_Gaika.GetCurSel();

	if (D == 0)
	{
		Rezba = Rezba_Gaika.SetCurSel(0);
		d = d_Gaika.SetCurSel(0);
		S = S_Gaika.SetCurSel(0);
		l = l_Gaika.SetCurSel(0);
	}
	if (D == 1)
	{
		Rezba = Rezba_Gaika.SetCurSel(1);
		d = d_Gaika.SetCurSel(1);
		S = S_Gaika.SetCurSel(1);
		l = l_Gaika.SetCurSel(1);
	}
	if (D == 2)
	{
		Rezba = Rezba_Gaika.SetCurSel(2);
		d = d_Gaika.SetCurSel(2);
		S = S_Gaika.SetCurSel(2);
		l = l_Gaika.SetCurSel(2);
	}
	if (D == 3)
	{
		Rezba = Rezba_Gaika.SetCurSel(3);
		d = d_Gaika.SetCurSel(3);
		S = S_Gaika.SetCurSel(3);
		l = l_Gaika.SetCurSel(3);
	}
}


void CGaikaDlg::OnCbnSelchangeSGaika()
{
	UpdateData();

	S = S_Gaika.GetCurSel();

	if (S == 0)
	{
		Rezba = Rezba_Gaika.SetCurSel(0);
		d = d_Gaika.SetCurSel(0);
		D = D_Gaika.SetCurSel(0);
		l = l_Gaika.SetCurSel(0);
	}
	if (S == 1)
	{
		Rezba = Rezba_Gaika.SetCurSel(1);
		d = d_Gaika.SetCurSel(1);
		D = D_Gaika.SetCurSel(1);
		l = l_Gaika.SetCurSel(1);
	}
	if (S == 2)
	{
		Rezba = Rezba_Gaika.SetCurSel(2);
		d = d_Gaika.SetCurSel(2);
		D = D_Gaika.SetCurSel(2);
		l = l_Gaika.SetCurSel(2);
	}
	if (S == 3)
	{
		Rezba = Rezba_Gaika.SetCurSel(3);
		d = d_Gaika.SetCurSel(3);
		D = D_Gaika.SetCurSel(3);
		l = l_Gaika.SetCurSel(3);
	}
}


void CGaikaDlg::OnCbnSelchangeLGaika()
{
	UpdateData();

	l = l_Gaika.GetCurSel();

	if (l == 0)
	{
		Rezba = Rezba_Gaika.SetCurSel(0);
		d = d_Gaika.SetCurSel(0);
		D = D_Gaika.SetCurSel(0);
		S = S_Gaika.SetCurSel(0);
	}
	if (l == 1)
	{
		Rezba = Rezba_Gaika.SetCurSel(1);
		d = d_Gaika.SetCurSel(1);
		D = D_Gaika.SetCurSel(1);
		S = S_Gaika.SetCurSel(1);
	}
	if (l == 2)
	{
		Rezba = Rezba_Gaika.SetCurSel(2);
		d = d_Gaika.SetCurSel(2);
		D = D_Gaika.SetCurSel(2);
		S = S_Gaika.SetCurSel(2);
	}
	if (l == 3)
	{
		Rezba = Rezba_Gaika.SetCurSel(3);
		d = d_Gaika.SetCurSel(3);
		D = D_Gaika.SetCurSel(3);
		S = S_Gaika.SetCurSel(3);
	}
}
	


void CGaikaDlg::OnBnClickedOk()
{
	UpdateData(1);

	//lox = DZnach_Gaika;

	CDialog::OnOK();
}


int CGaikaDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания
	
	return 0;
}


BOOL CGaikaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  Добавить дополнительную инициализацию
	l_Gaika.SetCurSel(l);
	S_Gaika.SetCurSel(S);
	D_Gaika.SetCurSel(D);
	Rezba_Gaika.SetCurSel(Rezba);
	d_Gaika.SetCurSel(d);
	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}
