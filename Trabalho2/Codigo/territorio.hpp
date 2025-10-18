#ifndef CLASS_TERRITORIO_HPP
#define CLASS_TERRITORIO_HPP

#include <string>

class Territorio {
private:
	std::string _nomeTerritorio;
	Territorio* _Fronteiras;
	int _contFronteiras;
	int _numExercitos; // eu adicionei - de acordo com main
	
public:	
	// Construtro e Destrutor
	Territorio(std::string& nome_territorio, Territorio* fronteiras, int num_fronteiras);
	~Territorio();
	
	// Getters
	std::string getNome();
	Territorio* getFronteiras();
	int getNumFronteiras();
	int getNumExercitos();
	
	// Setters
	void setNome(std::string& novo_nome_territorio);
	void setNumExercitos(int num_exercitos);
	
	void adicionarExercitos(int exercitos_adicionados);
	void removerExercitos(int exercitos_removidos);
	void adicionarFronteira(Territorio territorio_fronteira);
}

#endif