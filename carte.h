#include <iostream>
#include <ctime>

using namespace std;

class Carte {
  private:
    int valoare;
    int tip;

  public:
    Carte() {
      srand(time(NULL));
      valoare = (1 + (std::rand() % (int)(13)));
      tip = (1 + (std::rand() % (int)(4)));
    }

    int get_valoare() {
      return valoare;
    }

    string get_valoare_string() {
      if (valoare == 1) return "As";
      if (valoare == 2) return "Doi";
      if (valoare == 3) return "Trei";
      if (valoare == 4) return "Patru";
      if (valoare == 5) return "Cinci";
      if (valoare == 6) return "Sase";
      if (valoare == 7) return "Sapte";
      if (valoare == 8) return "Opt";
      if (valoare == 9) return "Noua";
      if (valoare == 10) return "Zece";
      if (valoare == 11) return "Juvete";
      if (valoare == 12) return "Dama";
      if (valoare == 13) return "Rege";
      else return "Uknown valoare";
    }

    int get_tip() {
      return tip;
    }

    string get_tip_string() {
      if (tip == 1) return "Romb";
      if (tip == 2) return "Inima Rosie";
      if (tip == 3) return "Inima Neagra";
      if (tip == 4) return "Trefla";
      else return "Unknown tip";
    }
};
