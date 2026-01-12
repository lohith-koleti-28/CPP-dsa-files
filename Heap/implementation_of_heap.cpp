#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    public:

    Heap(int size = 0){
        v = vector<int> (size + 1);
    }

    void insert(int x){

        v.push_back(x);
        int idx = v.size()-1;
        while(idx > 0){
            int par = idx/2;
            if(v[par] < v[idx]){
                swap(v[idx],v[par]);
                idx = par;
            }
        }
    }

    void display(){
        int ch = 0, mult = 1;
        for(int i=1;i<v.size();i++){
            ch++;
            cout << v[i] << " ";
            if(ch == mult){
                mult *= 2;
                ch = 0;
                cout<<endl;
            }
        }
    }
};

int main(){

    Heap h;
    h.display();
    h.insert(56);
    h.display();
}