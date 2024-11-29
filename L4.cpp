#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cmath>
using namespace std;
void print(vector<float> V, ofstream &outFile){
    for(int i = 0; i < V.size(); i++){
        cout << i << " - " << V[i] << endl;
        outFile << i << " - " << V[i] << endl;
    }
}
void write(string &fileName, vector<float> &V) {
    ofstream outFile(fileName, ios::out); 
    for (int i = 0; i < V.size(); i++) {
        outFile << i << " - " << V[i] << endl;
    }
    outFile.close();
}
void read(string fileName, vector<float> &V){
    ifstream F(fileName, ios_base::binary);
    float x;
    V.clear();
    while(true){
        F.read((char*)&x, sizeof(int));
        if (F.eof()) break;
        V.push_back(x);
    }
    F.close();
}
void findmaxelem(vector<float>V, ofstream &outFile){
    float max = V[0];
    int indexmax = 0;
    for(int i = 0; i < V.size(); i++){
        if (V[i] > max){
            max = V[i];
            indexmax = i;
        }
    }
    cout << "Max element - " << max << " at index " << indexmax << endl;
    outFile << "Max element - " << max << " at index " << indexmax << endl;
}
void task2(vector<float>V, ofstream &outFile){
    int pos1, pos2, ans = 0;
    for(int i = 0; i < V.size(); i++){
        if(V[i] < 0){
            pos1 = i;
            break;
        }
    }
    for(int i = pos1+1; i < V.size(); i++){
        if(V[i] < 0){
            pos2 = i;
            break;
        }
    }
    cout << "pos1 = " << pos1 << " pos2 = " << pos2 << endl;
    outFile << "pos1 = " << pos1 << " pos2 = " << pos2 << endl;
    for(int i = pos1 + 1; i < pos2; i++){
        ans += abs(V[i]);
    }
    cout << "Summa = " << ans << endl;
    outFile << "Summa = " << ans << endl;
}
void sortirovka(vector<float> &V) {
    for (int i = 1; i < V.size(); i++) {
        float temp = V[i];
        int j = i - 1;
        while (j >= 0 && V[j] < temp) {
            V[j + 1] = V[j];
            j--;
        }
        V[j + 1] = temp;
    }
}
void task3(vector<float> &V, ofstream &outFile){
    float ans;
    for (int i = 0; i < V.size(); i++) {
        if (V[i] < 0) {
            V[i] = fabs(modf(V[i], &ans));
        }
    }
    sortirovka(V);
    cout << "Упорядоченный масив через алгоритм собировки выбором:" << endl;
    outFile << "Упорядоченный массив через алгоритм сортировки выбором:" << endl;
    print(V, outFile);
}
int main() {
    system("clear");
    srand(time(0));
    string fileName = "task_4_dbl.dat";
    string outputFile = "rez_4.txt";
    ofstream outFile(outputFile, ios::out);
    vector<float> V;
    read(fileName, V);
    cout << "Вывод исходных значений с файла" << endl;
    outFile << "Вывод исходных значений с файла:" << endl;
    print(V, outFile);
    findmaxelem(V, outFile);
    task2(V, outFile);
    task3(V, outFile);
    outFile.close();
    return 0;
}