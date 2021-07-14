#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std; 
 

struct node {
 
    int data;
    struct node *next;
    struct node *prev;
};
 

struct node* start = NULL;
 

struct node* dugumOlustur(int veri)
{
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->data = veri;
    yeniDugum->next = NULL;
    yeniDugum->prev = NULL;
 
    return yeniDugum;
}
 

void CYBL_sonaelemanekle(int veri)
{
    struct node* sonaEklenecek = dugumOlustur(veri);
 
    
    if (start == NULL)
    {
        start = sonaEklenecek;
    }
 
    else
    {
        
        struct node* temp = start;
 
       
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
 
      
        sonaEklenecek->prev = temp;
 
       
        temp->next = sonaEklenecek;
    }
}
 

void CYBL_basaelemanekle(int veri)
{
    struct node* basaEklenecek = dugumOlustur(veri);
 
    if (start == NULL)
    {
        start = basaEklenecek;
        return;
    }
 
    start->prev = basaEklenecek;
    basaEklenecek->next = start;
    start = basaEklenecek;
}
 

void CYBL_siralielemanekle(int kiminOnune, int eklenecek)
{
    struct node* temp = start;
    struct node* arayaEklenecek = dugumOlustur(eklenecek);
    struct node* onceki = NULL;
 
    if (start == NULL)
    {
        start = arayaEklenecek;
    }
    else if(start->data == kiminOnune)
    {
        CYBL_basaelemanekle(eklenecek);
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->data == kiminOnune)
            {
                onceki = temp->prev;
                break;
            }
            temp = temp->next;
        }
        temp->prev = arayaEklenecek;
        arayaEklenecek->next = temp;
        arayaEklenecek->prev = onceki;
        onceki->next = arayaEklenecek;
    }
 
 
}
 

void CYBL_bastanelemansilme()
{
    if (start == NULL)
    {
        cout <<"\n Liste zaten bos ....";
        return;
    }
 
    if (start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }
 
    struct node* ikinci = start->next;
    free(start);
    ikinci->prev = NULL;
    start = ikinci;
}
 

void CYBL_sondanelemansilme()
{
    if (start == NULL)
    {
        cout<<"\n Liste zaten bos ....";
        return;
    }
 
    if (start->next == NULL)
    {
        CYBL_bastanelemansilme();
        return;
    }
 
    struct node* temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
 
    struct node* onceki = temp->prev;
    free(temp);
    onceki->next = NULL;
}

void  CYBL_belirlielemansilme(int silinecek)
{
    struct node* temp = start;
    while (temp->next != NULL)
    {
        if (temp->data == silinecek)
            break;
        temp = temp->next;
    }
        if(temp->next == NULL)
        cout<<"Silinecek Deger Bagli Listede Bulunmamaktadir";
         
   
    struct node* sonraki = temp->next;
    struct node* onceki = temp->prev;
    free(temp);
    onceki->next = sonraki;
    sonraki->prev = onceki;
}
 

void yazdir()
{
    struct node* temp = start;
 
    while (temp != NULL)
    {
        cout<< temp->data;
        temp = temp->next;
        cout<<"--";
    }
}
 
 
 
int main()
{
 
    int secim, sayi, sayi1;
    CYBL_basaelemanekle(10);  CYBL_sonaelemanekle(20);  CYBL_sonaelemanekle(100);  CYBL_sonaelemanekle(50); 
	CYBL_sonaelemanekle(40);  CYBL_sonaelemanekle(60);  CYBL_sonaelemanekle(30);  CYBL_sonaelemanekle(90);
	  
	 cout<<"Cift Yonlu Bagli Listenin Ilk Hali:  "; yazdir();
	 cout<<"\n\n";
 
    while (1)
    {
        cout<<"\n 1- sona eleman ekleme";
        cout<<"\n 2- basa eleman ekleme";
        cout<<"\n 3- araya eleman ekleme";
        cout<<"\n 4- bastan eleman sil";
        cout<<"\n 5- sondan eleman sil";
        cout<<"\n 6- aradan eleman sil";
        cout<<"\n Seciminizi yapin ... ";
        cin>>secim;
 
        switch (secim)
        {
            case 1:
                cout<<"\n Sona Eklemek istediginiz elemani girin ... ";
                cin>>sayi;
               CYBL_sonaelemanekle(sayi);
                cout<<"Cift Yonlu Bagli Listenin Yeni Hali:  "; yazdir();
	            cout<<"\n\n";
                
               
                break;
            case 2:
                cout<<"\n Basa Eklemek istediginiz elemani girin ... ";
                cin>>sayi;
                CYBL_basaelemanekle(sayi);
                cout<<"Cift Yonlu Bagli Listenin Yeni Hali:  "; yazdir();
	            cout<<"\n\n";
                
               
                break;
 
            case 3:
                cout<<"\n Araya Eklemek istediginiz sayiyi girin ... ";
                cin>>sayi;
                cout<<"\n Hangi elemanin arkasina eklemek istiyorsunuz... ";
                cin>>sayi1;
                CYBL_siralielemanekle(sayi1, sayi);
                cout<<"Cift Yonlu Bagli Listenin Yeni Hali:  "; yazdir();
	            cout<<"\n\n";
                
                break;
            case 4:
                CYBL_bastanelemansilme();
                cout<<"Cift Yonlu Bagli Listenin Yeni Hali:  "; yazdir();
	            cout<<"\n\n";
               
                break;
 
            case 5:
                CYBL_sondanelemansilme();
                cout<<"Cift Yonlu Bagli Listenin Yeni Hali:  "; yazdir();
	            cout<<"\n\n";
			
                break;
 
            case 6:
                cout<<"\n Silinmesini istedigini elemani girin ... ";
                cin>>sayi;
                 CYBL_belirlielemansilme(sayi);
               	cout<<"Cift Yonlu Bagli Listenin Yeni Hali:  "; yazdir();
	            cout<<"\n\n";
	           
                break;
 
        }
    }
    getch(); 
    return 0;
}
