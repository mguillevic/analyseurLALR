/*************************************************************************
                           Symbole  -  description
                             -------------------
    début                : 16/02/22
    copyright            : (C) 2022 par M'BARECK Aichetou et GUILLEVIC Marie
*************************************************************************/

#include "Symbole.h"
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



