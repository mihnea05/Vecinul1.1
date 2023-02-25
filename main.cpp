#include <iostream>
#include "carte.h"
#include "jucator.h"

using namespace std;

int main() {
  int dealer_valoare;
  int jucator_valoare;
  float pariu;
  char alegere;
  Carte carte;
  Jucator jucator = Jucator();

  cout << "Cum te cheama, cumetre? ";
  cin >> jucator.nume;

  cout << "Cu cati bani incepi? ";
  cin >> jucator.inceput_balanta;

  jucator.balanta = jucator.inceput_balanta;

  while (jucator.balanta > 0 && (jucator.balanta < jucator.inceput_balanta * 5)) {
    cout << jucator.nume << ", ai $"
         << jucator.balanta << ". ";

    while (pariu == 0 || pariu > jucator.balanta) {
      cout << "Cati bani vrei sa pariezi?";
      cin >> pariu;

      if (pariu > jucator.balanta) {
        cout << "Ne pare rau, ai saracit.\n";
      }
    }

    carte = Carte();
    dealer_valoare = carte.get_valoare();

    cout << "Ai tras un " << carte.get_valoare_string()
         << " de " << carte.get_tip_string() << ".\n";
    cout << "Va fi urmatoare carte mai mare sau mai mica? "
         << "Apasa \"h\" pentru mai mare sau \"l\" pentru mai mic: ";
    cin >> alegere;

    carte = Carte();
    jucator_valoare = carte.get_valoare();

    cout << "Ai tras un " << carte.get_valoare_string()
         << " de " << carte.get_tip_string() << ".\n";

    if ((alegere == 'h' && dealer_valoare > jucator_valoare) ||
        (alegere == 'l' && dealer_valoare < jucator_valoare)) {
      jucator.balanta -= pariu;

      cout << "Ai perdut! Ne pare rau, " + jucator.nume
           << ". Ai pierdut $" << pariu << ".\n";
    } else {
      jucator.balanta += pariu;

      cout << "Ai castigat, maestre " + jucator.nume
           << ". Ai adaugat la valuta $" << pariu << "!\n";
    }

    pariu = 0;
  }

  if (jucator.balanta <= 0) {
    cout << "Nasol " + jucator.nume << ". "
         << "Nu mai ai valuta, ai pierdut.\n";
  } else {
    cout << "Ai castigat, maestre " + jucator.nume << "!";
  }

  return 0;
}
