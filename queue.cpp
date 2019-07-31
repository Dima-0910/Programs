#include <iostream>
using namespace std;
class queue
{
    private:
    int *mas;
    int size,maxsize,n,k;
    public:
    queue()
    {
        maxsize=10;
        mas=new int (maxsize);
        size=0;
        n=0;
        k=0;
    }
    queue(int k)
    {
    maxsize=k;
    mas=new int[maxsize];
    size=0;
    n=0;
    k=0;
    }
    ~queue()
    {
        delete mas;
        size=0;
        maxsize=0;
        n=0;
        k=0;
        
    }
    void show()
    {
        int i,j;
        for(i=0,j=n;i<size;j=(j+1)%maxsize,i++)
        {
            cout<<mas[j]<<" ";
        }
        cout<<endl;
    }
    void put(int x)
    {
        if(size<maxsize)
        {
            mas[k]=x;
            k=(k+1)%maxsize;
            size++;
        }
        else
        {
            cout<<"queue is full"<<endl;
        }
    }
    
    void pop()
    {
        if(size>0)
        {
            size--;
            mas[n]=0;
            n=(n+1)%maxsize;
        }
        else
        {
            cout<<"queue is empty"<<endl;
        }
    }
    
    queue &operator =(const queue &b)
    {
        int i;
        maxsize=b.maxsize;
        delete mas;
        mas=new int[maxsize];
        size=b.size;
        n=b.n;
        k=b.k;
        for(i=0;i<size;i++)
        {
            mas[i]=b.mas[i];
        }
        return *this;
    }
    
    queue (const queue &b)
    {
        int i;
        maxsize=b.maxsize;
        mas=new int[maxsize];
        size=b.size;
        n=b.n;
        k=b.k;
        for(i=0;i<size;i++)
        {
            mas[i]=b.mas[i];
        }
    }
    
    queue operator +(const queue b)
    {
        queue c(maxsize+b.maxsize);
        int i,x=n,y=b.n;
        for(i=0;i<c.maxsize;i++)
        {
            if(i<size)
            {
                c.put(mas[x]);
                x=(x+1)%maxsize;
                if(i<b.size)
                {
                    c.put(b.mas[y]);
                    y=(y+1)%(b.maxsize);
                }
            }
            else if(i<b.size)
            {
                c.put(b.mas[y]);
                y=(y+1)%(b.maxsize);
            }
            else break;
        }
        return c;
    }
    
    friend ostream &operator <<(ostream &stream,queue ob);


    friend ostream &operator <<(ostream &stream, queue ob)
        {
            int i,j;
            for(i=0,j=ob.n;i<ob.size;j=(j+1)%(ob.maxsize),i++)
            {
                cout<<ob.mas[j]<<" ";
            }
            cout<<endl;
        
        return stream;
    }
};
int main()
{
    cout<<endl<<"test na elementi"<<endl;
    queue ob4;
    int i;
    for(i=0;i<5;i++)
    {
        ob4.put(i);
    }
    for(i=0;i<1000000;i++)
    {
        ob4.put(i);
        ob4.pop();
    }
    ob4.show();
    cout<<endl;
    cout<<"test udalenie i sozdanie"<<endl;
    queue* test=new queue(1000);
    for(i=0;i<1000000;i++)
    {
        delete test;
        test=new queue(1000);
        for(int j=1;j<51;j++)
        {
            test->put(i+j);
        }
    }
        test->show();
        cout<<"test na vivod"<<endl;
        cout<<ob4;
        cout<<"test na summu"<<endl;
        queue ob1,ob2;
        for(i=0;i<5;i++) ob1.put(i);
        for(i=10;i<17;i++)ob2.put(i);
        ob1.show();
        ob2.show();
        (ob1+ob2).show();
        return 0;
}
