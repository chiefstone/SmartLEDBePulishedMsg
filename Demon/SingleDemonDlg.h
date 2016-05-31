
// SingleDemonDlg.h : ͷ�ļ�
//



#pragma once
#include "afxwin.h"

#if _MSC_VER > 1000
#endif // _MSC_VER > 1000


#define WM_RECVDATA  WM_USER+200 //��������߳��û���Ϣ

//��������߳���Ϣ���ݽṹ��
struct RECVPARAM
{
	SOCKET sock;
	HWND hwnd;
};

// CSingleDemonDlg �Ի���
class CSingleDemonDlg : public CDialogEx
{
// ����
public:
	CSingleDemonDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SINGLEDEMON_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg LRESULT  OnRecvData(WPARAM wParam,LPARAM lParam);//���������߳���Ϣ������

	afx_msg LRESULT  OnRecVPulishMSG(WPARAM wParam,LPARAM lParam);//�������ڹرս�����Ϣ

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtPulish();
	afx_msg void OnClickedButtMatrixManage();
	afx_msg void OnBnClickedButton00();
	CString strPassWord;
	CString strAddAffirm;
	CString strContentTest;
	void Bytes_Display(char* const chs);
	afx_msg void OnClickedButtLogin();
	//void Bytes_Read_from_HZK16(unsigned char *s, char* const chs);
	afx_msg void OnBnClickedSend();   //����
	BOOL InitSocket();       //��ʼ��Socket
	static DWORD WINAPI RecvProc(LPVOID lpParameter);//��������߳�
	afx_msg void OnBnClickedStartButton();	//����

	unsigned char CheckSumCal(unsigned char *p,int len);


	CRect m_rect;
	//��ģ���ݳ���
	long sql_zimudatasize;
	//��ģ���������ַ���
	CString zimuDianzhenStr;
	int iChaChang;
	int iLengthTest;

	CBrush m_brBk;

protected:
	CEdit m_edtUserName;
	CEdit m_edtPassWord;

private:
	SOCKET m_socket;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	CStatusBarCtrl  *m_pStatBar;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	int ncheck;
	int num;
	BOOL bFlag;
	afx_msg void OnClickedStaticVersion();
	afx_msg void OnBnClickedButtHistory();

	BOOL bClick;
	BOOL bCliiick;
	CToolTipCtrl m_TlTips;
};
