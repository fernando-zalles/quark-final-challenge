#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>
#include "Prenda.h"

using namespace std;

class Vendedor;

class Tienda {
private:
    string nombre_;
    string direccion_;
    vector<Prenda*> listaPrendas_;
    vector<Vendedor*> vendedores_;
public:
    Tienda(const string nombre, const string direccion, const vector<Prenda*> listaPrendas, const vector<Vendedor*> vendedor);
    string getNombre();
    string getDireccion();
    vector<Prenda*> getListaPrendas();
    void addVendedor(Vendedor* vendedor);
    int getPrendaStock(Prenda* prenda);
    ~Tienda();
};

#endif //TIENDA_H