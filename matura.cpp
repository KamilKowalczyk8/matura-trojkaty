#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 500;
int tab[SIZE];

bool saDlugosciamiTrojkataProstokatnego(int a, int b, int c) {
	return (a * a + b * b == c * c ||
			a * a + c * c == b * b ||
			c * a + c * b == a * a);
}

void wyswietl(int a, int b, int c) {
	cout << a <<endl; 
	cout << b <<endl;
	cout << c <<endl;
}

bool saTrojkatem(int a, int b, int c) {
	return (a + b > c && a + c > b && b + c > a);
}

void z1() {
	cout << "zadanie 1 ---------------" << endl;
	for (int i = 0; i < SIZE - 2; i++) {
		if (saDlugosciamiTrojkataProstokatnego(tab[i], tab[i+1], tab[i+2])) {
			wyswietl(tab[i], tab[i+1], tab[i+2]);
		}
	}
	cout << endl;
}

void z2() {
	cout << "zadanie 1 ---------------" << endl;
	int max = 0;
	for (int i = 0; i < SIZE - 2; i++) {
		for (int j = i + 1; j < SIZE - 1; j++) {
			for (int k = j + 1; k < SIZE; k++) {
				if (saTrojkatem(tab[i], tab[j], tab[k])) {
					int obwod = tab[i] + tab[j] + tab[k];
					if (obwod > max) max = obwod;
				}
			}
		}
	}
	cout << max << endl << endl;
}


void z3() {
	cout << "zadanie 3 ---------------" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE - 2; i++) {
		for (int j = i + 1; j < SIZE - 1; j++) {
			for (int k = j + 1; k < SIZE; k++) {
				if (saTrojkatem(tab[i], tab[j], tab[k])) counter++;
			}
		}
	}
	cout << counter << endl << endl;
}

int main() {
	ifstream plik("dane.txt");
	for (int i = 0; i < SIZE; i++) {
		plik >> tab [i];
	}
	plik.close();
	
	z1();
	z2();
	z3();
}
