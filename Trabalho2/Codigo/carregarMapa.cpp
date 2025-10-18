#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

std::string *listaTodosTerritorios; 
std::string *numFronteirasPorTerritorio;
std::string **listaFronteirasPorTerritorio;

std::string *listaTodosContinentes;            
std::string *numTerritorioPorContinente;
std::string **listaTerritoriosContinentes;

std::string *listaTodosObjetivos;


void carregarMapa(const string &arquivo_territorios)
{
    ifstream arquivo(arquivo_territorios);
    if (!arquivo.is_open())
    {
        cout << "ERRO: Não foi possivel abrir o arquivo, verifique se o nome esta correto e se o arquivo está na pasta correta: " << arquivo_territorios << "\n";
        return;
    }

    string linha;
    int tamanho_das_entradas[4]; // contem o número de continentes, territórios, jogadores e objetivos respectivamente

	// tamanho_das_entradas[0] = continentes
	// tamanho_das_entradas[1] = territorio
	// tamanho_das_entradas[2] = jogadores
	// tamanho_das_entradas[3] = objetivos

    if (getline(arquivo, linha))
    {
        stringstream ss(linha);
        string item;
        int primeira_linha[4];
        int tam = 0;

        while (getline(ss, item, ','))
        {
            tamanho_das_entradas[tam] = stoi(item); // stoi - converte string para int
            tam++;
        }
    }
    listaTodosContinentes = new string[tamanho_das_entradas[0]];                               
    listaTodosTerritorios = new string[tamanho_das_entradas[1]];
	listaFronteirasPorTerritorio = new string*[tamanho_das_entradas[1]];
	listaTodosObjetivos = new string[tamanho_das_entradas[3]];
    numFronteirasPorTerritorio = new int[tamanho_das_entradas[1]];
    int contador_territorios = 0;                                               // Contador para facilitar o controle da inserção dos territórios nos arrays (territorios e fronteiras)
	
	int numero_de_jogadores = tamanho_das_entradas[2];                          // Número de jogadores, você irá utilizar essa informação no contrutor da classe Jogo
    int numero_de_territorios_por_continente[tamanho_das_entradas[0]];          // Para facilitar a inserção dos territórios na classe continente você pode utilizar esse array como referência

    int contador_continente = 0;
    while (getline(arquivo, linha)) // Leitura feita linha a linha, no caso aqui a leitura que está sendo feita é a da primeira linha
    {
        string continente, numero_de_territorios;
        if (linha.find(':') == string::npos && linha.find(',') != string::npos)
        {
            stringstream ss(linha);

            getline(ss, continente, ',');
            getline(ss, numero_de_territorios);
            continentes[contador_continente] = continente;

            numero_de_territorios_por_continente[contador_continente] = stoi(numero_de_territorios);

            contador_continente++;
        }

        else if (linha.find(':') != string::npos)
        {
            stringstream ss(linha);
            string territorio, fronteiras, fronteira;

            getline(ss, territorio, ':');

            listaTodosTerritorios[contador_territorios] = territorio;

            getline(ss, fronteiras);
            int numero_de_fronteiras = count(fronteiras.begin(), fronteiras.end(), ',') + 1;
            listaFronteirasPorTerritorio[contador_territorios] = new string[numero_de_fronteiras];
            numFronteirasPorTerritorio[contador_territorios] = numero_de_fronteiras;

            stringstream fs_filler(fronteiras);
            int contador_fronteira = 0;
            while (getline(fs_filler, fronteira, ','))
            {
                fronteiras_por_territorio[contador_territorios][contador_fronteira] = fronteira;
                contador_fronteira++;
            }
            contador_territorios++;
        }
    }

    int contador_objetivos = 0;
    while (getline(arquivo, linha))
    {
        if (!linha.empty())
        {
            listaTodosObjetivos[contador_objetivos] = linha;
            contador_objetivos++;
        }
    }

    arquivo.close();

    /** Testes de Leitura */
    /**CONTINENTES */
    for (int i = 0; i < tamanho_das_entradas[0]; i++)
    {
        cout << listaTodosContinentes[i] << " ";
    }
    cout << "\n ------------------------------------------ \n";
    /**TERRITORIOS */
    for (int i = 0; i < tamanho_das_entradas[1]; i++)
    {
        cout << listaTodosTerritorios[i] << ": ";
        /* FRONTEIRAS POR TERRITÓRIO*/
        for (int j = 0; j < numFronteirasPorTerritorio[i]; j++)
        {
            // cout << numero_de_fronteiras_por_territorio[i] << "\n";
            cout << listaFronteirasPorTerritorio[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n ------------------------------------------ \n";
    /**OBJETIVOS */
    for (int i = 0; i < tamanho_das_entradas[3]; i++)
    {
        cout << listaTodosObjetivos[i] << " ";
    }
    cout << "\n";

	/* Deletes */
	delete[] listaTodosContinentes;
	delete[] listaTodosTerritorios;
	delete[] numFronteirasPorTerritorio
	delete[] listaTodosObjetivos;
    for (int i = 0; i < tamanho_das_entradas[1]; i++)
    {
        delete[] listaFronteirasPorTerritorio[i];
    }
    delete[] listaFronteirasPorTerritorio;
}

using namespace std;
int main()
{

    carregarMapa("./territorios.txt"); // arquivo está no mesmo diretório que o código que faz a leitura

    return 0;
}