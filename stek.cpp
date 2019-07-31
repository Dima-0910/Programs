#include <iostream>
using namespace std;
class stack
{
	private:
	int *mas;
	int maxsize=10;
	int size;
	public:
	stack()
	{
		mas=new int[maxsize];
		size=0;
	}
	stack(int kol)
	{
		maxsize=kol;
		mas=new int[maxsize]; 
		size=0;
	}
	~stack()
	{
		delete mas;
	}
	void put(int x)
	{
		if(size<maxsize)
		{
			mas[size]=x;
			size++;
		}
		else
		{
			 cout<<"stack is full"<<endl;
		}
		
	}
	void show()
	{
		int i;
		for(i=0;i<size;i++)           
		{
			cout<<mas[i]<<" ";
		}
		cout<<endl;
	}
	void pop()
	{
		if(size>0)
		{
			size--;
			mas[size]=0;
		}
		else
		{
			cout<<"stack is empty"<<endl;
		}
	}
	void del()
	{
		int i;
		if(size==0)
		{
			cout<<"nothing";
			return;
		}
		for(i=0;i<size-1;i++)
		{
			mas[i]=mas[i+1];
		}
		size--;
		cout<<"SIZE = "<<size<<endl;
	}			
};
int main()
{
	stack ob;
	int i;
	for(i=1;i<12;i++)
	{
		ob.put(i);
		ob.show();
	}
	for(i=0;i<11;i++)
	{
		ob.pop();
		ob.show();
	}
	for(i=1;i<12;i++)
	{
		ob.put(i);
		ob.show();
	}
	for(i=0;i<11;i++)
	{
		ob.del();
		ob.show();
	}
	return 0;
}
