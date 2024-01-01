#include<iostream>
using namespace std;

class twoStacks{
    int *arr,cap,top1,top2;
    public:
        twoStacks(int n){
            cap=n;
            top1=-1;
            top2=cap;
            arr=new int[n];
        }
        void push1(int n){
            if(top1<top2-1){
                top1++;
                arr[top1]=n;
            }
            else cout<<"No capacity!"<<endl;
        }
        void push2(int n){
            if(top2>top1+1){
                top2--;
                arr[top2]=n;
            }
            else cout<<"No capacity!";
        }
        int pop1(){
            if(top1>=0){
                int x=arr[top1];
                top1--;
                return x;
            }
            else cout<<"Underflow!"; 
        }
        int pop2(){
            if(top2<cap){
                int x=arr[top2];
                top2++;
                return x;
            }
            else cout<<"Underflow";
        }
        void stop1(){
            if(top1>=0) cout<<arr[top1]<<endl;
        }
        void stop2(){
            if(top2<cap) cout<<arr[top2]<<endl;
        }
};

int main(){
    twoStacks t(6);
    t.push1(10);
    t.push1(20);
    t.push2(60);
    t.stop1();
    t.stop2();
    return 0;
}