#include <string>
#include <iostream>

using namespace std;

class Test{
protected:
   string testType;
public:
   virtual void test() = 0;
};

class Test_turn : public Test{
   
};
class Turn_left : public Test_turn{
public:
   Turn_left(){
      testType = "Test turn left";
   }
   void test(){
      cout << "now testing: " << testType << endl;
   }
};
class Turn_right : public Test_turn{
public:
   Turn_right(){
      testType = "Test turn right";
   }
   void test(){
      cout << "now testing: " << testType << endl;
   }  
};
class Test_start : public Test{
public:
   Test_start(){
      testType = "Test start";
   }
   void test(){
      cout << "now testing: " << testType << endl;
   }
};

class Vehicle{
protected:
   Test* testtype = nullptr;
   Vehicle(){}
   Vehicle(Test* t){
      testtype = t;
   }
public:
   ~Vehicle(){
      if(testtype){
         delete testtype;
      }
   }
   void changeTest(Test* t){
      if(testtype){
         delete testtype;
         testtype = nullptr;
      }
      testtype = t;
   }
   
};

class Car : public Vehicle{
public:
   Car(){}
   Car(Test* t) : Vehicle(t){
      
   }
   void test(){
      testtype->test();
   }
};
class Bus : public Vehicle{
public:
   Bus(){}
   Bus(Test* t) : Vehicle(t){
   
   }
   void test(){
      testtype->test();
   }
};

int main(){
   Car c1(new Turn_right);
   c1.test();
   c1.changeTest(new Turn_left);
   c1.test();
   c1.changeTest(new Test_start);
   c1.test();
   return 0;
}
