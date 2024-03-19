
// Kursach.h: основной файл заголовка для приложения Kursach
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CKursachApp:
// Сведения о реализации этого класса: Kursach.cpp
//

class CKursachApp : public CWinApp
{
public:
	CKursachApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKursachApp theApp;
