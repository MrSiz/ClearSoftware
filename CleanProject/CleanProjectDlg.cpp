
// CleanProjectDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CleanProject.h"
#include "CleanProjectDlg.h"
#include "afxdialogex.h"
#include "DlgLogin.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCleanProjectDlg �Ի���




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


// CCleanProjectDlg ��Ϣ�������

BOOL CCleanProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CDlgLogin m_DlgLogin;
	m_DlgLogin.DoModal();

	CRect tabRect;
	m_tab.InsertItem(0,_T("�ļ�ɾ��"));
	m_tab.InsertItem(1,_T("�ļ��½�"));//��ǩ��
	m_tab.InsertItem(2,_T("����"));
	m_tabOne.Create(IDD_DLG_TAB,&m_tab);//������һ����ǩҳ
	m_tabTow.Create(IDD_DLG_HELP,&m_tab);//�����ڶ�����ǩҳ
	m_tabThree.Create(IDD_DLG_MANAGE,&m_tab);//������������ǩҳ
	m_tab.GetClientRect(&tabRect);//��ȡ��ǩ������
	
	//����tabRect��ֵ
	tabRect.left+=1;
	tabRect.right-=1;
	tabRect.top+=25;
	tabRect.bottom-=1;

	//���ݵ����õ�tabRect�����ñ�ǩҳ��
	
	m_tabOne.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_SHOWWINDOW);
	m_tabTow.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_HIDEWINDOW);
	m_tabThree.SetWindowPos(NULL,tabRect.left,tabRect.top,tabRect.Width(),tabRect.Height(),SWP_HIDEWINDOW);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCleanProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCleanProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCleanProjectDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DestroyWindow( ); 
	//CDialogEx::OnCancel();
	//CDialogEx::OnOK();
	//CDialogEx:;OnClose();
}


void CCleanProjectDlg::OnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CRect tabRect;
	m_tab.GetClientRect(&tabRect);//��ȡ��ǩ������
	
	//����tabRect��ֵ
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
