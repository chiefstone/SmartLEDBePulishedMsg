
// SingleDemon.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "ADOInterface.h"
#include "Config.h"

// CSingleDemonApp:
// �йش����ʵ�֣������ SingleDemon.cpp
//

class CSingleDemonApp : public CWinApp
{
public:
	CSingleDemonApp();

// ��д
public:
	virtual BOOL InitInstance();
	
	BOOL OpenDataBase(DATABASEINFO databaseinfo);


// ʵ��

	ADOInterface m_ado;
	CConfig m_config;


	//ѡ�еķ�����ģ���
	CString strMSGNum1;
	CString strMSGNum2;
	CString strMSGNum3;
	CString strMSGNum4;
	CString strMSGNum5;
	CString strMSGNum6;
	CString strMSGNum7;
	CString strMSGNum8;
	//ѡ�еķ�����ģ����
	CString strMSGContent1;
	CString strMSGContent2;
	CString strMSGContent3;
	CString strMSGContent4;
	CString strMSGContent5;
	CString strMSGContent6;
	CString strMSGContent7;
	CString strMSGContent8;
	
	//��ǰ��½�û���:
	CString strUserName;


	DECLARE_MESSAGE_MAP()
};

extern CSingleDemonApp theApp;