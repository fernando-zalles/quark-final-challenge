#include "Camisa.h"
#include "Constants.h"
#include <iostream>
#include <string>

Camisa::Camisa() {
    this->tipoManga_ = "";
    this->tipoCuello_ = "";
    this->setTipo("");
    this->setCalidad("");
    this->setPrecio(0);
    this->setCantidad(0);
    this->setTipo(TIPO_CAMISA);
}

Camisa::Camisa(const int cantidad, const string tipoManga, const string tipoCuello, const string calidad) {
    this->tipoManga_ = tipoManga;
    this->tipoCuello_ = tipoCuello;
    this->setCantidad(cantidad);
    this->setCalidad(calidad);
    this->setTipo(TIPO_CAMISA);
}

string Camisa::getTipoManga() {
    return tipoManga_;
}

string Camisa::getTipoCuello() {
    return tipoCuello_;
}

void Camisa::setTipoManga(string tipoManga) {
    this->tipoManga_ = tipoManga;
}

void Camisa::setTipoCuello(string tipoCuello) {
    this->tipoCuello_ = tipoCuello;
}

float Camisa::cotizar() {
    float price = this->getPrecio();

    if (this->getTipoManga() == CAMISA_M_CORTA) {
        price -= price * (0.1);
    }

    if (this->getTipoCuello() == CAMISA_C_MAO) {
        price += price * (0.03);
    }

    if (this->getCalidad() == CALIDAD_PREMIUM) {
        price += price * (0.3);
    }

    return price;
}

Camisa::~Camisa() {}