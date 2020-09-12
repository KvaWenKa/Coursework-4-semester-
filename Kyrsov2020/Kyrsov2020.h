
// Kyrsov2020.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// основные символы


// CKyrsov2020App:
// Сведения о реализации этого класса: Kyrsov2020.cpp
//

class CKyrsov2020App : public CWinApp
{
public:
	CKyrsov2020App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CKyrsov2020App theApp;
