#include "territorio.hpp"
#include <string>


Territorio::Territorio(std::string& nome_territorio, Territorio* fronteiras, int num_fronteiras) {
	_nomeTerritorio = nome_territorio;
	_Fronteiras = new Territorio[num_fronteiras];
	_contFronteiras = 0;
	_numExercitos = 0;
}

Territorio::~Territorio() {
	delete[] _nomesFronteiras;
}

std::string Territorio::getNome() {
	return _nomeTerritorio;
}

Territorio* Territorio::getFronteiras() {
	return _nomesFronteiras;
}

int Territorio::getNumFronteiras() {
	retunr _numFronteiras;
}

int Territorio::getNumExercitos() {
	return _numTerritorios;
}
	
void Territorio::setNome(std::string& novo_nome_territorio) {
	nomeTerriorio = novo_nome_territorio;
} 

void Territorio::setNumExercitos(int num_exercitos) {
	_numExercitos = num_exercitos;
}

void Territorio::adicionarExercitos(int exercitos_adicionados) {
	_numExercitos += exercitos_adicionados;
}

void Territorio::removerExercitos(int exercitos_removidos) {
	_numExercitos -= exercitos_removidos
}

void Territorio::adicionarFronteira(Territorio territorio_fronteira) {
	_fronteiras[_contFronteiras] = territorio_fronteiras;
	_contFronteiras++;
}

/*
for(int i=0; i<num_fronteiras; i++)
		_nomesFronteiras[i] = fronteiras[i];
	
	// Apos a conquista de um novo territorio (eu acho)
	
	// 1) Copio o meu array para uma copia
	std::string* copia_nomes_fronteiras = new std::string[_contFronteiras];
	for (int i=0; i<_contFronteiras;i++)
		copia_nomes_fronteiras[i] = _nomesFronteiras[i];
	
	// 2) Aumento o tamanho do array
	_nomesFronteiras = new std::string[_contFronteiras+1]
	
	// 3) Copio o array da copia de volta para o original
	for (int i=0; i<_contFronteiras;i++)
		_nomesFronteiras[i] = copia_nomes_fronteiras[i];
	
	// 4) Coloco a nova fronteira
	_nomesFronteiras[_contFronteiras] = territorio_fronteira.getFronteira();
	_contFronteiras++;

	*/