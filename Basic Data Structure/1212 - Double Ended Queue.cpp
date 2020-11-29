#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i,t,x,k,l,q=1;
    string s;
    cin>>t;
    while(t--)
    {
        //int a[10001];
        //k=0;l=0;
       
        cin>>n>>m;
        deque<int>d;
        cout<<"Case "<<q++<<":"<<endl;
        //int p=n;
        while(m--)
        {
           
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>x;
                if(d.size()==n)
                {
                    cout <<"The queue is full"<<endl;
                }
                else
                {
                    cout<<"Pushed in left: " <<x<<endl;
                    d.push_front(x);
                }
               
            }
            else if(s=="pushRight")
            {
                cin>>x;
                if(d.size()==n)
                {
                    cout << "The queue is full"<<endl;
                }
                else
                {
                    cout<<"Pushed in right: " <<x<<endl;
                    d.push_back(x);
                }
               
            }
            else if(s=="popLeft")
            {
           
                if(d.size()==0)
                {
                    cout<<"The queue is empty"<<endl;
                }
                else
                {
                    cout<<"Popped from left: "<<d.front()<<endl;
                    d.pop_front();
                }
               
            }
            else if(s=="popRight")
            {
                if(d.size()==0)
                {
                    cout<<"The queue is empty"<<endl;
                }
                else
                {
                    cout<<"Popped from right: "<<d.back()<<endl;
                    d.pop_back();
                }
               
               
            }
        }
    }
}
