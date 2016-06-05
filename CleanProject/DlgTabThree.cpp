// DlgTabThree.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CleanProject.h"
#include "DlgTabThree.h"
#include "afxdialogex.h"


// CDlgTabThree �Ի���

IMPLEMENT_DYNAMIC(CDlgTabThree, CDialogEx)

CDlgTabThree::CDlgTabThree(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTabThree::IDD, pParent)
	//, m_ModeFileName(_T(""))
	, m_ModeFileName(_T(""))
	, m_KeepPosition(_T(""))
	, m_FileNum(0)
	, m_FolderPosition(_T(""))
	, m_folderName(_T(""))
	, m_folderNum(0)
	, m_luJing(_T(""))
	, m_name(_T(""))
{

}

CDlgTabThree::~CDlgTabThree()
{
}

void CDlgTabThree::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_MODEFILE, m_FilePath);
	//  DDV_MaxChars(pDX, m_FilePath, 99999999);
	//  DDX_Text(pDX, IDC_EDIT_MODEFILE, m_FilePath);
	//  DDV_MaxChars(pDX, m_FilePath, 999999999);
	//  DDX_Text(pDX, IDC_EDIT_MODEFILE, m_ModeFileName);
	//  DDV_MaxChars(pDX, m_ModeFileName, 9999999);
	DDX_Text(pDX, IDC_EDIT_MODEFILE, m_ModeFileName);
	DDV_MaxChars(pDX, m_ModeFileName, 9999999);
	DDX_Text(pDX, IDC_EDIT_KEEPPOSITION, m_KeepPosition);
	DDV_MaxChars(pDX, m_KeepPosition, 99999999);
	DDX_Text(pDX, IDC_EDIT_NUM, m_FileNum);
	DDV_MinMaxInt(pDX, m_FileNum, 0, 999999999);
	DDX_Text(pDX, IDC_EDIT_FOLDER, m_FolderPosition);
	DDV_MaxChars(pDX, m_FolderPosition, 999999999);
	DDX_Text(pDX, IDC_EDIT_FOLDERNAME, m_folderName);
	DDV_MaxChars(pDX, m_folderName, 999999);
	DDX_Text(pDX, IDC_EDIT_FOLDERNUM, m_folderNum);
	DDV_MinMaxInt(pDX, m_folderNum, 0, 9999999);
	DDX_Text(pDX, IDC_EDIT_LUJING, m_luJing);
	DDV_MaxChars(pDX, m_luJing, 999999999);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 99999999);
}


BEGIN_MESSAGE_MAP(CDlgTabThree, CDialogEx)
	//ON_EN_CHANGE(IDC_EDIT6, &CDlgTabThree::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON_FINDMODE, &CDlgTabThree::OnBnClickedButtonFindmode)
	ON_EN_CHANGE(IDC_EDIT_MODEFILE, &CDlgTabThree::OnEnChangeEditModefile)
	ON_BN_CLICKED(IDC_BUTTON_POSITION, &CDlgTabThree::OnBnClickedButtonPosition)
	ON_BN_CLICKED(IDC_BUTTON_CREATE, &CDlgTabThree::OnBnClickedButtonCreate)
	ON_BN_CLICKED(IDC_BUTTON_KEEPPOSITION, &CDlgTabThree::OnBnClickedButtonKeepposition)
	ON_BN_CLICKED(IDC_BUTTON_CREATEFOLDER, &CDlgTabThree::OnBnClickedButtonCreatefolder)
	ON_EN_CHANGE(IDC_EDIT_KEEPPOSITION, &CDlgTabThree::OnEnChangeEditKeepposition)
	ON_EN_CHANGE(IDC_EDIT_NUM, &CDlgTabThree::OnEnChangeEditNum)
	ON_EN_CHANGE(IDC_EDIT_FOLDERNAME, &CDlgTabThree::OnEnChangeEditFoldername)
	ON_EN_CHANGE(IDC_EDIT_FOLDERNUM, &CDlgTabThree::OnEnChangeEditFoldernum)
	ON_BN_CLICKED(IDC_BUTTON_XUANZEWENJIAN, &CDlgTabThree::OnBnClickedButtonXuanzewenjian)
	ON_BN_CLICKED(IDC_BUTTON_XUANZEWENJIANJIA, &CDlgTabThree::OnBnClickedButtonXuanzewenjianjia)
	ON_EN_CHANGE(IDC_EDIT_LUJING, &CDlgTabThree::OnEnChangeEditLujing)
	ON_BN_CLICKED(IDC_BUTTON_SURE, &CDlgTabThree::OnBnClickedButtonSure)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CDlgTabThree::OnEnChangeEditName)
END_MESSAGE_MAP()


// CDlgTabThree ��Ϣ�������

void CDlgTabThree::OnBnClickedButtonFindmode()
{
	 
    // ���ù�����   
    TCHAR szFilter[] = _T("�ı��ļ�(*.)|*|�����ļ�(*.*)|*.*||");   
    // ������ļ��Ի���   
    CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);   
    CString strFilePath;   
    // ��ʾ���ļ��Ի���   
    if (IDOK == fileDlg.DoModal())   
    {   
        // ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
         strFilePath = fileDlg.GetFileName();   
        SetDlgItemText(IDC_EDIT_MODEFILE, strFilePath);   
    }   
	//m_ModeFileName=strFilePath;
}


void CDlgTabThree::OnEnChangeEditModefile()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CDlgTabThree::OnBnClickedButtonPosition()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox(_T("asf"));
	char szPath[MAX_PATH];     //���ѡ���Ŀ¼·�� 
    CString str;
    ZeroMemory(szPath, sizeof(szPath));   
    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName =(LPWSTR)szPath;   
    bi.lpszTitle = _T("��ѡ����Ҫ�򿪵�Ŀ¼��");   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //����ѡ��Ŀ¼�Ի���
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

    if(lp && SHGetPathFromIDList(lp,(LPWSTR)szPath))   
    {
       // str.Format(_T("ѡ���Ŀ¼Ϊ %s"),szPath);
       // AfxMessageBox(str); 
		SetDlgItemText(IDC_EDIT_KEEPPOSITION,(LPCTSTR)szPath); 
    }
    else   
        AfxMessageBox(_T("��Ч��Ŀ¼��������ѡ��"));   
}


void CDlgTabThree::OnBnClickedButtonCreate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox(_T("asf"));
	 //UpdateData(TRUE);
   CFile file;
   CString filePath,fileName,str;
   filePath=m_KeepPosition;
   if(filePath.Right(1)!="\\")
	   filePath+="\\";
   for(int i=1;i<=m_FileNum;++i)
   {
	   str.Format(_T("(%d)"),i);
	   fileName=filePath+str+m_ModeFileName;
	   file.Open(fileName,CFile::modeCreate|CFile::modeWrite);
	   file.Close();
   }
   if(m_FileNum!=0)
   {
      AfxMessageBox(_T("�ļ������ɹ�"));
   }
}


void CDlgTabThree::OnBnClickedButtonKeepposition()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox(_T("asf"));
		// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox(_T("asf"));
	char szPath[MAX_PATH];     //���ѡ���Ŀ¼·�� 
    CString str;
    ZeroMemory(szPath, sizeof(szPath));   
    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName =(LPWSTR)szPath;   
    bi.lpszTitle = _T("��ѡ����Ҫ�򿪵�Ŀ¼��");   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //����ѡ��Ŀ¼�Ի���
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

    if(lp && SHGetPathFromIDList(lp,(LPWSTR)szPath))   
    {
       // str.Format(_T("ѡ���Ŀ¼Ϊ %s"),szPath);
       // AfxMessageBox(str); 
		SetDlgItemText(IDC_EDIT_FOLDER,(LPCTSTR)szPath); 
    }
    else   
        AfxMessageBox(_T("��Ч��Ŀ¼��������ѡ��"));   
}


void CDlgTabThree::OnBnClickedButtonCreatefolder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox(_T("asf"));
	CString folerName;
	CString tmp;
	 if(m_FolderPosition.Right(1)!="\\")
	  m_FolderPosition+="\\";
	for(int i=1;i<=m_folderNum;++i)
	{
		tmp.Format(_T("(%d)"),i);
		folerName=m_FolderPosition+tmp+m_folderName;
		CreateDirectory(folerName,NULL); 
	}
	if(m_folderNum!=0)
		 AfxMessageBox(_T("�ļ��д����ɹ�"));
}


void CDlgTabThree::OnEnChangeEditKeepposition()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CDlgTabThree::OnEnChangeEditNum()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CDlgTabThree::OnEnChangeEditFoldername()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CDlgTabThree::OnEnChangeEditFoldernum()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CDlgTabThree::OnBnClickedButtonXuanzewenjian()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    // ���ù�����   
    TCHAR szFilter[] = _T("�ı��ļ�(*.)|*|�����ļ�(*.*)|*.*||");   
    // ������ļ��Ի���   
    CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);   
    CString strFilePath;   
    // ��ʾ���ļ��Ի���   
    if (IDOK == fileDlg.DoModal())   
    {   
        // ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();   
        SetDlgItemText(IDC_EDIT_LUJING, strFilePath);   
    }   
	//m_ModeFileName=strFilePath;
}


void CDlgTabThree::OnBnClickedButtonXuanzewenjianjia()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox(_T("asf"));
		// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox(_T("asf"));
	char szPath[MAX_PATH];     //���ѡ���Ŀ¼·�� 
    CString str;
    ZeroMemory(szPath, sizeof(szPath));   
    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName =(LPWSTR)szPath;   
    bi.lpszTitle = _T("��ѡ����Ҫ�򿪵�Ŀ¼��");   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //����ѡ��Ŀ¼�Ի���
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

    if(lp && SHGetPathFromIDList(lp,(LPWSTR)szPath))   
    {
       // str.Format(_T("ѡ���Ŀ¼Ϊ %s"),szPath);
       // AfxMessageBox(str); 
		SetDlgItemText(IDC_EDIT_LUJING,(LPCTSTR)szPath); 
    }
    else   
        AfxMessageBox(_T("��Ч��Ŀ¼��������ѡ��")); 
}


void CDlgTabThree::OnEnChangeEditLujing()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}
void CDlgTabThree::Rename(CString Path,CString FileName)
{
	int lenth1=Path.GetLength();
	CString tmp=Path;
	int pos=Path.ReverseFind('\\')+1;
	Path.Delete(pos,lenth1-pos);
	CString tmp1=Path+FileName;
	if(Path.IsEmpty()||FileName.IsEmpty())
	{
		MessageBox(_T("�޷�����������"),_T(""),MB_OK);
		return ;
	}
	if(MoveFile(tmp,tmp1))
		MessageBox(_T("�������ɹ�"),_T(""),MB_OK);
}

void CDlgTabThree::OnBnClickedButtonSure()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Rename(m_luJing,m_name);
}


void CDlgTabThree::OnEnChangeEditName()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}
