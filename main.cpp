#include <iostream>


/*
 * Р—Р°РґР°РЅРёРµ 1
 * РћРїРёСЃР°С‚СЊ РјР°РєСЂРѕРєРѕРјР°РЅРґСѓ, РїСЂРѕРІРµСЂСЏСЋС‰СѓСЋ, РІС…РѕРґРёС‚ Р»Рё РїРµСЂРµРґР°РЅРЅРѕРµ РµР№ С‡РёСЃР»Рѕ РІ РґРёР°РїР°Р·РѕРЅ РѕС‚ РЅСѓР»СЏ (РІРєР»СЋС‡РёС‚РµР»СЊРЅРѕ)
 * РґРѕ РїРµСЂРµРґР°РЅРЅРѕРіРѕ РµР№ РІС‚РѕСЂРѕРіРѕ Р°СЂРіСѓРјРµРЅС‚Р° (РёСЃРєР»СЋС‡РёС‚РµР»СЊРЅРѕ)
*/
#define FUNC1(x, y) (((x)>=0)&&((x)<(y)) ? true : false)

/*
 * Р—Р°РґР°РЅРёРµ 2
 * РћРїРёСЃР°С‚СЊ РјР°РєСЂРѕРєРѕРјР°РЅРґСѓ, РїРѕР»СѓС‡Р°СЋС‰СѓСЋ РґРѕСЃС‚СѓРї Рє СЌР»РµРјРµРЅС‚Сѓ РґРІСѓРјРµСЂРЅРѕРіРѕ РјР°СЃСЃРёРІР°
 * (РѕСЂРіР°РЅРёР·РѕРІР°РЅРЅРѕРіРѕ РґРёРЅР°РјРёС‡РµСЃРєРё) РїРѕСЃСЂРµРґСЃС‚РІРѕРј СЂР°Р·С‹РјРµРЅРѕРІР°РЅРёСЏ СѓРєР°Р·Р°С‚РµР»РµР№
*/
#define ARRAY_RAWS 3
#define ARRAY_COLUMS 3
#define GET_ARR_EL(arr,i,j) (*(*(arr + i)+j))


/*
 * Р—Р°РґР°РЅРёРµ 3
 * * РћРїРёСЃР°С‚СЊ РјР°РєСЂРѕРєРѕРјР°РЅРґСѓ, РІРѕР·РІСЂР°С‰Р°СЋС‰СѓСЋ РєРѕР»РёС‡РµСЃС‚РІРѕ СЌР»РµРјРµРЅС‚РѕРІ Р»РѕРєР°Р»СЊРЅРѕРіРѕ РјР°СЃСЃРёРІР°,
 * РїСЂРёРЅРёРјР°СЋС‰СѓСЋ РЅР° РІС…РѕРґ СЃСЃС‹Р»РєСѓ РЅР° РјР°СЃСЃРёРІ Рё РµРіРѕ С‚РёРї
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
