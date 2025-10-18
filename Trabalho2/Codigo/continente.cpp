#include "continente.hpp"

Continente::Continente(std::string& nome_continente, int num_territorios_continente) {
	_nomeContinente = nome_continente;
	_territoriosContinente = new Territorio[num_territorios];
	_contTerritoriosContinente = 0;
}

Continente::~Continente() {
	delete[] _territoriosContinente;
}

Territorio* Continente::getTerritorios() {
	return _territoriosContinente;
}

std::string Continente::getNome() {
	return _nomeContinente;
}

void Continente::setNome(std::string& novo_nome_continente) {
	_nomeContinente = novo_nome_continente;
}

void Continente::adicionarTerritorio(Territorio territorio_adicionado) {
	_territoriosContinente[_contTerritoriosContinente] = territorio_adicionado; // atribuicao funciona mesmo com construtor
	_contTerritoriosContinente++;
}

void Continente::removerTerritorio(Territorio territorio_removido) {
	
	// 1) Apago o elemento solicitado
	for(int i=0; i<_contTerritoriosContinente; i++)
		if(_territoriosContinente[i].getNome() == territorio_removido.getNome()) {
			_territoriosContinente[i].setNome("\0"); // setar como caracter nulo
		}
		
	// 2) Crio uma copia dos territorios do continente
	copia_territorios_continente = new Territorio[_contTerritoriosContinente];
	for (int i=0; i<_numTerrritoriosContinente; i++)
		copia_territorios_continente[i] = _territoriosContinente[i];
	
	// 3) Desaloco e Redefino o array _territoriosContinente
	delete[] _territoriosContinente;
	_territoriosContinente = new Territorio[_contTerritoriosContinente-1];
	
	// 4) Completo o novo array com os elementos diferentes de "\0"
	for (int i=0, j=0; i<_contTerritoriosContinente; i++)
		if(copia_territorios_continente.getNome()) { // se existir, ou seja, se nao for nulo ("\0")
			_territoriosContinente[j] = copia_territorios_continente[i];
			j++;
		}
		
	// 5) Atualizo o contador de territorios e desaloco a memoria da copia
	_contTerritoriosContinente--;
	
	// 6) Desaloco a memoria da copia
	delete[] copia_territorio_continente;
}