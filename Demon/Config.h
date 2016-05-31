#pragma once

typedef struct _TagDataBaseInfo
{
	CString sDBServer;//���ݿ������
	CString sDBName; //���ݿ����ƣ�������ݿ������Ϊ�գ������ΪODBC����Դ
	CString sFailover_Partner;//�������ݿ�ʵ��
	CString sDBUser; //���ݿ��û���
	CString sDBPsw; //���ݿ�����
	int     m_nDBType;//���ݿ����� 0=SqlServer 1=Access 2=Oracle
} DATABASEINFO;


class CConfig
{
public:
	CConfig(void);
	~CConfig(void);

	BOOL ReadIni();

public:
	CString m_strAppPath;
	CString m_strHospitalName;
	int m_nDefaultMerge;		// 0:���ϲ� 1���Զ��ϲ�  2���ֶ��ϲ�
	DATABASEINFO m_databaseinfo;
};

