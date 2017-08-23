#include <iostream>
using namespace std;

class Product{
public:
  void operatation(){
    std::cout << "creado" << '\n';
  }
  void operatation2(){
    std::cout << "creado2" << '\n';
  }
};

class Creator{
private:
  virtual Product* createProduct(int type) = 0;
public:
  Product* factoryMethod(int type){
    Product *p = createProduct(type);
    p->operatation();
    return p;
  }
};

class CreatorA : public Creator{
public:
  Product* createProduct(int type){
    if (type == 1) return new Product;
    return new Product;
  }
};

int main() {
  //Creator must be Singleton, with private constructors
  Creator* c = new CreatorA;
  Product* p = c->factoryMethod(1);
  p->operatation2();

  delete p,c;
}
