VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "���ݹ���"
   ClientHeight    =   1920
   ClientLeft      =   60
   ClientTop       =   390
   ClientWidth     =   5385
   LinkTopic       =   "Form1"
   ScaleHeight     =   1920
   ScaleWidth      =   5385
   StartUpPosition =   3  '����ȱʡ
   Begin VB.TextBox Text1 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      BeginProperty Font 
         Name            =   "����"
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
         Name            =   "����"
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
         Name            =   "����"
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
    If Not IsNumeric(Text1) Then  'IsNumeric�����ж�Text1.Text�������Ƿ�����
      Text1 = ""                   ' �з������ַ����������Text1�е�����
      Text1.SetFocus               ' �������»ص�Text1����������
    End If
End Sub

Private Sub Text2_KeyPress(KeyAscii As Integer)
  If KeyAscii = 13 Then         '��ʾ���س����������
   If Not IsNumeric(Text2) Then  'IsNumeric�����ж�Text1.Text�������Ƿ�����
      Text2 = ""                 ' ��������
   End If
  End If
End Sub

Private Sub Text3_GotFocus()
    Text3 = Val(Text1) + Val(Text2)
End Sub

