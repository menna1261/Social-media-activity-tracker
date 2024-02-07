#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node* next;

    Node() : next(nullptr) {}
    Node(T value) : data(value), next(nullptr) {}
};


template <typename T>
class LinkedList
{
public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    LinkedList() : head(nullptr),tail(nullptr), size(0) {}

    bool isEmpty()
    {
        return head==nullptr;

    }
    void insertFirst(T value)
    {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty())
        {
            cout<<"hhh";
            head=tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        ++size;
    }
    void display() const
    {
        Node<T>* temp = head;
        while (temp != nullptr)
        {

            cout <<temp->data.hash_function()<<"."<<temp->data<<endl;

            temp = temp->next;
        }
        cout <<endl;
    }
    void append(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty())
        {

            head=tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;

        }
        ++size;

    }
    void deleteFront()
    {
        if (isEmpty())
            return;

        Node<T>* temp = head;
        head = head->next;
        --size;
        delete temp;
    }

    int return_size()
    {
        return size;
    }
    void remove_a(int key)
    {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        // Search for the key in the the list
        while (current->next != nullptr && current->data.hash_value != key)
        {
            prev = current;
            current = current->next;
        }

        // If the key is not found
        if (current == nullptr)
        {
            std::cout << "Invalid number" << std::endl;
            return;
        }
        if (prev == nullptr)
        {
            // Node to be deleted is the head
            head = current->next;
        }
        else
        {
            prev->next = current->next;
        }

        if (current == tail)
        {
            // Node to be deleted is the tail, update tail
            tail = prev;
        }
    }
    void delete_node(Node<T>* node)
    {
        --size;
        delete node;
    }

    void delete_next_node(Node<T>* prv)
    {
        assert(prv);
        Node<T>* to_delete = prv->next;
        bool is_tail = to_delete == tail;
        prv->next = prv->next->next;
        delete_node(to_delete);
        if (is_tail)
        {
            prv = tail;
        }
        }

        void key_delete(int key)
        {

            if(head->data.hash_function()==key)
        {
            Node<T>* cur = head;

            head = head->next;
            delete cur;
            /*if(!head)
            cout<<"The only activity removed successfully"<<endl;*/


        }
        else

        for (Node<T>* cur = head->next, *prv = head; cur; prv = cur, cur = cur->next)
        {
            if (cur->data.hash_function() == key)
            {
                delete_next_node(prv);    // I want to link between prv and the prv->next->next and delete the cur node
                return;
            }
        }
        }


    }
    ;

#endif // LINKEDLIST_H
