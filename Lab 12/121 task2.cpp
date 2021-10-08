#include<iostream>
#include<algorithm>
using namespace std;

template<class T> T amax(T arr[], int size, int n) {
    T temp[size];
    for(int i=0; i<size; i++){
        temp[i] = arr[i];
    }
    sort(temp, temp+size);
    return temp[size-n];
}

int main() {

    int iarr[5] = {23, 54, 2, 6, 66};
    cout<<amax(iarr, 5, 4)<<endl;

    float farr[5] = {0.6, 4.65, 5.77, 3.54, 66.65};
    cout<<amax(farr, 5, 2);


}
