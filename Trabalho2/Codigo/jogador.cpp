#include "jogador.hpp"
#include <string>
#include <iostream>

Territorio& getTerritorios() {
	return _territoriosJogador;
}

int Jogador::getNumTerritorios() {
	return _numTerritoriosJogador;
}

int Jogador::getObjetivoDaCarta() {
	return _cartaObjetivo.getObjetivo();
}

void Jogador::setCartaObjetivo(Carta& carta_objetivo) {
	_cartaObjetivo = carta_objetivo;
}

void Jogador::adicionarTerritorio(int num_exercitos_adicionados, Territorio& territorio_ganho) {
	_territorioJogador[_numTerritoriosJogador] = territorio_ganho;
	_numTerritoriosJogador++;
}

void Jogado::removerTerritorio(Territorio& territorio_perdido) {
	
	// 1) Encontro e apago o territorio perdido
	for (int i=0; i<_numTerritorioJogador; i++)
		if (_territoriosJogador[i].getNome() == territorio_perdido.getNome();)
			_territoriosJogador[i].setNome("\0");
		
	// 2) Atualizo as posicoes do vetor de territorios
	Territorio copia_territorios_jogador[50];
	for (int i=0; i<_numTerritoriosJogador; i++) {
		copia_territorios_jogador[i] = _territoriosJogador[i]; // passo para uma copia
		_territorioJogador[i].setNome("\0"); // apago os valores do original
	}
	for (int i=0; i<_numTerritoriosJogado; i++)
		if (copia_territorios_jogador[i] != "\0")
			_territoriosJogador[i] = copia_territorios_jogador[i]; // volto para o original
		
	_numTerritoriosJogador--;
}

void Jogador::setExercitosTerritorio(std::string nome_territorio, int num_exercitos) {
	for (int i=0; i<_numTerritoriosJogador; i++)
		if (_territoriosJogador[i].getNome() == nome_territorio) {
			_territoriosJogador[i].setExercitos(num_exercitos);
			return;
		}
	std::cout << "Jogador nao possui o territorio " << nome_territorio << std::endl;
	
}