#pragma once


// CDlgTabTow �Ի���

class CDlgTabTow : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTabTow)

public:
	CDlgTabTow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTabTow();

// �Ի�������
	enum { IDD = IDD_DLG_HELP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticOne();
	afx_msg void OnStnClickedStaticHelp();
	afx_msg void OnStnClickedStaticLast();
	afx_msg void OnStnClickedStaticBuc();
};
