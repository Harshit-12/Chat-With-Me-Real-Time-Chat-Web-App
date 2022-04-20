#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while (t--)
    {
            
    long long n,s=0,ans=0,k=0,ev=0,od=0;
            cin>>n;
        long long a[n],odd=0,even=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if (a[i]%2) odd++;
            else 
            even++;
        }

        if (a[0]%2 ==0 and a[n-1]%2 ==0)
        cout<<even-1<<endl;
        else if (a[0]%2 !=0 and a[n-1]%2 !=0)
        cout<<odd-1<<endl;
        else if (a[0]%2)
        {
            if (even>odd) 
            {
            
            
            ev=0;
            for (int i=n-1; i>=0; i--)
            {
                if (a[i]%2)
                {
                    k=i;
                    break;
                }
                else
                ev++;    
            }
            cout <<odd+ev-1<<endl;
            }

            else
            {
                cout<<even<<endl;
            }

        }
        else if (a[0]%2==0)
        {
             if (even>odd) 
            {
                cout<<odd<<endl;
                
            }
            else
            {

            od=0;
            for (int i=n-1; i>=0; i--)
            {
                if (a[i]%2==0)
                    break;
                else
                od++;   
            }
            cout <<even+od-1<<endl;
            }
        }
        else
            cout<<min(even,odd)<<endl;

        

    }

    return 0;
}