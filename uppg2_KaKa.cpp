/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: VT 2019

Inlämningsuppgift nr 2

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

        malTid = malH*60*60 + malMin*60 + malS; // Beräknar ny måltid justerad efter dygnspassage.

        tid = malTid - startTid;

        if(tid < vinnarTid) // Kontrollerar om den nya tiden är den bästa.
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
Här följer programkörningar för alla testdata:
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
Uppgiften gick ut på att skriva ett program som ska räkan ut och redovisa vem som är vinnaren.
Input är startnummer, starttid och måltid. Tiderna delas upp i tre heltal timmar, minuter och sekunder.
Output är vinnarens startnummer, vinnartid uppdelad i tre heltal (timmar, minuter och sekunder) samt antalet tävlande.

Jag löste uppgiften genom att skriva en while-loop som fortsatte tills inputen blev ett startnummer mindre än 1.
Inuti loopen räknar jag ut tiden för den tävlande, kontrollerar om det är den bästa tiden i en if-sats och om det är
den bästa tiden sätt bästa tid till tävlarens tid och vinnarens startnummer till den aktuella tävlandes startnummer.
För att justera för dygnspassage har jag lagt till en if-sats som kontrollerar om måltiden är mindre än starttiden. Om den
är det adderas 24 timmar till måltiden.

Frågor att besvara:
Den första vinner eftersom jag i mitt programm kontrollerar om den andra tävlandes tid är bättre än den förstas. I och med att den
andres tid är lika med den förstas tid uppfylls inte kravet och den första förblir vinnare.

För att kontrollera att koden uppfyller de kriterier som krävs för att utgöra en fungerande produkt.

Det finns absolut fördelar med att skriva testdata först. Då vet man exempelvis på förhand vilka krav som ställs
på koden och vad den förväntas klara av.


*/
