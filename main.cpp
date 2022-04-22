#include <iostream>
using namespace std;
class Trojkat
{
public:
    Trojkat(double bokStartowy = 0, double wysokoscStartowa = 0);
    double pole();
    bool ustawBok(double nowyBok);
    double podajBok();
    bool ustawWysokosc(double nowaWysokosc);
    double podajWysokosc();

private:
    double bok;
    double wysokosc;
};

Trojkat::Trojkat(double bokStartowy, double wysokoscStartowa) :bok(0), wysokosc(0)
{
    ustawBok(bokStartowy);
    ustawWysokosc(wysokoscStartowa);
}

double Trojkat::pole()
{
    return wysokosc * bok /2;
}
bool Trojkat::ustawWysokosc(double nowaWysokosc )
{
    if (nowaWysokosc >=0 );
    {
        wysokosc = nowaWysokosc;
        return true;
    }
}
bool Trojkat::ustawBok(double nowyBok)
{

    if (nowyBok >= 0);
    {
        bok = nowyBok;
        return true;
    }
    }

class Kwadrat
{
  public:
    Kwadrat(double startowyBok = 0);
    double pole();
    bool ustawBok(double nowyBok);
    double podajBok();
  private:
    double bok;
};

Kwadrat::Kwadrat(double startowyBok) : bok(0)
{
  ustawBok(startowyBok);
}

double Kwadrat::pole()
{
  return bok * bok;
}



bool Kwadrat::ustawBok(double nowyBok)
{
  if(nowyBok >= 0)
  {
    bok = nowyBok;
    return true;
  }
  else
    return false;
}

double Kwadrat::podajBok()
{
  return bok;
}
class Kolo
{
public:
    Kolo(double promienStartowy = 0);
    double pole();
    bool ustawPromien(double nowyPromien);
    double podajPromien;

private:
    double promien;

};
Kolo::Kolo(double promienStartowy): promien(0)
{
    ustawPromien(promienStartowy);
}
double Kolo::pole()
{
    return promien * promien * 3.14;

}

bool Kolo::ustawPromien(double nowyPromien) {
    if (nowyPromien >= 0 );
    {
        promien = nowyPromien;
        return true;
    }
}


class KalkulatorPolFigur
{
  public:
    KalkulatorPolFigur();
    ~KalkulatorPolFigur();
    void wykonajSie();
  private:
    void pokazMenu();
    void obliczeniaDlaKwadratu();
    void obliczeniaDlaKola();
    void obliczeniaDlaTrojkata();
};

KalkulatorPolFigur::KalkulatorPolFigur()
{
  cout << "Obliczam pola figur plaskich";
}

KalkulatorPolFigur::~KalkulatorPolFigur()
{
  cout << "\nNacisnij Enter by zakonczyc program...";
  cin.get();
}

void KalkulatorPolFigur::pokazMenu()
{
  cout << "\n\nWybierz rodzaj figury:\n1. Kwadrat\n2. Kolo\n3. Trojkat\n4. Koniec";
  cout << "\n>> ";
}

void KalkulatorPolFigur::obliczeniaDlaKwadratu()
{
  double dlugoscBoku;

  cout << "Obliczam pole kwadratu\n";
  do
  {
    cout << "\nPodaj dlugosc boku: ";
    cin >> dlugoscBoku;
    if(dlugoscBoku < 0)
      cout << "Dlugosc boku powinna byc nieujemna";
  }
  while(dlugoscBoku < 0);

  Kwadrat kwadracik(dlugoscBoku);
  cout << "Pole kwadratu: " << kwadracik.pole();
}

void KalkulatorPolFigur::obliczeniaDlaKola()
{
    double dlugoscPromienia;

    cout <<"Obliczam pole kola\n";
    do {
        cout << "\nPodaj dlugosc promienia: ";
        cin >> dlugoscPromienia;
        if (dlugoscPromienia <0)
            cout << "Dlugosc promienia powinna byc nieujemna";
    } while (dlugoscPromienia < 0 );

    Kolo kolko(dlugoscPromienia);
    cout << "Pole kola: " << kolko.pole();


}

void KalkulatorPolFigur::obliczeniaDlaTrojkata()
{
    double dlugoscBoku;
    double wysokosc;

    cout << "Obliczam pole Trojkata\n";
    do
    {
        cout << "\nPodaj dlugosc boku: ";
        cin >> dlugoscBoku;
        if(dlugoscBoku < 0)
            cout << "Dlugosc boku powinna byc nieujemna";
    }
    while(dlugoscBoku < 0);

    do
    {
        cout << "\nPodaj wysokość: ";
        cin >> wysokosc;
        if(wysokosc < 0)
            cout << "Wysokosc powinna byc nieujemna";
    }
    while(wysokosc < 0);

    Trojkat trojkacik(dlugoscBoku, wysokosc);
//    Kwadrat kwadracik(dlugoscBoku);
    cout << "Pole trojkata: " << trojkacik.pole();
}

void KalkulatorPolFigur::wykonajSie()
{
  char klawisz;

  do
  {
    pokazMenu();
    cin >> klawisz;
    cin.ignore();
    switch(klawisz)
    {
      case '1': obliczeniaDlaKwadratu();
                break;
      case '2': obliczeniaDlaKola();
                break;
      case '3': obliczeniaDlaTrojkata();
                break;
    }
  }
  while(klawisz != '4');
}

int main()
{
  KalkulatorPolFigur kalkulator;

  kalkulator.wykonajSie();

  return 0;
}
