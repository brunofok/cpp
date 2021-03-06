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
    int limit = 0;

    Node * head;
    Node * last;

    public:

    List()
    {
        head = nullptr;
    }

    bool Append(Node& node)
    {
        if (node.id < 0)
            return false;

        this->limit++;
        if (head == nullptr)
        {
            head = &node;
            last = &node;
            return true;
        }

        last->next = &node;
        last = &node;

        return true;
    }

    bool DeleteNext(Node * node)
    {
        if (node == nullptr && node->next != nullptr)
            return false;

        Node * next = node->next;

        node->next = node->next->next;
        next = nullptr;
        delete next;
        limit--;
        
        return true;
    }

    bool Remove(Node * node)
    {
        if (head == nullptr)
            return false;

        if (node == head)
        {
            head = head->next;
            node = nullptr;
            delete node;
            limit--;
            return true;
        }

        Node * current = head;

        Node * next = current->next;

        while(next != nullptr)
        {
            if (node == next)
            {
                return DeleteNext(current);
            }
            
            current = next;
            next = next->next;
        }
        return false;
    }
    
    int size()
    {
        return limit;
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
    walk(L->head, print_node);
    cout << "list size: " + to_string(L->size()) << endl;
    L->Remove(L->head);
    walk(L->head, print_node);
    cout << "list size: " + to_string(L->size()) << endl;    

    return 1;
}
