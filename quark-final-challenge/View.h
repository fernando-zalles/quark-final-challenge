#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <vector>
#include "IView.h"
#include "Prenda.h"
#include "Cotizacion.h"

using namespace std;

class View : public IView {
private:
    int menuCamisa();
    int menuPantalon();
    int showCalidadMenu(Prenda* prenda);
    int showPriceMenu(Prenda* prenda);
    void showCotizacion(Cotizacion* cotizacion);
    void showCotizarHeader();
    int showMenuCamisaCuello(Prenda* camisa);
    int showStockMenu(Prenda* prenda);
public:
    int showMenu();
    void showHistory();
    void makeQuote();
    void initData();
    void showWrongOptionText();
    int showNotANumberErrorText();
};

#endif //VIEW_H