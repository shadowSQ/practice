#include <iostream>
using namespace std;
#include <stdio.h>

int total=0;
int flag=0;
struct Cages{
	int cages[100];
	int size;
};

void push(int t,Cages &cage)
{
	int i ;
	for(i=0;i<cage.size;i++)
	{
		if(cage.cages[i]==t)
		return; 	
	}
	cage.cages[cage.size] = t;
	cage.size++;
}
bool initcages(Cages &cage)
{
	cage.size = 0;
}
int getsize(Cages &cage)
{
	return cage.size;
}
//遍历相加 
void turncage(int *pnum,int *price,int N,int dfsnum,int total,Cages &cage,int temp)
{
	int i;
	if(dfsnum>=N)
	{
	push(total,cage);
	flag = 1;
//	cout<<"total:"<<total<<endl;
	return;
	}
	for(i=0;i<=pnum[dfsnum];i++)
	{
		if(flag == 1)
		{
			total -= temp;
			flag = 0;
		}
		
		total += price[dfsnum]*i;
		temp = price[dfsnum]*i;
		turncage(pnum,price,N,dfsnum+1,total,cage,temp);
	}
	
} 

int main(){
	int T;
	int M,N,V;
	int *pnum,*price;
	int i,j;
	
	cin>>T;
	Cages cage1;
	initcages(cage1);
	while(T--)
	{
		cin>>N;
		//输入每种股票价格 
		price = new int[N];
		for(i=0;i<N;i++)
		cin>>price[i];
		//打印看看是否有出现错误 
	//	for(i=0;i<N;i++)
	//	cout<<*(price+i);
		
		//输入每种股票的个数 
		pnum = new int[N];
		for(i=0;i<N;i++)
		cin>>*(pnum+i);
		
		turncage(pnum,price,N,0,total,cage1,0);
		cout<<cage1.size;
	}
		

}
