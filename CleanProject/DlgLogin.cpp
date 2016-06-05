// DlgLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CleanProject.h"
#include "DlgLogin.h"
#include "afxdialogex.h"
#include "MD5.h"
#include <string>
// CDlgLogin �Ի���

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


// CDlgLogin ��Ϣ�������


void CDlgLogin::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
	CDialogEx::OnCancel();
}


void CDlgLogin::OnStnClickedStaticTheme()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgLogin::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//char *md5File = MD5_file("D:\\����\\CleanProject13 - ����\\tmp.txt",32);
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
		MessageBox(_T("�˺Ż����벻��Ϊ��"),_T(""),MB_OK);
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
			//MessageBox(_T("��½�ɹ�"),_T("ϵͳ��ʾ"),MB_OK);
			//CDialogEx::OnOK();
			//MessageBox(_T(""),_T(""),NULL);
		}
	}
	file.Close();
	if(flag==1)
	{
		MessageBox(_T("��½�ɹ�"),_T("ϵͳ��ʾ"),MB_OK);
	    CDialogEx::OnOK();
	}
	else
	  MessageBox(_T("�˺Ż��������"),_T(""),MB_OK);
	
}


void CDlgLogin::OnEnChangeEditUser()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CDlgLogin::OnEnChangeEditPassword()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}
