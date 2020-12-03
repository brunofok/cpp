#include <functional>
#include <iostream>
#include <string>

using namespace std;

static int last_id = 0;

class Consumer{
    public:
        Consumer(string str_name);
        int id;
        string name;
        
        void run_func(function<void()> function);
};

class Producer{
    public:
        Producer(string str_name);
        int id;
        string name;
        
        void inc_id();
};

Consumer::Consumer(const string str_name)
{
    this->name = str_name;
    last_id++;
    id = last_id;
}

void Consumer::run_func(function<void()> function){
    cout << "in the run_func\n";
    function();
}

Producer::Producer(const string str_name)
{
    this->name = str_name;
    last_id++;
    id = last_id;
}

void Producer::inc_id(){
    cout << "in the Producer::inc_id member function" << endl;
    this->id++;
}

void print_lambda() { cout << "Im in the lambda function...\n"; }

int main()
{
    cout << "Hello world\n";    

    Consumer* con = new Consumer("Consumer1");  
    Producer* pro = new Producer("Producer1");
    
    cout << con->name << ", id: " << con->id << endl;    
    cout << pro->name << ", id: " << pro->id << endl;

    auto f_display_something = bind(&Producer::inc_id, pro);
    con->run_func(f_display_something);

    cout << con->name << ", id: " << con->id << endl;    
    cout << pro->name << ", id: " << pro->id << endl;    

    return 1;
}