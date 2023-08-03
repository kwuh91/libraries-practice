#include "Header.h"

namespace Sorting {
	void Merge_Sort::Merge(double arr[], double aux[], int low, int mid, int high) {
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
	void Merge_Sort::mergesort(double arr[], double aux[], int low, int high) {
		{
			if (high == low) {
				return;
			}

			int mid = (low + ((high - low) >> 1));

			mergesort(arr, aux, low, mid);
			mergesort(arr, aux, mid + 1, high);

			Merge(arr, aux, low, mid, high);
		}
	}
}
