; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGameView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Game.h"
LastPage=0

ClassCount=6
Class1=CGameApp
Class2=CGameDoc
Class3=CGameView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CLeval
Resource3=IDD_DIALOG1

[CLS:CGameApp]
Type=0
HeaderFile=Game.h
ImplementationFile=Game.cpp
Filter=N

[CLS:CGameDoc]
Type=0
HeaderFile=GameDoc.h
ImplementationFile=GameDoc.cpp
Filter=N

[CLS:CGameView]
Type=0
HeaderFile=GameView.h
ImplementationFile=GameView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CGameView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDC_MUSIC




[CLS:CAboutDlg]
Type=0
HeaderFile=Game.cpp
ImplementationFile=Game.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDM_GAMESTART
Command2=IDM_GAMESTOP
Command3=ID_LEVAL
CommandCount=3

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=IDM_GAMESTART
Command2=IDM_GAMESTOP
CommandCount=2

[DLG:IDD_DIALOG1]
Type=1
Class=CLeval
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LEVAL,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CLeval]
Type=0
HeaderFile=Leval.h
ImplementationFile=Leval.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LEVAL
VirtualFilter=dWC

