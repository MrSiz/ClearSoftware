// DlgTabTow.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CleanProject.h"
#include "DlgTabTow.h"
#include "afxdialogex.h"


// CDlgTabTow �Ի���

IMPLEMENT_DYNAMIC(CDlgTabTow, CDialogEx)

CDlgTabTow::CDlgTabTow(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTabTow::IDD, pParent)
{

}

CDlgTabTow::~CDlgTabTow()
{
}

void CDlgTabTow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTabTow, CDialogEx)
	ON_STN_CLICKED(IDC_STATIC_ONE, &CDlgTabTow::OnStnClickedStaticOne)
	ON_STN_CLICKED(IDC_STATIC_HELP, &CDlgTabTow::OnStnClickedStaticHelp)
	ON_STN_CLICKED(IDC_STATIC_LAST, &CDlgTabTow::OnStnClickedStaticLast)
	ON_STN_CLICKED(IDC_STATIC_BUC, &CDlgTabTow::OnStnClickedStaticBuc)
END_MESSAGE_MAP()


// CDlgTabTow ��Ϣ�������


void CDlgTabTow::OnStnClickedStaticOne()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgTabTow::OnStnClickedStaticHelp()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgTabTow::OnStnClickedStaticLast()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgTabTow::OnStnClickedStaticBuc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
