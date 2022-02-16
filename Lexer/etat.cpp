#include "etat.h"

Etat::Etat(){}
Etat::Etat(string s){
    name = s;
}
Etat::~Etat(){}

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
            Etat3 * etat3;
            automate.decalage(s,etat3);
            return true;
        case OPENPAR:
            Etat2 * etat2;
            automate.decalage(s, etat2);
            return true;
        case EXPR:
            Etat1 * etat1;
            automate.decalage(s,etat1);
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
            Etat4 * etat4;
            automate.decalage(s,etat4);
            return true;
        case MULT:
            Etat5 * etat5;
            automate.decalage(s, etat5);
            return true;
        case FIN:
            return false;
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}

bool Etat2::transition(Automate &automate, Symbole * s){
    switch(*s){
        case INT:
            Etat3 * etat3;
            automate.decalage(s,etat3);
            return true;
        case OPENPAR:
            Etat2 * etat2;
            automate.decalage(s, etat2);
            return true;
        case EXPR:
            Etat6 * etat6;
            automate.decalage(s, etat6);
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
            automate.deleteTopSymbole();
            automate.reduction(new Expression(e1->getValeur()),1);
            return true;
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
            Etat3 * etat3;
            automate.decalage(s,etat3);
            return true;
        case OPENPAR:
            Etat2 * etat2;
            automate.decalage(s, etat2);
            return true;
        case EXPR:
            Etat7 * etat7;
            automate.decalage(s, etat7);
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
            Etat3 * etat3;
            automate.decalage(s,etat3);
            return true;
        case OPENPAR:
            Etat2 * etat2;
            automate.decalage(s, etat2);
            return true;
        case EXPR:
            Etat8 * etat8;
            automate.decalage(s, etat8);
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
            Etat4 * etat4;
            automate.decalage(s,etat4);
            return true;
        case MULT:
            Etat5 * etat5;
            automate.decalage(s, etat5);
            return true;
        case CLOSEPAR:
            Etat9 * etat9;
            automate.decalage(s, etat9);
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
            automate.deleteTopSymbole();
            automate.deleteTopSymbole();
            Expression * e2 = (Expression *) automate.getTopSymbole();
            automate.deleteTopSymbole();
            automate.reduction(new Expression(e1->getValeur()+e2->getValeur()),3);
            return true;
        }
        case MULT:
            Etat5 * etat5;
            automate.decalage(s, etat5);
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
            Expression * e1 = (Expression *) automate.getTopSymbole();
            automate.deleteTopSymbole();
            automate.deleteTopSymbole();
            Expression * e2 = (Expression *) automate.getTopSymbole();
            automate.deleteTopSymbole();
            automate.reduction(new Expression(e1->getValeur()*e2->getValeur()),3);
            return true;
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
            Expression * e1 = (Expression *) automate.getTopSymbole();
            automate.deleteTopSymbole();
            automate.deleteTopSymbole();
            automate.reduction(new Expression(e1->getValeur()),3);
            return true;
        }
        default:
            automate.decalage(new Symbole(ERREUR),NULL);
            return false;
    }

    return false;
}