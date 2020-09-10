#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>

using namespace std;

template <class T>
class Sorts{
    private:
       void swap(vector<T>&,int,int);
	   void copyArray(vector<T>&, vector<T>&, int, int);
	   void mergeArray(vector<T>&, vector<T>&, int, int, int);
	   void mergeSplit(vector<T>&, vector<T>&, int, int);
		
    public:
       void ordenaSeleccion(vector<T>&);
	   void ordenaBurbuja(vector<T>&);
       void ordenaMerge(vector<T>&);
       T busqSecuencial(vector<T>&, int);
       T busqBinaria(vector<T>&, int);
};

template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j) {
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

//Seleccion

template <class T>
void Sorts<T>::ordenaSeleccion(vector<T> &v){
    int pos;

	for (int i = v.size() - 1; i > 0; i--) {
		pos = 0;
		for (int j = 1; j <= i; j++) {
			if (v[j] > v[pos]) {
				pos = j;
			}
		}

		if (pos != i) {
			swap(v, i, pos);
		}
	}
}


//Burbuja

template <class T>
void Sorts<T>::ordenaBurbuja(vector<T> &v){
	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
}

//Merge

template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T> &v){
	vector<T> tmp(v.size());
	
	mergeSplit(v, tmp, 0, v.size() - 1);
}

//Busqueda secuencial

template <class T> 
T Sorts<T>::busqSecuencial(vector<T> &v, int n){
	for(int i=0; i < v.size(); i++){
		if(v[i]==n){
			return i;
		}
	}
	return -1;
}

//Busqueda binaria

template <class T>
T Sorts<T>::busqBinaria(vector<T> &v, int n){
	int central, min, max;
	min = 0;
	max = v.size() - 1;
	
	while(min < max){
		central = (min + max)/2;
		if(n == v[central]){
			return central;
		}
		else if(n < v[central]){
			max = central - 1;
		}
		else{
			min = central + 1;
		}
	}
	return min;
}


#endif /* SORTS_H_ */
