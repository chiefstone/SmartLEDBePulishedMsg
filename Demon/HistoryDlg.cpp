// HistoryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "HistoryDlg.h"
#include "afxdialogex.h"


//ThreadInfo Info;
// CHistoryDlg �Ի���

IMPLEMENT_DYNAMIC(CHistoryDlg, CDialogEx)

CHistoryDlg::CHistoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHistoryDlg::IDD, pParent)
{

}

CHistoryDlg::~CHistoryDlg()
{
}

void CHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HISTORY, m_listHis);
	DDX_Control(pDX, IDC_EDIT_USERID, m_edtUserID);
	DDX_Control(pDX, IDC_COMBO1, m_combFlag);
	DDX_Control(pDX, IDC_DATET_PUBLISHBEGIN, m_dateBeginDT);
	DDX_Control(pDX, IDC_DATET_PUBLISHEND, m_dateEndDT);
	DDX_Control(pDX, IDC_ED_DEVICENAME, m_edtDeviName);
	DDX_Control(pDX, IDC_EDIT3, m_edtMsgList);
}


BEGIN_MESSAGE_MAP(CHistoryDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTT_QUERRY, &CHistoryDlg::OnBnClickedButtQuerry)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_NOTIFY(NM_CLICK, IDC_LIST_HISTORY, &CHistoryDlg::OnClickListHistory)
	ON_WM_MOUSEWHEEL()
	ON_WM_SIZING()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_HISTORY, &CHistoryDlg::OnLvnItemchangedListHistory)
//	ON_BN_CLICKED(IDC_BUTT_DELETEH, &CHistoryDlg::OnClickedButtDeleteh)
ON_BN_CLICKED(IDC_BUTT_SHANCHU, &CHistoryDlg::OnBnClickedButtShanchu)
ON_BN_CLICKED(IDC_CHECK_ALLIN, &CHistoryDlg::OnBnClickedCheckAllin)
END_MESSAGE_MAP()


BEGIN_EASYSIZE_MAP(CHistoryDlg)
	EASYSIZE(IDC_STATIC_TOP,ES_BORDER,ES_BORDER,ES_BORDER,IDC_LIST_HISTORY,0)
	EASYSIZE(IDC_STATIC_FLAG,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_TOP,ES_KEEPSIZE,0)
	EASYSIZE(IDC_COMBO1,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_TOP,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_USERID,ES_KEEPSIZE,ES_BORDER,IDC_COMBO1,ES_KEEPSIZE,0)
	EASYSIZE(IDC_EDIT_USERID,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_USERID,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_PULISHDATE,ES_KEEPSIZE,ES_BORDER,IDC_EDIT_USERID,ES_KEEPSIZE,0)
	EASYSIZE(IDC_DATET_PUBLISHBEGIN,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_PULISHDATE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_1,ES_KEEPSIZE,ES_BORDER,IDC_DATET_PUBLISHBEGIN,ES_KEEPSIZE,0)
	EASYSIZE(IDC_DATET_PUBLISHEND,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_1,ES_KEEPSIZE,0)
	EASYSIZE(IDC_BUTT_QUERRY,ES_KEEPSIZE,ES_BORDER,IDC_DATET_PUBLISHEND,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STA_BOTTOM,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	EASYSIZE(IDCANCEL,IDC_STA_BOTTOM,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDOK,IDCANCEL,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_BUTT_SHANCHU,ES_KEEPSIZE,ES_KEEPSIZE,IDC_STA_BOTTOM,ES_BORDER,0);
	EASYSIZE(IDC_LIST_HISTORY,ES_BORDER,ES_BORDER,ES_BORDER,IDC_STA_BOTTOM,0)
END_EASYSIZE_MAP


// CHistoryDlg ��Ϣ�������


BOOL CHistoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	INIT_EASYSIZE;

	/*CRect rect;
	m_listHis.GetClientRect(&rect);*/
	m_listHis.SetExtendedStyle(m_listHis.GetExtendedStyle()|LVS_EX_FULLROWSELECT|LVS_EX_CHECKBOXES/*|LVS_EX_GRIDLINES*/);    //|LVS_EX_CHECKBOXES
	/*m_listHis.InitProgressColumn(6);
	m_listHis.InitProgressColumn11(7);*/
	int nIndex=0;
	m_listHis.InsertColumn(nIndex++,"��ɱ�ʶ",LVCFMT_LEFT,76);
	m_listHis.InsertColumn(nIndex++,"�û�ID",LVCFMT_CENTER,70);
	m_listHis.InsertColumn(nIndex++,"�豸ID",LVCFMT_LEFT,70);
	m_listHis.InsertColumn(nIndex++,"��Ϣ����",LVCFMT_CENTER,80);
	m_listHis.InsertColumn(nIndex++,"����״̬",LVCFMT_CENTER,80);
	m_listHis.InsertColumn(nIndex++,"����״̬",LVCFMT_CENTER,80);
	m_listHis.InsertColumn(nIndex++,"����ʱ��",LVCFMT_LEFT,170);
	m_listHis.InsertColumn(nIndex++,"���ʱ��",LVCFMT_LEFT,170);
	m_listHis.InsertColumn(nIndex++,"�豸Mac",LVCFMT_LEFT,140);
	m_listHis.InsertColumn(nIndex++,"UN",LVCFMT_LEFT,0);
	m_listHis.InsertColumn(nIndex++,"�豸����",LVCFMT_LEFT,90);
	m_listHis.InsertColumn(nIndex++,"��Ϣ��¼",LVCFMT_LEFT,800);

	m_imageLst.Create(16,16,ILC_COLOR24 | ILC_MASK ,10,20);
	CBitmap *pBm=NULL;
	pBm=new CBitmap();
	pBm->LoadBitmapA(IDB_BITMAP_TRUE);
	m_imageLst.Add(pBm,RGB(0,0,0));
	delete pBm;

	pBm=new CBitmap();
	pBm->LoadBitmapA(IDB_BITMAP_FALSE);
	m_imageLst.Add(pBm,RGB(0,0,0));
	delete pBm;

	m_combFlag.AddString(_T("ȫ��"));
	m_combFlag.AddString(_T("�����"));
	m_combFlag.AddString(_T("δ���"));
	m_combFlag.SetCurSel(0);

	//�����������ֱ��ʱ䶯
	CRect rect0;
	GetClientRect(&rect0);
	oldPoint.x=rect0.right-rect0.left;
	oldPoint.y=rect0.bottom-rect0.top;
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);  
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);  
	CRect rt;  
	SystemParametersInfo(SPI_GETWORKAREA,0,&rt,0);  
	cy = rt.bottom;  
	MoveWindow(0, 0, cx, cy); 
//////////////////////////////////////////////////////////////////////////
	GetDlgItem(IDC_STATIC_TOP)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_QUERRY)->SetFocus();
	//�༭����������
	/*m_fontEdt.CreatePointFont(170,"΢���ź�");
	m_edtUserID.SetFont(&m_fontEdt);*/
	m_edtUserID.SetLimitText(6);
	//////////////////////////////////////////////////////////////////////////
	m_brushi.CreateSolidBrush(RGB(255,255,255));
	//-----------------------------------��ҳ---------------------------------------
	m_iStartNum=0;
	m_iPerPageNum=34;
	m_iCurrPage=1;
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CHistoryDlg::OnBnClickedButtQuerry()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_listHis.DeleteAllItems();

	CString strsqlH,strSID,strDID,strDMac,strPulishTime,strCounts,strDownLoad,strSetMsg,strFinishTime,strFlag;
	int nSID,nDID,nCounts,nDownLoad,nSetMsg,nFlag;
	COleDateTime dtPulishDate,dtFinishDate;

	strsqlH.Format("select ������SID,���շ�DID,���շ�MAC,��������,������ģ����,�ɹ�������ģ��,�ɹ�������ģ��,�������ʱ��,��ɱ�־,MessageList,�豸����,Message_uniqueID  from MessageBuffer where 1=1 ");

/////�û�ID
	CString strUserID;
	m_edtUserID.GetWindowTextA(strUserID);
	strUserID.Replace(" ","");
	if (!strUserID.IsEmpty())
	{
		int nUserID=atoi(strUserID);
		CString strSQL;
		strSQL.Format(" and ������SID like '%%%d%%'",nUserID);
		strsqlH +=strSQL;
	}

///////�豸��
	CString strDeviceName,strsqlNm;
	m_edtDeviName.GetWindowTextA(strDeviceName);
	if (!strDeviceName.IsEmpty())
	{
		strsqlNm.Format(" and �豸���� like '%%"+strDeviceName+"%%'");
		strsqlH +=strsqlNm;
	}
////////��Ϣɸѡ
	CString strMsgList,strsqlMsg;
	m_edtMsgList.GetWindowTextA(strMsgList);
	if (!strMsgList.IsEmpty())
	{
		strsqlMsg.Format(" and MessageList like '%%"+strMsgList+"%%'");
		strsqlH+=strsqlMsg;
	}

	//����ʱ��
	COleDateTime dtBegin,dtEnd;
	m_dateBeginDT.GetTime(dtBegin);
	m_dateEndDT.GetTime(dtEnd);
	CString strSQl,strBegin,strEnd;
	strBegin=dtBegin.Format("%Y-%m-%d 00:00:00");
	strEnd=dtEnd.Format("%Y-%m-%d 23:59:59");
	strSQl.Format(" and ��������>='%s' and ��������<='%s'",strBegin,strEnd);
	strsqlH+=strSQl;
	//��ɱ�ʶ
	int nChoose=m_combFlag.GetCurSel();
	CString strSQL;
	if (nChoose==1)
	{
		strSQL.Format(" and ��ɱ�־=1");
		strsqlH+=strSQL;
	}
	else if (nChoose==2)
	{
		strSQL.Format("and ��ɱ�־=0");
		strsqlH+=strSQL;
	}

	CString strsqlOrd;
	strsqlOrd.Format(" order by ��������");
	strsqlH +=strsqlOrd;

	int nCl=0;
	if (theApp.m_ado.ExecuteSelect(strsqlH))
	{
		//theApp.m_ado.GetRecordSet();
		while(!theApp.m_ado.IsEOF())
		{
			//nCl++;
			// ����CImageListͼ���б���CListCtrl�ؼ����� LVSIL_SMALLСͼ���б�
			m_listHis.SetImageList(&m_imageLst,LVSIL_SMALL );
			theApp.m_ado.GetInt("��ɱ�־",nFlag);
			strFlag.Format("%d",nFlag);
			strFlag.Replace(" ","");
			int n=m_listHis.GetItemCount();
			CString strEndFlag;
			if (strFlag==_T("0"))
			{
				strEndFlag=_T("");
				m_listHis.InsertItem(n,strEndFlag,1);
			}
			else
			{
				strEndFlag=_T("");
				m_listHis.InsertItem(n,strEndFlag,0);
			}

			theApp.m_ado.GetInt("������SID",nSID);
			strSID.Format("%d",nSID);
			m_listHis.SetItemText(n,1,strSID);

			theApp.m_ado.GetInt("���շ�DID",nDID);
			strDID.Format("%d",nDID);
			m_listHis.SetItemText(n,2,strDID);

			theApp.m_ado.GetInt("������ģ����",nCounts);
			strCounts.Format("%d",nCounts);
			m_listHis.SetItemText(n,3,strCounts);

			theApp.m_ado.GetInt("�ɹ�������ģ��",nDownLoad);
			//strDownLoad.Format("%d",nDownLoad);
			if (nDownLoad==nCounts)
			{
				m_listHis.SetItemText(n,4,"%100");
			}
			else
				m_listHis.SetItemText(n,4,"%0");

			theApp.m_ado.GetInt("�ɹ�������ģ��",nSetMsg);
			//strSetMsg.Format("%d",nSetMsg);
			if (nSetMsg==nCounts)
			{
				m_listHis.SetItemText(n,5,"%100");
			}
			else
				m_listHis.SetItemText(n,5,"%0");

			theApp.m_ado.GetDateTime("��������",dtPulishDate);
			strPulishTime=dtPulishDate.Format("%Y-%m-%d %H:%M:%S");
			m_listHis.SetItemText(n,6,strPulishTime);

			theApp.m_ado.GetDateTime("�������ʱ��",dtFinishDate);
			strFinishTime=dtFinishDate.Format("%Y-%m-%d %H:%M:%S");
			CString str;
			if (strFlag==_T("0"))
			{
				str=_T(".......");
				m_listHis.SetItemText(n,7,str);
			}
			else
			{
				m_listHis.SetItemText(n,7,strFinishTime);
			}

			theApp.m_ado.GetString("���շ�MAC",strDMac);
			strDMac.Replace(" ","");
			/*Info.strMacIp=strDMac;
			pThread=AfxBeginThread((AFX_THREADPROC)Function,&Info);*/
			m_listHis.SetItemText(n,8,strDMac);

			CString strUnqueID;
			theApp.m_ado.GetString("Message_uniqueID",strUnqueID);
			strUnqueID.Replace(" ","");
			m_listHis.SetItemText(n,9,strUnqueID);

			CString strDeviceName;
			theApp.m_ado.GetString("�豸����",strDeviceName);
			strDeviceName.Replace(" ","");
			m_listHis.SetItemText(n,10,strDeviceName);

			CString strMatrixList;
			theApp.m_ado.GetString("MessageList",strMatrixList);
			strMatrixList.Replace(" ","");
			m_listHis.SetItemText(n,11,strMatrixList);

			theApp.m_ado.MoveNext();
		}
	}
}


HBRUSH CHistoryDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd-> GetDlgCtrlID() == IDC_STATIC_USERID||pWnd-> GetDlgCtrlID() == IDC_DATET_PUBLISHBEGIN||pWnd-> GetDlgCtrlID() == IDC_STATIC_1||
		pWnd-> GetDlgCtrlID() == IDC_STATIC_FLAG||pWnd-> GetDlgCtrlID() == IDC_STATIC_PULISHDATE ||pWnd->GetDlgCtrlID()==IDC_ST_DEVICENAME||
		pWnd->GetDlgCtrlID()==IDC_ST_MESSEGELIST)
	{
		pDC->SetBkMode(TRANSPARENT);         //���ÿؼ�����Ϊ͸��
		return   HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	return m_brushi;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


//���ڿؼ��洰��仯���仯����ʱ���ô˷���
void CHistoryDlg::ReSize()   
{
}

void CHistoryDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	UPDATE_EASYSIZE; //���´��ڴ�С
}


BOOL CHistoryDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	/*switch(pMsg->wParam)
	{
	case VK_RETURN:
	case VK_ESCAPE:
	return TRUE; break;
	}*/
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CHistoryDlg::OnClickListHistory(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	*pResult = 0;
}


BOOL CHistoryDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void CHistoryDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: �ڴ˴������Ϣ����������
	EASYSIZE_MINSIZE(1372,738,fwSide,pRect);
}


void CHistoryDlg::OnLvnItemchangedListHistory(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(1)) /* old state : unchecked */ 
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(2)) /* new state : checked */ 
		) 
	{ 
		GetDlgItem(IDC_BUTT_SHANCHU)->EnableWindow(TRUE);
	} 
	else if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(2)) /* old state : checked */ 
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(1)) /* new state : unchecked */ 
		) 
	{ 
		//TRACE("Item %d is unchecked\n", pNMLV->iItem);
		GetDlgItem(IDC_BUTT_SHANCHU)->EnableWindow(FALSE);
	} 

	*pResult = 0;
}


void CHistoryDlg::OnBnClickedButtShanchu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (IDCANCEL==MessageBox("ȷ��ɾ����ѡ��¼��","����ѡ��!!!",MB_OKCANCEL))
	{
		return;
	}
	int iCount=m_listHis.GetItemCount();
	for (int n=0;n<iCount;n++)
	{
		if (m_listHis.GetCheck(n))
		{
			CString strUniq=m_listHis.GetItemText(n,9);
			CString strsqlD;
			strsqlD.Format("delete from MessageBuffer where  Message_uniqueID='%s'",strUniq);
			if (theApp.m_ado.ExecuteSql(strsqlD))
			{
				m_listHis.DeleteItem(n);
				n--;
			}
			/*else
			{
			MessageBox("ɾ��ʧ��","����");
			break;
			}*/
		}
	}
	UpdateData(TRUE);
}


void CHistoryDlg::OnBnClickedCheckAllin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int iCount=m_listHis.GetItemCount();
	BOOL bCheck=FALSE;
	if (BST_CHECKED==IsDlgButtonChecked(IDC_CHECKALL))
	{
		bCheck=TRUE;
	}

	for (int i=0;i<iCount;i++)
	{
		m_listHis.SetCheck(i,bCheck);
	}
}
