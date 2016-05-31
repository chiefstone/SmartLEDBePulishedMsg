#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "EasySize.h"
#include "MyListCtrl.h"
#include "resource.h"


#define WM_PULISHMESSAGE WM_USER+201//�������ڹرմ�����Ϣ

static BOOL bSort;
// CDeviceQueryDlg �Ի���

class CDeviceQueryDlg : public CDialogEx
{
	DECLARE_EASYSIZE
	DECLARE_DYNAMIC(CDeviceQueryDlg)

public:
	CDeviceQueryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeviceQueryDlg();

// �Ի�������
	enum { IDD = IDD_DeViceQuery_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton6();
	afx_msg void OnClickedButtonLastStep();
	CMyListCtrl m_listDevice;
	//CListCtrlCl m_listDevice;
	virtual BOOL OnInitDialog();
	CComboBox m_combProvince;
	CComboBox m_combCity;
	afx_msg void OnClickedButtDevicelist();
	afx_msg void OnSelchangeCombProvince();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnClickedCheckAll();
	afx_msg void OnClickedButtStatusFlag();
	CButton m_checkAll;
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	CButton m_butt_NextStep;
	int nItem;

	
	POINT old;

	int nPress;

	CBrush m_brBk;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CEdit m_edtDevSID;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);

	static int CALLBACK ListCompare(LPARAM lParam1,LPARAM lParam2,LPARAM lParamSort);
	afx_msg void OnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult);

protected:
	CBrush m_brush;
public:
	int e_iTem;   //�ձ༭����
	int e_SubItem;//�ձ༭����
	BOOL bHaveBeenCreate;  //�༭���Ѿ���������ʶ
	//������Ԫ��༭����
	void CreateEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool bHadCreate);
	//���ٵ�Ԫ��༭�����
	void DestroyEdit(CListCtrl *list, CEdit* destroyEdit, int &Item, int &SubItem);
	afx_msg void OnDblclkListDoubleClick(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_edit;
	virtual void OnOK();

	afx_msg void OnKillFocusListEdit(void);
	afx_msg void OnRclickListChangeName(NMHDR *pNMHDR, LRESULT *pResult);

	//CFont m_edtFont;
	afx_msg void OnEnChangeEditDeviceid();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	CEdit m_edtID;
	CEdit m_edtAddress;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedStaticHighquery();
	CStatic m_stcQuery;
	
	int iPressHigh;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CEdit m_edtDeviceName;

	int ncheck;
	int num;
	BOOL bFlag;
	CStatusBarCtrl *m_pStatBar;
	CToolTipCtrl m_TlTips;

protected:
	afx_msg LRESULT  OnRecVPulishMSG(WPARAM wParam,LPARAM lParam);//�������ڹرս�����Ϣ
};


