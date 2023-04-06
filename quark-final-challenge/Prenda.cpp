#include "Prenda.h"

#include <string>

Prenda::Prenda() {
    this->calidad_ = "";
    this->precio_ = 0;
    this->cantidad_ = 0;
    this->tipo_ = "";
}

Prenda::Prenda(const string tipo, const string calidad, const float precio, const int cantidad) {
    this->calidad_ = calidad;
    this->precio_ = precio;
    this->cantidad_ = cantidad;
    this->tipo_ = tipo;
}

string Prenda::getTipo() {
    return tipo_;
}

string Prenda::getCalidad() {
    return calidad_;
}

float Prenda::getPrecio() {
    return precio_;
}

int Prenda::getCantidad() {
    return cantidad_;
}

void Prenda::setTipo(string tipo) {
    this->tipo_ = tipo;
}

void Prenda::setCalidad(string calidad) {
    this->calidad_ = calidad;
}

void Prenda::setPrecio(float precio) {
    this->precio_ = precio;
}

void Prenda::setCantidad(int cantidad) {
    this->cantidad_ = cantidad;
}

Prenda::~Prenda() {}