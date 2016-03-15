#include <iostream>
#include <time.h>

using namespace std;

/******************************************
 *		  COLORAÇÂO DO CARACTERES		  */
const std::string RED("\033[0;31m");
const std::string GREEN("\033[1;32m");
const std::string YELLOW("\033[1;33m");
const std::string CYAN("\033[0;36m");
const std::string MAGENTA("\033[0;35m");
const std::string RESET("\033[0m");
/******************************************/

inline int abs(int n) { return n > 0 ? n : -n; }
inline int round(float n) { return (int) (n + 0.5); }

int size;
bool** buffer;
unsigned long long times;

void drawLineDDA_(bool out, int xa, int ya, int xb, int yb)
{
	int dx = xb - xa,
		dy = yb - ya;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float	xIncrement = dx / (float) steps,
			yIncrement = dy / (float) steps,
			x = xa,
			y = ya;

	if (out) cout << "dx: " << dx << "\tdy: " << dy << "\tsteps: " << steps << endl;
	if (out) cout << "xInc: " << xIncrement << "\tyInc: " << yIncrement << endl;

	if (out) cout << "x: " << round(x) << "\ty: " << round(y) << endl;
	buffer[round(y)][round(x)] = true;;

	for (int k = 0; k < steps; k++)
	{
		x += xIncrement;
		y += yIncrement;

		if (out) cout << "x: " << round(x) << "\ty: " << round(y) << endl;
		buffer[round(y)][round(x)] = true;
	}
}

float drawLineDDA(int xa, int ya, int xb, int yb)
{
	time_t t1; time(&t1);
	
	drawLineDDA_(true, xa, ya, xb, yb);
	for (unsigned long long i = 1; i < times; i++)
		drawLineDDA_(false, xa, ya, xb, yb);
	
	time_t t2; time(&t2);
	return t2 - t1;
}

void drawLineBres_(bool out, int xa, int ya, int xb, int yb, bool inverted)
{
	int dx = xb - xa,
		dy = yb - ya,
		slope;
	
	if (xa > xb)
		return drawLineBres_(out, xb, yb, xa, ya, inverted);
	if (abs(dy) > abs(dx))
		return drawLineBres_(out, ya, xa, yb, xb, ! inverted);

	if (dy < 0)
	{
		slope = -1;
		dy = -dy;
	}
	else slope = 1;

	int incE = 2 * dy,
		incNE = 2 * (dy - dx),
		p = 2 * dy - dx;

	if (out) cout << "dx: " << (inverted ? dy : dx) << "\tdy: " << (inverted ? dx : dy) << endl;
	if (out) cout << "incE: " << incE << "\tincNE: " << incNE << endl;

	for (; xa <= xb; xa++)
	{
		if (out) cout << "p: " << p << "\tx: " << (inverted ? ya : xa) << "\ty: " << (inverted ? xa : ya) << endl;

		if (inverted)
			buffer[xa][ya] = true;
		else
			buffer[ya][xa] = true;

		if (p < 0)
			p += incE;
		else {
			p += incNE;
			ya += slope;
		}
	}
}

float drawLineBres(int xa, int ya, int xb, int yb)
{
	time_t t1; time(&t1);
	
	drawLineBres_(true, xa, ya, xb, yb, false);
	for (unsigned long long i = 1; i < times; i++)
		drawLineBres_(false, xa, ya, xb, yb, false);
	
	time_t t2; time(&t2);
	return t2 - t1;
}

void drawLine_(bool out, int xa, int ya, int xb, int yb, bool reversed)
{
	int dx = xb - xa,
		dy = yb - ya;

	if (out) cout << "dx: " << dx << "\tdy: " << dy << endl;

	if (abs(dx) >= abs(dy))
	{	
		double	m = (double) (yb - ya) / (xa - xb),
				y = ya;
		double	yInc = (dy > 0 ? 1 : -1) * (m > 0 ? m : -m);
		int 	xInc = dx > 0 ? 1 : -1;

		if (out) cout << "m: " << m << "\txInc: " << xInc << "\tyInc: " << yInc << endl;

		for (; dx > 0 ? xb > xa : xb < xa; xa += xInc)
		{
			if (out) cout << "x: " << xa << "\ty: " << y << endl;
			if (reversed)
				buffer[xa][(int) y] = true;
			else
				buffer[(int) y][xa] = true;

			y += yInc;
		}

		if (out) cout << "x: " << xa << "\ty: " << y << endl;
		if (reversed)
			buffer[xa][(int) y] = true;
		else
			buffer[(int) y][xa] = true;
	}
	else return drawLine_(out, ya, xa, yb, xb, ! reversed);
}

float drawLine(int xa, int ya, int xb, int yb)
{
	time_t t1; time(&t1);

	drawLine_(true, xa, ya, xb, yb, false);
	for (unsigned long long i = 1; i < times; i++)
		drawLine_(false, xa, ya, xb, yb, false);
	
	time_t t2; time(&t2);
	return t2 - t1;
}

void clear() 
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			buffer[i][j] = false;
}

void display()
{
	for (int i = size - 1; i >= 0; i--) {
		cout << RED << (i < 10 ? " " : "") << i << RESET;

		for (int j = 0; j < size; j++)
			if (buffer[i][j])
				cout << " o";
			else
				cout << MAGENTA << " ." << RESET;
		cout << endl;
	}

	cout << "  " << RED;
	for (int i = 0; i < size; i++)
		cout << (i < 10 ? " " : "") << i;
	cout << RESET << endl << endl;
}

/* Exemplo de uso:
 * Tamanho: 30			# Cria um buffer de tamanho 30x30
 * Pontos: 4 19 9 13	# Mostra gráfico da reta que vai do ponto (4, 19) ao (9, 13)
 * 						# Pontos no formato (x, y) */
int main()
{
	cout << "Repetições: ";
	cin >> times;

	cout << "Tamanho (largura/altura): ";
	cin >> size;

	buffer = new bool*[size];
	for (int i = 0; i < size; i++)
		buffer[i] = new bool[size];	

	int xa, ya, xb, yb;
	cout << "Pontos (xa xb ya yb): ";
	cin >> xa >> ya >> xb >> yb;
	cout << endl;

	cout << "Equação da reta:" << endl;
	clear();
	cout << "time: " << drawLine(xa, ya, xb, yb) << endl;
	display();

	cout << "DDA:" << endl;
	clear();
	cout << "time: " << drawLineDDA(xa, ya, xb, yb) << endl;
	display();

	cout << "Bresenham:" << endl;
	clear();
	cout << "time: " << drawLineBres(xa, ya, xb, yb) << endl;
	display();

	return 0;
}