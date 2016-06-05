#pragma once


// CDlgLogin 对话框

class CDlgLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgLogin)

public:
	CDlgLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgLogin();

// 对话框数据
	enum { IDD = IDD_DLG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnStnClickedStaticTheme();
	afx_msg void OnBnClickedOk();
//	CString m_csMD5;
	CString m_Zhanghao;
	afx_msg void OnEnChangeEditUser();
	afx_msg void OnEnChangeEditPassword();
//	int m_csMD5;
//	UINT m_csMD5;
	CString m_csMD5;
};
