// Implementação - Trabalho 1
// Escrito por João Pedro - 13/09

#include "arquivo.hpp"
#include <iostream>
#include <string>

// Colocar cor no terminal
std::string GetColorCode(char cor) {
	switch (cor) {
		case 'K': return "\033[30m"; // Black
        case 'R': return "\033[31m"; // Red
        case 'G': return "\033[32m"; // Green
        case 'Y': return "\033[33m"; // Yellow
        case 'B': return "\033[34m"; // Blue
        case 'M': return "\033[35m"; // Magenta
        case 'C': return "\033[36m"; // Cyan
        case 'W': return "\033[37m"; // White
        default:  return "\033[0m";  // Código para Resetar/Padrão
	}
	
}

// Funcao de Validacao - checar se o ponto/linha/Retangulo esta dentro do limites
bool ValidarPonto(Canvas &canvas, int pos_x, int pos_y) {
	
	bool x_valido = pos_x >= 0 && pos_x < canvas._largura;
	bool y_valido = pos_y >= 0 && pos_y < canvas._altura;
	
	if (x_valido && y_valido)
		return true;
	else
		return false;
}


// Criar Canvas
void CriarCanvas(Canvas &canvas, int largura, int altura) {
	// Largura e altura
	canvas._largura = largura;
	canvas._altura = altura;
	
	// Alocacao - pixels e cores
	canvas._pixels = new char*[altura]; // alocando vetor de ponteiros
	canvas._cores = new char*[altura]; 
 	for (int i = 0; i < altura; i++) { // percorrendo as linhas
		canvas._pixels[i] = new char[largura]; // alocando vetor para char de 'largura' espaços
		canvas._cores[i] = new char[largura];
	}
	
	
	// Inicializacao - pixels e cores
	for (int i = 0; i < altura; i++) // percorro as linhas
		for (int j = 0; j < largura; j++) { // percorro as colunas
			canvas._pixels[i][j] = ' '; // inicializo com whitespace
			canvas._cores[i][j] = ' '; // sem cor
		}
}

// Destruir Canvas
void DestruirCanvas(Canvas &canvas) {
	// Desalocacao - pixels e cores
 	for (int i = 0; i < canvas._altura; i++) { // percorrendo as linhas
		delete[] canvas._pixels[i]; // desalocando as linhas
		delete[] canvas._cores[i];
	}	
	delete[] canvas._pixels; // desalocando o vetor de ponteiro
	delete[] canvas._cores; 

}

// Imprimir Canvas
void ImprimirCanvas(Canvas &canvas) {
	
	// Desenhando a borda superior '-'
	for (int j = 0; j < canvas._largura+2; j++) // + 2 por causa das bordas
		std::cout << "-";
	std::cout << std::endl;
	
	// Desenhando o conteudo do Canvas + bordas laterais '|'
	for (int i = 0; i < canvas._altura; i++) {
		std::cout << "|";
		for (int j = 0; j < canvas._largura; j++)
			std::cout << GetColorCode(canvas._cores[i][j]) << canvas._pixels[i][j] << RESET;
		std::cout << "|" << std::endl;
	}
	// Desenhando a borda inferior '-'
	for (int j = 0; j < canvas._largura+2; j++) // + 2 por causa das bordas
		std::cout << "-";
	std::cout << std::endl;
}

// Desenhar Ponto
void DesenharPonto(Canvas &canvas, int coord_y, int coord_x,
char simbolo, char cor) {
	
	// Validacao - OutOfBoundarys
	bool ponto_valido = ValidarPonto(canvas, coord_x, coord_y);
	if (!ponto_valido) {
		std::cout << GetColorCode('R') << "Erro, o ponto em " << coord_x << " " 
		<< coord_y << " esta fora das dimensoes do canvas\n" << RESET;
		return; // encerro a funcao
	}
	
	// Desenhando o ponto
	canvas._pixels[coord_x][coord_y] = simbolo;
	canvas._cores[coord_x][coord_y] = cor;
}

// Desenhar Linha 	
void DesenharLinha(Canvas &canvas, int coord_x_inic, int coord_y_inic,
	int coord_x_fim, int coord_y_fim, char simbolo, char cor) {
	
	// Validacao - OutOfBoundary
	bool ponto_inic_valido = ValidarPonto(canvas, coord_x_inic, coord_y_inic);
	bool ponto_fim_valido = ValidarPonto(canvas, coord_x_fim, coord_y_fim);
	if (!ponto_inic_valido || !ponto_fim_valido) {
		std::cout << GetColorCode('R') << "Erro, a linha esta fora das dimensoes do canvas\n"
		<< RESET;
		return; // encerro a funcao
	}
	
	// Desenhando linha vertical
	if (coord_x_inic == coord_x_fim)
		for (int i = coord_y_inic; i <= coord_y_fim; i++) { // percorro as linhas. Considero a pos final tbm
			canvas._pixels[i][coord_x_inic] = simbolo;
			canvas._cores[i][coord_x_inic] = cor;
		}
	
	// Desenhando linha horizontal
	else if (coord_y_inic == coord_y_fim)
		for (int j = coord_x_inic; j <= coord_x_fim; j++) { // percorro as colunas. Considero a pos final tbm
			canvas._pixels[coord_y_inic][j] = simbolo;
			canvas._cores[coord_y_inic][j] = cor;
		}
	
	// Mensagem de Erro - Diagonal
	else
		std::cout << GetColorCode('R') << "Erro, a linha nao pode ser na diagonal\n"
		<< RESET;
	
}

// Desenhar Retangulo 
void DesenharRetangulo(Canvas &canvas, int coord_x_origem,
int coord_y_origem, int largura, int altura, char simbolo, char cor) {
	
	// Posicoes - somo a largura/altura menos para desconsiderar a pos_inicial
	int cima_esq_x = coord_x_origem, cima_esq_y = coord_y_origem;
	int cima_dir_x = coord_x_origem+largura-1, cima_dir_y = coord_y_origem;
	int baixo_esq_x = coord_x_origem, baixo_esq_y = coord_y_origem+altura-1;
	int baixo_dir_x = coord_x_origem+largura-1, baixo_dir_y = coord_y_origem+altura-1;
	
	// Validacao - OutofBoundary
	bool ponto1_valido = ValidarPonto(canvas, cima_esq_x, cima_esq_y);
	bool ponto2_valido = ValidarPonto(canvas, cima_dir_x, cima_dir_y);
	bool ponto3_valido = ValidarPonto(canvas, baixo_esq_x, baixo_esq_y);
	bool ponto4_valido = ValidarPonto(canvas, baixo_dir_x, baixo_dir_y);
	if (!ponto1_valido || !ponto2_valido || !ponto3_valido || !ponto4_valido) {
		std::cout << GetColorCode('R') << "Erro, o retangulo esta fora das dimensoes do canvas\n"
		<< RESET;
		return; // encerro a funcao
	}

	// Desenhan do retangulo
	
	// Linha Horizontal Cima
	DesenharLinha(canvas, cima_esq_x, cima_esq_y, // origem: cima_esq e fim: cima_dir
	cima_dir_x, cima_dir_y, simbolo, cor);
	// Linha Horizontal Baixo
	DesenharLinha(canvas, baixo_esq_x, baixo_esq_y, // origem: baixo_esq e fim: baixo_dir
	baixo_dir_x, baixo_dir_y, simbolo, cor);
	// Linha Vertical Esquerda
	DesenharLinha(canvas, cima_esq_x, cima_esq_y,  // origem: cima_esq e fim: baixo_esq
	baixo_esq_x, baixo_esq_y, simbolo, cor);
	// Linha Vertical Direita
	DesenharLinha(canvas, cima_dir_x, cima_dir_y, // origem: cima_dir e fim: baixo_dir
	baixo_dir_x, baixo_dir_y, simbolo, cor);
	
}

// Desenhar Retangulo Preenchido
void DesenharRetanguloPreenchido(Canvas &canvas, int coord_x_origem,
int coord_y_origem, int largura, int altura, char simbolo, char cor) {
	
	// Posicoes
	int cima_esq_x = coord_x_origem, cima_esq_y = coord_y_origem;
	int cima_dir_x = coord_x_origem+largura, cima_dir_y = coord_y_origem;
	int baixo_esq_x = coord_x_origem, baixo_esq_y = coord_y_origem+altura;
	int baixo_dir_x = coord_x_origem+largura, baixo_dir_y = coord_y_origem+altura;
	
	// Validacao - OutofBoundary
	bool ponto1_valido = ValidarPonto(canvas, cima_esq_x, cima_esq_y);
	bool ponto2_valido = ValidarPonto(canvas, cima_dir_x, cima_dir_y);
	bool ponto3_valido = ValidarPonto(canvas, baixo_esq_x, baixo_esq_y);
	bool ponto4_valido = ValidarPonto(canvas, baixo_dir_x, baixo_dir_y);
	if (!ponto1_valido || !ponto2_valido || !ponto3_valido || !ponto4_valido) {
		std::cout << GetColorCode('R') << "Erro, o retangulo esta fora das dimensoes do canvas\n"
		<< RESET;
		return; // encerro a funcao
	}
	
	// Desenhando o retangulo preenchido (loop de linhas)
	for (int i = 0; i < altura; i++)
		DesenharLinha(canvas, cima_esq_x, cima_esq_y+i, // a pos_y muda a cada iteracao
		cima_dir_x, cima_dir_y+i, simbolo, cor);
}

// Redimensionar Canvas
void Redimensionar(Canvas &canvas, int nova_altura, int nova_largura) {
	canvas._altura = nova_altura;
	canvas._largura = nova_largura;
}

// Sobrepor Canvas
void SobreporCanvas(Canvas &canva_resultante, Canvas &canva1, Canvas &canva2) {
	
	// Validacao - 2 canvas devem ter mesmo tamanho
	if (canva1._altura != canva2._altura || canva1._largura != canva2._largura) {
		std::cout << GetColorCode('R') << "Erro, os 2 canvas nao tem as mesmas dimensoes\n"
		<< RESET;
		return;
	}
	
	// Construo a tela resultante
	CriarCanvas(canva_resultante, canva1._largura, canva1._altura);
	
	// Criando novo canvas com a sobreposicao do canva1 e canva2
	for (int i = 0; i < canva1._altura; i++) // percorro as linhas
		for (int j = 0; j < canva1._largura; j++) { // percorro as colunas
			// Colocando canva1 -> canvaResultante
			if (canva1._pixels[i][j] != ' ') { // Se houver algo no canva1
				canva_resultante._pixels[i][j] = canva1._pixels[i][j]; 
				canva_resultante._cores[i][j] = canva1._cores[i][j];
			}
			// Colocando canva2 - > canvaResultante
			if (canva2._pixels[i][j] != ' ') { // Se houver algo no canva2
				canva_resultante._pixels[i][j] = canva2._pixels[i][j];
				canva_resultante._cores[i][j] = canva2._cores[i][j];
			}
		}
}

// Comparar Canvas
bool CompararCanvas(Canvas &canva1, Canvas &canva2){
	
	// Validacao - comparando dimensoes
	if (canva1._altura != canva2._altura || canva1._largura != canva2._largura)
		return false;
	
	// Validacao - comparando cores e pixels
	for (int i = 0; i < canva1._altura; i++) // percorro as linhas
		for (int j = 0; j < canva1._largura; j++) { // percorro as colunas
			if (canva1._pixels[i][j] != canva2._pixels[i][j])
				return false;
			else if (canva1._cores[i][j] != canva2._cores[i][j])
				return false;
		}
	
	// Se nao houve diferenca, sao iguais
	return true;
}