#pragma once

#include <string>
using namespace std;

#include "automate.h"
#include "symbole.h"

class Etat0;
class Etat1;
class Etat2;
class Etat3;
class Etat4;
class Etat5;
class Etat6;
class Etat7;
class Etat8;
class Etat9;

class Etat {
   public:
      Etat();
      Etat(string s);
      virtual ~Etat();
      virtual bool transition(Automate &automate, Symbole * s)=0;
      string getName();
      // virtual int getEtat();

      protected:
        string name;
};

class Etat0 : public Etat{

    public:
      Etat0();
      virtual ~Etat0();
      bool transition(Automate & automate, Symbole * s);
      // int getEtat();

    private:
      int etat;

};

class Etat1 : public Etat{

    public:
      Etat1();
      virtual ~Etat1();
      bool transition(Automate & automate, Symbole * s);
      // int getEtat();

    private:
      int etat;

};

class Etat2 : public Etat{

    public:
      Etat2();
      virtual ~Etat2();
      bool transition(Automate & automate, Symbole * s);
      // int getEtat();

    private:
      int etat;

};

class Etat3 : public Etat{

    public:
      Etat3();
      virtual ~Etat3();
      bool transition(Automate & automate, Symbole * s);
      // int getEtat();

    private:
      int etat;

};

class Etat4 : public Etat{

    public:
      Etat4();
      virtual ~Etat4();
      bool transition(Automate & automate, Symbole * s);
      // int getEtat();

    private:
      int etat;

};

class Etat5 : public Etat{

    public:
      Etat5();
      virtual ~Etat5();
      bool transition(Automate & automate, Symbole * s);
      // int getEtat();

    private:
      int etat;

};

class Etat6 : public Etat{

    public:
      Etat6();
      virtual ~Etat6();
      bool transition(Automate & automate, Symbole * s);
      // int getEtat();

    private:
      int etat;

};

class Etat7 : public Etat{

    public:
      Etat7();
      virtual ~Etat7();
      bool transition(Automate & automate, Symbole * s);
      // int getEtat();

    private:
      int etat;

};

class Etat8 : public Etat{

    public:
      Etat8();
      virtual ~Etat8();
      bool transition(Automate & automate, Symbole * s);
      // int getEtat();

    private:
      int etat;

};

class Etat9 : public Etat{

    public:
      Etat9();
      virtual ~Etat9();
      bool transition(Automate & automate, Symbole * s);
      // int getEtat();

    private:
      int etat;

};