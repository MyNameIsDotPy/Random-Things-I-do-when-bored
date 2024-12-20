//
// Created by Angel on 14/12/24.
//

#include "point7.h"
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>


// Utils

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Point 7a

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0...i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Point 7e

void insertionSortUltra(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        insertionSort(arr, i);
    }
}

// Point 7g

// Función para fusionar dos sub-arrays ordenados
void merge1(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamaño del subarray izquierdo
    int n2 = right - mid;    // Tamaño del subarray derecho

    // Crear arreglos temporales
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Fusionar los subarrays en el arreglo original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes del subarray izquierdo, si los hay
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes del subarray derecho, si los hay
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Liberar memoria dinámica
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort1(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar la primera y la segunda mitad
        mergeSort1(arr, left, mid);
        mergeSort1(arr, mid + 1, right);

        // Fusionar las dos mitades
        merge1(arr, left, mid, right);
    }
}
// Final punto 7g

// Punto 7i

// Función para fusionar las tres partes
void merge2(int arr[], int left, int mid1, int mid2, int right) {
    int n1 = mid1 - left + 1;
    int n2 = mid2 - mid1;
    int n3 = right - mid2;

    // Crear arreglos temporales
    int* leftArr = new int[n1];
    int* midArr = new int[n2];
    int* rightArr = new int[n3];

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) midArr[i] = arr[mid1 + 1 + i];
    for (int i = 0; i < n3; i++) rightArr[i] = arr[mid2 + 1 + i];

    // Fusionar los arreglos
    int i = 0, j = 0, k = 0, idx = left;
    while (i < n1 && j < n2 && k < n3) {
        if (leftArr[i] <= midArr[j] && leftArr[i] <= rightArr[k]) {
            arr[idx++] = leftArr[i++];
        } else if (midArr[j] <= leftArr[i] && midArr[j] <= rightArr[k]) {
            arr[idx++] = midArr[j++];
        } else {
            arr[idx++] = rightArr[k++];
        }
    }

    // Manejar elementos restantes
    while (i < n1) arr[idx++] = leftArr[i++];
    while (j < n2) arr[idx++] = midArr[j++];
    while (k < n3) arr[idx++] = rightArr[k++];

    // Liberar memoria
    delete[] leftArr;
    delete[] midArr;
    delete[] rightArr;
}

// Función principal de MergeSort2
void mergeSort2(int arr[], int left, int right) {
    if (left < right) {
        int mid1 = left + (right - left) / 4;
        int mid2 = left + (right - left) / 2;

        // Ordenar las tres partes
        mergeSort2(arr, left, mid1);
        mergeSort2(arr, mid1 + 1, mid2);
        mergeSort2(arr, mid2 + 1, right);

        // Fusionar las tres partes
        merge2(arr, left, mid1, mid2, right);
    }
}
// Final punto 7i





void point7g() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original:\n";
    printArray(arr, size);

    mergeSort1(arr, 0, size - 1);

    std::cout << "Array ordenado:\n";
    printArray(arr, size);
}

void point7b() {
    int min = 1, max = 500;
    int n = 1;
    std::ofstream outputFile("./outputB.txt");
    auto inicioBatch = std::chrono::high_resolution_clock::now();
    while (true) {
        double tiempoBatch = 0;
        for (int experimento = 0; experimento < 100; ++experimento) {
            int arr[n];
            generarNumerosAleatorios(arr, n, min, max);

            // Medir tiempo de ejecución antes y después del sort
            auto inicio = std::chrono::high_resolution_clock::now();
            insertionSort(arr, n);
            auto fin = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double, std::milli> duracion = fin - inicio;
            double time = duracion.count();
            tiempoBatch += time;
        }

        double media = tiempoBatch / 100;

        if (outputFile.is_open()) {
            // Write to the file
            outputFile << media << std::endl;
            // Close the file when done
            // std::cout << "Data saved to output.txt\n";
        } else {
            // If the file couldn't be opened
            std::cerr << "Unable to open file\n";
        }

        auto finBatch = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duracion = finBatch - inicioBatch;
        double time = duracion.count();

        if (time > 5*60*1000) {
            std::cout<<time<<std::endl;
            break;
        }
        n++;
    }
    outputFile.close();
}

void point7f() {
    int min = 1, max = 500;
    int n = 1;
    std::ofstream outputFile("./outputF.txt");
    auto inicioBatch = std::chrono::high_resolution_clock::now();
    while (true) {
        double tiempoBatch = 0;
        for (int experimento = 0; experimento < 100; ++experimento) {
            int arr[n];
            generarNumerosAleatorios(arr, n, min, max);

            // Medir tiempo de ejecución antes y después del sort
            auto inicio = std::chrono::high_resolution_clock::now();
            insertionSortUltra(arr, n);
            auto fin = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double, std::milli> duracion = fin - inicio;
            double time = duracion.count();
            tiempoBatch += time;
        }

        double media = tiempoBatch / 100;

        if (outputFile.is_open()) {
            // Write to the file
            outputFile << media << std::endl;
            // Close the file when done
            // std::cout << "Data saved to output.txt\n";
        } else {
            // If the file couldn't be opened
            std::cerr << "Unable to open file\n";
        }

        auto finBatch = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duracion = finBatch - inicioBatch;
        double time = duracion.count();

        if (time > 5*60*1000) {
            std::cout<<time<<std::endl;
            break;
        }
        n++;
    }
    outputFile.close();
}

void point7h() {
    int min = 1, max = 500;
    int n = 1;
    std::ofstream outputFile("./outputH.txt");
    auto inicioBatch = std::chrono::high_resolution_clock::now();
    while (true) {
        double tiempoBatch = 0;
        for (int experimento = 0; experimento < 100; ++experimento) {
            int arr[n];
            generarNumerosAleatorios(arr, n, min, max);

            // Medir tiempo de ejecución antes y después del sort
            auto inicio = std::chrono::high_resolution_clock::now();
            mergeSort1(arr, 0, n-1);
            auto fin = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double, std::milli> duracion = fin - inicio;
            double time = duracion.count();
            tiempoBatch += time;
        }

        double media = tiempoBatch / 100;

        if (outputFile.is_open()) {
            // Write to the file
            outputFile << media << std::endl;
            // Close the file when done
            // std::cout << "Data saved to output.txt\n";
        } else {
            // If the file couldn't be opened
            std::cerr << "Unable to open file\n";
        }

        auto finBatch = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duracion = finBatch - inicioBatch;
        double time = duracion.count();

        if (time > 5*60*1000) {
            std::cout<<time<<std::endl;
            break;
        }
        n++;
    }
    outputFile.close();
}

void point7j() {
    int min = 1, max = 500;
    int n = 1;
    std::ofstream outputFile("./outputJ.txt");
    auto inicioBatch = std::chrono::high_resolution_clock::now();
    while (true) {
        double tiempoBatch = 0;
        for (int experimento = 0; experimento < 100; ++experimento) {
            int arr[n];
            generarNumerosAleatorios(arr, n, min, max);

            // Medir tiempo de ejecución antes y después del sort
            auto inicio = std::chrono::high_resolution_clock::now();
            mergeSort2(arr, 0, n-1);
            auto fin = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double, std::milli> duracion = fin - inicio;
            double time = duracion.count();
            tiempoBatch += time;
        }

        double media = tiempoBatch / 100;

        if (outputFile.is_open()) {
            // Write to the file
            outputFile << media << std::endl;
            // Close the file when done
            // std::cout << "Data saved to output.txt\n";
        } else {
            // If the file couldn't be opened
            std::cerr << "Unable to open file\n";
        }

        auto finBatch = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duracion = finBatch - inicioBatch;
        double time = duracion.count();

        if (time > 5*60*1000) {
            std::cout<<time<<std::endl;
            break;
        }
        n++;
    }
    outputFile.close();
}

void generarNumerosAleatorios(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}