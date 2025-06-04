#include<iostream>
using namespace std;

class Queue
{
protected:
    int front,rear,capicity;
    int *array;
public:
    Queue(int size)
    {
        this->capicity = size;
        this->array = new int[this->capicity];
        this->front = this->rear = -1;
    }
    ~Queue()
    {
        delete[] array;
    }

    virtual void Push(int element) {}
    virtual int Pop() {}
    virtual int Peek() {}
    virtual bool IsEmpty() {}
    virtual bool IsFull() {}
    virtual void Clear() {}
    virtual int Size() {}
    int Size() {}
    virtual void ViewQueue() {}
};

class Display : public Queue 
{
public:
    Display(int size) : Queue (size){}

    void Push(int element) 
    {
        if (this->IsEmpty())
        {
            this->front = this->rear = 0;
            this->array[front] = element;
        }
        else 
        {
            this->array[front] = element;
        }
    }

    void Pop()
    {
        if (this->IsEmpty())
        {
            cout << endl << "The Queue Is Already Empty...." << endl;
        }
        else
        {
            cout << endl << array[front++] << " Is Removed...." << endl;
        }
    }

    int Peek()
    {
        if (this->IsEmpty())
        {
            return -1;
        }
        else
        {
            return array[front];
        }
    }

    bool IsEmpty()
    {
        return rear == -1;
    }

    bool IsFull()
    {
        return rear == capicity;
    }

    void Clear ()
    {
        this->front = this->rear = -1;
        for (int i=0; i<this->capicity; i++)
        {
            array[i] = 0;
        }
    }
    int Size()
    {
        return rear + 1;
    }

    int Size()
    {
        return capicity - (rear + 1);
    }

    void ViewQueue()
    {
        if (this->IsEmpty())
        {
            cout << endl << "The Queue Is Empty..." << endl;
        }
        else
        {
            cout << endl << "The Queue Is :- ";
            for (int i = this->front; i <= rear; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int size;

    cout << "Enter The Size Of Queue :- ";
    cin >> size;

    Display obj(size);

    int choice,num;

    do
    {
        cout << endl << "Program's" << endl;
        cout << "Press 1 To Insert." << endl;        
        cout << "Press 2 To Pop." << endl;        
        cout << "Press 3 To Peek." << endl;        
        cout << "Press 4 To Check If The Queue is Empty Or Not." << endl;        
        cout << "Press 5 To Check If The Queue is Full Or Not." << endl;        
        cout << "Press 6 To Check The Current Size Of Queue." << endl;        
        cout << "Press 7 To Check The Remaning Space Avaible In Queue." << endl;        
        cout << "Press 8 To Display The Queue." << endl;        
        cout << "Press 9 To Clear The Queue." << endl;        
        cout << "Press 0 To Exit." << endl;

        cout << "Enter Your Choice :- ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << endl << "Your Program Is Sucessfully Exited...." << endl;
            break;
        
        case 1:
            int num;
            cout << "Enter A Number To Insert :- ";
            cin >> num;
            obj.Push(num);
            break;
        
        case 2:
            obj.Pop();
            break;
        
        case 3:
            cout << endl << "The Top Most Element Of The Queue is :- " << obj.Peek() << endl;
            break;
        
        case 4:
            obj.IsEmpty();
            break;
        
        case 5:
            obj.IsFull();
            break;
        
        case 6:
            obj.Size();
            break;
        
        case 7:
            obj.Size();
            break;
        
        case 8:
            obj.ViewQueue();
            break;
        
        case 9:
            obj.Clear();
            break;

        default:
            cout << endl << "Wrong Choice...." << endl;
            break;
        }
    }
    while (choice != 0)
    return 0;
}
