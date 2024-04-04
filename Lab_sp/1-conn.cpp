#include <iostream>


struct Node
{
    int key = 0;
    Node* next = nullptr;
};

void push_front(Node*& head_ref, int new_key) {
    Node* node = new Node;
    node->key = new_key;
    node->next = head_ref;
    head_ref = node;
}

void push_back(Node*& head_ref, int new_key) {
    Node* node = new Node;
    node->key = new_key;
    node->next = nullptr;
    Node* last_node = head_ref;
    while(last_node->next!=nullptr) last_node = last_node->next; // идем до конца
    last_node->next = node;
}

Node* find(Node* head_ref, int key) {
    Node* current = head_ref;
    while(current!=nullptr) {
        if (current->key == key) return current;
        else current = current->next;
    }
    return nullptr;
}

void remove_key(Node*& head_ref, int key) {
    Node* rem = find(head_ref, key);
    if (rem != nullptr) {
        if (rem == head_ref) {
            Node* temp = head_ref;
            head_ref = head_ref->next;
            delete temp;
        } else {
            Node* current = head_ref;
            while (current->next != rem) current = current->next;
            current->next = rem->next;
            delete rem;
        }
    }
}

void destroy_list(Node*& head_ref) {
    while (head_ref!=nullptr) {
        Node* current = head_ref;
        head_ref = head_ref->next;
        delete current;
    }
}

void print_list(Node* head_ref) {
    Node* current = head_ref;
    if (current!=nullptr) {
        while (current->next!=nullptr) {
            std::cout << current->key << " ";
            current = current->next;
        }
        std::cout << current->key << "\n";
    } else std::cout << "\n";
}


int main() {
    Node *head = new Node;
    
    return 0;
}