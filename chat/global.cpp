#include "global.h"

std::function<void(QWidget*)>rePolish=[](QWidget*w){
    w->style()->unpolish(w);
    w->style()->polish(w);
};
