VERSION 5.00
Begin VB.Form Form1 
   AutoRedraw      =   -1  'True
   Caption         =   "Form1"
   ClientHeight    =   3780
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   3945
   DrawStyle       =   5  'Transparent
   FillStyle       =   0  'Solid
   BeginProperty Font 
      Name            =   "����"
      Size            =   36
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3780
   ScaleWidth      =   3945
   StartUpPosition =   2  '��Ļ����
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Click()
   Caption = "�������壬�ı�ͼƬ"
   Picture = LoadPicture(App.Path + "\Tongji.bmp")
   Print "��ӭʹ��VB"
End Sub

Private Sub Form_DblClick()
   Cls
   Caption = "˫�����壬жȥͼƬ"
   Picture = LoadPicture("")   '
End Sub

Private Sub Form_Load()
   Caption = "װ�봰��"
   Picture = LoadPicture(App.Path + "\Tongji-2.bmp")
   Print "װ��ͼ"
End Sub

Private Sub Form_Resize()     ' ���¼������ô���ʼ����ͼһ����
'  Caption = "�����С����"
'  Form1.Width = 260 * 16       ' 260��Tongji-2.bmpͼ�Ŀ�ȣ����ص�λ
'  Form1.Height = 260 * 16 + 200  ' 260��ͼ�ĸ߶ȣ����ص�λ��200�Ǵ���ı������߶�
End Sub
