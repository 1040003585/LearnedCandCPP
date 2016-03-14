VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00FFFFFF&
   Caption         =   "简单动画例"
   ClientHeight    =   3660
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5340
   LinkTopic       =   "Form1"
   Picture         =   "v3j01-01.frx":0000
   ScaleHeight     =   3660
   ScaleWidth      =   5340
   StartUpPosition =   2  '屏幕中心
   Begin VB.CommandButton Command2 
      Height          =   495
      Left            =   2760
      Picture         =   "v3j01-01.frx":6F75
      Style           =   1  'Graphical
      TabIndex        =   1
      ToolTipText     =   "自动"
      Top             =   3000
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Height          =   495
      Left            =   3840
      Picture         =   "v3j01-01.frx":73B7
      Style           =   1  'Graphical
      TabIndex        =   0
      ToolTipText     =   "手动"
      Top             =   3000
      Width           =   1095
   End
   Begin VB.Timer Timer1 
      Interval        =   100
      Left            =   2160
      Top             =   2520
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "欢迎使用VB"
      BeginProperty Font 
         Name            =   "隶书"
         Size            =   26.25
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   525
      Left            =   1320
      TabIndex        =   2
      Top             =   720
      Width           =   2805
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Form_Load()
    Timer1.Interval = 0
End Sub

Private Sub Command1_Click()   '手动
    Timer1.Interval = 0
   Call MyMove
End Sub

Private Sub Command2_Click()  '自动
  Timer1.Interval = 200
End Sub
Private Sub Timer1_Timer()
    Call MyMove
End Sub
Sub MyMove()
   Label1.Move Label1.Left, Label1.Top + 50
   If Label1.Top > Form1.Height Then Label1.Top = 0
End Sub
