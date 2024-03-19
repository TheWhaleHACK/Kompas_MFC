﻿
// KursachDoc.h: интерфейс класса CKursachDoc 
//
#pragma once
class CKursachView;
class CMyTreeView;
class CKursachDoc : public CDocument
{
protected: // создать только из сериализации
	CKursachDoc() noexcept;
	DECLARE_DYNCREATE(CKursachDoc)

// Атрибуты
public:
			
	CKursachView* pView;
	CMyTreeView* pTree;

	bool m_bGaika, m_bSalnik, m_bShaiba, m_bSborka;

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CKursachDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};