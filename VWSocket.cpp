//-- VWSOCKET.CPP

#include "stdafx.h"
#include "Winsock2.h"
#include "dgmodeless.h"
#include "VWSocket.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <bitset>
#include <string.h>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int compararbits(char *cad1, char *cad2){
    /*compara cadenas caracter a caracter con tolower*/   
    int i,j=0;
    
	if(strlen(cad1)>strlen(cad2)){
		return strlen(cad1)-strlen(cad2);
	}
	else if ( strlen(cad1)>strlen(cad2) ){
		return strlen(cad2)-strlen(cad1);
	}
	else{
		for (i=0;(unsigned)i<(unsigned)strlen(cad1);i++) { 
			if (tolower(cad1[i])!=tolower(cad2[i])) j++;
		}
		return j;/*devuelve la cantidad de bits dañados*/
	}
}


BEGIN_MESSAGE_MAP(CVWSocket, CFormView)
	//{{AFX_MSG_MAP(CVWSocket)
	ON_BN_CLICKED(IDOK,					AlSalir)
	ON_BN_CLICKED(IDC_BN_MODPRUEB,	ModoError)
	ON_BN_CLICKED(IDC_BN_RECBUDP,		RecibirUDP)
	ON_BN_CLICKED(IDC_BN_ENVUDP,		EnviarUDP)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

IMPLEMENT_DYNCREATE(CVWSocket, CFormView)

CVWSocket::CVWSocket()
	: CFormView(CVWSocket::IDD)
{
	//{{AFX_DATA_INIT(CVWSocket)
	//}}AFX_DATA_INIT
}

CVWSocket::~CVWSocket()
{
	RemoveSockets();
}

void CVWSocket::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVWSocket)
	DDX_Control(pDX, IDC_PUERTOUDP, m_edPuertEsc);
	DDX_Control(pDX, IDC_PUERTODEST, m_edPuertDest);
	DDX_Control(pDX, IDC_IPDEST, m_edIPDest);
	DDX_Control(pDX, IDC_NOMBRELOCAL, m_edNombreLocal);
	DDX_Control(pDX, IDC_IPLOCAL, m_edIPLocal);
	DDX_Control(pDX, IDC_TIEMPO, m_edTiempo);
	//}}AFX_DATA_MAP
}

void CVWSocket::OnInitialUpdate() 
{
	char		buf[255];

	CFormView::OnInitialUpdate();

	if (!InitSockets_1_1())
		AfxMessageBox("Error en Winsock.  No se pudo inicializar.");

//-- Obtiene la informacion del host local
	m_edNombreLocal.SetWindowText(GetHostName(buf, 255));
	m_edIPLocal.SetWindowText(IPString(uGetLocalIP(), buf, 25));

//-- Establece los puertos por defecto
	m_edPuertEsc.SetWindowText("2600");
	m_edPuertDest.SetWindowText("2600");
	
}

/************************************************************************/
/**************  MANEJADORES DE MENSAJES ********************************/
/************************************************************************/
void CVWSocket::RecibirUDP() 
{
	SOCKADDR_IN		dir_Srv, dir_Cli;
	SOCKET			sock_Receive;
	char			szMensaje[256], cad1[100], cad2[100], buf[256];
	int				puertoescucha;
	int				i, clilen, bitsmalos, paquetes;
	int				val = 1;
	CString			csTemp;
	ofstream		salida;
	
	
	
//-- Obtiene el puerto en el que se va a escuchar
	m_edPuertEsc.GetWindowText(csTemp);
	puertoescucha = atoi(csTemp.GetBuffer(0));
	csTemp.ReleaseBuffer(-1);
	
	if (puertoescucha < 1)
	{
		AfxMessageBox("Por favor Introduzca un puerto UDP válido");
		return;
	}

//-- Abre el socket UDP 
	if ((sock_Receive = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		AfxMessageBox("Error, no es posible abrir el socket");

//-- Fill in structure fields for binding to local host
	memset((char *) &dir_Srv, 0, sizeof(dir_Srv));
	dir_Srv.sin_family      = AF_INET;
	dir_Srv.sin_addr.s_addr = htonl(INADDR_ANY);
	dir_Srv.sin_port        = htons(puertoescucha);

//-- Enlaza el puerto UDP
	if (bind(sock_Receive, (sockaddr*)&dir_Srv, sizeof(dir_Srv)) < 0)
		AfxMessageBox("Error:  fallo en el enlace.");

	
//-- Muestra un mensaje mientras espera la recepcion de datos
	CDGModelessMessage dg("Esperando un mensaje UDP...", "BER");
	dg.Show();
	csTemp="";

	paquetes=0;
	bitsmalos=0;
	while(1){
		//-- Prepara la direccion del cliente para la recepcion de los datos
		memset(&dir_Cli, 0, sizeof(dir_Cli));
		clilen = sizeof(dir_Cli);
		
		//-- Recibe el mensaje
		if (recvfrom(sock_Receive, szMensaje, 256, 0, (sockaddr*)&dir_Cli, &clilen) == SOCKET_ERROR)
		{
			AfxMessageBox("Error:  fallo de recepcion.");
			return;
		}
		else if(strcmp(szMensaje,"\0")==0) break;
		else
		{
			//-- Recibimos el mensaje
			
			paquetes++;
			salida.open("log.txt", ios::out);
			for(i=0; (unsigned)i < strlen(szMensaje); i++)
				salida<<bitset<8>(szMensaje[i]);
			salida.close();
			ifstream entrada("log.txt");
			entrada>>cad1;
			bitsmalos += compararbits(cad1,"01100010");
			

		}
	}
	closesocket(sock_Receive);
	dg.Kill();

	csTemp += "Transmisión Completada\n";
	csTemp += "De:  ";
	csTemp += IPString(uGetIPFromSockAddr_In(&dir_Cli), buf, 255);
	csTemp += "\n\n";
	csTemp += "Bits enviados: ";
	sprintf_s(szMensaje, "%d\n", paquetes*8);
	csTemp += szMensaje;
	csTemp += "Bits erroneos: ";
	sprintf_s(szMensaje, "%d\n", bitsmalos);
	csTemp += szMensaje;
	csTemp += "Proporción de errores: ";
	sprintf_s(szMensaje, "%.4f", (float)bitsmalos/(float)(paquetes*8));
	csTemp += szMensaje;
	
	AfxMessageBox(csTemp);
	
}


void CVWSocket::EnviarUDP() 
{
	SOCKADDR_IN		dir_Dest;
	SOCKET			sock_Send;
	char			szMensaje[256], szIPDest[20];
	int				puertodest, tim;
	clock_t			inicio;
	CString			csTemp;


//-- Obtener la direccion ip a la que se desea enviar
	m_edIPDest.GetWindowText(csTemp);
	if (csTemp.IsEmpty())
	{
		AfxMessageBox("Por favor introduzca una dirección IP de destino");
		return;
	}
	strcpy_s(szIPDest, csTemp.GetBuffer(0));
	
//-- Obtener el Puerto de envio
	m_edPuertDest.GetWindowText(csTemp);
	puertodest = atoi(csTemp.GetBuffer(0));
	
	if (puertodest < 1)
	{
		AfxMessageBox("Por favor introduzca un puerto UDP valido");
		return;
	}
//-- Obtener el tiempo de prueba
	m_edTiempo.GetWindowText(csTemp);
	tim=atoi(csTemp);
	csTemp.ReleaseBuffer(-1);
	if (tim < 1)
	{
		AfxMessageBox("Por favor Introduzca un tiempo de transmisión valido");
		return;
	}

//-- Crear el socket UDP
	if ((sock_Send = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		AfxMessageBox("Error:  fallo en el socket.");

//-- Llenar la estructura de datos para el enlace
	memset((char *) &dir_Dest, 0, sizeof(dir_Dest));
	dir_Dest.sin_family      = AF_INET;
	dir_Dest.sin_addr.s_addr = inet_addr(szIPDest);
	dir_Dest.sin_port        = htons(puertodest);             

//-- Enviar por el periodo de tempo seleccionado
	
	inicio = clock();
	while(clock()/(double)CLOCKS_PER_SEC < (inicio/(double)CLOCKS_PER_SEC)+(double)tim)
    {		
		//-- Se Prepara el Mensaje
		//sprintf_s(szMensaje, "%i\n", i+1);
		if (sendto(sock_Send, "b", 256, 0, (sockaddr*)&dir_Dest, sizeof(dir_Dest)) == SOCKET_ERROR)
			AfxMessageBox("Error:  fallo de envio.");
	}
	if (sendto(sock_Send, "\0", 256, 0, (sockaddr*)&dir_Dest, sizeof(dir_Dest)) == SOCKET_ERROR)
		AfxMessageBox("Error:  fallo de envio.");
	
	closesocket(sock_Send);
	
}

void CVWSocket :: ModoError()
{
	SOCKADDR_IN		dir_Dest;
	SOCKET			sock_Send;
	char			szMensaje[256], szIPDest[20];
	int				puertodest, tim, w;
	clock_t			inicio;
	CString			csTemp;


//-- Obtener la direcion IP de destino
	m_edIPDest.GetWindowText(csTemp);
	if (csTemp.IsEmpty())
	{
		AfxMessageBox("Por favor introduzca una dirección IP de destino");
		return;
	}
	strcpy_s(szIPDest, csTemp.GetBuffer(0));

//-- Obtener el puerto a enviar
	m_edPuertDest.GetWindowText(csTemp);
	puertodest = atoi(csTemp.GetBuffer(0));
	
	if (puertodest < 1)
	{
		AfxMessageBox("Por favor introduzca un puerto UDP valido");
		return;
	}

//-- Obtener tiempo de la prueba
	m_edTiempo.GetWindowText(csTemp);
	tim=atoi(csTemp);
	csTemp.ReleaseBuffer(-1);
	if (tim < 1)
	{
		AfxMessageBox("Por favor Introduzca un tiempo de transmisión válido");
		return;
	}

//-- Crear socket UDP
	if ((sock_Send = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		AfxMessageBox("Error:  fallo en el socket.");

//-- Llenar la estructura de datos para el enlace
	memset((char *) &dir_Dest, 0, sizeof(dir_Dest));
	dir_Dest.sin_family      = AF_INET;
	dir_Dest.sin_addr.s_addr = inet_addr(szIPDest);
	dir_Dest.sin_port        = htons(puertodest);             

//-- Envio	
	inicio = clock();
	srand((unsigned)time(0));
	while(clock()/(double)CLOCKS_PER_SEC < (inicio/(double)CLOCKS_PER_SEC)+(double)tim)
    {		
		//-- Preparar Mensaje
		//sprintf_s(szMensaje, "%i\n", i+1);
		if (sendto(sock_Send, "b", 256, 0, (sockaddr*)&dir_Dest, sizeof(dir_Dest)) == SOCKET_ERROR)//Mensaje Correcto
			AfxMessageBox("Error:  fallo de envio.");
		srand((unsigned)time(0));
		w = rand();
		if( w % 2 == 0  )
		{
			if (sendto(sock_Send, "m", 256, 0, (sockaddr*)&dir_Dest, sizeof(dir_Dest)) == SOCKET_ERROR)//mensaje Incorrecto
				AfxMessageBox("Error:  fallo de envio.");
		}
	}
	if (sendto(sock_Send, "\0", 256, 0, (sockaddr*)&dir_Dest, sizeof(dir_Dest)) == SOCKET_ERROR)
		AfxMessageBox("Error:  fallo de envio.");

	closesocket(sock_Send);
	
}


void CVWSocket::AlSalir() 
{
	GetParentFrame()->SendMessage(WM_CLOSE);
}

/*********************************************************************************/
/***************  GENERALIDADES WINSOCK  *****************************************/
/*********************************************************************************/
int CVWSocket::InitSockets_1_1() 
{
	WORD		wVersionRequested = MAKEWORD(1, 1);  
	WSADATA		wsaData; 
	int			res; 
 
	res = WSAStartup(wVersionRequested, &wsaData); 
//-- If WSAStartup fails, abort
	if (res != 0) 
		return 0; 
//-- Confirm that the Windows Sockets DLL supports 1.1.
//-- Although the DLL may support higher versions, wVersion will hold 1.1
//-- because that's the one we requested. 
	if (LOBYTE(wsaData.wVersion)!= 1 || HIBYTE(wsaData.wVersion)!= 1) 
	{ 
	//-- Version 1.1 is not supported, abort
		WSACleanup(); 
		return 0; 
	} 
//-- All's good
	return 1;
}

void CVWSocket::RemoveSockets() 
{
	WSACleanup(); 
}

char* CVWSocket::GetHostName(char* buf, int len) 
{
	if (gethostname(buf, len) != 0)
		return NULL;
	return buf;
}

unsigned int CVWSocket::uGetLocalIP()
{
	char		szHostName[255];
	hostent*	HostData;
	
	GetHostName(szHostName, 255);
	HostData = gethostbyname(szHostName);
	if (HostData == NULL)
		return NULL;

	return *((unsigned int*)HostData->h_addr);
}

unsigned int CVWSocket::uGetIPFromSockAddr_In(sockaddr_in* pSockAddr)
{
	return (unsigned int)pSockAddr->sin_addr.S_un.S_addr;
}

char* CVWSocket::IPString(unsigned int dir, char* buf, int len)
{
	char* p = (char*)&dir;

	if (len < 16)
		return NULL;
	
	memset(buf, 0, len);
	sprintf(buf, "%d.%d.%d.%d", (unsigned char)*(p+0), (unsigned char)*(p+1), (unsigned char)*(p+2), (unsigned char)*(p+3));	

	return buf;
}

