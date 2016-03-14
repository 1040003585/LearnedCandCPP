; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSpecialButton
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Diamond.h"
LastPage=0

ClassCount=10
Class1=CDiamondApp
Class3=CChildView
Class4=CGamePlatform
Class9=CAboutDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class10=CSpecialButton
Resource2=IDD_ABOUTBOX

[CLS:CDiamondApp]
Type=0
HeaderFile=Diamond.h
ImplementationFile=Diamond.cpp
Filter=N

[CLS:CChildView]
Type=0
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp
Filter=N

[CLS:CGamePlatform]
Type=0
HeaderFile=CGamePlatform.h
ImplementationFile=CGamePlatform.cpp
Filter=W
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Diamond.cpp
ImplementationFile=Diamond.cpp
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
Class=CGamePlatform
Command1=ID_APP_EXIT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_APP_ABOUT
CommandCount=6

[ACL:IDR_MAINFRAME]
Type=1
Class=CGamePlatform
Command1=ID_EDIT_COPY
Command2=ID_EDIT_PASTE
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_CUT
Command10=ID_EDIT_UNDO
CommandCount=10

[CLS:CSpecialButton]
Type=0
HeaderFile=SpecialButton.h
ImplementationFile=SpecialButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

