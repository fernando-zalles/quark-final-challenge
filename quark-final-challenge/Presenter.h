#ifndef PRESENTER_H
#define PRESENTER_H

#include <string>
#include <vector>
#include "View.h"

using namespace std;

class Presenter {
private:
    View view_;
    int option_;
public:
    Presenter(View view);
    void start();
    ~Presenter();
};

#endif //PRESENTER_H