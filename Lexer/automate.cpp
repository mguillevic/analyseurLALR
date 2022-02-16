#include "automate.h"
#include "etat.h"

#include <iostream>
using namespace std;

Automate::Automate(string flux){
    lexer = new Lexer(flux);
    Etat0 * etat0= new Etat0();
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

void Automate::run(){
   Symbole * s;
   bool stop =false;
   while(!stop) {
      s=lexer->Consulter();
      bool avancer = pileEtats.top()->transition(*this,s);
      if((*s==FIN && avancer) || *pileSymboles.top()==ERREUR){
          stop=true;
      }
      if(avancer){lexer->Avancer();}
   }
   
   if(*pileSymboles.top()==ERREUR){
       cout<<"La syntaxe est non valide"<<endl;
   }else{
       cout<<"La syntaxe est valide. La valeur calculéé est égal à: "<<((Expression *) pileSymboles.top())->getValeur()<<endl;
   }
   
    
}



