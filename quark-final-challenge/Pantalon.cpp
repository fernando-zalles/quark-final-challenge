#include "Pantalon.h"
#include "Constants.h"
#include <iostream>
#include <string>

Pantalon::Pantalon() {
    this->tipoPantalon_ = "";
}

Pantalon::Pantalon(const int cantidad, const string tipo, const string calidad) {
    this->tipoPantalon_ = tipo;
    this->setCantidad(cantidad);
    this->setCalidad(calidad);
    this->setTipo(TIPO_PANTALON);
}

string Pantalon::getTipoPantalon() {
    return tipoPantalon_;
}

void Pantalon::setTipoPantalon(string tipo) {
    this->tipoPantalon_ = tipo;
}

float Pantalon::cotizar() {
    float price = this->getPrecio();

    if (this->getTipoPantalon() == PANTALON_CHUPIN) {
        price -= price * (0.12);
    }

    if (this->getCalidad() == CALIDAD_PREMIUM) {
        price += price * (0.3);
    }

    return price;
}

Pantalon::~Pantalon() {}