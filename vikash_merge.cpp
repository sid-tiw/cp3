#include <iostream>
using namespace std;

// define a node
struct Node {
    int data;
    Node* next;
};
Node* Merge(Node* start, Node* mid);

// divide list... mid
void split(Node* start, Node** mi	d) {
    Node* fast = start;
    Node* slow = start;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    *mid = slow;
}

// merge sort
void merge_sort(Node** head, int sz) {
    Node* start = *head;
    Node* mid;
    // size of ll is less than 2
    if (start == NULL || start->next == NULL) {
        return;
    }
    // mid nikal and call merge sort twice
	cout << mid->data << "\n";
    split(start, &mid);
    merge_sort(&start);
    merge_sort(&mid);
    // // merge sorted list's
    // *head = Merge(start, mid);
}
// Merge two list
Node* Merge(Node* start, Node* mid) {
    Node* result = NULL;
    if (start == NULL)
        return (mid);
    else if (mid == NULL)
        return (start);

    if (start->data <= mid->data) {
        result = start;
        result->next = Merge(start->next, mid);
    } else {
        result = mid;
        result->next = Merge(start, mid->next);
    }
    return result;
}

// print the list
void print_ll(struct Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    return;
}
// insert a node with value m at the end
void append(Node* n, int m) {
    Node* new_node = new Node;
    new_node->data = m;
    new_node->next = NULL;
    while (n->next != NULL) {
        n = n->next;
    }
    n->next = new_node;

    return;
}

int main() {
    Node* head = new Node();
    Node* temp = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    append(head, 7);
    append(head, 5);
    append(head, 6);
    append(head, 9);
    append(head, 5);
    append(head, 10);
    append(head, 4);
    append(head, 8);
    merge_sort(&head);
    print_ll(head);
    return 0;
}