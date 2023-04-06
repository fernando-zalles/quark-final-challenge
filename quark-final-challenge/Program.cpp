#include <iostream>
#include <string>
#include "Presenter.h"
#include "View.h"

//using namespace std;

int main() {
	View view;
	Presenter presenter(view);
	presenter.start();

	return 0;
}