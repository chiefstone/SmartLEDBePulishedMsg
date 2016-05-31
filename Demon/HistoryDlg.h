#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include "EasySize.h"
#include "MyListCtrl.h"

//struct ThreadInfo
//{
//	CString strMacIp;
//	CString strMacName;
//};
void Function(LPVOID lpParam);
// CHistoryDlg �Ի���

class CHistoryDlg : public CDialogEx
{
	DECLARE_EASYSIZE
	DECLARE_DYNAMIC(CHistoryDlg)

public:
	CHistoryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHistoryDlg();

// �Ի�������
	enum { IDD = IDD_HISTORY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CMyListCtrl m_listHis;
	//CReListCtrlEx m_listHis;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtQuerry();

	CBrush m_brushi;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CEdit m_edtUserID;
	CComboBox m_combFlag;
	CDateTimeCtrl m_dateBeginDT;
	CDateTimeCtrl m_dateEndDT;

	CImageList m_imageLst;
	POINT oldPoint;
	void ReSize();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

//////////////////////////////////////////////////////////////////////////��ҳ
	int m_iStartNum;  
	int m_iPerPageNum;     //ÿҳ��ʾ��¼��
	int m_iRecordSum;      //�ܼ�¼����
	int m_iCurrPage;           //��ǰ�ڼ�ҳ
	int m_iPageSum;           //��ҳ��

protected:
	//CWinThread *pThread;
public:
	afx_msg void OnClickListHistory(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//CFont m_fontEdt;    //�༭������
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	CEdit m_edtDeviName;
	CEdit m_edtMsgList;
	afx_msg void OnLvnItemchangedListHistory(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnClickedButtDeleteh();
	afx_msg void OnBnClickedButtShanchu();
	afx_msg void OnBnClickedCheckAllin();
};
