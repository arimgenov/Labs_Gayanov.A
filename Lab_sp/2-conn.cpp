#include <iostream>

struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    int key = 0;
};

struct List {
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;
};

List* create_empty_list() {
    List* newList = new List;
    newList->NIL = new Node; 
    newList->HEAD= newList->NIL;
    newList->TAIL = newList->NIL;
    return newList;
}

List* push_front(List* list_ptr, int new_key) {
    Node* new_node = new Node;
    new_node->key = new_key;
    if (list_ptr == nullptr) list_ptr = create_empty_list();
    if (list_ptr->size == 0) {
        list_ptr->HEAD = new_node;
        list_ptr->TAIL = new_node;
        new_node->next = list_ptr->NIL;
        new_node->prev = list_ptr->NIL;
        list_ptr->size++;
    } else {
        new_node->next = list_ptr->HEAD;
        new_node->prev = list_ptr->NIL;
        list_ptr->HEAD->prev = new_node;
        list_ptr->HEAD = new_node;
        list_ptr->size++;
    }
    return list_ptr;
}

List* insert_after(List* list_ptr, Node* prev_ptr, int new_key) {
    if ((prev_ptr == nullptr) or (list_ptr == nullptr)) return nullptr;
    Node* new_node = new Node;
    new_node->key = new_key;
    if (list_ptr->size == 0) {
        list_ptr->HEAD = new_node;
        list_ptr->TAIL = new_node;
        new_node->next = list_ptr->NIL;
        new_node->prev = list_ptr->NIL;
    } else if (prev_ptr == list_ptr->TAIL) {
        new_node->next = prev_ptr->next;
        prev_ptr->next = new_node;
        new_node->prev = prev_ptr;
    } else {
        new_node->next = prev_ptr->next;
        prev_ptr->next->prev = new_node;
        prev_ptr->next = new_node;
        new_node->prev = prev_ptr;
    }
    list_ptr->size++;
    return list_ptr;
}

List* push_back(List* list_ptr, int new_key)  {
    if (list_ptr==nullptr) list_ptr = create_empty_list();
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = list_ptr->NIL;
    if (list_ptr->TAIL == list_ptr->NIL) {
        new_node->prev = list_ptr->NIL;
        list_ptr->HEAD = new_node;
        list_ptr->TAIL = new_node;
        list_ptr->size++;
    } else {
        new_node->prev = list_ptr->TAIL;
        list_ptr->TAIL->next = new_node;
        list_ptr->TAIL = new_node;
        list_ptr->size++;
    }
    return list_ptr;
}

void print_list(const List* list_ptr) {
    if (list_ptr == nullptr) {return; std::cout << std::endl;}
    Node* current = list_ptr->HEAD;
    while (current != list_ptr->NIL) {
        std::cout << current->key << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void clear_list(List* list_ptr) {
    if (list_ptr == nullptr) return;
    Node* current = list_ptr->HEAD;
    while (current != list_ptr->NIL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
    list_ptr->size = 0;
}

void destroy_list(List* list_ptr) {
    if (list_ptr == nullptr) return;
    clear_list(list_ptr);
    delete list_ptr->NIL;
    delete list_ptr;
}

void remove_key(List* list_ptr, int key) {
    if (list_ptr == nullptr) return;
    Node* current = list_ptr->HEAD;
    while (current != list_ptr->NIL) {
        if (current->key == key) {
            if (current == list_ptr->HEAD) list_ptr->HEAD = current->next;
            else if (current == list_ptr->TAIL) list_ptr->TAIL = current->prev;
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            list_ptr->size--;
            break;
        }
        current = current->next;
    }
}

 Node* find_key(List* list_ptr, int key) {
    if (list_ptr == nullptr) return nullptr;
    Node* current = list_ptr->HEAD;
    while (current != list_ptr->NIL) {
        if (current->key == key) return current;
        current = current->next;
    }
    return list_ptr->NIL;
 }

using std::cout;
using std::endl;


int main() {
    
    return 0;
}
