#include <iostream>
using namespace std;


class FactoryProduct{
public:
  template<class Prod>
  Prod* factoryMethod(){
    return new Prod;
  }
};

class ProductA : public FactoryProduct{
public:
  void operatation(){
    std::cout << "estoy en el producto A" << '\n';
  }
};

int main() {
  FactoryProduct* p = new FactoryProduct;
  ProductA *a = p->factoryMethod<ProductA>();
  a->operatation();
}
