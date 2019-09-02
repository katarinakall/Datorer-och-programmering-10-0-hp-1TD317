/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: VT 2019

Inlämningsuppgift nr 3

Namn: Katarina Käll

Personummer:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kursprogramvaran CodeBlocks:  Ja

Jag har använt följande dator (t.ex. PC, Mac, Annat):        PC
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : Windows 10

Jag har arbetat ungefär  2 timmar med denna uppgift

================================================================================
*/
#include <iostream>

using namespace std;

void skrivInfo();
int lasEttTal(int &tal);
char lasOp(char &opTecken);
void ordna(int &tal1, int &tal2);
int berakna(int tal1, int tal2, char opTecken);
void skrivResultat(long resultat);

int main()
{
    int tal1, tal2, svar;
    char opTecken;

    skrivInfo();

    tal1 = lasEttTal(tal1);

    tal2 = lasEttTal(tal2);

    opTecken = lasOp(opTecken);

    ordna(tal1, tal2);

    svar = berakna(tal1, tal2, opTecken);

    skrivResultat(svar);

    return 0;
}

void skrivInfo()
{
    cout<< "Hej, har kan du addera, multiplicera eller berakna kvadratsumman av alla tal fr.o.m det minsta t.o.m det storsta." <<endl;
}

int lasEttTal(int &tal)
{
    cout<< "Skriv in ett heltal: ";
    cin>> tal;
    return tal;
}

char lasOp(char &opTecken)
{
    cout<< "Vilken operation ska utforas?" <<endl;
    cout<< "Addition (a), Multiplikation (m) eller Berakna kvadratsumman (k)" <<endl;
    cin >> opTecken;
    return opTecken;
}

void ordna(int &tal1, int &tal2)
{
    if(tal1>tal2)
    {
    int temp = tal1;
    tal1 = tal2;
    tal2 = temp;
    }
}

int berakna(int tal1, int tal2, char opTecken)
{
    int svar = 0;
    switch(opTecken)
    {
        case 'a':
        {
            for(tal1; tal1 <= tal2; tal1++)
            {
                svar += tal1;
            }
            break;
        }
        case 'm':
        {
            svar = 1;
            for(tal1; tal1 <= tal2; tal1++)
            {
                svar *= tal1;
            }
            break;
        }
        case 'k':
        {
            for(tal1; tal1 <= tal2; tal1++)
            {
                svar += tal1*tal1;
            }
            break;
        }
    }
    return svar;
}

void skrivResultat(long resultat)
{
    cout<< "Resultatet fran berakningen blev: " << resultat << endl;
}


/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================
Testdata 1:
Skriv in ett heltal: 3
Skriv in ett heltal: 5
Vilken operation ska utforas?
Addition (a), Multiplikation (m) eller Berakna kvadratsumman (k)
a
Resultatet fran berakningen blev: 12

Testdata 2:
Skriv in ett heltal: 3
Skriv in ett heltal: 5
Vilken operation ska utforas?
Addition (a), Multiplikation (m) eller Berakna kvadratsumman (k)
m
Resultatet fran berakningen blev: 60

Teatdata 3:
Skriv in ett heltal: 3
Skriv in ett heltal: 5
Vilken operation ska utforas?
Addition (a), Multiplikation (m) eller Berakna kvadratsumman (k)
k
Resultatet fran berakningen blev: 50

Testdata 4:
Skriv in ett heltal: -3
Skriv in ett heltal: 5
Vilken operation ska utforas?
Addition (a), Multiplikation (m) eller Berakna kvadratsumman (k)
m
Resultatet fran berakningen blev: 0

Testdata 5:
Skriv in ett heltal: 5
Skriv in ett heltal: 3
Vilken operation ska utforas?
Addition (a), Multiplikation (m) eller Berakna kvadratsumman (k)
a
Resultatet fran berakningen blev: 12

Testdata 6:
Skriv in ett heltal: -3
Skriv in ett heltal: -5
Vilken operation ska utforas?
Addition (a), Multiplikation (m) eller Berakna kvadratsumman (k)
a
Resultatet fran berakningen blev: -12

Testdata 7:
Skriv in ett heltal: 1
Skriv in ett heltal: 100
Vilken operation ska utforas?
Addition (a), Multiplikation (m) eller Berakna kvadratsumman (k)
k
Resultatet fran berakningen blev: 338350
================================================================================
Här skriver du en kort rapport om uppgiften:
Uppgiften gick ut på att skriva ett programm som som läser in två tal och sedan summerar,
multiplicerar eller kvadratsummerar alla tal fr.o.m det minsta t.o.m det störta beroende
på vald bersäkning.

Jag valde att lösa beräkningarna i en switch- sats där jag har nästlat for-loopar. Jag hade
problem med att få till korrekt syntax vilket jag löste genom att leta upp referensmaterial på
nästet. I övrigt var tipsen väldigt andvändbara.

Frågor att besvara:
- Ja jag känner att funktioner gör koden blir mindre rörig och lättare att förstå.
Bra metodnamn minskar dessutom behovet för kommentarer. Koden blir mer självförklarande.
- Ibland vill man behålla det ursprungliga värdet i en parameter och då lämpar sig värdeparameter bättre.


*/
