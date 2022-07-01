#include<iostream>
#include"PQueue.h"
using namespace std;

template <class T>

/*class Stack {
public:

    SeqQueue<int> q1;
    SeqQueue<int> q2;


    Stack()
    {

    }


    void push(int x)
    {
        if (q1.IsEmpty())
            q2.EnQueue(x);
        if (q2.IsEmpty())
            q1.EnQueue(x);
    }


    int pop()
    {
        //³ö¶ÓÁÐ
        int t;
        if (q1.IsEmpty())
        {
            if (q2.getSize() == 1)
            {
                t = q2.getFront();
                q2.DeQueue();
                return t;
            }
            else
            {
                while (q2.getSize() > 1)
                {
                    q1.EnQueue(q2.getFront());
                    q2.DeQueue();
                }
                t = q2.getFront();
                q2.DeQueue();
                return t;
            }
        }
        else
        {
            if (q1.getSize() == 1)
            {
                t = q1.getFront();
                q1.DeQueue();
                return t;
            }
            else
            {
                while (q1.getSize() > 1)
                {
                    q2.EnQueue(q1.getFront());
                    q1.DeQueue();
                }
                t = q1.getFront();
                q1.DeQueue();
                return t;
            }
        }
    }

    int top()
    {
        if (q1.IsEmpty())
            return q2.getFront();
        else
            return q1.getFront();
    }


    bool empty()
    {
        return q1.IsEmpty() && q2.IsEmpty();
    }
};*/








class Stack {
private:
    SeqQueue<int> q1, q2;
public:
    Stack() {}
    void push(int x) {
        if (!q1.IsEmpty())
        {
            q2.EnQueue(x);
            while (!q1.IsEmpty())
            {
                int a;
                q1.DeQueue(a);
                q2.EnQueue(a);
            }
        }
        else
        {
            q1.EnQueue(x);
            while (!q2.IsEmpty())
            {
                int b;
                q2.DeQueue(b);
                q1.EnQueue(b);
            }
        }
    }
    int pop() {
        if (q1.IsEmpty() && q2.IsEmpty())
            return -1;
        else if (!q1.IsEmpty()) { 
            int c;
            q1.DeQueue(c);
            return c;
        }
        else {
            int c;
            q2.DeQueue(c);
            return c;
        }
    }
    int top() {
        if (!q1.IsEmpty()) {
            int d;
            q1.getFront(d);
            return d;
        }
        else {
            int d;
            q2.getFront(d);
            return d;
        }
    }
    bool empty() {
        return (q1.IsEmpty() && q2.IsEmpty());
    }
};
