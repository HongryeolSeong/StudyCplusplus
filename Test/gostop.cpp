#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "cursor.h"		// gotoxy(), delay() �Լ� ��� ���� ���
#include <assert.h>
#include <iostream>
using namespace std;

// 1. ���� ������ ���� Ŭ����

// ���� ��ü�� ���� �Ǵ� �� ���� �ֿ� ���
const int MaxCard = 48;			// ��ü ȭ������ ����
const int CardGap = 4;			// ī�尣 ����
const int Speed = 1000;			// ī�� ���� ��� �ð� -> ��ü���� ���� ������ õõ�� ���� ����
const int PromptSpeed = 2000;	// �޽��� ��� ��� �ð�

// ���ӿ� �����ϴ� �繰
struct SCard
{
	char Name[4];
	SCard() { Name[0] = 0; }	// �ʱ�ȭ�� ������ �� û�� -> �̸� ���� �� ī�� ����
	SCard(const char* pName) 
	{	// ī�� �̸��� �޾� �ʱ�ȭ
		strcpy(Name, pName);
	}

	int GetNumber() const 
	{		// ȭ���� ���� üũ
		if (isdigit(Name[0])) return Name[0] - '0';
		if (Name[0] == 'J') return 10;
		if (Name[0] == 'D') return 11;
		return 12;
	}

	int GetKind() const 
	{		// ȭ���� ���� üũ
		if (strcmp(Name + 1, "��") == 0) return 0;
		else if (strcmp(Name + 1, "��") == 0) return 1;
		else if (strcmp(Name + 1, "��") == 0) return 2;
		else return 3;
	}

	// ī�� ����� ���� << ������
	friend ostream& operator <<(ostream& c, const SCard& C) 
	{
		return c << C.Name;
	}

	// �� ī�尡 ������ ���縦 ���� == ������
	bool operator ==(const SCard& Other) const 
	{
		return (strcmp(Name, Other.Name) == 0);
	}

	// �� ī���� ��Ҹ� ���ϴ� < ������
	bool operator <(const SCard& Other) const 
	{
		if (GetNumber() < Other.GetNumber()) return true;
		if (GetNumber() < Other.GetNumber()) return false;
		if (GetKind() < Other.GetKind()) return true;
		return false;
	}
};

// ȭ���� �ʱ� ī�� ���
SCard HwaToo[MaxCard] = {
	"1��","1��","1��","1��","2��","2��","2��","2��","3��","3��","3��","3��",
	"4��","4��","4��","4��","5��","5��","5��","5��","6��","6��","6��","6��",
	"7��","7��","7��","7��","8��","8��","8��","8��","9��","9��","9��","9��",
	"J��","J��","J��","J��","D��","D��","D��","D��","B��","B��","B��","B��"
};

// ī���� ������ �����ϴ� Ŭ����
class CCardSet
{
protected:
	SCard Card[MaxCard];
	int Num;				// ���տ� ���Ե� ī���� ���� ����
	const int sx, sy;		// ī�� ������ ȭ��� ��ǥ
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }

public:
	int GetNum() { return Num; }

	SCard GetCard(int idx) { return Card[idx]; }

	void Reset() 
	{
		for (int i = 0; i < MaxCard; i++)
		{
			Card[i].Name[0] = 0;
		}
		Num = 0;
	}

	// ī�� ������ �����ϴ� �Լ�
	void InsertCard(SCard C);
	SCard RemoveCard(int idx);
	int FindSameCard(SCard C, int* pSame);
	int FindFirstCard(const char* pName);
};

// �� ī�� ���� �ź� �� ��ȿ ī���� ���ĵ� ��ġ ����
void CCardSet::InsertCard(SCard C)
{
	int i;

	if (C.Name[0] == 0) return;

	for (i = 0; i < Num; i++)
	{
		if (C < Card[i]) break;
	}

	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));
	Card[i] = C;
	Num++;
}

// �ش� �ε����� ī�� ���� �� ����
SCard CCardSet::RemoveCard(int idx)
{
	assert(idx < Num);
	SCard C = Card[idx];
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--;
	return C;
}

// Cī��� ��ġ�ϴ� ī�� Ž��
int CCardSet::FindSameCard(SCard C, int* pSame)
{
	int i, num;
	int* p = pSame;

	for (i = 0, num = 0; i < Num; i++)
	{
		if (Card[i].GetNumber() == C.GetNumber())
		{
			num++;
			*p++ = i;
		}
	}
	*p = -1;
	return num;
}

// ���ڳ� ������ ��ġ�ϴ� ������ ī�� Ž�� �� �ε��� ����
int CCardSet::FindFirstCard(const char* pName)
{
	int i;

	for (i = 0; i < Num; i++)
	{
		if (strstr(Card[i].Name, pName) != NULL)
		{
			return i;
		}
	}

	return -1;
}

// ��ũ in �߾� ���
class CDeck : public CCardSet
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }

	// ������ ����
	void Shuffle()
	{
		int i, n;

		for (i = 0; i < MaxCard; i++)
		{
			do
			{
				n = random(MaxCard);
			} while (Card[n].Name[0] != NULL);
			Card[n] = HwaToo[i];
			Num++;
		}
	}

	SCard Pop() { return RemoveCard(Num - 1); }
	bool IsEmpty() { return Num == 0; }
	bool IsNotLast() { return Num > 1; }

	// ȭ�鿡 ��ũ �׸���
	void Draw(bool bFlip)
	{
		gotoxy(sx, sy);
		cout << "???" << (bFlip ? Card[Num - 1].Name : " ");
	}
};

// ������ �����ϴ� �÷��̾�
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }

	void Draw(bool MyTurn)
	{
		int i, x;

		for (i = 0, x= sx; i < Num; i++, x += CardGap)
		{
			gotoxy(x, sy);
			cout << Card[i];
			if (MyTurn)
			{
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

// �߾� ���
class CBlanket : public CPlayer
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }

	void Draw()
	{
		CPlayer::Draw(false);
	}

	void DrawSelNum(int* pSame)
	{
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++)
		{
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}

	void DrawTempCard(int idx, SCard C)
	{
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

// �÷��̾ ������ �ִ� ī���� ����
class CPlayerPae : public CCardSet
{
private:
	int nGo;

public:
	int OldScore;
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; }
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; }
	int GetGo() { return nGo; }
	void IncreaseGo() { nGo++; }
	void Draw();
	SCard RemovePee();
	int CalcScore();
};

// ������ �ִ� �и� ȭ�鿡 �������� ���
void CPlayerPae::Draw() 
{
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;

	for (i = 0; i < Num; i++) 
	{
		kind = Card[i].GetKind();

		if (kind < 3) 
		{
			gotoxy(x[kind], sy + kind);
			x[kind] += CardGap;
		}
		else 
		{
			gotoxy(x[3], py);
			x[3] += CardGap;
			if (x[3] > 75) 
			{
				x[3] = sx;
				py++;
			}
		}

		cout << Card[i];
	}
	gotoxy(sx + 23, sy);
	cout << "����:" << CalcScore() << "��, " << nGo << "��";
}

// ������ �� ���� �Ѳ����� �԰ų� �Ͼ������� ���
// �� �� ���� �����Ͽ� ���濡�� ��
SCard CPlayerPae::RemovePee() 
{
	int idx;

	idx = FindFirstCard("��");
	if (idx != -1) {
		return RemoveCard(idx);
	}
	return SCard();	// ���ϵ� ī��� ������ ���� �п� ����
}

// ���� ��Ģ��� ���� ���
int CPlayerPae::CalcScore() 
{
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 };

	for (i = 0; i < Num; i++) 
	{
		kind = Card[i].GetKind();
		n[kind]++;
	}
	NewScore = gscore[n[0]];
	if (n[0] == 3 && FindFirstCard("B��") != -1) NewScore--;
	if (n[1] >= 5) NewScore += (n[1] - 4);
	if (n[2] >= 5) NewScore += (n[2] - 4);
	if (n[3] >= 10) NewScore += (n[3] - 9);
	if (FindFirstCard("8��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("2��") != -1) NewScore += 5;
	if (FindFirstCard("1��") != -1 && FindFirstCard("2��") != -1 && FindFirstCard("3��") != -1) NewScore += 3;
	if (FindFirstCard("4��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("7��") != -1) NewScore += 3;
	if (FindFirstCard("9��") != -1 && FindFirstCard("J��") != -1 && FindFirstCard("6��") != -1) NewScore += 3;
	return NewScore;
}

// 2. ���� �
// ������ �������� ��� ���Ǵ� ���� ����
CDeck Deck(18, 9);
CPlayer South(5, 20), North(5, 1);
CBlanket Blanket(5, 12);
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);
bool SouthTurn;

// main�� ���� ��� �����ִ� ����� �Լ�
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

// ��ũ�� �и� �������� ���� ī�带 �ʱ�ȭ�ϴ� �Լ�
void Initialize()
{
	int i;

	Deck.Shuffle();
	for (i = 0; i < 10; i++) 
	{
		South.InsertCard(Deck.Pop());
		North.InsertCard(Deck.Pop());
		if (i < 8) Blanket.InsertCard(Deck.Pop());
	}
}

// ȭ���� ����� ��� ��ü�� Draw �Լ��� ���ʴ�� ȣ���Ͽ� �׸��� �Լ�
void DrawScreen()
{
	clrscr();
	South.Draw(SouthTurn);
	North.Draw(!SouthTurn);
	Blanket.Draw();
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

// ����ڿ��� �޼����� �����ְ� ��� ���
// ���� ���� �� ���� �ൿ ����
void OutPrompt(const char* Mes, int Wait/*=0*/)
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes;
	delay(Wait);
}

// ������ ������ ���� �ϳ��� �޴� �Լ�
int InputInt(const char* Mes, int start, int end)
{
	int ch;

	OutPrompt(Mes);
	for (;;) {
		ch = tolower(getch());
		if (ch == 0xE0 || ch == 0) 
		{
			ch = getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;
		if (ch == 'a') ch = 10; else ch = ch - '0';
		if (ch >= start && ch <= end) 
		{
			return ch;
		}
		OutPrompt("��ȿ�� ��ȣ�Դϴ�. ������ ������ �°� �ٽ� �Է��� �ּ���.");
	}
}

// �������� ������ �����ϴ� main()
int main()
{
	int i, ch;
	int arSame[4], SameNum;
	char Mes[256];
	CPlayer* Turn;
	CPlayerPae* TurnPae, * OtherPae;
	int UserIdx, UserSel, DeckSel;
	SCard UserCard, DeckCard;
	bool UserTriple, DeckTriple;
	int nSnatch;
	int NewScore;

	randomize();	// ���� �߻�
	Initialize();	// ī�� ���� �� �ʱ�ȭ

	// ���� ����
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) 
	{
		DrawScreen();
		if (SouthTurn) 
		{
			Turn = &South;
			TurnPae = &SouthPae;
			OtherPae = &NorthPae;
		}
		else 
		{
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		sprintf(Mes, "���� ���� ȭ���� �����ϼ���(1~%d,0:����) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());
		if (ch == 0) 
		{
			if (InputInt("���� �����̴ϱ�?(0:��,1:�ƴϿ�)", 0, 1) == 0)
				return;
			else
				continue;
		}

		// �÷��̾ ī�� �� �� ��
		UserTriple = DeckTriple = false;	// �ʱ����
		UserIdx = ch - 1;
		UserCard

	return 0;
}