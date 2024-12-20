#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;
//void input(float &x, float &y, float &zn, float &s, int &num) {
//    cout << "Введите значения переменных:\n";
//    cout << "x: "; cin >> x;
//    cout << "y: "; cin >> y;
//    cout << "zn (начальное значение z): "; cin >> zn;
//    cout << "s (шаг изменения z): "; cin >> s;
//    cout << "num (количество вычисляемых значений): "; cin >> num;
//}
void print(float* M, int N) {
    cout << "---------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << i + 1 << " - " << M[i] << endl;
    }
}
float FunctionA(float x, float y, float z) {
    if (x == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
    }
    return sqrt(pow(y, 3)) * ((z + pow(x, 2)) / x);
}
float FunctionB(float x, float y, float z) {
    if (z == 0 || y == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
    }
    return cos(y * x / z) + (sin(z * x) / y);
}
float FunctionC(float x, float y, float z) {
    if (x * z < -1 || x * z > 1) {
        cout << "Ошибка: значение arcsin вне допустимого диапазона!" << endl;
    }
    return y * pow(asin(x * z), 2);
}
int calcA(float* &A, float x, float y, float zn, float s, int num) {
    int N = 0;
    cout << "---------------------------------------------------" << endl;
    cout << "Рассчитываем выражение A:" << endl;
    for (int i = 0; i < num; i++) {
        float z = zn + i * s;
        float result = FunctionA(x, y, z);
        if (result == result && result > -FLT_MAX && result < FLT_MAX) {
            float* temp = new float[N + 1];
            for (int j = 0; j < N; j++) {
                temp[j] = A[j];
            }
            temp[N] = result;
            delete[] A;
            A = temp;
            N++;
        } else {
            cout << "x= " << x << " z= " << z << " - Некорректный результат" << endl;
        }
    }
    return N;
}
int calcB(float* &B, float x, float y, float zn, float s, int num) {
    int N = 0;
    cout << "---------------------------------------------------" << endl;
    cout << "Рассчитываем выражение B:" << endl;
    //for (int i = 0; i < num; i++) 
    int i = 0;
    while(i < num){
        float z = zn + i * s;
        float result = FunctionB(x, y, z);
        if (result == result && result > -FLT_MAX && result < FLT_MAX) {
            float* temp = new float[N + 1];
            for (int j = 0; j < N; j++) {
                temp[j] = B[j];
            }
            temp[N] = result;
            delete[] B;
            B = temp;
            N++;
        } else {
            cout << "x= " << x << " z= " << z << " - Некорректный результат" << endl;
        }
        i++;
    }
    return N;
}
int calcC(float* &C, float x, float y, float zn, float s, int num) {
    int N = 0;
    cout << "---------------------------------------------------" << endl;
    cout << "Рассчитываем выражение C:" << endl;
    //for (int i = 0; i < num; i++) 
    int i = 0;
    do{
        float z = zn + i * s;
        float result = FunctionC(x, y, z);
        if (result == result && result > -FLT_MAX && result < FLT_MAX) {
            float* temp = new float[N + 1];
            for (int j = 0; j < N; j++) {
                temp[j] = C[j];
            }
            temp[N] = result;
            delete[] C;
            C = temp;
            N++;
        } else {
            cout << "x= " << x << " z= " << z << " - Некорректный результат" << endl;
        }
        i++;
    }while(i < num);
    return N;
}
int main() {
    char c;
    float x = 0.8, y = 0.31, zn = -0.5, s = 0.2;
    int num = 5;
    do {
        cout << "Labwork 3 Variant 6 | Borisov Vadim | BBSO - 01 - 24" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Нынешнии значения:" << " x = " << x << " y = " << y << " zn = " << zn << " s = " << s << " num = " << num << endl;
        cout << "---------------------------------------------------" << endl;
        //cout << "Ввод значений\t\t(press 0)" << endl;
        cout << "Рассчитать функцию A\t(press 1)" << endl;
        cout << "Рассчитать функцию B\t(press 2)" << endl;
        cout << "Рассчитать функцию C\t(press 3)" << endl;
        cout << "Закрыть программу\t(press 4)" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Выбор: " << endl;
        cin >> c;
        switch (c) {
            //case '0': {
            //    input(x, y, zn, s, num);
            //} break;
            case '1': {
                float* A = new float[0];
                int NA = calcA(A, x, y, zn, s, num);
                print(A, NA);
                delete[] A;
            } break;
            case '2': {
                float* B = new float[0];
                int NB = calcB(B, x, y, zn, s, num);
                print(B, NB);
                delete[] B;
            } break;
            case '3': {
                float* C = new float[0];
                int NC = calcC(C, x, y, zn, s, num);
                print(C, NC);
                delete[] C;
            } break;
            case '4': {
                cout << "Выход из программы." << endl;
            } break;
        }
    } while (c != '4');

    return 0;
}