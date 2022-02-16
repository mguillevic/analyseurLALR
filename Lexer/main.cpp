#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("5+6*9");

   Automate automate(chaine);
   automate.run();

   return 0;
}

