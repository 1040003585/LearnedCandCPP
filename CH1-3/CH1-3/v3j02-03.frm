VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "颜色和对齐属性"
   ClientHeight    =   2145
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3885
   LinkTopic       =   "Form1"
   MouseIcon       =   "v3j02-03.frx":0000
   MousePointer    =   99  'Custom
   ScaleHeight     =   2145
   ScaleWidth      =   3885
   StartUpPosition =   3  '窗口缺省
   Begin VB.Image Image1 
      Height          =   480
      Left            =   3180
      Picture         =   "v3j02-03.frx":0442
      Top             =   1500
      Width           =   480
   End
   Begin VB.Label Label4 
      BackColor       =   &H0080FFFF&
      Caption         =   "前景红"
      ForeColor       =   &H000000FF&
      Height          =   735
      Left            =   1680
      TabIndex        =   4
      Top             =   1320
      Width           =   1095
   End
   Begin VB.Label Label3 
      BackColor       =   &H00FFFFFF&
      Caption         =   "背景白"
      Height          =   735
      Left            =   360
      TabIndex        =   3
      Top             =   1320
      Width           =   1095
   End
   Begin VB.Label lable1 
      AutoSize        =   -1  'True
      BorderStyle     =   1  'Fixed Single
      Caption         =   "自动"
      Height          =   240
      Left            =   3240
      TabIndex        =   2
      Top             =   240
      Width           =   420
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      BorderStyle     =   1  'Fixed Single
      Caption         =   "水平居中"
      Height          =   735
      Left            =   1680
      TabIndex        =   1
      Top             =   240
      Width           =   1095
   End
   Begin VB.Label Label1 
      BorderStyle     =   1  'Fixed Single
      Caption         =   "左对齐"
      Height          =   735
      Left            =   360
      TabIndex        =   0
      Top             =   240
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


