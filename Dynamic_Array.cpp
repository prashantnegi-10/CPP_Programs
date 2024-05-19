#include <iostream>
using namespace std;
void create(int *arr,int currentsize)
{
    for(int i=0;i<currentsize;i++)
    {
        cout<<"\n Enter element for "<<i<<" index : ";
        cin>>arr[i];
    }
    cout<<"Data inserted successfully\n";
}
int* resize(int *arr,int newsize,int oldsize)
{
        int* temparr = new int[newsize];
        for(int i=0;i<oldsize && i<newsize ;i++)
        {
            temparr[i]=arr[i];
        }
        if(newsize > oldsize)
        {
           // int current = oldsize;
            for(int i=oldsize;i<newsize;i++)
            {
                cout<<"\n Enter data for "<<i<<" index  :";
                cin>>temparr[i];
            }
        }
        cout<<"\nArray is updated\n";
        delete[] arr;
        return temparr;
}
void print(int* arr, int currentsize)
{
    for(int i=0;i<currentsize;i++)
    {
        cout<<"\n Element at "<<i<<" is : "<<arr[i];
    }
    cout<<endl;
    
}
int* deleteelementbyindex(int* arr,int currentsize,int index)
{
    if(index<0 || index>currentsize){
        cout<<"\n Entered index is out of array bound\n";
                        return arr;     
                        }
    else{
        int* temparr = new int[currentsize-1];
        for(int i=0;i<index;i++)
        {
            temparr[i]=arr[i];
        }
        for(int i=index+1;i<=currentsize-1;i++)
        {
             temparr[i-1]=arr[i];
        }
            delete[] arr;
            cout<<"\n Element Deleted \n";
        return temparr;
    }

}
int* deleteelementbyvalue(int* arr,int currentsize,int key)
{
    int index=-1;
    for(int i =0; i<currentsize ; i++)
    {
        if(arr[i]==key)
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        cout<<"\n Entered Element is not present in the array\n";
    }
    else
    {
      arr=  deleteelementbyindex(arr,currentsize,index);
        
    }
    return arr;
}

int main()
{
    int currentsize=0,newsize=0,oldsize=0,loopcheck=1,index,key;
    int* arr;
  
    while(loopcheck)
    {
        int choice;
        cout<<"Enter 1 for Create array\n";
        cout<<"Enter 2 for Update array size and add new data\n";
        cout<<"Enter 3 for Delete element by value\n";
        cout<<"Enter 4 for Delete element by index\n";
        cout<<"Enter 5 for Print Arrya\n";
        cout<<"Enter 6 for Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"\nEnter size for create array\n";
                    cin>>currentsize;
                    if(currentsize==0)
                    {
                cout<<"\nPlease enter value greater than 0 to create new array try again\n ";
                break;
                      }
                      else
                     { 
                         oldsize=currentsize;
                      arr = new int[currentsize];
                      create(arr,currentsize);
                     }
                      break;
            case 2:  if(currentsize==0)
                    {
                     cout<<"\nPlease first create an array  try again \n";
                     break;
                      }
                     else 
                    { cout<<"\n Please Enter new size for array ";
                     cin>>newsize;
                     if(newsize<=0)
                     {
                         cout<<"\n Please Enter correct new size try again";
                         break;
                     }
                    
                     else 
                     if(newsize == oldsize)
                     {
                         cout<<"\nNew Entered Array size is same as old array try again \n";
                         break;
                     }
                     else 
                    { currentsize=newsize;
                     arr=resize(arr, newsize,oldsize);
                     oldsize=newsize;
                    }
                    }
                     break;
            case 3: 
                    if(currentsize==0)
                    {
                     cout<<"\nPlease first create an array  try again \n";
                     break;
                      }
                     else 
                     {
                     cout<<"\n Please enter element that you want to delete \n";
                     cin>>key;
                        arr=  deleteelementbyvalue(arr,currentsize,key);
                     currentsize--;
                     }
                     break;
            case 4:   
                    if(currentsize==0)
                    {
                     cout<<"\nPlease first create an array  try again \n";
                     break;
                      }
                     else 
                {
                     cout<<"\n Enter single Index of element to delete  :";
                     cin>>index;
                       arr = deleteelementbyindex(arr,currentsize,index);
                       currentsize--;
                }
                       break;
            case 5:  if(currentsize==0)
                    {
                     cout<<"\nPlease first create an array  try again \n";
                     break;
                      }
                     else 
                     print(arr,currentsize);
                     break;
            case 6: loopcheck=0;
                    break;
            default : cout<<"\n Please select correct option from above menu try again \n";
            break;
        }
        
    }
    return 0;
}













