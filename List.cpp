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
    Node * last = nullptr;
    for (int i=0; i<10; i++)
    {
        Node node;
        node.id = i;
        node.name = "node " + i;
        
        if (last != nullptr)
        {
            last->next = &node;
            last = &node;
        }

        if (i=0)
            head = &node;
    }

    cout << "walk:" << endl;
    walk(head);

    return 1;
}
