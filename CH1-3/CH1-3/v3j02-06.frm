VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "���ť��"
   ClientHeight    =   3675
   ClientLeft      =   60
   ClientTop       =   390
   ClientWidth     =   5640
   LinkTopic       =   "Form1"
   ScaleHeight     =   3675
   ScaleWidth      =   5640
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton Command6 
      Caption         =   "����"
      Height          =   495
      Left            =   3840
      TabIndex        =   6
      Top             =   3000
      Width           =   735
   End
   Begin VB.CommandButton Command5 
      Caption         =   "20��"
      Height          =   375
      Left            =   3840
      TabIndex        =   5
      Top             =   2520
      Width           =   735
   End
   Begin VB.CommandButton Command4 
      Caption         =   "����"
      Height          =   495
      Left            =   3840
      TabIndex        =   4
      Top             =   1920
      Width           =   735
   End
   Begin VB.CommandButton Command3 
      BeginProperty Font 
         Name            =   "����"
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
      ToolTipText     =   "ճ��"
      Top             =   1320
      Width           =   735
   End
   Begin VB.CommandButton Command2 
      BeginProperty Font 
         Name            =   "����"
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
      ToolTipText     =   "����"
      Top             =   720
      Width           =   735
   End
   Begin VB.CommandButton Command1 
      BeginProperty Font 
         Name            =   "����"
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
      ToolTipText     =   "����"
      Top             =   120
      Width           =   735
   End
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "����"
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
Dim st As String           'Ϊ���ơ����к�ճ�����������ģ�鼶����
Private Sub Command1_Click()
    st = Text1.SelText    '��ѡ�е����ݴ�ŵ�st������
    Text1.SelText = ""    '��ѡ�е��������,ʵ���˼���
End Sub
Private Sub Command2_Click()
     st = Text1.SelText   '��ѡ�е����ݴ�ŵ�st������
End Sub
Private Sub Command3_Click()
     ' ��st�����е����ݲ��뵽������ڵ�λ��,ʵ����ճ��
    Text1.SelText = st
End Sub

Private Sub Command4_Click()
  Text1.FontName = "����"
End Sub


Private Sub Command5_Click()
   Text1.FontSize = 20
End Sub

Private Sub Command6_Click()
   End
End Sub
