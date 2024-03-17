#include <iostream>

class BubbleSort {
public:
    // Fonction membre pour trier un tableau en utilisant le tri à bulles.
    static void sort(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                // Compare deux éléments adjacents et les échange si nécessaire.
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Tableau non trié : ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Appel de la fonction de tri à bulles
    BubbleSort::sort(arr, size);

    std::cout << "Tableau trié : ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


