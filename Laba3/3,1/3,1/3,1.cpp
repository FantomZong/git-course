
#include <iostream>
#include"DSU.h"

using namespace std;

struct R
{
    int v1, v2;
    int weight;

};

void sort(R*, int);
void Kras();


int main()
{
    Kras();




}

void Kras() {
    cout << "Enter number of vertexes : ";
    int vs;
    cin >> vs;
    cout << endl;

    cout << "Enter number of ribs : ";
    int size;
    cin >> size;
    cout << endl;

    R* arr = new R[size];
    Vertex* vxs = new Vertex[vs];


    cout << "v1 v2 weight" << endl;
    for (int i = 0, j = 0; i < size + 1; i++, j++)
    {
        if (i < size) {
            cin >> arr[i].v1;
            cin >> arr[i].v2;
            cin >> arr[i].weight;
        }
        if (j < vs) {
            set_make(&vxs[j]);
        }
    }

    sort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << "v1 : " << arr[i].v1 << " v2 : " << arr[i].v2 << " W : " << arr[i].weight << endl;
    }

    cout << "Vertexes Weight Dobir" << endl;
    bool b = false;

    for (int i = 0; i < size; i++)
    {
        b = false;
        cout << arr[i].v1 << ", " << arr[i].v2;

        if (set_find(&vxs[arr[i].v1]) != set_find(&vxs[arr[i].v2])) {
            b = true;
            set_union(&vxs[arr[i].v1], &vxs[arr[i].v2]);
        }
        cout << "        " << arr[i].weight << "       " << b << endl;
    }
}


void sort(R* arr, int size) {
    R temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j].weight > arr[j + 1].weight) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

    }
}
