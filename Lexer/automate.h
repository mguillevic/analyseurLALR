#pragma once

#include <string>
#include <stack>
using namespace std;

#include "lexer.h"
#include "symbole.h"
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