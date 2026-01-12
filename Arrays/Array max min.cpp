#include<simplecpp>

void print(int arr [10]){
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}

main_program{
    int arr[10];int max;
    srand(10);
    for(int i=0;i<10;i++){
        arr[i] = rand()*100.0/RAND_MAX;
    }
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            if(arr[j]>arr[i]){
                max = arr[j];
            }
        }
    }
    cout<<"Array: ";print(arr);
    cout<<endl;
    cout<<"Maximun value is: "<<max<<endl;
    for(int i=0;i<10;i++){
        if(arr[i]<max){
            max  = arr[i];
        }
    }
    cout<<"Minimun value is: "<<max<<endl;
}



