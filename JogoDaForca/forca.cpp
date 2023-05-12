#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <fstream>
using namespace std;


string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

void imprime_cabecalho() {
	cout << "********************" << endl;
	cout << "*  Jogo da forca!  *" << endl;
	cout << "********************" << endl;
	cout << endl;
}

bool letra_existe(char chute) {
	for (char letra : palavra_secreta){
		if (chute == letra)
			return true;
	}
	return false;
}

void imprime_chutes_errados() {
	cout << "Chutes errados: ";
	for (char letra : chutes_errados) {
		cout << letra << " "; 
	}
	cout << endl; 
	
}

void imprime_palavra_secreta() {
	for (char letra : palavra_secreta) {
		if  (chutou[letra]) {
			cout << letra << " ";
		} else {
			cout << "_ ";
		}
	}
	cout << endl;
}

void chutar_letra() {
	char chute;
	cout << " " << endl;
	cout << "Chute uma letra: " << endl;
	cin >> chute;
	chutou[chute] = true;
	if (letra_existe(chute)) {
		cout << "Você acertou! Seu chute está na palavra!" << endl;
	} else {
		cout << "Você errou! Seu chute não está na palavra!" << endl;
		chutes_errados.push_back(chute);
	}
	cout << " " << endl;
}

bool is_valid_acerto() {
	for (char letra : palavra_secreta)
		if (!chutou[letra])
			return true;
	return false;
}

bool is_valid_enforcou () {
	return chutes_errados.size() < 5;
}

vector<string> le_arquivo() {
	ifstream arquivo;
	arquivo.open("palavras.txt");

	if (arquivo.is_open()){
		int quantidade_palavras;
		// lê a primeira linha e pula já para a proxima ;)
		arquivo >> quantidade_palavras;

		// cout << "O arquivo possui " << quantidade_palavras << " palavras." << endl;

		vector<string> palavras_do_arquivo;

		for (int i = 0; i < quantidade_palavras; i++) {
			string palavra_lida;
			arquivo >> palavra_lida;
			// cout << "Na linha " << i << " : " << palavra_lida << endl;
			palavras_do_arquivo.push_back(palavra_lida);
		}
		arquivo.close();
		return palavras_do_arquivo;
	} else {
		cout << "Não foi possível abrir o arquivo." << endl;
		exit(0);
	}
}

void sortear_palavra() {
	vector<string> palavras = le_arquivo();
	srand(time(NULL));
	int indice_sorteado = rand() % palavras.size();
	palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista) {
	ofstream arquivo;
	arquivo.open("palavras.txt");
	if (arquivo.is_open()) {
		arquivo << nova_lista.size() << endl;
		for (string palavra: nova_lista) {
			arquivo << palavra << endl;
		}
		arquivo.close();
	} else {
		cout << "Não foi possível abrir o arquivo." << endl;
		exit(0);
	}

}

void adiciona_palavra() {
	cout << "Digite a nova palavra, usando letras maiúsculas!" << endl;
	string nova_palavra;
	cin >> nova_palavra;

	vector<string> lista_palavras = le_arquivo();
	lista_palavras.push_back(nova_palavra);

	salva_arquivo(lista_palavras);
}

int main(int argc, char const *argv[]) {
	imprime_cabecalho();
    
	le_arquivo();

	sortear_palavra();

	while (is_valid_enforcou() && is_valid_acerto()) {
		imprime_chutes_errados();

		imprime_palavra_secreta();
		
		chutar_letra();
	}

	cout << "Fim de jogo!" << endl;
	cout << "A palavra secreta era: " << palavra_secreta << endl;
	if (is_valid_acerto())
		cout << "Você perdeu! Tente novamente!" << endl;
	else {
		cout << "Você venceu!" << endl;
		cout <<"Você deseja adicionar uma nova palavra ao banco de palavras? (S/N)" << endl;
		char resposta;
		cin >> resposta;
		if (resposta == 'S') {
			adiciona_palavra();
		}
	}
    return 0;
}