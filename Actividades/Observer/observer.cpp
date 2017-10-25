#include <iostream>
#include <vector>
using namespace std;

class Subject {
    vector < class Observer * > views;
    string name;
  public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setName(string n) {
        name = n;
    }
    string getName() {
        return name;
    }
    void getObservers();
};

class Observer :public Subject{
    Subject *model;
    string name;
  public:
    Observer(Subject *mod, string n) {
        model = mod;
        name = n;
        model->attach(this);
    }
    string getName(){return name;}
    void setName(string n){ name = n;}

  protected:
    Subject *getSubject() {
        return model;
    }

};


void Subject::getObservers(){
  for (int i = 0; i < views.size(); i++)
    std::cout << views[i]->getName() << '\n';
}

int main() {
  Subject* subj = new Subject();
  subj->setName("Trump");
  Subject* subj2 = new Subject();
  subj2->setName("Peña");
  Subject* subj3 = new Subject();
  subj3->setName("Lider Coreano");
  Observer* obs = new Observer(subj, "MVS");
  Observer* obs2 = new Observer(subj, "Televisa Red Noticias");
  Observer* obs3 = new Observer(subj, "Noticias Internacionales");
  subj2->attach(obs2);
  subj2->attach(obs3);
  subj3->attach(obs3);

  std::cout << subj->getName() << " is followed by :"<<endl;
  subj->getObservers();
  std::cout << " -------------------"<<endl;


  std::cout << subj2->getName() << " is followed by :"<<endl;
  subj2->getObservers();
  std::cout << " -------------------"<<endl;


  std::cout << subj3->getName() << " is followed by :"<<endl;
  subj3->getObservers();
}
