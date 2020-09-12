#pragma once
#include <Windows.h>
#include <wincrypt.h>
#include <stdio.h>

#include <string.h>
#include "afxdialogex.h"

using namespace std;
class Сryptographer {
public:
	CStringA Crypting(CStringA str) {
		HCRYPTPROV hProv;
		HCRYPTKEY hSessionKey;
		const char *chrstr = str;
		DWORD count = strlen(chrstr);
		if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) { MessageBoxA(NULL, "CryptAcquireContext", "Ошибка шифровщика", MB_ICONERROR | MB_OK); return NULL; }
		if (!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey)) { MessageBoxA(NULL, "CryptGenKey", "Ошибка шифровщика", MB_ICONERROR | MB_OK); return NULL; }
		if (!CryptEncrypt(hSessionKey, 0, true, 0, (BYTE*)chrstr, &count, strlen(chrstr))) { MessageBoxA(NULL, "CryptEncrypt", "Ошибка шифровщика", MB_ICONERROR | MB_OK); return NULL; }
		ofstream out("Key.txt");
		if (!out.is_open()) {
			MessageBoxA(NULL, "Не удалось открыть файл: Key", "Fille not open", MB_ICONERROR | MB_OK); return NULL;
		}
		out << hSessionKey;
		out.close();
		str = chrstr;
		return str;
	}
};
class clStudent: public Сryptographer {
	struct Session
	{
		CString name_subject[10];
		int value[10];
	};
	int pos = 0;

	CString getElement(CString str) {
		CString element = _T("");
		for (pos; str[pos] != _T(' ') && pos != str.GetLength(); pos++) {	//Проверка на конец строки
			element += str[pos];
		}
		if (pos != str.GetLength()) { pos++; }
		return element;
	}

	void AddStudent(CString str) {
		surname = (LPCTSTR) getElement(str);
		name = getElement(str);
		otc = getElement(str);
		CString buf;
		buf = getElement(str);
		CSTRbirthday = buf; birthday[0] = _wtoi(buf.GetString());
		buf = getElement(str);
		CSTRbirthday += '.' + buf;	birthday[1] = _wtoi(buf.GetString());
		buf = getElement(str);
		CSTRbirthday += '.' + buf; birthday[2] = _wtoi(buf.GetString());
		gender = getElement(str);
		CSTRyear_admission = getElement(str); year_admission = _wtoi(CSTRyear_admission.GetString());
		faculty = getElement(str);
		department = getElement(str);
		group = getElement(str);
		number_book = getElement(str);
		for (int i = 0; i < 9; i++) {
			getElement(str);
			for (int j = 0; j < 10; j++) {
				progress[i].name_subject[j] = getElement(str);
				progress[i].value[j] = _wtoi(getElement(str));
			}
		}
	}
	void AddData(CListCtrl &ctrl, int row, int col, CString str)
	{
		LVITEM lv;
		lv.iItem = row;
		lv.iSubItem = col;
		lv.pszText = (LPTSTR)(LPCTSTR)str;
		lv.mask = LVIF_TEXT;
		if (col == 0)
			ctrl.InsertItem(&lv);
		else
			ctrl.SetItem(&lv);
	}
public:
	clStudent(CString str) { AddStudent(str); }

	CString name, surname, otc;
	CString CSTRbirthday;
	int birthday[3];
	CString CSTRyear_admission;
	int year_admission;
	CString faculty, department, group, number_book, gender;
	Session progress[9];

	void addToTable(CListCtrl &ctrl, int totalCount, int numSession) {
		CString number; number.Format(_T("%d"), totalCount + 1);
		AddData(ctrl, totalCount, 0, number);
		ctrl.SetItemText(totalCount, 1, surname);
		ctrl.SetItemText(totalCount, 2, name);
		ctrl.SetItemText(totalCount, 3, otc);
		ctrl.SetItemText(totalCount, 4, CSTRbirthday);
		ctrl.SetItemText(totalCount, 5, gender);
		ctrl.SetItemText(totalCount, 6, CSTRyear_admission);
		ctrl.SetItemText(totalCount, 7, faculty);
		ctrl.SetItemText(totalCount, 8, department);
		ctrl.SetItemText(totalCount, 9, group);
		ctrl.SetItemText(totalCount, 10, number_book);
		CString sub = _T(""); CString val = _T("");
		for (int i = 0; i < 10; i++)
		{
			if (progress[numSession].name_subject[i] != _T("#")) {
				sub += progress[numSession].name_subject[i] + _T(";");
				CString strVal; strVal.Format(_T("%d"), progress[numSession].value[i]);
				val += strVal + _T(";");
			}
		}
		if (sub != _T("")) {
			ctrl.SetItemText(totalCount, 11, sub);
			ctrl.SetItemText(totalCount, 12, val);
		}
		else {
			ctrl.SetItemText(totalCount, 11, _T("Нет"));
			ctrl.SetItemText(totalCount, 12, _T("Нет"));
		}
	}
	CStringA StudentToStr(bool DataView) {// DataView - вид даты ДР в строке: 0 - ДД.ММ.ГГГГ 1 - ДД ММ ГГГГ
		CStringA str = "";
		str += surname += " "; str += name += " "; str += otc += " ";
		CStringA strDay, strMonth, strYear; strDay.Format("%d", birthday[0]); strMonth.Format("%d", birthday[1]); strYear.Format("%d", birthday[2]);
		if (!DataView) {
			str += strDay += " "; str += strMonth += " "; str += strYear += " ";
		}
		else { str += strDay += "."; str += strMonth += "."; str += strYear += " "; }
		str += gender += " "; CStringA strYearAdm; strYearAdm.Format("%d", year_admission); str += strYearAdm += " ";
		str += faculty += " "; str += department += " "; str += group += " "; str += number_book += " ";
		for (int i = 0; i < 9; i++)
		{
			if (DataView) { str += "|"; }
			for (int j = 0; j < 10; j++)
			{
				if (DataView) {
					if (progress[i].name_subject[j] != "-") {
						str += progress[i].name_subject[j] += " ";
						CStringA strVal; strVal.Format("%d", progress[i].value[j]);
						str += strVal += ";";
					}
				}
				else
				{
					str += progress[i].name_subject[j] += " ";
					CStringA strVal; strVal.Format("%d", progress[i].value[j]);
					str += strVal += " ";
				}

			}
		}
		return str;
	}
};