VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "命令按钮例"
   ClientHeight    =   3675
   ClientLeft      =   60
   ClientTop       =   390
   ClientWidth     =   5640
   LinkTopic       =   "Form1"
   ScaleHeight     =   3675
   ScaleWidth      =   5640
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command6 
      Caption         =   "结束"
      Height          =   495
      Left            =   3840
      TabIndex        =   6
      Top             =   3000
      Width           =   735
   End
   Begin VB.CommandButton Command5 
      Caption         =   "20磅"
      Height          =   375
      Left            =   3840
      TabIndex        =   5
      Top             =   2520
      Width           =   735
   End
   Begin VB.CommandButton Command4 
      Caption         =   "黑体"
      Height          =   495
      Left            =   3840
      TabIndex        =   4
      Top             =   1920
      Width           =   735
   End
   Begin VB.CommandButton Command3 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3840
      Picture         =   "v3j02-06.frx":0000
      Style           =   1  'Graphical
      TabIndex        =   3
      ToolTipText     =   "粘贴"
      Top             =   1320
      Width           =   735
   End
   Begin VB.CommandButton Command2 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3840
      Picture         =   "v3j02-06.frx":0532
      Style           =   1  'Graphical
      TabIndex        =   2
      ToolTipText     =   "复制"
      Top             =   720
      Width           =   735
   End
   Begin VB.CommandButton Command1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3840
      Picture         =   "v3j02-06.frx":0A64
      Style           =   1  'Graphical
      TabIndex        =   1
      ToolTipText     =   "剪切"
      Top             =   120
      Width           =   735
   End
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3615
      Left            =   0
      MultiLine       =   -1  'True
      TabIndex        =   0
      Text            =   "v3j02-06.frx":0F96
      Top             =   0
      Width           =   3735
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim st As String           '为复制、剪切和粘贴操作所需的模块级变量
Private Sub Command1_Click()
    st = Text1.SelText    '将选中的内容存放到st变量中
    Text1.SelText = ""    '将选中的内容清除,实现了剪切
End Sub
Private Sub Command2_Click()
     st = Text1.SelText   '将选中的内容存放到st变量中
End Sub
Private Sub Command3_Click()
     ' 将st变量中的内容插入到光标所在的位置,实现了粘贴
    Text1.SelText = st
End Sub

Private Sub Command4_Click()
  Text1.FontName = "黑体"
End Sub


Private Sub Command5_Click()
   Text1.FontSize = 20
End Sub

Private Sub Command6_Click()
   End
End Sub
