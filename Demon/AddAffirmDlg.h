#pragma once
#include "afxwin.h"


// CAddAffirmDlg �Ի���

class CAddAffirmDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddAffirmDlg)

public:
	CAddAffirmDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddAffirmDlg();

// �Ի�������
	enum { IDD = IDD_ADDAFFIRM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edtAdd;
	afx_msg void OnBnClickedButtAdd();
	CString strEditAdd;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	virtual void OnOK();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
