#include <iostream>
using namespace std;
#include <stdio.h>
double counttime = 0;
double countpettime = 0;
int handle_data_func(double M,double N,double X,int &T1)
{
	double nowsize = 0;
	counttime = 0;
	countpettime = 0;
	double a = 0.8*X;
	double b = 0.6*X;
	int cha = M-N;

		counttime+=a/cha;
		counttime+=(a - b)/N;

countpettime = (a-b)/cha+(a-b)/N;

}
 
int main(){
	int T;
	cin>>T;
	while(T)
	{
		double M,N,X;
		cin>>M>>N;
		cin>>X;
		handle_data_func(M,N,X,T);
		
		T--;
			printf("%.2f\n",counttime);
	printf("%.2f",countpettime);
	} 

}
