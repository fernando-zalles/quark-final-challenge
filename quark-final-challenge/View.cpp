#include <iostream>
#include <string>
#include "Tienda.h"
#include "Vendedor.h"
#include "Prenda.h"
#include "Camisa.h"
#include "Pantalon.h"
#include "View.h"
#include "Constants.h"

using namespace std;

vector<Prenda*> prendasDisponibles;
Tienda* tienda;
Vendedor* vendedor;
vector<Vendedor*> vendedores;

void View::initData() {
	Prenda* camisaCMP = new Camisa(100, CAMISA_M_CORTA, CAMISA_C_MAO, CALIDAD_PREMIUM);
	Prenda* camisaCMS = new Camisa(100, CAMISA_M_CORTA, CAMISA_C_MAO, CALIDAD_STANDARD);
	Prenda* camisaCCP = new Camisa(150, CAMISA_M_CORTA, CAMISA_C_COMUN, CALIDAD_PREMIUM);
	Prenda* camisaCCS = new Camisa(150, CAMISA_M_CORTA, CAMISA_C_COMUN, CALIDAD_STANDARD);
	prendasDisponibles.push_back(camisaCMP);
	prendasDisponibles.push_back(camisaCMS);
	prendasDisponibles.push_back(camisaCCP);
	prendasDisponibles.push_back(camisaCCS);

	Prenda* camisaLMP = new Camisa(75, CAMISA_M_LARGA, CAMISA_C_MAO, CALIDAD_PREMIUM);
	Prenda* camisaLMS = new Camisa(75, CAMISA_M_LARGA, CAMISA_C_MAO, CALIDAD_STANDARD);
	Prenda* camisaLCP = new Camisa(175, CAMISA_M_LARGA, CAMISA_C_COMUN, CALIDAD_PREMIUM);
	Prenda* camisaLCS = new Camisa(175, CAMISA_M_LARGA, CAMISA_C_COMUN, CALIDAD_STANDARD);
	prendasDisponibles.push_back(camisaLMP);
	prendasDisponibles.push_back(camisaLMS);
	prendasDisponibles.push_back(camisaLCP);
	prendasDisponibles.push_back(camisaLCS);

	Prenda* pantalonChP = new Pantalon(750, PANTALON_CHUPIN, CALIDAD_PREMIUM);
	Prenda* pantalonChS = new Pantalon(750, PANTALON_CHUPIN, CALIDAD_STANDARD);
	Prenda* pantalonCP = new Pantalon(250, PANTALON_COMUN, CALIDAD_PREMIUM);
	Prenda* pantalonCS = new Pantalon(250, PANTALON_COMUN, CALIDAD_STANDARD);
	prendasDisponibles.push_back(pantalonChP);
	prendasDisponibles.push_back(pantalonChS);
	prendasDisponibles.push_back(pantalonCP);
	prendasDisponibles.push_back(pantalonCS);
	
	tienda = new Tienda("Tu Estilo", "San Miguel calle 9 #23", prendasDisponibles, vendedores);
	vendedor = new Vendedor("Luis", "Garcia", "579L5", tienda);
	tienda->addVendedor(vendedor);
}

int View::showMenu() {
	system("CLS");
	int option;

	cout << "COTIZADOR EXPRESS - MENU PRINCIPAL" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Tienda: " + tienda->getNombre() << " | Direccion: " << tienda->getDireccion() << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Nombre Vendedor: " + vendedor->getNombre() + " " + vendedor->getApellido() << " | Codigo Vendedor: " << vendedor->getCodigo() << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "SELECCIONE UNA OPCION DEL MENU:" << endl;
	cout << endl;
	cout << "1) Historial de Cotizaciones" << endl;
	cout << "2) Realizar Cotizacion" << endl;
	cout << endl;
	cout << "0) Salir" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Opcion: ";
	
	cin >> option;
	if (!cin.fail() && option == -2) {
		showWrongOptionText();
	}
	option = cin.fail() ? showNotANumberErrorText() : option;

	return option;
}

void View::showCotizacion(Cotizacion* cotizacion) {
	Prenda* prenda = cotizacion->getPrenda();
	cout << "NUMERO DE IDENTIFICACION: " << cotizacion->getId() << endl;
	cout << "Fecha y Hora de la cotizacion: " << cotizacion->getFecha() << endl;
	cout << "Codigo del Vendedor: " << cotizacion->getCodigoVendedor() << endl;
	cout << "Prenda cotizada: " << prenda->getTipo() + " - " + (prenda->getTipoPantalon().size() ? prenda->getTipoPantalon() : prenda->getTipoManga() + " - " + prenda->getTipoCuello()) + " - " + prenda->getCalidad() << endl;
	cout << "Precio unitario: " << prenda->getPrecio() << endl;
	cout << "Cantidad de unidades cotizadas: " << cotizacion->getUnidades() << endl;
	cout << "Precio Final: " << cotizacion->getResultado() << endl;

	cout << endl;
	cout << endl;
}

void View::showHistory() {
	int option = -1;

	while (option != 0) {
		system("CLS");

		cout << "COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		cout << "Presiona 0 para volver atras" << endl;
		cout << "-------------------------------------------------------------------" << endl;

		for (Cotizacion* cotizacion: vendedor->getCotizaciones()) {
			showCotizacion(cotizacion);
		}

		cout << "-------------------------------------------------------------------" << endl;
		cout << "Presiona 0 para volver atras" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		cin >> option;
		if (!cin.fail() && option == -2) {
			showWrongOptionText();
		}
		option = cin.fail() ? showNotANumberErrorText() : option;

		if (option != 0 && option != -2) {
			showWrongOptionText();
		}
	}
}

void View::showCotizarHeader() {
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Presiona  0 para volver al menu principal" << endl;
	cout << "Presiona -1 para ver el historial de cotizaciones" << endl;
	cout << "-------------------------------------------------------------------" << endl;
}

int View::showStockMenu(Prenda* prenda) {
	int option = -1;
	int prendaStock = 0;
	Cotizacion* cotizacion = new Cotizacion();
	
	while (option != 0) {
		system("CLS");
		prendaStock = tienda->getPrendaStock(prenda);
		showCotizarHeader();
		cout << "INFORMACION:" << endl;
		cout << "EXISTE(N) " << prendaStock << " UNIDADES EN STOCK DE LA PRENDA SELECCIONADA" << endl;
		cout << endl;
		cout << "PASO 5: Ingrese la cantidad de unidades a cotizar" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		
		cin >> option;
		if (!cin.fail() && option == -2) {
			showWrongOptionText();
		}
		option = cin.fail() ? showNotANumberErrorText() : option;

		if (option > 0) {
			if (option <= prendaStock) {
				cotizacion->addInfo(option, prenda, vendedor->getCodigo());
				cotizacion->getCotizacionFinal();

				vendedor->addCotizacion(cotizacion);

				while (option != 0) {
					system("CLS");
					showCotizarHeader();
					showCotizacion(cotizacion);
					cout << "-------------------------------------------------------------------" << endl;
					cout << "Presiona 0 para volver al menu principal" << endl;
					cout << "-------------------------------------------------------------------" << endl;
					cin >> option;
					if (!cin.fail() && option == -2) {
						showWrongOptionText();
					}
					option = cin.fail() ? showNotANumberErrorText() : option;

					if (option != 0 && option != -1 && option != -2) {
						showWrongOptionText();
					}
					else if (option == -1) {
						showHistory();
					}
				}
			}
			else {
				cout << "Error: No se puede realizar una cotizacion sobre una cantidad de stock no disponible. Presione Enter para continuar" << endl;
				cin.get();
				cin.get();
			}
		}
		else if (option == -1) {
			showHistory();
		}
		else if (option != -2 && option !=0) {
			showWrongOptionText();
		}
	}

	return option;
}

int View::showPriceMenu(Prenda* prenda) {
	float option = -1;

	while (option != 0) {
		system("CLS");

		showCotizarHeader();
		cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		cin >> option;
		if (!cin.fail() && option <= -2) {
			showWrongOptionText();
		}
		option = cin.fail() ? showNotANumberErrorText() : option;

		if (option > 0) {
			prenda->setPrecio(option);
			option = showStockMenu(prenda);
		}
		else if (option == -1) {
			showHistory();
		}
	}

	return option;
}

int View::showCalidadMenu(Prenda* prenda) {
	int option = -1;

	while (option != 0) {
		system("CLS");

		showCotizarHeader();
		cout << "PASO 3: Seleccione la calidad de la prenda" << endl;
		cout << "1) Standard" << endl;
		cout << "2) Premium" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		
		cin >> option;
		if (!cin.fail() && option == -2) {
			showWrongOptionText();
		}
		option = cin.fail() ? showNotANumberErrorText() : option;

		switch (option)
		{
		case 1:
			prenda->setCalidad(CALIDAD_STANDARD);
			break;
		case 2:
			prenda->setCalidad(CALIDAD_PREMIUM);
			break;
		case -1:
			showHistory();
		case -2:
		case 0:
			break;
		default:
			showWrongOptionText();
			break;
		}

		if (option <= 2 && option > 0) {
			option = showPriceMenu(prenda);
		}
	}

	return option;
}

int View::showMenuCamisaCuello(Prenda* camisa) {
	int option = -1;

	while (option != 0) {
		system("CLS");

		showCotizarHeader();
		cout << "PASO 2.b: La Camisa a cotizar, es Cuello Mao?" << endl;
		cout << "1) Si" << endl;
		cout << "2) No" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		
		cin >> option;
		if (!cin.fail() && option == -2) {
			showWrongOptionText();
		}
		option = cin.fail() ? showNotANumberErrorText() : option;

		switch (option)
		{
		case 1:
			camisa->setTipoCuello(CAMISA_C_MAO);
			break;
		case 2:
			camisa->setTipoCuello(CAMISA_C_COMUN);
			break;
		case -1:
			showHistory();
		case -2:
		case 0:
			break;
		default:
			showWrongOptionText();
			break;
		}

		if (option <= 2 && option > 0) {
			option = showCalidadMenu(camisa);
		}
	}

	return option;
}

int View::menuCamisa() {
	int option = -1;
	Prenda* camisa = new Camisa();
	camisa->setTipo(TIPO_CAMISA);

	while (option != 0) {
		system("CLS");

		showCotizarHeader();
		cout << "PASO 2.a: La Camisa a cotizar, es Manga corta?" << endl;
		cout << "1) Si" << endl;
		cout << "2) No" << endl;
		cout << "-------------------------------------------------------------------" << endl;

		cin >> option;
		if (!cin.fail() && option == -2) {
			showWrongOptionText();
		}
		option = cin.fail() ? showNotANumberErrorText() : option;

		switch (option)
		{
		case 1:
			camisa->setTipoManga(CAMISA_M_CORTA);
			break;
		case 2:
			camisa->setTipoManga(CAMISA_M_LARGA);
			break;
		case -1:
			showHistory();
		case -2:
		case 0:
			break;
		default:
			showWrongOptionText();
			break;
		}

		if (option <= 2 && option > 0) {
			option = showMenuCamisaCuello(camisa);
		}
	}

	return option;
}

int View::menuPantalon() {
	int option = -1;
	string str;
	Prenda* pantalon = new Pantalon();
	pantalon->setTipo(TIPO_PANTALON);

	while (option != 0) {
		system("CLS");

		showCotizarHeader();
		cout << "PASO 2: El Pantalon a cotizar es Chupin?" << endl;
		cout << "1) Si" << endl;
		cout << "2) No" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		
		cin >> option;
		if (!cin.fail() && option == -2) {
			showWrongOptionText();
		}
		option = cin.fail() ? showNotANumberErrorText() : option;

		switch (option)
		{
		case 1:
			pantalon->setTipoPantalon(PANTALON_CHUPIN);
			break;
		case 2:
			pantalon->setTipoPantalon(PANTALON_COMUN);
			break;
		case -1:
			showHistory();
		case -2:
		case 0:
			break;
		default:
			showWrongOptionText();
			break;
		}

		if (option <= 2 && option > 0) {
			option = showCalidadMenu(pantalon);
		}
	}

	return option;
}

void View::makeQuote() {
	int option = -1;

	while (option != 0) {
		system("CLS");

		showCotizarHeader();
		cout << "PASO 1: Selecciona la prenda a cotizar:" << endl;
		cout << "1) Camisa" << endl;
		cout << "2) Pantalon" << endl;
		cout << "-------------------------------------------------------------------" << endl;

		cin >> option;
		if (!cin.fail() && option == -2) {
			showWrongOptionText();
		}
		option = cin.fail() ? showNotANumberErrorText() : option;

		switch (option)
		{
		case 1:
			option = menuCamisa();
			break;
		case 2:
			option = menuPantalon();
			break;
		case -1:
			showHistory();
		case -2:
		case 0:
			break;
		default:
			showWrongOptionText();
			break;
		}
	}
}

void View::showWrongOptionText() {
	cout << "Opcion incorrecta. Presiona Enter para continuar" << endl;
	cin.get();
	cin.get();
}

int View::showNotANumberErrorText() {
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Por favor introduzca un numero. Presiona Enter para continuar" << endl;
	cin.get();

	return -2;
}