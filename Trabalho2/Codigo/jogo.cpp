#include "jogo.hpp"
#include "jogador.hpp"
#include "territorio.hpp"
#include "continente.hpp"
#include "carregarMapa.hpp" 

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

// Variaveis globais de "carregarMapa.hpp" (ja preenchidas)
/* std::string *nomesTodosTerritorios; 
std::string *numFronteirasPorTerritorio;
std::string **matrizFronteirasPorTerritorio;
std::string *nomesTodosContinentes;            
std::string *numTerritorioPorContinente;
std::string **matrizTerritoriosContinentes;
std::string *nomesTodosObjetivos; */

Jogo::Jogo(int num_jogadores, int num_territorios, int num_continentes, int num_objetivos) {
	// Inicializar variaveis num
	
	// Jogadores
	_numJogadores = num_jogadores;
	_numTerritorios = num_territorios;
	_numContinentes = num_continentes;
	_numObjetivos = num_objetivos;
	
	// Chamar os contrutores
	
	_jogadoresNoJogo = new Jogador[num_jogadores];
	
	_territoriosNoJogo = new Territorio[num_territorios];
	for (int i=0; i<num_territorios; i++) {
		_territoriosNoJogo[i] = Territorio(nomesTodosTerritorios[i], numFronteirasPorTerritorio[i]);  // recebe da variavel global 
		for (int j=0; j<numFronteirasPorTerritorio; j++)
			_territoriosNoJogo[i].adicionarFronteira(matrizFronteirasDeTerritorios[i][j]);
	}
	
	_continentesNoJogo = new Continente[num_continentes];
	for (int i=0; i<num_continentes; i++)
		_continentesNoJogo = Continente(nomesTodosContinentes[i], numTerritoriosPorContinente[i]);
		for(int j=0; j<numTerritoriosPorContinente; j++)
			_continentesNoJogo.adicionarTerritorio(matrizTerritoriosContinentes[i][j]);
	
	_objetivosNoJogo = new Carta[num_objetivos];
	for (int i=0; i<num_objetivos; i++)
		_objetivosNoJogo[i].setObjetivo(nomesTodosObjetivos[i]);
	
	_jogadorDaVez = nullptr;
}
	
Jogo::~Jogo() {
	delete[] _jogadoresNoJogo;
	delete[] _territoriosNoJogo;
	delete[] _continentesNoJogo;
	delete[] _objetivosNoJogo;
}

Jogador* Jogo::getJogadorDaVez() {
	return _jogadorDaVez;
}

void Jogo::setJogadorDaVez(Jogador* jogador_da_vez) {
	*_jogadorDaVez = *jogador_da_vez;
}

void Jogo::organizarJogo() {
	// 1) Distribuicao dos territorios aos jogadores - por sorteio
	num_territorios_jogador = _numTerritorios / _numJogadores;
	num_territorios_sobra = _numTerritorios % _numJogadores;
	int valores_sorteados[_numTerritorios];
	int num_valores_sorteados = 0;
	int index_territorio;
	for (int i=0; i<_numJogadores; i++) {// para cada jogador
		for (int j=0; j<num_territorios_jogador; j++) { // para cada territorio do jogador
			index_territorio_sorteado = sortearValorN(_numTerritorios)  // um valor de 0 a N sorteado (N = parametro da funcao)
			if (validarValorSorteado(index_territorio_sorteado, valores_sorteados, num_valores_sorteados))// valida o valor sorteado (valor novo) e atualiza a lista
				_jogadoresNoJogo[i].adicionarTerritorio(_territorioNoJogo[index_territorio_sorteado];
			else 
				j--; // desconsidera essa iteracao
		}
		exibir_territorio(_jogadoresNoJogo[i], i); // exibi os territorios o i-esimo jogador
	}
		
	// 2) Distribuicao dos objetivos para cada jogador - por sorteio
	int valores_sorteados[_numObjetivos];
	int num_valores_sorteados = 0;
	for (int i=0; i<_numJogadores; i++) {
		index_objetivo_sorteado = sortearValorN(_numObjetivos);
		if (validarValorSorteado(index_objetivo_sorteado, valores_sorteados, num_valores_sorteados)) {
			_jogaresNoJogo[i].setCartaObjetivo(_objetivosNoJogo[index_objetivo_sorteado];
			exibirObjetivos(_jogadoresNoJogo[i], i);
		}
		else 
			j--; // desconsidera essa iteracao
	}
	
	// 3) Distribuir os exercitos em cada territorio de cada jogador
	int num_exercitos_disponiveis; // num exercitos disponiveis para alocar
	Territorio territorios_jogador[num_territorios_jogador]; // variavel
	
	// Primeiro altero os exercitos nos territorios localmente, depois passo o resultado final para o objeto
	
	// 3.1) Alteracao local
	for (int i=0; i<_numJogadores; i++) {
		territorios_jogador = jogadoresNoJogo[i].getTerritorio()
		num_exercitos_disponiveis = num_territorios_jogador/2; // REGRA DO JOGO
		for (int j=0; j<num_territorios_jogador; j++) { // loop 1 - para preenchimento obrigatorio de exercitos 
			territorios_jogador[j].adicionarExercitos(1) // Todos territorios precisam ter pelo menos 1 exercito
			num_exercitos_disponiveis--;
		}
		if (num_exercitos_disponiveis > 0) {
			int exercitos;
			std::cout << "Territorios:\n";
			exibirTerritorios(_jogadoresNoJogo[i], i);
			for (int j=0; j<num_territorios_jogador || num_exercitos_disponiveis > 0; j++)  { // loop 2 - para preenchimento opcional de exercitos 
				// Jogador aloca os exercitos que sobraram
				std::cout << "Exercitos disponiveis para alocacao " << num_exercitos_disponiveis << std::endl;
				std::cout << "Adicionar exercitos no territorio " << territorios_jogador[j] << ": ";
				std::cin >> exercitos;
				territorios_jogador[j].adicionarExercitos(exercitos);
				num_exercitos_disponiveis -= exercitos;
			}
							
		}
	}
	
	// 3.2)Alteracao nos objetos
	for (int i=0; i<_numJogadores; i++)
		for (int j=0; j<num_territorios_jogador; j++)
			jogadoresNoJogo[i].setNumExercitosTerritorio(territorios_jogador[j].getNome(), territorios_jogador[j].getNumExercitos());
}

void distribuirExercitos(int num_exercitos_colocados, std::string nome_territorio_escolhido, Jogador& jogador_da_vez) {
	jogador_da_vez.setNumExercitosTerritorios(nome_territorio_escolhido, num_exercitos, colocados)
}

void Jogo::iniciarJogada(Jogador* jogador_da_vez) {
	// Atacar o adversario e passar a vez
	
	// Para os territorios do jogador da vez
	int num_territorios = jogador_da_vez.getNumTerritorios();
	int num_fronteiras[num_territorios];
	int num_exercitos[num_territorios];
	for (int i=0; i< num_territorios; i++) {
		num_fronteiras[i] = jogador_da_vez.getTerritorios()[i].getNumFronteiras();
		num_exercitos[i] = jogador_da_vez.getTerritorios()[i].getNumExercitos();
	}
	
	// Para as fronteiras dos territorios do jogador da vez
	num_exercitos_fronteiras[num_territorios][10]; // para cada territorio e para cada fronteira desse territorio

	std::cout << "Territorios e fronteiras do jogador (E = numero de exercitos):\n";
	for (int i=0; i<num_territorios; i++) {
		std::cout << i+1 << ")" << jogador_da_vez.getTerritorios()[i].getNome() << "(" << num_exercitos[i] << " E)" << ": ";
		for (int j=0; j<num_fronteiras[i]; j++) {
			num_exercitos_fronteiras[i][j] = jogador_da_vez.getTerritorios()[i].getFronteiras()[j].getNumExercitos();
			std::cout << jogador_da_vez.getTerritorios()[i].getFronteiras()[j].getNome() << "(" << num_exercitos_fronteiras[i][j] << " E)" << " ";
		}
		std:cout << std::endl;
	}
	
	// Leitura do territorio atacante e do territorio atacado
	int num_atacante, num_defensor;
	std::string atacante_escolhido, defensor_escolhido;
	
	std::cout << "Digite o numero referente ao territorio que deseja usar no ataque: ";
	cin >> nome_atacante;
	atacante_escolhido = jogador_da_vez.getTerritorios()[num_atacante-1].getNome()
	std::cout << "Territorio atacante escolhido: " << atacante_escolhido  << std::endl;
	
	std::cout << "Fronteiras do territorio " << atacante_escolhido << std::endl;
	for (int i=0; i<num_fronteiras[num_atacante]; i++)
		std::cout << i+1 << ") " << jogador_da_vez.getTerritorios()[num_atacante-1].getFronteiras()[i].getNome() << std::endl;
	std::cout << "Digite um numero referente a fronteira que deseja atacar: ";
	cin >> num_defensor;
	defensor_escolhido = jogador_da_vez.getTerrritorio()[num_atacante-1].getFronteiras()[num_atacado-1].getNome();
	std::cout << "Fronteira defensora escolhida: " << defensor_escolhido;
	
	// Iniciar ataque
	int num_exercito_ataque = jogador_da_vez.getTerritorios()[num_atacante-1].getNumExercitos();
	int num_exercito_defesa = jogador_da_vez.getTerritorios()[num_atacante-1].getFronteiras[num_defensor-1].getNumExercitos();
	
	std::cout << "\n----------CONFRONTO----------\n";
	std::cout << "ATACANTE: " << atacante_escolhido << " X " << "DEFENSOR: " << defensor_escolhido << std::endl;
	std::cout << "EXERCITOS NO ATAQUE: " << num_exercitos_ataque << " X " << "EXERCITOS NA DEFESA: " << num_exercitos_defesa << std::endl;
	// Cada territorio (territorio do jogador e as fronteiras) tem exercitos e os exercitos tem o metodo "ataque"
	
		
}

void distribuirExercitos(int num_exercitos_deslocados, Territorio& territorio_origem, Territorio& territorio_destino) {
	Jogador jogador_defesa = 
	
	
	
}


int sortearValorN(int valor_maximo) {
	seed = time(0);
	srand(seed);
	return rand()%(valor_maximo+1);
}

bool validarValorSorteado(int valor, int valores_sorteados[], int& num_valores_sorteado) {
	for (int i=0; i<num_valores_sorteados; i++)
		if (valor == valores_sorteados[i])
			return false;
	valores_sorteados[num_valores_sorteado] = valor;
	num_valores_sorteados++;
	return true;
}

void exibirTerritorios(Jogador& jogador, int num_jogador) {
	Territorio territorios[] = jogador.getTerritorios();
	int num_territorios = jogador.getNumTerritorios();
	
	std::cout << "Jogador " << num_jogador << ": ";
	for (int i=0; i<num_territorios; i++)
		if (i == num_territorios-1)
			std::cout << territorios[i].getNome() << std::endl;			
		else
			std::cout << territorios[i].getNome() << ", ";	
}

void exibirObjetivos(Jogador& jogador, int num_jogador) {
	std::string objetivo = jogador.getObjetivoDaCarta();
	std::cout << "Jogador " << num_jogador << ": " << objetivo << std::endl;
}

/*
	// Primeiro, checo se há mais jogadores que objetivos, caso isso ocorra, duplica-se a lista de objetivos
	while (_numJogadores > _numObjetivos) { 
		Carta* copia_objetivos_jogo = new Carta[_numObjetivos];
		for (int i=0; i<_numObjetivos; i++)
			copia_objetivos_jogo[i] = _objetivosNoJogo[i];
		delete[] _objetivosNoJogo; 						// deleta a lista antiga
		_objetivosNoJogo = new Carta[_numObjetivos*2]; 	// aloca uma maior
		for (int i=0; i<2; i++)
			for (int j=0; j<_numObjetivos; j++) {
				if (i == 0)
					_objetivosNoJogo[j] = copia_objetivos_jogo[j];
				else if (i == 1)
					_objetivosNoJogo[j+_numObjetivos] = copia_objetivos_jogo[j];
			}
		delete[] copia_objetivos_jogo;
		_numObjetivos *= 2;
	}
*/