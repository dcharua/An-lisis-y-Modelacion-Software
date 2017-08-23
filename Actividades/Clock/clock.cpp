#include <ctime>
#include <iostream>
using namespace std;

class Clock{
private:
  Clock() = default;
public:
  static Clock* getInstance(){
    if(!instance)  instance = new Clock;
    return instance;
  }

  void getTime(){
    time_t rawtime;
    time (&rawtime);
    std::cout << ctime (&rawtime) << '\n';
  }
protected:
  static Clock* instance;
};
Clock* Clock::instance = 0;

int main (){

  Clock* instance = Clock::getInstance();
  instance->getTime();

  Clock* instance2 = Clock::getInstance();
  instance2->getTime();

  Clock* instance3 = Clock::getInstance();
  instance3->getTime();
}
