#ifndef PRENDA_H
#define PRENDA_H

#include <string>

using namespace std;

class Prenda {
private:
    string tipo_;
    string calidad_;
    float precio_;
    int cantidad_;
public:
    Prenda();
    Prenda(const string tipo, const string calidad, const float precio, const int cantidad);
    string getTipo();
    string getCalidad();
    float getPrecio();
    int getCantidad();
    void setTipo(string tipo);
    void setCalidad(string calidad);
    void setPrecio(float precio);
    void setCantidad(int cantidad);

    virtual string getTipoManga() { return ""; };
    virtual string getTipoCuello() { return ""; };
    virtual void setTipoManga(string tipoManga) {};
    virtual void setTipoCuello(string tipoCuello) {};
    virtual Prenda* addCamisa(int cantidad, string tipoManga, string tipoCuello, string calidad) { return new Prenda(); };

    virtual string getTipoPantalon() { return ""; };
    virtual void setTipoPantalon(string tipo) {};
    virtual Prenda* addPantalon(int cantidad, string tipoPantalon, string calidad) { return new Prenda(); };

    virtual float cotizar() { return 0.0; };
    ~Prenda();
};

#endif //PRENDA_H