#pragma once
enum class Palo
{
	OROS, COPAS, ESPADAS, BASTOS
};

class Carta
{
public:
	size_t valor;
	int sprite;
	float px1, px2, py1, py2;
	Palo palo;
	bool onTouch(float posx, float posy);
	bool estaMostrandoValor;
	Carta();
	void setValor(size_t valor);
private:
	void AsignaPalo();
};

