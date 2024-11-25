#include<bits/stdc++.h>
using namespace std;
struct bucket{
    int*brr;
    bucket(){
        brr=new int[10];
        for(int i=0;i<10;i++)
        {
            brr[i]=0;
        }
    }
};
void subroute(int *arr,int n,int exp){
    bucket b1;
    int out[n];
    for(int i=0;i<n;i++){
        b1.brr[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        b1.brr[i]+=b1.brr[i-1];
    }
    for(int i=n-1;i>=0;i--){
        out[b1.brr[(arr[i]/exp)%10]-1]=arr[i];
        b1.brr[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=out[i];
    }
}
void radix_sort(int *arr,int n){
    int m=*max_element(arr,arr+n);
    for(int e=1;m/e>0;e*=10){
        subroute(arr,n,e);
    }
}
void bubble(int*arr,int n){
    bool swapped=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
                swapped=true;
            }
        }
        if(swapped==false){
            return;
        }
    }
}
void select(int *arr,int n){
    int i;
    for( i=0;i<n;i++){
        int m=i;
        bool sor=true;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[m]){
                m=j;
                sor=false;
            }
            if(arr[j-1]>arr[j]){
                sor=false;
            }
        }
        swap(arr[i],arr[m]);
        if(sor){
            //already sorted 
            cout<<"just took a early exit\n";
            cout<<"total passes="<<i<<endl;// in case we exit early 
            return;
        }
        sor=true;
    }
    cout<<"total passes="<<i<<endl;
}
void insert(int *arr,int n){
    for(int i=0;i<n;i++){
        int key=arr[i],j=i-1;
        while(j>=0 and arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void merge(int*arr,int l,int m,int h){
    int n1=m-l+1,n2=h-m;
    int left[n1],right[n2];
    int i=0,j=0;
    for(int i=0;i<n1;i++){
        left[i]=arr[i+l];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[m+i+1];
    }
    int k=l;
    while(i<n1 and j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k++]=left[i++];
    }
    while(j<n2){
        arr[k++]=right[j++];
    }
}
void mergesort(int *arr,int l,int h){
    if(l<h){
        int mid=(l+h)>>1;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int part(int *arr,int l,int h){
    int i=l-1,pivot=arr[h];
    for(int j=l;j<h;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
void quick(int *arr,int l,int h){
    if(l<h){
        int p=part(arr,l,h);
        quick(arr,l,p-1);
        quick(arr,p+1,h);
    }
}
void count(int *arr,int n,int e){
    int out[n];
    int i,count[10]={0};
    for(int i=0;i<n;i++){
        count[(arr[i]/e)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        out[count[(arr[i]/e)%10]-1]=arr[i];
        count[(arr[i]/e)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=out[i];
    }
}
int max(int*arr,int n){
    int c=0;
    for(int i=0;i<n;i++){
        c=max(arr[i],c);
    }
    return c;
}
void radix(int *arr,int n){
    int m=max(arr,n);
    for(int e=1;m/e>0;e*=10){
        count(arr,n,e);
    }
}
void create(int*arr,int n){
    int p,c,i;
    for(i=2;i<=n;i++){
        c=i;
        p=c>>1;
        while(p>0 and arr[c]>arr[p]){
            swap(arr[c],arr[p]);
            c=p;
            p=c>>1;
        }
    }
}
void heapsort(int *arr,int n){
    while(n>1){
        create(arr,n);
        swap(arr[1],arr[n]);
        n--;
    }
}
int main(){
    int arr[]={10,20,30,40,50,60},n=6;
    reverse(arr,arr+n);
    // bubble(arr,n);
    // select(arr,n);
    // insert(arr,n);
    mergesort(arr,0,n);
    // quick(arr,0,n);
    // radix(arr,n);
    // radix_sort(arr,n);
    // heapsort(arr,n-1);
    for(int i:arr){
        cout<<i<<"\t";
    }
    return 0;
}