#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("5*8+6");

   Automate automate(chaine);
   automate.run();

   return 0;
}

