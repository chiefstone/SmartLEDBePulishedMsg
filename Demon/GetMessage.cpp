// GetMessage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "GetMessage.h"


// CGetMessage

IMPLEMENT_DYNCREATE(CGetMessage, CWinThread)

CGetMessage::CGetMessage()
{
	
}

CGetMessage::~CGetMessage()
{
}

BOOL CGetMessage::InitInstance()
{
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	m_dlg.Create(IDD_AFFIRMMANAGE_DIALOG);
	m_dlg.ShowWindow(SW_HIDE);
	m_pMainWnd=&m_dlg;
	return TRUE;
}

int CGetMessage::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	m_dlg.DestroyWindow();

	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CGetMessage, CWinThread)
END_MESSAGE_MAP()


// CGetMessage ��Ϣ�������
