// DlgTabOne.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CleanProject.h"
#include "DlgTabOne.h"
#include "afxdialogex.h"
#include<iostream>
using namespace std;

// CDlgTabOne �Ի���

IMPLEMENT_DYNAMIC(CDlgTabOne, CDialogEx)

CDlgTabOne::CDlgTabOne(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTabOne::IDD, pParent)
	, m_FileNum(0)
	, m_FileSize(0)
	, m_FileType(_T(""))
	, m_FileDate(_T(""))
	, m_Size1(0)
	, m_Size2(0)
	, m_SameNameFile(_T(""))
{

	m_file = _T("");
}

CDlgTabOne::~CDlgTabOne()
{
}

void CDlgTabOne::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_RESULT, m_list);
	DDX_Text(pDX, IDC_EDIT_SEARCH, m_file);
	DDV_MaxChars(pDX, m_file, 10000);
	DDX_Text(pDX, IDC_EDIT_NUM, m_FileNum);
	//  DDX_Text(pDX, IDC_EDIT_FILESIZE, m_FileSize);
	//  DDV_MinMaxDouble(pDX, m_FileSize, 0.0, 999999999999.0);
	DDX_Text(pDX, IDC_EDIT_FILESIZE, m_FileSize);
	DDX_Text(pDX, IDC_EDIT_FILETYPE, m_FileType);
	//  DDX_Text(pDX, IDC_EDIT_DATE1, m_Date1);
	//  DDX_Text(pDX, IDC_EDIT_DATE2, m_Date2);
	DDX_Text(pDX, IDC_EDITSIZE1, m_FileDate);
	DDX_Text(pDX, IDC_EDIT_DATE1, m_Size1);
	DDX_Text(pDX, IDC_EDIT_DATE2, m_Size2);
	//DDX_Text(pDX, IDC_EDIT_SAMENAMEFILE, m_SameNameFile);
	//DDV_MaxChars(pDX, m_SameNameFile, 99999999);
	DDX_Text(pDX, IDC_EDIT_FINDSAMENAMEFILE, m_SameNameFile);
	DDV_MaxChars(pDX, m_SameNameFile, 99999);
}


BEGIN_MESSAGE_MAP(CDlgTabOne, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CDlgTabOne::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_READ, &CDlgTabOne::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_CHOOSE4, &CDlgTabOne::OnBnClickedButtonChoose4)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_RESULT, &CDlgTabOne::OnLvnItemchangedListResult)
	ON_BN_CLICKED(IDC_BUTTON_CHOOSE2, &CDlgTabOne::OnBnClickedButtonChoose2)
	//ON_BN_CLICKED(IDC_BUTTON3, &CDlgTabOne::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT_NUM, &CDlgTabOne::OnEnChangeEditNum)
	ON_STN_CLICKED(IDC_STATIC_DESCRIPTION, &CDlgTabOne::OnStnClickedStaticDescription)
	ON_EN_CHANGE(IDC_EDIT_FILESIZE, &CDlgTabOne::OnEnChangeEditFilesize)
	ON_EN_CHANGE(IDC_EDIT_SEARCH, &CDlgTabOne::OnEnChangeEditSearch)
	ON_STN_CLICKED(IDC_STATIC_DATEFANWEI, &CDlgTabOne::OnStnClickedStaticDatefanwei)
	ON_EN_CHANGE(IDC_EDIT_FILETYPE, &CDlgTabOne::OnEnChangeEditFiletype)
	ON_EN_CHANGE(IDC_EDIT_DATE1, &CDlgTabOne::OnEnChangeEditDate1)
	ON_EN_CHANGE(IDC_EDIT_DATE2, &CDlgTabOne::OnEnChangeEditDate2)
	ON_STN_CLICKED(IDC_STATIC_DANWEI2, &CDlgTabOne::OnStnClickedStaticDanwei2)
	ON_EN_CHANGE(IDC_EDITSIZE1, &CDlgTabOne::OnEnChangeEditsize1)
	ON_BN_CLICKED(IDC_BUTTON_FINDBIGFILE, &CDlgTabOne::OnBnClickedButtonFindbigfile)
	ON_BN_CLICKED(IDC_BUTTON_SAOMIAOLAJI, &CDlgTabOne::OnBnClickedButtonSaomiaolaji)
	ON_STN_CLICKED(IDC_STATIC_FILETYPE, &CDlgTabOne::OnStnClickedStaticFiletype)
	ON_STN_CLICKED(IDC_STATIC_CONDITION, &CDlgTabOne::OnStnClickedStaticCondition)
	ON_EN_CHANGE(IDC_EDIT_FINDSAMENAMEFILE, &CDlgTabOne::OnEnChangeEditFindsamenamefile)
	ON_BN_CLICKED(IDC_BUTTON_FINDSAMENAMEFILE, &CDlgTabOne::OnBnClickedButtonFindsamenamefile)
	ON_BN_CLICKED(IDC_BUTTON_CHOOSE, &CDlgTabOne::OnBnClickedButtonChoose)
	//ON_BN_CLICKED(IDC_BUTTON5, &CDlgTabOne::OnBnClickedButton5)
	//ON_BN_CLICKED(IDC_BUTTON_SAOMIAOLINSHI, &CDlgTabOne::OnBnClickedButtonSaomiaolinshi)
	ON_BN_CLICKED(IDC_BUTTON_SAOMIAO, &CDlgTabOne::OnBnClickedButtonSaomiao)
END_MESSAGE_MAP()


// CDlgTabOne ��Ϣ�������


int CDlgTabOne::InitListCtrlStyle(void)
{
	CRect rect;
	m_list.GetClientRect(&rect);
	int nColInterval =rect.Width();
	//����ListCtrl����ʽ
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//�������������������еĶ����ʽ���п�
	m_list.InsertColumn(0, _T("�ļ���"), LVCFMT_RIGHT, int (nColInterval * 0.3));
	m_list.InsertColumn(1, _T("�ļ�·��"), LVCFMT_LEFT, int (nColInterval * 0.3));
	m_list.InsertColumn(2, _T("�޸�����"), LVCFMT_LEFT, int (nColInterval * 0.2));
	m_list.InsertColumn(3, _T("�ļ���С"), LVCFMT_LEFT, int (nColInterval * 0.2));
	return 0;
}

//ˢ��list������
int CDlgTabOne::RefreshListCtrlData(void)
{
	return 0;
}


BOOL CDlgTabOne::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
    InitListCtrlStyle();
	RefreshListCtrlData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}




void CDlgTabOne::OnBnClickedButtonRead()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString ReturnPach;								//�ַ�������
	TCHAR szPath[_MAX_PATH];                       	//����·������
	BROWSEINFO bi;                                  	// BROWSEINFO�ṹ����
	bi.hwndOwner = NULL;                          	//HWND���
	bi.pidlRoot = NULL;                          	//Ĭ��ֵΪNULL
	bi.lpszTitle = _T("��ѡ��һ���ļ���");          	//�Ի������
	bi.pszDisplayName = szPath;                         //ѡ���ļ���·��
	bi.ulFlags = BIF_RETURNONLYFSDIRS;       //���
	bi.lpfn = NULL;                          	//Ĭ��ֵΪNULL
	bi.lParam = NULL;                          	//�ص���Ϣ
	LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);  	//��ʾ�ļ�����Ի���
	if (pItemIDList)
	{
		if (SHGetPathFromIDList(pItemIDList, szPath)) 		//�ж��Ƿ����ļ���·��
			ReturnPach = szPath;					//����ļ���·��
	}
	else
	{
		ReturnPach = ""; 							//�ļ���·��Ϊ��
	}
	UpdateData(false);
	m_file = ReturnPach;			//�ļ���·��
	
	SetDlgItemText(IDC_EDIT_SEARCH, m_file);
}
void  CDlgTabOne::findFile(CString nowFile)
{
	 FILETIME filetime;
	 FILETIME localtime;
	 SYSTEMTIME systemtime;
	 CFileFind finder;
	 if (nowFile.Right(1)!=_T("\\"))  
          nowFile+=  _T("\\*.*");
	 else 
		 nowFile+=_T("*.*");
     if(m_Size1>m_Size2)
	 {
		 MessageBox(_T("��С��Χ����ȷ�����������룡"),_T(""),MB_OK);
		 return;
	 }
     BOOL bWorking = finder.FindFile(nowFile);  
     while(bWorking)  
     {  
       bWorking = finder.FindNextFile();  
       //����ҵ������ļ��У��ݹ��ȥ  
       if (finder.IsDirectory()&&!finder.IsDots())  
       {  
         findFile(finder.GetFilePath());  
       }  	
	   if(!finder.IsDirectory()&&!finder.IsDots())
	   {
		   CString tmpFileName=finder.GetFileName();
		   int pos=tmpFileName.ReverseFind('.');
		   int lenth=tmpFileName.GetLength();
		   CString NowFileType=tmpFileName.Right(lenth-pos-1);
		   LONGLONG FileSize=finder.GetLength()/1024;
		   finder.GetLastWriteTime(&filetime);
		   FileTimeToLocalFileTime(&filetime,&localtime);
		   FileTimeToSystemTime(&localtime,&systemtime);
		   CString TmpFileTime=_T("");
		   TmpFileTime.Format(_T("%04d/%02d/%02d"),systemtime.wYear,systemtime.wMonth,systemtime.wDay);
		   if(m_FileType!=""||m_Size1!=0||m_FileDate!="")
		   {
		     if(m_FileType==NowFileType&&m_Size1==0&&m_Size2==0&&m_FileDate=="")
		      {
                //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
		         }
			 else if(m_FileType==""&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate=="")
			 {
				 m_list.InsertItem(0,finder.GetFileName());
	             m_list.SetItemText(0,1,finder.GetFilePath());
		         CTime ftime;
		         finder.GetLastWriteTime(ftime);
		         double fileSize=(double)finder.GetLength()/1024;
		         CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		         m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==""&&m_Size1==0&&m_Size2==0&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==NowFileType&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate=="")
			 {
				 m_list.InsertItem(0,finder.GetFileName());
	             m_list.SetItemText(0,1,finder.GetFilePath());
		         CTime ftime;
		         finder.GetLastWriteTime(ftime);
		         double fileSize=(double)finder.GetLength()/1024;
		         CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			  else if(m_FileType==NowFileType&&m_Size1==0&&m_Size2==0&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==""&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			   else if(m_FileType==NowFileType&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
		   }
		   if(m_FileType==""&&m_Size1==0&&m_FileDate=="")
		   {  
			   m_list.InsertItem(0,finder.GetFileName());
	           m_list.SetItemText(0,1,finder.GetFilePath());
		      CTime ftime;
		      finder.GetLastWriteTime(ftime);
		      double fileSize=(double)finder.GetLength()/1024;
		      CString FileFormat;
	          FileFormat.Format(_T("%.0fKB"),fileSize);
		      m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		      m_list.SetItemText(0,3,FileFormat);
		      m_FileNum++;
		      m_FileSize+=(LONGLONG)fileSize;
		   }
	   }
     }  
	 UpdateData(FALSE);
}
void CDlgTabOne::OnBnClickedButtonSearch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_list.DeleteAllItems();
	m_FileSize=0;
	m_FileNum=0;
	if(m_file=="")
	{
		MessageBox(_T("�޷����в���"),_T(""),MB_OK);
	}
	else
	 findFile(m_file);//��ʼ����
	m_FileType="";
	m_Size1=0;
	m_Size2=0;
	m_FileDate="";
	UpdateData(FALSE);
}

void CDlgTabOne::OnBnClickedButtonChoose4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 int cnt=0;
	 for(int i=0; i<m_list.GetItemCount(); i++)
       {
            if(m_list.GetCheck(i))
			{
				cnt++;
			}
	 }
	 if(cnt==0)
	 {
		MessageBox(_T("�޷���������"),_T(""),MB_OK);
	 return ; 
	 }
       for(int i=0; i<m_list.GetItemCount(); i++)
       {
            if(m_list.GetCheck(i))
            {
                CString s=m_list.GetItemText(i,1);
				DeleteFile(s);
            }
       }
		   AfxMessageBox(_T("����ɹ�"));
	  
}



void CDlgTabOne::OnLvnItemchangedListResult(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 m_list.SetExtendedStyle(LVS_EX_CHECKBOXES);
	*pResult = 0;
}


void CDlgTabOne::OnBnClickedButtonChoose2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int i=0;i<m_list.GetItemCount();++i)
	{
		if(m_list.GetCheck(i)==1)
			continue;
		else if(m_list.GetCheck(i)==0)
		{
			m_list.SetCheck(i,1);
		}
	}
}


void CDlgTabOne::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgTabOne::OnEnChangeEditNum()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	 UpdateData(FALSE);//��ʾ�ļ���������ļ�����
}


void CDlgTabOne::OnStnClickedStaticDescription()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgTabOne::OnEnChangeEditFilesize()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	 UpdateData(FALSE);//��ʾ�ļ��еĴ�С
}


void CDlgTabOne::OnEnChangeEditSearch()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDlgTabOne::OnStnClickedStaticDatefanwei()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgTabOne::OnEnChangeEditFiletype()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CDlgTabOne::OnEnChangeEditDate1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CDlgTabOne::OnEnChangeEditDate2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CDlgTabOne::OnStnClickedStaticDanwei2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgTabOne::OnEnChangeEditsize1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}

void CDlgTabOne::findBigFile(CString nowFile)
{
	 FILETIME filetime;
	 FILETIME localtime;
	 SYSTEMTIME systemtime;
	 CFileFind finder;
	 if (nowFile.Right(1)!=_T("\\"))  
          nowFile+=  _T("\\*.*");
	 else 
		 nowFile+=_T("*.*");
     if(m_Size1>m_Size2)
	 {
		 MessageBox(_T("��С��Χ����ȷ�����������룡"),_T(""),MB_OK);
		 return;
	 }
     BOOL bWorking = finder.FindFile(nowFile);  
     while(bWorking)  
     {  
       bWorking = finder.FindNextFile();  
       //����ҵ������ļ��У��ݹ��ȥ  
       if (finder.IsDirectory()&&!finder.IsDots())  
       {  
         findBigFile(finder.GetFilePath());  
       }  	
	   if(!finder.IsDirectory()&&!finder.IsDots())
	   {
		   CString tmpFileName=finder.GetFileName();
		   int pos=tmpFileName.ReverseFind('.');
		   int lenth=tmpFileName.GetLength();
		   CString NowFileType=tmpFileName.Right(lenth-pos-1);
		   LONGLONG FileSize=finder.GetLength()/1024;
		   finder.GetLastWriteTime(&filetime);
		   FileTimeToLocalFileTime(&filetime,&localtime);
		   FileTimeToSystemTime(&localtime,&systemtime);
		   CString TmpFileTime=_T("");
		   TmpFileTime.Format(_T("%04d/%02d/%02d"),systemtime.wYear,systemtime.wMonth,systemtime.wDay);
		   if(m_FileType!=""||m_Size1!=0||m_FileDate!=""&&FileSize>=100576)
		   {
		     if(m_FileType==NowFileType&&m_Size1==0&&m_Size2==0&&m_FileDate=="")
		      {
                //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
		         }
			 else if(m_FileType==""&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate=="")
			 {
				 m_list.InsertItem(0,finder.GetFileName());
	             m_list.SetItemText(0,1,finder.GetFilePath());
		         CTime ftime;
		         finder.GetLastWriteTime(ftime);
		         double fileSize=(double)finder.GetLength()/1024;
		         CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		         m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==""&&m_Size1==0&&m_Size2==0&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==NowFileType&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate=="")
			 {
				 m_list.InsertItem(0,finder.GetFileName());
	             m_list.SetItemText(0,1,finder.GetFilePath());
		         CTime ftime;
		         finder.GetLastWriteTime(ftime);
		         double fileSize=(double)finder.GetLength()/1024;
		         CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			  else if(m_FileType==NowFileType&&m_Size1==0&&m_Size2==0&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==""&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			   else if(m_FileType==NowFileType&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
		   }
		   if(m_FileType==""&&m_Size1==0&&m_FileDate==""&&FileSize>=100576)
		   {  
			   m_list.InsertItem(0,finder.GetFileName());
	           m_list.SetItemText(0,1,finder.GetFilePath());
		      CTime ftime;
		      finder.GetLastWriteTime(ftime);
		      double fileSize=(double)finder.GetLength()/1024;
		      CString FileFormat;
	          FileFormat.Format(_T("%.0fKB"),fileSize);
		      m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		      m_list.SetItemText(0,3,FileFormat);
		      m_FileNum++;
		      m_FileSize+=(LONGLONG)fileSize;
		   }
	   }
     }  
	 UpdateData(FALSE);
}
void CDlgTabOne::OnBnClickedButtonFindbigfile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_list.DeleteAllItems();
	m_FileSize=0;
	m_FileNum=0;
	if(m_file=="")
	{
		MessageBox(_T("�޷����в���"),_T(""),MB_OK);
	}
	else
	 findBigFile(m_file);
	m_FileType="";
	m_Size1=0;
	m_Size2=0;
	m_FileDate="";
	UpdateData(FALSE);
}
void CDlgTabOne::findLitterFile(CString nowFile)
{
	 FILETIME filetime;
	 FILETIME localtime;
	 SYSTEMTIME systemtime;
	 CFileFind finder;
	 if (nowFile.Right(1)!=_T("\\"))  
          nowFile+=  _T("\\*.*");
	 else 
		 nowFile+=_T("*.*");
     if(m_Size1>m_Size2)
	 {
		 MessageBox(_T("��С��Χ����ȷ�����������룡"),_T(""),MB_OK);
		 return;
	 }
     BOOL bWorking = finder.FindFile(nowFile);  
     while(bWorking)  
     {  
       bWorking = finder.FindNextFile();  
       //����ҵ������ļ��У��ݹ��ȥ  
       if (finder.IsDirectory()&&!finder.IsDots())  
       {  
         findLitterFile(finder.GetFilePath());  
       }  	
	   if(!finder.IsDirectory()&&!finder.IsDots())
	   {
		   CString tmpFileName=finder.GetFileName();
		   int pos=tmpFileName.ReverseFind('.');
		   int lenth=tmpFileName.GetLength();
		   CString NowFileType=tmpFileName.Right(lenth-pos-1);
		   LONGLONG FileSize=finder.GetLength()/1024;
		   finder.GetLastWriteTime(&filetime);
		   FileTimeToLocalFileTime(&filetime,&localtime);
		   FileTimeToSystemTime(&localtime,&systemtime);
		   CString TmpFileTime=_T("");
		   TmpFileTime.Format(_T("%04d/%02d/%02d"),systemtime.wYear,systemtime.wMonth,systemtime.wDay);
		   if((m_FileType!=""||m_Size1!=0||m_FileDate!="")&&(NowFileType=="tmp"||NowFileType=="syd"||NowFileType=="ftg"||NowFileType=="gid"||NowFileType=="bak"||NowFileType=="chk"||NowFileType=="diz"||NowFileType=="temp"||NowFileType=="log"))
		   {
		     if(m_FileType==NowFileType&&m_Size1==0&&m_Size2==0&&m_FileDate=="")
		      {
                //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
		         }
			 else if(m_FileType==""&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate=="")
			 {
				 m_list.InsertItem(0,finder.GetFileName());
	             m_list.SetItemText(0,1,finder.GetFilePath());
		         CTime ftime;
		         finder.GetLastWriteTime(ftime);
		         double fileSize=(double)finder.GetLength()/1024;
		         CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		         m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==""&&m_Size1==0&&m_Size2==0&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==NowFileType&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate=="")
			 {
				 m_list.InsertItem(0,finder.GetFileName());
	             m_list.SetItemText(0,1,finder.GetFilePath());
		         CTime ftime;
		         finder.GetLastWriteTime(ftime);
		         double fileSize=(double)finder.GetLength()/1024;
		         CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			  else if(m_FileType==NowFileType&&m_Size1==0&&m_Size2==0&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==""&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			   else if(m_FileType==NowFileType&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
		   }
		   if((m_FileType==""&&m_Size1==0&&m_FileDate=="")&&(NowFileType=="tmp"||NowFileType=="syd"||NowFileType=="ftg"||NowFileType=="gid"||NowFileType=="bak"||NowFileType=="chk"||NowFileType=="diz"||NowFileType=="temp"||NowFileType=="log"))
		   {  
			   m_list.InsertItem(0,finder.GetFileName());
	           m_list.SetItemText(0,1,finder.GetFilePath());
		      CTime ftime;
		      finder.GetLastWriteTime(ftime);
		      double fileSize=(double)finder.GetLength()/1024;
		      CString FileFormat;
	          FileFormat.Format(_T("%.0fKB"),fileSize);
		      m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		      m_list.SetItemText(0,3,FileFormat);
		      m_FileNum++;
		      m_FileSize+=(LONGLONG)fileSize;
		   }
	   }
     }  
	 UpdateData(FALSE);
}
void CDlgTabOne::OnBnClickedButtonSaomiaolaji()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_list.DeleteAllItems();
	m_FileSize=0;
	m_FileNum=0;
	if(m_file=="")
	{
		MessageBox(_T("�޷����в���"),_T(""),MB_OK);
	}
	else
	 findLitterFile(m_file);
	m_FileType="";
	m_Size1=0;
	m_Size2=0;
	m_FileDate="";
	UpdateData(FALSE);
}


void CDlgTabOne::OnStnClickedStaticFiletype()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgTabOne::OnStnClickedStaticCondition()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CFont font;
 //font.CreatePointFont(400,_T("����"),NULL);
 //GetDlgItem(IDC_STATIC_CONDITION)->SetFont(&font);
}
void CDlgTabOne::findSameNameFile(CString nowFile)
{
	 FILETIME filetime;
	 FILETIME localtime;
	 SYSTEMTIME systemtime;
	 CFileFind finder;
	 if (nowFile.Right(1)!=_T("\\"))  
          nowFile+=  _T("\\*.*");
	 else 
		 nowFile+=_T("*.*");
     if(m_Size1>m_Size2)
	 {
		 MessageBox(_T("��С��Χ����ȷ�����������룡"),_T(""),MB_OK);
		 return;
	 }
     BOOL bWorking = finder.FindFile(nowFile);  
     while(bWorking)  
     {  
       bWorking = finder.FindNextFile();  
       //����ҵ������ļ��У��ݹ��ȥ  
       if (finder.IsDirectory()&&!finder.IsDots())  
       {  
         findSameNameFile(finder.GetFilePath());  
       }  	
	   if(!finder.IsDirectory()&&!finder.IsDots())
	   {
		   CString tmpFileName=finder.GetFileName();
		   int pos=tmpFileName.ReverseFind('.');
		   int lenth=tmpFileName.GetLength();
		   CString NowFileType=tmpFileName.Right(lenth-pos-1);
		   CString tmp1FileName=tmpFileName.Left(pos);
		   CString NowFileName=m_SameNameFile;//+"."+NowFileType;
		   LONGLONG FileSize=finder.GetLength()/1024;
		   finder.GetLastWriteTime(&filetime);
		   FileTimeToLocalFileTime(&filetime,&localtime);
		   FileTimeToSystemTime(&localtime,&systemtime);
		   CString TmpFileTime=_T("");
		   TmpFileTime.Format(_T("%04d/%02d/%02d"),systemtime.wYear,systemtime.wMonth,systemtime.wDay);
		   if((m_FileType!=""||m_Size1!=0||m_FileDate!="")&&(IsEquale(NowFileName,tmp1FileName)==1))
		   {
		     if(m_FileType==NowFileType&&m_Size1==0&&m_Size2==0&&m_FileDate=="")
		      {
                //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
		         }
			 else if(m_FileType==""&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate=="")
			 {
				 m_list.InsertItem(0,finder.GetFileName());
	             m_list.SetItemText(0,1,finder.GetFilePath());
		         CTime ftime;
		         finder.GetLastWriteTime(ftime);
		         double fileSize=(double)finder.GetLength()/1024;
		         CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		         m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==""&&m_Size1==0&&m_Size2==0&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==NowFileType&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate=="")
			 {
				 m_list.InsertItem(0,finder.GetFileName());
	             m_list.SetItemText(0,1,finder.GetFilePath());
		         CTime ftime;
		         finder.GetLastWriteTime(ftime);
		         double fileSize=(double)finder.GetLength()/1024;
		         CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			  else if(m_FileType==NowFileType&&m_Size1==0&&m_Size2==0&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==""&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			   else if(m_FileType==NowFileType&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
		   }
		   if((m_FileType==""&&m_Size1==0&&m_FileDate=="")&&(IsEquale(NowFileName,tmp1FileName)==1))
		   {  
			   m_list.InsertItem(0,finder.GetFileName());
	           m_list.SetItemText(0,1,finder.GetFilePath());
		      CTime ftime;
		      finder.GetLastWriteTime(ftime);
		      double fileSize=(double)finder.GetLength()/1024;
		      CString FileFormat;
	          FileFormat.Format(_T("%.0fKB"),fileSize);
		      m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		      m_list.SetItemText(0,3,FileFormat);
		      m_FileNum++;
		      m_FileSize+=(LONGLONG)fileSize;
		   }
	   }
     }  
	 UpdateData(FALSE);
}

void CDlgTabOne::OnEnChangeEditFindsamenamefile()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CString m_Head;
    //char *codefile;
    //codefile=(LPSTR)(LPCTSTR)m_Head;
	UpdateData(TRUE);
}


void CDlgTabOne::OnBnClickedButtonFindsamenamefile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_list.DeleteAllItems();
	m_FileSize=0;
	m_FileNum=0;
	if(m_SameNameFile=="")
	{
		MessageBox(_T("�޷����в���"),_T(""),MB_OK);
	}
	else
	 findSameNameFile(m_file);
	m_FileType="";
	m_Size1=0;
	m_Size2=0;
	m_FileDate="";
	UpdateData(FALSE);
}


void CDlgTabOne::OnBnClickedButtonChoose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int i=0;i<m_list.GetItemCount();++i)
	{
		if(m_list.GetCheck(i)==0)
			continue;
		else if(m_list.GetCheck(i)==1)
		{
			m_list.SetCheck(i,0);
		}
	}
}


void CDlgTabOne::findLinshiFile(CString nowFile)
{
	FILETIME filetime;
	 FILETIME localtime;
	 SYSTEMTIME systemtime;
	 CFileFind finder;
	 if (nowFile.Right(1)!=_T("\\"))  
          nowFile+=  _T("\\*.*");
	 else 
		 nowFile+=_T("*.*");
     if(m_Size1>m_Size2)
	 {
		 MessageBox(_T("��С��Χ����ȷ�����������룡"),_T(""),MB_OK);
		 return;
	 }
     BOOL bWorking = finder.FindFile(nowFile);  
     while(bWorking)  
     {  
       bWorking = finder.FindNextFile();  
       //����ҵ������ļ��У��ݹ��ȥ  
       if (finder.IsDirectory()&&!finder.IsDots())  
       {  
         findLinshiFile(finder.GetFilePath());  
       }  	
	   if(!finder.IsDirectory()&&!finder.IsDots())
	   {
		   CString tmpFileName=finder.GetFileName();
		   int pos=tmpFileName.ReverseFind('.');
		   int lenth=tmpFileName.GetLength();
		   CString NowFileType=tmpFileName.Right(lenth-pos-1);
		   LONGLONG FileSize=finder.GetLength()/1024;
		   finder.GetLastWriteTime(&filetime);
		   FileTimeToLocalFileTime(&filetime,&localtime);
		   FileTimeToSystemTime(&localtime,&systemtime);
		   CString TmpFileTime=_T("");
		   TmpFileTime.Format(_T("%04d/%02d/%02d"),systemtime.wYear,systemtime.wMonth,systemtime.wDay);
		   if((m_FileType!=""||m_Size1!=0||m_FileDate!="")&&(NowFileType=="tmp"||NowFileType=="temp"))
		   {
		     if(m_FileType==NowFileType&&m_Size1==0&&m_Size2==0&&m_FileDate=="")
		      {
                //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
		         }
			 else if(m_FileType==""&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate=="")
			 {
				 m_list.InsertItem(0,finder.GetFileName());
	             m_list.SetItemText(0,1,finder.GetFilePath());
		         CTime ftime;
		         finder.GetLastWriteTime(ftime);
		         double fileSize=(double)finder.GetLength()/1024;
		         CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		         m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==""&&m_Size1==0&&m_Size2==0&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==NowFileType&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate=="")
			 {
				 m_list.InsertItem(0,finder.GetFileName());
	             m_list.SetItemText(0,1,finder.GetFilePath());
		         CTime ftime;
		         finder.GetLastWriteTime(ftime);
		         double fileSize=(double)finder.GetLength()/1024;
		         CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			  else if(m_FileType==NowFileType&&m_Size1==0&&m_Size2==0&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			 else if(m_FileType==""&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
			   else if(m_FileType==NowFileType&&((m_Size1<=FileSize)&&(FileSize<=m_Size2))&&m_FileDate==TmpFileTime)
			 {
				    //����ҵ����ļ���������·����ӽ��ַ�������,��Сд������    
	            m_list.InsertItem(0,finder.GetFileName());
	            m_list.SetItemText(0,1,finder.GetFilePath());
		        CTime ftime;
		        finder.GetLastWriteTime(ftime);
		        double fileSize=(double)finder.GetLength()/1024;
		        CString FileFormat;
	             FileFormat.Format(_T("%.0fKB"),fileSize);
		         m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		         m_list.SetItemText(0,3,FileFormat);
		          m_FileNum++;
		         m_FileSize+=(LONGLONG)fileSize;
			 }
		   }
		   if((m_FileType==""&&m_Size1==0&&m_FileDate=="")&&(NowFileType=="tmp"||NowFileType=="temp"))
		   {  
			   m_list.InsertItem(0,finder.GetFileName());
	           m_list.SetItemText(0,1,finder.GetFilePath());
		      CTime ftime;
		      finder.GetLastWriteTime(ftime);
		      double fileSize=(double)finder.GetLength()/1024;
		      CString FileFormat;
	          FileFormat.Format(_T("%.0fKB"),fileSize);
		      m_list.SetItemText(0,2,ftime.Format("%Y/%m/%d %H:%M:%S"));
		      m_list.SetItemText(0,3,FileFormat);
		      m_FileNum++;
		      m_FileSize+=(LONGLONG)fileSize;
		   }
	   }
     }  
	 UpdateData(FALSE);
}

void CDlgTabOne::OnBnClickedButtonSaomiao()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_list.DeleteAllItems();
	m_FileSize=0;
	m_FileNum=0;
	if(m_file=="")
	{
		MessageBox(_T("�޷����в���"),_T(""),MB_OK);
	}
	else
	 findLinshiFile(m_file);
	m_FileType="";
	m_Size1=0;
	m_Size2=0;
	m_FileDate="";
	UpdateData(FALSE);
}
/*int CDlgTabOne::IsEquale(CString str1,CString str2)
{
	char *strArr1;
    strArr1=(LPSTR)(LPCTSTR)str1;
	char *strArr2;
	strArr2=(LPSTR)(LPCTSTR)str2;
	int lenth1=strlen(strArr1);
	int lenth2=strlen(strArr2);
	int j=0;
	for(int i=0;i<lenth2;i++)
	{
		if(strArr1[j]==strArr2[i]&&j<lenth1)
		{
			j++;
		}
	}
	if(j==lenth1)
		return 1;
	return 0;
}*/
int CDlgTabOne::IsEquale(CString str1,CString str2)
{
	int lenth1=str1.GetLength();
	int lenth2=str2.GetLength();
	int j=0;
	for(int i=0;i<lenth2;++i)
	{
		CString tmp=str1.Mid(j,1);
		CString tmp1=str2.Mid(i,1);
		if(str1.Mid(j,1)==str2.Mid(i,1)&&j<lenth1)
		{
			j++;
		}
	}
	if(j==lenth1)
		return 1;
	return 0;
}
