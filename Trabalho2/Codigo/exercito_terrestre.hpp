#ifndef CLASS_EXERCITOTERRESTRE_HPP
#define CLASS_EXERCITOTERRESTRE_HPP

class ExercitoTerrestre : public Exercito {
private:
// ?

public:
	ExercitoTerrestre(std::string nome_exercito, Jogador dono_exercito)
	~ExercitoTerrestre();
	
	// herda gets e sets
	
	void ataque(Territorio territorio_origem,
		Territorio territorio_destino) override;
	
}

#endif