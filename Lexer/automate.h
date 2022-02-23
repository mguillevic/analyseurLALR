/*************************************************************************
                           Automate  -  description
                             -------------------
    début                : 16/02/22
    copyright            : (C) 2022 par M'BARECK Aichetou et GUILLEVIC Marie
*************************************************************************/
#if ! defined ( AUTOMATE_H )
#define AUTOMATE_H

#pragma once

#include <string>
#include <stack>
using namespace std;

#include "Lexer.h"
#include "Symbole.h"

class Etat;

class Automate {
   public:
      Automate(string flux);
      virtual ~Automate();
      void decalage(Symbole * s, Etat * etat);
      void reduction(Symbole * s, int nbEtat);
      Symbole * getTopSymbole();
      void deleteTopSymbole();
      void run();

   private:
      Lexer * lexer;
      stack<Symbole *> pileSymboles;
      stack<Etat *> pileEtats;

};
#endif //AUTOMATE_H