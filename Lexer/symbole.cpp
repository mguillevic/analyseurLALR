#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout.flush();
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Expression::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Entier::getValeur(){
   return valeur;
}


int Expression::getValeur(){
   return valeur;
}



