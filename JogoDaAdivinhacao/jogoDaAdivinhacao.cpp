#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	const int NUMERO_SECRETO = rand() % 100;
	int chute;
	char dificuldade;
	int numero_de_tentativas, tentativa = 0;
	double pontos = 1000;
	
	
	cout << "Hello World!" << endl;	
	cout << "*************************************" << endl;
	cout << "* Bem-vindo ao jogo de adivinhação! *" << endl;
	cout << "*************************************" << endl; 
	
	cout << "Escolha uma dificuldade: " << endl; 
	cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl; 
	cin >> dificuldade;

	switch (dificuldade) {
		case 'F':
			numero_de_tentativas = 15;
			break; 
		case 'M':
			numero_de_tentativas = 10;
			break;
		case 'D':
			numero_de_tentativas = 5;
			break;
		default:
			numero_de_tentativas = 5;
			break;
	}
	bool nao_acertou = chute != NUMERO_SECRETO;
	for (tentativa = 1; tentativa <= numero_de_tentativas; tentativa++) {
		cout << "Tentativa: " << tentativa << endl;
		cout << "Qual seu chute?" << endl;
		cin >> chute;
		cout << "O valor do seu chute é: " << chute << endl;
		
		double distanciaAcerto = abs(chute - NUMERO_SECRETO);
		double pontos_perdidos = distanciaAcerto / 2;
		pontos = pontos - pontos_perdidos;
		bool acertou = chute == NUMERO_SECRETO;
		bool chute_maior = chute > NUMERO_SECRETO;
		
		if (acertou) {
			cout << "Parabéns, você acertou o número" << endl;
			nao_acertou = false;
			break;
		} else if(chute_maior) {
			cout << "Seu chute foi maior que o número secreto" << endl;
		} else {
			cout << "Seu chute foi menor que o número secreto" << endl;
		}
	}
	cout << "Fim de jogo!" << endl;
	if (nao_acertou) {
		cout << "Número secreto era: " << NUMERO_SECRETO << endl;
		cout << "Você não acertou o número... ._." << endl;
	} else {
		cout << "Você terminou o jogo com " << tentativa << endl;
		cout.precision(2);
		cout << fixed;
		cout << "Sua pontuação foi de: " << pontos << " pontos." << endl;
	}
	return 0;
}
