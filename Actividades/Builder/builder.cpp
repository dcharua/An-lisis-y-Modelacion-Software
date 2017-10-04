#include <iostream>
#include <string>

using namespace std;

class Motor{
  int potencia;
  int numSerie;
public:
  Motor() = default;
  Motor(int pot, int nS): potencia(pot), numSerie(nS){}
  int getPotencia(){return potencia;}
  int getNumSerie(){return numSerie;}
};

class Alas{
  string marca;
  int numSerie;
  int hiper;
  int spoilers;
public:
  Alas() = default;
  Alas(string m, int n, int h, int s): marca(m), numSerie(n), hiper(h), spoilers(s){}
  string getMarca(){return marca;}
  int getNumSerie(){return numSerie;}
  int getHiper(){return hiper;}
  int getSpoilers(){return spoilers;}
};
class Builder;

class Avion{
  friend class Builder;
  friend class BoeingBuilder;
  Alas* alas;
  Motor* motor;
  string marca;
  string modelo;
  int numSerie;
  void setAlas(Alas* a){alas = a;}
  void setMotor(Motor *m){motor = m;}
  void setMarca(string m){marca = m;}
  void setModelo(string m){modelo = m;}
  void setNumSerie(int n){numSerie= n;}
public:
  string getMarca(){return marca;}
  string getModelo(){return modelo;}
  int getNumSerie(){return numSerie;}
  Alas* getAlas(){return alas;}
  Motor* getMotor(){return motor;}
};

class Builder{
protected:
  Avion* avion;
public:
  Avion* getAvion(){return avion;}
  void createAvion(){
    avion = new Avion;
    Motor* motor = buildMotor();
    avion->setMotor(motor);
    Alas* alas = buildAlas();
    avion->setAlas(alas);
  }
  virtual Motor* buildMotor() = 0;
  virtual Alas* buildAlas() = 0;
  virtual string buildMarca() = 0;
  virtual string buildModelo() = 0;
  virtual int buildNumSerie() = 0;

};

class BoeingBuilder : public Builder{
public:
  Motor* buildMotor(){
    Motor* motor = new Motor(10000, 11111);
    avion->setMotor(motor);
    return motor;
  }
  Alas* buildAlas(){
    Alas* alas = new Alas("boeing", 10101, 10, 10);
    avion->setAlas(alas);
  }
  string buildMarca(){
    avion->setMarca("Boeing");
    return avion->getMarca();
  }
  string buildModelo(){
    avion->setModelo("776");
    return avion->getModelo();
  }
  int buildNumSerie(){
    avion->setNumSerie(23455);
    return avion->getNumSerie();
  }
};

class Director{
  Builder* builder;
public:
  void setBuilder(string tipoAvion){
    if (tipoAvion == "Boeing")
      builder = new BoeingBuilder;
  }
  Avion * getAvion(){return builder->getAvion();}
  void construct(){
    builder->createAvion();
    builder->buildAlas();
    builder->buildModelo();
    builder->buildMarca();
    builder->buildNumSerie();
  }
};

int main(){
  Director d;
  d.setBuilder("Boeing");
  d.construct();
  Avion* a = d.getAvion();
  std::cout << a->getMarca() << '\n';
}
