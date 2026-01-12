#include<iostream>
using namespace std;
int length(char* s){
    int i;
    for(i=0;;i++){
        if(s[i] == '\0'){
            break;
        }
    }
    return i;
}
char* strrchr(char*s , char c){
    int l = length(s);
    for(int i=(l-1);i>=0;i--){
        if(s[i] == c){
            return &s[i];
        }
    }
    return NULL;
}
char* strstr(char*s , char c[]){
    bool found;
    for(int i=0;i<=(length(s)- length(c));i++){
        for(int j=0;j<length(c);j++){
            if(s[j+i] != c[j]){
                found = false;
                break;
            }
        }
        if(found) return &s[i];
        found = true;
    }
    return NULL;
}
char* strncpy(char* src,char* dest , int n){
    bool check = length(src)>n;
    if(check){
        for(int i=0;i<(n-1);i++){
            dest[i] = src[i];
        }
        dest[n] = '\0';
    }
    else{
        for(int i=0;i<length(src);i++){
            dest[i] = src[i];
        }
    }
    return dest;
}
char* strcat(char* dest , char* src){
    int l= length(dest);
    for(int i = l;i<=(l + length(src));i++){
        dest[i] = src[i-l];
    }
    return dest;
}
int strcmp(char*a , char*b){
    //0 if same 1 if a>b and -1 if a<b
    for(int i=0;;i++){
        if(a[i] == '\0' && b[i] == '\0') return 0;
        if(a[i] == '\0') return -1;
        if(b[i] == '\0') return 1;
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return -1;
    }
}
int strncmp(char*a , char*b,int n){
    //0 if same 1 if a>b and -1 if a<b
    for(int i=0;i<n;i++){
        if(a[i] == '\0' && b[i] == '\0') return 0;
        if(a[i] == '\0') return -1;
        if(b[i] == '\0') return 1;
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return -1;
    }
    return 0;
}
int main(){
    char c[] = "Good Morning";
    char b[40] = "Good Night";
    cout<<strncmp(b,c,6)<<endl;
}