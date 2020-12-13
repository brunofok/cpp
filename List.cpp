#include <iostream>

using namespace std;

struct Node
{
    int id;
    string name;

    Node* next = nullptr;
};

struct List
{
    Node * head;
    Node * last;

    public:

    List()
    {
        head = nullptr;
    }

    void Append(Node& node)
    {
        if (head == nullptr)
        {
            head = &node;
            return;
        }
        
        Node * walk = head;
        while(walk->next != nullptr)
        {
            walk = walk->next;
        }

        walk->next = &node;

    }
    
    private:
    int size()
    {
        return 0;
    }
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

    List * L = new List;
    
    for (int i=0; i<10; i++)
    {
        Node * node = new Node;
        node->id = i;
        node->name = "node " + to_string(i);

        L->Append(*node);
    }

    cout << "walk:" << endl;
    walk(L->head);

    return 1;
}
