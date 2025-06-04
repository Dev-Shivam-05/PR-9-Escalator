// Polymorphism :- Two Same Name Function But With different Works

#include<iostream>
using namespace std;

class Stack 
{
protected:
    int *array;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        this->capacity = size;
        this->array = new int[capacity];
        this->top = -1;
    }

    ~Stack()
    {
        delete[] array;
    }

    void Push(int element)
    {
        if (this->isEmpty())
        {
            this->array[++top] = element;
        }
        else if (this->isFull())
        {
            cout << endl << "The Stack is Over Flowing...." << endl;
        }
        else
        {
            this->top++;
            this->array[top] = element;   
        }
    }

    int Pop()
    {
        if (this->isEmpty())
        {
            return -1;
        }
        else
        {
            return array[top--];
        }
    }

    int Top()
    {
        if (this->isEmpty())
        {
            return -1;
        }
        else
        {
            return array[top];
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top + 1 == capacity;
    }
};

class Display : public Stack
{
public:
    int Size()
    {
        return top + 1;
    }

    void ViewStack()
    {
        cout << endl <<"The Stack Is :- ";
        for (int i = 0; i < top; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size;

    cout<< "Enter the Size Of Stack :- ";
    cin >> size;

    Stack obj[size];

    int choice;
    do
    {
        cout << endl << "---- Program's ----" << endl;
        cout << "Press 1 To Insert." << endl;
        cout << "Press 2 To Pop." << endl;
        cout << "Press 3 To See the Top Most Element Of Stack." << endl;
        cout << "Press 4 To Check the Stack Is Empty Or Not." << endl;
        cout << "Press 5 To Check the Stack Is Full Or Not." << endl;
        cout << "Press 6 To Check the Current Size Of Stack." << endl;
        cout << "Press 7 To Displayt Full Stack." << endl;
        cout << "Press 0 To exit." << endl;
        
        cout << endl << "Enter Your Choice :- ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "\n ---- Your program Is Sucessfully Exited ----" << endl;
            break;
        
        case 1:
            int num;
            cout << "Enter A Number :- ";
            cin >> num;
            obj.Push(num);
            
            break;

        case 2:
            obj.Pop();
            break;
            
        case 3:
            obj.Top();
            break;
            
        case 4:
            if (obj.isEmpty())
            {
                cout << endl << "The Stack is Empty Or UnderFlowing." << endl;
            }
            else
            {
                cout << endl << "The Stack is Not Empty." << endl;
            }
            break;

        case 5:
            if (obj.isFull())
            {
                cout << endl << "The Stack is Full Or OverFlowing." << endl;
            }
            else
            {
                cout << endl << "The Stack is Not Full." << endl;
            }
            break;
        
        case 6:
            cout << endl << "The Current Size of The Stack Is :- " << obj.Size() << endl;
            break;
        
        case 7:
            obj.ViewStack();
            break;

        default:
            cout << endl << "Wrong Choice...." << endl;
            break;
        }
    } while (choice != 0);
    
    
    return 0;
}