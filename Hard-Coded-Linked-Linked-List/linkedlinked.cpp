#include <iostream>
#include <string>
using namespace std;

template<class T>
class Node {
public:
    T obj;
    Node* next;
    Node* prev;
};

template<typename T>
void printForward(Node<T>* head);

template<typename T>
void printReverse(Node<T>* head);

template<typename T>
int size(Node<T>* head);

template<typename T>
void deleteSecond(Node<T>* head);

template<typename T>
void deleteAll(Node<T>*& head);

int main(void) {
	Node<string>* head = new Node<string>;
	head->obj = "C++";
    Node<string>* mid = new Node<string>;
    mid->obj = "Data";
    Node<string>* tail = new Node<string>;
    tail->obj = "Structure";
	
	head->next = mid;
	head->prev = nullptr;
	mid->next = tail;
	mid->prev = head;
	tail->next = nullptr;
	tail->prev = mid;

	cout << "Forward: " << endl;
	printForward(head);
	cout << "\nReverse: " << endl;
	printReverse(head);

	cout << "\nCurrent Size: " << size(head) << endl;
	deleteSecond(head);
	cout << "\nAfter Deletion of second node: " << endl;
	printForward(head);
	deleteAll(head);
    cout << "\nSize After Deallocation: " << size(head) << endl;

    return(0);
}

template<typename T>
void printForward(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        do {
            cout << cur->obj << endl;
            cur = cur->next;
        } while (cur != nullptr);
    }

}

template<typename T>
void printReverse(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        //iterate to end;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cout << cur->obj << endl;
        while (cur->prev != nullptr) {
            cur = cur->prev;
            cout << cur->obj << endl;
        }
    }
}

template<typename T>
void deleteSecond(Node<T>* head) {
    Node<T>* second = head->next;
    head->next = second->next;
    if (second->next != nullptr) {
        second->next->prev = head;
    }
    delete second;
}

template<typename T>
int size(Node<T>* head) {
    int count = 0;
    Node<T>* cur = head;
    while (cur != nullptr) {
        count++;
        cur = cur->next;
    }
    return count;
}

template<typename T>
void deleteAll(Node<T>*& head) {
    Node<T>* cur = head;
    while (cur != nullptr) {
        Node<T>* next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
}

