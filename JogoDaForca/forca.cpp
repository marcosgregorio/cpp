#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

const string PALAVRA_SECRETA = "UVA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letraExiste(char chute) {
	for (char letra : PALAVRA_SECRETA){
		if (chute == letra)
			return true;
	}
	return false;
}

void imprimeChutesErrados() {
	cout << "Chutes errados: ";
	for (char letra : chutes_errados) {
		cout << letra << " "; 
	}
		cout << " " << endl; 
	
}

int main(int argc, char const *argv[]) {
    bool nao_acertou = true;
    bool nao_enforcou = true;

	cout << "********************" << endl;
	cout << "   Jogo da forca!  " << endl;
	cout << "********************" << endl;
	cout << endl;


    while (nao_enforcou && nao_acertou) {
		imprimeChutesErrados();

		for (char letra : PALAVRA_SECRETA) {
			if  (chutou[letra]) {
				cout << letra << " ";
			} else {
				cout << "_ ";
			}
		}
		char chute;
		cout << endl;
		cout << " " << endl;
		cout << "Chute uma letra: " << endl;
		cin >> chute ;
		chutou[chute] = true;
		if (letraExiste(chute)) {
			cout << "Você acertou! Seu chute está na palavra!" << endl;
		} else {
			cout << "Você errou! Seu chute não está na palavra!" << endl;
			chutes_errados.push_back(chute);
		}
		cout << " " << endl;
	}
    return 0;
}
