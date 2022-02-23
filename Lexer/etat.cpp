/*************************************************************************
                           Etat  -  description
                             -------------------
    début                : 16/02/22
    copyright            : (C) 2022 par M'BARECK Aichetou et GUILLEVIC Marie
*************************************************************************/

#include <iostream>
#include <string>
using namespace std;


#include "Etat.h"

Etat::Etat(){}
Etat::Etat(string s){
    name = s;
}
Etat::~Etat(){}

Etat0::~Etat0(){}

Etat1::~Etat1(){}

Etat2::~Etat2(){}

Etat3::~Etat3(){}

Etat4::~Etat4(){}

Etat5::~Etat5(){}

Etat6::~Etat6(){}

Etat7::~Etat7(){}

Etat8::~Etat8(){}

Etat9::~Etat9(){}

Etat0::Etat0() : Etat("E0"){}

Etat1::Etat1() : Etat("E1"){}

Etat2::Etat2() : Etat("E2"){}

Etat3::Etat3() : Etat("E3"){}

Etat4::Etat4() : Etat("E4"){}

Etat5::Etat5() : Etat("E5"){}

Etat6::Etat6() : Etat("E6"){}

Etat7::Etat7() : Etat("E7"){}

Etat8::Etat8() : Etat("E8"){}

Etat9::Etat9() : Etat("E9"){}

bool Etat0::transition(Automate &automate, Symbole * s){
    switch(*s){
        case INT:
            automate.decalage(s,new Etat3());
            return true;
        case OPENPAR:
            automate.decalage(s, new Etat2());
            return true;
        case EXPR:
            automate.decalage(s,new Etat1());
            return true;
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}

bool Etat1::transition(Automate &automate, Symbole * s){
    switch(*s){
        case PLUS:
            automate.decalage(s,new Etat4());
            return true;
        case MULT:
            automate.decalage(s, new Etat5());
            return true;
        case FIN:
            return true;
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}

bool Etat2::transition(Automate &automate, Symbole * s){
    switch(*s){
        case INT:
            automate.decalage(s,new Etat3());
            return true;
        case OPENPAR:
            automate.decalage(s, new Etat2());
            return true;
        case EXPR:
            automate.decalage(s, new Etat6());
            return true;
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}

bool Etat3::transition(Automate &automate, Symbole * s){
    switch(*s){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
        {
            Entier * e1 = (Entier *) automate.getTopSymbole();
            int val = e1->getValeur();
            automate.deleteTopSymbole();
            
            automate.reduction(new Expression(val),1);
            return false;
        }
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}

bool Etat4::transition(Automate &automate, Symbole * s){
    switch(*s){
        case INT:
            automate.decalage(s,new Etat3());
            return true;
        case OPENPAR:
            automate.decalage(s, new Etat2());
            return true;
        case EXPR:
            automate.decalage(s, new Etat7);
            return true;
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}

bool Etat5::transition(Automate &automate, Symbole * s){
    switch(*s){
        case INT:
            automate.decalage(s,new Etat3());
            return true;
        case OPENPAR:
            automate.decalage(s, new Etat2());
            return true;
        case EXPR:
            automate.decalage(s, new Etat8());
            return true;
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}

bool Etat6::transition(Automate &automate, Symbole * s){
    switch(*s){
        case PLUS:
            automate.decalage(s,new Etat4());
            return true;
        case MULT:
            automate.decalage(s, new Etat5());
            return true;
        case CLOSEPAR:
            automate.decalage(s, new Etat9());
            return true;
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}


bool Etat7::transition(Automate &automate, Symbole * s){
    switch(*s){
        case PLUS:
        case CLOSEPAR:
        case FIN:
        {
            Expression * e1 = (Expression *) automate.getTopSymbole();
            int val1 = e1->getValeur();
            automate.deleteTopSymbole();
            automate.deleteTopSymbole();
            Expression * e2 = (Expression *) automate.getTopSymbole();
            int val2 = e2->getValeur();
            automate.deleteTopSymbole();
            automate.reduction(new Expression(val1+val2),3);
            return false;
        }
        case MULT:
            automate.decalage(s, new Etat5());
            return true;
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}

bool Etat8::transition(Automate &automate, Symbole * s){
    switch(*s){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
        {
            Expression *e1 = (Expression *) automate.getTopSymbole();
            int val1 = e1->getValeur();
            automate.deleteTopSymbole();
            automate.deleteTopSymbole();
            Expression *e2 = (Expression *) automate.getTopSymbole();
            int val2 = e2->getValeur();
            automate.deleteTopSymbole();
            automate.reduction(new Expression(val1*val2),3);
            return false;
        }
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}

bool Etat9::transition(Automate &automate, Symbole * s){
    switch(*s){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
        {
            automate.deleteTopSymbole();
            Expression *e1 = (Expression *) automate.getTopSymbole();
            int val = e1->getValeur();
            automate.deleteTopSymbole();
            automate.deleteTopSymbole();
            automate.reduction(new Expression(val),3);
            return false;
        }
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}

// int Etat0::getEtat(){
//     return etat;
// }