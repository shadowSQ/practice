#include <iostream>
using namespace std;
#include <stdio.h>
//测试用例 
/*
有一种特殊的正整数（int类型），将数分为两侧，每侧至少有一位数，
两侧的每个数字相加相等，请写出判断的方法用来检测是否这种数。
比如：1236,可以拆分为123和6。
2
1232145
4543622

1
1
*/

bool is_magicnum(int number)
{
	if(number<10)
	{
		cout<<"error input"<<endl;
		return 0;
	}
	
	int poi[32];
	int front = 0;
	while(number>0)
	{
		poi[front]=number%10;
	//	cout<<number%10<<endl;
		number /= 10;
		front++;
	}
	int i,j;
	int sumfront=0,sumback=0;
	
	for(i=0;i<=front;i++)
	{
		sumfront=0; 
		sumback=0;
		for(j=0;j<=i;j++)
		{
			sumfront +=poi[j];
		}
		for(j=i+1;j<front;j++)
		{
			sumback +=poi[j];
		}
	//	cout<<sumfront<<endl;
	//	cout<<sumback<<endl;
		if(sumfront==sumback)
		return true;
	}
	return false;
	
}

int main()
{
	int T;
	scanf("%d",&T);
	int tempT=T;
	int i = 0;
	int number[T]; 
	while(tempT--)
	{
	scanf("%d",&number[i]);
	i++;
	}
	for(i=0;i<T;i++)
printf("%d\n",is_magicnum(number[i]));
}
