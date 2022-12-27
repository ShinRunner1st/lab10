#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loan, rpy, ppy;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> rpy;
	cout << "Enter amount you can pay per year: ";
	cin >> ppy;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	double pb, inter, total, nb;
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect

	pb = loan;
	total = pb*(rpy/100);
	nb = pb + total - ppy;

	cout << fixed << setprecision(2);
	cout << setw(13) << left << 1;
	cout << setw(13) << left << pb;
	inter = pb*(rpy/100);
	cout << setw(13) << left << inter;
	total = pb + inter;
	cout << setw(13) << left << total;
	if(total < ppy)
	{
		cout << setw(13) << left << total;
		ppy = total;
	}
	else cout << setw(13) << left << ppy;
	nb = total - ppy;
	cout << setw(13) << left << nb;
	cout << "\n";

	for(int i; nb > 0; i++)  //อย่าถามว่าทำไมไม่เขียน do while คือขี้เกี้ยจแก้โอเคนะ
	{
		if(i == 0)
		{
			continue;
		}
		else
		{
			cout << fixed << setprecision(2); 
			cout << setw(13) << left << i + 1; 
			pb = nb;
			cout << setw(13) << left << pb;
			inter = nb*(rpy/100);
			cout << setw(13) << left << inter;
			total = pb + inter;
			cout << setw(13) << left << total;
			if(total < ppy)
			{
				ppy = total;
				cout << setw(13) << left << ppy;
			}
			else cout << setw(13) << left << ppy;
			nb = total - ppy;
			cout << setw(13) << left << nb;
			cout << "\n";
		}
	}
	
	return 0;
}
