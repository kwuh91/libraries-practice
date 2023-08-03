#include <iostream>
#include <random>
#include <vector>
#include "Header.h"
#include "Dll.h"

int main() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(-25, 100);
	int choice;
	bool sorted = false;
	std::vector<double> sorted_arr;
	std::vector<double> v_arr;
	int arr_size;
	arr_size = ((int)(abs(floor(dist(mt)))) % 20) + 10;
	double* arr = new double[arr_size];
	double* t_arr = new double[arr_size];
	std::cout << "Enter:\n 1 - Generate an array\n 2 - Sort an array\n 3 - Display\n 4 - exit\n";
	while (true) {
		std::cin >> choice;
		switch (choice) {
		case 1: {
			bool flag = true;
			if (!v_arr.empty()) {
				flag = false;
			}
			for (size_t i = 0; i < arr_size; ++i) {
				v_arr.push_back(dist(mt));
			}
			if (flag) {
				std::cout << "An array of size " << arr_size << " has been successfully generated\n";
			}
			else {
				std::cout << "You have already generated an array\n";
			}

			break;
		}
		case 2: {
			sorted = true;
			for (auto i : v_arr) {
				sorted_arr.push_back(i);
			}
			for (size_t i = 0; i < arr_size; ++i) {
				arr[i] = t_arr[i] = sorted_arr[i];
			}
			int library_choice;
			std::cout << "Which library would you like to use?:\n 1 - static\n 2 - dynamic\n";
			bool flag_l_c = true;
			while (flag_l_c) {
				std::cin >> library_choice;
				switch (library_choice) {
				case 1: {
					Sorting::Merge_Sort::mergesort(arr, t_arr, 0, (int)v_arr.size() - 1);
					flag_l_c = false;
					break;
				}
				case 2: {
					mergesortDLL(arr, t_arr, 0, (int)v_arr.size() - 1);
					flag_l_c = false;
					break;
				}
				default: {
					std::cout << "Invalid option\n";
					break;
				}
				}
			}
			std::cout << "Your array has been successfully sorted\n";
			break;
		}
		case 3: {
			if (v_arr.empty()) {
				std::cout << "Your array is empty\n";
				break;
			}
			else {
				std::cout << "Your initial array:\n";
				for (auto i : v_arr) {
					printf("[%lf] ", i);
				}
				std::cout << std::endl;
				if (sorted) {
					std::cout << "Your sorted array:\n";
					for (size_t i = 0; i < v_arr.size(); ++i) {
						printf("[%lf] ", arr[i]);
					}
					std::cout << std::endl;
				}
			}
			break;
		}
		case 4: {
			delete[] arr;
			delete[] t_arr;
			exit(0);
			break;
		}
		default: {
			std::cout << "Invalid option\n";
			break;
		}
		}
	}
}
