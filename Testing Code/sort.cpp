#include "SortLib.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <sstream>

using namespace::std;

int main() {
	string algos[] = {"Counting Sort", "Merge Sort", "Quick Sort"};
	string tests[] = {"test1.csv", "test2.csv", "test3.csv", "test5.csv", "test5.csv"};
	string outputs[] = {"results/count.csv", "results/merge.csv", "results/quick.csv"};
	int numNums[] = {100, 1000, 10000, 100000, 1000000};

	for(int i = 0; i < 1; i++){
		ofstream output = ofstream(outputs[i], std::ios_base::out|std::ios_base::trunc);
		if(!output.is_open())
			break;

		cout << "Testing " << algos[i] << endl;
		for(int j = 0; j < 5; j++){
			cout << "Array size: " << numNums[j] << endl;
			int* arr = new int[numNums[j]];

			ifstream testFile = ifstream(tests[j]);
			if(!testFile.is_open()){
				cout << "Couldn't open " << tests[j] << endl;
				break;
			}

			string line = "";
			int index = 0; 
			while(getline(testFile, line, ',') && index < numNums[j]){
				arr[index++] = stoi(line);
			}

			//run each test 30 times and get times, write to output
			for(int k = 0; k < 30; k++){
				std::clock_t start = clock();
				switch (i) {
					case 1:
						SortLib::CountingSort(arr, numNums[j]);
						break;
					case 2: 
						SortLib::MergeSort(arr, numNums[j]);
						break;
					case 3: 
						SortLib::QuickSort(arr, numNums[j]);
						break;
					default:
						break;
				}
				std::clock_t end = clock();
				long double elapsedCPU = 1000.0 * (end-start) / CLOCKS_PER_SEC;
				output << elapsedCPU << ","; 
				cout << algos[i] << " File:" << (j+1) << " Test:" << k << " completed. " << elapsedCPU << endl;
			}
			output << endl;
			delete[] arr;

		}
		cout << endl << endl;
		output.close();
	}
	return 0;  
}