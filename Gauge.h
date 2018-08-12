#ifndef _GAUGE_H
#define _GAUGE_H
#endif _GAUGE_H

#include <inttypes.h>

class OpAmp{
public:
  //Pin ktory jest podlaczony do potencjometru
  uint8_t digitalPin;

  //Konstruktor
  OpAmp();

  //Getery zmiennych prywatnych
  float GetCurrent(void);
  float GetPower(void);
  float GetVolOpAmp(void);
  float GetNoFlipp(void);
  int GetPWM(void);

  //Funkcja przeliczajaca dane cyfrowe na wartosci analogowe napiecia
  float Voltage(uint8_t pin);

  //Funkcja wyliczajaca moc wydzielana na glowicy
  void PowerHead(void);

  //Napiecie na wejsciu nieodwracajacym wzmacniacza
  void NoFlippIn(void);

  /*
    Funkcja dzieki ktorej zamiast rzeczywistego PWM podajemy wypenienie
    sygnalu w procentach
  */
  void Fill_PerCent(void);

  //Funkcja wyliczajaca prąd płynący w obwodzie
  void Current(void);

private:
  //Zmienne przechowujace dane dot. rezystora ustalajacego prąd w obwodzie
  float volResSet;
  float valueResSet;

  //Zmienne przechowujace dane dot.wejscia wzmacniacza
  float volNoFlipp;

  //Prąd płynący w obwodzie
  float curr;

  //Zmienne przechowujace dane dot. glowicy pomiarowej
  float powerHead;

  //Zmienne przechowujace dane dot. wyjscie wzmacniacza
  float volOpAmpOut;

  //Napiecia zewnetrzego źródła zasilania
  uint8_t sourceVol;

  //Maksymalne napiecie jakie moze wystapic na wyprowadzeniu uC
  float maxVol;

  //Liczba bitow przetwornika ADC
  float bits;

  //Stała używana do przeliczania bitów na napiecie
  float parts = maxVol/bits;

  //Wielokrotnosc wzmonienia OpAmp'a
  float multiple;

  //Zmienne przechowujace pobrana z monitora szeregowego wartosc, oraz wartosc PWM
  int perCent;
  int pwm;
};
