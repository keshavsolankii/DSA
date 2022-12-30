#include<iostream>
#include<stack>
using namespace std;

class Queue
{
    public:

    int *arr;
    int front;
    int rear;
    int size;

    Queue(int s)
    {
        this -> size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int data)
    {
        if(rear == size)
        {
            cout<<"Queue is full!"<<endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if(front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear)
            {
                front = 0;
                rear = 0;
            }
        return ans;
        }
    }

    bool isEmpty()
    {
        if(front == rear)
        {
            return true;
        }
        else{
            return false;
        }
    }

    int frontElement()
    {
        if(front == rear)
        {
            return -1;
        }
        else{
            return arr[front];
        }
    }
};

void revesre_K_elements(Queue &q, int k, int n)
{
    stack<int> st;
    // pushing k elements into the stack
    for(int i=0; i<k; i++)
    {
        st.push(q.dequeue());
    }
    // pushing back the elements into the queue
    while(!st.empty())
    {
        q.enqueue(st.top());
        st.pop();
    }
    /* for k = 3, now the queue looks like --> {40,50,30,20,10}. Now we have to 
       pop the (n-k) elements and push at the back*/

    for(int i=0; i<(n-k); i++)
    {
        int val = q.frontElement();
        q.dequeue();
        q.enqueue(val);
    }   
    cout<<"After reversing"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<q.dequeue()<<" ";
    }
}

int main()
{
    Queue q(10);
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    revesre_K_elements(q,3,5);
    
    return 0;
}