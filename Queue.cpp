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

    virtual void Enqueue(int element) {}
    virtual void Dequeue() {}
    virtual int Front() {}
    virtual int Rear() {}
    virtual bool IsEmpty() {}
    virtual bool IsFull() {}
    virtual void Clear() {}
    virtual int Size() {}
    int Remaning_Size() {}
    virtual void ViewQueue() {}
};

class Display : public Queue 
{
public:
    Display(int size) : Queue (size){}

    void Enqueue(int element) 
    {
        
        if (this->front > 0 && this->rear == capicity - 1)
        {
            cout << endl << "You Need to Clear Full Queue.To Insert New Element...." << endl;
        }
        else
        {
            if (this->IsFull())
            {
                cout << endl << "The Queue is Over Flowing...." << endl;
                return;
            }
            else if (this->IsEmpty())
            {
                this->front = this->rear = 0;
                this->array[rear] = element;
                cout << endl << element << " Is Sucessfully Enqueued...." << endl << endl;
            }
            else
            {
                this->rear++;
                this->array[rear] = element;
                cout << endl << element << " Is Sucessfully Enqueued...." << endl << endl;
            }
        }
    }

    void Dequeue()
    {
        if (this->IsEmpty())
        {
            cout << endl << "The Queue Is Already Empty...." << endl;
        }
        else if (this->front == this->rear)
        {
            this->front = this->rear = -1;
        }
        else
        {
            cout << endl << array[this->front++] << " Is Removed...." << endl;
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
            return array[this->front];
        }
    }

    bool IsEmpty()
    {
        return this->rear == -1;
    }

    bool IsFull()
    {
        return (this->rear + 1) == this->capicity;
    }

    void Clear()
    {
        this->front = this->rear = -1;
        for (int i = 0; i < this->capicity; i++)
        {
            this->array[i] = 0;
        }
        cout << endl << "The Queue Cleared Sucessfully...." << endl;
    }

    int Size()
    {
        return (this->rear + 1) - this->front;
    }

    int Remaning_Size()
    {
        return this->capicity - this->Size();
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
            for (int i = this->front; i <= this->rear; i++)
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
        cout << endl << "---- Program's ----" << endl;
        cout << "Press 1 To Enqueue." << endl;              
        cout << "Press 2 To Dequeue." << endl;        
        cout << "Press 3 To See The Front Elemnt Of The Queue." << endl;        
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
            obj.Enqueue(num);
            break;
            
        case 2:
            obj.Dequeue();
            break;
        
        case 3:
            cout << endl << "The Top Most Element Of The Queue is :- " << obj.Peek() << endl;
            break;
        
        case 4:
            (obj.IsEmpty() == 1) ? cout << endl << "The Queue Is Empty...." << endl : cout << endl << "The Queue Is Not Empty With The Size Of :- " << obj.Size() << endl;
            break;
        
        case 5:
            (obj.IsFull() == 1) ? cout << endl << "The Queue Is Full...." << endl : cout << endl << "The Queue Is Not Full With The Size Of :- " << obj.Size() << endl;
            break;
        
        case 6:
            cout << endl << "The Current Size Of The Queue is :- " << obj.Size();
            break;
        
        case 7:
            cout << endl << "The Remaning Space In The Queue is :- " << obj.Remaning_Size() << endl;
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
    while (choice != 0);

    return 0;
}
