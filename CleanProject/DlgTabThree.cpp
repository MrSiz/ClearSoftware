// DlgTabThree.cpp : 实现文件
//

#include "stdafx.h"
#include "CleanProject.h"
#include "DlgTabThree.h"
#include "afxdialogex.h"


// CDlgTabThree 对话框

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


// CDlgTabThree 消息处理程序

void CDlgTabThree::OnBnClickedButtonFindmode()
{
	 
    // 设置过滤器   
    TCHAR szFilter[] = _T("文本文件(*.)|*|所有文件(*.*)|*.*||");   
    // 构造打开文件对话框   
    CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);   
    CString strFilePath;   
    // 显示打开文件对话框   
    if (IDOK == fileDlg.DoModal())   
    {   
        // 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
         strFilePath = fileDlg.GetFileName();   
        SetDlgItemText(IDC_EDIT_MODEFILE, strFilePath);   
    }   
	//m_ModeFileName=strFilePath;
}


void CDlgTabThree::OnEnChangeEditModefile()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CDlgTabThree::OnBnClickedButtonPosition()
{
	// TODO: 在此添加控件通知处理程序代码
	//AfxMessageBox(_T("asf"));
	char szPath[MAX_PATH];     //存放选择的目录路径 
    CString str;
    ZeroMemory(szPath, sizeof(szPath));   
    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName =(LPWSTR)szPath;   
    bi.lpszTitle = _T("请选择需要打开的目录：");   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //弹出选择目录对话框
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

    if(lp && SHGetPathFromIDList(lp,(LPWSTR)szPath))   
    {
       // str.Format(_T("选择的目录为 %s"),szPath);
       // AfxMessageBox(str); 
		SetDlgItemText(IDC_EDIT_KEEPPOSITION,(LPCTSTR)szPath); 
    }
    else   
        AfxMessageBox(_T("无效的目录，请重新选择"));   
}


void CDlgTabThree::OnBnClickedButtonCreate()
{
	// TODO: 在此添加控件通知处理程序代码
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
      AfxMessageBox(_T("文件创建成功"));
   }
}


void CDlgTabThree::OnBnClickedButtonKeepposition()
{
	// TODO: 在此添加控件通知处理程序代码
	//AfxMessageBox(_T("asf"));
		// TODO: 在此添加控件通知处理程序代码
	//AfxMessageBox(_T("asf"));
	char szPath[MAX_PATH];     //存放选择的目录路径 
    CString str;
    ZeroMemory(szPath, sizeof(szPath));   
    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName =(LPWSTR)szPath;   
    bi.lpszTitle = _T("请选择需要打开的目录：");   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //弹出选择目录对话框
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

    if(lp && SHGetPathFromIDList(lp,(LPWSTR)szPath))   
    {
       // str.Format(_T("选择的目录为 %s"),szPath);
       // AfxMessageBox(str); 
		SetDlgItemText(IDC_EDIT_FOLDER,(LPCTSTR)szPath); 
    }
    else   
        AfxMessageBox(_T("无效的目录，请重新选择"));   
}


void CDlgTabThree::OnBnClickedButtonCreatefolder()
{
	// TODO: 在此添加控件通知处理程序代码
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
		 AfxMessageBox(_T("文件夹创建成功"));
}


void CDlgTabThree::OnEnChangeEditKeepposition()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CDlgTabThree::OnEnChangeEditNum()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CDlgTabThree::OnEnChangeEditFoldername()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CDlgTabThree::OnEnChangeEditFoldernum()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CDlgTabThree::OnBnClickedButtonXuanzewenjian()
{
	// TODO: 在此添加控件通知处理程序代码
    // 设置过滤器   
    TCHAR szFilter[] = _T("文本文件(*.)|*|所有文件(*.*)|*.*||");   
    // 构造打开文件对话框   
    CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);   
    CString strFilePath;   
    // 显示打开文件对话框   
    if (IDOK == fileDlg.DoModal())   
    {   
        // 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();   
        SetDlgItemText(IDC_EDIT_LUJING, strFilePath);   
    }   
	//m_ModeFileName=strFilePath;
}


void CDlgTabThree::OnBnClickedButtonXuanzewenjianjia()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	//AfxMessageBox(_T("asf"));
		// TODO: 在此添加控件通知处理程序代码
	//AfxMessageBox(_T("asf"));
	char szPath[MAX_PATH];     //存放选择的目录路径 
    CString str;
    ZeroMemory(szPath, sizeof(szPath));   
    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName =(LPWSTR)szPath;   
    bi.lpszTitle = _T("请选择需要打开的目录：");   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //弹出选择目录对话框
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

    if(lp && SHGetPathFromIDList(lp,(LPWSTR)szPath))   
    {
       // str.Format(_T("选择的目录为 %s"),szPath);
       // AfxMessageBox(str); 
		SetDlgItemText(IDC_EDIT_LUJING,(LPCTSTR)szPath); 
    }
    else   
        AfxMessageBox(_T("无效的目录，请重新选择")); 
}


void CDlgTabThree::OnEnChangeEditLujing()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
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
		MessageBox(_T("无法进行重命名"),_T(""),MB_OK);
		return ;
	}
	if(MoveFile(tmp,tmp1))
		MessageBox(_T("重命名成功"),_T(""),MB_OK);
}

void CDlgTabThree::OnBnClickedButtonSure()
{
	// TODO: 在此添加控件通知处理程序代码
	Rename(m_luJing,m_name);
}


void CDlgTabThree::OnEnChangeEditName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}
