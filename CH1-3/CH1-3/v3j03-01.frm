VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5205
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   5205
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command3 
      Caption         =   "调用Word"
      Height          =   495
      Left            =   3480
      TabIndex        =   10
      Top             =   2280
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Replace函数"
      Height          =   495
      Left            =   1800
      TabIndex        =   9
      Top             =   2280
      Width           =   1335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "多个函数"
      Height          =   495
      Left            =   480
      TabIndex        =   8
      Top             =   2280
      Width           =   975
   End
   Begin VB.TextBox Text4 
      Height          =   495
      Left            =   1080
      TabIndex        =   7
      Top             =   1560
      Width           =   3735
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   3600
      TabIndex        =   5
      Top             =   960
      Width           =   1215
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   1080
      TabIndex        =   3
      Top             =   960
      Width           =   1095
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   1080
      TabIndex        =   1
      Text            =   "Visual Basic程序设计(第二版)"
      Top             =   240
      Width           =   3615
   End
   Begin VB.Label Label4 
      Caption         =   "结果"
      Height          =   495
      Left            =   240
      TabIndex        =   6
      Top             =   1560
      Width           =   735
   End
   Begin VB.Label Label3 
      Caption         =   "替换为"
      Height          =   375
      Left            =   2640
      TabIndex        =   4
      Top             =   960
      Width           =   735
   End
   Begin VB.Label Label2 
      Caption         =   "查找"
      Height          =   495
      Left            =   240
      TabIndex        =   2
      Top             =   960
      Width           =   615
   End
   Begin VB.Label Label1 
      Caption         =   "源字符串"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
 i = InStr(Text1, Text2)       '在Text1中查找出现Text2内容的位置
 k = i + Len(Text2)            ' 定位右子串的起始位置
 Ls = Left(Text1, i - 1)       ' 取左子串
 Text4 = Ls + Text3 + Mid(Text1, k)     '  左子串连接替换为子串连接右子串实现替换
 'Text4 = Left(Text1, i - 1) + Text3 + Mid(Text1, k)
End Sub

Private Sub Command2_Click()
 Text4 = Replace(Text1, Text2, Text3)
End Sub

Private Sub Command3_Click()
   i = Shell("C:\Program Files\Microsoft Office\OFFICE11\winword.exe", 1)
End Sub
