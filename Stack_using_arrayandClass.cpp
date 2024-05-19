#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
//#define max 100;
class Mystack{

public:
int top;
static const int max=100;
int a[max];
bool push(int x)
{
    if(top>=max-1)
   { cout<<"\nStack overflow\n";
   
       return false;
   }
   else{
       a[++top]=x;
       cout<<"\n Item pushed \n";
       return true;
   }
}
int pop(){
    if(top<0)
    {
        cout<<"\nStack underflow \n";
        return 0;
    }
    else{
        int x =a[top--];
        return x;
    }
    
}
int peek(){
    if(top<0)
    {
        cout<<"\n Stack is empty \n ";
        return -1;
    }
    else{
        int x =a[top];
        return x;
    }
    
}
void show(){
    if(top<0)
    {
        cout<<"\n Stack is empty \n";
        
    }
    else{ cout<<"\n Stack item are \n";
        for(int i=0 ;i<=top;i++)
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
bool isEmpty()
{
    if(top<0)
    return true;
    else return false;
}
Mystack(){
    top=-1;
}

};

int main()
{
    int k,l=1;
    bool check;
     Mystack s;
    while(l){
    
    cout<<"\nEnter 1 for push\n ";
    cout<<"\nEnter 2 for pop\n ";
    cout<<"\nEnter 3 for peek\n ";
    cout<<"\nEnter 4 for show\n ";
    cout<<"\nEnter 5 for chrck stack is empty or not\n ";
    cout<<"\nEnter 6 for Exit\n ";
    cin>>k;
    switch(k)
    {
        case 1:     if(s.top>=s.max-1)
   { cout<<"\nStack overflow\n";
        break;
   }else{
       cout<<"\nEnter element you want to push  :";
       int x;
       cin>>x;
       s.push(x);
       break;
   }
   case 2:    if(s.top<0)
   { cout<<"\nStack underflow\n";
        break;
   }else {
       int x =s.pop();
       cout<<"\n "<<x<<" is poped \n";
       break;
   }
   case 3:     if(s.top>=s.max-1)
   { cout<<"\nStack overflow\n";
        break;
   }else{int x = s.peek();
       cout<<"\n peek element is  "<<x<<endl;
       break;
       
   }
   case 4:    if(s.top<0)
   { cout<<"\nStack underflow\n";
        break;
   }else {
       s.show();
       break;
   }
   case 5: check=s.isEmpty();
            if(check==true)
            cout<<"\nStack is empty\n";
            else 
            cout<<"\n stack is not empty\n";
            break;
    case 6: l=0;
    break;
    default:cout<<"\n Please select right option \n";
    break;
    }
    }
    return 0;
}
