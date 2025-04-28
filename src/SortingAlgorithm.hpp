#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary 
{
	// funzione per Bubble Sort
	template<typename T>
	void BubbleSort(std::vector<T>& v)
	{
		const unsigned int n = v.size();
		//Scorro la lista fino alla fine
		for(unsigned int i = 0; i < n - 1; i++)
		{
			//Confronto gli elementi vicini
			for(unsigned int j = 0; j < n - 1 - i; j++)
			{
				//Se l'elemento j-esimo è più grande del suo successivo 
				if(v[j] > v[j + 1])
				{
					//Scambio i due elementi
					T tmp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = tmp;
				}
			}
			
		}
	}



// Funzione che costruisce un max-heap: albero in cui ogni genitore è più grande dei suoi figli
template<typename T>
void Heapify(vector<T>& v, unsigned int n, unsigned int i)
{
	unsigned int maggiore = i; //Indice nodo corrente: assumo sia il maggiore
	unsigned int figlio_sx = 2 * i + 1; //Indice figlio sinistro
	unsigned int figlio_dx = 2 * i + 2; //Indice figlio destro
	
	//Se il figlio sinistro sta nel vettore ed è maggiore del nodo assunto più grande --> il figlio sinistro diventa il più grande
	if(figlio_sx < n && v[figlio_sx] > v[maggiore]) 
		maggiore = figlio_sx;
		
	//Se il figlio destro sta nel vettore ed è maggiore del nodo assunto più grande --> il figlio destro diventa il più grande
	if(figlio_dx < n && v[figlio_dx] > v[maggiore]) 
		maggiore = figlio_dx;
	
	//Se il nodo maggiore non è il nodo i --> scambio e si rifà l'Heapify
	if(maggiore != i){
		swap(v[i], v[maggiore]);
		Heapify(v, n, maggiore);
	}
}

///Funzione per l'Heap Sort
template<typename T>
void HeapSort(vector<T>& v)
{
	const int n = v.size();
	//Costruisco il max-heap usando la funzione che ho appena creato, partendo dal fondo, dal primo nodo non foglia
	for(int i = n / 2 - 1; i >= 0; i--)
        Heapify(v, n, i);
	
	//Scambio la radice con l’ultimo elemento dell’heap, poi rimuovo quell’elemento e riapplico la Heapify al vettore 
	for(int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);
        Heapify(v, i, 0);
	}
}

// Funzione per Selectio Sort
template<typename T>
void SelectionSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
    for (unsigned int i = 0; i < n - 1; ++i)
    {
        unsigned int min_index = i;
        for (unsigned int j = i + 1; j < n; ++j)
        {
            if (v[j] < v[min_index])
                min_index = j;
        }
        if (min_index != i)
            swap(v[i], v[min_index]);
    }
}

// Funzione per Insertion Sort
template<typename T>
void InsertionSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
    for (unsigned int i = 1; i < n; ++i)
    {
        T key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = key;
    }
}
}


