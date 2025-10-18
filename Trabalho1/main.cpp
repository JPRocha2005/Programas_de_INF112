// Main - Trabalho 1
// Escrito por João Pedro em 14/09

#include "arquivo.hpp"
#include <iostream>

int main() {
	
	// Declaracao do canvas principal
	Canvas tela;
	
	// Passo 1: Inicializando o Canvas
	CriarCanvas(tela, 40, 12);
	ImprimirCanvas(tela);
	
	// PASSO 2: Desenhar pontos coloridos
	DesenharPonto(tela, 5, 2, '@', 'R'); // Ponto vermelho
	DesenharPonto(tela, 8, 5, '@', 'G'); // Ponto verde
	ImprimirCanvas(tela);
	
	// PASSO 3: Desenhar uma linha horizontal
	DesenharLinha(tela, 2, 8, 15, 8, '=', 'B'); // Linha azul
	ImprimirCanvas(tela);
	
	// PASSO 4: Desenhar a borda de um retangulo
	DesenharRetangulo(tela, 18, 1, 12, 5, '#', 'Y'); // Retangulo amarelo
	ImprimirCanvas(tela);

	// PASSO 5: Desenhar um retangulo preenchido
	DesenharRetanguloPreenchido(tela, 28, 7, 10, 4, '*', 'C'); // Retangulo ciano
	ImprimirCanvas(tela);
	
	// PASSO 6: Criar dois novos canvas para testes
	Canvas telaA, telaB, telaResultante;
	CriarCanvas(telaA, 20, 8);
	CriarCanvas(telaB, 20, 8);
	// Desenhar formas em cada canvas
	DesenharRetangulo(telaA, 1, 1, 10, 6, 'A', 'M');
	DesenharRetanguloPreenchido(telaB, 5, 3, 12, 4, 'B', 'G');
	ImprimirCanvas(telaA);
	ImprimirCanvas(telaB);
	
	// PASSO 7: Sobrepor os dois canvas
	SobreporCanvas(telaResultante, telaA, telaB);
	ImprimirCanvas(telaResultante);
	
	// PASSO 8: Comparar os dois canvas
	std::cout << "\n7. Comparando Tela A e Tela B... " << std::endl;
	std::cout << "Resultado: "
	<< (CompararCanvas(telaA, telaB) ? "Iguais" : "Diferentes")
	<< std::endl;
	
	// PASSO 9: Liberar toda a memoria alocada
	DestruirCanvas(tela);
	DestruirCanvas(telaA);
	DestruirCanvas(telaB);
	DestruirCanvas(telaResultante);
	
	
	return 0;
}