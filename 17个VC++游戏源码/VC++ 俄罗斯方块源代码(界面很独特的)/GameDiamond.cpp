// GameDiamond.cpp: implementation of the CGameDiamond class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Diamond.h"
#include "GameDiamond.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//
std::vector<DIAMOND> CGameDiamond::StockDiamond = CGameDiamond::InitialStockDiamond();
//

std::vector<DIAMOND> CGameDiamond::InitialStockDiamond()
{
    std::vector<DIAMOND> vt;
	vt.resize(KINDSOFDIAMOND);
	vt[0].Pos[0] = 1; vt[0].Pos[1] = 8; vt[0].Pos[2] = 12; vt[0].Pos[3] = 15; 
   	vt[1].Pos[0] = 1; vt[1].Pos[1] = 2; vt[1].Pos[2] = 12; vt[1].Pos[3] = 15; 
    vt[2].Pos[0] = 1; vt[2].Pos[1] = 2; vt[2].Pos[2] = 13; vt[2].Pos[3] = 14; 
    vt[3].Pos[0] = 1; vt[3].Pos[1] = 12;vt[3].Pos[2] = 13; vt[3].Pos[3] = 14; 
    vt[4].Pos[0] = 2; vt[4].Pos[1] = 12;vt[4].Pos[2] = 13; vt[4].Pos[3] = 15; 
    vt[5].Pos[0] = 1; vt[5].Pos[1] = 12;vt[5].Pos[2] = 13; vt[5].Pos[3] = 15; 
	vt[6].Pos[0] = 12;vt[6].Pos[1] = 13;vt[6].Pos[2] = 14; vt[6].Pos[3] = 15; 
	vt[0].nPosX = vt[1].nPosX = vt[2].nPosX = vt[3].nPosX = vt[4].nPosX = vt[5].nPosX = vt[6].nPosX = GAME_ZONE_WIDTH / 2 - 2;
	vt[0].nPosY = vt[1].nPosY = vt[2].nPosY = vt[3].nPosY = vt[4].nPosY = vt[5].nPosY = vt[6].nPosY = 0;
	return vt;
}

CGameDiamond::CGameDiamond()
{
   NextDiamond = StockDiamond[rand()%7];
}

CGameDiamond::~CGameDiamond()
{

}

DIAMOND CGameDiamond::CreateDiamond()
{
	CurDiamond =  NextDiamond;
	NextDiamond = StockDiamond[rand() % KINDSOFDIAMOND];
  	return CurDiamond;
}

DIAMOND CGameDiamond::GetCurDiamond()
{
	return CurDiamond;
}

DIAMOND CGameDiamond::GetNextDiamond()
{
	return NextDiamond;

}
void CGameDiamond::SetCurDiamond(DIAMOND diamond)
{
	CurDiamond = diamond;
}
DIAMOND CGameDiamond::ChangePos(DIAMOND diamond)
{
    diamond.Pos[0] = (diamond.Pos[0] < 12) ? (diamond.Pos[0] + 3) % 12 : (diamond.Pos[0] - 12 + 1) % 4 + 12;
	diamond.Pos[1] = (diamond.Pos[1] < 12) ? (diamond.Pos[1] + 3) % 12 : (diamond.Pos[1] - 12 + 1) % 4 + 12;
 	diamond.Pos[2] = (diamond.Pos[2] < 12) ? (diamond.Pos[2] + 3) % 12 : (diamond.Pos[2] - 12 + 1) % 4 + 12;
	diamond.Pos[3] = (diamond.Pos[3] < 12) ? (diamond.Pos[3] + 3) % 12 : (diamond.Pos[3] - 12 + 1) % 4 + 12;
	return diamond;
}

CPoint CGameDiamond::CalcIndex(short int nPos)
{
	CPoint ptIndex;
 	switch(nPos) 
	{
	case 0:   ptIndex.x = 0; ptIndex.y = 0; break;
	case 1:   ptIndex.x = 1; ptIndex.y = 0; break;
	case 2:   ptIndex.x = 2; ptIndex.y = 0; break;
	case 3:   ptIndex.x = 3; ptIndex.y = 0; break;
	case 4:   ptIndex.x = 3; ptIndex.y = 1; break;
	case 5:   ptIndex.x = 3; ptIndex.y = 2; break;
	case 6:   ptIndex.x = 3; ptIndex.y = 3; break;
	case 7:   ptIndex.x = 2; ptIndex.y = 3; break;
	case 8:   ptIndex.x = 1; ptIndex.y = 3; break;
	case 9:   ptIndex.x = 0; ptIndex.y = 3; break;
	case 10:  ptIndex.x = 0; ptIndex.y = 2; break;
	case 11:  ptIndex.x = 0; ptIndex.y = 1; break;
	case 12:  ptIndex.x = 1; ptIndex.y = 1; break;
	case 13:  ptIndex.x = 2; ptIndex.y = 1; break;
	case 14:  ptIndex.x = 2; ptIndex.y = 2; break;
	case 15:  ptIndex.x = 1; ptIndex.y = 2; break;
	default:  break;
	}
	return ptIndex;
}

void CGameDiamond::SetCurrentDiamondPos(int PosX, int PosY)
{
	CurDiamond.nPosX = PosX;
	CurDiamond.nPosY = PosY;
}
