
// Kyrsov2020Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Kyrsov2020.h"
#include "Kyrsov2020Dlg.h"
#include "afxdialogex.h"
#include <fstream>
#include "string.h"
#include <list>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CKyrsov2020Dlg



CKyrsov2020Dlg::CKyrsov2020Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KYRSOV2020_DIALOG, pParent)
	, ec_surname(_T(""))
	, ec_name(_T(""))
	, ec_otc(_T(""))
	, ec_year_admission(0)
	, ec_faculty(_T(""))
	, ec_department(_T(""))
	, ec_group(_T(""))
	, ec_number_book(_T(""))
	, ec_birthday(CTime::GetCurrentTime())
	, ec_gender(_T(""))
	, ec_subject1(_T(""))
	, ec_subject2(_T(""))
	, ec_subject3(_T(""))
	, ec_subject4(_T(""))
	, ec_subject5(_T(""))
	, ec_subject6(_T(""))
	, ec_subject7(_T(""))
	, ec_subject8(_T(""))
	, ec_subject9(_T(""))
	, ec_subject10(_T(""))
	, ec_session(0)
	, ec_value1(0)
	, ec_value2(0)
	, ec_value3(0)
	, ec_value4(0)
	, ec_value5(0)
	, ec_value6(0)
	, ec_value7(0)
	, ec_value8(0)
	, ec_value9(0)
	, ec_value10(0)
	, ec_year(0)
	, ec_month(0)
	, rewriting(false)// не нужно
	, ec_day(0)
{
	m_pDlg1 = NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKyrsov2020Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, ec_surname);
	DDX_Text(pDX, IDC_EDIT8, ec_name);
	DDX_Text(pDX, IDC_EDIT3, ec_otc);
	DDX_Text(pDX, IDC_EDIT6, ec_year_admission);
	DDX_Text(pDX, IDC_EDIT5, ec_faculty);
	DDX_Text(pDX, IDC_EDIT4, ec_department);
	DDX_Text(pDX, IDC_EDIT7, ec_group);
	DDX_Text(pDX, IDC_EDIT1, ec_number_book);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, ec_birthday);
	DDX_CBString(pDX, IDC_COMBO1, ec_gender);
	DDX_Text(pDX, IDC_EDIT18, ec_subject1);
	DDX_Text(pDX, IDC_EDIT19, ec_subject2);
	DDX_Text(pDX, IDC_EDIT10, ec_subject3);
	DDX_Text(pDX, IDC_EDIT11, ec_subject4);
	DDX_Text(pDX, IDC_EDIT12, ec_subject5);
	DDX_Text(pDX, IDC_EDIT13, ec_subject6);
	DDX_Text(pDX, IDC_EDIT14, ec_subject7);
	DDX_Text(pDX, IDC_EDIT15, ec_subject8);
	DDX_Text(pDX, IDC_EDIT16, ec_subject9);
	DDX_Text(pDX, IDC_EDIT17, ec_subject10);
	DDX_CBIndex(pDX, IDC_COMBO3, ec_session);
	DDX_CBIndex(pDX, IDC_COMBO13, ec_value1);
	DDX_CBIndex(pDX, IDC_COMBO12, ec_value2);
	DDX_CBIndex(pDX, IDC_COMBO4, ec_value3);
	DDX_CBIndex(pDX, IDC_COMBO5, ec_value4);
	DDX_CBIndex(pDX, IDC_COMBO6, ec_value5);
	DDX_CBIndex(pDX, IDC_COMBO7, ec_value6);
	DDX_CBIndex(pDX, IDC_COMBO8, ec_value7);
	DDX_CBIndex(pDX, IDC_COMBO9, ec_value8);
	DDX_CBIndex(pDX, IDC_COMBO10, ec_value9);
	DDX_CBIndex(pDX, IDC_COMBO11, ec_value10);
	DDX_Control(pDX, IDC_BUTTON4, but_Ref);
	DDX_Control(pDX, IDC_BUTTON2, but_write);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, ct_control);
	DDX_Control(pDX, IDC_EDIT20, cbc_day);
	DDX_Control(pDX, IDC_EDIT9, cbc_month);
	DDX_Control(pDX, IDC_EDIT21, cbc_year);
	DDX_Text(pDX, IDC_EDIT21, ec_year);
	DDX_Text(pDX, IDC_EDIT9, ec_month);
	DDX_Text(pDX, IDC_EDIT20, ec_day);
	DDX_Control(pDX, IDC_BUTTON3, bt_session);
	DDX_Control(pDX, IDC_COMBO3, cb_session);
}

BEGIN_MESSAGE_MAP(CKyrsov2020Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CKyrsov2020Dlg::OnBnClickedButton2)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CKyrsov2020Dlg::OnDtnDatetimechangeDatetimepicker1)
	ON_BN_CLICKED(IDC_BUTTON3, &CKyrsov2020Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CKyrsov2020Dlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CKyrsov2020Dlg::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON4, &CKyrsov2020Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// Обработчики сообщений CKyrsov2020Dlg





BOOL CKyrsov2020Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	fillSession();
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CKyrsov2020Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CKyrsov2020Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CKyrsov2020Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool valid(CString str) {
	string s = (CT2CA)str.GetString();
	for (int i = 0; i < strlen(s.c_str()); i++)
	{
		if (s[i] >= '0' && s[i] <= '9') {
			 MessageBoxA(NULL, "Цифры в поле", "Ошибка", MB_ICONERROR | MB_OK); 
			 return true; 
		}
		if (s[i] == ' ' ) {
			MessageBoxA(NULL, "Пробел", "Ошибка", MB_ICONERROR | MB_OK);
			return true;
		}
	}
	return false;
}

void CKyrsov2020Dlg::OnBnClickedButton2()
{
	
	UpdateData();
	if (ec_surname == "" || valid(ec_surname) || ec_name == "" || valid(ec_name) || ec_otc == "" || valid(ec_otc)) { MessageBoxA(NULL, "Не  заполненны поля: ФИО", "Ошибка", MB_ICONERROR | MB_OK); return; }
	ec_student.surname = ec_surname; ec_student.name = ec_name; ec_student.otc = ec_otc;
	if(ec_year == 0 || ec_day == 0 || ec_month == 0 ){ MessageBoxA(NULL, "Не  заполненны поля: Год рождения", "Ошибка", MB_ICONERROR | MB_OK); return; }
	ec_student.birthday[0] = ec_day; ec_student.birthday[1] = ec_month; ec_student.birthday[2] = ec_year;
	if (ec_gender == "") { ec_student.gender = "Н.у."; } else ec_student.gender = ec_gender;
	if(ec_faculty == "" || valid(ec_faculty) || ec_department == "" || ec_year_admission == 0) {MessageBoxA(NULL, "Не  заполненны поля: Год поступления, Факультет, Кафедра", "Ошибка", MB_ICONERROR | MB_OK); return;}
	ec_student.faculty = ec_faculty; ec_student.department = ec_department; ec_student.year_admission = ec_year_admission;
	if (ec_group == ""  || ec_number_book == "") { MessageBoxA(NULL, "Не  заполненны поля: Группа, Номер ЗК", "Ошибка", MB_ICONERROR | MB_OK); return;}
	ec_student.group = ec_group; ec_student.number_book = ec_number_book;
	UpdateData(false);
	std::ofstream out("bd.txt", std::ios_base::app);
	if (!out.is_open()) { MessageBoxA(NULL, "Не удалось открыть файл", "Fille not open", MB_ICONERROR | MB_OK); return; }
	out << ec_student.surname << " " << ec_student.name << " " << ec_student.otc << " " << ec_student.birthday[0] << " " << ec_student.birthday[1] << " " << ec_student.birthday[2] << " "
		<< ec_student.gender << " " << ec_student.year_admission << " " << ec_student.faculty << " " << ec_student.department << " "
		<< ec_student.group << " " << ec_student.number_book << " ";
	for (int i = 0; i < 9; i++) {
		out << i << " ";
		for (int j = 0; j < 10; j++)
		{
			out << ec_student.progress[i].name_subject[j] << " " << ec_student.progress[i].value[j] << " ";
		}
	}
	out << "\n";
	out.close();

	// TODO: добавьте свой код обработчика уведомлений
}



void CKyrsov2020Dlg::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData();
	CTime m = ec_birthday.GetTime();
	ec_year = m.GetYear();
	ec_day = m.GetDay();
	ec_month = m.GetMonth();
	UpdateData(false);
	*pResult = 0;
}


void CKyrsov2020Dlg::OnBnClickedButton3()
{
	UpdateData();
	if (ec_subject1 != "" || valid(ec_subject1)) { ec_student.progress[ec_session].name_subject[0] = ec_subject1; ec_student.progress[ec_session].value[0] = ec_value1; }
	if (ec_subject2 != "" || valid(ec_subject2)) { ec_student.progress[ec_session].name_subject[1] = ec_subject2; ec_student.progress[ec_session].value[1] = ec_value2; }
	if (ec_subject3 != "" || valid(ec_subject3)) { ec_student.progress[ec_session].name_subject[2] = ec_subject3; ec_student.progress[ec_session].value[2] = ec_value3; }
	if (ec_subject4 != "" || valid(ec_subject4)) { ec_student.progress[ec_session].name_subject[3] = ec_subject4; ec_student.progress[ec_session].value[3] = ec_value4; }
	if (ec_subject5 != "" || valid(ec_subject5)) { ec_student.progress[ec_session].name_subject[4] = ec_subject5; ec_student.progress[ec_session].value[4] = ec_value5; }
	if (ec_subject6 != "" || valid(ec_subject6)) { ec_student.progress[ec_session].name_subject[5] = ec_subject6; ec_student.progress[ec_session].value[5] = ec_value6; }
	if (ec_subject7 != "" || valid(ec_subject7)) { ec_student.progress[ec_session].name_subject[6] = ec_subject7; ec_student.progress[ec_session].value[6] = ec_value7; }
	if (ec_subject8 != "" || valid(ec_subject8)) { ec_student.progress[ec_session].name_subject[7] = ec_subject8; ec_student.progress[ec_session].value[7] = ec_value8; }
	if (ec_subject9 != "" || valid(ec_subject9)) { ec_student.progress[ec_session].name_subject[8] = ec_subject9; ec_student.progress[ec_session].value[8] = ec_value9; }
	if (ec_subject10 != "" || valid(ec_subject10)) { ec_student.progress[ec_session].name_subject[9] = ec_subject10; ec_student.progress[ec_session].value[9] = ec_value10; }
	UpdateData(false);
	// TODO: добавьте свой код обработчика уведомлений
}



void CKyrsov2020Dlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (m_pDlg1 == NULL) {
		m_pDlg1 = new CDLG1(this);
		m_pDlg1->Create(IDD_DIALOG1);
		m_pDlg1->createTable(m_pDlg1->tableStudents);
	}
	else {
		m_pDlg1->SetActiveWindow();
	}
	m_pDlg1->ShowWindow(SW_SHOWNORMAL);
}


void CKyrsov2020Dlg::OnCbnSelchangeCombo3()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CKyrsov2020Dlg::OnBnClickedButton4()
{
	// TODO: добавьте свой код обработчика уведомлений
	but_Ref.EnableWindow(false); bt_session.EnableWindow(true);
	but_write.EnableWindow(true); cb_session.EnableWindow(true);
	ct_control.EnableWindow(true);
	cbc_day.EnableWindow(false); cbc_month.EnableWindow(false); cbc_year.EnableWindow(false);
	UpdateData();
	if (ec_surname == "" || ec_name == "" || ec_otc == "") { MessageBoxA(NULL, "Не  заполненны поля: ФИО", "Ошибка", MB_ICONERROR | MB_OK); return; }
	m_pDlg1->struct_st.surname = ec_surname; m_pDlg1->struct_st.name = ec_name; m_pDlg1->struct_st.otc = ec_otc;
	if (ec_year == 0 || ec_day == 0 || ec_month == 0) { MessageBoxA(NULL, "Не  заполненны поля: Год рождения", "Ошибка", MB_ICONERROR | MB_OK); return; }
	m_pDlg1->struct_st.birthday[0] = ec_day; m_pDlg1->struct_st.birthday[1] = ec_month; m_pDlg1->struct_st.birthday[2] = ec_year;
	if (ec_gender == "") { m_pDlg1->struct_st.gender = "Не указан"; return;}
	else m_pDlg1->struct_st.gender = ec_gender;
	if (ec_faculty == "" || ec_department == "" || ec_year_admission == 0) { MessageBoxA(NULL, "Не  заполненны поля: Год поступления, Факультет, Кафедра", "Ошибка", MB_ICONERROR | MB_OK); return; }
	m_pDlg1->struct_st.faculty = ec_faculty; m_pDlg1->struct_st.department = ec_department; m_pDlg1->struct_st.year_admission = ec_year_admission;
	if (ec_group == "" || ec_number_book == "") { MessageBoxA(NULL, "Не  заполненны поля: Группа, Номер ЗК", "Ошибка", MB_ICONERROR | MB_OK); return;}
	m_pDlg1->struct_st.group = ec_group; m_pDlg1->struct_st.number_book = ec_number_book;
	m_pDlg1->struct_st.progress[ec_session].name_subject[0] = ec_subject1; m_pDlg1->struct_st.progress[ec_session].value[0] = ec_value1;
	m_pDlg1->struct_st.progress[ec_session].name_subject[1] = ec_subject2; m_pDlg1->struct_st.progress[ec_session].value[1] = ec_value2;
	m_pDlg1->struct_st.progress[ec_session].name_subject[2] = ec_subject3; m_pDlg1->struct_st.progress[ec_session].value[2] = ec_value3;
	m_pDlg1->struct_st.progress[ec_session].name_subject[3] = ec_subject4; m_pDlg1->struct_st.progress[ec_session].value[3] = ec_value4;
	m_pDlg1->struct_st.progress[ec_session].name_subject[4] = ec_subject5; m_pDlg1->struct_st.progress[ec_session].value[4] = ec_value5;
	m_pDlg1->struct_st.progress[ec_session].name_subject[5] = ec_subject6; m_pDlg1->struct_st.progress[ec_session].value[5] = ec_value6;
	m_pDlg1->struct_st.progress[ec_session].name_subject[6] = ec_subject7; m_pDlg1->struct_st.progress[ec_session].value[6] = ec_value7;
	m_pDlg1->struct_st.progress[ec_session].name_subject[7] = ec_subject8; m_pDlg1->struct_st.progress[ec_session].value[7] = ec_value8;
	m_pDlg1->struct_st.progress[ec_session].name_subject[8] = ec_subject9; m_pDlg1->struct_st.progress[ec_session].value[8] = ec_value9;
	m_pDlg1->struct_st.progress[ec_session].name_subject[9] = ec_subject10; m_pDlg1->struct_st.progress[ec_session].value[9] = ec_value10;
	m_pDlg1->RewritingStudent(ec_session);
	m_pDlg1->Rewriting();
	m_pDlg1->b_creat.EnableWindow(true);
	m_pDlg1->bt_delete.EnableWindow(true);
	m_pDlg1->OnBnClickedButton1();
	UpdateData(false);
	
}
