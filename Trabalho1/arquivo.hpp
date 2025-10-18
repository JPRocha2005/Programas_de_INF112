// Cabeçalho - Trabalho 1
// Escrito por João Pedro - 13/09

#include <string>

// Colocar cor no terminal
std::string GetColorCode(char cor);

// Variavel Global - resetar a cor do terminal
const std::string RESET = GetColorCode(' '); 

struct Canvas {
	
// Dados
	int _largura;
	int _altura;
	char **_pixels ;
	char **_cores ;
};

// OPERAÇÕES - Canvas

// Funcoes Void
void CriarCanvas(Canvas &canvas, int largura, int altura);
void DestruirCanvas(Canvas &canvas);
void ImprimirCanvas(Canvas &canvas);
void DesenharPonto(Canvas &canvas, int coord_x, int coord_y, char simbolo, char cor);
void DesenharLinha(Canvas &canvas, int coord_x_inic, int coord_y_inic, int coord_x_fim, 
	int coord_y_fim, char simbolo, char cor);
void DesenharRetangulo(Canvas &canvas, int coord_x_origem, int coord_y_origem, int largura, 
	int altura, char simbolo, char cor);
void DesenharRetanguloPreenchido(Canvas &canvas, int coord_x_origem, int coord_y_origem, 
	int largura, int altura, char simbolo, char cor);
void Redimensionar(Canvas &canvas, int nova_altura, int nova_largura);
void SobreporCanvas(Canvas &canva_resultante, Canvas &canvas1, Canvas &canvas2);

// Funcao bool
bool CompararCanvas(Canvas &canvas1, Canvas &canvas2);
bool ValidarPonto(Canvas &canvas, int pos_x, int pos_y); 

