#ifndef CLASS_EXERCITO_HPP
#define CLASS_EXERCITO_HPP

#include <string>

class Exercito {
private:
	std::string _nomeExercito;
	Jogador _jogadorDonoExercito;
	
public:
	Exercito(std::string nome_exercito, Jogador jogador_dono_exercito)
	~Exercito();
	
	std::string getNome();
	Jogador getDono();
	setDono(Jogador novo_dono);
	
	char rolarDado();
	virtual void ataque(Territorio territorio_origem, 
		Territorio territorio_destino)
	
}

#endif