#include "graphics.h"
#include <conio.h>

class Hinh
{
private:
	int mau;

public:
	Hinh(int m)
	{
		this->mau = m;
	}
	int getMau()
	{
		return mau;
	}
	virtual void draw(int x, int y) = 0;
};

class Dthang : public Hinh
{
private:
	int dodai;

public:
	Dthang(int mau, int dodai) : Hinh(mau)
	{
		this->dodai = dodai;
	}
	virtual void draw(int x, int y)
	{
		setcolor(getMau());
		line(x, y, x + dodai, y);
	}
};

class ChuNhat : public Hinh
{
private:
	int rong, cao;

public:
	ChuNhat(int mau, int rong, int c) : Hinh(mau)
	{
		this->rong = rong;
		this->cao = cao;
	}

	virtual void draw(int x, int y)
	{

		setcolor(getMau());
		rectangle(x, y, x + rong, y + cao);
		setfillstyle(1, getMau());
		floodfill(x + rong / 2, y + cao / 2, getMau());
	}
};

class Vuong : public ChuNhat
{
public:
	Vuong(int a, int m) : ChuNhat(a, a, m)
	{
	}
};

class HTron : public Hinh
{
private:
	int bk;

public:
	HTron(int mau, int bk) : Hinh(mau)
	{
		this->bk = bk;
	}

	virtual void draw(int x, int y)
	{

		setcolor(getMau());
		circle(x + bk, y + bk, bk);
		setfillstyle(1, getMau());
		floodfill(x + bk, y + bk, getMau());
	}
};

class picture
{

private:
	Hinh *h[4];

public:
	picture(Hinh *h0, Hinh *h1, Hinh *h2, Hinh *h3)
	{
		this->h[0] = h0;
		this->h[1] = h1;
		this->h[2] = h2;
		this->h[3] = h3;
	}

	void paint(int *k);
	void listpaint();
};

void picture::paint(int *k)
{
	for (int i = 0; i < 4; i++)
	{
		h[k[i]]->draw(10 + i * 150, 200);
	}
}

void picture::listpaint()
{

	int k[4] = {};
	for (int i1 = 0; i1 < 4; i1++)
		for (int i2 = 0; i2 < 4; i2++)
			if (i2 != i1)
				for (int i3 = 0; i3 < 4; i3++)
					if (i3 != i2 && i3 != i1)
						for (int i4 = 0; i4 < 4; i4++)
							if (i4 != i3 && i4 != i2 && i4 != i1)
							{
								k[0] = i1;
								k[1] = i2;
								k[2] = i3;
								k[3] = i4;
								paint(k);
								getch();
								cleardevice();
							}

	Dthang dt(120, 14);
	HTron ht(60, RED);
	ChuNhat cn(120, 100, MAGENTA);
	Vuong v(120, CYAN);
};

int main()
{

	int mh = 0, mode = 0;
	initgraph(&mh, &mode, "");
	// picture pic(&dt, &ht, &cn, &v);
	// pic.listpaint();
	getch();
	closegraph();

	return 0;
}
