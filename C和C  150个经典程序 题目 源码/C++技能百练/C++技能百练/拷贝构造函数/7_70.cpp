#include<iostream.h>
class point
{
public:
	point(int x,int y) {X=x,Y=y;cout<<"Constructor called!"<<endl;}
	point(point &p);
	~point() {cout<<"Destructor called"<<endl;}
	int getX(){return X;}
	int getY(){return Y;}
private:
	int X,Y;
};
point::point(point &p)
{
	X=p.X;
	Y=p.Y;
	cout<<"Copy-initialization Constructor called!"<<endl;
}
point fun(point A)
{
	cout<<"The function of \'fun\' is called!"<<endl;
	int x=A.getX()+5;
	int y=A.getY()+10;
	point R(x,y);
	return R;
}
void main()
{
	point M(6,7),P(0,0),S(0,0);
	point N(M);
	P=fun(N);
	S=M;
	cout<<"P="<<P.getX()<<","<<P.getY()<<endl;
    cout<<"S="<<S.getX()<<","<<S.getY()<<endl;
}
