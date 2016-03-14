VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "数据过虑"
   ClientHeight    =   1920
   ClientLeft      =   60
   ClientTop       =   390
   ClientWidth     =   5385
   LinkTopic       =   "Form1"
   ScaleHeight     =   1920
   ScaleWidth      =   5385
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text1 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   975
   End
   Begin VB.TextBox Text3 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3360
      Locked          =   -1  'True
      TabIndex        =   2
      Top             =   360
      Width           =   1215
   End
   Begin VB.TextBox Text2 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   1800
      TabIndex        =   1
      Top             =   360
      Width           =   975
   End
   Begin VB.Label Label2 
      Caption         =   "="
      Height          =   375
      Left            =   3000
      TabIndex        =   4
      Top             =   480
      Width           =   375
   End
   Begin VB.Label Label1 
      Caption         =   "+"
      Height          =   375
      Left            =   1440
      TabIndex        =   3
      Top             =   480
      Width           =   495
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub Text1_LostFocus()
    If Not IsNumeric(Text1) Then  'IsNumeric函数判断Text1.Text的内容是否数字
      Text1 = ""                   ' 有非数字字符，清除输入Text1中的内容
      Text1.SetFocus               ' 焦点重新回到Text1，继续输入
    End If
End Sub

Private Sub Text2_KeyPress(KeyAscii As Integer)
  If KeyAscii = 13 Then         '表示按回车键输入结速
   If Not IsNumeric(Text2) Then  'IsNumeric函数判断Text1.Text的内容是否数字
      Text2 = ""                 ' 重新输入
   End If
  End If
End Sub

Private Sub Text3_GotFocus()
    Text3 = Val(Text1) + Val(Text2)
End Sub

