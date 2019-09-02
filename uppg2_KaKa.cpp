/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/�r: VT 2019

Inl�mningsuppgift nr 2

Namn: Katarina K�ll

Personummer:

Den fil som jag l�mnar in g�r att kompilera och
programmet fungerar f�r alla de testdata som finns f�r uppgiften: Ja

Jag har anv�nt kursprogramvaran CodeBlocks:  Ja

Jag har anv�nt f�ljande dator (t.ex. PC, Mac, Annat):        PC
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : Windows 10

Jag har arbetat ungef�r  2 timmar med denna uppgift

================================================================================
*/

 #include <iostream>
using namespace std;

int main()
{
    const int dygn = 24*60*60;
    int startNr, vinnarNr, startH, startMin, startS, startTid, malH, malMin, malS, malTid,
        antalTavlande=0, tid, vinnarTid = dygn, vinnarH, vinnarMin, vinnarS;

    cout << "Skriv in startnummer: " << endl;
    cin>> startNr;


    while (startNr >= 1)
    {
        antalTavlande++;
        cout << "Skriv in starttid i timmar, minuter och sekunder som tre separata tal: " << endl;
        cin>> startH >> startMin >> startS;

        cout << "Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal: " << endl;
        cin>> malH >> malMin >> malS;

        startTid = startH*60*60 + startMin*60 + startS;
        malTid = malH*60*60 + malMin*60 + malS;

        if(malTid < startTid) // Kontrollerar och justerar vid dyngspassage.
            {
                malH = malH + 24;
            }

        malTid = malH*60*60 + malMin*60 + malS; // Ber�knar ny m�ltid justerad efter dygnspassage.

        tid = malTid - startTid;

        if(tid < vinnarTid) // Kontrollerar om den nya tiden �r den b�sta.
            {
                vinnarTid = tid;
                vinnarNr = startNr;
            }

        cout << "Skriv in startnummer: " << endl;
        cin>> startNr;
    }

    vinnarH = vinnarTid/3600;
    vinnarMin = (vinnarTid % 3600) /60;
    vinnarS = vinnarTid -vinnarH*3600 - vinnarMin*60;

       if (startNr < 1 && antalTavlande < 1)
        {
            cout << "Inga tavlande" << endl;
            cout << "Programmet avslutas" << endl;
        } else
        {
            cout << "Vinnare ar startnr: " << vinnarNr << endl;
            cout << "Tim: " << vinnarH << " Min: " << vinnarMin << " Sek: " << vinnarS << endl;
            cout << "Antal tavlande: " << antalTavlande << endl;
            cout << "Programmet avslutas" << endl;
        }


    return 0;
}


/*
================================================================================
H�r f�ljer programk�rningar f�r alla testdata:
==============================================
Testdata 1:
Skriv in startnummer:
33
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
17 30 15
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
18 22 35
Skriv in startnummer:
-1
Vinnare ar startnr: 33
Tim: 0 Min: 52 Sek: 20
Antal tavlande: 1
Programmet avslutas

Testdata 2:
Skriv in startnummer:
33
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
17 30 15
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
18 22 35
Skriv in startnummer:
-1
Vinnare ar startnr: 33
Tim: 0 Min: 52 Sek: 20
Antal tavlande: 1
Programmet avslutas

Testdata 3:
Skriv in startnummer:
33
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
17 30 15
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
18 22 35
Skriv in startnummer:
14
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
23 35 00
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
0 12 24
Skriv in startnummer:
26
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
10 11 12
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
20 21 22
Skriv in startnummer:
-1
Vinnare ar startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tavlande: 3
Programmet avslutas

Testdata 4:
Skriv in startnummer:
14
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
23 35 00
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
0 12 24
Skriv in startnummer:
26
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
10 11 12
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
20 21 22
Skriv in startnummer:
33
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
17 30 15
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
18 22 35
Skriv in startnummer:
-1
Vinnare ar startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tavlande: 3
Programmet avslutas

Testdata 5:
Skriv in startnummer:
26
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
10 11 12
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
20 21 22
Skriv in startnummer:
33
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
17 30 15
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
18 22 35
Skriv in startnummer:
14
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
23 35 00
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
0 12 24
Skriv in startnummer:
-1
Vinnare ar startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tavlande: 3
Programmet avslutas

Testdata 6:
Skriv in startnummer:
17
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
00 00 50
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
00 00 30
Skriv in startnummer:
-1
Vinnare ar startnr: 17
Tim: 23 Min: 59 Sek: 40
Antal tavlande: 1
Programmet avslutas

Testdata 7:
Skriv in startnummer:
-1
Inga tavlande
Programmet avslutas

Testdata 8:
Skriv in startnummer:
15
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
10 00 00
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
11 00 00
Skriv in startnummer:
12
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
11 00 00
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
10 00 10
Skriv in startnummer:
-1
Vinnare ar startnr: 15
Tim: 1 Min: 0 Sek: 0
Antal tavlande: 2
Programmet avslutas

Testdata 9:
Skriv in startnummer:
8
Skriv in starttid i timmar, minuter och sekunder som tre separata tal:
00 00 10
Skriv in tid vid malgang i timmar, minuter och sekunder som tre separata tal:
00 00 20
Skriv in startnummer:
-1
Vinnare ar startnr: 8
Tim: 0 Min: 0 Sek: 10
Antal tavlande: 1
Programmet avslutas


================================================================================
Kort rapport om uppgiften:
Uppgiften gick ut p� att skriva ett program som ska r�kan ut och redovisa vem som �r vinnaren.
Input �r startnummer, starttid och m�ltid. Tiderna delas upp i tre heltal timmar, minuter och sekunder.
Output �r vinnarens startnummer, vinnartid uppdelad i tre heltal (timmar, minuter och sekunder) samt antalet t�vlande.

Jag l�ste uppgiften genom att skriva en while-loop som fortsatte tills inputen blev ett startnummer mindre �n 1.
Inuti loopen r�knar jag ut tiden f�r den t�vlande, kontrollerar om det �r den b�sta tiden i en if-sats och om det �r
den b�sta tiden s�tt b�sta tid till t�vlarens tid och vinnarens startnummer till den aktuella t�vlandes startnummer.
F�r att justera f�r dygnspassage har jag lagt till en if-sats som kontrollerar om m�ltiden �r mindre �n starttiden. Om den
�r det adderas 24 timmar till m�ltiden.

Fr�gor att besvara:
Den f�rsta vinner eftersom jag i mitt programm kontrollerar om den andra t�vlandes tid �r b�ttre �n den f�rstas. I och med att den
andres tid �r lika med den f�rstas tid uppfylls inte kravet och den f�rsta f�rblir vinnare.

F�r att kontrollera att koden uppfyller de kriterier som kr�vs f�r att utg�ra en fungerande produkt.

Det finns absolut f�rdelar med att skriva testdata f�rst. D� vet man exempelvis p� f�rhand vilka krav som st�lls
p� koden och vad den f�rv�ntas klara av.


*/
