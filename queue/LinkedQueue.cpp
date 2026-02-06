#include "LinkedQueue.h"
#include <iostream>

using namespace std;

LinkedQueue::LinkedQueue():front(nullptr),rear(nullptr),count(0){}

LinkedQueue::~LinkedQueue(){
    clear();
}

void LinkedQueue::enqueue(int value){
    Node* n = new Node(value);

    if(isEmpty()){
        front = n;
        rear = n;
    }else {
        rear->next = n;
        rear = n;
    }

    count++;
}

void LinkedQueue::dequeue(){
    if (isEmpty()){
        cout << "错误" <<endl;
        return;
    }

    Node* n = front;
    front = n->next;

    if (front == nullptr){
        rear = nullptr;
    }

    delete n;
    count--;

}

int LinkedQueue::peek() const{
    if(isEmpty()){
        return -1;
    }
    return front->data;
}

int LinkedQueue::size() const{
    return count;
}

bool LinkedQueue::isEmpty() const{
    return count == 0;
}

void LinkedQueue::clear(){
    while(!isEmpty()){
        dequeue();
    }
}
