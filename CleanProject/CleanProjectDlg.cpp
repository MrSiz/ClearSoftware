
// CleanProjectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CleanProject.h"
#include "CleanProjectDlg.h"
#include "afxdialogex.h"
#include "DlgLogin.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCleanProjectDlg 对话框




CCleanProjectDlg::CCleanProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCleanProjectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCleanProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_tab);
}

BEGIN_MESSAGE_MAP(CCleanProjectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CCleanProjectDlg::OnBnClickedCancel)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CCleanProjectDlg::OnSelchangeTabMain)
END_MESSAGE_MAP()


// CCleanProjectDlg 消息处理程序

BOOL CCleanProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CDlgLogin m_DlgLogin;
	m_DlgLogin.DoModal();

	CRect tabRect;
	m_tab.InsertItem(0,_T("文件删除"));
	m_tab.InsertItem(1,_T("文件新建"));//标签名
	m_tab.InsertItem(2,_T("帮助"));
	m_tabOne.Create(IDD_DLG_TAB,&m_tab);//创建第一个标签页
	m_tabTow.Create(IDD_DLG_HELP,&m_tab);//创建第二个标签页
	m_tabThree.Create(IDD_DLG_MANAGE,&m_tab);//创建第三个标签页
	m_tab.GetClientRect(&tabRect);//获取标签的属性
	
	//调整tabRect的值
	tabRect.left+=1;
	tabRect.right-=1;
	tabRect.top+=25;
	tabRect.bottom-=1;

	//根据调整好的tabRect，放置标签页面
	
	m_tabOne.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_SHOWWINDOW);
	m_tabTow.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_HIDEWINDOW);
	m_tabThree.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_HIDEWINDOW);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCleanProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCleanProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCleanProjectDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	DestroyWindow( ); 
	//CDialogEx::OnCancel();
	//CDialogEx::OnOK();
	//CDialogEx:;OnClose();
}


void CCleanProjectDlg::OnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	CRect tabRect;
	m_tab.GetClientRect(&tabRect);//获取标签的属性
	
	//调整tabRect的值
	tabRect.left+=1;
	tabRect.right-=1;
	tabRect.top+=25;
	tabRect.bottom-=1;

	int n = m_tab.GetCurSel();
	switch(n)
	{
	case 0:
		{
			m_tabOne.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_SHOWWINDOW);
	        m_tabTow.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_HIDEWINDOW);
			m_tabThree.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_HIDEWINDOW);
			break;
		}
	case 1:
		{
			m_tabOne.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_HIDEWINDOW);
	        m_tabTow.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_HIDEWINDOW);
			m_tabThree.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_SHOWWINDOW);
			break;
		}
	case 2:
		{
			m_tabThree.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_HIDEWINDOW);
			m_tabOne.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_HIDEWINDOW);
	        m_tabTow.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_SHOWWINDOW);
			break;
		}
	default:
		break;
	}

}
