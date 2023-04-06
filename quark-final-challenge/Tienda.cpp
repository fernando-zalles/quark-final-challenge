#include "Tienda.h"
#include "Constants.h"
#include <iostream>

#include <string>

Tienda::Tienda(const string nombre, const string direccion, const vector<Prenda*> listaPrendas, const vector<Vendedor*> vendedor) {
    this->nombre_ = nombre;
    this->direccion_ = direccion;
    this->listaPrendas_ = listaPrendas;
    this->vendedores_ = vendedor;
}

string Tienda::getNombre() {
    return nombre_;
}

string Tienda::getDireccion() {
    return direccion_;
}

vector<Prenda*> Tienda::getListaPrendas() {
    return listaPrendas_;
}

int Tienda::getPrendaStock(Prenda* prenda) {
    for (Prenda* prendaStock : this->getListaPrendas()) {
        if (prendaStock->getTipo() == prenda->getTipo()) {
            if (prendaStock->getTipoManga() == prenda->getTipoManga()) {
                if (prendaStock->getTipoCuello() == prenda->getTipoCuello()) {
                    if (prendaStock->getTipoPantalon() == prenda->getTipoPantalon()) {
                        if (prendaStock->getCalidad() == prenda->getCalidad()) {
                            return prendaStock->getCantidad();
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void Tienda::addVendedor(Vendedor* vendedor) {
    vendedores_.push_back(vendedor);
}

Tienda::~Tienda() {
    for (Prenda* prenda : listaPrendas_) {
        delete(prenda);
    }
    for (Vendedor* vendedor : vendedores_) {
        delete(vendedor);
    }
}