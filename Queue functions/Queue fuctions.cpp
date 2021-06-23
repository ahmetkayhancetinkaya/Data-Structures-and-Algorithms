#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream> 

using namespace std;

#define BOYUT 8 
 
int KuyrukOlustur[BOYUT]={'0'};
int on   = 0;
int arka = 0;
 
int elemanekle(int);
int elemansil();
int kuyruk_dolumu();
int kuyruk_bosmu();
void elemanyazdir();
 
int main(){
     
     
    elemanekle(10);elemanyazdir();
    elemanekle(20);elemanyazdir();
    elemanekle(30);elemanyazdir();
    elemanekle(40);elemanyazdir();
    elemanekle(50);elemanyazdir();
    elemanekle(60);elemanyazdir();
    elemanekle(70);elemanyazdir();
    cout<<"\n";
    
    elemanekle(80);
    cout<<"\n";
    
    
    elemansil();elemanyazdir();
    elemansil();elemanyazdir();
    elemansil();elemanyazdir();
    elemansil();elemanyazdir();
    elemansil();elemanyazdir();
    elemansil();elemanyazdir();
    elemansil();elemanyazdir();
 
    cout<<"\n";
    
    elemansil();
    
    getch();
    return 0;
 
 
}
int elemanekle(int eklenecek){
     
    if(kuyruk_dolumu())
        cout<<"Kuyruk Dolu Ekleme Yapilamaz!\n";
    else{
        arka=(arka+1)%BOYUT;
        KuyrukOlustur[arka]=eklenecek;
    }
}
int elemansil(){
     
    if(kuyruk_bosmu())
       cout<<"Kuyruk Bos Silme Yapilamaz!\n";
    else{
        on=(on+1) % BOYUT;
        return KuyrukOlustur[on];}
}
int kuyruk_dolumu(){
    return (arka+1)%BOYUT==on;
}
int kuyruk_bosmu(){
    return on==arka;
}
void elemanyazdir(){
     
    int i;
        for(i=(on+1)%BOYUT;i!=(arka+1)%BOYUT;i=(i+1)%BOYUT)
           {
           	cout<<KuyrukOlustur[i]; cout<<"--";
           }
           cout<<"\n";
     
}
