#pragma once


// CDlgTabTow 对话框

class CDlgTabTow : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTabTow)

public:
	CDlgTabTow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTabTow();

// 对话框数据
	enum { IDD = IDD_DLG_HELP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticOne();
	afx_msg void OnStnClickedStaticHelp();
	afx_msg void OnStnClickedStaticLast();
	afx_msg void OnStnClickedStaticBuc();
};
