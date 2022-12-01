#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,pair<set<int>,int>>log;//log is the details of the log of resturant
    int n;
    cout<<"Enter the number of dishes in the menu"<<endl; //number of dishes in menu
    cin>>n;
    cout<<"Enter the dish ids"<<endl;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        set<int>s;
        log[p]={s,0};
    }
    //enter the diner_id and dish_id which will be saved in this log
   
    cout<<"Enter the number of diners"<<endl;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int d,f;
        cout<<"Enter the diner_id and dish_id"<<endl;
        cin>>d>>f;
        if(log[f].first.find(d)!=log[f].first.end())
        cout<<"ERROR!!!";
        else{
            int count=log[f].second;
            count++;
            set<int> st=log[f].first;
            st.insert(d);
            log[f]={st,count};
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(auto i:log)
    {
        if(pq.size()>3 && pq.top().first<i.second.second)
            pq.pop();
        else if(pq.size()<3)
            pq.push({i.second.second,i.first});
    }
    //the top 3 dish ids are(if n will be greater than 3 else it will return 0's after n ids)
    // if all the dishes are ordered once then it will return the last ordered dishes
    for(int i=0;i<min(n,3);i++)
    {
        cout<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}