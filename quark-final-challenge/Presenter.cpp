#include "Presenter.h"
#include "View.h"
#include <iostream>

Presenter::Presenter(View view) {
    this->view_ = view;
}

void Presenter::start() {
	view_.initData();
	do {
		option_ = view_.showMenu();

		switch (option_)
		{
		case 1:
			view_.showHistory();
			break;
		case 2:
			system("CLS");
			view_.makeQuote();
			break;
		case 0:
			system("CLS");
			cout << "Saliendo..." << endl;
			break;
		case -2:
			break;
		default:
			view_.showWrongOptionText();
			break;
		}
	} while (option_ != 0);
}

Presenter::~Presenter() {}

