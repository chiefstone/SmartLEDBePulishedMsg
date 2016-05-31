#pragma once
#include "HeaderCtrlCl.h"
#include <vector>
using namespace std;
// CListCtrlCl

//List��������
typedef enum 
{
	KEY_RETURN = 0,
	KEY_UP = 1,
	KEY_DWON = 2
}KEY_TYPE;

#define MLSM_ITEMCHANGED (WM_USER + 200)

class CListCtrlCl : public CListCtrl
{
	DECLARE_DYNAMIC(CListCtrlCl)

public:
	CHeaderCtrlCl m_Header;
	CListCtrlCl();
	virtual ~CListCtrlCl();

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
public:
	// �и�
	int m_nRowHeight;
	CFont m_font;
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading,
		int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1);
	BOOL DeleteAllItems(void);
public:
	// Gradient - ����ϵ�������屳����,���ý�����Ϊ0
	void SetHeaderBKColor(int R, int G, int B, int Gradient);
public:
	// ���ñ�ͷ�߶�
	void SetHeaderHeight(float Height);
	CPtrList m_ptrListCol;  //��������ɫ
	CPtrList m_ptrListItem; //����Item��ɫ��
	CPtrList m_colTextColor; //������������ɫ
	CPtrList m_ItemTextColor; //���浥Ԫ��������ɫ
	bool FindColColor(int col ,COLORREF &color); //��������ɫ
	bool FindItemColor(int col,int row,COLORREF &color);
	bool FindColTextColor(int col,COLORREF &color); //������������ɫ
	bool FindItemTextColor(int col,int row,COLORREF &color);
	void SetColColor(int col,COLORREF color);  //��������ɫ
	void SetItemColor(int col,int row,COLORREF color); //����Item��ɫ
	void SetColTextColor(int col,COLORREF color);   //�������ı���ɫ
	void SetItemTextColor(int col,int row,COLORREF color);
	void SetRowHeigt(int nHeight); //�����и�
	void SetHeaderFontHW(int nHeight,int nWith); //���ñ�ͷ�����С
	void SetHeaderTextColor(COLORREF color);
	COLORREF m_color;
	BOOL SetTextColor(COLORREF cr);
	void SetFontHW(int nHeight,int nWith);  //��������ĸߺͿ�
	void SetEditColumn(int iColumn);
public:
	// ����߶�
	int m_fontHeight;
public:
	// ������
	int m_fontWith;
    BOOL m_BChanged;
protected:
	CEdit m_EditItem;
	BOOL m_bEditing;
	int m_Row;
	int m_Col;
	vector<int> m_vcEditColumn;
	int m_SortCol;
	bool m_Ascending;
private:
	BOOL IsEditColumn(int iColumn);
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLvnColumnclick(NMHDR *pNMHDR, LRESULT *pResult);
	LRESULT InsertGroupHeader(int nIndex, int nGroupID, const CString& strHeader, DWORD dwState = LVGS_NORMAL, DWORD dwAlign = LVGA_HEADER_LEFT);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

private:
	CString GetGroupHeader(int nGroupID);
	int GetRowGroupId(int nRow);
	BOOL SetRowGroupId(int nRow, int nGroupID);
	int GroupHitTest(const CPoint& point);

	BOOL GroupByColumn(int nCol);
	void DeleteEntireGroup(int nGroupId);
	BOOL HasGroupState(int nGroupID, DWORD dwState);
	BOOL SetGroupState(int nGroupID, DWORD dwState);
	BOOL IsGroupStateEnabled();
	BOOL SetGroupFooter(int nGroupID, const CString& footer, DWORD dwAlign = LVGA_FOOTER_CENTER);
	BOOL SetGroupTask(int nGroupID, const CString& task);
	BOOL SetGroupSubtitle(int nGroupID, const CString& subtitle);
	void CheckEntireGroup(int nGroupId, bool bChecked);
public:
	//
	BOOL CheckTime(CString time);
    void SetChanged(BOOL bIsChanged);
	bool SortColumn(int columnIndex, bool ascending);
	void ListEditItem(int nRow, int nCol);
};


