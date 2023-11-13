#include <iostream>
using namespace  std;

class ArrayStack{
    private:
    int* array;
    int cap;
    int top;

    public:
    ArrayStack(int size){
        cap=size;
        array = new int[cap];
        top=-1;
    }

    bool isEmpty(){
        return (top==-1);
    }

    void push (int value){
        if(top>=cap) {
            cout<<"stack overflow";
    }
    else {
        array[++top]=value; 
        }
        }
    
    void pop(){
        if(isEmpty()){
            cout << "Empty Stack";    
            }
            else {
                --top;
         }
    }

    int peak(){
        if(isEmpty()) {
            cout << "Empty Stack";
            return -1;
            }
            return array[top];
    }

    void display(){
        cout<< array[top];
    }
    };

    int main(){
        ArrayStack s(5);
        s.push(20);
        s.display();
        cout<<endl;
        s.pop();
        s.peak();
        s.display();
        cout<<endl;
        return 0;
        }
    
