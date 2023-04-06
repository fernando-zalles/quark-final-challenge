#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>
#include <vector>
#include "Cotizacion.h"

using namespace std;

class Tienda;

class Vendedor {
private:
    string nombre_;
    string apellido_;
    string codigo_;
    vector<Cotizacion*> cotizaciones_;
    Tienda* tienda_;
public:
    Vendedor(const string nombre, const string apellido, const string codigo, Tienda* tienda);
    string getNombre();
    string getApellido();
    string getCodigo();
    vector<Cotizacion*> getCotizaciones();
    void addCotizacion(Cotizacion* cotizacion);
    ~Vendedor();
};

#endif //VENDEDOR_H