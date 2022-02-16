#include "automate.h"
#include "etat.h"

Automate::Automate(string flux){
    Lexer * lexer = new Lexer(flux);
    Etat0 * etat0;
    pileEtats.push(etat0);
}

Automate::~Automate(){}

void Automate::decalage(Symbole * s, Etat * etat){
    pileEtats.push(etat);
    pileSymboles.push(s);
}

void Automate::reduction(Symbole * s, int nbEtat){

    for(int i=0; i<nbEtat; i++){
        delete(pileEtats.top());
        pileEtats.pop();

    }

    pileEtats.top()->transition(*this,s);
    
}


Symbole * Automate::getTopSymbole(){
    return pileSymboles.top();
}

void Automate::deleteTopSymbole(){
    delete(pileSymboles.top());
    pileSymboles.pop();
}



