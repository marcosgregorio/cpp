#include <iostream>
using namespace std;

int main() {
	cout << "Hello World!" << endl;	
	cout << "*************************************" << endl;
	cout << "* Bem-vindo ao jogo de adivinhação! *" << endl;
	cout << "*************************************" << endl; 
	
	int numero_secreto = 42;
	// cout << "O número secreto é " << numero_secreto << "." << endl;
	int chute;
	cin >> chute;
	cout << "O valor do seu chute é: " << chute << endl;
	
	if (chute == numero_secreto) {
		cout << "Parabéns, você acertou o número";
	} else if(chute > numero_secreto) {
		cout << "Seu chute foi maior que o número secreto" << endl;
	} else {
		cout << "Seu chute foi menor que o número secreto" << endl;
	}
}
