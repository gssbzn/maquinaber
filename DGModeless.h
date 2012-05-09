//-- DGMODELESS.H

#include "resource.h"
 
class CDGModelessMessage : public CDialog
{
public:
	CDGModelessMessage(CWnd* pParent = NULL);
	CDGModelessMessage(CString csMessage, CString csTitle = "Message", CWnd* pParent = NULL);

	//{{AFX_DATA(CDGModelessMessage)
	enum { IDD = IDD_MODELESSMESSAGE };
	CStatic	m_stMessage;
	//}}AFX_DATA

//-- Data
	CString m_csMessage;
	CString m_csTitle;

//-- Funciones
	void Show();
	void Kill();

	//{{AFX_VIRTUAL(CDGModelessMessage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDGModelessMessage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
