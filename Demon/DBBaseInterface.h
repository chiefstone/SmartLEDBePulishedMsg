//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBBASEINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_)
#define AFX_DBBASEINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef _DBOPERATE
#define DBBASEINTERFACE_CLS __declspec(dllexport)
#else
#define DBBASEINTERFACE_CLS __declspec(dllimport)
#endif

class CLogFileInterface;
//**********************************************************************************
class DBBASEINTERFACE_CLS DBBaseInterface  
{
public:
	DBBaseInterface();
	virtual ~DBBaseInterface();

public:
//�������ַ���ΪsConnect�����ݿ�
	virtual BOOL OpenConnect(const CString &sConnect) = 0;
//��ODBC����Դ,sDataSource, �û���sUserId, ����sPassword
	virtual BOOL OpenODBC(const CString & sDataSource, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const BOOL bSQLRSet = 0) = 0;
//��ACCESS���ݿ�,�ļ�����·��sFilename, �û���sUserId, ����sPassword.ACCESS�汾����iVersionFlag
	virtual BOOL OpenAccess(const CString & sFilename, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const int iVersionFlag = 0) = 0;
//��SQL Server���ݿ�,����������sServer, ���ݿ�����sDatabaseName, �û���sUserId, ����sPassword
	virtual BOOL OpenSQLServer(const CString & sServer, const CString & sDatabaseName, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const CString& sMirror= _T("")) = 0;
//��Oracle���ݿ�,ʵ������sDSN, �û���sUserId, ����sPassword
	virtual BOOL OpenOracle(const CString & sDSN, const CString & sUserId = _T(""), const CString & sPassword = _T("")) = 0;
//���´����ݿ�
	virtual BOOL ReOpen(void) = 0;
//�رռ�¼��
	virtual BOOL CloseRecord(void) = 0;
//�ر����ݿ�
	virtual BOOL CloseDatabase(void) = 0;
//������DBBaseInterface����dbbaseinterface����һ������
	virtual BOOL CopyDatabase(const DBBaseInterface * pDBBaseInterface) = 0;

//ִ�в�ѯ���Ϊsql�Ĳ�ѯ����,ָ����ѯ����flag
	virtual BOOL ExecuteSelect(const CString & sql, const long flag = 0) = 0;
//ִ��insert, update, delete��sql�Ĳ���,ָ��ִ������flag
	virtual BOOL ExecuteSql(const CString & sql, const long flag) = 0;
//ִ��insert, update, delete��sql�Ĳ���,ָ��ִ������flag. arraySql����sql��������
	virtual BOOL ExecuteSql(const CStringArray & arraySql, const long flag) = 0;

//��ȡ�ַ��ֶ�sField��ֵ������sVal��,��bEmpty�����Ƿ�Ĭ��Ϊ��
	virtual BOOL GetString(const CString & sField, CString &sVal, BOOL bEmpty = TRUE) = 0;
//��ȡ�����ֶ�sField��ֵ������nVal��,��bReset�����Ƿ�Ĭ��Ϊ0
	virtual BOOL GetInt(const CString & sField, int &nVal, BOOL bReset = TRUE) = 0;
//��ȡʱ���ֶ�sField��ֵ������Val��,��bDefault�����Ƿ�Ĭ��Ϊ��ǰʱ��
	virtual BOOL GetDateTime(const CString & sField, COleDateTime & Val, BOOL bDefault = TRUE) = 0;
//��ȡ�����ֶ�sField��ֵ������dVal��,��bReset�����Ƿ�Ĭ��Ϊ0
	virtual BOOL GetFloat(const CString & sField, double & dVal, BOOL bReset = TRUE) = 0;
//��ȡ�����ֶ�sField��ֵ������Val��,��bReset�����Ƿ�Ĭ��Ϊ0
	virtual BOOL GetCurrency(const CString & sField, COleCurrency & Val, BOOL bReset = TRUE) = 0;
//��ȡBOOL�ֶ�sField��ֵ������bVal��,��bReset�����Ƿ�Ĭ��Ϊ��
	virtual BOOL GetBOOL(const CString & sField, BOOL & bVal, BOOL bReset = TRUE) = 0;

//�鿴�Ƿ��˼�¼��β��
	virtual BOOL IsEOF(void) = 0;
//����¼�������ƶ�һ����¼
	virtual BOOL MoveNext(void) = 0;

//����ִ��sql������־��¼�ļ�
	void SetLogFile(const CString &sFilename);
//��ȡ��־�ļ���
	CString GetLogFile(void);
protected:
	CLogFileInterface*		m_pLogfileinterface;	//ִ��SQL������־�ļ��ӿ�
public:
	int						m_iClsID;				//���ID	
};

#endif // !defined(AFX_DBBASEINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_)
