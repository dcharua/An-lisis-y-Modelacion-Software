#include <iostream>
using namespace std;


class Fabrica{
public:
  string nombre;

  void instalacion(){
  seleccionComponentes();
  ensambladoComponentes();
  instalacionConfiguracionSoftware();
  empaquetadoComputador();
  std::cout << "Instalacion terminada!" << '\n';
  }

  void seleccionComponentes(){
    std::cout << "En seleccion de componentes..." << '\n';
  }
  void ensambladoComponentes(){
    std::cout << "En ensamblado de componentes..." << '\n';
  }
  void instalacionConfiguracionSoftware(){
    std::cout << "En instalacion de configuracion del software..." << '\n';
  }
  void empaquetadoComputador(){
    std::cout << "En empaquetado del computador..." << '\n';
  }
  template<class Prod>
  Prod* crear(){
    return new Prod;
  }
};

class Laptop : public Fabrica{
public:
  void queSoy(){
    std::cout << "Soy Laptop" << '\n';
  }
};
class Desktop : public Fabrica{
public:
  void queSoy(){
    std::cout << "Soy Desktop" << '\n';
  }
};
class Netbook : public Fabrica{
public:
  void queSoy(){
    std::cout << "Soy Netbook" << '\n';
  }
};
class Tablet : public Fabrica{
public:
  void queSoy(){
    std::cout << "Soy Tablet" << '\n';
  }
};
class Rack : public Fabrica{
public:
  void queSoy(){
    std::cout << "Soy Rack" << '\n';
  }
};
class Tower : public Fabrica{
public:
  void queSoy(){
    std::cout << "Soy Tower" << '\n';
  }
};

int main() {
  Fabrica* f = new Fabrica;

  int op;
  std::cout << "Seleciona que quieres crear"<<'\n' << "1.- Laptop" <<'\n' << "2.- Desktop" <<
  '\n' << "3.- Netbook" <<'\n' << "4.- Tablet" <<'\n' << "5.- Rack" <<'\n' << "6.- Tower"<< '\n' ;
  std::cin >> op;
  switch (op) {
    case 1: {Laptop *a = f->crear<Laptop>();
      a->instalacion();
      a->queSoy();
      a->nombre = "la mas chingona";
      std::cout << "me llamo " <<a->nombre << '\n';
    break;}

    case 2: { Desktop *d = f->crear<Desktop>();
      d->instalacion();
      d->queSoy();
    break;}

    case 3: {Netbook *n = f->crear<Netbook>();
      n->instalacion();
      n->queSoy();
    break;}

    case 4: { Tablet *t = f->crear<Tablet>();
      t->instalacion();
      t->queSoy();
    break;}

    case 5: {Rack *r = f->crear<Rack>();
      r->instalacion();
      r->queSoy();
    break;}

    case 6: { Tower *t = f->crear<Tower>();
      t->instalacion();
      t->queSoy();
    break;}

    default: std::cout << "Esa opcion no existe" << '\n';
    break;
  }
  return 0;
}
