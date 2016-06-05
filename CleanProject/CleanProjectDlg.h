
// CleanProjectDlg.h : ͷ�ļ�
//

#pragma once
#include "DlgLogin.h"
#include "DlgTabOne.h"
#include "DlgTabTow.h"
#include "DlgTabThree.h"
// CCleanProjectDlg �Ի���
class CCleanProjectDlg : public CDialogEx
{
// ����
public:
	CCleanProjectDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLEANPROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	CTabCtrl m_tab;
    CDlgTabOne  m_tabOne;
	CDlgTabTow  m_tabTow;
	CDlgTabThree m_tabThree;
	afx_msg void OnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
};
