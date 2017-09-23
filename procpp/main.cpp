#include <iostream>

using namespace std;
struct Node {
    char data;
    Node *next;
};

int main() {
    Node *list = new Node;
    list->next = nullptr;
    Node *cur = list;

    char c;
    while (cin >> c) {
        if (c == 'q') break;
        if (c != ']' && c != '[') {
            Node *node = new Node;
            node->data = c;
            node->next = cur->next;
            cur->next = node;
            cur = node;
        }
        if (c == '[') {
            cur = list;
        }

        if (c == ']') {
            Node *tmp = list;
            while (tmp->next != nullptr) {
                cur = tmp;
            }
        }
    }

    Node *tmp;
    for (tmp = list->next; tmp != nullptr; tmp = tmp->next) {
        cout << tmp->data;
    }

    cout << endl;
    return 0;
}