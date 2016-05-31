#pragma once
#include "afxcmn.h"
#include "MyListCtrl.h"

// CAffirmManage �Ի���

class CAffirmManage : public CDialogEx
{
	DECLARE_DYNAMIC(CAffirmManage)

public:
	CAffirmManage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAffirmManage();

// �Ի�������
	enum { IDD = IDD_AFFIRMMANAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtCancerA();
	virtual BOOL OnInitDialog();
	CMyListCtrl  m_listMatrix;
	afx_msg void OnBnClickedQueryMatrixButton();
	afx_msg void OnClickListChooseMatrix(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtLeadIn();
	afx_msg void OnBnClickedButtAddmatrix();
	CString strMSG;
	afx_msg void OnBnClickedButtDelete();

	int icount;
	CStringArray  strArray;

	int iClick;
	CBrush m_brushe;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
