#include <iostream>
#include <functional>

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
    
    int size()
    {
        if (head == nullptr)
            return 0;

        int i = 1;
        Node * walk = head;
        while(walk->next != nullptr)
        {
            walk = walk->next;
            i++;
        }

        return i;
    }
};

void print_node(const Node * node)
{
    if (node != nullptr)
        cout << "node: " << node->name << endl;
}

void walk(Node * start, std::function<void(Node *)> function = {})
{
    Node * node = start;

    while(node != nullptr)
    {
        if (function)
            function(node);
        node = node->next;
    }
}

int main(int argc, char * argv[])
{
    cout << "Hello world!" << endl;

    if (argc < 2)
    {
        cout << "Invalid parameters. Please provide the size of a list" << endl;
        return 0;
    }
    const int limit = atoi(argv[1]);

    List * L = new List;
    
    for (int i=0; i<limit; i++)
    {
        Node * node = new Node;
        node->id = i;
        node->name = "node " + to_string(i);

        L->Append(*node);
    }

    cout << "walk:" << endl;
    walk(L->head);
    cout << "list size: " + to_string(L->size()) << endl;

    return 1;
}
