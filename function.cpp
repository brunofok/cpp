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
        
        void run_func(std::function<void()> function);
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

void Consumer::run_func(std::function<void()> function){
    std::cout << "in the run_func\n";
    function();
}

Producer::Producer(const string str_name)
{
    this->name = str_name;
    last_id++;
    id = last_id;
}

void Producer::inc_id(){
    std::cout << "in the Producer::inc_id member function" << std::endl;
    this->id++;
}

void print_lambda() { std::cout << "Im in the lambda function...\n"; }

int main()
{
    std::cout << "Hello world\n";    

    Consumer* con = new Consumer("Consumer1");  
    Producer* pro = new Producer("Producer1");
    
    std::cout << con->name << ", id: " << con->id << std::endl;    
    std::cout << pro->name << ", id: " << pro->id << std::endl;

    auto f_display_something = std::bind(&Producer::inc_id, pro);
    con->run_func(f_display_something);

    std::cout << con->name << ", id: " << con->id << std::endl;    
    std::cout << pro->name << ", id: " << pro->id << std::endl;    

    return 1;
}