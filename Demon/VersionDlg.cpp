// VersionDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "VersionDlg.h"
#include "afxdialogex.h"


// CVersionDlg �Ի���

IMPLEMENT_DYNAMIC(CVersionDlg, CDialogEx)

CVersionDlg::CVersionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVersionDlg::IDD, pParent)
{

}

CVersionDlg::~CVersionDlg()
{
}

void CVersionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CONTRODUCE, m_edtVersion);
}


BEGIN_MESSAGE_MAP(CVersionDlg, CDialogEx)
	ON_STN_CLICKED(IDC_STATIC_CLOSE1, &CVersionDlg::OnClickedStaticClose1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CVersionDlg ��Ϣ�������


BOOL CVersionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CString strE=_T("(2016-4-15)������־\r\n\r\n\
1,��¼��������û�������ʶ��δ�Ǽ����޷���¼��Ҳ�޷�ʹ�ò�Ʒ���ܡ�\r\n\r\n\
2,��ҳ���״̬����\r\n\r\n\
	1����¼״̬����������״̬��\r\n\r\n\
	2����ҳÿһ����ť�Ĺ��ܽ��ܣ�����ƶ�����ťλ���������ʾ��\r\n\r\n\
	3��������Ҫ��ʾ������Ϣ��״̬��\r\n\r\n\
3,ʡ��������ѡ��ʡ���Զ����ֶ�Ӧ�У��������ֶ�ѡ��\r\n\r\n\
4,����/���ð�ť����״̬��ʵʱ�޸�����ѡ�����״̬��\r\n\r\n\
5,ѡ���豸��������һ����ת����Ϣ�б��ٵ����һ���ص�ѡ���豸���棬�ظ������������κ�ᱨ��   ����Ϣ�б��������ϢҲ��仯�����޸���\r\n\r\n\
6,������Ϣ��ѡ�������Ϣ���뵽��Ϣ�б�������Ϣ�����ģ�����ݳ��ȡ� \r\n\r\n\
7,������Ϣ��ɾ��ģ�����ֵľ��档\r\n\r\n\
8,������Ϣ�������ʾ�����Ա����أ�����ѡ�񷢲���\r\n\r\n\
9,������Ϣ��������������ر����д��ڣ��ص���ҳ���ڣ���������ײ�״̬����ʾ��ǰ������Ϣ��״̬��\r\n\r\n\
10,�汾��־���£������ҳ��汾�ż��ɲ鿴�汾������־��\r\n\r\n\
11,��ҳ��������ʷ������Ϣ��¼��ѯ��������ת����ʷ��¼ҳ�棬ͨ��ѡ�񷢲�ʱ���������ѯ�ѷ�����Ϣ��״̬��\r\n\r\n\
12,����ҳ���������д��ڱ�����΢������\r\n\r\n\
13,��ѯ�豸ҳ������Ϣ��ѯҳ��ı����ʵ�ֵ��ÿһ���ϾͿ���ѡ�񣬶����Ǳ����ֶ���ѡ��\r\n\r\n\
14,�ڲ�ѯ�豸ҳ���Ҽ�����Զ����豸��һ����ʵ���޸��豸������\r\n\r\n");
	CString strText;
	strText=_T("(2016-4-22)������־\r\n\r\n\
1,�ڲ�ѯ�豸ҳ���Ҽ�����Զ����豸��һ����ʵ���޸��豸������\r\n\r\n2,������ʷ��¼���ֲ��֡�\r\n\r\n\
3,�޸ķ��������Ƿ�ɹ���ʾ��ʽ����������ʾΪͼƬ��ʾ��\r\n\r\n\
4,���ӷ�����Ϣ״̬��������ʾ��ʽ��\r\n\r\n\
5,��ʷ��¼�������豸�����뷢������Ϣ������ʾ��\r\n\r\n");
	CString strText29;
	strText29=_T("(2016-4-29)������־\r\n\r\n\
1,�Ż���ʷ��¼ҳ����ɱ�ʶ��ͼƬ�ͽ�������ʾ��\r\n\r\n\
2,������ʷ��¼ҳ��ȫ������沼�֡�\r\n\r\n\
3,ѡ�񷢲��豸����ȫ���󲼾ֵ�����\r\n\r\n\
4,�޸���ѡ���豸��һЩbug������ѡ���κ�����ˢ���豸�б�ѡ��һ���豸���������󣩣�Ȼ��ѡ��ʡ�����������Ĵ���һЩ�豸ע����ٵ�ʡ�У��ٴβ�ѯ��ѡ���б���һ�У������һ���ᱨ��\r\n\r\n\
5,����������ɺ󣬻�ص������棬�������������˶�ʱ��ѯ��ǰ�����������״̬����ʵʱ������������״̬���ϡ�\r\n\r\n\
6,�������ڷ���������ʾ�����Ϣģ��Ĺ��ܣ�����ֻ������������Ϣ����ť������������Ϣģ�塣\r\n\r\n");

	CString strText24;
	strText24=_T("(2016-5-24)������־\r\n\r\n\
1,'�豸�б�'�������Ӹ߼��������ܣ�֧��ģ����ѯ�����������ɫ�߼�������ť��������Ӧѡ�����������и��༭��������������������ֻ�����������������е��ֶμ������������Ϣ��\r\n\r\n\
2,�Զ����豸����Ϊ˫���޸ģ��޸����޸��豸���ٷ�����Ϣ��ʧ�ܵ�bug���������޸����ƺ�ɻس���Ӧ�޸ģ�\r\n\r\n\
3,�б��չʾ�����������Ӿ�Ч�����ӣ�ͬʱ�����˹�ѡ��ʽ��������������ұ߿����ʾѡ�У�ͬʱ�������б������������У�\r\n\r\n\
4,�޸���ȫѡ֮����һ������ť�޷��ָ�����ʾ��bug���Ż��ˡ���һ������ť������仯�Ŀ��ӻ���\r\n\r\n\
5,���豸�б����������״̬�����Ա�����ʾ��������Ϣ״̬��\r\n\r\n\
6,������Ϣ������Ϻ󣬳��򽫲����˻ص������棬����Ϊ�˻ء��豸�б����棬��Ϣ״̬Ҳ����״̬����ʾ��\r\n\r\n\
7,����Ϣ�б������У�ͣ��ʱ���ݶ�Ĭ��Ϊ1��ͬʱ������ʾģʽ�������ƣ����ƣ��Ϲ����¹��Ը�Ϊ����ѡ����ʾģ�塯��ͬʱ���е�ģʽѡ����ʵ�ֶ�������ģʽ���ƣ�\r\n\r\n\
8,�޸���ѡ�������Ϣ��ɾ�����п���ͷβ����Ϣ�ٷ������ֻ���ֻ�����ʾ���������޷���ʾ��bug��\r\n\r\n\
9,�޸��˵�����Ϣ����8����һֱ��ʾ��bug��\r\n\r\n\
10,����ʷ��¼������Ҳ�����˱༭����֧��ģ����ѯ���ܣ�\r\n\r\n\
11���Ż��˼������н��棬ʹ֮����ȥ�����ʣ��ر��Ǳ���ڵ���ʾ���Լ����ƺͷ���ͳһ��\r\n\r\n");

	CString strText27=_T("(2016-5-27)������־\r\n\r\n\
1,�����漰������Ϣ���̽���ȫ������Tips��ʾ������ť�Ĺ�����ʾ������ƶ�����ť�����ɿ�����ʾ��\r\n\r\n\
2,�����˽�������ʾ����״̬��������Ϣ�����У�״̬�������Ŀǰִ�е�����ָʾ���ȣ�\r\n\r\n\
3,��ʷ��¼��������ɾ��ĳ����Ϣ���ܣ�ͬʱҲ������ȫѡ���ܣ��������ɾ����\r\n\r\n\r\n\r\n");
	m_edtVersion.SetWindowTextA(strText27+strText24+strText29+strText+strE);

	m_brush.CreateSolidBrush(RGB(210,255,255));

//////////////////////////////////////////////////////////////////////////
	GetDlgItem(IDC_STATIC_CLOSE1)->SetFocus();

	return FALSE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CVersionDlg::OnClickedStaticClose1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


HBRUSH CVersionDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd-> GetDlgCtrlID() == IDC_STATIC_VERS || pWnd-> GetDlgCtrlID() == IDC_STATIC_ED||pWnd-> GetDlgCtrlID() == IDC_STATIC_CLOSE1)
	{
		pDC->SetTextColor(RGB(255,0,0)); //��������Ϊxɫ
		pDC->SetBkMode(TRANSPARENT);         //���ñ���Ϊ͸��
		return   HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID()==IDC_EDIT_CONTRODUCE&&nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(255,255,255));
		return ::CreateSolidBrush(RGB(255,255,255));
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkMode(TRANSPARENT);  
	}

	return m_brush;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}



BOOL CVersionDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CDialogEx::PreTranslateMessage(pMsg);
}
