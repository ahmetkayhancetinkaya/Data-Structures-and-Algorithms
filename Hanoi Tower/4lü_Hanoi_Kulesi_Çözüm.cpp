

#include <iostream>
using namespace std; 

void hanoi(int n, char from_rod,char to_rod, char aux_rod) 
{ 
	if (n == 1) 
	{ 
		cout << "Disk Hareketi=        1 " << from_rod << " den/dan " <<  to_rod  << " ye/ya" <<endl; 
		cout<<"\n-------------------------\n\n";
		return; 
	} 
	hanoi(n - 1, from_rod, aux_rod, to_rod);
	
	 
	cout << "Disk Hareketi=        " << n <<" " <<  from_rod << " den/dan " << to_rod << " ye/ya " << endl; 
	cout<<"\n-------------------------\n\n";
	
	hanoi(n - 1, aux_rod, to_rod, from_rod); 
	
} 

 int main() 
{ 
	int n = 4; // Disk Numrasý
    hanoi(n, 'A', 'C', 'B'); //Kule Ýsimleri 
	return 0; 
} 

