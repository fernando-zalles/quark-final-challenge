#ifndef COTIZACION_H
#define COTIZACION_H

#include <string>
#include "Prenda.h"

using namespace std;

class Cotizacion {
private:
    string id_;
    string fecha_;
    string codigoVendedor_;
    Prenda* prendaCotizada_;
    int unidades_;
    float resultado_;
    static int idCount_;
public:
    Cotizacion();
    Cotizacion(const string id, const string fecha, const string codigoVendedor, const int unidades);
    string getId();
    string getFecha();
    string getCodigoVendedor();
    Prenda* getPrenda();
    int getUnidades();
    float getResultado();
    void setId(string id);
    void setFecha(string fecha);
    void setCodigoVendedor(string codigoVendedor);
    void setPrenda(Prenda* prendaCotizada);
    void setUnidades(int unidades);
    void getCotizacionFinal();
    void getCotizacionIdString();
    void incrementIdCount();
    void addInfo(int unidades, Prenda* prenda, string codigoVendedor);
    ~Cotizacion();
};

#endif //COTIZACION_H