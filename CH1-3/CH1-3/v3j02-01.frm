VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Font��������"
   ClientHeight    =   2895
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4815
   BeginProperty Font 
      Name            =   "����"
      Size            =   14.25
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   2895
   ScaleWidth      =   4815
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton Command2 
      Caption         =   "command2"
      BeginProperty Font 
         Name            =   "����"
         Size            =   15.75
         Charset         =   134
         Weight          =   700
         Underline       =   -1  'True
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   600
      TabIndex        =   1
      Top             =   1080
      Width           =   2355
   End
   Begin VB.CommandButton Command1 
      Caption         =   "command1"
      BeginProperty Font 
         Name            =   "����"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   600
      TabIndex        =   0
      Top             =   240
      Width           =   2355
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command2_Click()
    i = InputBox("�������ָ����״ 0-15")
    Form1.MousePointer = i
End Sub

Private Sub Form_Click()
    Command1.Caption = "��ʾ1"
    Command1.FontName = "����"
    Command1.FontSize = 20
    Command1.FontBold = True
    Command1.FontItalic = True
    Command1.FontUnderline = True ' ���»���
    Command1.Enabled = False  ' �ʰ���ɫ
    Command2.FontName = "����"
    Command2.Enabled = True
    Command2.Caption = "���ָ����״"
End Sub

