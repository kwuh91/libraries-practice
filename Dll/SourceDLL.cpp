#include "pch.h" 
#include <vector>
#include "Dll.h"              

void MergeDLL(double arr[], double aux[], int low, int mid, int high) {
	int k = low, i = low, j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j]) {
			aux[k++] = arr[i++];
		}
		else {
			aux[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		aux[k++] = arr[i++];
	}

	for (int i = low; i <= high; i++) {
		arr[i] = aux[i];
	}
}
void mergesortDLL(double arr[], double aux[], int low, int high) {
	{
		if (high == low) {
			return;
		}

		int mid = (low + ((high - low) >> 1));

		mergesortDLL(arr, aux, low, mid);
		mergesortDLL(arr, aux, mid + 1, high);

		MergeDLL(arr, aux, low, mid, high);
	}
}
