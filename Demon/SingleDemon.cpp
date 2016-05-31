
// SingleDemon.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "SingleDemonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleDemonApp

BEGIN_MESSAGE_MAP(CSingleDemonApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CSingleDemonApp ����

CSingleDemonApp::CSingleDemonApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CSingleDemonApp ����

CSingleDemonApp theApp;


// CSingleDemonApp ��ʼ��

BOOL CSingleDemonApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	//theApp.bPresss=FALSE;

	if (!m_config.ReadIni())
	{
		return(FALSE);
	}

	if (!OpenDataBase(m_config.m_databaseinfo))
	{
		return(FALSE);
	}


	CSingleDemonDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

BOOL CSingleDemonApp::OpenDataBase(DATABASEINFO databaseinfo)
{
	if (!databaseinfo.sDBServer.IsEmpty())
	{
		if (databaseinfo.m_nDBType==0)
		{
			try
			{
				BOOL bConnect =FALSE;
				bConnect =m_ado.OpenSQLServer(databaseinfo.sDBServer,databaseinfo.sDBName,
					databaseinfo.sDBUser,databaseinfo.sDBPsw,databaseinfo.sFailover_Partner);

				if(bConnect ==FALSE)
					return FALSE;
			}
			catch(...)
			{
				AfxMessageBox("MS_SQLServer���ݿ��޷���",MB_OK| MB_ICONEXCLAMATION);
			}
		}
	}
	return TRUE;
}