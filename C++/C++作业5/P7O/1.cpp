#include<iostream>
using namespace std;
int sum_array(int array[5],int no_of_elements);
int sum_array1(int array[][2],int no_of_rows,int a);
int main()//
{
	int one_d_array[5]={0,1,2,3,4};
	int two_d_array[][2]={1,2,11,12,21,22,1,2,3,4,5,6};
	int sum=sum_array(&one_d_array[0],5);//
	cout<<sum<<endl;
	cout<<sum_array1(two_d_array,3,2)<<endl;	//
    return 0;
}
int sum_array(int array[],int no_of_elements)
{
	int total=0;
	for(int index=0;index<no_of_elements;index++)
		total+=array[index];
	return total;
}
int sum_array1(int array[][2],int no_of_rows,int a)
{
	int toatl;
	for(int row=0;row<no_of_rows;row++)
		for(int col=0;col<a;col++)
			toatl+=array[row][col];	
	return toatl;
}

