#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

int stanga = 200, sus = 200, width, height, latura, numar, x1, y1, ecranactiv = 0; // 0-meniu 1-intructiuni 2-joc 3-nivelterminat
int ax = 200, ay = 200, bx = 600, by = 200, cx = 600, cy = 600, dx = 200, dy = 600;
bool aplicatiepornita = true;
struct Nivel
{
    int ciupercix[4], ciuperciy[4], iepurix[4], iepuriy[4], nriepuri, vulpex[3], vulpey[3], nrvulpi, nrciuperci;

    int A[6][6], B[6][6];

} nivele[10];
int nivelcurent = 1;

int i, j;
void patrat(int x, int y, int L)
{
    int L2 = L / 2;
    line(x - L2, y - L2, x + L2, y - L2);
    line(x + L2, y - L2, x + L2, y + L2);
    line(x + L2, y + L2, x - L2, y + L2);
    line(x - L2, y + L2, x - L2, y - L2);
}

void desenatpatratel(int i, int j)
{
    setfillstyle(1, 2); // coloram patratele
    setcolor(2);        // stabilim GREEN pentru conturul patratelor
    patrat(x1 + latura * (j - 1), y1 + latura * (i - 1), latura);
    floodfill(x1 + latura * (j - 1) - latura / 2 + 1, y1 + latura * (i - 1) - latura / 2 + 1, 2);
    setfillstyle(1, LIGHTGREEN);                                                       // forma umpluta in culoarea respectiva
    setcolor(LIGHTGREEN);                                                              // culoarea conturului formei
    fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 3, latura / 3); //
}
void buton()
{
    rectangle(200, 380, 500, 450);
    settextstyle(9, HORIZ_DIR, 18);
    setbkcolor(GREEN);
    outtextxy(206, 383, "START");
}

void desen(int x, int y)
{
    int i, j;

    numar = 5;              // tabla 5x5
    width = 400;            // latime
    height = 400;           // inaltime
    latura = width / numar; // aflam latura unui patrat
    x1 = x - 2 * latura;    // x1 pentru centrul primului patrat
    y1 = y - 2 * latura;    // y1 pentru centrul primul patrat din stg
    setcolor(LIGHTGREEN);   // rama sah
    for (i = 1; i <= 5; i++)
        for (j = 1; j <= 5; j++)
        {
            setfillstyle(1, 2); // coloram patratele
            setcolor(2);        // stabilim GREEN pentru conturul patratelor
            patrat(x1 + latura * (j - 1), y1 + latura * (i - 1), latura);
            floodfill(x1 + latura * (j - 1) - latura / 2 + 1, y1 + latura * (i - 1) - latura / 2 + 1, 2); // coloram patratele
            if (i == 1 && j == 1 || i == 1 && j == 5 || i == 5 && j == 1 || i == 5 && j == 5 || i == 3 && j == 3)
            {
                setfillstyle(1, BROWN);
                setcolor(BROWN);
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 3, latura / 3);
            }
            else
            {
                setfillstyle(1, LIGHTGREEN);                                                       // forma umpluta in culoarea respectiva
                setcolor(LIGHTGREEN);                                                              // culoarea conturului formei
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 3, latura / 3); // contruim cerculete in fiecare patrat
            }
        }
    /*line(200,200,600,200);
    line(200,200,200,600);
    line(200,600,600,600);
    line(600,200,600,600);*/
}
bool pozitiefinala(int a, int b)
{
    if (a == 1 && b == 1 || a == 1 && b == 5 || a == 5 && b == 1 || a == 5 && b == 5 || a == 3 && b == 3)
        return true;
    else
        return false;
}
void desenlevel_1()
{
    cleardevice();
    settextstyle(9, HORIZ_DIR, 18);
    readimagefile("img.jpg", 0, 0, 800, 800);
    outtextxy(50, 100, "JUMPIN' LEVEL 1");
    desen(400, 400);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
        {
            if (i == 1 && j == 2 || i == 1 && j == 3 || i == 2 && j == 4) // desenam ciupercile
            {
                setfillstyle(SOLID_FILL, RED); // UMPLUTURA

                setcolor(RED); // PENTRU MARGINE
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 3, latura / 3);
                setfillstyle(1, WHITE);                                                                           // CULOAREA DE UMPLERE A ELIPSELOR PE CARE LE DESENAM
                setcolor(WHITE);                                                                                  // MARGINEA BULINELOR
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 20, latura / 20);              // bulina din centru
                fillellipse(x1 + latura * (j - 1) + latura / 4, y1 + latura * (i - 1), latura / 20, latura / 20); // buline lateral
                fillellipse(x1 + latura * (j - 1) - latura / 4, y1 + latura * (i - 1), latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) - latura / 8, y1 + latura * (i - 1) - latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) + latura / 8, y1 + latura * (i - 1) + latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) - latura / 8, y1 + latura * (i - 1) + latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) + latura / 8, y1 + latura * (i - 1) - latura / 6, latura / 20, latura / 20);
            }
            if (i == 3 && j == 4)
                readimagefile("iepure.jpg", 440, 360, 520, 440);
        }
    desenatpatratel(1, 4);
}

void desenlevel_2()
{
    cleardevice();
    settextstyle(9, HORIZ_DIR, 18);
    readimagefile("img.jpg", 0, 0, 800, 800);
    outtextxy(50, 100, "JUMPIN' LEVEL 2");
    desen(400, 400);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)

            if (i == 1 && j == 4 || i == 2 && j == 3 || i == 4 && j == 3)
            {
                setfillstyle(SOLID_FILL, RED); // UMPLUTURA
                setcolor(RED);                 // PENTRU MARGINE
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 3, latura / 3);
                setfillstyle(1, WHITE); // stabilim culoarea ciupercilor
                setcolor(WHITE);
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 20, latura / 20);              // bulina din centru
                fillellipse(x1 + latura * (j - 1) + latura / 4, y1 + latura * (i - 1), latura / 20, latura / 20); // buline lateral
                fillellipse(x1 + latura * (j - 1) - latura / 4, y1 + latura * (i - 1), latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) - latura / 8, y1 + latura * (i - 1) - latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) + latura / 8, y1 + latura * (i - 1) + latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) - latura / 8, y1 + latura * (i - 1) + latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) + latura / 8, y1 + latura * (i - 1) - latura / 6, latura / 20, latura / 20);
            }
    readimagefile("iepure.jpg", 200, 200, 280, 280);
    readimagefile("iepuremaro.jpg", 360, 520, 440, 600);
}
void desenlevel_3()
{
    cleardevice();
    settextstyle(9, HORIZ_DIR, 18);
    readimagefile("img.jpg", 0, 0, 800, 800);
    outtextxy(50, 100, "JUMPIN' LEVEL 3");
    desen(400, 400);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)

            if (i == 3 && j == 2 || i == 3 && j == 4 || i == 2 && j == 5)
            {
                setfillstyle(SOLID_FILL, RED); // UMPLUTURA
                setcolor(RED);                 // PENTRU MARGINE
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 3, latura / 3);
                setfillstyle(1, WHITE);
                setcolor(WHITE);
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 20, latura / 20);              // bulina din centru
                fillellipse(x1 + latura * (j - 1) + latura / 4, y1 + latura * (i - 1), latura / 20, latura / 20); // buline lateral
                fillellipse(x1 + latura * (j - 1) - latura / 4, y1 + latura * (i - 1), latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) - latura / 8, y1 + latura * (i - 1) - latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) + latura / 8, y1 + latura * (i - 1) + latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) - latura / 8, y1 + latura * (i - 1) + latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) + latura / 8, y1 + latura * (i - 1) - latura / 6, latura / 20, latura / 20);
            }
    readimagefile("iepure.jpg", 200, 360, 280, 440);
    readimagefile("iepuremaro.jpg", 360, 360, 440, 440);
    readimagefile("iepurealbastru.jpg", 520, 360, 600, 440);
}
void desenlevel_4()
{
    cleardevice();
    settextstyle(9, HORIZ_DIR, 18);
    readimagefile("img.jpg", 0, 0, 800, 800);
    outtextxy(50, 100, "JUMPIN' LEVEL 4");
    desen(400, 400);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)

            if (i == 1 && j == 4 || i == 2 && j == 2 || i == 3 && j == 3)
            {
                setfillstyle(SOLID_FILL, RED); // UMPLUTURA

                setcolor(RED); // PENTRU MARGINE
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 3, latura / 3);
                setfillstyle(1, WHITE);
                setcolor(WHITE);
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 20, latura / 20);              // bulina din centru
                fillellipse(x1 + latura * (j - 1) + latura / 4, y1 + latura * (i - 1), latura / 20, latura / 20); // buline lateral
                fillellipse(x1 + latura * (j - 1) - latura / 4, y1 + latura * (i - 1), latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) - latura / 8, y1 + latura * (i - 1) - latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) + latura / 8, y1 + latura * (i - 1) + latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) - latura / 8, y1 + latura * (i - 1) + latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) + latura / 8, y1 + latura * (i - 1) - latura / 6, latura / 20, latura / 20);
            }

    readimagefile("iepure.jpg", 360, 280, 440, 360); // incepe la x=360 pana la 440
    readimagefile("vulpe.jpg", 450, 280, 595, 360);
}
void desenlevel_5()
{
    cleardevice();
    settextstyle(9, HORIZ_DIR, 18); // font pozitie marime
    readimagefile("img.jpg", 0, 0, 800, 800);
    outtextxy(50, 100, "JUMPIN' LEVEL 5");
    desen(400, 400);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)

            if (i == 1 && j == 5 || i == 3 && j == 4 || i == 5 && j == 3)
            {
                setfillstyle(SOLID_FILL, RED); // UMPLUTURA

                setcolor(RED); // PENTRU MARGINE
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 3, latura / 3);
                setfillstyle(1, WHITE);
                setcolor(WHITE);
                fillellipse(x1 + latura * (j - 1), y1 + latura * (i - 1), latura / 20, latura / 20);              // bulina din centru
                fillellipse(x1 + latura * (j - 1) + latura / 4, y1 + latura * (i - 1), latura / 20, latura / 20); // buline lateral
                fillellipse(x1 + latura * (j - 1) - latura / 4, y1 + latura * (i - 1), latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) - latura / 8, y1 + latura * (i - 1) - latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) + latura / 8, y1 + latura * (i - 1) + latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) - latura / 8, y1 + latura * (i - 1) + latura / 6, latura / 20, latura / 20);
                fillellipse(x1 + latura * (j - 1) + latura / 8, y1 + latura * (i - 1) - latura / 6, latura / 20, latura / 20);
            }

    readimagefile("iepure.jpg", 440, 200, 520, 280);
    readimagefile("vulpe.jpg", 210, 280, 360, 360);
    readimagefile("vulpe2.jpg", 280, 440, 360, 590);
}
void instr();
void initializare()
{

    nivele[1].iepurix[1] = 4;
    nivele[1].iepuriy[1] = 3;
    nivele[1].nriepuri = 1;
    nivele[1].ciupercix[1] = 2;
    nivele[1].ciuperciy[1] = 1;
    nivele[1].ciupercix[2] = 3;
    nivele[1].ciuperciy[2] = 1;
    nivele[1].ciupercix[3] = 4;
    nivele[1].ciuperciy[3] = 2;
    nivele[1].nrvulpi = 0;
    nivele[1].nrciuperci = 3;
    // nivelul 2
    nivele[2].iepurix[1] = 2;
    nivele[2].iepuriy[1] = 1;
    nivele[2].iepurix[2] = 3;
    nivele[2].iepuriy[2] = 5;
    nivele[2].nriepuri = 2;
    nivele[2].ciupercix[1] = 4;
    nivele[2].ciuperciy[1] = 1;
    nivele[2].ciupercix[2] = 3;
    nivele[2].ciuperciy[2] = 2;
    nivele[2].ciupercix[3] = 3;
    nivele[2].ciuperciy[3] = 4;
    nivele[2].nrvulpi = 0;
    nivele[2].nrciuperci = 3;

    // nivelul 3
    nivele[3].iepurix[1] = 1;
    nivele[3].iepuriy[1] = 3;
    nivele[3].iepurix[2] = 3;
    nivele[3].iepuriy[2] = 3;
    nivele[3].iepurix[3] = 5;
    nivele[3].iepuriy[3] = 3;
    nivele[3].nriepuri = 3;
    nivele[3].ciupercix[1] = 4;
    nivele[3].ciuperciy[1] = 3;
    nivele[3].ciupercix[2] = 2;
    nivele[3].ciuperciy[2] = 3;
    nivele[3].ciupercix[3] = 5;
    nivele[3].ciuperciy[3] = 2;
    nivele[3].nrvulpi = 0;
    nivele[3].nrciuperci = 3;
    // nivelul 4
    nivele[4].iepurix[1] = 3;
    nivele[4].iepuriy[1] = 2;
    nivele[4].nriepuri = 1;
    nivele[4].ciupercix[1] = 4;
    nivele[4].ciuperciy[1] = 1;
    nivele[4].ciupercix[2] = 2;
    nivele[4].ciuperciy[2] = 2;
    nivele[4].ciupercix[3] = 3;
    nivele[4].ciuperciy[3] = 3;
    nivele[4].nrvulpi = 1;
    nivele[4].vulpex[1] = 4; // 4si5
    nivele[4].vulpey[1] = 2;
    nivele[4].nrciuperci = 3;
    // nivelul 5
    nivele[5].iepurix[1] = 4;
    nivele[5].iepuriy[1] = 1;
    nivele[5].nriepuri = 1;
    nivele[5].ciupercix[1] = 5;
    nivele[5].ciuperciy[1] = 1;
    nivele[5].ciupercix[2] = 4;
    nivele[5].ciuperciy[2] = 3;
    nivele[5].ciupercix[3] = 3;
    nivele[5].ciuperciy[3] = 5;
    nivele[5].nrvulpi = 2;
    nivele[5].vulpex[1] = 1; // 1 si 2 vulpe in pozitie orizontala//x pentru vulpea 1 x poate fi<=4
    nivele[5].vulpey[1] = 2;
    nivele[5].vulpex[2] = 2;
    nivele[5].vulpey[2] = 4; // 4 si 5 pe y , iar y trebuie sa fie <=4
    nivele[5].nrciuperci = 3;
    cout << "test\n";
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            nivele[nivelcurent].A[i][j] = 0;

    cout << "nivel curent: " << nivelcurent << "\n";
    for (int n = 1; n <= 5; n++)
    {
        nivelcurent = n;

        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= nivele[nivelcurent].nriepuri; k++)
                    if (nivele[nivelcurent].iepurix[k] == j && nivele[nivelcurent].iepuriy[k] == i)
                        nivele[nivelcurent].A[i][j] = 1;

                for (int l = 1; l <= nivele[nivelcurent].nrciuperci; l++)
                    if (nivele[nivelcurent].ciupercix[l] == j && nivele[nivelcurent].ciuperciy[l] == i)
                        nivele[nivelcurent].A[i][j] = 2;

                for (int m = 1; m <= nivele[nivelcurent].nrvulpi; m++)
                {
                    if (m == 1) // vulpea din pozitie orizontala
                        if (nivele[nivelcurent].vulpex[m] == j && nivele[nivelcurent].vulpey[m] == i)
                        {
                            nivele[nivelcurent].A[i][j] = 3;
                            nivele[nivelcurent].A[i][j + 1] = 3;
                        }
                    if (m == 2) // vulpe in pozitie orizontala
                        if (nivele[nivelcurent].vulpex[m] == j && nivele[nivelcurent].vulpey[m] == i)
                        {
                            nivele[nivelcurent].A[i][j] = 3;
                            nivele[nivelcurent].A[i + 1][j] = 3;
                        }
                }
            }
    }
    nivelcurent = 1;
}
void menu()
{
    int x, y, ok = 0;

    initializare();
    readimagefile("img.jpg", 0, 0, 800, 800);
    settextstyle(9, HORIZ_DIR, 20);
    setbkcolor(GREEN);
    outtextxy(100, 150, "JUMPIN'");
    settextstyle(9, HORIZ_DIR, 18);
    rectangle(200, 380, 500, 450);
    outtextxy(206, 383, "START");
    rectangle(66, 497, 715, 565);
    outtextxy(70, 500, "INSTRUCTIUNI");
    rectangle(248, 598, 460, 665);
    outtextxy(250, 600, "EXIT");
    cout << "test\n";
    while (!ismouseclick(WM_LBUTTONDOWN))
        ;

    // if(ismouseclick(WM_LBUTTONDOWN))
    //{

    // clearmouseclick(WM_LBUTTONDOWN);
    getmouseclick(WM_LBUTTONDOWN, x, y);
    // x=mousex();
    // y=mousey();
    cout << "x: " << x << " y: " << y << "\n";
    if (x >= 200 && x <= 500 && y >= 380 && y <= 450)

        ecranactiv = 2; // apasat pe start
    else if (x >= 66 && x <= 715 && y >= 497 && y <= 565)
        ecranactiv = 1; // apasat pe instructiuni
    else if (x >= 248 && x <= 460 && y >= 598 && y <= 665)
        ecranactiv = 3;

    //}
}

void instr()
{
    int x, y;

    cleardevice();
    readimagefile("img.jpg", 0, 0, 800, 800);
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(80, 100, "Un joc haios cu animale mult indragite care o sa");
    outtextxy(60, 120, "ofere momente de concentrare, dar si distractie.");
    outtextxy(60, 140, "Primele provocari se adreseaza copiilor, cele mai");
    outtextxy(60, 160, "avansate sunt antrenante chiar si pentru adulti.");
    outtextxy(60, 180, "Scopul jocului este de a ii ajuta pe iepurasi");
    outtextxy(60, 200, "sa topaie in siguranta. Ai la dispozitie iepurasi,");
    outtextxy(60, 220, "ciupercute, chiar si vulpite pentru a ajuta");
    outtextxy(60, 240, "iepurasii sa ajunga la vizuinile lor. Muta iepurasii");
    outtextxy(60, 260, "si vulpitele pana cand toti iepurasii sunt in");
    outtextxy(60, 260, "siguranta in vizuinile maro. Ai grija: iepurasii");
    outtextxy(60, 280, "se deplaseaza numai prin sarituri peste celelalte");
    outtextxy(60, 300, "figurine. Vulpitele se pot glisa, ai grija sa sari");
    outtextxy(60, 320, "peste ele. Ciupercutele sunt fixe. Iepurasii poznasi");
    outtextxy(60, 340, "pot sari si peste un grup de figurine, dar nu pot");
    outtextxy(60, 360, "sari direct in vizuina.");
    settextstyle(9, HORIZ_DIR, 15);
    setbkcolor(GREEN);

    outtextxy(68, 497, "INAPOI LA MENIU");
    rectangle(66, 497, 445, 530);
    settextstyle(9, HORIZ_DIR, 15);
    setbkcolor(GREEN);
    /*outtextxy(500,497, "EXEMPLU");
    rectangle(500,497,710,530);*/

    while (!ismouseclick(WM_LBUTTONDOWN))
        ;

    getmouseclick(WM_LBUTTONDOWN, x, y);
    // x=mousex();
    // y=mousey();
    cout << "x: " << x << " y: " << y << "\n";
    /* if(x>=500 && x<=710 && y>=497 && y<=530)
      exemplu();
     else*/
    if (x >= 66 && x <= 445 && y >= 497 && y <= 530)
        ecranactiv = 0; // intoarcere inapoi in meniu
}

void menu_2()
{
    readimagefile("img.jpg", 0, 0, 800, 800);
    settextstyle(9, HORIZ_DIR, 20);
    setbkcolor(GREEN);
    outtextxy(150, 150, "JUMPIN'");
    settextstyle(9, HORIZ_DIR, 17);
    outtextxy(200, 400, "FELICITARI!");
    rectangle(500, 600, 705, 660); // mouse-ul trebuie sa fie intre dim astea
    outtextxy(503, 603, "NEXT");
    rectangle(50, 600, 273, 660); // mouse-ul trebuie sa fie intre dim astea
    outtextxy(53, 603, "MENU");
    int x, y;
    while (!ismouseclick(WM_LBUTTONDOWN))
        ;

    getmouseclick(WM_LBUTTONDOWN, x, y);
    if (x >= 500 && x <= 705 && y >= 600 && y <= 660)
        ecranactiv = 2; // incepe iar jocul cu un alt nivel curent

    if (x >= 100 && x <= 325 && y >= 600 && y <= 660)
    {
        ecranactiv = 0;
        nivelcurent = 1;
    }
}

void pozitieSuccesoare(int j, int i, int index)
{
    int dreapta, stanga, sus, jos, dreapta1, stanga1, sus1, jos1;
    cout << i << " " << j << "\n";
    dreapta1 = stanga1 = sus1 = jos1 = 0;
    dreapta = j + 1;
    stanga = j - 1;
    sus = i - 1;
    jos = i + 1;
    if (nivele[nivelcurent].A[i][dreapta] != 0 && dreapta <= 5) // sa nu iasa din matrice
    {
        while (nivele[nivelcurent].A[i][dreapta] != 0 && dreapta <= 5)
            dreapta++;
        dreapta1 = dreapta;
    }
    else
        dreapta1 = j;
    if (nivele[nivelcurent].A[i][stanga] != 0 && stanga >= 1)
    {
        while (nivele[nivelcurent].A[i][stanga] != 0 && stanga >= 1)
            stanga--;

        stanga1 = stanga;
    }
    else
        stanga1 = j;
    cout << nivele[nivelcurent].A[sus][j] << " " << sus << "\n";
    if (nivele[nivelcurent].A[sus][j] != 0 && sus >= 1)
    {
        while (nivele[nivelcurent].A[sus][j] != 0 && sus >= 1)
            sus--;
        sus1 = sus;
        cout << "test\n";
    }
    else
        sus1 = i;

    if (nivele[nivelcurent].A[jos][j] != 0 && jos <= 5)
    {
        while (nivele[nivelcurent].A[jos][j] != 0 && jos <= 5)

            jos++;
        jos1 = jos;
    }
    else
        jos1 = i;
    cout << sus1 << " " << dreapta1 << " " << jos1 << " " << stanga1 << "\n";
    if (jos1 != 0 && jos1 != i && jos1 >= 1 && jos1 <= 5)
    {
        setfillstyle(1, WHITE);
        setcolor(WHITE);
        fillellipse(x1 + latura * (j - 1), y1 + latura * (jos1 - 1), latura / 3, latura / 3);
    }

    if (sus1 != 0 && sus1 != i && sus1 >= 1 && sus1 <= 5)
    {
        setfillstyle(1, WHITE);
        setcolor(WHITE);
        fillellipse(x1 + latura * (j - 1), y1 + latura * (sus1 - 1), latura / 3, latura / 3);
    }
    if (dreapta1 != 0 && dreapta1 != j && dreapta1 >= 1 && dreapta1 <= 5)
    {
        setfillstyle(1, WHITE);
        setcolor(WHITE);
        fillellipse(x1 + latura * (dreapta1 - 1), y1 + latura * (i - 1), latura / 3, latura / 3);
    }
    if (stanga1 != 0 && stanga1 != j && stanga1 >= 1 && stanga1 <= 5)
    {
        setfillstyle(1, WHITE);
        setcolor(WHITE);
        fillellipse(x1 + latura * (stanga1 - 1), y1 + latura * (i - 1), latura / 3, latura / 3);
    }
    int x, y;
    while (!ismouseclick(WM_LBUTTONDOWN))
        ;
    getmouseclick(WM_LBUTTONDOWN, x, y);
    int linia = (y - ::sus) / latura + 1;
    int coloana = (x - ::stanga) / latura + 1;
    cout << "lc: " << y - ::sus << " " << latura << " " << x - ::stanga << "\n";
    if (coloana == stanga1 && linia == i || coloana == dreapta1 && linia == i || linia == sus1 && coloana == j || linia == jos1 && coloana == j)
    {
        cout << "if working\n";
        nivele[nivelcurent].A[linia][coloana] = 1;
        nivele[nivelcurent].A[i][j] = 0;
        nivele[nivelcurent].iepurix[index] = coloana;
        nivele[nivelcurent].iepuriy[index] = linia;
    }
}
void pozitieVulpe(int j, int i, int index)
{
    cout << "aaaa\n";
    int dreapta, stanga, sus, jos, dreapta1, stanga1, sus1, jos1;
    dreapta1 = stanga1 = sus1 = jos1 = 0;
    if (index == 1)
    {
        dreapta = j + 1;
        stanga = j;
        if (nivele[nivelcurent].A[i][dreapta + 1] == 0 && dreapta <= 5)
        {
            while (nivele[nivelcurent].A[i][dreapta + 1] == 0 && dreapta < 5)
                dreapta++;
            dreapta1 = dreapta;
        }
        else
            dreapta1 = j;
        if (nivele[nivelcurent].A[i][stanga - 1] == 0 && stanga >= 1)
        {
            while (nivele[nivelcurent].A[i][stanga - 1] == 0 && stanga > 1)
                stanga--;
            stanga1 = stanga;
        }

        else
            stanga1 = j;
    }
    if (index == 2)
    {
        sus = i;
        jos = i + 1;
        if (nivele[nivelcurent].A[jos + 1][j] == 0 && jos <= 5)
        {
            while (nivele[nivelcurent].A[jos + 1][j] == 0 && jos < 5)
                jos++;
            jos1 = jos;
        }
        else
            jos1 = i;
        if (nivele[nivelcurent].A[sus - 1][j] == 0 && sus >= 1)
        {
            while (nivele[nivelcurent].A[sus - 1][j] == 0 && sus > 1)
                sus--;
            sus1 = sus;
        }

        else
            sus1 = i;
    }
    int x, y;
    while (!ismouseclick(WM_LBUTTONDOWN))
        ;
    getmouseclick(WM_LBUTTONDOWN, x, y);
    int linia = (y - ::sus) / latura + 1;
    int coloana = (x - ::stanga) / latura + 1;
    if (index == 1) // verific dreapta si stanga
    {
        cout << "test index 1 " << linia << " " << coloana << "\n";
        if (dreapta1 != j && coloana >= j + 2 && coloana <= dreapta1)
        {
            nivele[nivelcurent].A[i][j] = 0;
            nivele[nivelcurent].A[i][j + 1] = 0;
            nivele[nivelcurent].A[i][coloana] = 3;
            nivele[nivelcurent].A[i][coloana - 1] = 3;
            nivele[nivelcurent].vulpex[index] = coloana - 1;
            nivele[nivelcurent].vulpey[index] = i;
        }
        cout << stanga << " " << j << " " << coloana << " " << stanga1 << "\n";
        if (stanga1 != j && coloana <= j - 1 && coloana >= stanga1)
        {
            nivele[nivelcurent].A[i][j] = 0;
            nivele[nivelcurent].A[i][j + 1] = 0;
            nivele[nivelcurent].A[i][coloana] = 3;
            nivele[nivelcurent].A[i][coloana + 1] = 3;
            nivele[nivelcurent].vulpex[index] = coloana;
            nivele[nivelcurent].vulpey[index] = i;
        }
    }
    else // index 2
    {
        if (sus1 != i && linia <= i - 1 && linia >= sus1)
        {
            nivele[nivelcurent].A[i][j] = 0;
            nivele[nivelcurent].A[i + 1][j] = 0;
            nivele[nivelcurent].A[linia][j] = 3;
            nivele[nivelcurent].A[linia + 1][j] = 3;
            nivele[nivelcurent].vulpex[index] = j;
            nivele[nivelcurent].vulpey[index] = linia;
        }
        cout << jos1 << " " << i << " " << linia << " \n";
        if (jos1 != i && linia >= i + 2 && linia <= jos1)
        {
            nivele[nivelcurent].A[i][j] = 0;
            nivele[nivelcurent].A[i + 1][j] = 0;
            nivele[nivelcurent].A[linia][j] = 3;
            nivele[nivelcurent].A[linia - 1][j] = 3;
            nivele[nivelcurent].vulpex[index] = j;
            nivele[nivelcurent].vulpey[index] = linia - 1;
        }
    }
}
void joc()
{ // cleardevice();
    settextstyle(9, HORIZ_DIR, 18);
    readimagefile("img.jpg", 0, 0, 800, 800);
    char nume[50] = "JUMPIN' LEVEL ";
    char level[10];
    itoa(nivelcurent, level, 10); // 10-baza in care o sa fie nivelcurent;
    strcat(nume, level);

    outtextxy(50, 100, nume);
    desen(400, 400);
    cout << "joc\n";

    for (int i = 1; i <= 5; i++)
    {

        for (int j = 1; j <= 5; j++)
            cout << nivele[nivelcurent].A[i][j] << " ";
        cout << "\n";
    }
    for (int i = 1; i <= 3; i++)
    {
        // desenam ciupercile
        setfillstyle(SOLID_FILL, RED); // UMPLUTURA

        setcolor(RED); // PENTRU MARGINE
        fillellipse(x1 + latura * (nivele[nivelcurent].ciupercix[i] - 1), y1 + latura * (nivele[nivelcurent].ciuperciy[i] - 1), latura / 3, latura / 3);
        setfillstyle(1, WHITE); // CULOAREA DE UMPLERE A ELIPSELOR PE CARE LE DESENAM
        setcolor(WHITE);        // MARGINEA BULINELOR

        fillellipse(x1 + latura * (nivele[nivelcurent].ciupercix[i] - 1), y1 + latura * (nivele[nivelcurent].ciuperciy[i] - 1), latura / 20, latura / 20);              // bulina din centru
        fillellipse(x1 + latura * (nivele[nivelcurent].ciupercix[i] - 1) + latura / 4, y1 + latura * (nivele[nivelcurent].ciuperciy[i] - 1), latura / 20, latura / 20); // buline lateral
        fillellipse(x1 + latura * (nivele[nivelcurent].ciupercix[i] - 1) - latura / 4, y1 + latura * (nivele[nivelcurent].ciuperciy[i] - 1), latura / 20, latura / 20);
        fillellipse(x1 + latura * (nivele[nivelcurent].ciupercix[i] - 1) - latura / 8, y1 + latura * (nivele[nivelcurent].ciuperciy[i] - 1) - latura / 6, latura / 20, latura / 20);
        fillellipse(x1 + latura * (nivele[nivelcurent].ciupercix[i] - 1) + latura / 8, y1 + latura * (nivele[nivelcurent].ciuperciy[i] - 1) + latura / 6, latura / 20, latura / 20);
        fillellipse(x1 + latura * (nivele[nivelcurent].ciupercix[i] - 1) - latura / 8, y1 + latura * (nivele[nivelcurent].ciuperciy[i] - 1) + latura / 6, latura / 20, latura / 20);
        fillellipse(x1 + latura * (nivele[nivelcurent].ciupercix[i] - 1) + latura / 8, y1 + latura * (nivele[nivelcurent].ciuperciy[i] - 1) - latura / 6, latura / 20, latura / 20);
    }

    for (int i = 1; i <= nivele[nivelcurent].nriepuri; i++)
    {

        // readimagefile("iepure.jpg",440,360,520,440);
        int x = x1 + latura * (nivele[nivelcurent].iepurix[i] - 1) - latura / 2;
        int y = x1 + latura * (nivele[nivelcurent].iepuriy[i] - 1) - latura / 2;
        if (i == 1)
            readimagefile("iepure.jpg", x, y, x + latura, y + latura);
        if (i == 2)
            readimagefile("iepuremaro.jpg", x, y, x + latura, y + latura);
        if (i == 3)
            readimagefile("iepurealbastru.jpg", x, y, x + latura, y + latura);
    }
    for (int i = 1; i <= nivele[nivelcurent].nrvulpi; i++)
    {
        int x = x1 + latura * (nivele[nivelcurent].vulpex[i] - 1) - latura / 2;
        int y = x1 + latura * (nivele[nivelcurent].vulpey[i] - 1) - latura / 2;
        if (i == 1)
            readimagefile("vulpe.jpg", x, y, x + 2 * latura, y + latura);
        if (i == 2)
            readimagefile("vulpe2.jpg", x, y, x + latura, y + 2 * latura);
    }

    bool finalizare = true;
    for (int i = 1; i <= nivele[nivelcurent].nriepuri; i++)
        if (!(nivele[nivelcurent].iepurix[i] == 1 && (nivele[nivelcurent].iepuriy[i] == 1 || nivele[nivelcurent].iepuriy[i] == 5) || nivele[nivelcurent].iepurix[i] == 5 && (nivele[nivelcurent].iepuriy[i] == 1 || nivele[nivelcurent].iepuriy[i] == 5) || nivele[nivelcurent].iepurix[i] == 3 && nivele[nivelcurent].iepuriy[i] == 3))
        {

            finalizare = false;
        }
    if (finalizare == true)
    { /* for(int i=1;i<=5;i++)
       for(int j=1;j<=5;j++) nivele[nivelcurent].A[i][j]=nivele[nivelcurent].B[i][j];*/
        nivelcurent = nivelcurent + 1;
        ecranactiv = 10;
        delay(1000);
        return;
    }
    while (!ismouseclick(WM_LBUTTONDOWN))
        ;
    int x, y;
    getmouseclick(WM_LBUTTONDOWN, x, y);
    int linia = (y - sus) / latura + 1;
    int coloana = (x - stanga) / latura + 1;
    //   cout<<"pos "<<linia<<" "<<coloana<<

    for (int i = 1; i <= nivele[nivelcurent].nriepuri; i++)
        if (coloana == nivele[nivelcurent].iepurix[i] && linia == nivele[nivelcurent].iepuriy[i])
        {
            cout << "fortest1\n";
            pozitieSuccesoare(nivele[nivelcurent].iepurix[i], nivele[nivelcurent].iepuriy[i], i); // desenare de cercuri albe
        }
    for (int i = 1; i <= nivele[nivelcurent].nrvulpi; i++)
    {

        if (i == 1) // prima vulpe
            if ((coloana == nivele[nivelcurent].vulpex[1] || coloana == nivele[nivelcurent].vulpex[1] + 1) && linia == nivele[nivelcurent].vulpey[1])
            {
                cout << "ifpositie\n";
                pozitieVulpe(nivele[nivelcurent].vulpex[i], nivele[nivelcurent].vulpey[i], i);
            } // i spune a cata vulpe
        if (i == 2)
            if ((linia == nivele[nivelcurent].vulpey[2] || linia == nivele[nivelcurent].vulpey[2] + 1) && coloana == nivele[nivelcurent].vulpex[2])
                pozitieVulpe(nivele[nivelcurent].vulpex[i], nivele[nivelcurent].vulpey[i], i);
    }

    cout << "test\n";
}
int main()
{
    initwindow(800, 800, "windows BGI", 0, 0);

    int x, y;

    cout << "a\n";

    while (aplicatiepornita)
    {
        // setactivepage(1);
        if (ecranactiv == 0)
            menu();
        if (ecranactiv == 1)
            instr();
        if (ecranactiv == 2) //|| ecranactiv==3 || ecranactiv==4 || ecranactiv==5 || ecranactiv==6)
            joc();
        if (ecranactiv == 10)
            menu_2();
        if (ecranactiv == 3)
        {
            closegraph();
            return 0;
        }
    }

    // getch();
    closegraph();

    cout << "Hello world!" << endl;
    return 0;
}
