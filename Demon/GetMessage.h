#pragma once

#include "AffirmManage.h"

// CGetMessage

class CGetMessage : public CWinThread
{
	DECLARE_DYNCREATE(CGetMessage)

protected:
	CGetMessage();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CGetMessage();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()

protected:
	CAffirmManage m_dlg;
};


