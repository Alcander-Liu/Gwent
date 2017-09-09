#ifndef CARDDATABASE_H
#define CARDDATABASE_H

#include "Card.h"
#include <QPushButton>
#include <QGraphicsPixmapItem>

#define SCALE (0.36)



class Card001: public Card // First Light
{
public:
    Card001(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/001_FisrtLight.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = false; //Not Loyal
        lane = -1; //None, special
        power = -1; //None
        cardNumber = 001;
        this->setScale(SCALE);
    }
};


class Card002: public Card // Biting Frost
{
public:
    Card002(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/002_BitingFrost.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = false; //DisLoyal
        lane = 0; //all
        power = -1; //None
        cardNumber = 002;
        this->setScale(SCALE);
    }
};


class Card003: public Card // Impenetrable Fog
{
public:
    Card003(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/003_ImpenetrableFog.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = false; //DisLoyal
        lane = 0; //all
        power = -1; //None
        cardNumber = 003;
        this->setScale(SCALE);
    }
};


class Card004: public Card // Torrential Rain
{
public:
    Card004(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/004_TorrentialRain.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = false; //DisLoyal
        lane = 0; //all
        power = -1; //None
        cardNumber = 004;
        this->setScale(SCALE);
    }
};


class Card005: public Card // Lacerate
{
public:
    Card005(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/005_Lacerate.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 2; //Rare
        loyalty = false; //DisLoyal, Loyal
        lane = 0; //all
        power = -1; //None
        cardNumber = 005;
        this->setScale(SCALE);
    }
};


class Card006: public Card // Full Moon Potion
{
public:
    Card006(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/006_FullMoonPotion.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = false; //DisLoyal
        lane = 0; //all
        power = -1; //None
        cardNumber = 006;
        this->setScale(SCALE);
    }
};


class Card007: public Card // Commanders Horn
{
public:
    Card007(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/007_CommandersHorn.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = false; //None
        lane = -1; //None, Special
        power = -1; //None
        cardNumber = 007;
        this->setScale(SCALE);
    }
};


class Card008: public Card // Bekkers Twisted Mirror
{
public:
    Card008(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/008_BekkersTwistedMirror.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = false; //None
        lane = -1; //None, Special
        power = -1; //None
        cardNumber = 8;
        this->setScale(SCALE);
    }
};


class Card009: public Card // Geralt Igni
{
public:
    Card009(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/009_GeraltIgni.png"))), parent)
    {
        level = 3; //Gold
        rarity = 4; //Legendary
        loyalty = true; //Loyal
        lane = 0; //all
        power = -1; //None
        cardNumber = 9;
        this->setScale(SCALE);
    }
};


class Card010: public Card // Dagon
{
public:
    Card010(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/010_Dagon.png"))), parent)
    {
        level = 4; //Leader
        rarity = 4; //Legendary
        loyalty = true; //Loyal
        lane = 0; //all
        power = 6;
        cardNumber = 010;
        this->setScale(SCALE);
    }
};


class Card011: public Card // Foglet
{
public:
    Card011(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/011_Foglet.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = 0; //all
        power = 4;
        cardNumber = 011;
        this->setScale(SCALE);
    }
};


class Card012: public Card // Geels
{
public:
    Card012(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/012_Geels.png"))), parent)
    {
        level = 3; //Gold
        rarity = 4; //Legendary
        loyalty = true; //Loyal
        lane = 0; //all
        power = 1;
        cardNumber = 012;
        this->setScale(SCALE);
    }
};


class Card013: public Card // Celaeno Harpy
{
public:
    Card013(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/013_CelaenoHarpy.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = 0; //all
        power = 5;
        cardNumber = 013;
        this->setScale(SCALE);
    }
};


class Card014: public Card // Harpy
{
public:
    Card014(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/014_Harpy.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 2; //Rare
        loyalty = true; //Loyal
        lane = 0; //all
        power = 3;
        cardNumber = 014;
        this->setScale(SCALE);
    }
};


class Card015: public Card // Woodland spirit
{
public:
    Card015(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/015_WoodlandSpirit.png"))), parent)
    {
        level = 3; //Gold
        rarity = 4; //Legendary
        loyalty = true; //Loyal
        lane = 0; //all
        power = 5;
        cardNumber = 015;
        this->setScale(SCALE);
    }
};


class Card016: public Card // Earth Elemental
{
public:
    Card016(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/016_EarthElemental.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = 1; //Melee
        power = 6;
        cardNumber = 016;
        this->setScale(SCALE);
    }
};


class Card017: public Card // Crone Weavess
{
public:
    Card017(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/017_CroneWeavess.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = true; //Loyal
        lane = 3; //Siege
        power = 6;
        cardNumber = 017;
        this->setScale(SCALE);
    }
};


class Card018: public Card // Crone Whipess
{
public:
    Card018(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/018_CroneWhipess.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = true; //Loyal
        lane = 3; //Siege
        power = 6;
        cardNumber = 18;
        this->setScale(SCALE);
    }
};


class Card019: public Card // Crone Brewess
{
public:
    Card019(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/019_CroneBrewess.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = true; //Loyal
        lane = 3; //Siege
        power = 8;
        cardNumber = 19;
        this->setScale(SCALE);
    }
};


class Card020: public Card // Archgriffin
{
public:
    Card020(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/020_Archgriffin.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = 0; //all
        power = 8;
        cardNumber = 020;
        this->setScale(SCALE);
    }
};


class Card021: public Card // Nithral
{
public:
    Card021(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/021_Nithral.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = true; //Loyal
        lane = 0; //all
        power = 5;
        cardNumber = 021;
        this->setScale(SCALE);
    }
};


class Card022: public Card // Caranthir
{
public:
    Card022(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/022_Caranthir.png"))), parent)
    {
        level = 3; //Gold
        rarity = 4; //Legendary
        loyalty = true; //Loyal
        lane = 0; //all
        power = 8;
        cardNumber = 022;
        this->setScale(SCALE);
    }
};


class Card023: public Card // Frightener
{
public:
    Card023(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/023_Frightener.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = false; //Disloyal
        lane = 0; //all
        power = 12;
        cardNumber = 023;
        this->setScale(SCALE);
    }
};


class Card024: public Card // Unseen Elder
{
public:
    Card024(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/024_UnseenElder.png"))), parent)
    {
        level = 4; //Leader
        rarity = 4; //Legendary
        loyalty = false; //None
        lane = 0; //all
        power = 5;
        cardNumber = 024;
        this->setScale(SCALE);
    }
};


class Card025: public Card // Arachas
{
public:
    Card025(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/025_Arachas.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = 2; //Ranged
        power = 3;
        cardNumber = 025;
        this->setScale(SCALE);
    }
};

class Card026: public Card // Vran Warrior
{
public:
    Card026(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/026_VranWarrior.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 2; //Rare
        loyalty = true; //Loyal
        lane = 0; //all
        power = 6;
        cardNumber = 026;
        this->setScale(SCALE);
    }
};


class Card027: public Card // Arachas Behemoth
{
public:
    Card027(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/027_ArachasBehemoth.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 2; //Rare
        loyalty = true; //Loyal
        lane = 3; //Siege
        power = 6;
        cardNumber = 027;
        this->setScale(SCALE);
    }
};


#endif // CARDDATABASE_H
