#pragma once


// CDlgTabThree 对话框

class CDlgTabThree : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTabThree)

public:
	CDlgTabThree(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTabThree();
	void Rename(CString Path,CString FileName);

// 对话框数据
	enum { IDD = IDD_DLG_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedButtonFindmode();
//	CString m_FilePath;
	afx_msg void OnEnChangeEditModefile();
//	CString m_FilePath;
//	CString m_ModeFileName;
	afx_msg void OnBnClickedButtonPosition();
	afx_msg void OnBnClickedButtonCreate();
	afx_msg void OnBnClickedButtonKeepposition();
	afx_msg void OnBnClickedButtonCreatefolder();
	CString m_ModeFileName;
	afx_msg void OnEnChangeEditKeepposition();
	CString m_KeepPosition;
	int m_FileNum;
	afx_msg void OnEnChangeEditNum();
	CString m_FolderPosition;
	CString m_folderName;
	afx_msg void OnEnChangeEditFoldername();
	int m_folderNum;
	afx_msg void OnEnChangeEditFoldernum();
	CString m_luJing;
	CString m_name;
	afx_msg void OnBnClickedButtonXuanzewenjian();
	afx_msg void OnBnClickedButtonXuanzewenjianjia();
	afx_msg void OnEnChangeEditLujing();
	afx_msg void OnBnClickedButtonSure();
	afx_msg void OnEnChangeEditName();
};
