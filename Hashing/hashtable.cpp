#include<iostream>
#include<list>
using namespace std;

class hash{
    public:
        int bucket;
        list<int> *table;
        hash(int val){
            bucket=val;
            table=new list<int>[val];
        }
        void insert(int key){
            int i=key%bucket;
            table[i].push_back(key);
        }
        void remove(int key){
            int i=key%bucket;
            table[i].remove(key);
        }
        bool search(int key){
            int i=key%bucket;
            for(auto x:table[i]){
                if(x==key) return true;
            }
            return false;
        }
};

int main(){
    hash tab(7);
    return 0;
}