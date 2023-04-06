#include "Vendedor.h"

#include <string>

Vendedor::Vendedor(const string nombre, const string apellido, const string codigo, Tienda* tienda) {
    this->nombre_ = nombre;
    this->apellido_ = apellido;
    this->codigo_ = codigo;
    this->tienda_ = tienda;
}

string Vendedor::getNombre() {
    return nombre_;
}

string Vendedor::getApellido() {
    return apellido_;
}

string Vendedor::getCodigo() {
    return codigo_;
}

vector<Cotizacion*> Vendedor::getCotizaciones() {
    return cotizaciones_;
}

void Vendedor::addCotizacion(Cotizacion* cotizacion) {
    cotizaciones_.push_back(cotizacion);
}

Vendedor::~Vendedor() {
    delete tienda_;
    for (Cotizacion* cotizacion : cotizaciones_) {
        delete(cotizacion);
    }
}
