#include "exercito"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Exercito::Exercito(std::string nome_exercito, Jogador jogador_dono_exercito) {
	_nomeExercito = nome_exercito;
	_jogadorDonoExercito = jogador_dono_exercito;
}

Exercito::~Exercito() {}
	
std::string getNome() {
	return _nomeExercito;
}


Jogador getDono() {
	return _jogadorDonoExercito;
}


setDono(Jogador novo_dono) {
	_jogadorDonoExercito = novo_dono;
}

char rolarDado() { // Funcao retorna A para vitoria do Ataque D para Defesa

	unsigned int seed = time(0); // 1) crio uma seed com time(0)
	srand(time(0)); // 2) inicializo srand para gerar os numeros aleatorios com rand()
	
	int ataque_numero1_6 = (rand()%6) + 1; // sorteio um numero aleatorio de 1 a 6
	int defesa_numero1_6 = (rand()%6) + 1;
	
	if (ataque_numero1_6 > defesa_numero1_6) // Ataque só ganha se for maior que Defesa
		return "A"; 
	else									// Defesa ganha no empate e se for maior que o Ataque
		return "D";
}

virtual void ataque(Territorio territorio_origem, Territorio territorio_destino) {
	
	// Variaveis auxiliares
	int num_exercitos_ataque = territorio_origem.getExercitos();
	int num_exercitos_defesa = territorio_destino.getExercitos();
	
	// 1) Verificar se o ataque é permitido
	
	// Duas condicoes:
	// 1.1) O territorio_origem deve ter mais de 1 exercito
	if (num_exercitos_ataque <= 1) {
		std::cout << "Ataque indisponivel! Nao ha exercitos suficientes para realizar o ataque\n";
		return;
	}
	
	// 1.2) O territorio_origem deve fazer fronteira com o territorio_destino
	std::string* fronteiras_permitidas = territorio_origem.getFronteiras();
	int num_fronteiras = territorio_origem.getNumFronteiras();
	bool faz_fronteira = false;
	for (int i=0; i<num_fronteiras; i++)
		if (fronteiras_permitidas[i] == territorio_destino.getNome())
			faz_fronteira = true;
	if (!faz_fronteira) {
		std::cout << "Ataque indisponivel! O territorio " << territorio_origem << "nao faz fronteira com " << territorio_destino << std::endl;
		return;
	}
	
	// 2) Combate
	while (num_exercitos_defesa > 0 || num_exercitos_ataque > 1) { // Enquanto houver exercitos suficientes na defesa ou no ataque
		if (rolarDado() == "A") // Vitoria do ataque
			num_exercitos_defesa--;
		else					// Vitoria da defesa
			num_exercitos_ataque--;
	}
	
	// 3) Conquista
	if (num_exercitos_ataque > 1) { // Significa que o ataque venceu 
		// Transferencia de 1 exercito para o territorio ganho - OBRIGATORIO
		num_exercitos_ataque--;
		num_exercitos_defesa++;
		
		// Mudando o jogador dono dos territorios - ataque ganha 1 territorio e a defesa perde 1 territorio
		// ?????????????????????????
	}
	territorio_origem.setExercitos(num_exercitos_ataque); // Atualizando as variaveis Territorio
	territorio_destino.setExercitos(num_exercitos_defesa);	
}