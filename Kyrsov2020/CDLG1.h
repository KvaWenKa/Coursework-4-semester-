#pragma once


// Диалоговое окно CDLG1

class CKyrsov2020Dlg;
class CDLG1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDLG1)
	
public:
	CDLG1(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CDLG1();
	CKyrsov2020Dlg*  m_pCKyrsov2020Dlg;
// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	struct Session
	{
		CStringA name_subject[10];
		int value[10];
	};

	struct Student
	{
		CStringA name, surname, otc;
		int birthday[3];
		int year_admission;
		CStringA faculty, department, group, number_book, gender;
		Session progress[9];
	};
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl tableStudents;
	int cb_session;
	afx_msg void OnBnClickedButton2();
	CButton b_ref;
	CButton b_creat;
	Student struct_st;
	void createTable(CListCtrl &ctrl) {
		CRect rect;
		ctrl.GetClientRect(&rect);
		int count;
		count = rect.Width() / 10.;
		ctrl.InsertColumn(0, _T("№"), LVCFMT_LEFT, count / 3);
		ctrl.InsertColumn(1, _T("Фамилия"), LVCFMT_LEFT, count);
		ctrl.InsertColumn(2, _T("Имя"), LVCFMT_LEFT, count);
		ctrl.InsertColumn(3, _T("Отчество"), LVCFMT_LEFT, count);
		ctrl.InsertColumn(4, _T("ДР"), LVCFMT_LEFT, count);
		ctrl.InsertColumn(5, _T("Пол"), LVCFMT_LEFT, count / 3);
		ctrl.InsertColumn(6, _T("Дата поступления"), LVCFMT_LEFT, count);
		ctrl.InsertColumn(7, _T("Факультет"), LVCFMT_LEFT, count);
		ctrl.InsertColumn(8, _T("Кафедра"), LVCFMT_LEFT, count);
		ctrl.InsertColumn(9, _T("Группа"), LVCFMT_LEFT, count);
		ctrl.InsertColumn(10, _T("Номер ЗЧ"), LVCFMT_LEFT, count);
		ctrl.InsertColumn(11, _T("Предметы"), LVCFMT_LEFT, count);
		ctrl.InsertColumn(12, _T("Оценки"), LVCFMT_LEFT, count / 3);
	}

	int numberRedact;
	
	afx_msg void Rewriting();
	void RewritingStudent(int curSession);
	CButton buttton_Search;
	BOOL cb_value3;
	BOOL cb_value4;
	BOOL cb_value5;
	afx_msg void OnBnClickedButton3();
	CButton bt_delete;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	int ec_inter_ot;
	int ec_inter_do;
};

