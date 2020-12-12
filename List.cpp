#include <iostream>

using namespace std;

struct Node
{
    int id;
    string name;

    Node* next = nullptr;
};

void print_node(const Node * node)
{
    if (node != nullptr)
        cout << "node: " << node->name << endl;
}

void walk(Node * start)
{
    Node * node = start;

    while(node != nullptr)
    {
        print_node(node);
        node = node->next;
    }
}

int main()
{
    cout << "Hello world!" << endl;

    Node * head = nullptr;

    Node node1;
    node1.id = 1;
    node1.name = "node 1";
    head = &node1;
    
    Node node2;
    node2.id = 2;
    node2.name = "node 2";
    node1.next = &node2;

    Node node3;
    node3.id = 3;
    node3.name = "node 3";    
    node2.next = &node3;
    
    cout << "walk:" << endl;
    walk(head);

    return 1;
}
