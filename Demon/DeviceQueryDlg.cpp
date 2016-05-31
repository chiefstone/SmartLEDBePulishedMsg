// DeviceQueryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "DeviceQueryDlg.h"
#include "afxdialogex.h"
#include "MessageListDlg.h"


#define CID 1052672  

// CDeviceQueryDlg �Ի���

IMPLEMENT_DYNAMIC(CDeviceQueryDlg, CDialogEx)

CDeviceQueryDlg::CDeviceQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeviceQueryDlg::IDD, pParent)
{

}

CDeviceQueryDlg::~CDeviceQueryDlg()
{
}

void CDeviceQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listDevice);
	DDX_Control(pDX, IDC_COMBPROVINCE, m_combProvince);
	DDX_Control(pDX, IDC_COMBCITY, m_combCity);
	DDX_Control(pDX, IDC_CHECKALL, m_checkAll);
	DDX_Control(pDX, IDC_BUTTON6, m_butt_NextStep);
	DDX_Control(pDX, IDC_EDIT_DEVICEID, m_edtDevSID);
	DDX_Control(pDX, IDC_EDIT_DEVICEDID, m_edtID);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, m_edtAddress);
	DDX_Control(pDX, IDC_STATIC_HIGHQUERY, m_stcQuery);
	DDX_Control(pDX, IDC_EDIT_DEVICENAME, m_edtDeviceName);
}


BEGIN_MESSAGE_MAP(CDeviceQueryDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON6, &CDeviceQueryDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CDeviceQueryDlg::OnClickedButtonLastStep)
	ON_BN_CLICKED(IDC_BUTT_DEVICELIST, &CDeviceQueryDlg::OnClickedButtDevicelist)
	ON_CBN_SELCHANGE(IDC_COMBPROVINCE, &CDeviceQueryDlg::OnSelchangeCombProvince)
	ON_BN_CLICKED(IDC_RADIO1, &CDeviceQueryDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_CHECKALL, &CDeviceQueryDlg::OnClickedCheckAll)
	ON_BN_CLICKED(IDC_BUTT_STATUS, &CDeviceQueryDlg::OnClickedButtStatusFlag)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDeviceQueryDlg::OnClickList1)
	ON_WM_CTLCOLOR()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CDeviceQueryDlg::OnLvnItemchangedList1)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &CDeviceQueryDlg::OnColumnclickList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CDeviceQueryDlg::OnDblclkListDoubleClick)
	ON_EN_KILLFOCUS(IDC_EDIT_LISTEDIT,&CDeviceQueryDlg::OnKillFocusListEdit)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &CDeviceQueryDlg::OnRclickListChangeName)
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_STATIC_HIGHQUERY, &CDeviceQueryDlg::OnClickedStaticHighquery)
	ON_MESSAGE(WM_PULISHMESSAGE,OnRecVPulishMSG)
END_MESSAGE_MAP()


//ʹ��EasySize�����ƿؼ�λ�ü�����
BEGIN_EASYSIZE_MAP(CDeviceQueryDlg)
	/*EASYSIZE(IDC_EDIT_ADDRESS,ES_BORDER,ES_BORDER,ES_BORDER,ES_KEEPSIZE,ES_HCENTER)
	EASYSIZE(IDC_STATIC_DID,ES_KEEPSIZE,ES_BORDER,IDC_EDIT_ADDRESS,ES_KEEPSIZE,0)
	EASYSIZE(IDC_EDIT_DEVICEID,ES_KEEPSIZE,ES_BORDER,IDC_EDIT_ADDRESS,ES_KEEPSIZE,0)
	EASYSIZE(IDC_BUTT_DEVICELIST,ES_KEEPSIZE,ES_BORDER,IDC_EDIT_ADDRESS,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_ADDRESS,IDC_EDIT_ADDRESS,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_EDIT_DEVICEDID,IDC_STATIC_ADDRESS,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_DEVICEDID,IDC_EDIT_DEVICEDID,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_EDIT_DEVICENAME,IDC_STATIC_DEVICEDID,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_DEVICENAME,IDC_EDIT_DEVICENAME,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)*/
	//EASYSIZE(IDC_STATIC_HIGHQUERY,ES_KEEPSIZE,ES_BORDER,IDC_EDIT_ADDRESS,ES_KEEPSIZE,ES_HCENTER)
	EASYSIZE(IDC_STATIC_TOP,ES_BORDER,ES_BORDER,ES_BORDER,IDC_LIST1,0)
	EASYSIZE(IDC_CHECKALL,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_TOP,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_PROVINCE,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_TOP,ES_KEEPSIZE,0)
	EASYSIZE(IDC_COMBPROVINCE,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_PROVINCE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_CITY,ES_KEEPSIZE,ES_BORDER,IDC_COMBPROVINCE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_COMBCITY,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_CITY,ES_KEEPSIZE,0)
	EASYSIZE(IDC_RADIO1,ES_KEEPSIZE,ES_BORDER,IDC_COMBCITY,ES_KEEPSIZE,0)
	EASYSIZE(IDC_RADIO2,ES_KEEPSIZE,ES_BORDER,IDC_RADIO1,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_BOTTOM,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	EASYSIZE(IDC_BUTT_STATUS,ES_KEEPSIZE,ES_KEEPSIZE,IDC_STATIC_BOTTOM,ES_BORDER,0)
	EASYSIZE(IDC_BUTTON5,ES_KEEPSIZE,ES_KEEPSIZE,IDC_BUTT_STATUS,ES_BORDER,0)
	EASYSIZE(IDC_BUTTON6,ES_KEEPSIZE,ES_KEEPSIZE,IDC_BUTTON5,ES_BORDER,0)
	EASYSIZE(IDC_LIST1,ES_BORDER,ES_BORDER,ES_BORDER,IDC_STATIC_BOTTOM,0)
END_EASYSIZE_MAP



// CDeviceQueryDlg ��Ϣ�������



void CDeviceQueryDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������	
	/*int nCheck=0;
	for (int i=0;i<m_listDevice.GetItemCount();i++)
	{
	if (m_listDevice.GetCheck(i))
	{
	nCheck++;
	}
	}
	if (nCheck==0)
	{
	MessageBox("��ǰδѡ���κ���Ϣ","��ܰ��ʾ");
	return;
	}*/
	
	CMessageListDlg *pMSGDlg=new CMessageListDlg;
	pMSGDlg->pQueryDlg=this;
	//pMSGDlg->DoModal();
	if (IDCANCEL==pMSGDlg->DoModal())
	{
		GetDlgItem(IDC_BUTT_DEVICELIST)->SetFocus();
	}
	
}


void CDeviceQueryDlg::OnClickedButtonLastStep()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


BOOL CDeviceQueryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	INIT_EASYSIZE;

	//�豸�б��ʼ������
	CRect rect;
	m_listDevice.GetClientRect(&rect);
	m_listDevice.SetExtendedStyle(m_listDevice.GetExtendedStyle()|LVS_EX_FULLROWSELECT/*|LVS_EX_GRIDLINES*/|LVS_EX_CHECKBOXES);

	int nIndex=0;
	m_listDevice.InsertColumn(nIndex++,"�豸ID",LVCFMT_CENTER,100);
	m_listDevice.InsertColumn(nIndex++,"ʹ��״̬",LVCFMT_LEFT,100);
	m_listDevice.InsertColumn(nIndex++,"�豸Mac",LVCFMT_LEFT,170);
	m_listDevice.InsertColumn(nIndex++,"�Զ����豸��",LVCFMT_LEFT,150);
	m_listDevice.InsertColumn(nIndex++,"ʡ��",LVCFMT_LEFT,0);
	m_listDevice.InsertColumn(nIndex++,"����",LVCFMT_LEFT,0);
	m_listDevice.InsertColumn(nIndex++,"����",LVCFMT_LEFT,130);
	m_listDevice.InsertColumn(nIndex++,"���õ���ģ",LVCFMT_LEFT,250);
	m_listDevice.InsertColumn(nIndex++,"��ģ���ݰ�",LVCFMT_LEFT,0);
	m_listDevice.InsertColumn(nIndex++,"��ַ",LVCFMT_LEFT,480);

	//ʡ������
	m_combProvince.AddString("ȫ��");
	CString strSqlp,strProvince;
	strSqlp.Format("select distinct ʡ�� from DeviceRegisted");
	theApp.m_ado.ExecuteSelect(strSqlp);
	while(!theApp.m_ado.IsEOF())
	{
		theApp.m_ado.GetString("ʡ��",strProvince);
		m_combProvince.AddString(strProvince);
		theApp.m_ado.MoveNext();
	}
	m_combProvince.SetCurSel(0);
	m_combCity.AddString(_T("ȫ��"));
	m_combCity.SetCurSel(0);

	//��һ����ť��ʼ��Ϊ���ɵ��
	GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTT_STATUS)->EnableWindow(FALSE);

	//������ֱ��ʱ䶯
	CRect rect1;      
	GetClientRect(&rect1);     //ȡ�ͻ�����С    
	old.x=rect1.right-rect1.left;  
	old.y=rect1.bottom-rect.top;  
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);  
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);  
	CRect rt;  
	SystemParametersInfo(SPI_GETWORKAREA,0,&rt,0);  
	cy = rt.bottom;  
	MoveWindow(0, 0, cx, cy);  
//////////////////////////////////////////////////////////////////////////
	m_brush.CreateSolidBrush(RGB(255,255,255));
//////////////////////
	nPress=0;
	bHaveBeenCreate=FALSE;
///////////////////////////
	m_edtID.SetLimitText(8);
	m_edtAddress.SetLimitText(30);
	m_edtDevSID.SetLimitText(12);
//////////////////////////////////////////////////////////////////////////
	SetTimer(1,7,NULL);
	
	GetDlgItem(IDC_STATIC_TOP)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DEVICEDID)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_DEVICEDID)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DID)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_DEVICEID)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DEVICENAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_DEVICENAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_HIGHQUERY)->SetWindowTextA(_T(">>�߼���ѯ"));
//////////////////////////////////////////////////////////////////////////
	iPressHigh=0;

	GetDlgItem(IDC_BUTT_DEVICELIST)->SetFocus();
//////////////////////////////////////////////////////////////////////////
	m_pStatBar=new CStatusBarCtrl;
	RECT recta;
	GetClientRect(&recta);
	recta.top=recta.bottom-20;
	m_pStatBar->Create(WS_BORDER|WS_CHILD|WS_VISIBLE|CBRS_BOTTOM,recta,this,4);
	int nP1=(int)cx/2;
	int nP2=(int)nP1/4+nP1;
	int nP3=(int)nP1/4+nP2;
	int nP4=(int)nP1/4+nP3;
	int nPart[5]={nP1,nP2,nP3,nP4,-1};
	m_pStatBar->SetParts(5,nPart);
	m_pStatBar->SetText(_T("����������0 ��"),1,1);
	m_pStatBar->SetText(_T("�ɹ����أ�0 ��"),2,2);
	m_pStatBar->SetText(_T("�ɹ�ˢ����0 ��"),3,3);
	m_pStatBar->SetText(_T("��"),4,4);
	//--------------ToolTip---------------------
	m_TlTips.Create(this);
	m_TlTips.AddTool(GetDlgItem(IDC_STATIC_HIGHQUERY),TEXT(_T("��������ؼ��ֿ�ʵ��ģ����ѯ")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTT_STATUS),TEXT(_T("�л��豸״̬Ϊ���û�������")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTTON5),TEXT(_T("��������������")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTTON6),TEXT(_T("����������Ϣ���,����,��������")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTT_DEVICELIST),TEXT(_T("ˢ���б���߲�ѯ������ѡ�������豸")));
//////////////////////////////////////////////////////////////////////////
	return FALSE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDeviceQueryDlg::OnClickedButtDevicelist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	nPress=0;
	m_listDevice.DeleteAllItems();
	m_checkAll.SetCheck(FALSE);

	CString strSQL,strsqlL,strDeviceID,strStatus,strDeviceDMAC,strProvinceL,strCityL,strCountryL,strSetinFont,strFontPacket,strAdress;
	strSQL.Format("select �豸DID,ʹ��״̬,�豸DMAC,�豸DMAC����,ʡ��,����,����,���õ���ģ,��ģ���ݰ�,��ַ from DeviceRegisted   where  1=1 ");
	//�ͻ�CID='1052672'  
	//ʡ,������
	int iCity,iProV;
	CString strsqlPro,strsqlCit;
	iProV=m_combProvince.GetCurSel();
	iCity=m_combCity.GetCurSel();
	if (iProV>0)
	{
		m_combProvince.GetLBText(iProV,strProvinceL);
		strsqlPro.Format(" and ʡ��='%s'",strProvinceL);
		strSQL +=strsqlPro;
	}
	if (iCity>0)
	{
		m_combCity.GetLBText(iCity,strCityL);
		strsqlCit.Format(" and ����='%s'",strCityL);
		strSQL +=strsqlCit;
	}

	//�豸״̬
	CString strsqla;
	BOOL bCheck=FALSE;
	if (BST_CHECKED==IsDlgButtonChecked(IDC_RADIO1))
	{
		bCheck=TRUE;
		strsqla.Format(" and ʹ��״̬='����' ");
	}
	else if(BST_CHECKED==IsDlgButtonChecked(IDC_RADIO2))
	{
		bCheck=TRUE;
		strsqla.Format(" and ʹ��״̬='����' ");
	}
	strSQL +=strsqla;

	//�豸��
	CString strDeviceName,strsqlName;
	m_edtDeviceName.GetWindowTextA(strDeviceName);
	if (!strDeviceName.IsEmpty())
	{
		strsqlName.Format(" and �豸DMAC���� like '%%"+strDeviceName+"%%'");
		strSQL +=strsqlName;
	}

	//�豸ID
	CString strsqlID,strEdtID;
	m_edtID.GetWindowTextA(strEdtID);
	if (!strEdtID.IsEmpty())
	{
		strsqlID.Format(" and �豸DID like '%%"+strEdtID+"%%'");
		strSQL +=strsqlID;
	}

	//�豸DMAC
	CString strsqld,strEdtDMac;
	m_edtDevSID.GetWindowTextA(strEdtDMac);
	if (strEdtDMac!=_T(""))
	{
		strsqld.Format("and �豸DMAC like '%%"+strEdtDMac+"%%'");
		strSQL +=strsqld;
	}

	//��ַ
	CString strsqladdr,strEdtAddr;
	m_edtAddress.GetWindowTextA(strEdtAddr);
	if (!strEdtAddr.IsEmpty())
	{
		strsqladdr.Format(" and ��ַ like '%%"+strEdtAddr+"%%'");
		strSQL +=strsqladdr;
	}

	//����
	CString strsqlOrder;
	strsqlOrder.Format(" order by ����");
	strSQL +=strsqlOrder;

	if (theApp.m_ado.ExecuteSelect(strSQL))
	{
		while(!theApp.m_ado.IsEOF())
		{
			theApp.m_ado.GetString("�豸DID",strDeviceID);
			int n=m_listDevice.GetItemCount();
			m_listDevice.InsertItem(n,strDeviceID);

			theApp.m_ado.GetString("ʹ��״̬",strStatus);
			strStatus.Replace(" ","");
			m_listDevice.SetItemText(n,1,strStatus);

			theApp.m_ado.GetString("�豸DMAC",strDeviceDMAC);
			m_listDevice.SetItemText(n,2,strDeviceDMAC);

			CString strDMacAli;
			theApp.m_ado.GetString("�豸DMAC����",strDMacAli);
			strDMacAli.Replace(" ","");
			m_listDevice.SetItemText(n,3,strDMacAli);

			theApp.m_ado.GetString("ʡ��",strProvinceL);
			m_listDevice.SetItemText(n,4,strProvinceL);

			theApp.m_ado.GetString("����",strCityL);
			m_listDevice.SetItemText(n,5,strCityL);

			theApp.m_ado.GetString("����",strCountryL);
			strCountryL.Replace(" ","");
			m_listDevice.SetItemText(n,6,strCountryL);

			theApp.m_ado.GetString("���õ���ģ",strSetinFont);
			strSetinFont.Replace(" ","");
			m_listDevice.SetItemText(n,7,strSetinFont);

			theApp.m_ado.GetString("��ģ���ݰ�",strFontPacket);
			m_listDevice.SetItemText(n,8,strFontPacket);

			theApp.m_ado.GetString("��ַ",strAdress);
			strAdress.Replace(" ","");
			m_listDevice.SetItemText(n,9,strAdress);

			theApp.m_ado.MoveNext();
		}
	}
	int iCounts=m_listDevice.GetItemCount();
	CString strCounts;
	strCounts.Format(_T("��ǰ��ʾ��Ϣ��:%d"),iCounts);
	m_pStatBar->SetText(strCounts,0,0);
}


void CDeviceQueryDlg::OnSelchangeCombProvince()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��������
	CString strSqlc,strCity,strProvince;
	int iProv;
	iProv=m_combProvince.GetCurSel();
	m_combProvince.GetLBText(iProv,strProvince);
	if (strProvince==_T("ȫ��"))
	{
		m_combCity.AddString(_T("ȫ��"));
		m_combCity.SetCurSel(0);
	}
	int iIndex =m_combCity.GetCount();
	while(iIndex--)
		m_combCity.DeleteString(iIndex);
	
	strSqlc.Format("select distinct ���� from DeviceRegisted where ʡ��='%s' ",strProvince);
	theApp.m_ado.ExecuteSelect(strSqlc);
	m_combCity.AddString(_T("ȫ��"));
	while(!theApp.m_ado.IsEOF())
	{
		m_combCity.SetCurSel(0);
		theApp.m_ado.GetString("����",strCity);
		m_combCity.AddString(strCity);
		theApp.m_ado.MoveNext();
	}
}

//������ð�ť
void CDeviceQueryDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDeviceQueryDlg::OnClickedCheckAll()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int iCount=m_listDevice.GetItemCount();
	BOOL bCheck=FALSE;
	if (BST_CHECKED==IsDlgButtonChecked(IDC_CHECKALL))
	{
		bCheck=TRUE;
		GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	}
	else
		GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
		
	for (int i=0;i<iCount;i++)
	{
		m_listDevice.SetCheck(i,bCheck);
	}

}

//ʹ��״̬�ı�
void CDeviceQueryDlg::OnClickedButtStatusFlag()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	for (int i=0;i<m_listDevice.GetItemCount();i++)
	{
		if (m_listDevice.GetCheck(i))
		{
			int iCheck=m_listDevice.GetItemCount();
			CString strsqlCheck,strDeviceDID,strDeviceStatus;
			strDeviceDID=m_listDevice.GetItemText(i,0);
			strDeviceStatus=m_listDevice.GetItemText(i,1);
			if (strDeviceStatus==_T("����"))
			{
				strsqlCheck.Format("update DeviceRegisted set ʹ��״̬='����'   where �豸DID='%s' ",strDeviceDID);
				if (theApp.m_ado.ExecuteSql(strsqlCheck))
				{
					m_listDevice.SetItemText(i,1,"����");
					m_listDevice.SetCheck(i,FALSE);
				}
			}
			else 
			{
				strsqlCheck.Format("update DeviceRegisted set ʹ��״̬='����'   where �豸DID='%s' ",strDeviceDID);
				if (theApp.m_ado.ExecuteSql(strsqlCheck))
				{
					m_listDevice.SetItemText(i,1,"����");
					m_listDevice.SetCheck(i,FALSE);
				}
			}
		}
	}
	UpdateData();
}


//�ж�LIST���Ƿ񱻵����ѡ����ѡ����Ե����һ����ť
void CDeviceQueryDlg::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	 //TODO: �ڴ���ӿؼ�֪ͨ����������
	
	///////////////////////////////////////////////////////
	
	

	*pResult = 0;
}


HBRUSH CDeviceQueryDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����


	if (pWnd-> GetDlgCtrlID() == IDC_STATIC_PROVINCE || pWnd-> GetDlgCtrlID() == IDC_STATIC_CITY|| pWnd-> GetDlgCtrlID() ==IDC_STATIC_DevStat||
		pWnd-> GetDlgCtrlID() ==IDC_STATIC_DID|| pWnd-> GetDlgCtrlID() == IDC_STATIC_DEVICEDID || pWnd-> GetDlgCtrlID() == IDC_STATIC_ADDRESS||
		pWnd->GetDlgCtrlID()==IDC_STATIC_DEVICENAME)
	{
		//pDC->SetTextColor(RGB(255,255,255)); //��������Ϊ��ɫ

		pDC->SetBkMode(TRANSPARENT);         //���ñ���Ϊ͸��
		return   HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID()==IDC_STATIC_HIGHQUERY)
	{
		pDC->SetTextColor(RGB(0,0,255));
		//pDC->SetBkMode(TRANSPARENT);
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	return m_brush;

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CDeviceQueryDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(1)) /* old state : unchecked */ 
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(2)) /* new state : checked */ 
		) 
	{ 
		GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
		nItem=pNMLV->iItem;
		GetDlgItem(IDC_BUTT_STATUS)->EnableWindow(TRUE);
	} 
	else if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(2)) /* old state : checked */ 
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(1)) /* new state : unchecked */ 
		) 
	{ 
		//TRACE("Item %d is unchecked\n", pNMLV->iItem);
		GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTT_STATUS)->EnableWindow(FALSE);
	} 
	else 
	{ 
		//TRACE("Item %d does't change the check-status\n", pNMLV->iItem); 
	} 

	*pResult = 0;
}

//�б�����Ļص�����
int CALLBACK  CDeviceQueryDlg::ListCompare(LPARAM lParam1,LPARAM lParam2,LPARAM lParamSort)
{
	int row1=(int)lParam1;
	int row2=(int)lParam2;

	CListCtrl *pLc=(CListCtrl *)lParamSort;
	CString str1=pLc->GetItemText(row1,0);
	CString str2=pLc->GetItemText(row2,0);

	if (bSort)
	{
		return strcmp(str1,str2);
	}
	else
		return strcmp(str2,str1);
}

//����б��������һ������
void CDeviceQueryDlg::OnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (pNMLV->iSubItem==0)
	{
		bSort=!bSort;
		int nCount=m_listDevice.GetItemCount();
		for (int i=0;i<nCount;i++)
		{
			m_listDevice.SetItemData(i,i);
		}
		m_listDevice.SortItems(ListCompare,(LPARAM)&m_listDevice);
	}
	*pResult = 0;
}


void CDeviceQueryDlg::OnDblclkListDoubleClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW *pEditCtrl=(NM_LISTVIEW *)pNMHDR;
	printf("��:%d,��:%d\n",pEditCtrl->iItem,pEditCtrl->iSubItem);
	if (pEditCtrl->iItem==-1)
	{
		if (bHaveBeenCreate==TRUE)
		{
			DestroyEdit(&m_listDevice,&m_edit,e_iTem,e_SubItem);
			bHaveBeenCreate=FALSE;
		}
	}	
	else if (pEditCtrl->iSubItem==3)
	{
		if (bHaveBeenCreate==TRUE)
		{
			if (e_iTem!=pEditCtrl->iItem&&e_SubItem!=pEditCtrl->iSubItem)
			{
				DestroyEdit(&m_listDevice,&m_edit,e_iTem,e_SubItem);
				bHaveBeenCreate=FALSE;
				CreateEdit(pEditCtrl,&m_edit,e_iTem,e_SubItem,bHaveBeenCreate);
			}
			else
			{
				m_edit.SetFocus();
			}
		}
		else
		{
			e_iTem=pEditCtrl->iItem;
			e_SubItem=pEditCtrl->iSubItem;
			CreateEdit(pEditCtrl,&m_edit,e_iTem,e_SubItem,bHaveBeenCreate);
		}
	}

	*pResult = 0;
}

void CDeviceQueryDlg::OnRclickListChangeName(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	

	*pResult = 0;
}


void CDeviceQueryDlg::DestroyEdit(CListCtrl *list, CEdit* destroyEdit, int &Item, int &SubItem)
{
	CString strEditData;
	destroyEdit->GetWindowTextA(strEditData);
	m_listDevice.SetItemText(Item,SubItem,strEditData);     //�����Ӧ��Ԫ���ַ� 
	destroyEdit->DestroyWindow();                           //���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
}

void CDeviceQueryDlg::CreateEdit(NM_LISTVIEW *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool bHadCreate)
{
	Item=pEditCtrl->iItem;                         //�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem=pEditCtrl->iSubItem;
	createdit->Create(ES_AUTOHSCROLL| WS_CHILD | ES_LEFT | ES_WANTRETURN ,CRect(0,0,0,0),this,IDC_EDIT_LISTEDIT);    //�����༭�����,IDC_EDIT_CREATEIDΪ�ؼ�ID��1141,��Resource.h�ж���
	bHadCreate=TRUE;
	createdit->SetFont(this->GetFont(),FALSE);  //��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createdit->SetParent(&m_listDevice);                     //��list control����Ϊ������,���ɵ�Edit������ȷ��λ,���Ҳ����Ҫ  
	CRect editRect;
	m_listDevice.GetSubItemRect(e_iTem,e_SubItem,LVIR_LABEL,editRect);    //��ȡ��Ԫ��Ŀռ�λ����Ϣ 
	editRect.SetRect(editRect.left,editRect.top,editRect.left+m_listDevice.GetColumnWidth(e_SubItem)-1,editRect.bottom-1);        //+1��-1�����ñ༭�����ڵ�ס�б���е�������  
	CString strItem=m_listDevice.GetItemText(e_iTem,e_SubItem);     //�����Ӧ��Ԫ���ַ� 
	createdit->SetWindowTextA(strItem);                                    //����Ԫ���ַ���ʾ�ڱ༭����
	createdit->MoveWindow(&editRect);                                  //���༭��λ�÷�����Ӧ��Ԫ���� 
	createdit->ShowWindow(SW_SHOW);                               //��ʾ�༭���ڵ�Ԫ������ 
	createdit->SetLimitText(10);												  //�༭�������ַ�����
	createdit->SetFocus();                                                        //����Ϊ����
	createdit->SetSel(-1);															//���ù�����ı������ֵ����
}

void CDeviceQueryDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}

void CDeviceQueryDlg::OnKillFocusListEdit()
{
	DestroyEdit(&m_listDevice,&m_edit,e_iTem,e_SubItem);
	bHaveBeenCreate=FALSE;
	CString strAli,strSql,strDeV,strDMac;
	strAli=m_listDevice.GetItemText(e_iTem,e_SubItem);
	try
	{
		if (!strAli.IsEmpty())
		{
			strDeV=m_listDevice.GetItemText(e_iTem,0);               //��ȡ��Ӧ���豸DID
			strDeV.Replace(" ","");
			strDMac=m_listDevice.GetItemText(e_iTem,2);            //�����Ӧ�豸DMAC
			strSql.Format("update DeviceRegisted set �豸DMAC����='%s' where �豸DID='%s' and �豸DMAC='%s' ",strAli,strDeV,strDMac);
			if (IDCANCEL==MessageBox("ȷ���Զ�����豸������","��ܰ��ʾ",MB_OKCANCEL))
			{
				m_listDevice.SetItemText(e_iTem,3,"");
				return ;
			}
			else
				theApp.m_ado.ExecuteSql(strSql);
		}
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return ;
	}
}




void CDeviceQueryDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	UPDATE_EASYSIZE; //���´��ڴ�С
}


void CDeviceQueryDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: �ڴ˴������Ϣ����������
	EASYSIZE_MINSIZE(1263,694,fwSide,pRect);
}


void CDeviceQueryDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nIDEvent)
	{
	case 1:
		OnClickedButtDevicelist();
		KillTimer(1);
		break;
	case 2:
		OnRecVPulishMSG(ncheck,num);
		if (bFlag==TRUE )
		{
			KillTimer(1);
		}
		break;
	default: break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CDeviceQueryDlg::OnClickedStaticHighquery()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	iPressHigh++;
	if (iPressHigh%2==0)
	{
		GetDlgItem(IDC_STATIC_DEVICEDID)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_DEVICEDID)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DID)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_DEVICEID)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DEVICENAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_DEVICENAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_HIGHQUERY)->SetWindowTextA(_T(">>"));
	}
	else
	{
		GetDlgItem(IDC_STATIC_DEVICEDID)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_DEVICEDID)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_DID)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_DEVICEID)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_DEVICENAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_DEVICENAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_HIGHQUERY)->SetWindowTextA(_T("<<"));
	}
}




BOOL CDeviceQueryDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message==WM_KEYDOWN&&pMsg->wParam==VK_RETURN)
	{
		GetNextDlgTabItem(GetFocus())->SetFocus();
	}

	if (pMsg->message==WM_MOUSEMOVE)
	{
		m_TlTips.RelayEvent(pMsg);
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


LRESULT CDeviceQueryDlg::OnRecVPulishMSG(WPARAM wParam,LPARAM lParam)
{
	SetTimer(2,3000,NULL);
	ncheck=wParam;
	num=lParam;
	int x=0,y=0;
	int iPlsSuccess,iSetSuccess,iUser;
	iUser=atoi(theApp.strUserName);
	int nPlsCount=num*ncheck;
	CString strsqlp,strPlsSuccess,strSetSuccess;
	strsqlp.Format("select top %d ������SID,��������,�ɹ�������ģ��,�ɹ�������ģ��  from MessageBuffer where ������SID=%d  order by �������� desc ",ncheck,iUser);
	if (theApp.m_ado.ExecuteSelect(strsqlp))
	{
		while(!theApp.m_ado.IsEOF())
		{
			theApp.m_ado.GetInt("�ɹ�������ģ��",iPlsSuccess);
			x+=iPlsSuccess;
			theApp.m_ado.GetInt("�ɹ�������ģ��",iSetSuccess);
			y+=iSetSuccess;
			theApp.m_ado.MoveNext();
		}
		CString strPlsCount,strPhone,strLED;
		strPlsCount.Format(_T("��������:%d ��"),nPlsCount);
		strPhone.Format(_T("�ɹ����أ�%d ��"),x);
		strLED.Format(_T("�ɹ�ˢ����%d ��"),y);
		m_pStatBar->SetText(strPlsCount,1,1);
		m_pStatBar->SetText(strPhone,2,2);
		m_pStatBar->SetText(strLED,3,3);
		if (nPlsCount==x&&nPlsCount==y)
		{
			bFlag=TRUE;
			m_pStatBar->SetText(_T("�����"),4,4);
		}
		else
		{
			bFlag=FALSE;
			m_pStatBar->SetText(_T("������..."),4,4);
		}

	}
	return TRUE;
}

