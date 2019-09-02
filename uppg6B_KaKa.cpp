/*===============================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: sommar 19

Inlämningsuppgift nr 6 B

Namn: Katarina Käll

Personummer:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Nej
Utskrift av mindre fil blir inte längre korrekt.


Jag har använt kompilator/editor (namn/version) Code Blocks 17.12

Jag har använt följande dator (t.ex. PC, Mac, Annat):        PC
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : Windows 10

Jag har arbetat ungefär  5 timmar med denna uppgift

================================================================================
*/
#include <iostream>
#include <fstream>

using namespace std;

// -------------------------------------------------------
class Person
 {
 private:
   string namn;
   double betalat_andras;   // ligger ute med totalt
   double skyldig;          // skyldig totalt

 public:
   Person();
   Person( string n, double b, double s );
   string haemta_namn();
   double haemta_betalat();
   double haemta_skyldig();
   void skrivUt();
};
//-------------------------------------------------------
class PersonLista
 {
 private:
   int antal_pers;
   Person *pers;

 public:
   PersonLista();
   ~PersonLista();
   PersonLista& operator=(const PersonLista& pl);
   void laggTillEn( Person pny );
   void skrivUtOchFixa();
   double summaSkyldig();
   double summaBetalat();
   bool finnsPerson(const string& namn);
 };
//--------------------------------------------------------
 class Transaktion
 {
  private:
   string datum;
   string typ;
   string namn;
   double belopp;
   int ant_kompisar;
   string *kompisar;

  public:
   Transaktion();
   ~Transaktion();
   Transaktion& operator=(const Transaktion& t);
   string haemta_namn();
   double haemta_belopp();
   int haemta_ant_kompisar();
   bool finnsKompis( string namnet );
   bool laesEnTrans( istream &is );
   void skrivEnTrans( ostream &os );
 };
 // -------------------------------------------------------
class TransaktionsLista
{
 private:
   Transaktion *trans;
   int antalTrans;

 public:
   TransaktionsLista();
   ~TransaktionsLista();
   TransaktionsLista& operator=(const TransaktionsLista& tl);
   void laesin( istream & is );
   void skrivut( ostream & os );
   void laggTill( Transaktion & t );
   double totalkostnad();
   double liggerUteMed( string namnet );
   double aerSkyldig( string namnet );
   PersonLista FixaPersoner();
 };
//-------------------------------------------------------
void ritaMeny();
//-------------------------------------------------------
int main()
{
    int menyVal = 7;
    string namn;

    Transaktion trans;
    TransaktionsLista transList;
    PersonLista persList;

    ifstream fin("resa.txt");
    ofstream fout("resultat.txt");

    transList.laesin(fin); //Läs in data från infilen

    while(menyVal != 0)
        {
            ritaMeny();
            cin >> menyVal;

            switch(menyVal)
            {
                case 0:
                    transList.skrivut(fout);
                    break;
                case 1:
                    cout << "Skriv in en transaktion enligt foljande monster:" << endl;
                    cout <<  "datum(yymmdd) typ namn belopp antal lista pa kompisar";
                    trans.laesEnTrans(cin);
                    transList.laggTill(trans);
                    break;
                case 2:
                    transList.skrivut(cout);
                    break;
                case 3:
                    cout << "Total kostnad: " << transList.totalkostnad() << endl;
                    break;
                case 4:
                    cout << "Skriv in namn: " << endl;
                    cin >> namn;
                    cout << namn << " ar skyldig " << transList.aerSkyldig(namn) << endl;
                    break;
                case 5:
                    cout << "Skriv in namn: " << endl;
                    cin >> namn;
                    cout << namn << " ligger ute med: " << transList.liggerUteMed(namn) << endl;
                    break;
                case 6:
                    persList = transList.FixaPersoner();
                    persList.skrivUtOchFixa();
                    break;
                case 7:
                    ritaMeny();
                    break;
            }
        }

    return 0;
}
// -------------------------------------------------------
// Klassimplementationen
// -------------------------------------------------------
Person::Person()
{
    namn = "";
    betalat_andras = 0.0;
    skyldig = 0.0;
}

Person::Person(string n, double b, double s)
{
    namn = n;
    betalat_andras = b;
    skyldig = s;
}

string Person::haemta_namn()
{
    return namn;
}

double Person::haemta_betalat()
{
    return betalat_andras;
}

double Person::haemta_skyldig()
{
    return skyldig;
}

void Person::skrivUt()
{
    cout << namn << " ligger ute med: " << betalat_andras <<" och ar skyldig " << skyldig ;
    if(skyldig < betalat_andras)
    {
        cout << ". Ska ha " << betalat_andras - skyldig << " fran potten!" << endl;
    }
    else
    {
        cout << ". Ska lagga " << skyldig - betalat_andras << " till potten!" << endl;
    }
}
// -------------------------------------------------------
PersonLista::PersonLista()
{
    antal_pers = 0;
    pers = 0;
}

PersonLista::~PersonLista()
{
    delete[] pers;
}

PersonLista& PersonLista::operator=(const PersonLista& pl)
{
    if(this != &pl)
    {
        delete[] pers;
        antal_pers = pl.antal_pers;
        pers = new Person[antal_pers];
        for (int i = 0; i<antal_pers; i++)
        {
            pers[i] = pl.pers[i];
        }
        return *this;
    }
}

void PersonLista::laggTillEn(Person pny)
{
    Person *nyPers = 0;
    nyPers = new Person[antal_pers + 1]; // Skapa array med antal+1 elem.

    for ( int i = 0; i < antal_pers; i++ )  //Kopiera in de gamla
	{
	  nyPers[i] = pers[i];
	}

      nyPers[antal_pers] = pny;     // lägg in transaktion sist i arrayen
      antal_pers++;          // öka antalet transaktioner i arrayen

      delete [] pers; // Avallokera minne.
      pers = nyPers;       // Sätt array till nya arrayen.
}

void PersonLista::skrivUtOchFixa()
{
    cout << "Nu skapar vi en personarray och reder ut det hela!" << endl;
    for(int i = 0; i < antal_pers; i++)
    {
        pers[i].skrivUt();
    }
    summaSkyldig() == summaBetalat();
}

double PersonLista::summaSkyldig()
{
    double skyldig = 0.0;

    for(int i = 0; i < antal_pers; i++)
    {
        skyldig += pers[i].haemta_skyldig();
    }

    return skyldig;
}

double PersonLista::summaBetalat()
{
    double betalat = 0.0;

    for(int i = 0; i < antal_pers; i++)
    {
        betalat += pers[i].haemta_betalat();
    }

    return betalat;
}

bool PersonLista::finnsPerson(const string &namn)
{
    bool finns = false;

    for(int i = 0; i < antal_pers; i++)
    {
        int pos = pers[i].haemta_namn().find(namn);
        if(pos != string::npos)
        {
            finns = true;
        }
    }
    return finns;
}
// -------------------------------------------------------

Transaktion::Transaktion()
{
    datum = "";
    typ = "";
    namn = "";
    belopp = 0.0;
    ant_kompisar = 0;
    kompisar = 0;
}

Transaktion::~Transaktion()
{
    delete[] kompisar;
}

Transaktion& Transaktion::operator=( const Transaktion& t)
{
  if (this != &t)
    {
      delete[] kompisar;
      datum = t.datum;
      typ = t.typ;
      namn = t.namn;
      belopp = t.belopp;
      ant_kompisar = t.ant_kompisar;
      kompisar = new string[ant_kompisar];
      for (int i=0; i < ant_kompisar; i++)
	kompisar[i] = t.kompisar[i];
    }
  return *this;
}

string Transaktion::haemta_namn()
{
    return namn;
}

double Transaktion::haemta_belopp()
{
    return belopp;
}

int Transaktion::haemta_ant_kompisar()
{
    return ant_kompisar;
}

bool Transaktion::finnsKompis(string namnet)
{
    bool finns = false;

    if (namnet.at(0)>='a' && namnet.at(0)<='z') // Kontrollerar om det sökta namnet börjar på en gemen och om så är fallet ändrar den till en versal.
    {
        char ch = namnet.at(0) - 32;
        std::string s(1, ch);
        namnet.replace(0, 1, s);
    }

    for(int i = 0; i < ant_kompisar; i++)
    {
        int pos = kompisar[i].find(namnet);
        if(pos != string::npos)
        {
            finns = true;
        }
    }
    return finns;
}

bool Transaktion::laesEnTrans(istream &is)
{
    delete[] kompisar;

    is >> datum >> typ >> namn >> belopp >> ant_kompisar;

    kompisar = new string[ant_kompisar];

    for(int i = 0; i < ant_kompisar; i++)
    {
        is >> kompisar[i];
    }

    return is;
}

void Transaktion::skrivEnTrans(ostream &os)
{
    os << datum << "\t" << typ << "\t" << namn << "\t" << belopp << "\t" << ant_kompisar << "\t";
    for(int i = 0; i < ant_kompisar; i++)
    {
        os << kompisar[i] << "\t";
    }
    cout << endl;

}
//-----------------------------------------------------------------------
TransaktionsLista::TransaktionsLista()
{
    antalTrans = 0;
    trans = 0;
}

TransaktionsLista::~TransaktionsLista()
{
    delete[] trans;
}

TransaktionsLista& TransaktionsLista::operator=(const TransaktionsLista& tl)
{
    if(this != &tl)
    {
        delete[] trans;
        antalTrans = tl.antalTrans;
        trans = new Transaktion[antalTrans];
        for (int i = 0; i<antalTrans; i++)
        {
            trans[i] = tl.trans[i];
        }
        return *this;
    }
}

void TransaktionsLista::laesin(istream &is)
{
    Transaktion t;

    while(t.laesEnTrans(is))
    {
        laggTill(t);
    }
}

void TransaktionsLista::skrivut(ostream &os)
{
    cout << "Antal trans: " << antalTrans << endl;
		for(int i = 0; i < antalTrans; i++)
		{
			trans[i].skrivEnTrans(os);
		}
}

void TransaktionsLista::laggTill(Transaktion &t)
{
    Transaktion *nyTrans = 0;
    nyTrans = new Transaktion[antalTrans+1]; // Skapa array med antal+1 elem.

    for ( int i = 0; i < antalTrans; i++ )  //Kopiera in de gamla
	{
	  nyTrans[i] = trans[i];
	}

      nyTrans[antalTrans] = t;     // lägg in transaktion sist i arrayen
      antalTrans++;          // öka antalet transaktioner i arrayen

      delete [] trans; // Avallokera minne.
      trans = nyTrans;       // Sätt array till nya arrayen.

}

double TransaktionsLista::totalkostnad()
{
    double totalkostnad = 0.0;

    for(int i = 0; i < antalTrans; i++)
    {
        totalkostnad += trans[i].haemta_belopp();
    }

    return totalkostnad;
}

double TransaktionsLista::liggerUteMed(string namnet)
{
    double liggerUteMed = 0.0;

    for(int i = 0; i < antalTrans; i++)
    {
        if(trans[i].haemta_namn().find(namnet) != string::npos)
        {
            liggerUteMed += (trans[i].haemta_belopp()-(trans[i].haemta_belopp()/
                            (trans[i].haemta_ant_kompisar() + 1)));
        }
    }

    return liggerUteMed;
}

double TransaktionsLista::aerSkyldig(string namnet)
{
    double skuld = 0.0;

    for(int i = 0; i < antalTrans; i++)
    {
        if(trans[i].finnsKompis(namnet))
        {
            skuld += (trans[i].haemta_belopp()/(trans[i].haemta_ant_kompisar() + 1));
        }
    }
    return skuld;
}

PersonLista TransaktionsLista::FixaPersoner()
{
    PersonLista personList;
    string namn;
    double tillbaka = 0.0;
    double skuld = 0.0;

    for(int i = 0; i<antalTrans; i++)
    {
        namn = trans[i].haemta_namn();
        if(!personList.finnsPerson(namn))
        {
            tillbaka = liggerUteMed(namn);
            skuld = aerSkyldig(namn);

            Person pers(namn, tillbaka, skuld);
            personList.laggTillEn(pers);
        }
    }

    return personList;
}

// -------------------------------------------------------
// Funktionsdefinitioner:
void ritaMeny()
{
    cout << "Valj i menyn nedan:" << endl;
    cout << "0. Avsluta. Alla transaktioner sparas pa fil." << endl;
    cout << "1. Las in en transaktion fran tangentbordet." << endl;
    cout << "2. Skriv ut information om alla transaktioner." << endl;
    cout << "3. Berakna totala kostnaden." << endl;
    cout << "4. Hur mycket ar en viss person skyldig?" << endl;
    cout << "5. Hur mycket ligger en viss person ute med?" << endl;
    cout << "6. Lista alla personer mm och FIXA!" << endl << endl;
}

/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================
Testdata 1:
Valj i menyn nedan:
0. Avsluta. Alla transaktioner sparas pa fil.
1. Las in en transaktion fran tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Berakna totala kostnaden.
4. Hur mycket ar en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

2
Antal trans: 10
050615  transp  Eva     6000    5       Bosse   Kristin Paul    Torsten Stina
050721  mat     Eva     300     2       Bosse   Kristin
050721  mat     Paul    400     2       Torsten Stina
050721  transp  Bosse   5000    3       Eva     Kristin Paul
050721  transp  Stina   5000    1       Torsten
050722  boende  Kristin 200     1       Eva
050722  mat     Eva     300     2       Kristin Bosse
050723  mat     Torsten 300     2       Paul    Stina
050724  mat     Paul    200     1       Stina
050725  transp  Eva     600     3       Bosse   Kristin Paul
Valj i menyn nedan:
0. Avsluta. Alla transaktioner sparas pa fil.
1. Las in en transaktion fran tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Berakna totala kostnaden.
4. Hur mycket ar en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

6
Nu skapar vi en personarray och reder ut det hela!
Eva ligger ute med: 5850 och ar skyldig 1350. Ska ha 4500 fran potten!
Paul ligger ute med: 366.667 och ar skyldig 2500. Ska lagga 2133.33 till potten!
Bosse ligger ute med: 3750 och ar skyldig 1350. Ska ha 2400 fran potten!
Stina ligger ute med: 2500 och ar skyldig 1333.33. Ska ha 1166.67 fran potten!
Kristin ligger ute med: 100 och ar skyldig 2600. Ska lagga 2500 till potten!
Torsten ligger ute med: 200 och ar skyldig 3633.33. Ska lagga 3433.33 till potten!

Testdata 2:
Valj i menyn nedan:
0. Avsluta. Alla transaktioner sparas pa fil.
1. Las in en transaktion fran tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Berakna totala kostnaden.
4. Hur mycket ar en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!

6
Nu skapar vi en personarray och reder ut det hela!
Eva ligger ute med: 600 och ar skyldig 100. Ska ha 500 fran potten!
Bosse ligger ute med: 100 och ar skyldig 600. Ska lagga 500 till potten!

================================================================================
Här skriver du en kort rapport om uppgiften:
Uppgiften gick ut på att  skriva ett program som läser in ett antal transaktioner och sedan
räknar ut hur mycket var och en har betalat, om de är skyldiga pengar eller om de ska få
tillbaka pengar.

Jag tycker att det var särksillt svårt att jobba med en så pass stor uppgift. Jag försökte
föja råden med att implementera lite i taget och testa efter hand.

Frågor att besvara:
Tilldelningsoperatorn används för att göra en sk "deep copy" vilket  innebär att arrayen
kopieras men inte pekaren. Tilldelningsoperatorn används varje gång den dynamiska arrayen
kopieras i programmet.

"if (this != &t)" Betyder om inte this-pekaren pekar på adressen till pekare t

*/
