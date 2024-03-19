
// KursachView.cpp: реализация класса CKursachView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Kursach.h"
#endif
#include "CGaikaDlg.h"
#include "CShaibaDlg.h"
#include "CSalnikDlg.h"
#include <vector>
#include "KursachDoc.h"
#include "KursachView.h"
#include "string"
#include "CMyTreeView.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "C:\Program Files\ASCON\KOMPAS-3D v22 Study\SDK\Include\ksConstants.h"
#include "C:\Program Files\ASCON\KOMPAS-3D v22 Study\SDK\Include\ksConstants3D.h"


#import "C:\Program Files\ASCON\KOMPAS-3D v22 Study\SDK\lib\kAPI5.tlb"
using namespace Kompas6API5;

KompasObjectPtr pKompasApp5;
//KompasObjectPtr pKompasApp5;

ksPartPtr pPart;// = PartDoc->GetTopPart();
ksDocument3DPtr pDOC;
// CKursachView

IMPLEMENT_DYNCREATE(CKursachView, CView)

BEGIN_MESSAGE_MAP(CKursachView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_START, &CKursachView::StartKompas)
END_MESSAGE_MAP()

// Создание или уничтожение CKursachView

CKursachView::CKursachView() noexcept
{
	
}

CKursachView::~CKursachView()
{
}

BOOL CKursachView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CKursachView

void CKursachView::OnDraw(CDC* pDC)
{
	CKursachDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (pDoc->m_bSborka == 1)
	{
		CImage image;
		image.Load(_T("C:\\Users\\saintazimov\\Desktop\\kyrsovaya\\Kursach\\png\\Sborka.bmp"));

		if (image.IsNull()) {
			return;
		}
		CDC memDC;
		int imageWidth = image.GetWidth();
		int imageHeight = image.GetHeight();
		image.StretchBlt(pDC->GetSafeHdc(), 0, 0, imageWidth, imageHeight, 0, 0, imageWidth, imageHeight, SRCCOPY);
	}
	if (pDoc->m_bShaiba == 1)
	{
		CImage image;
		image.Load(_T("C:\\Users\\saintazimov\\Desktop\\kyrsovaya\\Kursach\\png\\Shaiba.bmp"));

		if (image.IsNull()) {
			return;
		}
		CDC memDC;
		int imageWidth = image.GetWidth();
		int imageHeight = image.GetHeight();
		image.StretchBlt(pDC->GetSafeHdc(), 0, 0, imageWidth, imageHeight, 0, 0, imageWidth, imageHeight, SRCCOPY);
	}
	if (pDoc->m_bGaika == 1)
	{
		CImage image;
		image.Load(_T("C:\\Users\\saintazimov\\Desktop\\kyrsovaya\\Kursach\\png\\Gaika.bmp"));

		if (image.IsNull()) {
			return;
		}
		CDC memDC;
		int imageWidth = image.GetWidth();
		int imageHeight = image.GetHeight();
		image.StretchBlt(pDC->GetSafeHdc(), 0, 0, imageWidth, imageHeight, 0, 0, imageWidth, imageHeight, SRCCOPY);
	}
	if (pDoc->m_bSalnik == 1)
	{
		CImage image;
		image.Load(_T("C:\\Users\\saintazimov\\Desktop\\kyrsovaya\\Kursach\\png\\Gnezdo.bmp"));

		if (image.IsNull()) {
			return;
		}
		CDC memDC;
		int imageWidth = image.GetWidth();
		int imageHeight = image.GetHeight();
		image.StretchBlt(pDC->GetSafeHdc(), 0, 0, imageWidth, imageHeight, 0, 0, imageWidth, imageHeight, SRCCOPY);
	}

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CKursachView

BOOL CKursachView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CKursachView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CKursachView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CKursachView

#ifdef _DEBUG
void CKursachView::AssertValid() const
{
	CView::AssertValid();
}

void CKursachView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKursachDoc* CKursachView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKursachDoc)));
	return (CKursachDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CKursachView


void CKursachView::OnInitialUpdate()
{
	
	Start.Create(_T("СТАРТ"), WS_CHILD | WS_VISIBLE, CRect(10, 500, 300, 570), this, IDC_START);
	

	CView::OnInitialUpdate();
}

void CKursachView::StartKompas()
{		
	CKursachDoc* pDoc = GetDocument();
	if (F == 1)
	{ 
	dSh = pDoc->pTree->dShT;
	Dsh = pDoc->pTree->DshT;
	sSh = pDoc->pTree->sShT;


	dSal = pDoc->pTree->dSalT;
	d1Sal = pDoc->pTree->d1SalT;
	d2Sal = pDoc->pTree->d2SalT;
	RezSal = pDoc->pTree->RezSalT;
	D1Sal = pDoc->pTree->D1SalT;
	D2Sal = pDoc->pTree->D2SalT;
	DSal = pDoc->pTree->DSalT;
	B1Sal = pDoc->pTree->B1SalT;
	lSal = pDoc->pTree->lSalT;


	dGai = pDoc->pTree->dGaiT;
	RezGai = pDoc->pTree->RezGaiT;
	DGai = pDoc->pTree->DGaiT;
	SGai = pDoc->pTree->SGaiT;
	lGai = pDoc->pTree->lGaiT;
	}
	else
	{
		dSh = 8;
		Dsh = 14;
		sSh = 1.5;

		dGai = 10;
		DGai = 21.9;
		SGai = 19;
		lGai = 17;

		dSal = 8;
		d1Sal = 4.5;
		d2Sal = 8;
		D1Sal = 34;
		D2Sal = 46;
		DSal = 20;
		B1Sal = 42;
		lSal = 18;

		dGRez = dSRez = 16;
		ShagRez = 1;
		faska = 1;
	}
	if (dSal == 8 || dSh == 8 || dGai == 10)
	{
		dSh = 8;
		Dsh = 14;
		sSh = 1.5;

		dGai = 10;
		DGai = 21.9;
		SGai = 19;
		lGai = 17;

		dSal = 8;
		d1Sal = 4.5;
		d2Sal = 8;
		D1Sal = 34;
		D2Sal = 46;
		DSal = 20;
		B1Sal = 42;
		lSal = 18;

		dGRez = dSRez = 16;
		ShagRez = 1;
		faska = 1;
	}
	if (dSal == 16 || dSh == 12 || dSh == 14 || dSh == 16 || dGai == 20)
	{
		dSh = 12;
		if (dSh == 12)
			dSh = 12;
		if (dSh == 14)
			dSh = 14;
		if (dSh == 16)
			dSh = 16;
		sSh = 2;
		Dsh = 24;
		dGai = 20;
		DGai = 36.9;
		SGai = 32;
		lGai = 23;
		dSal = 16;
		d1Sal = 5.5;
		d2Sal = 10;
		D1Sal = 46;
		D2Sal = 60;
		DSal = 32;
		B1Sal = 57;
		lSal = 26;
		dGRez = dSRez = 27;
		ShagRez = 1.5;
		faska = 1.5;
	}
	if (dSal == 28 || dSh == 18 || dSh == 20 || dSh == 22 || dSh == 24 || dSh == 26 || dSh == 28 || dGai == 32)
	{
		dSh = 20;
		if (dSh == 18)
			dSh = 18;
		if (dSh == 20)
			dSh = 20;
		if (dSh == 22)
			dSh = 22;
		if (dSh == 24)
			dSh = 24;
		if (dSh == 26)
			dSh = 26;
		if (dSh == 28)
			dSh = 28;
		sSh = 2;
		Dsh = 38;
		dGai = 32;
		DGai = 53;
		SGai = 46;
		lGai = 32;
		dSal = 28;
		d1Sal = 6.6;
		d2Sal = 12;
		DSal = 46;
		D1Sal = 62;
		D2Sal = 78;
		B1Sal = 73;
		lSal = 35;
		dGRez = dSRez = 42;
		ShagRez = 2;
		faska = 2;
	}
	if (dSal == 38 || dSh == 30 || dSh == 32 || dSh == 38 || dGai == 40)
	{
		dSh = 32;
		if (dSh == 30)
			dSh = 30;
		if (dSh == 32)
			dSh = 32;
		if (dSh == 38)
			dSh = 38;
		sSh = 3;
		Dsh = 48;
		dGai = 40;
		DGai = 63.5;
		SGai = 55;
		lGai = 34;
		dSal = 38;
		d1Sal = 6.6;
		d2Sal = 12;
		DSal = 58;
		D1Sal = 76;
		D2Sal = 95;
		B1Sal = 90;
		lSal = 39;
		dGRez = dSRez = 52;
		ShagRez = 2;
		faska = 2;
	}

	CComPtr<IUnknown> pKompasAppUnk = nullptr;
	if (!pKompasApp5)
	{
		// Получаем CLSID для Компас
		CLSID InvAppClsid;
		HRESULT hRes = CLSIDFromProgID(L"Kompas.Application.5", &InvAppClsid);
		if (FAILED(hRes)) {
			pKompasApp5 = nullptr;
			return;
		}

		// Проверяем есть ли запущенный экземпляр Компас
		//если есть получаем IUnknown
		hRes = ::GetActiveObject(InvAppClsid, NULL, &pKompasAppUnk);
		if (FAILED(hRes)) {
			// Приходится запускать Компас самим так как работающего нет
			// Также получаем IUnknown для только что запущенного приложения Компас
			TRACE(L"Could not get hold of an active Inventor, will start a new session\n");
			hRes = CoCreateInstance(InvAppClsid, NULL, CLSCTX_LOCAL_SERVER, __uuidof(IUnknown), (void**)&pKompasAppUnk);
			if (FAILED(hRes)) {
				pKompasApp5 = nullptr;
				return;
			}
		}

		// Получаем интерфейс приложения Компас
		hRes = pKompasAppUnk->QueryInterface(__uuidof(KompasObject), (void**)&pKompasApp5);
		if (FAILED(hRes)) {
			return;
		}
	}
	pKompasApp5->Visible = true;
	//НАЧАЛО ШАЙБЫ
	pDOC = pKompasApp5->Document3D();
	pDOC->Create(false, true);
	pPart = pDOC->GetPart(pTop_Part);
	ksEntityPtr pSketch = pPart->NewEntity(o3d_sketch);
	ksSketchDefinitionPtr pSketchDef = pSketch->GetDefinition();



	ksDocument2DPtr p2DDoc = pSketchDef->BeginEdit();
	pSketchDef->EndEdit();
	ksEntityPtr pSketch1 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch1->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch1->Create();
	p2DDoc = pSketchDef->BeginEdit();
	p2DDoc->ksLineSeg(0, 0, 0, 100, 3);
	p2DDoc->ksLineSeg(dSh/2, 0, dSh/2, sSh, 1);
	p2DDoc->ksLineSeg(dSh / 2, sSh, Dsh/2, sSh, 1);
	p2DDoc->ksLineSeg(Dsh/2, sSh, Dsh/2, 0, 1);
	p2DDoc->ksLineSeg(Dsh/2, 0, dSh/2, 0, 1);
	pSketchDef->EndEdit();
	//выдавливаем шайбу
	ksEntityPtr telo = pPart->NewEntity(o3d_baseRotated);
	ksBaseRotatedDefinitionPtr ptelo = telo->GetDefinition();
	ptelo->SetSideParam(TRUE, 360);
	ptelo->directionType* (dtNormal);
	ptelo->SetSketch(pSketch1);
	telo->Create();

	ksEntityPtr entityChamfers7 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef7 = entityChamfers7->GetDefinition();
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart7 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_face);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers7 = (ksEntityCollectionPtr)chamferDef7->array();
	entityCollectionChamfers7->Clear();
	entityColPart7->SelectByPoint(dSh/2 + 0.01, 0, 0);
	for (int i = 0; i < entityColPart7->GetCount(); i++) {
		ksEntityPtr face3 = entityColPart7->GetByIndex(i);

		face3->Putname("ShaibaNiz");
		face3->Update();
	}
	ksEntityPtr entityChamfers8 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef8 = entityChamfers8->GetDefinition();
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart8 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_face);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers8 = (ksEntityCollectionPtr)chamferDef8->array();
	entityCollectionChamfers8->Clear();
	entityColPart8->SelectByPoint(dSh/2 + 0.01, 0, -sSh);
	for (int i = 0; i < entityColPart8->GetCount(); i++) {
		ksEntityPtr face4 = entityColPart8->GetByIndex(i);

		face4->Putname("ShaibaVerx");
		face4->Update();
	}
		ksEntityPtr entityChamfers9 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef9 = entityChamfers8->GetDefinition();
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart9 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_face);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers9 = (ksEntityCollectionPtr)chamferDef9->array();
	entityCollectionChamfers9->Clear();
	entityColPart9->SelectByPoint(Dsh/2, 0, -0.1);
	for (int i = 0; i < entityColPart9->GetCount(); i++) {
		ksEntityPtr face4 = entityColPart9->GetByIndex(i);

		face4->Putname("ShaibaBok");
		face4->Update();
	}


	pDOC->SaveAs("C:\\Users\\saintazimov\\Documents\\kyrsovaya_details\\Part1.m3d");



	pDOC = pKompasApp5->Document3D();

	//создаем гайку
	pDOC->Create(false, true);

	pPart = pDOC->GetPart(pTop_Part);
	

	ksDocument2DPtr p3DDoc = pSketchDef->BeginEdit();
	pSketchDef->EndEdit();
	ksEntityPtr pSketch2 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch2->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch2->Create();
	p3DDoc = pSketchDef->BeginEdit();
	p3DDoc->ksCircle(0, 0, dGRez/2, 1);
	pSketchDef->EndEdit();

	ksEntityPtr pSketch3 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch3->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch3->Create();
	p3DDoc = pSketchDef->BeginEdit();
	p3DDoc->ksCircle(0, 0, dGRez / 2 - 2, 1);
	pSketchDef->EndEdit();

	ksEntityPtr pSketch4 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch4->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));//Плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch4->Create();
	p3DDoc = pSketchDef->BeginEdit();
	p3DDoc->ksCircle(0, 0, dGai/2, 1);
	pSketchDef->EndEdit();
	
	//Выдавливаем
	ksEntityPtr bossExtr = pPart->NewEntity(o3d_baseExtrusion);
	ksBaseExtrusionDefinitionPtr ptelo1 = telo->GetDefinition();
	ptelo1 = bossExtr->GetDefinition();
	ptelo1->directionType = dtNormal;
	ptelo1->SetSketch(pSketch2);
	ptelo1->SetSideParam(true, 0, lGai*3/5, 0, true);
	bossExtr->Create();

	ksEntityPtr bossExtr1 = pPart->NewEntity(o3d_baseExtrusion);
	ksBaseExtrusionDefinitionPtr ptelo2 = telo->GetDefinition();
	ptelo2 = bossExtr1->GetDefinition();
	ptelo2->directionType = dtNormal;
	ptelo2->SetSketch(pSketch3);
	ptelo2->SetSideParam(true, 0, lGai * 4 / 5, 0, true);
	bossExtr1->Create();

	//доп плоскость
	ksEntityPtr basePlaneOffset = (ksEntityPtr)pPart->NewEntity(o3d_planeOffset);
	ksPlaneOffsetDefinitionPtr offsetPlaneDef = basePlaneOffset -> GetDefinition();
	offsetPlaneDef->direction = true;
	// расстояние
	offsetPlaneDef->offset = lGai * 4 / 5;
	// плоскость, относительно которой будет проходить смещение
	offsetPlaneDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));
	// создаём плоскость
	basePlaneOffset->Create();

	ksEntityPtr pSketch5 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch5->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(basePlaneOffset);//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch5->Create();
	p3DDoc = pSketchDef->BeginEdit();
	double point4[6][2];
	point4[0][0] = DGai/2;
	point4[0][1] = 0;

	point4[1][0] = DGai / 4;
	point4[1][1] = SGai/2;

	point4[2][0] = -DGai / 4;
	point4[2][1] = SGai/2;

	point4[3][0] = -DGai/2;
	point4[3][1] = 0;

	point4[4][0] = -DGai / 4;
	point4[4][1] = -SGai / 2;

	point4[5][0] = DGai / 4;
	point4[5][1] = -SGai / 2;


	p3DDoc->ksLineSeg(point4[0][0], point4[0][1], point4[1][0], point4[1][1], 1);
	p3DDoc->ksLineSeg(point4[1][0], point4[1][1], point4[2][0], point4[2][1], 1);
	p3DDoc->ksLineSeg(point4[2][0], point4[2][1], point4[3][0], point4[3][1], 1);
	p3DDoc->ksLineSeg(point4[3][0], point4[3][1], point4[4][0], point4[4][1], 1);
	p3DDoc->ksLineSeg(point4[4][0], point4[4][1], point4[5][0], point4[5][1], 1);
	p3DDoc->ksLineSeg(point4[5][0], point4[5][1], point4[0][0], point4[0][1], 1);
	
	pSketchDef->EndEdit();

	ksEntityPtr bossExtr2 = pPart->NewEntity(o3d_baseExtrusion);
	ksBaseExtrusionDefinitionPtr ptelo3 = telo->GetDefinition();
	ptelo3 = bossExtr2->GetDefinition();
	ptelo3->directionType = dtNormal;
	ptelo3->SetSketch(pSketch5);
	ptelo3->SetSideParam(true, 0, lGai/ 5, 0, true);
	bossExtr2->Create();

	//отвертстие гайки
	ksEntityPtr cutExtr = pPart->NewEntity(o3d_cutExtrusion);
	ksCutExtrusionDefinitionPtr ptelo4 = cutExtr->GetDefinition();
	ptelo4->directionType = dtReverse;
	ptelo4->SetSketch(pSketch4);
	ptelo4->SetSideParam(true, etBlind, lGai, 0, false);//A это глубина выреза
	ptelo4->SetSideParam(false, etBlind, lGai, 0, false);//A это глубина выреза
	cutExtr->Create();

	//резьба
	ksEntityPtr Thread = pPart->NewEntity(o3d_thread);
	// получаем интерфейс настроек резьбы
	ksThreadDefinitionPtr ThreadDef = Thread ->GetDefinition();
	ThreadDef->allLength = true; // признак полной длины
	ThreadDef->autoDefinDr = true;// признак автоопределения диаметра
	ThreadDef->dr = dGRez; // номинальный диаметр резьбы
	ThreadDef->length = lGai*3/5; // длина резьбы
	ThreadDef->faceValue = true; // направление построения резьбы
	ThreadDef->p = ShagRez; // шаг резьбы
	// получаем коллекцию рёбер детали
	ksEntityCollectionPtr EdgeECol = (ksEntityCollectionPtr)pPart->EntityCollection(o3d_edge);
	// оставляем в массиве только ребро, проходящее через точку (x,y,z)
	EdgeECol->SelectByPoint(dGRez / 2, 0, 0);
	ThreadDef->SetBaseObject(EdgeECol->First()); // устанавливаем ребро в параметры
		// создаёём резьбу
	Thread->Create();


	//фаска гайки
	ksEntityPtr entityChamfers = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef = entityChamfers->GetDefinition();
	// устанавливаем параметры фаски
	// (признак направленичя фаски, размер первого катета, размер второго катета)
	chamferDef->SetChamferParam(true, faska, faska);
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_edge);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers = (ksEntityCollectionPtr)chamferDef->array();
	entityCollectionChamfers->Clear(); // очищаем коллекцию
	entityColPart->SelectByPoint( dGRez/2, 0 , 0); // получаем ребро по точке
	entityCollectionChamfers->Add(entityColPart->First()); // добавляем в массив
	entityChamfers->Create();

	ksEntityPtr entityChamfers11 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef11 = entityChamfers11->GetDefinition();
	// устанавливаем параметры фаски
	// (признак направленичя фаски, размер первого катета, размер второго катета)
	chamferDef11->SetChamferParam(true, faska, faska);
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart11 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_edge);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers11 = (ksEntityCollectionPtr)chamferDef11->array();
	entityCollectionChamfers11->Clear(); // очищаем коллекцию
	entityColPart11->SelectByPoint(dGai / 2, lGai, 0); // получаем ребро по точке
	entityCollectionChamfers11->Add(entityColPart11->First()); // добавляем в массив
	entityChamfers11->Create();

	ksEntityPtr entityChamfers6 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef6 = entityChamfers6->GetDefinition();
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart6 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_face);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers6 = (ksEntityCollectionPtr)chamferDef6->array();
	entityCollectionChamfers6->Clear();
	entityColPart6->SelectByPoint(dGai/2+0.01, 0, 0);
	for (int i = 0; i < entityColPart6->GetCount(); i++) {
		ksEntityPtr face2 = entityColPart6->GetByIndex(i);

		face2->Putname("GaikaNiz");
		face2->Update();
	}
	ksEntityPtr entityChamfers10 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef10 = entityChamfers10->GetDefinition();
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart10 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_face);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers10 = (ksEntityCollectionPtr)chamferDef10->array();
	entityCollectionChamfers10->Clear();
	entityColPart10->SelectByPoint(dGRez/2, 2.5, 0);
	for (int i = 0; i < entityColPart10->GetCount(); i++) {
		ksEntityPtr face2 = entityColPart10->GetByIndex(i);

		face2->Putname("GaikaBok");
		face2->Update();
	}

	//Сальник

	pDOC->SaveAs("C:\\Users\\saintazimov\\Documents\\kyrsovaya_details\\Part2.m3d");

	pDOC = pKompasApp5->Document3D();

	pDOC->Create(false, true);

	pPart = pDOC->GetPart(pTop_Part);

	ksEntityPtr pSketch6 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch6->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch6->Create();
	p3DDoc = pSketchDef->BeginEdit();
	p3DDoc->ksCircle(0, 0, DSal/2, 1);
	pSketchDef->EndEdit();

	ksEntityPtr pSketch7 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch7->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch7->Create();
	p3DDoc = pSketchDef->BeginEdit();
	p3DDoc->ksCircle(0, 0, dSRez/2, 1);
	pSketchDef->EndEdit();

	ksEntityPtr bossExtr3 = pPart->NewEntity(o3d_baseExtrusion);
	ksBaseExtrusionDefinitionPtr ptelo5= telo->GetDefinition();
	ptelo5 = bossExtr3->GetDefinition();
	ptelo5->directionType = dtNormal;
	ptelo5->SetSketch(pSketch6);
	ptelo5->SetSideParam(true, 0, lSal * 4 / 5, 0, true);
	bossExtr3->Create();

	ksEntityPtr cutExtr1 = pPart->NewEntity(o3d_cutExtrusion);
	ksCutExtrusionDefinitionPtr ptelo6 = cutExtr1->GetDefinition();
	ptelo6->directionType = dtReverse;
	ptelo6->SetSketch(pSketch7);
	ptelo6->SetSideParam(true, etBlind, lSal * 4 / 5, 0, false);//A это глубина выреза
	ptelo6->SetSideParam(false, etBlind, lSal * 4 / 5, 0, false);//A это глубина выреза
	cutExtr1->Create();

	ksEntityPtr basePlaneOffset1 = (ksEntityPtr)pPart->NewEntity(o3d_planeOffset);
	ksPlaneOffsetDefinitionPtr offsetPlaneDef1 = basePlaneOffset1->GetDefinition();
	offsetPlaneDef1->direction = true;
	// расстояние
	offsetPlaneDef1->offset = lSal * 4 / 5;
	// плоскость, относительно которой будет проходить смещение
	offsetPlaneDef1->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));
	// создаём плоскость
	basePlaneOffset1->Create();

	
	ksEntityPtr pSketch8 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch8->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(basePlaneOffset1);//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch8->Create();
	p3DDoc = pSketchDef->BeginEdit();

	double onex,twox,treex,fourx,fivex,sixx, oney, twoy, treey, foury, fivey, sixy;

	onex = sqrt(D2Sal / 2 * D2Sal / 2 - B1Sal / 2 * B1Sal / 2);
	oney = B1Sal / 2;
	twox = sqrt(D2Sal / 2 * D2Sal / 2 - B1Sal / 2 * B1Sal / 2);
	twoy = -B1Sal / 2;

	double f1 = atan((B1Sal / 2) / sqrt(D2Sal / 2 * D2Sal / 2 - B1Sal / 2 * B1Sal / 2));
	double f2 = atan((-B1Sal / 2) / sqrt(D2Sal / 2 * D2Sal / 2 - B1Sal / 2 * B1Sal / 2));
	
	f1 = f1 + 120 * 3.14 / 180;
	f2 = f2 + 120 * 3.14 / 180;

	treex = D2Sal / 2 * cos(f1);
	treey = D2Sal / 2 * sin(f1);
	fourx = D2Sal / 2 * cos(f2);
	foury = D2Sal / 2 * sin(f2);

	f1 = f1 + 120 * 3.14 / 180;
	f2 = f2 + 120 * 3.14 / 180;

	fivex = D2Sal / 2 * cos(f1);
	fivey = D2Sal / 2 * sin(f1);
	sixx = D2Sal / 2 * cos(f2);
	sixy = D2Sal / 2 * sin(f2);

	p3DDoc->ksLineSeg(onex, oney, sixx, sixy,1);
	p3DDoc->ksLineSeg(twox, twoy, fivex, fivey, 1);
	p3DDoc->ksLineSeg(treex, treey, twox, twoy, 1);
	p3DDoc->ksLineSeg(treex, treey, sixx, sixy, 1);
	p3DDoc->ksLineSeg(onex, oney, fourx, foury, 1);
	p3DDoc->ksLineSeg(fivex, fivey, fourx, foury, 1);
	pSketchDef->EndEdit();

	ksEntityPtr bossExtr4 = pPart->NewEntity(o3d_baseExtrusion);
	ksBaseExtrusionDefinitionPtr ptelo7 = telo->GetDefinition();
	ptelo7 = bossExtr4->GetDefinition();
	ptelo7->directionType = dtNormal;
	ptelo7->SetSketch(pSketch8);
	ptelo7->SetSideParam(true, 0, lSal * 1 / 5, 0, true);
	bossExtr4->Create();
	
	//вырезаем отверстие
	ksEntityPtr pSketch9 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch9->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch9->Create();
	p3DDoc = pSketchDef->BeginEdit();
	p3DDoc->ksCircle(0, 0, dSal/2, 1);
	pSketchDef->EndEdit();

	ksEntityPtr cutExtr2 = pPart->NewEntity(o3d_cutExtrusion);
	ksCutExtrusionDefinitionPtr ptelo8 = cutExtr2->GetDefinition();
	ptelo8->directionType = dtReverse;
	ptelo8->SetSketch(pSketch9);
	ptelo8->SetSideParam(true, etBlind, lSal, 0, false);//A это глубина выреза
	ptelo8->SetSideParam(false, etBlind, lSal, 0, false);//A это глубина выреза
	cutExtr2->Create();

	ksEntityPtr pSketch10 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch10->GetDefinition();//получаем параметры эскиза
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));//плоскость созданную для отверстия пишем просто название смещ плоскости
	pSketch10->Create();
	p3DDoc = pSketchDef->BeginEdit();
	p3DDoc->ksCircle(-D1Sal/2, 0, d1Sal / 2, 1);
	pSketchDef->EndEdit();

	ksEntityPtr cutExtr3 = pPart->NewEntity(o3d_cutExtrusion);
	ksCutExtrusionDefinitionPtr ptelo9 = cutExtr3->GetDefinition();
	ptelo9->directionType = dtReverse;
	ptelo9->SetSketch(pSketch10);
	ptelo9->SetSideParam(true, etBlind, lSal, 0, false);//A это глубина выреза
	ptelo9->SetSideParam(false, etBlind, lSal, 0, false);//A это глубина выреза
	cutExtr3->Create();

	//резьба
	ksEntityPtr Thread1 = pPart->NewEntity(o3d_thread);
	// получаем интерфейс настроек резьбы
	ksThreadDefinitionPtr ThreadDef1 = Thread1->GetDefinition();
	ThreadDef1->allLength = true; // признак полной длины
	ThreadDef1->autoDefinDr = true;// признак автоопределения диаметра
	ThreadDef1->dr = dGRez; // номинальный диаметр резьбы
	ThreadDef1->length = lGai * 3 / 5; // длина резьбы
	ThreadDef1->faceValue = true; // направление построения резьбы
	ThreadDef1->p = ShagRez; // шаг резьбы
	// получаем коллекцию рёбер детали
	ksEntityCollectionPtr EdgeECol1 = (ksEntityCollectionPtr)pPart->EntityCollection(o3d_edge);
	// оставляем в массиве только ребро, проходящее через точку (x,y,z)
	EdgeECol1->SelectByPoint(dSRez / 2, 0, 0);
	ThreadDef1->SetBaseObject(EdgeECol1->First()); // устанавливаем ребро в параметры
	// создаёём резьбу
	Thread1->Create();

	//фаски
	ksEntityPtr entityChamfers1 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef1 = entityChamfers1->GetDefinition();
	// устанавливаем параметры фаски
	// (признак направленичя фаски, размер первого катета, размер второго катета)
	chamferDef1->SetChamferParam(true, 1, 1);
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart1 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_edge);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers1 = (ksEntityCollectionPtr)chamferDef1->array();
	entityCollectionChamfers1->Clear(); // очищаем коллекцию
	entityColPart1->SelectByPoint(dSRez / 2, 0, 0); // получаем ребро по точке
	entityCollectionChamfers1->Add(entityColPart1->First()); // добавляем в массив
	entityChamfers1->Create();

	ksEntityPtr entityChamfers2 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef2 = entityChamfers2->GetDefinition();
	// устанавливаем параметры фаски
	// (признак направленичя фаски, размер первого катета, размер второго катета)
	chamferDef2->SetChamferParam(true, faska, faska);
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart2 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_edge);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers2 = (ksEntityCollectionPtr)chamferDef2->array();
	entityCollectionChamfers2->Clear(); // очищаем коллекцию
	entityColPart2->SelectByPoint(dSal/2, lSal, 0); // получаем ребро по точке
	entityCollectionChamfers2->Add(entityColPart2->First()); // добавляем в массив
	entityChamfers2->Create();

	ksEntityPtr entityChamfers3 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef3 = entityChamfers3->GetDefinition();
	// устанавливаем параметры фаски
	// (признак направленичя фаски, размер первого катета, размер второго катета)
	chamferDef3->SetChamferParam(true, (d2Sal-d1Sal)/2, (d2Sal - d1Sal) / 2);
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart3 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_edge);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers3 = (ksEntityCollectionPtr)chamferDef3->array();
	entityCollectionChamfers3->Clear(); // очищаем коллекцию
	entityColPart3->SelectByPoint(-D1Sal/2-d1Sal/2, lSal, 0);
	entityCollectionChamfers3->Add(entityColPart3->First()); // добавляем в массив
	entityChamfers3->Create();
	
	


	ksEntityPtr circCopy = pPart->NewEntity(o3d_circularCopy);
	// получаем свойства кругового массива
	ksCircularCopyDefinitionPtr circCopyDef = circCopy->GetDefinition();
	// создаём ось вращения на основе базовой
	ksEntityPtr baseAxisY = (ksEntityPtr)pPart->GetDefaultEntity(o3d_axisOY);
	// выставляем базовую ось
	circCopyDef->SetAxis(baseAxisY);
	// значение для кругового массива, 3 копии 120 градусов
	circCopyDef->SetCopyParamAlongDir(3, 120, false, false);
	// создаём коллекцию для копируемых элементов
	ksEntityCollectionPtr EntityCollection = circCopyDef->GetOperationArray();
	// очищаем её
	EntityCollection->Clear();
	// добавляем элемент выдавливания в коллекци.
	EntityCollection->Add(cutExtr3);
	// создаём массив
	circCopy->Create();



	ksEntityPtr circCopy1 = pPart->NewEntity(o3d_circularCopy);
	// получаем свойства кругового массива
	ksCircularCopyDefinitionPtr circCopyDef1 = circCopy1->GetDefinition();
	// создаём ось вращения на основе базовой
	ksEntityPtr baseAxisY1 = (ksEntityPtr)pPart->GetDefaultEntity(o3d_axisOY);
	// выставляем базовую ось
	circCopyDef1->SetAxis(baseAxisY1);
	// значение для кругового массива, 3 копии 120 градусов
	circCopyDef1->SetCopyParamAlongDir(3, 120, false, false);
	// создаём коллекцию для копируемых элементов
	ksEntityCollectionPtr EntityCollection1 = circCopyDef1->GetOperationArray();
	// очищаем её
	EntityCollection1->Clear();
	// добавляем элемент выдавливания в коллекци.
	EntityCollection1->Add(entityChamfers3);
	// создаём массив
	circCopy1->Create();

	ksEntityPtr entityChamfers4 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef4 = entityChamfers4->GetDefinition();
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart4 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_face);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers4 = (ksEntityCollectionPtr)chamferDef4->array();
	entityCollectionChamfers4->Clear(); // очищаем коллекцию
	entityColPart4->SelectByPoint(dSal/2+0.01, lSal*4/5, 0);
	for (int i = 0; i < entityColPart4->GetCount(); i++) {
		ksEntityPtr face = entityColPart4->GetByIndex(i);

		face->Putname("SalnikNutr");
		face->Update();
	}
	ksEntityPtr entityChamfers5 = (ksEntityPtr)pPart->NewEntity(o3d_chamfer);
	// поллучаем интерфейс настроек создания фаски
	ksChamferDefinitionPtr chamferDef5 = entityChamfers5->GetDefinition();
	// получаем коллекцию граней модели
	ksEntityCollectionPtr entityColPart5 =
		(ksEntityCollectionPtr)pPart->EntityCollection(o3d_face);
	// получаем коллекцию граней для создания фаски
	ksEntityCollectionPtr entityCollectionChamfers5 = (ksEntityCollectionPtr)chamferDef5->array();
	entityCollectionChamfers5->Clear();
	entityColPart5->SelectByPoint(DSal/2, 1, 0);
	for (int i = 0; i < entityColPart5->GetCount(); i++) {
		ksEntityPtr face1 = entityColPart5->GetByIndex(i);

		face1->Putname("SalniknBok");
		face1->Update();
	}

	//создаем сборку
	pDOC->SaveAs("C:\\Users\\saintazimov\\Documents\\kyrsovaya_details\\Part3.m3d");

	pDOC = pKompasApp5->Document3D();
	pDOC->Create(false, false);
	//pDocsb = pKompasApp5->ActiveDocument3D();
	pPart = pDOC->GetPart(pTop_Part);
	ksPartPtr Shaiba1, Shaiba2, Salnik, Gaika, kolzo2;

	pDOC->SetPartFromFile(L"C:\\Users\\saintazimov\\Documents\\kyrsovaya_details\\Part1.m3d", pPart, VARIANT_FALSE);
	pDOC->SetPartFromFile(L"C:\\Users\\saintazimov\\Documents\\kyrsovaya_details\\Part1.m3d", pPart, VARIANT_FALSE);
	pDOC->SetPartFromFile(L"C:\\Users\\saintazimov\\Documents\\kyrsovaya_details\\Part3.m3d", pPart, VARIANT_FALSE);
	pDOC->SetPartFromFile(L"C:\\Users\\saintazimov\\Documents\\kyrsovaya_details\\Part2.m3d", pPart, VARIANT_FALSE);
	ksPartCollectionPtr partCollect = pDOC->PartCollection(VARIANT_TRUE);


	Shaiba1 = pDOC->GetPart(0);
	Shaiba2 = pDOC->GetPart(1);
	Salnik = pDOC->GetPart(2);
	Gaika = pDOC->GetPart(3);
	ksEntityCollectionPtr PartCol;

	pPart = partCollect->GetByIndex(0);//шайба1
	PartCol = pPart->EntityCollection(o3d_unknown);
	ksEntityPtr Shaiba1Niz = PartCol->GetByName("ShaibaNiz", true, true);
	ksEntityPtr Shaiba1Verx = PartCol->GetByName("ShaibaVerx", true, true);
	ksEntityPtr Shaiba1Bok = PartCol->GetByName("ShaibaBok", true, true);
	
	pPart = partCollect->GetByIndex(1);//шайба2
	PartCol = pPart->EntityCollection(o3d_unknown);
	ksEntityPtr Shaiba2Niz = PartCol->GetByName("ShaibaNiz", true, true);
	ksEntityPtr Shaiba2Verx = PartCol->GetByName("ShaibaVerx", true, true);
	ksEntityPtr Shaiba2Bok = PartCol->GetByName("ShaibaBok", true, true);
	
	pPart = partCollect->GetByIndex(2);//сальник
	PartCol = pPart->EntityCollection(o3d_unknown);
	ksEntityPtr SalnikNutr = PartCol->GetByName("SalnikNutr", true, true);
	ksEntityPtr SalnikBok = PartCol->GetByName("SalniknBok", true, true);
	
	pPart = partCollect->GetByIndex(3);//гайка
	PartCol = pPart->EntityCollection(o3d_unknown);
	ksEntityPtr GaikaNiz = PartCol->GetByName("GaikaNiz", true, true);
	ksEntityPtr GaikaBok = PartCol->GetByName("GaikaBok", true, true);
	
	pDOC->AddMateConstraint(mc_Concentric, SalnikBok, Shaiba1Bok, 0, 1, 0);
	pDOC->AddMateConstraint(mc_Concentric, SalnikBok, GaikaBok, -1, 1, 0);
	pDOC->AddMateConstraint(mc_Concentric, SalnikBok, Shaiba2Bok, 0, 1, 0);
	pDOC->AddMateConstraint(mc_Distance, Shaiba2Niz, Shaiba1Verx, 0, 1, 0);
	pDOC->AddMateConstraint(mc_Distance, Shaiba1Niz, SalnikNutr, 0, 2, 0);
	pDOC->AddMateConstraint(mc_Distance, GaikaNiz, SalnikNutr, 0, 2, lSal*1.5/5);
	

	
	pDOC->RebuildDocument();
	pDOC->SaveAs("C:\\Users\\saintazimov\\Documents\\kyrsovaya_details\\sborka.a3d");
	
}
