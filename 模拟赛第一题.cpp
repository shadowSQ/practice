#include <iostream>
using namespace std;
/*输入的第一行指定用例数量T；
用例的第一行输入指定队列的最大节点数K；
用例的第二行输入指定插入的节点数量M；
用例的第三行输入指定插入的节点数值，使用空格隔开；
用例的第四行输入指定移除的节点数量N；

"node_buffer定义了一个用于存储int型数据的缓冲器，请实现其声明的所有成员方法，并满足如下要求：
1.除非调用pop_front，否则push_back成功的数据节点不可移除；
2.不可添加给定之外的数据成员和成员方法；"

*/
//Input:
//T//1
//K //8 
//M 9
// SHUZHI 1 2 3 4 5 6 7 8 9
//N 4
///utput:
//5 6 7 8
//int size();
class node_buffer
{
public:
 // 构造函数
 // 参数: max_size 指定缓冲的最大节点数
 node_buffer(int max_size){m_max_size = max_size;m_front=0;m_back=0;m_size=0;
 m_queue = new int[m_max_size+1];
 };
 // 析构函数
 ~node_buffer(){	
 	int i;
 	for(i=front();i%m_max_size<back();i++)
 	{
 		cout<<*(m_queue+i)<<" ";
 	}
	 delete m_queue;};
 // 从队尾插入一个数据节点
 // 参数：i 待插入节点
 // 返回值：true 插入成功
 //         false 插入失败，表示数据节点个数达到最大值
 bool push_back(int i);
 // 从队首移除一个数据节点
 // 返回值：true 移除成功
 //         false 移除失败，表示数据节点个数为0
 bool pop_front();
 // 获取队首节点值，不移除数据
 int front(){return m_front;
 };
 // 获取队尾节点值，不移除数据
 int back(){return m_back;
 };
 // 获取数据节点数量
 // 返回值：数据节点数量
private:
 int* m_queue;
 int  m_max_size;
 int  m_front;
 int  m_back;
 int  m_size;
};

 bool node_buffer::push_back(int i){
 	if(front()==(back()+1)%m_max_size)
 	return false;
 	
 	*(m_queue+back()) = i;
 	m_back=(m_back+1)%m_max_size;
 	m_size++;
 	return true;	
 };
 
 bool node_buffer::pop_front(){
 	if(back()==front())
 	return false;
 	
 //	*(m_queue+front())=0;
 	m_front=(m_front+1)%m_max_size;
 	m_size--;
 	return true;
 };

int main()
{
	int T,K,M,N;
	cin>>T;
	int i;
	
	while(T--)
	{
		cin>>K;
		if(K<=0)
		return 0; 
		node_buffer a(K+1);
		cin>>M;
	
		while(M--)
		{
			cin>>i;
			a.push_back(i);
		}
		cin>>N;

		while(N--)
		{
			a.pop_front();
		}
	}
	return 0;
} 
