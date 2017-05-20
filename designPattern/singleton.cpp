#include <iostream>
#include <thread>
#include <exception>
#include <mutex>
#include <chrono>
using namespace std;

mutex myLock;

class Singleton{
private:
    Singleton(){}
    static Singleton* instance;
    int content;
public:
    static Singleton* getInstance(int c){
        cout << "enter create progress...\n";
        if(instance==nullptr){
            instance = new Singleton;
            cout << "create new instance!\n";
        }
        (*instance).content = c;
        return instance;
    }
    int getContent(){
        return content;
    }
};

void display(int threadId){
    unique_lock<mutex> lazyLock(myLock);
    Singleton* mysingleton = Singleton::getInstance(threadId);
    cout << reinterpret_cast<unsigned long long>(mysingleton) << endl;
    return;
}

Singleton* Singleton::instance = nullptr;
int main(){
    thread t1(display, 1);
    cout << "create thread 1\n";
    thread t2(display, 2);
    cout << "create thread 2\n";
    t1.detach();
    cout << "1 finished\n";
    t2.detach();
    cout << "2 finished\n";
    this_thread::sleep_for(chrono::seconds(2));
    return 0;
}
