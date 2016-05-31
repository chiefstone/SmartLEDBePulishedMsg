
// SingleDemonDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "SingleDemonDlg.h"
#include "afxdialogex.h"
#include "DeviceQueryDlg.h"
//#include "resource.h"
#include "AffirmManage.h"
#include "VersionDlg.h"
#include "HistoryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
 

SOCKADDR_IN addrTo;

//��ģ����
unsigned char sql_zimubuffer[1280] = {0};
//��ģ���ݳ���
long sql_zimudatasize;

int HeartTime_ID1 =1000;

char recvBuf[3000];

//��½����
unsigned char loginbuffer[50] = {0x4C, 0x4B, 0x50, 0xFF, 0xFF, 0x64, 0xA6, 0x51, 0x7A, 0x44, 0x74, 0x00, 0x16, 0x3E, 0x00, 0x00, 0x35, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x12, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,  0x0B, 0x31, 0x33, 0x37, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0xFF, 0x0D, 0x00};                 
//��������
unsigned char heartbuffer[32] = {0x4C, 0x4B, 0x50, 0xFF, 0xFF, 0x64, 0xA6, 0x51, 0x7A, 0x44, 0x74, 0x00, 0x16, 0x3E, 0x00, 0x00, 0x35, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0xFF, 0x0D, 0x00};                 



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSingleDemonDlg �Ի���




CSingleDemonDlg::CSingleDemonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSingleDemonDlg::IDD, pParent)
	, strContentTest(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strAddAffirm = _T("");
}

void CSingleDemonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_edtUserName);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_edtPassWord);
}

BEGIN_MESSAGE_MAP(CSingleDemonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSingleDemonDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTT_PULISH, &CSingleDemonDlg::OnBnClickedButtPulish)
	ON_BN_CLICKED(IDC_BUTT_MATRIX, &CSingleDemonDlg::OnClickedButtMatrixManage)
	ON_BN_CLICKED(IDC_BUTTON,&CSingleDemonDlg::OnBnClickedButton00)
	ON_BN_CLICKED(IDC_BUTT_LOGIN, &CSingleDemonDlg::OnClickedButtLogin)
	ON_BN_CLICKED(IDC_SEND_MSG,&CSingleDemonDlg::OnBnClickedSend)
	ON_MESSAGE(WM_RECVDATA,OnRecvData)//��ӽ����߳���Ϣӳ��
	ON_BN_CLICKED(IDC_START_BUTTON,&CSingleDemonDlg::OnBnClickedStartButton)
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_PULISHMESSAGE,OnRecVPulishMSG)
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_STATIC_VERSION, &CSingleDemonDlg::OnClickedStaticVersion)
	ON_BN_CLICKED(IDC_BUTT_HISTORY, &CSingleDemonDlg::OnBnClickedButtHistory)
END_MESSAGE_MAP()


// CSingleDemonDlg ��Ϣ�������

BOOL CSingleDemonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP_BACKHOME);
	m_brBk.CreatePatternBrush(&bmp);
	bmp.DeleteObject();
///////////////////////////////////
	m_edtPassWord.SetPasswordChar('*');
/////////////////////////////
	CFont *pfont=new CFont;
	pfont->CreateFontA(30,12,0,0,200,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,FF_SWISS,"΢���ź�");
	CEdit *pedit=(CEdit *)GetDlgItem(IDC_STATIC_COMPANY);
	pedit->SetFont(pfont,FALSE);
	GetDlgItem(IDC_STATIC_COMPANY)->SetFont(pfont);
//////////////////////////////////////////////
   GetDlgItem(IDC_STATIC_USNAME)->ShowWindow(SW_HIDE);
   GetDlgItem(IDC_STATIC_PSWORD)->ShowWindow(SW_HIDE);
   GetDlgItem(IDC_EDIT_USERNAME)->ShowWindow(SW_HIDE);
   GetDlgItem(IDC_EDIT_PASSWORD)->ShowWindow(SW_HIDE);
   GetDlgItem(IDC_BUTT_LOGIN)->ShowWindow(SW_HIDE);
   GetDlgItem(IDC_BUTT_REGISTER)->ShowWindow(SW_HIDE);

   GetDlgItem(IDC_BUTT_MATRIX)->EnableWindow(FALSE);
   GetDlgItem(IDC_BUTT_PULISH)->EnableWindow(FALSE);
   /*GetDlgItem(IDC_BUTT_DEVICE)->EnableWindow(FALSE);
   GetDlgItem(IDC_BUTT_USER)->EnableWindow(FALSE);*/
   GetDlgItem(IDC_BUTT_HISTORY)->EnableWindow(FALSE);
//////////////////////////////////////////	

   CString strsql,strCount;
   int it=0;
   strsql.Format("select t=COUNT(*) from DeviceRegisted ");
   if (theApp.m_ado.ExecuteSelect(strsql))
   {
	   theApp.m_ado.GetInt("t",it);
	   strCount.Format("%d",it);
	   GetDlgItem(IDC_STATIC_DEVICOUNT)->SetWindowTextA(strCount);
   }
//////////////////////////////////////////////
   //UDP
   SetDlgItemTextA(IDC_PORT_EDIT,"7000");//��ʼ�����ն˿�ֵ

   SetDlgItemTextA(IDC_SENDPORT,"1234");//��ʼ�����Ͷ˿�ֵ

   SetDlgItemText(IDC_IPADDRESS1,"120.25.102.127");//��ʼ������IP��ַ

   GetDlgItem(IDC_SEND_MSG)->EnableWindow(FALSE);

   WORD wVersionRequested;
   WSADATA wsaData;//WSAata�����洢ϵͳ���صĹ���WinSocket�����ϡ�
   int err;

   wVersionRequested = MAKEWORD( 1, 1 );

   err = WSAStartup( wVersionRequested, &wsaData );
   if ( err != 0 ) {
	   //  return;
   }

   if ( LOBYTE( wsaData.wVersion ) != 1 ||HIBYTE( wsaData.wVersion ) != 1 ) 
   {
	   WSACleanup( ); 
	   //  return;
   }

   //Ĭ���û�
   m_edtUserName.SetWindowText(_T("10244"));
   m_edtPassWord.SetWindowText(_T("888888"));
////////////////////////////////////////////״̬������
   m_pStatBar=new CStatusBarCtrl;
   RECT rect;
   GetClientRect(&rect);
   rect.top=rect.bottom-20;
   m_pStatBar->Create(WS_BORDER|WS_CHILD|WS_VISIBLE|CBRS_BOTTOM,rect,this,4);
   int nPart[6]={250,700,820,940,1060,-1};
   m_pStatBar->SetParts(6,nPart);
   m_pStatBar->SetText(_T("����δ��¼,��Ҫ��¼��������ʹ�ñ���Ʒ"),0,0);
   /* CTime time;
   time=CTime::GetCurrentTime();
   CString strTm;
   strTm=time.Format(_T("%Y-%m-%d %H:%M:%S"));
   m_pStatBar->SetText(strTm,0,2);*/
   m_pStatBar->SetText(_T("����������0 ��"),2,2);
   m_pStatBar->SetText(_T("�ɹ����أ�0 ��"),3,3);
   m_pStatBar->SetText(_T("�ɹ�ˢ����0 ��"),4,4);
   m_pStatBar->SetText(_T("��"),5,5);

   num=0;
   ncheck=0;

   bClick=FALSE;
   bCliiick=FALSE;
//--------------Tooltip------------------------------//
   m_TlTips.Create(this);
   m_TlTips.AddTool(GetDlgItem(IDC_BUTTON1),TEXT(_T("������ѡ���¼����ע����ʹ�ñ���Ʒ")));
   m_TlTips.AddTool(GetDlgItem(IDC_BUTT_REGISTER),TEXT(_T("����û�е�¼�˺ţ���ע�����ʹ�ñ���Ʒ.")));
   m_TlTips.AddTool(GetDlgItem(IDC_BUTT_LOGIN),TEXT(_T("�����˺�����֮������¼ʹ��")));
   m_TlTips.AddTool(GetDlgItem(IDC_EDIT_USERNAME),TEXT(_T("��������ʹ���˺�,��û���˺�,��ע��")));
   m_TlTips.AddTool(GetDlgItem(IDC_EDIT_PASSWORD),TEXT(_T("��������ʹ������,������������ϵ����Ա")));
   m_TlTips.AddTool(GetDlgItem(IDC_BUTT_PULISH),TEXT(_T("����������Ϣ��ť,��ת���豸��ѯ����,��ʼ������Ϣ����")));
   m_TlTips.AddTool(GetDlgItem(IDC_BUTT_MATRIX),TEXT(_T("������Ϣ����ť,������Ϣ����棬����Ϣ��������ɾ������")));
   m_TlTips.AddTool(GetDlgItem(IDC_STATIC_VERSION),TEXT(_T("������ȡ�汾������Ϣ")));
   m_TlTips.AddTool(GetDlgItem(IDC_BUTT_HISTORY),TEXT(_T("������ʷ��ѯ��ť,����ɲ�ѯ��ʷ������Ϣ")));
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSingleDemonDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSingleDemonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSingleDemonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSingleDemonDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_BUTT_MATRIX)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_PULISH)->ShowWindow(SW_HIDE);
	/*GetDlgItem(IDC_BUTT_DEVICE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_USER)->ShowWindow(SW_HIDE);*/
	GetDlgItem(IDC_BUTT_HISTORY)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_MANAGE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_ONLINE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DEVICOUNT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC_USNAME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_PSWORD)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_USERNAME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_PASSWORD)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTT_LOGIN)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTT_REGISTER)->ShowWindow(SW_SHOW);
}


void CSingleDemonDlg::OnBnClickedButtPulish()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ShowWindow(SW_HIDE);
	/*CDeviceQueryDlg *pDlg =new CDeviceQueryDlg;
	pDlg->Create(IDD_DeViceQuery_DIALOG,this);
	pDlg->ShowWindow(SW_SHOW);*/
	CDeviceQueryDlg Dlg;
	Dlg.DoModal();
}


void CSingleDemonDlg::OnClickedButtMatrixManage()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAffirmManage Dlg;
	bClick=TRUE;
	Dlg.DoModal();
}


void CSingleDemonDlg::OnBnClickedButton00()
{
	iChaChang=3;
	iLengthTest=2;
	char chs[32]; //16*16=256���� 
	char echs[16];
	unsigned char s[1000] = {0}; //Ҫ��ʾ�ĺ��� 

	CString mystr;
	/*mystr = strAddAffirm;*/
	mystr=strContentTest;
	sql_zimudatasize = 0;
	iLengthTest = mystr.GetLength()*16;
	iChaChang = mystr.GetLength();

	memcpy(s, mystr, mystr.GetLength()*2); 

	for(int i = 0;i < mystr.GetLength();i++)
	{
		if (s[i] > 0xa0)
		{
			FILE *fp=NULL; 
			unsigned long offset; 

			offset=((s[i]-0xa1)*94+(s[i+1]-0xa1))*32; //���������ҳ�������HZK16�е�ƫ��λ��

			if((fp=fopen("HZKS_16_Z.DZK","rb"))==NULL) return; //���ֿ��ļ� 
			fseek(fp,offset,SEEK_SET); //�ļ�ָ��ƫ�Ƶ�Ҫ�ҵĺ��ִ� 
			fread(chs,32,1,fp); //��ȡ�ú��ֵ���ģ 
			fclose(fp); 
			for (int i1 = 0;i1 < 32;i1++)
			{
				sql_zimubuffer[16*i+i1] = chs[i1];
			}
			Bytes_Display(chs); //����Ļ����ʾ������� 
			i = i+1;

			sql_zimudatasize = sql_zimudatasize + 32;

		}
		else
		{
			FILE *fp; 
			unsigned long offset; 

			offset=s[i]*16; //���������ҳ�ƫ��λ��

			if((fp=fopen("ASC_16_Z.DZK","rb"))==NULL) return; //���ֿ��ļ� 
			fseek(fp,offset,SEEK_SET); //�ļ�ָ��ƫ�Ƶ�Ҫ�ҵĺ��ִ� 
			fread(echs,16,1,fp); //��ȡ�ú��ֵ���ģ 
			fclose(fp); 
			for (int i1 = 0;i1 < 16;i1++)
			{
				sql_zimubuffer[16*i+i1] = echs[i1];
			}
			sql_zimudatasize = sql_zimudatasize + 16;
		}

	}

	//����
	for (int i = 0;i<iLengthTest;i++)
	{
		if (sql_zimubuffer[i] != 0x00)
		{
			sql_zimubuffer[i] = (byte) ((sql_zimubuffer[i] & 0x55) << 1 | (sql_zimubuffer[i] & 0xAA) >> 1);
			sql_zimubuffer[i] = (byte) ((sql_zimubuffer[i] & 0x33) << 2 | (sql_zimubuffer[i] & 0xCC) >> 2);
			sql_zimubuffer[i] = (byte) ((sql_zimubuffer[i] & 0x0F) << 4 | (sql_zimubuffer[i] & 0xF0) >> 4);
		}
	}


	//��λȡ��
	for (int i = 0;i<iLengthTest;i++)
	{
		sql_zimubuffer[i] = ~sql_zimubuffer[i];
	}

	zimuDianzhenStr = "";

	CString zimutemp11,zimutemp12,zimutemp110,zimutemp11e,zimutemp110e;

	//��ģ����ƴ�ӳ��ַ���
	for (int i = 0;i < mystr.GetLength();i++)
	{
		if (s[i] > 0xa0)
		{

			for (int j = 0;j < 32;j++)
			{
				CString zimutemp1,zimutemp2;
				zimutemp1 = "";
				zimutemp2 = "";
				if(j%2 == 0)
				{
					zimutemp2.Format(_T("%02X"), sql_zimubuffer[16*i+j]);
					if (zimutemp2.GetLength() > 2)
						zimutemp2 = zimutemp2.Right(2);
					if (j == 0)
					{
						zimutemp12 = zimutemp2;
					}
					else
					{
						zimutemp12 = zimutemp12 + " " + zimutemp2;
					}
				}
				else
				{
					zimutemp1.Format(_T("%02X"), sql_zimubuffer[16*i+j]);
					if (zimutemp1.GetLength() > 2)
						zimutemp1 = zimutemp1.Right(2);
					zimutemp11 = zimutemp11 + " " + zimutemp1;
				}
			}
			zimutemp110 = zimutemp12 + zimutemp11;
			zimutemp11 = "";
			zimutemp12 = "";
			if (i == 0)
			{
				zimuDianzhenStr = zimutemp110;
			}
			else
			{
				zimuDianzhenStr = zimuDianzhenStr + " " + zimutemp110;
			}
			i=i+1 ;
		}
		else
		{
			for (int j = 0;j < 16;j++)
			{
				CString zimutemp1e;
				zimutemp1e = "";

				zimutemp1e.Format(_T("%02X"), sql_zimubuffer[16*i+j]);
				if (zimutemp1e.GetLength() > 2)
					zimutemp1e = zimutemp1e.Right(2);
				if (j == 0)
				{
					zimutemp11e = zimutemp1e;
				}
				else
				{
					zimutemp11e = zimutemp11e + " " + zimutemp1e;
				}


			}
			zimutemp110e = zimutemp11e;
			zimutemp11e = "";
			if (i == 0)
			{
				zimuDianzhenStr = zimutemp110e;
			}
			else
			{
				zimuDianzhenStr =  zimuDianzhenStr + " " + zimutemp110e;
			}
		}

	}

}

void CSingleDemonDlg::Bytes_Display(char* const chs) 
{ 
	CString str;
	static int count = 0;

	int i; 

	for (i=0;i<32;i++)//��ʾ 
	{ 
		count++;
		str.Format(_T("%02X"), chs[i]);
		if (str.GetLength() > 2)
			str = str.Right(2);
		((CEdit *)GetDlgItem(IDC_EDIT_WORDDATA))->ReplaceSel(str + _T(" "));
		if (count >= 16)
		{
			((CEdit *)GetDlgItem(IDC_EDIT_WORDDATA))->ReplaceSel(_T("\r\n"));
			count = 0;
		}
	} 
}

//void CSingleDemonDlg::Bytes_Read_from_HZK16(unsigned char *s, char* const chs)
//{
//	FILE *fp; 
//	unsigned long offset; 
//
//	offset=((s[0]-0xa1)*94+(s[1]-0xa1))*32; //���������ҳ�������HZK16�е�ƫ��λ�� 
//
//	if((fp=fopen("HZK16","r"))==NULL) return; //���ֿ��ļ� 
//	fseek(fp,offset,SEEK_SET); //�ļ�ָ��ƫ�Ƶ�Ҫ�ҵĺ��ִ� 
//	fread(chs,32,1,fp); //��ȡ�ú��ֵ���ģ 
//	fclose(fp); 
//}

void CSingleDemonDlg::OnClickedButtLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_edtUserName.GetWindowTextA(theApp.strUserName);
	m_edtPassWord.GetWindowTextA(strPassWord);

	if (theApp.strUserName.IsEmpty()||strPassWord.IsEmpty())
	{
		MessageBox("��Ϣ����Ϊ��","��ܰ��ʾ");
		return;
	}
	//OnBnClickedStartButton();

	CString strsql,strLoginName,strLoginWord;
	strsql.Format("select ��¼����,�û�ID from UserRegisted where �û�ID ='%s' and  ��¼����='%s' ",theApp.strUserName,strPassWord);
	if (theApp.m_ado.ExecuteSelect(strsql))
	{
		theApp.m_ado.GetString("�û�ID",strLoginName);
		theApp.m_ado.GetString("��¼����",strLoginWord);
	}
	strLoginName.Replace(" ","");
	strLoginWord.Replace(" ","");
	//////////
	if (strcmp(strLoginName,theApp.strUserName)==0&&strcmp(strLoginWord,strPassWord)==0)
	{
		//MessageBox("��½�ɹ�","��ܰ��ʾ");
		OnBnClickedStartButton();

		GetDlgItem(IDC_BUTT_MATRIX)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTT_PULISH)->ShowWindow(SW_SHOW);
		/*GetDlgItem(IDC_BUTT_DEVICE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTT_USER)->ShowWindow(SW_SHOW);*/
		GetDlgItem(IDC_BUTT_HISTORY)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MANAGE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_ONLINE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_DEVICOUNT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGINING)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGINUSER)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_STATIC_USNAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PSWORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_USERNAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_PASSWORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTT_LOGIN)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTT_REGISTER)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_BUTT_MATRIX)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTT_PULISH)->EnableWindow(TRUE);
		/*GetDlgItem(IDC_BUTT_DEVICE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTT_USER)->EnableWindow(TRUE);*/
		GetDlgItem(IDC_BUTT_HISTORY)->EnableWindow(TRUE);

		GetDlgItem(IDC_STATIC_LOGINUSER)->SetWindowTextA(theApp.strUserName);
		
		m_pStatBar->SetText(_T("��¼�ɹ�,������������"),0,0);
	}
	else
	{
		MessageBox("�˺Ż��������","��ܰ��ʾ");
	}

}


void CSingleDemonDlg::OnBnClickedSend()
{
	DWORD dwIP;
	((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->GetAddress(dwIP);//��ȡ���Ͷ˿�

	int SendPort=GetDlgItemInt(IDC_SENDPORT);//��ȡ�����˿ں�

	//SOCKADDR_IN addrTo;
	addrTo.sin_family=AF_INET;
	addrTo.sin_port=htons(SendPort);
	addrTo.sin_addr.S_un.S_addr=htonl(dwIP);

	CString strSend;
	GetDlgItemText(IDC_WENZI_EDIT,strSend);//��ȡ������Ϣ

	//sendto(m_socket,strSend,strSend.GetLength()+1,0,(SOCKADDR*)&addrTo,sizeof(SOCKADDR));//������Ϣ
	CheckSumCal(loginbuffer,sizeof(loginbuffer));
	sendto(m_socket,(const char *)loginbuffer,sizeof(loginbuffer),0,(SOCKADDR*)&addrTo,sizeof(SOCKADDR));//������Ϣ
}


BOOL CSingleDemonDlg::InitSocket()
{
	m_socket=socket(AF_INET,SOCK_DGRAM,0);//UDP���ӷ�ʽ

	if(INVALID_SOCKET==m_socket)
	{
		AfxMessageBox("�׽��ִ���ʧ�ܣ�");
		return FALSE;
	}

	int m_port=GetDlgItemInt(IDC_PORT_EDIT);//��ȡ�����˿ں�

	SOCKADDR_IN addrSock;
	addrSock.sin_family=AF_INET;
	addrSock.sin_port=htons(m_port);
	addrSock.sin_addr.S_un.S_addr=htonl(INADDR_ANY);

	if(SOCKET_ERROR==bind(m_socket,(SOCKADDR*)&addrSock,sizeof(SOCKADDR)))
	{
		m_pStatBar->SetText(_T("�������ӹ���,����ϵ����Ա"),0,0);
		closesocket(m_socket);
		AfxMessageBox("��ʧ��!");
		return FALSE;

	}
	return TRUE;
}

DWORD WINAPI CSingleDemonDlg::RecvProc(LPVOID lpParameter)
{
	SOCKET sock=((RECVPARAM*)lpParameter)->sock;
	HWND hwnd=((RECVPARAM*)lpParameter)->hwnd;
	delete lpParameter;	

	SOCKADDR_IN addrFrom;
	int len=sizeof(SOCKADDR);

	char tempBuf[3500];

	while(TRUE)
	{
		if(SOCKET_ERROR==recvfrom(sock,recvBuf,2000,0,(SOCKADDR*)&addrFrom,&len))
			break;

		sprintf(tempBuf,"%ssend: %s",inet_ntoa(addrFrom.sin_addr),recvBuf);
		::PostMessage(hwnd,WM_RECVDATA,0,(LPARAM)tempBuf);//���ݽ�����Ϣ��������

	}
	return 0;
}


LRESULT CSingleDemonDlg::OnRecvData(WPARAM wParam,LPARAM lParam)
{
	CString str=(char*)lParam;
	CString strTemp;
	GetDlgItemText(IDC_EDIT_WORDDATA,strTemp);
	str+="\r\n";
	str+=strTemp;
	SetDlgItemText(IDC_EDIT_WORDDATA,str);

	CheckSumCal(heartbuffer,sizeof(heartbuffer));
	//sendto(m_socket,(const char *)heartbuffer,sizeof(heartbuffer),0,(SOCKADDR*)&addrTo,sizeof(SOCKADDR));//����������Ϣ
	//SetTimer(HeartTime_ID1, 5000, NULL);

	if(recvBuf[25] == 0x80 &&
		recvBuf[26] == 0x02)
	{
		recvBuf[21] = heartbuffer[17];
		recvBuf[22] = heartbuffer[18];
		recvBuf[23] = heartbuffer[19];
		recvBuf[24] = heartbuffer[20];

		sendto(m_socket,(const char *)heartbuffer,sizeof(heartbuffer),0,(SOCKADDR*)&addrTo,sizeof(SOCKADDR));//����������Ϣ
		SetTimer(HeartTime_ID1, 5000, NULL);
	}

	return 0;
}

void CSingleDemonDlg::OnBnClickedStartButton()
{
	if(InitSocket())//��ʼ��Socket
	{
		RECVPARAM *pRecvParam=new RECVPARAM;
		pRecvParam->sock=m_socket;
		pRecvParam->hwnd=m_hWnd;

		HANDLE hThread=CreateThread(NULL,0,RecvProc,(LPVOID)pRecvParam,0,NULL);//���������߳�
		CloseHandle(hThread);

		GetDlgItem(IDC_SEND_MSG)->EnableWindow(TRUE);//����Ͱ�ť
	}
	m_pStatBar->SetText(_T("���������ӳɹ������ڻ�ȡ���ݡ���"),0,0);
}

unsigned char CSingleDemonDlg::CheckSumCal(unsigned char *p,int len)
{
	unsigned char checksum;
	unsigned int i;

	checksum = 0;
	for (i = 0;i < len;i++)
	{
		checksum = checksum ^ *(p+i);
	}

	loginbuffer[len - 1] = checksum;


	return checksum;
}

HBRUSH CSingleDemonDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	if (pWnd-> GetDlgCtrlID() == IDC_STATIC_COMPANY || pWnd-> GetDlgCtrlID() == IDC_STATIC_LOGIN||pWnd->GetDlgCtrlID()==IDC_STATIC_LOGINING
		||pWnd->GetDlgCtrlID()==IDC_STATIC_LOGINUSER||pWnd->GetDlgCtrlID()==IDC_STATIC_PSWORD||pWnd->GetDlgCtrlID()==IDC_STATIC_USNAME
		||pWnd->GetDlgCtrlID()==IDC_STATIC_ONLINE||pWnd->GetDlgCtrlID()==IDC_STATIC_DEVICOUNT)
	{
		pDC->SetTextColor(RGB(255,255,255)); //��������Ϊ��ɫ

		pDC->SetBkMode(TRANSPARENT);         //���ñ���Ϊ͸��
		return   HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID()==IDC_STATIC_VERSION)
	{
		pDC->SetTextColor(RGB(0,0,255));
		pDC->SetBkMode(TRANSPARENT);         //���ñ���Ϊ͸��
		return   HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	if (pWnd == this)
	{
		return m_brBk;
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


BOOL CSingleDemonDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	switch(pMsg->wParam)
	{
	case VK_RETURN:
	case VK_ESCAPE:
		return TRUE; break;
	}

	if (pMsg->message==WM_MOUSEMOVE)
	{
		m_TlTips.RelayEvent(pMsg);
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

LRESULT CSingleDemonDlg::OnRecVPulishMSG(WPARAM wParam,LPARAM lParam)
{
	return TRUE;
}


void CSingleDemonDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*OnRecVPulishMSG(ncheck,num);
	if (bFlag==TRUE || bCliiick==TRUE)
	{
	KillTimer(1);
	}*/
	CDialogEx::OnTimer(nIDEvent);
}


void CSingleDemonDlg::OnClickedStaticVersion()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CVersionDlg dlg;
	dlg.DoModal();
}


void CSingleDemonDlg::OnBnClickedButtHistory()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bCliiick=TRUE;
	CHistoryDlg Hdlg;
	Hdlg.DoModal();
}
