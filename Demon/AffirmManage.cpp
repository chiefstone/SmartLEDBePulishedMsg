// AffirmManage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "AffirmManage.h"
#include "afxdialogex.h"
#include "MessageListDlg.h"
#include "SingleDemonDlg.h"
#include "AddAffirmDlg.h"

// CAffirmManage �Ի���

IMPLEMENT_DYNAMIC(CAffirmManage, CDialogEx)

CAffirmManage::CAffirmManage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAffirmManage::IDD, pParent)
{
	
}

CAffirmManage::~CAffirmManage()
{
}

void CAffirmManage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTAFFIRM, m_listMatrix);
}


BEGIN_MESSAGE_MAP(CAffirmManage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTT_CANCERA, &CAffirmManage::OnClickedButtCancerA)
	ON_BN_CLICKED(IDC_BUTT_QUERYMATRIX,&CAffirmManage::OnBnClickedQueryMatrixButton)
	ON_NOTIFY(NM_CLICK, IDC_LISTAFFIRM, &CAffirmManage::OnClickListChooseMatrix)
	ON_BN_CLICKED(IDC_BUTT_LEAD_IN, &CAffirmManage::OnClickedButtLeadIn)
	ON_BN_CLICKED(IDC_BUTT_ADDMATRIX, &CAffirmManage::OnBnClickedButtAddmatrix)
	ON_BN_CLICKED(IDC_BUTT_DELETE, &CAffirmManage::OnBnClickedButtDelete)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CAffirmManage ��Ϣ�������


void CAffirmManage::OnClickedButtCancerA()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


BOOL CAffirmManage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;
	m_listMatrix.GetClientRect(&rect);
	m_listMatrix.SetExtendedStyle(m_listMatrix.GetExtendedStyle()|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES);

	int nIndex=0;
	m_listMatrix.InsertColumn(nIndex++,"��ģ���",LVCFMT_LEFT,150);
	m_listMatrix.InsertColumn(nIndex++,"��ʾ����",LVCFMT_LEFT,580);

	OnBnClickedQueryMatrixButton();
	
	CSingleDemonDlg *pMain=(CSingleDemonDlg *)GetParent();
	if (pMain->bClick==TRUE)
	{
		GetDlgItem(IDC_BUTT_LEAD_IN)->ShowWindow(SW_HIDE);
	}
	CMessageListDlg *pMsgs=(CMessageListDlg *)GetParent();
	if (pMsgs->bLeadin==TRUE)
	{
		GetDlgItem(IDC_BUTT_ADDMATRIX)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTT_DELETE)->ShowWindow(SW_HIDE);
	}

	m_brushe.CreateSolidBrush(RGB(255,255,255));
	iClick=0;
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CAffirmManage::OnBnClickedQueryMatrixButton()
{
	Sleep(10);
	try
	{
		m_listMatrix.DeleteAllItems();

		CString strsql,strSerialNo,strMatrContent;
		int iSeriaNo;
		strsql.Format("SELECT ��ģ���,��ʾ���� FROM DotDisplayData where ʹ�ñ�־ = 1");//
		if (theApp.m_ado.ExecuteSelect(strsql))
		{
			while(!theApp.m_ado.IsEOF())
			{
				theApp.m_ado.GetInt("��ģ���",iSeriaNo);
				strSerialNo.Format("%d",iSeriaNo);
				int n=m_listMatrix.GetItemCount();
				m_listMatrix.InsertItem(n,strSerialNo);

				theApp.m_ado.GetString("��ʾ����",strMatrContent);
				m_listMatrix.SetItemText(n,1,strMatrContent);

				theApp.m_ado.MoveNext();
			}
		}
	}
	catch(_com_error &e)
	{
		AfxMessageBox(e.Description());
	}
}

void CAffirmManage::OnClickListChooseMatrix(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//DWORD dwPos = GetMessagePos();
	//CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
	// ScreenToClient(&point);
	//LVHITTESTINFO lvinfo;
	//lvinfo.pt = point;
	//CRect rcCtrl;
	//int nitem = m_listMatrix.SubItemHitTest(&lvinfo);//�õ������ĵ��к�
	//if (nitem!=-1)
	//{
	//	iClick++;
	//	if (iClick==1)
	//	{
	//		m_listMatrix.SetCheck(nitem,TRUE);
	//	}
	//	if (iClick>1)
	//	{
	//		if (m_listMatrix.GetCheck(nitem)==TRUE)
	//		{
	//			m_listMatrix.SetCheck(nitem,FALSE);
	//		}
	//		else
	//			m_listMatrix.SetCheck(nitem,TRUE);
	//	}
	//}
	*pResult = 0;
}


void CAffirmManage::OnClickedButtLeadIn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	int iSum=0;
	icount=m_listMatrix.GetItemCount();
	for (int i=0;i<icount;i++)
	{
		if (m_listMatrix.GetCheck(i))
		{
			iSum++;
		}
	}
	if (iSum==0)
	{
		MessageBox("��ǰ�б�δѡ���κ���Ϣ","��ܰ��ʾ");
	}
	else
	{
		for (int i=0;i<icount;i++)
		{
			if (m_listMatrix.GetCheck(i))
			{
				strMSG=m_listMatrix.GetItemText(i,1);
				strArray.Add(strMSG);
			}
		}
		CDialogEx::OnOK();
	}
	
}


void CAffirmManage::OnBnClickedButtAddmatrix()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAddAffirmDlg Add;
	if (IDOK==Add.DoModal())
	{
		CString strAdd=Add.strEditAdd;
		CSingleDemonDlg *pHomeDlg=(CSingleDemonDlg *)GetParent();
		pHomeDlg->strContentTest=strAdd;
		pHomeDlg->OnBnClickedButton00();
		int iLatticeL,iLatticeW;
		iLatticeL=80;
		iLatticeW=16;
		try
		{
			UpdateData(TRUE);
			//m_listMatrix.DeleteAllItems();
			CString strSQL;
			strSQL.Format("insert into DotDisplayData(����ߴ糤,����ߴ��,ȡģ��ʽ,��ʾ���ݲ鳤��,��ʾ����,��ģ���ݳ���,��ģ����,������Ϣ֧�ֳ���,ʹ�ñ�־) values('%d','%d',1,'%d','%s','%d','%s',8,1)"
				,iLatticeL,iLatticeW,pHomeDlg->iChaChang,pHomeDlg->strContentTest,pHomeDlg->iLengthTest,pHomeDlg->zimuDianzhenStr);
			if (theApp.m_ado.ExecuteSql(strSQL))
			{
				MessageBox("�����ģ�ɹ���","��ܰ��ʾ");
				OnBnClickedQueryMatrixButton();
				UpdateData(TRUE);
			}
		}
		catch(_com_error e)
		{
			AfxMessageBox(e.Description());
			return;
		}
	}
}


void CAffirmManage::OnBnClickedButtDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strsqlDe,strBH,strNR;
	int nSum=0;
	for (int i=0;i<m_listMatrix.GetItemCount();i++)
	{
		if (m_listMatrix.GetCheck(i))
		{
			nSum++;
		}
	}
	if (nSum==0)
	{
		MessageBox("��ǰδѡ���κ���Ϣ","��ܰ��ʾ");
		return;
	}

	if (IDCANCEL==MessageBox("ȷ��ɾ����ѡ��Ϣ��?","����!!",MB_OKCANCEL))
	{
		return;
	}
	for (int i=0;i<m_listMatrix.GetItemCount();i++)
	{
		if (m_listMatrix.GetCheck(i))
		{
			strBH=m_listMatrix.GetItemText(i,0);
			strNR=m_listMatrix.GetItemText(i,1);
			int iBH=atoi(strBH);
			strsqlDe.Format("update DotDisplayData set ʹ�ñ�־=0 where ��ģ���=%d and ��ʾ����='%s'",iBH,strNR);
			if (theApp.m_ado.ExecuteSql(strsqlDe))
			{
				m_listMatrix.DeleteItem(i);
				i--;
			}
		}
	}
	UpdateData(TRUE);
}


HBRUSH CAffirmManage::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	return m_brushe;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
