#include <iostream>
#include<stdio.h> 
#include<conio.h> 

using namespace std;

struct Dugum 
{ 
    int key; 
    struct Dugum *left, *right; 
}; 
  
 
struct Dugum *newDugum(int item) 
{ 
    struct Dugum *temp = new Dugum; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  

void yrdmc_AgcSrlm(Dugum *root, int arr[], int &i) 
{ 
    if (root != NULL) 
    { 
        yrdmc_AgcSrlm(root->left, arr, i); 
        arr[i++] = root->key; 
        yrdmc_AgcSrlm(root->right, arr, i); 
    } 
} 
  

Dugum* insert(Dugum* node, int key) 
{ 
    
    if (node == NULL) return newDugum(key); 
  
    
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
  
   
    return node; 
} 
  

void treeSort(int arr[], int n) 
{ 
    struct Dugum *root = NULL; 
  
  
    root = insert(root, arr[0]); 
    for (int i=1; i<n; i++) 
        root = insert(root, arr[i]); 
  
    
    int i = 0; 
    yrdmc_AgcSrlm(root, arr, i); 
} 

void yerdegistir(int *xp, int *yp) 
{ 
    int gecici = *xp; 
    *xp = *yp; 
    *yp = gecici; 
} 

int yrdmc_HzlSrlm (int arr[], int Alt, int Ust) 
{ 
    int pivot = arr[Ust];    
    int i = (Alt - 1);   
  
    for (int j = Alt; j <= Ust- 1; j++) 
    { 
       
        if (arr[j] <= pivot) 
        { 
            i++;     
            yerdegistir(&arr[i], &arr[j]); 
        } 
    } 
    yerdegistir(&arr[i + 1], &arr[Ust]); 
    return (i + 1); 
} 
  

void quickSort(int arr[], int Alt, int Ust) 
{ 

    if (Alt < Ust) 
    { 
        
        int pi = yrdmc_HzlSrlm(arr, Alt, Ust); 
  
        quickSort(arr, Alt, pi - 1); 
        quickSort(arr, pi + 1, Ust); 
    } 
} 
 
 void shell_sort (int *p, int size)
{
   int   i, j, k, temp;
   for (k = size; k > 1; ) {
      k = (k < 5) ? 1 : ((k * 5 - 1) / 11);
      for (i = k - 1; ++i < size; ) {
         temp = p[i];
         for (j = i; p[j - k] > temp; ) {
            p[j] = p[j - k];
            if ((j -= k) < k)
               break;
         }
         p[j] = temp;
      }
   }
} 

										     


void diziyazdir(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<" ";
} 
  

int main() 
{ 
    
    int n; 
    cout<<"Diziye kac eleman gireceksiniz ";
    cin>>n;
    
	int arr[n];
	int k=0;
	for(k;k<n;k++){
		cout<<k+1<<" nci elemani girin: ";
		cin>>arr[k]; 
	} 
    cout<<"Diziniz: ";
    diziyazdir(arr,n); cout<<"\n\n";
    
    
    int secim;
     while (1)
    {
        cout<<"\n 1- Quick Sort ile Siralama";
        cout<<"\n 2- Shell Sort ile Siralama";
        cout<<"\n 3- Tree Sort ile Siralama";
	    cout<<"\n Sizin Seciminiz: "; cin>>secim;
     
       
 
        switch (secim)
        {
            case 1:
                quickSort(arr, 0, n-1);
                cout<<"Quick Sort ile Siralanmis Dizi:  "; diziyazdir(arr,n);
	            cout<<"\n\n";
                break;
          case 2:
                shell_sort(arr, n);
                cout<<"Shell Sort ile Siralanmis Dizi:  "; diziyazdir(arr,n);
	            cout<<"\n\n";
                break;
          case 3:
                treeSort(arr, n);
                cout<<" Tree Sort ile Siralanmis Dizi:  "; diziyazdir(arr,n);
	            cout<<"\n\n";
                break;
        
                
 
        }
    }
    getch(); 
    return 0;
} 
