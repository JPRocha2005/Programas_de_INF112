#ifndef CLASS_EXERCITOAEREO_HPP
#define CLASS_EXERCITOAEREO_HPP

#include <string>

class ExercitoAereo : public Exercito{
private:
// ?

public:
	ExercitoAereo(std::string nome_exercito, Jogador dono_exercito)
	~ExercitoAereo();
	
	// herdam gets e sets
	
	void ataque(Territorio territorio_origem, 
		Territorio territorio_destino) override;


}

#endif