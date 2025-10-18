#ifndef CLASS JOGADOR_HPP
#define CLASS_JOGADOR_HPP

class Jogador {
private:
	Carta _cartaObjetivo;
	Territorio _territoriosJogador[50];
	int _numTerritoriosJogador = 0;

public:
	// Getters
	Territorio& getTerritorios();
	int getNumTerritorios();
	int getObjetivoDaCarta();
	
	// Setters
	void setCartaObjetivo(Carta& carta_objetivo);
	
	// Outras operacoes
	void adicionarTerritorio(int num_exercitos_adicionados, Territorio& territorio_ganho);
	void removerTerritorio(Territorio& territorio_perdido);
}

#endif