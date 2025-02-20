
void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}
void vypisPole(int pole[], int vel){
	for(int i = 0; i < vel; i++){
		printf("%d ", pole[i]);
	}
	printf("\n");
}

void vypis2DPole(int ** pole, int pocRadku, int pocSloupcu){
	for(int r=0; r < pocRadku; r++){

		for (int s = 0; s < pocSloupcu; ++s)
		{
			printf("%d ", pole[r][s]);
		}

		printf("\n");

	}
}