/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 16/02/22
    copyright            : (C) 2022 par M'BARECK Aichetou et GUILLEVIC Marie
*************************************************************************/

#include <iostream>
#include "Lexer.h"
#include "Automate.h"


int main(void) {
   string chaine("");

   cout << "Quelle chaine de charactere voulez vous analiser ?" << endl;
   cin >>chaine;

   Automate automate(chaine);
   automate.run();

   return 0;
}

