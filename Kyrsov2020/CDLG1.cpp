// CDLG1.cpp: файл реализации
//

#include "pch.h"
#include "Kyrsov2020.h"
#include "CDLG1.h"
#include "afxdialogex.h"
#include "Kyrsov2020Dlg.h"
#include <fstream>
#include <string.h>
#include <list>
#include "Stud.h"

using namespace std;
// Диалоговое окно CDLG1

IMPLEMENT_DYNAMIC(CDLG1, CDialogEx)




CDLG1::CDLG1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, cb_session(0)
	, numberRedact(0)
	, cb_value3(FALSE)
	, cb_value4(FALSE)
	, cb_value5(FALSE)
	, ec_inter_ot(0)
	, ec_inter_do(0)
{
	m_pCKyrsov2020Dlg = (CKyrsov2020Dlg*)pParent;
}

CDLG1::~CDLG1()
{
}

void CDLG1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, tableStudents);
	DDX_CBIndex(pDX, IDC_COMBO3, cb_session);
	DDX_Control(pDX, IDC_BUTTON1, b_ref);
	DDX_Control(pDX, IDC_BUTTON2, b_creat);
	DDX_Text(pDX, IDC_EDIT1, numberRedact);
	DDX_Control(pDX, IDC_BUTTON3, buttton_Search);
	DDX_Check(pDX, IDC_CHECK1, cb_value3);
	DDX_Check(pDX, IDC_CHECK2, cb_value4);
	DDX_Check(pDX, IDC_CHECK3, cb_value5);
	DDX_Control(pDX, IDC_BUTTON4, bt_delete);
	DDX_Text(pDX, IDC_EDIT2, ec_inter_ot);
	DDX_Text(pDX, IDC_EDIT3, ec_inter_do);
}


BEGIN_MESSAGE_MAP(CDLG1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDLG1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDLG1::OnBnClickedButton2)
	ON_COMMAND(IDD_DIALOG1, &CDLG1::Rewriting)
	ON_BN_CLICKED(IDC_BUTTON3, &CDLG1::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDLG1::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDLG1::OnBnClickedButton5)
END_MESSAGE_MAP()



// Обработчики сообщений CDLG1

list<clStudent> baseStudent;

void ReadFile() {
	setlocale(LC_ALL, "Rus");

	CStdioFile reader;
	CFileException fileEx;
	CString s;
	if (reader.Open(_T("bd.txt"), CFile::modeRead, &fileEx)) {
		while (reader.ReadString(s)) {
		
			baseStudent.push_back(clStudent(s));
		}
	}
	reader.Close();
}



void CDLG1::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлени
	UpdateData();
	b_creat.EnableWindow(true);
	bt_delete.EnableWindow(true);
	tableStudents.DeleteAllItems();
	baseStudent.clear();
	ReadFile();
	int row = 0;
	for (list<clStudent>::iterator i = baseStudent.begin(); i != baseStudent.end(); i++) {
		(*i).addToTable(tableStudents, row, cb_session); row++;
		
	}
	buttton_Search.EnableWindow(true);
	numberRedact = 0;
	UpdateData(false);
}


void CDLG1::OnBnClickedButton2()
{
	UpdateData();
	if (numberRedact == 0 || numberRedact > (&baseStudent)->size()) { MessageBoxA(NULL, "Введенного номера не существует", "Редоктирование", MB_ICONERROR | MB_OK); }
	else {
		
		b_creat.EnableWindow(false);
		bt_delete.EnableWindow(false);
		list<clStudent>::iterator i = baseStudent.begin();
		for(int j = 0;j < numberRedact - 1;j++)i++;
		m_pCKyrsov2020Dlg->cb_session.EnableWindow(false);
		m_pCKyrsov2020Dlg->but_Ref.EnableWindow(true);
		m_pCKyrsov2020Dlg->but_write.EnableWindow(false);
		m_pCKyrsov2020Dlg->bt_session.EnableWindow(false);
		m_pCKyrsov2020Dlg->ec_surname = (*i).surname;
		m_pCKyrsov2020Dlg->ec_name = (*i).name;
		m_pCKyrsov2020Dlg->ec_otc = (*i).otc;
		m_pCKyrsov2020Dlg->ct_control.EnableWindow(false);
		m_pCKyrsov2020Dlg->cbc_day.EnableWindow(true);m_pCKyrsov2020Dlg->cbc_month.EnableWindow(true);m_pCKyrsov2020Dlg->cbc_year.EnableWindow(true);
		m_pCKyrsov2020Dlg->ec_day = (*i).birthday[0]; m_pCKyrsov2020Dlg->ec_month = (*i).birthday[1]; m_pCKyrsov2020Dlg->ec_year = (*i).birthday[2];
		m_pCKyrsov2020Dlg->ec_gender = (*i).gender;
		m_pCKyrsov2020Dlg->ec_year_admission = (*i).year_admission;
		m_pCKyrsov2020Dlg->ec_faculty = (*i).faculty; m_pCKyrsov2020Dlg->ec_department = (*i).department;
		m_pCKyrsov2020Dlg->ec_group = (*i).group; m_pCKyrsov2020Dlg->ec_number_book = (*i).number_book;
		m_pCKyrsov2020Dlg->rewriting = true;
		m_pCKyrsov2020Dlg->ec_session = cb_session;
		m_pCKyrsov2020Dlg->fillSession();
		m_pCKyrsov2020Dlg->ec_subject1 = (*i).progress[cb_session ].name_subject[0]; m_pCKyrsov2020Dlg->ec_value1 = (*i).progress[cb_session].value[0]; 
		m_pCKyrsov2020Dlg->ec_subject2 = (*i).progress[cb_session ].name_subject[1]; m_pCKyrsov2020Dlg->ec_value2 = (*i).progress[cb_session].value[1];
		m_pCKyrsov2020Dlg->ec_subject3 = (*i).progress[cb_session].name_subject[2]; m_pCKyrsov2020Dlg->ec_value3 = (*i).progress[cb_session].value[2];
		m_pCKyrsov2020Dlg->ec_subject4 = (*i).progress[cb_session].name_subject[3]; m_pCKyrsov2020Dlg->ec_value4 = (*i).progress[cb_session].value[3];
		m_pCKyrsov2020Dlg->ec_subject5 = (*i).progress[cb_session].name_subject[4]; m_pCKyrsov2020Dlg->ec_value5 = (*i).progress[cb_session].value[4];
		m_pCKyrsov2020Dlg->ec_subject6 = (*i).progress[cb_session].name_subject[5]; m_pCKyrsov2020Dlg->ec_value6 = (*i).progress[cb_session].value[5];
		m_pCKyrsov2020Dlg->ec_subject7 = (*i).progress[cb_session].name_subject[6]; m_pCKyrsov2020Dlg->ec_value7 = (*i).progress[cb_session].value[6];
		m_pCKyrsov2020Dlg->ec_subject8 = (*i).progress[cb_session].name_subject[7]; m_pCKyrsov2020Dlg->ec_value8 = (*i).progress[cb_session].value[7];
		m_pCKyrsov2020Dlg->ec_subject9 = (*i).progress[cb_session].name_subject[8]; m_pCKyrsov2020Dlg->ec_value9 = (*i).progress[cb_session].value[8];
		m_pCKyrsov2020Dlg->ec_subject10 = (*i).progress[cb_session].name_subject[9]; m_pCKyrsov2020Dlg->ec_value10 = (*i).progress[cb_session].value[9];
		
		m_pCKyrsov2020Dlg->UpdateData(false);
	}
}
void CDLG1::RewritingStudent(int curSession) {
	list<clStudent>::iterator i = baseStudent.begin();
	for (int j = 0; j < numberRedact - 1; j++)i++;
	(*i).surname = struct_st.surname;
	(*i).name = struct_st.name;
	(*i).otc = struct_st.otc;
	(*i).birthday[0] = struct_st.birthday[0]; (*i).birthday[1] = struct_st.birthday[1]; (*i).birthday[2] = struct_st.birthday[2];
	(*i).gender = struct_st.gender;
	(*i).year_admission = struct_st.year_admission;
	(*i).faculty = struct_st.faculty; (*i).department = struct_st.department;
	(*i).group = struct_st.group; (*i).number_book = struct_st.number_book;
	for (int k = 0; k < 10; k++) {
		(*i).progress[curSession].name_subject[k] = struct_st.progress[curSession].name_subject[k];
		(*i).progress[curSession].value[k] = struct_st.progress[curSession].value[k];
	}
}

void CDLG1::Rewriting()
{
	ofstream out("bd.txt");
	
	for (list<clStudent>::iterator i = baseStudent.begin(); i != baseStudent.end(); i++) {
		out << (CT2CA) (*i).surname << " " << (CT2CA)(*i).name << " " << (CT2CA)(*i).otc << " "
			<< (*i).birthday[0] << " " << (*i).birthday[1] << " " << (*i).birthday[2] << " "
			<< (CT2CA)(*i).gender << " " << (*i).year_admission << " " << (CT2CA)(*i).faculty << " "
			<< (CT2CA)(*i).department << " " << (CT2CA)(*i).group << " " << (CT2CA)(*i).number_book << " ";
		for (int s = 0; s < 9; s++) {
			out << s << " ";
			for (int j = 0; j < 10; j++)
			{
				out << (CT2CA)(*i).progress[s].name_subject[j] << " " << (*i).progress[s].value[j] << " ";
			}
		}
		out << "\n";
	}
	out.close();
}


void CDLG1::OnBnClickedButton3()
{
	UpdateData(true);
	if (ec_inter_do == 0 || ec_inter_ot > ec_inter_do) { MessageBoxA(NULL, "Ошибка интервала", "Выборка", MB_ICONERROR | MB_OK); return; }
	tableStudents.DeleteAllItems();
	int row = 0;
	// TODO: добавьте свой код обработчика уведомлений
	for (list<clStudent>::iterator i = baseStudent.begin(); i != baseStudent.end(); i++) {
		int value3 = 0, value4 = 0, value5 = 0;
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 10; k++)
			{
				switch ((*i).progress[j].value[k])
				{
				case 3: {value3++; break; }
				case 4: {value4++; break; }
				case 5: {value5++; break; }
				default:break;
				}
			}
		}
		int result = 0;
		if (cb_value3)result += value3;
		if (cb_value4)result += value4;
		if (cb_value5)result += value5;
		if (result <= (value3 + value4 + value5)*0.25 && ec_inter_ot <= (*i).birthday[2] && ec_inter_do > (*i).birthday[2]) {
			(*i).addToTable(tableStudents, row, cb_session); row++;
		}
	}
	UpdateData(false);
}


void CDLG1::OnBnClickedButton4()
{
	UpdateData();
	if (numberRedact == 0 || numberRedact > (&baseStudent)->size()) { MessageBoxA(NULL, "Введенного номера не существует", "Редоктирование", MB_ICONERROR | MB_OK); return; }
	ofstream out("bd.txt");
	int k = 1;
	for (list<clStudent>::iterator i = baseStudent.begin(); i != baseStudent.end(); i++,k++) {
		if(k != numberRedact){
			out << (CT2CA)(*i).surname << " " << (CT2CA)(*i).name.GetString() << " " << (CT2CA)(*i).otc.GetString() << " "
				<< (*i).birthday[0] << " " << (*i).birthday[1] << " " << (*i).birthday[2] << " "
				<< (CT2CA)(*i).gender.GetString() << " " << (*i).year_admission << " " << (CT2CA)(*i).faculty.GetString() << " "
				<< (CT2CA)(*i).department.GetString() << " " << (CT2CA)(*i).group.GetString() << " " << (CT2CA)(*i).number_book.GetString() << " ";
			for (int s = 0; s < 9; s++) {
				out << s << " ";
				for (int j = 0; j < 10; j++)
				{
					out << (CT2CA)(*i).progress[s].name_subject[j].GetString() << " " << (*i).progress[s].value[j] << " ";
				}
			}
			out << "\n";
		}
	}
	out.close();
	OnBnClickedButton1();
}

void CDLG1::OnBnClickedButton5()
{
	ofstream out("crypt_bd.txt");
	for (list<clStudent>::iterator i = baseStudent.begin(); i != baseStudent.end(); i++) {
		out << (*i).Crypting((*i).StudentToStr(0)) << "\n";
	}
	out.close();
}
