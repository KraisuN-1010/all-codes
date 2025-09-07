#include<bits/stdc++.h>
using namespace std;
int squareRoot(int num){
    int low=1;
    int high=num;
    int ans;
    while(low<=high){
        int mid=(high+low)/2;
        if((mid*mid)==num) return mid;
        else if(mid*mid>num) high=mid-1;
        else if(mid*mid<=num){
            ans=mid;
            low=mid+1;
        }

    }
    return ans;
}
int main(){
    int num;
    cout<<"Enter a num:";
    cin>>num;
    int root=squareRoot(num);
    cout<<"The square root of "<<num<<" is: "<<root;
}