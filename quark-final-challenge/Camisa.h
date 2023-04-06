#ifndef CAMISA_H
#define CAMISA_H

#include <string>
#include "Prenda.h"

using namespace std;

class Camisa : public Prenda {
private:
    string tipoManga_;
    string tipoCuello_;
public:
    Camisa();
    Camisa(const int cantidad, const string tipoManga, const string tipoCuello, const string calidad);
    string getTipoManga();
    string getTipoCuello();
    void setTipoManga(string tipoManga);
    void setTipoCuello(string tipoCuello);
    float cotizar();
    ~Camisa();
};

#endif //CAMISA_H