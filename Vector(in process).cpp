#include<iostream>
using namespace std;
class Vector{
    //Length of array
    int l;
    //Pointer to heap
    int* data;
    public:
    Vector& operator=(Vector v){
        delete [] data;
        l = v.l;
        data = new int [l];
        for(int i=0;i<l;i++){
            data[i] = v.data[i];
        }
        return *this;
    }
    //Constructors
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
    //Copy constructor
    Vector(const Vector & v){
        if(l != 0)
        delete [] data;
        l = v.l;
        data = new int [l];
        for(int i=0;i<l;i++){
            data[i] = v.data[i];
        }
    }
    //Destructor
    ~Vector(){
        delete [] data;
    }
    //Pointer iterators
    int *begin(){
        return &data[0];
    }
    int * end(){
        return &data[l];
    }
    int size(){
        return l;
    }
    void resize(int n,int k=0){
        if(n==l){}
        else if(n>l){
            Vector v(*this);
            delete [] data;
            l = n;
            data = new int [l];
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
    bool empty(){
        return l==0;
    }
    int& operator[](int i){
        return data[i];
    }
    
    //Modifiers
    void assign(int n){
        for(int i=0;i<l;i++){
            data[i] = n;
        }
    }
    void push_back(int n){
        this->resize(l+1,n);
    }
    void pop_back(){
        this->resize(l-1);
    }
    void insert(int k,int i){
        //i is the index where k is inserted
        this->resize(l+1);
        for(int j=l;j>=(i+1);j--){
            data[j] = data[j-1];
        }
        data[i] = k;
    }
    void erase(int i){
        for(int j=i;j<(l-1);j++){
            data[j] = data[j+1];
        }
        this->resize(l-1);
    }
    void clear(){
        delete [] data;
        data = NULL;
        l=0;
    }
    void swap(Vector v){
        Vector temp(v);
        v = (*this);
        (*this) = temp;
    }
    void print(){
        for(int i=0;i<l;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Vector v(8,3);
    v.print();
    v.resize(7,2);
    v.print();
    v.resize(10,4);
    v.print();
}
