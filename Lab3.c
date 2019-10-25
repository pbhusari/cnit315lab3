#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Taken from: https://www.geeksforgeeks.org/binary-search/
int binarySearch(int *array, int l, int r, int query) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 

        if (array[mid] == query) {

            return mid; 

	}

        if (array[mid] > query)  {

            return binarySearch(array, l, mid - 1, query); 
	
	}
        return binarySearch(array, mid + 1, r, query); 
    } 
  

    return -1; 
} 
  

int linearSearch(int *array, int n, int query) {
	int i;

	for (i=0; i<n; i++) {
		if (array[i] == query) {
			return i;
		} 
	}

	return -1;
}

int randomElement(int n) {
	srand (time(NULL)); 
	
	return rand() % n;
}

// Taken from: https://www.geeksforgeeks.org/bubble-sort/
void bubbleSort(int *array, int n) {
	int i;
	int j;

	for (i=0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}


//Taken from: https://www.geeksforgeeks.org/selection-sort/
void selectionSort(int *array, int n) {
	int i;
	int j;
	int minIndex;

	for (i=0; i < n-1; i++) 
	{
	
		minIndex = i;

		// Finds the minimum of the unsorted portion
		for (j = i +1; j < n; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}

		swap(&array[minIndex], &array[i]); 
	
	
	}
}

//Taken from: https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(int *array, int n) {
	int i;
	int key;
	int j;

	for (i=1;i<n;i++) {

		key = array[i];

		j = i - 1;

		while (j>=0 && array[j] > key) {
			
			array[j + 1] = array[j];
			j = j - 1;
		
		}

		array[j + 1] = key;

	}
}

// Shuffles an array given an array and its length
// Taken From: https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
void shuffleArray(int *array, size_t n)
{
	
	//Deterministic if not reseeded
	srand (time(NULL)); 

	int i;	

	for(i = n-1; i >0; i--) {

		int j = rand() % (i+1);
		swap(&array[i], &array[j]);
		
	}
}

// Creates a sequential array n in length
void createArray(int *array, int n) {

	int i;

	for (i=0; i < n; ++i) {
		array[i] = i;
	}

	
}

void printArray(int *array, int n) {

	int i = 0;
	for (i=0; i < n; i++) {
		printf("%d\n", array[i]);
	}
	printf("\n");

}

// "((float)t)/CLOCKS_PER_SEC" taken from: http://www.cplusplus.com/reference/ctime/clock/
void evaluate(int n) {

	int testArray[n];
	int searchQuery;
 	clock_t begin, end;

	printf("%d,", n);

	// Array Creation
	
	begin = clock();
	createArray(testArray, n);
	end = clock();
	printf("%Lf,", (long double)(end - begin)/CLOCKS_PER_SEC);

	// Array Shuffling
	
	begin = clock();
	shuffleArray(testArray, n);
	end = clock();
	printf("%Lf,", (long double)(end - begin)/CLOCKS_PER_SEC);

	// Bubble Sort
	
	begin = clock();
	bubbleSort(testArray,n);
	end = clock();
	printf("%Lf,", (long double)(end - begin)/CLOCKS_PER_SEC);
	shuffleArray(testArray, n);

	// Selection Sort
	
	begin = clock();
	selectionSort(testArray,n);
	end = clock();
	printf("%Lf,", (long double)(end - begin)/CLOCKS_PER_SEC);
	shuffleArray(testArray, n);

	// Insertion Sort
	
	begin = clock();
	insertionSort(testArray,n);
	end = clock();
	printf("%Lf,", (long double)(end - begin)/CLOCKS_PER_SEC);

	// Linear Search
	searchQuery = randomElement(n);
	begin = clock();
	int linearResult = linearSearch(testArray, n, searchQuery);
	end = clock();
	printf("%Lf,", (long double)(end - begin)/CLOCKS_PER_SEC);

	
	// Binary Search
	insertionSort(testArray,n);
	begin = clock();
	int binaryResult = binarySearch(testArray, 0, n - 1, searchQuery);
	end = clock();
	printf("%Lf", (long double)(end - begin)/CLOCKS_PER_SEC);
	
	printf("\n");

}


int main () {

	int evaluationLengths[9] = {50, 100, 500, 1000, 5000,10000, 25000, 50000};
	int i;

	printf("elements,array creation,array shuffling,bubble sort,selection sort,insertion sort,linear search,binary search\n");
	
	for (i=0; i<9; i++) {
		evaluate(evaluationLengths[i]);
	}

}
