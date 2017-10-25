#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class General{
protected:
  int positionx;
  int positiony;
  string type;
  int id;
public:
  int getX(){return positionx;}
  int getY(){return positiony;}
  int getID() {return id;}
  string getType() {return type;}
  void setPosition(int x, int y){
    positionx = x;
    positiony = y;
  }
  void kill(){id = 0;}
};

template <typename T>
class Singleton: public General{
protected:
  static T* instance;
public:
  static T* getInstance(){
    if(!instance) instance = new T;
    return instance;
  }

  void operatation(){
    std::cout << instance << '\n';
  }
};
template <typename T>
T* Singleton<T>::instance = 0;


class Spacecraft : public Singleton<Spacecraft>{

public:
  void setvalues(int x, int y, string t, int i){
    positionx = x;
    positiony = y;
    type= t;
    id = i;
  }
};

class Asteroid : public Singleton<Asteroid>{

public:
  void setvalues(int x, int y, string t, int i){
    positionx = x;
    positiony = y;
    type= t;
    id = i;
  }
};

class Planet : public Singleton<Planet>{

public:
  void setvalues(int x, int y, string t, int i){
    positionx = x;
    positiony = y;
    type= t;
    id = i;
  }
};

class Board : public Singleton<Board>{
public:
  int game[10][10];

  int getBoard(int x, int y){
    return game[x][y];
  }
  void setPlayer(General* g, int positionx, int positiony){
    game[positionx][positiony] = g->getID();
    g->setPosition(positionx, positiony);
  }

  void resetPlayer(int positionx, int positiony){
    game[positionx][positiony] = 0;
  }
  void printBoard(){
    for (int i = 0; i < 10; ++i){
      for (int j = 0; j < 10; ++j){
        std::cout << game[i][j] << ' ';
        }
      std::cout << std::endl;
    }
  }
};

template <class I>
class Iterator;

template<class C>
class Collection{
protected:
  C* array;
  int size, cont;
public:
  friend class Iterator<C>;
  Collection<C>(){
    size = 10;
    cont = 0;
    array = new C[size];
  }

  void addElement(C value){
    if (cont <= size)
      array[cont++] = value;
    else
      std::cout << "ya no hay espacio para agregar elementos" << '\n';
  }

  Iterator<C>* getIterator();

  C at(int pos){
    return array[pos];
  }
};

template <class I>
class Iterator : public Board{
protected:
  Collection<I> coll;
  int cont = 0;
public:
  Iterator(const Collection<I>& coll) : coll(coll){}
  bool hasNext(){
    if (cont < coll.cont)
      return true;
    return false;
  }
  I next(){
    return coll.at(cont++);
  }
};

template <class I>
Iterator<I>* Collection<I>::getIterator(){
  return new Iterator<I>(*this);
}

template<class C, class Function, class T >
void find_if(Collection<C> coll, Function func, T object2){
  Iterator<C>* it = coll.getIterator();
  while (it->hasNext())
    func(it->next(), object2);
}

template<class C, class T>
void collision(C object, T object2 ){
  if (object->getX() == object2->getX() && object->getY() ==  object2->getY() && object->getID() != object2->getID()
  && object->getID()!=0 && object2->getID()!=0){
    std::cout << object2->getType()<< " collisioned with " << object->getType() << " and it was killed!" <<'\n';
    object2->kill();
  }
}

typedef void(*funcion)(General *, General *);

int main (){
  srand (time(NULL));
  Collection<General* > i;

  Spacecraft* ship = Spacecraft::getInstance();
  ship->setvalues(rand() % 10, rand() % 10 , "Planet exploration ships", 1);

  Asteroid* asteroid = Asteroid::getInstance();
  asteroid->setvalues(rand() % 10, rand() % 10, "Stony meteorites", 2);

  Planet* planet = Planet::getInstance();
  planet->setvalues(rand() % 10, rand() % 10, "Desert planet", 3);

  Board* game = Board::getInstance();
  i.addElement(ship);
  i.addElement(asteroid);
  i.addElement(planet);

  char shuffle = 'y';
  while (shuffle == 'y'){

    game->resetPlayer(ship->getX(), ship->getY());
    game->setPlayer(ship, rand() % 10, rand() % 10);
    find_if<General*, funcion, General*> (i, collision, ship);

    game->resetPlayer(asteroid->getX(), asteroid->getY());
    game->setPlayer(asteroid, rand() % 10, rand() % 10);

    game->resetPlayer(planet->getX(), planet->getY());
    game->setPlayer(planet, rand() % 10, rand() % 10);

    game->printBoard();
    std::cout << "Do you want to shuffle again (y/n)" << '\n';
    cin>> shuffle;
  }
}
