
// CleanProjectDlg.h : 头文件
//

#pragma once
#include "DlgLogin.h"
#include "DlgTabOne.h"
#include "DlgTabTow.h"
#include "DlgTabThree.h"
// CCleanProjectDlg 对话框
class CCleanProjectDlg : public CDialogEx
{
// 构造
public:
	CCleanProjectDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLEANPROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
