
// tuan1part3Dlg.cpp : implementation file

#include "pch.h"
#include "framework.h"
#include "tuan1part3.h"
#include "tuan1part3Dlg.h"
#include "afxdialogex.h"
#include <iostream>;
#include <string>;
#include <vector>;
#include <fstream>;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define BUFFERSIZE 5
DWORD g_BytesTransferred = 0;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// Ctuan1part3Dlg dialog



Ctuan1part3Dlg::Ctuan1part3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TUAN1PART3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctuan1part3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PATH, PATHNAME);
}

BEGIN_MESSAGE_MAP(Ctuan1part3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONSAVE, &Ctuan1part3Dlg::OnBnClickedButtonsave)
	

	ON_BN_CLICKED(IDC_BUTTONLOAD, &Ctuan1part3Dlg::OnBnClickedButtonload)

END_MESSAGE_MAP()


// Ctuan1part3Dlg message handlers

BOOL Ctuan1part3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Ctuan1part3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Ctuan1part3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Ctuan1part3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Ctuan1part3Dlg::OnBnClickedButtonsave()
{
	OPENFILENAME ofn;

	//Save file
	TCHAR szFileName[MAX_PATH] = {0};

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = (LPCWSTR)L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = (LPWSTR)szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = (LPCWSTR)L"txt";

	if (GetSaveFileName(&ofn) != true)
	{
		AfxMessageBox(_T("Saving file canceled!"));
	}
	else
	{

	}

	//hien thi tren PATH
	SetDlgItemText(IDC_PATH, (LPCWSTR)szFileName);

	//Tao va viet file
	{
		CString text = L"";
		GetDlgItemText(IDC_EDITSCREEN, text);
		DWORD dwBytesWritten = 0;
		BOOL bTest = FALSE;
		HANDLE hFile = CreateFile(szFileName,                // name of the write
			GENERIC_WRITE,          // open for writing
			0,                      // do not share
			NULL,                   // default security
			CREATE_NEW,             // create new file only
			FILE_ATTRIBUTE_NORMAL,  // normal file
			NULL);                  // no attr. template


		bTest = WriteFile(
			hFile,           // open file handle
			text,
			text.GetLength() * sizeof(TCHAR),
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure

		CloseHandle(hFile);
	}

}



//LOAD
void Ctuan1part3Dlg::OnBnClickedButtonload()
{
	TCHAR szFileName[MAX_PATH] = { 0 };
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));


	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = (LPCWSTR)L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = (LPWSTR)szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = (LPCWSTR)L"txt";

	if (GetOpenFileName(&ofn) != true)
	{
		AfxMessageBox(_T("Loading file canceled!"));
	}
	else
	{

	}

	//hien thi tren PATH
	SetDlgItemText(IDC_PATH, (LPCWSTR)szFileName);

	//read
	HANDLE hFile;
	//PVOID First_Bytes[2048];
	char First_Bytes[2048];
	DWORD dbr = 0;
	hFile = CreateFile(
		L"(LPWSTR)szFileName", 
		GENERIC_READ, 
		FILE_SHARE_READ, 
		NULL, 
		OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, 
		NULL
	);
	CloseHandle(hFile);
		
	}
		


