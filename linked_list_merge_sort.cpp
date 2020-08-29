#include <iostream>

using namespace std;

class Vertex {
   public:
    int data;
    Vertex *next;
    Vertex(int data) {
        this->data = data;
        next = nullptr;
    }
};

void append(Vertex **head, int data) {
    Vertex *temp = *head;
    if (*head == nullptr) {
        *head = new Vertex(data);
        return;
    }
    while (temp->next != nullptr) temp = temp->next;
    temp->next = new Vertex(data);
}

void print_list(Vertex *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void merge(Vertex **start, Vertex *mid) {
    Vertex *head = NULL, *pointer1 = *start, *pointer2 = mid;
    while (pointer1 != nullptr && pointer2 != nullptr) {
        if ((pointer1->data) < (pointer2->data)) {
            append(&head, pointer1->data);
            pointer1 = pointer1->next;
        } else {
            append(&head, pointer2->data);
            pointer2 = pointer2->next;
        }
    }
    Vertex *mainp;
    if (pointer1 == nullptr)
        mainp = pointer2;
    else
        mainp = pointer1;
    while (mainp != nullptr) {
        append(&head, mainp->data);
    }
    *start = head;
}

void merge_sort(Vertex **start) {  // end is NULL
    // What is mid?
    Vertex *mid = *start, *crp = *start;
    if (mid->next == nullptr) return;
    while (crp->next != nullptr && crp->next->next != nullptr) {
        mid = mid->next;
        crp = crp->next->next;
    }
    crp = mid->next;
    mid->next = nullptr;
	cout << mid->data << " " << crp->data << "\n";
    merge_sort(start);
    merge_sort(&crp);
    merge(start, crp);
}

int main() {
    Vertex *head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        append(&head, temp);
    }
	merge_sort(&head);
	print_list(head);
    return 0;
}