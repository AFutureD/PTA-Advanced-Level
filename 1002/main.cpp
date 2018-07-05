#include <map>
#include <iostream>
#include<iterator>
#include <iomanip>
using namespace std;
map<int,double> da;
int main()
{
    int size;
    int tmp1;
    double tmp2;
    cin>>size;
    for(int i=0;i<size;++i)
    {
        cin>>tmp1;
        cin>>tmp2;
        da[tmp1]+=tmp2;
    }
    cin>>size;
    for(int i=0;i<size;++i)
    {
        cin>>tmp1;
        cin>>tmp2;
        da[tmp1]+=tmp2;
        if(da[tmp1]==0)
            da.erase(tmp1);
    }
    cout<<da.size();
    for(map<int,double>::reverse_iterator s=da.rbegin();s!=da.rend();++s)
    {
        cout<<fixed<<setprecision(1);
        cout<<" "<<s->first<<" "<<s->second;
    }
    cout<<endl;
    return 0;
}