#pragma once
#include "afxcmn.h"


// CDlgTabOne 对话框

class CDlgTabOne : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTabOne)
	void findFile(CString nowFile);
	void findBigFile(CString nowFile);
	void findLitterFile(CString nowFile);
	void findSameNameFile(CString nowFile);
	void findLinshiFile(CString nowFile);
	int IsEquale(CString str1,CString str2);
public:
	CDlgTabOne(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTabOne();

// 对话框数据
	enum { IDD = IDD_DLG_TAB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	int InitListCtrlStyle(void);
	int RefreshListCtrlData(void);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSearch();
	CString m_file;
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedButtonChoose4();
	afx_msg void OnLvnItemchangedListResult(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonChoose2();
	afx_msg void OnBnClickedButton3();
	LONGLONG m_FileNum;
	afx_msg void OnEnChangeEditNum();
	afx_msg void OnStnClickedStaticDescription();
//	double m_FileSize;
	afx_msg void OnEnChangeEditFilesize();
	afx_msg void OnEnChangeEditSearch();
	afx_msg void OnStnClickedStaticDatefanwei();
	LONGLONG m_FileSize;
	CString m_FileType;
	afx_msg void OnEnChangeEditFiletype();
//	LONGLONG m_Date1;
//	LONGLONG m_Date2;
	afx_msg void OnEnChangeEditDate1();
	afx_msg void OnEnChangeEditDate2();
	CString m_FileDate;
	LONGLONG m_Size1;
	LONGLONG m_Size2;
	afx_msg void OnStnClickedStaticDanwei2();
	afx_msg void OnEnChangeEditsize1();
	afx_msg void OnBnClickedButtonFindbigfile();
	afx_msg void OnBnClickedButtonSaomiaolaji();
	afx_msg void OnStnClickedStaticFiletype();
	afx_msg void OnStnClickedStaticCondition();
	CString m_SameNameFile;
	afx_msg void OnEnChangeEditFindsamenamefile();
	afx_msg void OnBnClickedButtonFindsamenamefile();
	afx_msg void OnBnClickedButtonChoose();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButtonSaomiaolinshi();
	afx_msg void OnBnClickedButtonSaomiao();
};
