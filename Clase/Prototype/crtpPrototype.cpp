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

template <class SubClase>
class ClonPersonaje : public Personaje{
public:
  Personaje* clone(){
    return new SubClase(dynamic_cast <SubClase&>(*this));
  }
};

class Princesa : public ClonPersonaje <Princesa>{
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

class Villano : public ClonPersonaje<Villano>{
public:
  Villano(string n){
    nombre = n;
  }
  Villano(const Villano& v){
    nombre = v.nombre;
    correo = v.correo;
    telefono = v.telefono;
    mundo = new Mundo(v.mundo->nombreMundo);
  }
  void secuerstrar(){std::cout << "te atrape" << '\n';}
};

class Heroe : public ClonPersonaje<Heroe>{
public:
  Heroe(string n){
    nombre = n;
  }
  Heroe(const Heroe& h){
    nombre = h.nombre;
    correo = h.correo;
    telefono = h.telefono;
    mundo = new Mundo(h.mundo->nombreMundo);
  }
  void gritar(){std::cout << "yo te rescato" << '\n';}
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
