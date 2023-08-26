#include <iostream>
using namespace std;

void ordena(int array[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = (i+1); j < size; j++) {
      if (array[j] < array[i]) {
        int aux = array[j];
        array[j] = array[i];
        array[i] = aux;
      }
    }
  }

}

int main(int argc, char const *argv[]) {
  int array[5] = {};
  int n = sizeof(array)/sizeof(array[0]);

  cout << "Insira os numeros\n";

  for (int i = 0; i < 5; i++) {
    cin >> array[i];
  }

  ordena(array, n);

  cout << "\n";
  for (int i = 0; i < 5; i++) {
    cout << array[i] << " ";
  }

  cout << "\n";
  cout << "Hello, world!\n";
  return 0;
}
