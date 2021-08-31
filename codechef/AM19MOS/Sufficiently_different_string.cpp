#include<bits/stdc++.h>
using namespace std;
void rec()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n=s.length();
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[s[i]-'a']=1;
    }
    string ans="";
    if((26 - n+ k )>=n)
    {
        int cnt=0;
        int len=0;
        for(int i=0;i<26;i++)
        {
            if(len==n)
                break;

            if(mp[i]==1)
            {
                if(cnt<k)
                {
                    cnt++;
                    ans+=(char)('a'+i);
                    len++;
                }
                else 
                {
                    continue;
                }
            }
            else 
            {
                ans+=(char)('a'+i);
                len++;
            }
        }
        cout<<ans<<endl;
    }
    else
    {
        cout<<"NOPE\n";
    }
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int i=0;i<tc;i++)
        rec();
    return 0;
}