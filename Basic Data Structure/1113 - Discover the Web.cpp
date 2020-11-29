#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    stack <string> beg;
    stack <string> alt;
    int n,i=1;
    string k;
    cin>>n;
   
   
    while(n--)
    {
        cin>>k;
        while(!beg.empty()){
            beg.pop();
        }
       
        while(!alt.empty()){
            alt.pop();
        }
       
       
        string url = "http://www.lightoj.com/";
        printf("Case %d:\n",i);
        i++;
        while(k!="QUIT")
        {
            if(k=="VISIT")
            {
                beg.push(url);
                cin>>url;
                cout<<url<<endl;
                while(!alt.empty()) {
                        alt.pop();
                    }
            }
           
            else if(k=="BACK")
            {
                if(beg.empty())
                    cout<<"Ignored"<<endl;
               
                else
                {
                    alt.push(url);
                    url = beg.top();
                    beg.pop();
                    cout<<url<<endl;
                }
            }
           
            else if(k=="FORWARD")
            {
                if(alt.empty())
                    cout<<"Ignored"<<endl;
               
                else
                {
                    beg.push(url);
                    url = alt.top();
                    alt.pop(); 
                    cout<<url<<endl;   
                }
            }
            cin>>k;
        }
    }
   
}
