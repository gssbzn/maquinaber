//-- DGMODELESS.CPP

#include "stdafx.h"
#include "dgmodeless.h"

BEGIN_MESSAGE_MAP(CDGModelessMessage, CDialog)
	//{{AFX_MSG_MAP(CDGModelessMessage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CDGModelessMessage::CDGModelessMessage(CWnd* pParent /*= NULL*/)
	: CDialog(CDGModelessMessage::IDD, pParent)
{
	m_csMessage = "No Message Specified";
	m_csTitle = "Message";
}

CDGModelessMessage::CDGModelessMessage(CString csMessage, CString csTitle /*= "Message"*/, CWnd* pParent /*= NULL*/)
	: CDialog(CDGModelessMessage::IDD, pParent)
{
	m_csMessage = csMessage;
	m_csTitle = csTitle;
}

void CDGModelessMessage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDGModelessMessage)
	DDX_Control(pDX, IDC_MESSAGE, m_stMessage);
	//}}AFX_DATA_MAP
}

BOOL CDGModelessMessage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CenterWindow();
	SetWindowText(m_csTitle);
	m_stMessage.SetWindowText(m_csMessage);

	return TRUE;
}

void CDGModelessMessage::Show() 
{
	Create(IDD);
}

void CDGModelessMessage::Kill() 
{
	DestroyWindow();
}

