; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSelectDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CatCatchRat.h"
LastPage=0

ClassCount=6
Class1=CCatCatchRatApp
Class2=CCatCatchRatDoc
Class3=CCatCatchRatView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CSelectDlg
Resource3=IDD_SELECT

[CLS:CCatCatchRatApp]
Type=0
HeaderFile=CatCatchRat.h
ImplementationFile=CatCatchRat.cpp
Filter=N

[CLS:CCatCatchRatDoc]
Type=0
HeaderFile=CatCatchRatDoc.h
ImplementationFile=CatCatchRatDoc.cpp
Filter=N

[CLS:CCatCatchRatView]
Type=0
HeaderFile=CatCatchRatView.h
ImplementationFile=CatCatchRatView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_Start


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=CatCatchRat.cpp
ImplementationFile=CatCatchRat.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_Start
Command2=ID_Stop
Command3=ID_Restart
Command4=ID_SELECT
Command5=ID_APP_ABOUT
CommandCount=5

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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_SELECT]
Type=1
Class=CSelectDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_HARD,button,1342308361
Control4=IDC_NORMAL,button,1342177289
Control5=IDC_EASY,button,1342177289
Control6=IDC_STATIC,button,1342177287
Control7=IDC_RATMAX,edit,1350631552
Control8=IDC_STATIC,static,1342308352

[CLS:CSelectDlg]
Type=0
HeaderFile=SelectDlg.h
ImplementationFile=SelectDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSelectDlg
VirtualFilter=dWC

