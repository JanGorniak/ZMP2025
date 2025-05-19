#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};


void append(Node** headRef, int value)
    {
    Node* newNode=new Node{value, nullptr};
    if(*headRef==nullptr)
    {
        *headRef=newNode;
        return;
    }

    Node* temp=*headRef;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next = newNode;
    }
void splitList(Node* source, Node** frontRef, Node** backRef)
{
    Node* slow=source;
    Node* fast=source->next;

    while(fast!=nullptr)
    {
        fast=fast->next;
        if(fast!=nullptr    )
        {
            slow=slow->next;
            fast=fast->next;
        }
    }

    *frontRef=source;
    *backRef=slow->next;
    slow->next=nullptr;
}
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = nullptr;

    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) return;

    Node* a;
    Node* b;

    splitList(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);

    *headRef = merge(a, b);
}
void print(Node*node)
{
    while (node!=nullptr)
    {
        cout << node->data;
        node = node->next;
    }
}

int main()
{
    Node* head=nullptr;
    int size;
    cin >> size;
    for(int i=0; i<size; ++i)
    {
        int val;
        cin >> val;
        append(&head, val);
    }
    mergeSort(&head);
    print(head);

    return 0;
}