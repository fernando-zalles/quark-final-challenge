#pragma warning(disable: 4996)

#include "Cotizacion.h"
#include "Constants.h"
#include <string>
#include <chrono>
#include <ctime> 

int Cotizacion::idCount_ = 0;

Cotizacion::Cotizacion() {
    this->id_ = "";
    this->fecha_ = "";
    this->codigoVendedor_ = "";
    this->unidades_ = 0;
    this->resultado_ = 0;
}

Cotizacion::Cotizacion(const string id, const string fecha, const string codigoVendedor, const int unidades) {
    this->id_ = id;
    this->fecha_ = fecha;
    this->codigoVendedor_ = codigoVendedor;
    this->unidades_ = unidades;
}

string Cotizacion::getId() {
    return id_;
}

string Cotizacion::getFecha() {
    return fecha_;
}

string Cotizacion::getCodigoVendedor() {
    return codigoVendedor_;
}

Prenda* Cotizacion::getPrenda() {
    return prendaCotizada_;
}

int Cotizacion::getUnidades() {
    return unidades_;
}

float Cotizacion::getResultado() {
    return resultado_;
}

void Cotizacion::setId(string id) {
    this->id_ = id;
}

void Cotizacion::setFecha(string fecha) {
    this->fecha_ = fecha;
}

void Cotizacion::setCodigoVendedor(string codigoVendedor) {
    this->codigoVendedor_ = codigoVendedor;
}

void Cotizacion::setPrenda(Prenda* prendaCotizada) {
    this->prendaCotizada_ = prendaCotizada;
}

void Cotizacion::setUnidades(int unidades) {
    this->unidades_ = unidades;
}

void Cotizacion::getCotizacionFinal() {
    Prenda* prenda = this->getPrenda();
    float price = prenda->cotizar();
    this->resultado_ = price * this->getUnidades();
}

void Cotizacion::getCotizacionIdString() {
    incrementIdCount();
    string numberString = "0000" + to_string(idCount_);

    while (numberString.size() > 5) {
        numberString = numberString.erase(0, 1);
    }
    this->id_ = numberString;
}

void Cotizacion::incrementIdCount() {
    idCount_++;
}

void Cotizacion::addInfo(int unidades, Prenda* prenda, string codigoVendedor) {
    this->setUnidades(unidades);
    this->setPrenda(prenda);
    this->getCotizacionFinal();

    auto fechaCotizacion = chrono::system_clock::now();
    time_t fechaCotizacionFormatted = chrono::system_clock::to_time_t(fechaCotizacion);
    char* fechaCotizacionString = ctime(&fechaCotizacionFormatted);

    int len = strlen(fechaCotizacionString);

    if (len > 0 && fechaCotizacionString[len - 1] == '\n') {
        fechaCotizacionString[len - 1] = '\0';
    }

    this->setFecha(fechaCotizacionString);

    this->getCotizacionIdString();

    this->setCodigoVendedor(codigoVendedor);
}

Cotizacion::~Cotizacion() {
    delete prendaCotizada_;
}