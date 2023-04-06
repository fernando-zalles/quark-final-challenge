#ifndef PANTALON_H
#define PANTALON_H

#include <string>
#include "Prenda.h"

using namespace std;

class Pantalon : public Prenda {
private:
    string tipoPantalon_;
public:
    Pantalon();
    Pantalon(const int cantidad, const string tipo, const string calidad);
    string getTipoPantalon();
    void setTipoPantalon(string tipo);
    float cotizar();
    ~Pantalon();
};

#endif //PANTALON_H