VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "人民币与美元兑换"
   ClientHeight    =   2070
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   2070
   ScaleWidth      =   4680
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command4 
      Caption         =   "结束"
      Height          =   495
      Left            =   3360
      TabIndex        =   7
      Top             =   1440
      Width           =   735
   End
   Begin VB.CommandButton Command3 
      Caption         =   "￥←＄"
      Height          =   495
      Left            =   2280
      TabIndex        =   6
      Top             =   1440
      Width           =   855
   End
   Begin VB.CommandButton Command2 
      Caption         =   "￥→＄"
      Height          =   495
      Left            =   1200
      TabIndex        =   5
      Top             =   1440
      Width           =   855
   End
   Begin VB.CommandButton Command1 
      Caption         =   "清屏"
      Height          =   495
      Left            =   240
      TabIndex        =   4
      Top             =   1440
      Width           =   735
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   3120
      TabIndex        =   3
      Top             =   720
      Width           =   975
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   1560
      TabIndex        =   2
      Top             =   720
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   240
      TabIndex        =   1
      Top             =   720
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "人民币       兑换比率          美元   "
      Height          =   375
      Left            =   360
      TabIndex        =   0
      Top             =   240
      Width           =   3735
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Text1 = ""
  Text2 = ""
  Text3 = ""
End Sub

Private Sub Command2_Click()
  Text3 = Val(Text1) / Val(Text2)
End Sub

Private Sub Command3_Click()
  Text1 = Val(Text3) * Val(Text2)
End Sub

Private Sub Command4_Click()
  End
End Sub
