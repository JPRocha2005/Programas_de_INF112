#ifndef CLASS_CONTINENTE_HPP
#define CLASS_CONTINENTE_HPP

#include <string>

class Continente {}
private:
	const std::string _nomeContinente;
	Territorio* _territoriosContinente;
	int _contTerritoriosContinente;

public:
	Continente(std::string& nome_continente, int num_territorios_continente);
	~Continente();
	
	Territorio* getTerritorios();
	std::string getNome();
	
	void setNome(std::string& novo_nome_continente);

	void adicionarTerritorio(Territorio territorio_adicionado);
	void removerTerritorio(Territorio territorio_removido);
}

#endif