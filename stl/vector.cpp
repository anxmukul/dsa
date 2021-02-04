#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <int> numbers;
    numbers.push_back(3);
    cout<<numbers.size()<<endl;
    auto ptr = numbers.begin(); // returns an iterator pointing to first element in the vector
    cout<<"address of first element of vector is:- "<<&ptr<<endl;
    cout<<*ptr<<endl;
    numbers.push_back(7);
    auto ptr1 = numbers.end(); // return an iterator pointing to end of the vector not at the last element
    cout<<"address of second element of vector is:- "<<&ptr1<<endl;
    cout<<numbers.back()<<endl;
    for(auto i = numbers.begin(); i != numbers.end(); ++i){
        cout<<*i<<" ";
    }
    cout<<endl;
    vector <char> alphabets;
    for(int i=0; i<5; i++){
        alphabets.push_back(65+i);
    }
    int s = alphabets.size();
    for(int j=0; j<s; j++){
        cout<<alphabets[j]<<" ";
    }
    cout<<endl;
}