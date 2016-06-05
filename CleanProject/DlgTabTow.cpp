// DlgTabTow.cpp : 实现文件
//

#include "stdafx.h"
#include "CleanProject.h"
#include "DlgTabTow.h"
#include "afxdialogex.h"


// CDlgTabTow 对话框

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


// CDlgTabTow 消息处理程序


void CDlgTabTow::OnStnClickedStaticOne()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgTabTow::OnStnClickedStaticHelp()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgTabTow::OnStnClickedStaticLast()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgTabTow::OnStnClickedStaticBuc()
{
	// TODO: 在此添加控件通知处理程序代码
}
