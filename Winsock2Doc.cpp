// Winsock2Doc.cpp : implementation of the CWinsock2Doc class
//

#include "stdafx.h"
#include "Winsock2.h"

#include "Winsock2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinsock2Doc

IMPLEMENT_DYNCREATE(CWinsock2Doc, CDocument)

BEGIN_MESSAGE_MAP(CWinsock2Doc, CDocument)
	//{{AFX_MSG_MAP(CWinsock2Doc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinsock2Doc construction/destruction

CWinsock2Doc::CWinsock2Doc()
{
}

CWinsock2Doc::~CWinsock2Doc()
{
}

BOOL CWinsock2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	SetTitle("");

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CWinsock2Doc serialization

void CWinsock2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWinsock2Doc diagnostics

#ifdef _DEBUG
void CWinsock2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWinsock2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinsock2Doc commands
