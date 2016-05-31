//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_)
#define AFX_ADOINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef _DBOPERATE
#define ADODB_CLS __declspec(dllexport)
#else
#define ADODB_CLS __declspec(dllimport)
#endif

#include "DBBaseInterface.h"
//**********************************************************************************
class ADODB_CLS ADOInterface : public DBBaseInterface
{
public:
	ADOInterface();
	virtual ~ADOInterface();

public:
	BOOL SetDatabase(_ConnectionPtr pConn);//jia080325�����ⲿ���ݿ�ָ�룬����Ҫ�ڲ�����������
//�������ַ���ΪsConnect�����ݿ�
	BOOL OpenConnect(const CString &sConnect);
//��ODBC����Դ,sDataSource, �û���sUserId, ����sPassword
	BOOL OpenODBC(const CString & sDataSource, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const BOOL bSQLRSet = 0);
//��ACCESS���ݿ�,�ļ�����·��sFilename, �û���sUserId, ����sPassword.ACCESS�汾����iVersionFlag
	BOOL OpenAccess(const CString & sFilename, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const int iVersionFlag = 0);
//��SQL Server���ݿ�,����������sServer, ���ݿ�����sDatabaseName, �û���sUserId, ����sPassword
	//jia081118���ӶԾ���������֧��
	BOOL OpenSQLServer(const CString & sServer, const CString & sDatabaseName, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const CString& sMirror=_T(""));
//��Oracle���ݿ�,���ݿ�ʵ��sDSN, �û���sUserId, ����sPassword
	BOOL OpenOracle(const CString & sDSN, const CString & sUserId = _T(""), const CString & sPassword = _T(""));
//���´����ݿ�
	BOOL ReOpen(void);

//�ر����ݿ�
	BOOL CloseDatabase(void);
//�رռ�¼��
	BOOL CloseRecord(void);
//������DBBaseInterface����dbbaseinterface����һ������
	BOOL CopyDatabase(const DBBaseInterface * pDBBaseInterface);

//ִ�в�ѯ���Ϊsql�Ĳ�ѯ����,ָ����ѯ����flag
	BOOL ExecuteSelect(const CString & sql, const long flag = 0);
//ִ��insert, update, delete��sql�Ĳ���,ָ��ִ������flag
	BOOL ExecuteSql(const CString & sql, const long flag = 0);
//ִ��insert, update, delete��sql�Ĳ���,ָ��ִ������flag. arraySql����sql��������
	BOOL ExecuteSql(const CStringArray & arraySql, const long flag = 0);

//ִ�д洢���� add by qinwl 2014-3-1 ֻ֧���������Ͳ��� int,char
	BOOL ExecuteStoreProc(CString sql,CString& err);

//��ȡ�ַ��ֶ�sField��ֵ������sVal��,��bEmpty�����Ƿ�Ĭ��Ϊ��
	BOOL GetString(const CString & sField, CString &sVal, BOOL bEmpty = TRUE);
//��ȡ���������ֶ�sField��ֵ,����sVal��,VT_NULL,VT_EMPTY���ؿ��ִ� add by qinwl 2012-6-11
	BOOL GetStringEx(const CString & sField, CString &sVal);
//��ȡ�ֶ����� add by qinwl 2014-2-25
	BOOL GetFieldNames(CStringArray& ar);
//��ȡ�����ֶ�sField��ֵ������nVal��,��bReset�����Ƿ�Ĭ��Ϊ0
	BOOL GetInt(const CString & sField, int &nVal, BOOL bReset = TRUE);
//��ȡʱ���ֶ�sField��ֵ������Val��,��bDefault�����Ƿ�Ĭ��Ϊ��ǰʱ��
	BOOL GetDateTime(const CString & sField, COleDateTime & Val, BOOL bDefault = TRUE);
//��ȡ�����ֶ�sField��ֵ������dVal��,��bReset�����Ƿ�Ĭ��Ϊ0
	BOOL GetFloat(const CString & sField, double & dVal, BOOL bReset = TRUE);
//��ȡ�����ֶ�sField��ֵ������Val��,��bReset�����Ƿ�Ĭ��Ϊ0
	BOOL GetCurrency(const CString & sField, COleCurrency & Val, BOOL bReset = TRUE);
//��ȡBOOL�ֶ�sField��ֵ������bVal��,��bReset�����Ƿ�Ĭ��Ϊ��
	BOOL GetBOOL(const CString & sField, BOOL & bVal, BOOL bReset = TRUE);

//�鿴�Ƿ��˼�¼��β��
	BOOL IsEOF(void);
//����¼�������ƶ�һ����¼
	BOOL MoveNext(void);
//��ȡ����ָ��
	_ConnectionPtr GetConnect(void){return m_pConnection;};
//��ȡ��¼ָ��
	_RecordsetPtr GetRecordSet(void){return m_pSet;};
//��ȡ���ݿ������ַ���
	CString GetConnectString(void){return m_sConnect;};
//�������ݿ��Ƿ��Ѿ�����
	BOOL isDbOpen();
private:
	_ConnectionPtr m_pConnection;			//ADOָ��
	_ConnectionPtr m_pLocalConnection;		//���ֱ����Լ��򿪵����ݿ�ָ�룬���ڱȽϺ͹ر��ж�//jia081118
	_RecordsetPtr  m_pSet;					//ADO��¼��ָ��	
	BOOL m_bADOOpenByMySelf;				//�Ƿ����ݿ��ɱ����
	CString		   m_sConnect;				//���ݿ������ַ���
};

#endif // !defined(AFX_ADOINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_)
