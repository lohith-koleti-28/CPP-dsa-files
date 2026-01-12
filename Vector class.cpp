#include<iostream>
using namespace std;
class Vector{
    int l;
    int* data;
    public:
    Vector& operator=(Vector &v){
        if(l != 0)
        delete [] data;
        l = v.l;
        data = new int[l];
        for(int i=0;i<l;i++){
            data[i] = v.data[i];
        }
        return *this;
    }
    Vector(int n=0,int k=0){
        if(n==0){
            data = NULL;
            l = 0;
        }
        else{
            data = new int[n];
            l = n;
            for(int i=0;i<n;i++){
                data[i] = k;
            }
        }
    }
    Vector(const Vector & v){
        l = v.l;
        data = new int [l];
        for(int i=0;i<l;i++){
            data[i] = v.data[i];
        }
    }
    ~Vector(){
        delete [] data;
    }

    int* begin(){
        return &data[0];
    }
    int *end(){
        return &data[l];
    }
    bool empty(){
        return l==0;
    }
    int& operator[](int i){
        return data[i];
    }
    void assign(int n){
        for(int i=0;i<l;i++){
            data[i] = n;
        }
    }
    void insert(int val,int pos){
        this->resize(l+1);
        for(int i=(l-1);i>pos;i--){
            data[i] = data[i-1];
        }
        data[pos] = val;
    }
    void erase(int pos){
        for(int i=pos;i<(l-1);i++){
            data[i] = data[i+1];
        }
        this->resize(l-1);
    }
    void print(){
        for(int i=0;i<l;i++)cout<<data[i]<<" ";
        cout<<endl;
    }
    int size(){
        return l;
    }
    void resize (int n,int k=0){
        if(n==l){}
        else if(n>l){
            Vector v(*this);
            delete [] data;
            l = n;
            data = new int[n];
            for(int i=0;i<v.l;i++){
                data[i] = v.data[i];
            }
            for(int i=v.l;i<l;i++){
                data[i] = k;
            }
        }
        else if(n<l){
            Vector v(*this);
            delete [] data;
            l = n;
            data = new int[l];
            for(int i=0;i<l;i++){
                data[i] = v.data[i];
            }
        }
    }
    void clear(){
        l=0;
        delete [] data;
        data = NULL;
    }
    void swap(Vector &v){
        Vector temp(v);
        v = *this;
        *this = temp;
    }
    void push_back(int n){
        this->resize(l+1,n);
    }
    void pop_back(){
        this->resize(l-1);
    }
};
int main(){
    Vector v;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int t; cin >> t;
        v.push_back(t);
    }
    cout<<"Size is: "<<v.size()<<endl;
    v.print();
}