// AddAffirmDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "AddAffirmDlg.h"
#include "afxdialogex.h"
#include "SingleDemonDlg.h"


// CAddAffirmDlg �Ի���

IMPLEMENT_DYNAMIC(CAddAffirmDlg, CDialogEx)

CAddAffirmDlg::CAddAffirmDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddAffirmDlg::IDD, pParent)
{

}

CAddAffirmDlg::~CAddAffirmDlg()
{
}

void CAddAffirmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_, m_edtAdd);
}


BEGIN_MESSAGE_MAP(CAddAffirmDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTT_ADD, &CAddAffirmDlg::OnBnClickedButtAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddAffirmDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CAddAffirmDlg ��Ϣ�������


void CAddAffirmDlg::OnBnClickedButtAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_edtAdd.GetWindowText(strEditAdd);
	strEditAdd.Replace(" ","");
	if (strEditAdd.IsEmpty())
	{
		MessageBox("�����Ϊ��,����������","��ܰ��ʾ",MB_OK);
		return;
	}
	else
	{
		CDialogEx::OnOK();
	}
}


BOOL CAddAffirmDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_edtAdd.LimitText(25);

	GetDlgItem(IDC_BUTT_ADD)->SetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CAddAffirmDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CAddAffirmDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


BOOL CAddAffirmDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message==WM_KEYDOWN &&pMsg->wParam==VK_RETURN)
	{
		OnBnClickedButtAdd();
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
