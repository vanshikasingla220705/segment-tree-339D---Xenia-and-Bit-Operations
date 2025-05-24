#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,vector<int> &arr,vector<int> &seg){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr,seg);
    build(2*ind+2,mid+1,high,arr,seg);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

void update(int ind,int low,int high,vector<int> &arr,vector<int> &seg,int i,int val){
    if(low==high){
        seg[ind]=val;
        return;
    }
    int mid=(low+high)/2;
    if(i<=mid)update(2*ind+1,low,mid,arr,seg,i,val);
    else update(2*ind+2,mid+1,high,arr,seg,i,val);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int main(){
    int n,m;
    
    cin>>n>>m;
    int size=1<<n;
    vector<int>arr(size);
    for(int i=0;i<size;i++)cin>>arr[i];
    vector<int> seg(4*size);
    bool is_or=(n%2==1);
    build(0,0,size-1,arr,seg,is_or);
    
    for(int i=0;i<m;i++){
        int p,b;
       
        cin>>p>>b;
        

        update(0,0,size-1,arr,seg,p,b);
        cout<<seg[0];
        cout<<endl;
    }
    return 0;
}