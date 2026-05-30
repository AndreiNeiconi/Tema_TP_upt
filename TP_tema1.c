
#include <stdio.h>
#include <stdlib.h>
#define maxim_charactere_nume 300
/*
Am folosit o abordare mai coplexa pentru a fii mai usor de implementat functiile viitoare din problema 2,3 

*/

struct Pacient {
    char name[maxim_charactere_nume];
    int varsta;
    float glicemie;
    int sys;
    int dia;
    int puls;
};
// Am folosit propotipe de functii pentru a fii mai usor de citit si de a avea functia main cat mai sus in code 
void afisiere_pacienti(struct Pacient* lista_pacienti, int n);
float medie_valori(struct Pacient* lista_pacienti, int n,int selector);
void afisiare_medie_valori(struct Pacient* lista_pacienti, int n,int selector);
void afisiare_risc_valori_marite(struct Pacient* lista_pacienti, int n,int selector);



int main() {

    int optiune;
    int n = 0;
    int data_count = 0;
    struct Pacient pacient;
    struct Pacient *pacient_list = NULL;
    int total_pacienti = 0;

    do {
        // Afisarea Meniului
        printf("\n======= MENIU PACIENTI =======\n");
        printf("1. Introducerea datelor pacientilor\n");
        printf("2. Afisarea pacientilor\n");
        printf("3. Valoarea medie a glicemiei\n");
        printf("4. Pacienti cu glicemia > 180\n");
        printf("5. Pacienti cu tensiunea > [valoare]\n");
        printf("0. Iesire\n");
        printf("==============================\n");
        printf("Alegeti o optiune: ");
        scanf_s("%d", &optiune);

        switch (optiune) {
            case 1:
                
                printf("Cati pacenti noi doriti sa introduceti?\n");
                scanf_s("%d", &n);
                //alocam dinamic memoria dupa ce stim numarul de pacienti care urmeaza sa fie introdusi
                pacient_list = (struct Pacient*)realloc(pacient_list, (total_pacienti + n) * sizeof(struct Pacient));
                

   

                for (int i = total_pacienti;i <= total_pacienti+ n - 1;i++) {
                    printf("\nNume:");
                    scanf_s("%s", pacient_list[i].name, maxim_charactere_nume);
                    printf("\nvarsta:");
                    scanf_s("%d", &pacient_list[i].varsta);
                    printf("\nglicemie:");
                    scanf_s("%f", &pacient_list[i].glicemie);
                    printf("\nsys:");
                    scanf_s("%d", &pacient_list[i].sys);
                    printf("\ndia:");
                    scanf_s("%d", &pacient_list[i].dia);
                    printf("\npuls:");
                    scanf_s("%d", &pacient_list[i].puls);

                }
                total_pacienti += n;
                data_count = 1;
                break;

            case 2:
                if (data_count == 0) {
                    printf("\nEroare: Nu ati introdus datele pacientilor inca!\n");
                }
                else {
                    printf("\n--- Lista Pacienti ---\n");
                    afisiere_pacienti(pacient_list, total_pacienti);
                }
                break;

            case 3:
                if (data_count == 0) {
                    printf("\nEroare: Nu ati introdus datele pacientilor inca!\n");
                }
                else {
                    // Apeleaza functia de medie (optiunea 1 din afisiare_medie_valori a ta)
                    afisiare_medie_valori(pacient_list, total_pacienti, 1);
                }
                break;
            case 4:
                if (data_count == 0) {
                printf("\nEroare: Nu ati introdus datele pacientilor inca!\n");
                }
                else {
                    // Apeleaza functia ta de filtru pentru glicemie > 180 (selector 2)
                    afisiare_risc_valori_marite(pacient_list, total_pacienti, 2);
                }
                break;
            case 5:
                if (data_count == 0) {
                    printf("\nEroare: Nu ati introdus datele pacientilor inca!\n");
                }
                else {
                    // Apeleaza functia ta de filtru tensiune (selector 3)
                    afisiare_risc_valori_marite(pacient_list, total_pacienti, 3);
                }
                break;
            case 0:
                printf("\nIesire din program. O zi buna!\n");
                if (pacient_list != NULL) {
                    free(pacient_list);
                }
                break;
            default:
                printf("\nOptiune invalida! Va rugam introduceti un numar intre 0 si 5.\n");
                break;
                

        }
    } while (optiune !=0);

    
    return 0;

    



}
//afisare
void afisiere_pacienti(struct Pacient* lista_pacienti, int n) {
    for (int i = 0;i < n;i++) {
        printf("Nume:%s\nVarsta:%d \nGlicemia:%f mg/dl \nTensinea arteriala:%d/%d \nPuls:%d \n", lista_pacienti[i].name, lista_pacienti[i].varsta, lista_pacienti[i].glicemie, lista_pacienti[i].sys, lista_pacienti[i].dia, lista_pacienti[i].puls);
    }
}

void afisiare_medie_valori(struct Pacient* lista_pacienti, int n, int selector) {
    switch (selector) {
    //Glicemie
    case 1:
        printf("\nmedie gliciemie:%f", medie_valori(lista_pacienti, n, 1));
        break;
    //Tensiune
    case 2:
        
        printf("\nmedia tensiunilor:%f/%f", medie_valori(lista_pacienti, n, 2), medie_valori(lista_pacienti, n, 3));
        break;
     //puls
    case 3:
        printf("\nmedie puls:%f", medie_valori(lista_pacienti, n, 4));
        break;
    }
}
void afisiare_risc_valori_marite(struct Pacient* lista_pacienti, int n, int selector) {
    int valoare_filtru;
    printf("\nSelectati valoarea dupa care vreti sa filtrati");
    scanf_s("%d",&valoare_filtru);
    printf("\nVlorile pacientilor :");
    switch (selector) {
        //gliceme
        case 1:
            for (int i = 0;i < n;i++) {
                if (lista_pacienti[i].glicemie > valoare_filtru) {
                    printf("\n%s:%d",lista_pacienti[i].name, lista_pacienti[i].glicemie);
                }
            }
            break;
        //cazul pentru cerinta problemei
        case 2:
            for (int i = 0;i < n;i++) {
                if (lista_pacienti[i].glicemie > 180) {
                    printf("\n%s:%.2f", lista_pacienti[i].name, lista_pacienti[i].glicemie);
                }
            }
            break;
        // Tensiunea sistemica
        case 3:
            for (int i = 0;i < n;i++) {
                if (lista_pacienti[i].sys > valoare_filtru) {
                    printf("\n%s:%d", lista_pacienti[i].name, lista_pacienti[i].sys);
                }
            }
            break;
        //Puls
        case 4:
            for (int i = 0;i < n;i++) {
                if (lista_pacienti[i].puls > valoare_filtru) {
                    printf("\n%s:%d", lista_pacienti[i].name, lista_pacienti[i].puls);
                }
            }
            break;


    }
}



//calculare
float medie_valori(struct Pacient* lista_pacienti, int n, int selector) {
    float suma = 0;

    switch(selector){
    //Glicemie
    case 1:
        for (int i = 0;i < n;i++) {
            suma = suma + lista_pacienti[i].glicemie;

        }
        return suma/n;
        break;
    //sys
    case 2:
        for (int i = 0;i < n;i++) {
            suma = suma + lista_pacienti[i].sys;

        }
        return suma / n;
        break;
    //dya
    case 3:
        for (int i = 0;i < n;i++) {
            suma = suma + lista_pacienti[i].dia;

        }
        return suma / n;

        break;
    //puls
    case 4:
        for (int i = 0;i < n;i++) {
            suma = suma + lista_pacienti[i].puls;

        }
        return suma / n;
    default:
        perror("Nu ati selectat nici un meniu");
    }
}



