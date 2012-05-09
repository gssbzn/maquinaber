//-- VWSOCKET.H

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CVWSocket : public CFormView
{
protected:
	CVWSocket();
	DECLARE_DYNCREATE(CVWSocket)

public:
	//{{AFX_DATA(CVWSocket)
	enum { IDD = IDD_SOCK };
	CEdit		m_edNombreLocal;
	CEdit		m_edIPLocal;

	CEdit		m_edPuertEsc;
	CEdit		m_edPuertDest;
	CEdit		m_edIPDest;
	CEdit		m_edTiempo;
	//}}AFX_DATA

//-- General Winsock Helpful Functions
	int InitSockets_1_1();
	void RemoveSockets();
	char* GetHostName(char* buf, int len);
	unsigned int uGetLocalIP();
	unsigned int uGetIPFromSockAddr_In(sockaddr_in* pSockAddr);
	char* IPString(unsigned int addr, char* buf, int len);

public:
	//{{AFX_VIRTUAL(CVWSocket)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	virtual ~CVWSocket();

	//{{AFX_MSG(CVWSocket)
	afx_msg void AlSalir();
	afx_msg void ModoError();
	afx_msg void RecibirUDP();
	afx_msg void EnviarUDP();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

