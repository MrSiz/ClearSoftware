// DlgLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "CleanProject.h"
#include "DlgLogin.h"
#include "afxdialogex.h"
#include "MD5.h"
#include <string>
// CDlgLogin 对话框

IMPLEMENT_DYNAMIC(CDlgLogin, CDialogEx)

CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgLogin::IDD, pParent)
	, m_Zhanghao(_T(""))
{

	//  m_csMD5 = _T("");
	//  m_csMD5 = 0;
	//  m_csMD5 = 0;
	m_csMD5 = _T("");
}

CDlgLogin::~CDlgLogin()
{
}

void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_PASSWORD, m_csMD5);
	//  DDV_MaxChars(pDX, m_csMD5, 32);
	DDX_Text(pDX, IDC_EDIT_USER, m_Zhanghao);
	DDV_MaxChars(pDX, m_Zhanghao, 9999999);
	//  DDX_Text(pDX, IDC_EDIT_PASSWORD, m_csMD5);
	//  DDX_Text(pDX, IDC_EDIT_PASSWORD, m_csMD5);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_csMD5);
	DDV_MaxChars(pDX, m_csMD5, 999999);
}
BEGIN_MESSAGE_MAP(CDlgLogin, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CDlgLogin::OnBnClickedCancel)
	ON_STN_CLICKED(IDC_STATIC_THEME, &CDlgLogin::OnStnClickedStaticTheme)
	ON_BN_CLICKED(IDOK, &CDlgLogin::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_USER, &CDlgLogin::OnEnChangeEditUser)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CDlgLogin::OnEnChangeEditPassword)
END_MESSAGE_MAP()


// CDlgLogin 消息处理程序


void CDlgLogin::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
	CDialogEx::OnCancel();
}


void CDlgLogin::OnStnClickedStaticTheme()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgLogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//char *md5File = MD5_file("D:\\备份\\CleanProject13 - 副本\\tmp.txt",32);
	//m_csMD5=md5File;
	//UpdateData(FALSE);
	unsigned char outPassword[99];
	unsigned int  tmp[99];
	for(int i=0;i<m_csMD5.GetLength();++i)
	{
		tmp[i]=m_csMD5[i]-'0';
	}
	//MD5Encode(outPassword,m_csMD5,m_csMD5.GetLength());
	MD5Encode(outPassword,tmp,32);
	if(m_Zhanghao.IsEmpty()||m_csMD5.IsEmpty())
	{
		MessageBox(_T("账号或密码不能为空"),_T(""),MB_OK);
		return ;
	}
	CString res=m_Zhanghao+m_csMD5;
	CStdioFile file;
	CString readFile;
	file.Open(_T("..\\CleanProject\\res\\tmp.txt"),CFile::modeRead);
	int flag=0;
	while(file.ReadString(readFile))
	{
		if(readFile==res)
		{
			flag=1;
			//file.Close();
			//MessageBox(_T("登陆成功"),_T("系统提示"),MB_OK);
			//CDialogEx::OnOK();
			//MessageBox(_T(""),_T(""),NULL);
		}
	}
	file.Close();
	if(flag==1)
	{
		MessageBox(_T("登陆成功"),_T("系统提示"),MB_OK);
	    CDialogEx::OnOK();
	}
	else
	  MessageBox(_T("账号或密码错误"),_T(""),MB_OK);
	
}


void CDlgLogin::OnEnChangeEditUser()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CDlgLogin::OnEnChangeEditPassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}
