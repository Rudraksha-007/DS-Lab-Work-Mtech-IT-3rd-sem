#include<bits/stdc++.h>
using namespace std;
int binary(int *arr,int l,int h,int t){//Q4 this is binary search with recursion 
    if(l>h){
        return -1;
    }
    int mid=(l+h)>>1;
    if(arr[mid]==t){
        return mid;
    }
    else if(arr[mid]>t){
        return binary(arr,l,mid-1,t);
    }else if(arr[mid]<t){
        return binary(arr,mid+1,h,t);
    }
}
//Q6
void bubble(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
            }
        }
        cout<<"pass: "<<i+1<<endl;
    }
}
void select(int *arr,int n){
    
}
int main(){
    int arr[]={1,2,16,90,21,241,21,8},n=8;
    // cout<<binary(arr,0,n-1,0);
    bubble(arr,n);
    for(int i:arr)
    {
        cout<<i<<"\t";
    }
}