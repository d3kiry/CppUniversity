#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
//#include <fstream>
 
int main()
{
    system("chcp 65001");
    //setlocale(LC_ALL,"Russian");
    char c;
    double x,y,z;
    do {
        system("cls");
        printf("Главное меню\n");
        printf("Вариант 6\n");
        printf("Последняя цифра студенческого билета: 0\n");
        printf("Ввод исходных данных (нажмите 0)\n");
        printf("Расчет A             (нажмите 1)\n");
        printf("Расчет B             (нажмите 2)\n");
        printf("Расчет C             (нажмите 3)\n");
        printf("Выход                (нажмите 4)\n");
        c = getchar();
        switch (c) {
        case '0':{
            system("cls");
            printf("Ввод исходных данных...\n");
            scanf("%lf%lf%lf",&x,&y,&z);
            system("pause");
        }break;
        case '1':{
            system("cls");
            printf("Расчет A...\n");
            double A;
            for (int x1 = -8; x1 <= 1; x1++) {
                if (pow(y, 3) >= 0 && x != 0) {
                    A = sqrt(pow(y,3)) * ((z + pow(x,2)) / x);
                    printf("x1 = %i\tA = %.3f\n",x1,A);
                } else {
                    printf("Вычисление невозможно!\n");
                }
            }
            system("pause");
        }break;
        case '2':{
            system("cls");
            printf("Расчет B...\n");
            double B;
 
            double y1 = 0;
            while(y1 >= -13.00001){
                if (z != 0 && y1 != 0){
                    B = cos((y*x)/z)+(sin(z*x)/y1);
                    printf("y1 = %f\tB = %.3f\n",y1,B);
                } else {
                    printf("Вычисление невозможно!\n");
                }
 
                y1 = y1 - 13./5;
 
            }
 
            system("pause");
        }break;
        case '3':{
            system("cls");
            printf("Расчет C...\n");
            double C;
            double z1 = 0;
            do {
                if ((x*z1) <= 1 && (x * z1) >= -1){
                    C = y * pow(asin(x*z1),2);
                printf("z1 = %f\tC = %.3f\n",z1,C);
                }
                else{
                    printf("Вычисление невозможно.\n");
                }
                z1 = z1 - 23./6;
 
            } while(z1 >= -21.00001);
            system("pause");
        }break;
        case '4':{
          printf("Выйти? y/n\n");
            c = getch();
        }break;
        }
    } while (c != 'y');
    return 0;
}