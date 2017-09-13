//Daniel Charua 13/09/17

#include  <iostream>
using namespace std;
typedef void(*funcion)(int);

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
    array = new C(size);
  }

  void addElement(C value){
    if (cont <= size)
      array[cont++] = value;
    else
      std::cout << "ya no hay espacio para agregar elementos" << '\n';
  }

  Iterator<C>* getIterator();

  int at(int pos){
    return array[pos];
  }
};

template <class I>
class Iterator{
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
  int next(){
    return coll.at(cont++);
  }
};

template <class I>
Iterator<I>* Collection<I>::getIterator(){
  return new Iterator<I>(*this);
}

template<class C, class Function>
void find_if(Collection<C> coll, Function func){
  Iterator<C>* it = coll.getIterator();
  while (it->hasNext())
    func(it->next());
}

template<class C>
void isEven(C num){
  if (num % 2 == 0)
  std::cout << num << '\n';
}


int main(){
  Collection<int> i;
  i.addElement(1);
  i.addElement(4);
  i.addElement(2);
  i.addElement(3);
  find_if<int, funcion> (i, isEven);

}
