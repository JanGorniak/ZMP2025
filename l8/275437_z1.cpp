#include <iostream>

using namespace std;

class Pojazd
{
    private:
        string marka;
        string model;
        int rok_produkcji;
    
    public:
        Pojazd(string marka, string model, int rok) : marka(marka), model(model), rok_produkcji(rok) {}

        string get_marka() const { return marka; }
        string get_model() const { return model; }
        int get_rok_produkcji() const { return rok_produkcji; }

        void set_marka(string m) { marka=m; }
        void set_model(string mod) { model=mod; }
        void set_rok_produkcji(int rok) { rok_produkcji=rok; }

        virtual void wyswietlanie() const
        {
            cout << "Pojazd: " << marka << " " << model << ", Rok: " << rok_produkcji << "\n";
        }

        virtual ~Pojazd() {}
};

class Samochod : public Pojazd
{
    private:
        int liczba_drzwi;

    public:
        Samochod(string marka, string model, int rok, int drzwi)
            : Pojazd(marka, model, rok), liczba_drzwi(drzwi) {}

        int get_liczba_drzwi() const { return liczba_drzwi; }
        void set_liczba_drzwi(int drzwi) { liczba_drzwi=drzwi; }

        void wyswietlanie() const override
        {
            Pojazd::wyswietlanie();
            cout << "Liczba drzwi: " << liczba_drzwi << "\n";
        }
};

class Rower : public Pojazd
{
    private:
        int liczba_przerzutek;

    public:
        Rower(string marka, string model, int rok, int przerzutki)
            : Pojazd(marka, model, rok), liczba_przerzutek(przerzutki) {}

        int get_liczba_przerzutek() const { return liczba_przerzutek; }
        void set_liczba_przerzutek(int przerzutki) { liczba_przerzutek=przerzutki; }

        void wyswietlanie() const override
        {
            Pojazd::wyswietlanie();
            cout << "Liczba przerzutek: " << liczba_przerzutek << "\n";
        }

};

int main()
{
    string marka_samochod, model_samochod;
    int rok_samochod, drzwi;
    string marka_rower, model_rower;
    int rok_rower, przerzutki;

    cout << "Podaj dane (8 argumentów):\n";
    cout << "(samochod: marka model rok drzwi, rower: marka model rok przerzutki)\n";

    cin >> marka_samochod >> model_samochod >> rok_samochod >> drzwi
        >> marka_rower >> model_rower >> rok_rower >> przerzutki;

    Samochod s(marka_samochod, model_samochod, rok_samochod, drzwi);
    Rower r(marka_rower, model_rower, rok_rower, przerzutki);

    cout << "\nInformacje o samochodzie:\n";
    s.wyswietlanie();

    cout << "\nInformacje o rowerze:\n";
    r.wyswietlanie();

    return 0;
}