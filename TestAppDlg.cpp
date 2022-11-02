
// TestAppDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "TestApp.h"
#include "TestAppDlg.h"
#include "afxdialogex.h"
#include <string>
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>
using namespace std;


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
public:
	afx_msg void B1Clicked();
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


// Диалоговое окно CMainDlg



CMainDlg::CMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTAPP_DIALOG, pParent)
	, m_sFileIn(_T(""))
	, Calc_pole(_T(""))
	, m_sFileOut(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILEIN, m_sFileIn);
	DDX_Text(pDX, IDC_EDIT1, Calc_pole);
	DDX_Text(pDX, IDC_EDIT_FILEOUT, m_sFileOut);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BTN_GTFILEIN, &CMainDlg::OnGetFilein)
	ON_BN_CLICKED(b_1, &CMainDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_BTN_GTFILEOUT, &CMainDlg::OnGetFileOut)
	ON_BN_CLICKED(IDC_BTN_GTPROCESS, &CMainDlg::OnBnClickedBtnGtprocess)
	ON_BN_CLICKED(b_2, &CMainDlg::OnBnClicked2)
	ON_BN_CLICKED(b_3, &CMainDlg::OnBnClicked3)
	ON_BN_CLICKED(b_4, &CMainDlg::OnBnClicked4)
	ON_BN_CLICKED(b_5, &CMainDlg::OnBnClicked5)
	ON_BN_CLICKED(b_6, &CMainDlg::OnBnClicked6)
	ON_BN_CLICKED(b_7, &CMainDlg::OnBnClicked7)
	ON_BN_CLICKED(b_8, &CMainDlg::OnBnClicked8)
	ON_BN_CLICKED(b_9, &CMainDlg::OnBnClicked9)
	ON_BN_CLICKED(b_0, &CMainDlg::OnBnClicked0)
	ON_BN_CLICKED(b_reset, &CMainDlg::OnBnClickedreset)
	ON_BN_CLICKED(b_10, &CMainDlg::OnBnClicked10)
	ON_BN_CLICKED(b_p, &CMainDlg::OnBnClickedp)
	ON_BN_CLICKED(b_result, &CMainDlg::OnBnClickedresult)
	ON_BN_CLICKED(b_m, &CMainDlg::OnBnClickedm)
	ON_BN_CLICKED(b_d, &CMainDlg::OnBnClickedd)
	ON_BN_CLICKED(b_u, &CMainDlg::OnBnClickedu)
END_MESSAGE_MAP()


// Обработчики сообщений CMainDlg

BOOL CMainDlg::OnInitDialog()
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
	SetIcon(m_hIcon, FALSE);			// Крупный значок
	SetIcon(m_hIcon, TRUE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	m_sFileIn = "input.txt";
	m_sFileOut = "output.txt";
	UpdateData(FALSE); //AS false - из переменнных, на экран. true - с экрана в переменные

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMainDlg::OnPaint()
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
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool CMainDlg::ProcessFiles(CString sFileIn, CString sFileOut)
{
	CFile fileIn;
	if (!fileIn.Open(sFileIn, CFile::modeRead)) 
	{ 
		CString sMsg;
		sMsg.Format(L"Не могу открыть файл %s", sFileIn);
		MessageBox(sMsg, L"Ошибка", MB_OK);
		return false;
	}
	CFile fileOut;
	if (!fileOut.Open(sFileIn, CFile::modeWrite | CFile::modeCreate))
	{
		CString sMsg;
		sMsg.Format(L"Не могу открыть файл %s", sFileOut);
		MessageBox(sMsg, L"Ошибка", MB_OK | MB_ICONERROR);
		return false;
	}
	int a;
	fileIn.Read(&a, sizeof(int));
	fileOut.Write(&a, sizeof(int));

	return TRUE;
}

void CMainDlg::OnGetFilein()
{
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
	{
		m_sFileIn = dlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}

	//из поля в переменную
	//UpdateData(true);
	//CString sMsg = L"Вы ввели - " + m_sFileIn;
	// выводим сообщение
	//MessageBox(m_sFileIn, L"Окно", MB_OK | MB_ICONEXCLAMATION); // текст сообщения, заголовок, кнопки
	// TODO: Add your control notification handler code here
}

void CMainDlg::OnGetFileOut()
{
	CFileDialog dlg(FALSE);
	if (dlg.DoModal() == IDOK)
	{
		m_sFileOut = dlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}

void CMainDlg::OnBnClickedBtnGtprocess()
{
	UpdateData(TRUE);
	if (!ProcessFiles(m_sFileIn, m_sFileOut))
	{
		MessageBox(L"Что-то не получается", L"Алярма", MB_OK | MB_ICONERROR);
	}
	else 
	{
		MessageBox(L"Что-то сработало!", L"Ура!", MB_OK | MB_ICONHAND);
	}
}


// КАЛЬКУЛЯТОР

float a = 0;
float b = 0;
char s = '0';
void CMainDlg::OnBnClicked1() { if (s == 'r') { Calc_pole = "";	UpdateData(false); s = '0'; }Calc_pole += "1";	UpdateData(false); }
void CMainDlg::OnBnClicked2() { if (s == 'r') { Calc_pole = "";	UpdateData(false); s = '0'; }Calc_pole += "2";	UpdateData(false); }
void CMainDlg::OnBnClicked3() { if (s == 'r') { Calc_pole = "";	UpdateData(false); s = '0'; }Calc_pole += "3";	UpdateData(false); }
void CMainDlg::OnBnClicked4() { if (s == 'r') { Calc_pole = "";	UpdateData(false); s = '0'; }Calc_pole += "4";	UpdateData(false); }
void CMainDlg::OnBnClicked5() { if (s == 'r') { Calc_pole = "";	UpdateData(false); s = '0'; }Calc_pole += "5";	UpdateData(false); }
void CMainDlg::OnBnClicked6() { if (s == 'r') { Calc_pole = "";	UpdateData(false); s = '0'; }Calc_pole += "6";	UpdateData(false); }
void CMainDlg::OnBnClicked7() { if (s == 'r') { Calc_pole = "";	UpdateData(false); s = '0'; }Calc_pole += "7";	UpdateData(false); }
void CMainDlg::OnBnClicked8() { if (s == 'r') { Calc_pole = "";	UpdateData(false); s = '0'; }Calc_pole += "8";	UpdateData(false); }
void CMainDlg::OnBnClicked9() { if (s == 'r') { Calc_pole = "";	UpdateData(false); s = '0'; }Calc_pole += "9";	UpdateData(false); }
void CMainDlg::OnBnClicked0() { if (s == 'r') { Calc_pole = "";	UpdateData(false); s = '0'; }Calc_pole += "0";	UpdateData(false); }
void CMainDlg::OnBnClickedreset() { Calc_pole = "";	UpdateData(false); }
void CMainDlg::OnBnClicked10() { Calc_pole += ".";	UpdateData(false); }

void CMainDlg::OnBnClickedp()
{	
	UpdateData(TRUE);
	a = _ttof(Calc_pole);
	s = '+',
	//Calc_pole.Format(_T("%f"), a);
	//UpdateData(FALSE);
	Calc_pole = "";	UpdateData(false);

	//a += stod(Calc_pole); // Интересный вариант преобразования
	//a = atof(_bstr_t((LPCSTR)Calc_pole));//Тоже не завелось
	//istringstream(Calc_pole) >> a;	
	//for (int i = 0; i < s.length(); i++)
	//{
	//	Calc_pole += (string)i;
	//}	
}

void CMainDlg::OnBnClickedm()
{
	UpdateData(TRUE);
	a = _ttof(Calc_pole);
	s = '-';
	Calc_pole = "";	UpdateData(false);
}
void CMainDlg::OnBnClickedd()
{
	UpdateData(TRUE);
	a = _ttof(Calc_pole);
	s = '/';
	Calc_pole = "";	UpdateData(false);
}
void CMainDlg::OnBnClickedu()
{
	UpdateData(TRUE);
	a = _ttof(Calc_pole);
	s = '*';
	Calc_pole = "";	UpdateData(false);
}
void CMainDlg::OnBnClickedresult()
{
	b = _ttof(Calc_pole);
	switch (s)
	{
	case '0':
		break;
	case '+':
		Calc_pole.Format(_T("%f"), a + b);
		UpdateData(FALSE); a = 0; b = 0; s = 'r';
		break;
	case '-':
		Calc_pole.Format(_T("%f"), a - b);
		UpdateData(FALSE); a = 0; b = 0; s = 'r';
		break;
	case '/':
		Calc_pole.Format(_T("%f"), a / b);
		UpdateData(FALSE); a = 0; b = 0; s = 'r';
		break;
	case '*':
		Calc_pole.Format(_T("%f"), a * b);
		UpdateData(FALSE); a = 0; b = 0; s = '0';
		break;
	default:
		break;
	}
}


// КРЕСТИКИ / НОЛИКИ


