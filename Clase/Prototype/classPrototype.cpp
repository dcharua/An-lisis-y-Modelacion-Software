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

class Princesa : public Personaje{
public:
  Princesa(string n) : Personaje(n){}
  Princesa(const Princesa& p){
    nombre = p.nombre;
    correo = p.correo;
    telefono = p.telefono;
    mundo = new Mundo(p.mundo->nombreMundo);
  }
  void gritar(){std::cout << "aaaaaaaaaaaaaa" << '\n';}
  Personaje* clone(){
    return new Princesa(*this);
  }
};

class Villano : public Personaje{
public:
  Villano(string n) : Personaje(n){}
  Villano(const Villano& v){
    nombre = v.nombre;
    correo = v.correo;
    telefono = v.telefono;
    mundo = new Mundo(v.mundo->nombreMundo);
  }
  void secuerstrar(){std::cout << "te atrape" << '\n';}
  Personaje* clone(){
    return new Villano(*this);
  }
};

class Heroe : public Personaje{
public:
  Heroe(string n) : Personaje(n){}
  Heroe(const Heroe& h){
    nombre = h.nombre;
    correo = h.correo;
    telefono = h.telefono;
    mundo = new Mundo(h.mundo->nombreMundo);
  }
  void gritar(){std::cout << "yo te rescato" << '\n';}
  Personaje* clone(){
    return new Heroe(*this);
  }
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
}
