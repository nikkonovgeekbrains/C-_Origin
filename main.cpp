#include <iostream>


/*
 * Задание 1
 * Описать макрокоманду, проверяющую, входит ли переданное ей число в диапазон от нуля (включительно)
 * до переданного ей второго аргумента (исключительно)
*/
#define FUNC1(x, y) (((x)>=0)&&((x)<(y)) ? true : false)

/*
 * Задание 2
 * Описать макрокоманду, получающую доступ к элементу двумерного массива
 * (организованного динамически) посредством разыменования указателей
*/
#define ARRAY_RAWS 3
#define ARRAY_COLUMS 3
#define GET_ARR_EL(arr,i,j) (*(*(arr + i)+j))


/*
 * Задание 3
 * * Описать макрокоманду, возвращающую количество элементов локального массива,
 * принимающую на вход ссылку на массив и его тип
*/
#define GET_ARR_LEN(arr, type) (sizeof(arr)/sizeof(type))


using namespace std;

int main()
{
    int x;
    int y;
    cout << "Input x: " << endl;
    cin >> x;
    cout << "Input y: " << endl;
    cin >> y;
    if (FUNC1(x, y)){
        cout << "x included in [0,y)" << endl;
    }
    else{
        cout << "x not included in [0,y)" << endl;
    }

    int **my_array = new int* [ARRAY_RAWS];
    for(int i = 0; i < ARRAY_RAWS; i++){
        my_array[i] = new int [ARRAY_COLUMS];
    }

    int count = 1;
    for(int i=0; i < ARRAY_RAWS; i++){
        for(int j=0; j < ARRAY_COLUMS; j++){
            my_array[i][j] = count++;
            cout << my_array[i][j] << endl;
        }
    }

    for(int i=0; i < ARRAY_RAWS; i++){
        for(int j=0; j < ARRAY_COLUMS; j++){
            cout << GET_ARR_EL(my_array, i,j) << endl;
        }
    }

    int my_arr_2 [5]{1,2,3,4,5};
    for(int i=0; i < 5; i++){
        cout << my_arr_2[i] << endl;
    }

    cout << "Len of Array = " << GET_ARR_LEN(my_arr_2, int);

    for(int i=0; i < ARRAY_RAWS; i++){
        delete[] my_array[i];
    }

    return 0;
}
