#include "carta.hpp"
#include "continente.hpp"
#include "exercito.hpp"
#include "exercito_aereo.hpp"
#include "exercito_terrestre.hpp"
#include "jogador.hpp"
#include "jogo.hpp"
#include "territorio.hpp"

#include <iostream>
#include <string>

bool is_parametros_ok(int num_territorios, int num_jogadores, int num_continentes, int num_objetivos) {
	if (num_territorios > 42 || num_territorios < 2)
		return false;
	if (num_jogadores > 6 || num_jogadores < 2)
		return false;
	if (num_continentes != 6)
		return false;
	if (num_objetivos < num_jogadores || num_objetivos > 6)
		return false;
	return true;
	
}

int main() {

	int numero_territorios = 42; // num_min = 2, num_max = 42
	int numero_de_jogadores = 2; // de 2 a 6 jogadores
	int numero_de_continentes = 6; // sempre = 6
	int numero_de_objetivos = 6 // maior ou igual ao numero_de_jogadores e num_max = 6
	std::string nome_do_territorio_de_destino, nome_do_territorio_de_origem;
	
	if (!is_parametros_ok(numero_territorios, numero_de_jogadores, numero_de_continentes, numero_de_objetivos))
		std::cout << "Algum dos parametros informados tem um valor invalido\n";
		std::cout << "Fim de jogo\n";
		return 0;
	
	Jogo war(numero_de_jogadores, numero_territorios,
		numero_de_continentes, numero_de_objetivos);
		
	war.organizarJogo()
	
	while(war.fimDeJogo() == "nao") {
		// 1) Jogador da vez informa o numero de exercitos que quer mover e para onde
		cin >> numero_de_exercitos >> nome_do_territorio_de_destino;
		
		// 2) Jogador da vez distribui seus exercitos no territorio de origem
		war.distribuirExercitos(numero_de_exercitos, nome_do_territorio_de_origem, war.getJogadorDaVez())
		
		// 3) Jogador da vez inicia sua jogada - faz os ataques
		war.iniciarJogada(war.getJogadorDaVez());
		
		// 4) Após os ataques, Jogador da vez faz a redistribuicao de exercitos
		// para os territorios conquistados
		war.distribuirExercitos(numero_de_exercitos, nome_do_territorio_de_origem, nome_do_territorio_de_destino);
	}

	return 0;
}