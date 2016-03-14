//Download by http://www.NewXing.com
// GameDiamond.h: interface for the CGameDiamond class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEDIAMOND_H__B5380B41_D667_4EEC_99FE_B7B4E14C8E65__INCLUDED_)
#define AFX_GAMEDIAMOND_H__B5380B41_D667_4EEC_99FE_B7B4E14C8E65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<vector>
#define KINDSOFDIAMOND 7
 
struct DIAMOND
{
  	std::vector<short int> Pos;
	int nPosX,nPosY;
    DIAMOND():nPosX(GAME_ZONE_WIDTH / 2 - 2),nPosY(0){
		Pos.resize(4,0);
	 }
	operator= (DIAMOND diamond)
	{
		Pos[0] = diamond.Pos[0];
		Pos[1] = diamond.Pos[1];
		Pos[2] = diamond.Pos[2];
		Pos[3] = diamond.Pos[3];
		nPosX = diamond.nPosX;
		nPosY = diamond.nPosY;
	}
};
class CGameDiamond  
{
public:
	void SetCurrentDiamondPos(int PosX,int PosY);
	CPoint CalcIndex(short int nPos);
	void SetCurDiamond(DIAMOND diamond);
	DIAMOND GetNextDiamond();
	DIAMOND GetCurDiamond();
	DIAMOND CreateDiamond();
	DIAMOND ChangePos(DIAMOND diamond);

	CGameDiamond();
	virtual ~CGameDiamond();


protected:
	DIAMOND CurDiamond;
	DIAMOND NextDiamond;
	static std::vector<DIAMOND> StockDiamond;
    static std::vector<DIAMOND> InitialStockDiamond();

};

#endif // !defined(AFX_GAMEDIAMOND_H__B5380B41_D667_4EEC_99FE_B7B4E14C8E65__INCLUDED_)
