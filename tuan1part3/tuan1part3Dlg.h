
// tuan1part3Dlg.h : header file
//

#pragma once


// Ctuan1part3Dlg dialog
class Ctuan1part3Dlg : public CDialogEx
{
// Construction
public:
	Ctuan1part3Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUAN1PART3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonsave();
	CStatic PATHNAME;
	
	afx_msg void OnBnClickedButtonload();
	
};
