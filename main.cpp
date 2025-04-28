#include <chrono>
#include <numeric> 
#include <cmath>
#include <iostream>
#include <sstream>
#include "SortingAlgorithm.hpp"

using namespace std;


int main(int argc, char *argv[])
{
    size_t m=10;
	
	// vettore ordinato di interi compresi tra -3 e 3
	vector<int> v1(m);
	iota(v1.begin(), v1.end(),-3);
	
	// vettore randomico di double compresi tra 0 e 1
	vector<double> v2(m);
	for (unsigned int i=0; i<m; i++)
		v2[i]=rand()/((double)RAND_MAX);
	
	// vettore di interni: primi floor(m*0.5)+ elemento copiato dal vettore v1 (ordinati), quelli dopo sono numeri randomici tra 0 e 99
	vector<int> v3(m,0);
	copy(v1.begin(), v1.begin()+floor(m*0.5)+1, v3.begin());
	for (unsigned int i=floor(m*0.5)+1; i<m; i++)
		v3[i]=rand()%100;
	
	unsigned int num_experiment=100;
	
	double time_elapsed_dubble_v1=0.0;
	for(unsigned int t=0; t<num_experiment; t++)
	{
		vector<int> v(v1);
		std::chrono::steady_clock::time_point start_time=std::chrono::steady_clock::now();
		SortLibrary::BubbleSort<int>(v);
		std::chrono::steady_clock::time_point end_time=std::chrono::steady_clock::now();
		time_elapsed_dubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
	}
	time_elapsed_dubble_v1 /=num_experiment;
	
	cout<<"Bubble Sort -v1: "<<time_elapsed_dubble_v1<<endl;
	
	double time_elapsed_heap_v1=0.0;
	for (unsigned int t=0; t<num_experiment; t++)
	{
		vector<int> v(v1);
		std::chrono::steady_clock::time_point start_time=std::chrono::steady_clock::now();
		SortLibrary::HeapSort<int>(v);
		std::chrono::steady_clock::time_point end_time=std::chrono::steady_clock::now();
		time_elapsed_heap_v1 +=std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
	}
	time_elapsed_heap_v1 /= num_experiment;
    
	cout << "Heap Sort - v1: " << time_elapsed_heap_v1 << endl;
	
	double time_elapsed_bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);
		std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v2 /= num_experiment;

    cout << "Bubble Sort - v2: " << time_elapsed_bubble_v2 << endl;
	
	double time_elapsed_heap_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);
		std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v2 /= num_experiment;

    cout << "Heap Sort - v2: " << time_elapsed_heap_v2 << endl;
	
	double time_elapsed_bubble_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v3 /= num_experiment;

    cout << "Bubble Sort - v3: " << time_elapsed_bubble_v3 << endl;
	
	double time_elapsed_heap_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);
		std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v3 /= num_experiment;

    cout << "Heap Sort - v3: " << time_elapsed_heap_v3 << endl;
	
	return 0;
}

