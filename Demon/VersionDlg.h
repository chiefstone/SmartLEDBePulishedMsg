#pragma once
#include "afxwin.h"


// CVersionDlg �Ի���

class CVersionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVersionDlg)

public:
	CVersionDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CVersionDlg();

// �Ի�������
	enum { IDD = IDD_VERSION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit m_edtVersion;
	afx_msg void OnClickedStaticClose1();
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
