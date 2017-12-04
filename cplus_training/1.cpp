#include<iostream>
using namespace std;
/*
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    void swap(int *x,int *y);
    int a = 10;
    int b = 30;
    cout<<"the value of a is"<<a;
    cout<<"\nthe value of b is"<<b;
    swap(&a,&b);
    cout<<"\nthe value of a is"<<a;
    cout<<"\nthe value of b is"<<b; 
    cout<<""<<endl;   
    return 0;
}
*/

void swap(int &x,int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{

    int a = 10;
    int b = 30;
    cout<<"the value of a is"<<a;
    cout<<"\nthe value of b is"<<b;
    swap(a,b);
    cout<<"\nthe value of a is"<<a;
    cout<<"\nthe value of b is"<<b; 
    cout<<""<<endl;   
    return 0;
}