// ConsoleDraw.cpp : Draws simple figures on console screen.
//

#include "stdafx.h"

#define power2f(x) (float((x)*(x)))

const wchar_t *menu = 
	L"Melyik alakzatot rajzoljam fel:	\n" \
	L"1. Téglalap						\n" \
	L"2. Háromszög						\n" \
	L"3. Kör							\n" \
	L"Alakzat száma: ";

void clear_input_stream(void)
{
	fflush(stdin);
}

int print_question(const wchar_t *question)
{
	wchar_t line[8];
	wprintf(question);

	wchar_t* answer = _getws_s(line);
	int retn = _wtoi(answer);
	clear_input_stream();

	return retn;
}

void draw_rectangle(void)
{
	int height = print_question(L"Milyen magas legyen: ");
	int width = print_question(L"Milyen széles legyen: ");

	for (int h = 1; h <= height; h++)
	{
		for (int w = 1; w <= width; w++)
		{
			if (w == 1 || w == width || h == 1 || h == height)
			{
				putwchar('*');
			} else {
				putwchar(' ');
			}
		}

		putwchar('\n');
	}
}

void draw_triangle(void)
{
	int height = print_question(L"Milyen magas legyen: ");
	int width = height == 1 ? 1 : height == 2 ? 3 : height * 2 - 1;
	
	for (int h = 1; h <= height; h++)
	{
		for (int w = 1; w <= width; w++)
		{
			if (h == 1 || w == h || w == width - h + 1)
			{
				putwchar('*');
			} else {
				putwchar(' ');
			}
		}

		putwchar('\n');
	}
}

void draw_circle(void)
{
	int radius = print_question(L"Mekkora sugara legyen: ");
	
	for (int h = 1; h <= 2*radius+1; h++)
	{
		for (int w = 1; w <= 2*radius+1; w++)
		{

			double distance = sqrt(power2f(h - radius - 1) + power2f(w - radius - 1));
			if ((radius-0.5 < distance && distance < radius+0.5))
			{
				putwchar('*');
			}
			else
			{
				putwchar(' ');
			}
		}

		putwchar('\n');
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");

	int answer = print_question(menu);
	switch (answer)
	{
	case 1:
	default:
		draw_rectangle();
		break;
	case 2:
		draw_triangle();
		break;
	case 3:
		draw_circle();
		break;
	}
	getwchar();

	return 0;
}