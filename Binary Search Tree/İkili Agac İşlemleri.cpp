#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std; 

struct dugum
{
    int veri;
    dugum * sol;
    dugum * sag;
};

typedef dugum eleman;


eleman* ekle(eleman* agac, int eklenecekDeger)
{
    
    if (agac == NULL)
    {
       
        eleman* kok = (eleman*)malloc(sizeof(eleman));

       
        kok->sag = NULL;
        kok->sol = NULL;

       
        kok->veri = eklenecekDeger;

       
        return kok;
    }

    
    if (agac->veri < eklenecekDeger)
    {
        agac->sag = ekle(agac->sag, eklenecekDeger);
    }
    else 
    {
        agac->sol = ekle(agac->sol, eklenecekDeger);
    }

 
    return agac;
}

int enKdeger(eleman* agac)
{
    eleman* arayici = agac;

   
    while(arayici->sol != NULL)
        arayici = arayici->sol;

   
    return arayici->veri;
}


int enBdeger(eleman* agac)
{
    eleman* arama_dugumu = agac;

  
    while(arama_dugumu->sag != NULL)
        arama_dugumu = arama_dugumu->sag;


    return arama_dugumu->veri;
}


eleman* sil(eleman* agac, int silinecekDeger)
{

    if (agac == NULL)
    {
        return NULL;
    }


    if (silinecekDeger == agac->veri)
    {
     
        if (agac->sol == NULL && agac->sag == NULL)
        {
            return NULL;
        }

   
        if (agac->sag != NULL)
        {
    
            agac->veri = enKdeger(agac->sag);

          
            agac->sag = sil(agac->sag, enKdeger(agac->sag));

            return agac;
        }
      
        if (agac->sol != NULL)
        {
           
            agac->veri = enBdeger(agac->sol);

           
            agac->sol = sil(agac->sol, enBdeger(agac->sol));
            return agac;
        }
    }

    if (silinecekDeger < agac->veri)
    {
      
        agac->sol = sil(agac->sol, silinecekDeger);
        return agac;
    }
    
 
    agac->sag = sil(agac->sag, silinecekDeger);

   
    return agac;
}


void kokten_saga_yazdir(eleman* agac)
{
   
    if (agac == NULL)
    {
        return;
    }

 
    cout << agac->veri << " ";

   
    kokten_saga_yazdir(agac->sol);

   
    kokten_saga_yazdir(agac->sag);
}

int main(int argc, char *argv[])
{
   
    eleman* agac = NULL;

   
    agac = ekle(agac, 20);
    agac = ekle(agac, 15);
    agac = ekle(agac, 10);
    agac = ekle(agac, 30);
    agac = ekle(agac, 40);
  
    
    
    cout<<"Agac="<<endl;
    kokten_saga_yazdir(agac);
    cout<<"\n"<<"--------------------------"<<"\n"<< endl;
  



 
    cout<<"En Kucuk Deger="<<endl;
    cout << enKdeger(agac) <<"\n"<<"--------------------------"<<"\n"<<endl;
    
    cout<<"En Buyuk Deger="<<endl;
    cout << enBdeger(agac)<<"\n"<<"--------------------------"<<"\n" << endl;

 
 
   
    cout << endl;

    cout << endl;

    return 0;
}
