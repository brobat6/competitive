#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll s=0,a[18],c=9;
        if(n<10)
            cout<<n<<endl;
        else{
            ll b=n,i=0;
            for(i=0;b>0;i++){
                a[i]=b%10;
                b/=10;
            }
            if(i==2){
                s=n/11;
                cout<<c+s<<endl;
            }
            else if(i==3){
                c=18;
                s=n/111;
                cout<<c+s<<endl;
            }
            else if(i==4){
                c=27;
                s=n/1111;
                cout<<c+s<<endl;
            }
            else if(i==5){
                c=36;
                s=n/11111;
                cout<<c+s<<endl;
            }
            else if(i==6){
                c=45;
                s=n/111111;
                cout<<c+s<<endl;
            }
            else if(i==7){
                c=54;
                s=n/1111111;
                cout<<c+s<<endl;
            }
            else if(i==8){
                c=63;
                s=n/11111111;
                cout<<c+s<<endl;
            }
            else if(i==9){
                c=72;
                s=n/111111111;
                cout<<c+s<<endl;
            }
            else if(i==10){
                c=81;
                s=n/1111111111;
                cout<<c+s<<endl;
            }
        }
    }
}