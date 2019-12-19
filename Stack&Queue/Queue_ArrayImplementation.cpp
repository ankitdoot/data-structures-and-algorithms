#include<iostream>
using namespace std;
int main()
{
    cout<<"enter max size of queue : ";
    int size;
    cin>>size;
    int front = -1;
    int rare = -1;
    int arr[size];
    int x=1;
    while(x != 0)
    {
        cout<<"\nEnter for push=1__pop=-1__nothing=0 : ";
        cin>>x;
        if(x == 1)
        {
            if(rare == size)
                cout<<"error : stackoverflow";
            else{
                cout<<"enter element to push : ";
                cin>>arr[++rare];
            }
        }
        else if(x == -1)
        {
            front++;
        }
        else break;
    }
    cout<<"\nYour final queue is : ";
    for(int i=front+1;i<=
	rare;i++)
    {
     cout<<arr[i]<<" ";   
    }
}

