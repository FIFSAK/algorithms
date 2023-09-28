#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;
    Node(const std::string& d) : data(d), next(nullptr) {}
};

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cin.ignore();  // Ignore newline after reading n and k

    Node* head = nullptr;
    Node* tail = nullptr;

    // Read the words and create the linked list
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;

        Node* newNode = new Node(word);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Move the first n-k nodes to the end
    if (k < n) {
        Node* prev = nullptr;
        Node* curr = head;
        for (int i = 0; i < n - k; ++i) {
            prev = curr;
            curr = curr->next;
        }

        if (prev) {
            prev->next = nullptr;
            tail->next = head;
            head = curr;
        }
    }

    // Print the linked list
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    // Cleanup
    while (head) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    return 0;
}
