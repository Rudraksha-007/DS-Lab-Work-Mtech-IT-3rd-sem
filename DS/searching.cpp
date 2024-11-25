#include<bits/stdc++.h>
using namespace std;
int binarySearch(int *arr,int n,int t){
    int l=0,h=n-1;
    while(l<=h){
        int mid=(l+h)>>1;
        if(arr[mid]==t){
            return mid;
        }else if(arr[mid]>t){
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return -1;
}
int bsearch(int *arr,int l,int h,int t){
    if(l>h){
        return -1;
    }
    else{
        int mid=(l+h)>>1;
        if(arr[mid]==t){
            return mid;
        }
        else if(arr[mid]>t){
            return bsearch(arr,l,mid-1,t);
        }else{
            return bsearch(arr,mid+1,h,t);
        }
    }
}
int indexSeq(int *arr,int GN,int n,int k){
    int elem[n],indices[n];
    int i=0,in=0;
    int start,end,s=0;
    for(int i=0;i<n;i+=GN){
        elem[in]=arr[i];
        indices[in]=i;
        in++;
    }
    if(k<elem[0]){
        cout<<"The element is not present in the array\n";
        return -1;
    }
    for(i=1;i<=in;i++){
        if(k<=elem[i]){
            start=indices[i-1];
            end=indices[i];
            s=1;
            break;
        }
    }
    if(s==0){
        start=indices[i-1];
        end=n-1;
    }
    for(int i=start;i<=end;i++){
        if(arr[i]==k){
            cout<<"The element was found at : "<<i<<endl;
            return i;
        }
    }
    cout<<"Not found\n";
    return -1;
}
int main(){
    int arr[]={10,30,50,60,70,80},n=6;
    // indexSeq(arr,2,n,50);
    cout<<bsearch(arr,0,n-1,50);
    return 0;
}