#include <iostream>
using namespace std;

class Singleton{
private:
  Singleton() = default;
public:
  static Singleton* getInstance(){
    if(!instance)  instance = new Singleton;
    return instance;
  }

  void operatation(){
    std::cout << instance << '\n';
  }
protected:
  static Singleton* instance;
};
Singleton* Singleton::instance = 0;

int main (){

  Singleton* instance = Singleton::getInstance();
  instance->operatation();

  Singleton* instance2 = Singleton::getInstance();
  instance2->operatation();

  Singleton* instance3 = Singleton::getInstance();
  instance3->operatation();
}
