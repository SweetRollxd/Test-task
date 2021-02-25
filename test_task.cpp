#include <iostream>
#include <random>
#include <time.h>

//функция быстрой сортировки, параметр order отвечает за порядок сортировки, 1 - по возрастанию, 0 - по убыванию
void quicksort(int *array, int left, int right, bool order){
    int l = left, r = right;
    int mid = array[(r + l) / 2];
    while(l < r){
        if (order){
            while(array[l] < mid) l++;
            while(array[r] > mid) r--;

            if (array[l] >= array[r] && (l <= r)){
               int tmp = array[l];
               array[l] = array[r];
               array[r] = tmp;
               l++; r--;
            }
        }
        else {
            while(array[l] > mid) l++;
            while(array[r] < mid) r--;

            if (array[l] <= array[r] && (l <= r)){
               int tmp = array[l];
               array[l] = array[r];
               array[r] = tmp;
               l++; r--;
            }
        }
    }
    if (left < r) quicksort(array, left, r, order);
    if (l < right) quicksort(array, l, right, order);
}


int** foo(int n){

    int **main_array = new int* [n]; // указатель на массив, содержащий в себе n массивов

    /* Сгенерируем случайный размер массивов внутри главного массива
     * Чтобы размеры в качестве размеров возьмём числа из ряда последовательных перемешанных чисел
     */
    int max_array_size = 20; //максимальный размер массива
    if(max_array_size < n) return 0; //ошибка, если количество массивов больше допустимого количества размеров массивов
    int *sizes_array = new int[max_array_size];
    // заполняем массив последовательностью чисел
    for(int i = 0; i < max_array_size; ++i){
        sizes_array[i] = i + 1;
    }
    //перемешиваем их случайном порядке
    for(int i = 0; i < max_array_size; ++i){
        int j = rand() % (i + 1);
        sizes_array[i] = sizes_array[j];
        sizes_array[j] = i + 1;
    }

    //заполняем главный массив
    int *array;
    for(int i = 0; i < n; ++i){
        array  = new int[sizes_array[i]];
        for(int j = 0; j < sizes_array[i]; ++j){
            array[j] = rand() % 100;
        }
        main_array[i] = array;
    }

    //сортировка внутренних массивов по возрастанию и убыванию в зависмости от чётности индекса
    for(int i = 0; i < n; ++i){
        if ((i + 1) % 2 == 0) quicksort(main_array[i], 0, sizes_array[i] - 1, 1);
        else quicksort(main_array[i], 0, sizes_array[i] - 1, 0);
    }

    delete[] sizes_array;
    return main_array;
}



int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n;
    std::cin >> n;
    foo(n);

    return 0;
}

