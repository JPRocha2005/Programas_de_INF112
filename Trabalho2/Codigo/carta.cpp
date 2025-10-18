#include "carta.hpp"
#include <string>

std::string Carta::getObjetivo() {
	return _objetivo;
}

void Carta::setObejtivo(std::string texto_objetivo) {
	_objetivo = texto_objetivo;
}