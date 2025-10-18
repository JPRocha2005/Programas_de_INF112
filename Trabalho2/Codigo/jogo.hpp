#ifndef CLASS_JOGO_HPP
#define CLASS_JOGO_HPP

#include <string>

class Jogo {
private:
	int _numJogadores;
	int _numTerritorios;
	int _numContinentes;
	int _numObjetivos;
	Jogador* _jogadoresNoJogo;
	Territorio* _territoriosNoJogo;
	Continente* _continentesNoJogo;
	Carta* _objetivosNoJogo;
	Jogador* _jogadorDaVez;

public:
	// Contrutor e Destrutor
	Jogo(int num_jogadores, int num_territorios, int num_continentes, int num_objetivos);
	~Jogo();
	
	// Getters
	Jogador* getJogadorDaVez();
	
	// Setters
	void setJogadorDaVez(Jogador* jogador_da_vez);
	
	// Outras operacoes
	void organizarJogo(); // distribuicao inicial de territorios, objetivos e exercitos aos jogadores
	void iniciarJogada(Jogador* jogador_da_vez);
	void distribuirExercitos(int num_exercitos_colocados, std::string nome_territorio_escolhido, Jogador& jogador_da_vez);
	void distribuirExercitos(int num_exercitos_deslocados, std::string nome_territorio_origem, std::string nome_territorio_destino);
	int sortearValor();
	bool isValorSorteadoValido();
	void exibirTerritorios(Jogador& jogador);
	void exibirObjetivos(Jogador& jogador);
	std::string fimdejogo(); // retorna "nao" se nao houver ganhador
}
	

#endif

