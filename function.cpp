#include <functional>
#include <iostream>
#include <string>
#include <boost/function.hpp>
#include <boost/bind.hpp>

using namespace std;

static int last_id = 0;

class Consumer{
    public:
        Consumer(string str_name);
        int id;
        string name;
        
        void run_func(function<void()> function);
        void run_func2(boost::function<void()> function);
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
    cout << "in the run_func by std::function\n";
    function();
}

void Consumer::run_func2(boost::function<void()> function){
    cout << "in the run_func by std::boost\n";
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
static int id_global = 0;
void print_lambda() { 
    cout << "Changing idi_global to 1 ...\n"; 
    id_global = 1;
}

int main()
{
    int id_local = 0;
    int* ptr_id_local = &id_local;
    cout << "Hello world\n";    

    Consumer* con = new Consumer("Consumer1");  
    Producer* pro = new Producer("Producer1");
    
    cout << con->name << ", id: " << con->id << endl;    
    cout << pro->name << ", id: " << pro->id << endl;

    auto f_display_something = bind(&Producer::inc_id, pro);
    con->run_func(f_display_something);

    cout << con->name << ", id: " << con->id << endl;    
    cout << pro->name << ", id: " << pro->id << endl;    

    cout << "id_local: " << id_local << std::endl;
    con->run_func2(boost::bind(&print_lambda));
    *ptr_id_local = id_global;
    cout << "id_local: " << id_local << std::endl;

    return 1;
}