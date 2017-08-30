#include <iostream>
#include <string>
using namespace std;

class Mundo{
public:
  Mundo(string nombreMundo): nombreMundo(nombreMundo){}
  string nombreMundo;
};

class Personaje{
public:
  Personaje () = default;
  Personaje(string nombre) :nombre(nombre){}
  string nombre;
  string correo;
  int telefono;
  Mundo* mundo;
  virtual Personaje* clone() = 0;
};

template <class Base, class SubClass>
class Clone : public Base{
public:
  Base* clone(){
    return new SubClass(dynamic_cast<SubClass&>(*this));
  }
};

class Princesa : public Clone<Personaje, Princesa>{
public:
  Princesa(string n){
    nombre = n;
  }
  Princesa(const Princesa& p){
    nombre = p.nombre;
    correo = p.correo;
    telefono = p.telefono;
    mundo = new Mundo(p.mundo->nombreMundo);
  }
  void gritar(){std::cout << "aaaaaaaaaaaaaa" << '\n';}
};

int main(){
  Princesa* pri = new Princesa("Rapunzel");
  pri->correo = "princesa@hotmail.com";
  pri->telefono = 5534663;
  pri->mundo = new Mundo("Paleta");
  Princesa* p = dynamic_cast<Princesa*>(pri->clone());
  pri->nombre = "Bestia";
  pri->mundo->nombreMundo= "Paleton";
  std::cout << p->nombre << '\n';
  std::cout << p->telefono << '\n';
  std::cout << p->correo << '\n';
  std::cout << p->mundo->nombreMundo << '\n';
  Princesa* pp = dynamic_cast<Princesa*>(pri->clone());
  pp->mundo->nombreMundo = "Paletita";
}
