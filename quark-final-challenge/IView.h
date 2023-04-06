#ifndef IVIEW_H
#define IVIEW_H

using namespace std;

class IView {
public:
	virtual int showMenu() = 0;
	virtual void showHistory() = 0;
	virtual void makeQuote() = 0;
	virtual void initData() = 0;
	virtual void showWrongOptionText() = 0;
	virtual int showNotANumberErrorText() = 0;
};

#endif //IVIEW_H