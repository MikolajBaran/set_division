#include <iostream>
#include <fstream>

using namespace std;

int n;
fstream plik;

void wyswietl(int* t, bool f) {
	if(f == false){
		plik.open("podzialy.txt", ios::out|ios::app);
	}
	else{
		plik.open("podzialy.txt", ios::out);
	}
	for (int i = 0; i < n; i++) {
		cout << t[i] << " ";
		plik << t[i] << " ";
	}
	cout << endl;
	plik << endl;
	plik.close();
}

void generuj() {
	int* tab = new int[n];
	for (int i = 0; i < n; i++) {
		tab[i] = 1;
	}
	
	bool first = true;
	
	int max = 0;	
	do{
		wyswietl(tab, first);
		first = false;
		tab[n-1]++;
		int index=1;
		while(n-1-index>=0){
			max = 0;
            for(int j = 0; j < n-index ; j++ ){
	            if( tab[j] > max ){
	                max = tab[j];
	            }
            }
            if( tab[n-index] == max+2 || tab[n-index] == n+1 ){
                tab[n-1-index]++;
                tab[n-index] = 1;
                index++;
            } else break;
		}
	}while(tab[0] == 1);
	cout << "\nWyniki generacji podzialow zostaly zapisane w pliku podzialy.txt" << endl;
}

int main() {
	cout << "Program do generowania podzialow zbioru n-elementowego." << endl;
	cout << "Wprowadz liczbe elementow zbioru: ";
	cin >> n;
	while(!n || n<1){
		cout << "Wprowadzono niepoprawne dane. Sprobuj ponownie." << endl;
		cout << "Wprowadz liczbe elementow zbioru: ";
		cin >> n;
	}
	cout << "Generuje podzialy..." << endl;
	generuj();

	return 0;
}
