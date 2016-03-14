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
      Name            =   "隶书"
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
   StartUpPosition =   2  '屏幕中心
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Click()
   Caption = "单击窗体，改变图片"
   Picture = LoadPicture(App.Path + "\Tongji.bmp")
   Print "欢迎使用VB"
End Sub

Private Sub Form_DblClick()
   Cls
   Caption = "双击窗体，卸去图片"
   Picture = LoadPicture("")   '
End Sub

Private Sub Form_Load()
   Caption = "装入窗体"
   Picture = LoadPicture(App.Path + "\Tongji-2.bmp")
   Print "装入图"
End Sub

Private Sub Form_Resize()     ' 该事件的作用窗体始终与图一样大
'  Caption = "窗体大小不变"
'  Form1.Width = 260 * 16       ' 260是Tongji-2.bmp图的宽度，象素单位
'  Form1.Height = 260 * 16 + 200  ' 260是图的高度，象素单位，200是窗体的标题栏高度
End Sub
