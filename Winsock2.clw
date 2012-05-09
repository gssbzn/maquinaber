; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CVWSocket
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Winsock2.h"
LastPage=0

ClassCount=6
Class1=CWinsock2App
Class2=CWinsock2Doc
Class3=CWinsock2View
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_MODELESSMESSAGE
Resource2=IDD_SOCK
Class5=CAboutDlg
Class6=CVWSocket
Resource3=IDD_ABOUTBOX
Resource4=IDR_MAINFRAME

[CLS:CWinsock2App]
Type=0
HeaderFile=Winsock2.h
ImplementationFile=Winsock2.cpp
Filter=N
LastObject=CWinsock2App

[CLS:CWinsock2Doc]
Type=0
HeaderFile=Winsock2Doc.h
ImplementationFile=Winsock2Doc.cpp
Filter=N

[CLS:CWinsock2View]
Type=0
HeaderFile=Winsock2View.h
ImplementationFile=Winsock2View.cpp
Filter=C

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T



[CLS:CAboutDlg]
Type=0
HeaderFile=Winsock2.cpp
ImplementationFile=Winsock2.cpp
Filter=D
LastObject=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_VIEW_TOOLBAR
Command3=ID_APP_ABOUT
CommandCount=3

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_SOCK]
Type=1
Class=CVWSocket
ControlCount=26
Control1=IDC_STATIC,static,1342308352
Control2=IDC_LOCALNAME,edit,1350568064
Control3=IDC_STATIC,static,1342308352
Control4=IDC_LOCALIP,edit,1350568064
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_UDPPORT,edit,1350631552
Control8=IDC_BN_UDPRECV,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_UDPDESTIP,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_UDPDESTPORT,edit,1350631552
Control13=IDC_BN_UDPSEND,button,1342242816
Control14=IDC_BN_UDPBROADCAST,button,1342242817
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,static,1342308352
Control17=IDC_TCPPORT,edit,1350631552
Control18=IDC_BN_TCPRECV,button,1342242816
Control19=IDC_STATIC,static,1342308352
Control20=IDC_TCPDESTIP,edit,1350631552
Control21=IDC_STATIC,static,1342308352
Control22=IDC_TCPDESTPORT,edit,1350631552
Control23=IDC_BN_TCPSEND,button,1342242816
Control24=IDC_BN_TCPSENDOOB,button,1342242816
Control25=IDOK,button,1342242816
Control26=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME]
Type=1
Command1=ID_APP_ABOUT
CommandCount=1

[CLS:CVWSocket]
Type=0
HeaderFile=VWSocket.h
ImplementationFile=VWSocket.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_BN_TCPSENDOOB
VirtualFilter=VWC

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_MODELESSMESSAGE]
Type=1
ControlCount=1
Control1=IDC_MESSAGE,static,1342308353

