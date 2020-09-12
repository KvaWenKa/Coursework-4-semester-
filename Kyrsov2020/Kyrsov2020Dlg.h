
// Kyrsov2020Dlg.h: файл заголовка
//

#pragma once
#include "CDLG1.h"


using namespace std;
// Диалоговое окно CKyrsov2020Dlg
class CKyrsov2020Dlg : public CDialogEx
{
// Создание
	CDLG1 *m_pDlg1;
public:
	CKyrsov2020Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KYRSOV2020_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	struct Session
	{
		CStringA name_subject[10];
		int value[10];
	};


public:
	struct Student
	{
		CStringA name, surname, otc;
		int birthday[3];
		int year_admission;
		CStringA faculty, department, group, number_book, gender;
		Session progress[9];
	};
	CString ec_surname;
	CString ec_name;
	CString ec_otc;
	int ec_year_admission;
	CString ec_faculty;
	CString ec_department;
	CString ec_group;
	CString ec_number_book;
	bool rewriting;
	afx_msg void OnBnClickedButton2();
	CTime ec_birthday;
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	CString ec_gender;
	CString ec_subject1;
	CString ec_subject2;
	CString ec_subject3;
	CString ec_subject4;
	CString ec_subject5;
	CString ec_subject6;
	CString ec_subject7;
	CString ec_subject8;
	CString ec_subject9;
	CString ec_subject10;
	int ec_session;
	afx_msg void OnBnClickedButton3();
	int ec_value1;
	int ec_value2;
	int ec_value3;
	int ec_value4;
	int ec_value5;
	int ec_value6;
	int ec_value7;
	int ec_value8;
	int ec_value9;
	int ec_value10;
	afx_msg void OnBnClickedButton1();
	CButton but_Ref;
	CButton but_write;
	CDateTimeCtrl ct_control;
	CEdit cbc_day;
	CEdit cbc_month;
	CEdit cbc_year;
	int ec_year;
	int ec_month;
	int ec_day;
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnBnClickedButton4();
	Student ec_student;
	
	void fillSession() {
		for (int s = 0; s < 9; s++) {
			for (int i = 0; i < 10; i++) {
				ec_student.progress[s].name_subject[i] = "#";
				ec_student.progress[s].value[i] = 0;
			}
		}
	}
	CButton bt_session;
	CComboBox cb_session;
};
