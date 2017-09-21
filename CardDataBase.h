#ifndef CARDDATABASE_H
#define CARDDATABASE_H

#include "Card.h"
#include <QPushButton>
#include <QGraphicsPixmapItem>

#define SCALE (0.33)


class Card001: public Card // First Light
{
public:
    Card001(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/001_FisrtLight.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = false; //Not Loyal
        lane = 0; //None, special
        power = -1; //None
        cardNumber = 1;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>First Light</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Special</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Spawn </b></font>Clear Skies or Rally. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card001(parent);
        return copy;
    }
};


class Card002: public Card // Biting Frost
{
public:
    Card002(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/002_BitingFrost.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = false; //DisLoyal
        lane = 0; //all
        power = -1; //None
        cardNumber = 2;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Biting Frost</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Biting Frost</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Apply Frost to a row on your opponent's side. Frost: Every turn, at the start of your turn, Damage the Lowest Unit on the row by 2. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card002(parent);
        return copy;
    }
};


class Card003: public Card // Impenetrable Fog
{
public:
    Card003(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/003_ImpenetrableFog.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = false; //DisLoyal
        lane = 0; //all
        power = -1; //None
        cardNumber = 3;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Impenetrable Fog</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Special, Weather</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Apply Fog to a row on your opponent's side. Fog: Every turn, at the start of your turn, Damage the Highest Unit on the row by 2. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card003(parent);
        return copy;
    }
};


class Card004: public Card // Torrential Rain
{
public:
    Card004(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/004_TorrentialRain.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = false; //DisLoyal
        lane = 0; //all
        power = -1; //None
        cardNumber = 4;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Torrential Rain</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Special, Weather</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Apply Rain to a row on your opponent's side. Rain: Every turn, at the start of your turn, Damage up to 2 random Units on the row by 1. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card004(parent);
        return copy;
    }
};


class Card005: public Card // Lacerate
{
public:
    Card005(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/005_Lacerate.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 2; //Rare
        loyalty = false; //DisLoyal, Loyal
        lane = 0; //all
        power = -1; //None
        cardNumber = 5;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Lacerate</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Special, Organic</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Damage</b></font> all Units on a row by 3.</font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card005(parent);
        return copy;
    }
};


class Card006: public Card // Thunderbolt Potion
{
public:
    Card006(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/006_ThunderboltPotion.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = false; //
        lane = 0; //all
        power = -1; //Special, None
        cardNumber = 6;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Thunderbolt Potion</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Special, Alchemy</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Add 2 Armor to 3 adjacent Units and Boost them by 3. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card006(parent);
        return copy;
    }
};


class Card007: public Card // Commanders Horn
{
public:
    Card007(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/007_CommandersHorn.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = false; //None
        lane = 0; //None, Special
        power = -1; //None
        cardNumber = 7;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Commander's Horn</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Special, Tactic</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Boost</b></font> 5 adjacent Units by 4.</font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card007(parent);
        return copy;
    }
};


class Card008: public Card // Bekkers Twisted Mirror
{
public:
    Card008(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/008_BekkersTwistedMirror.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = false; //None
        lane = 0; //None, Special
        power = -1; //None
        cardNumber = 8;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Bekkers Twisted Mirror</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Special, Spell</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Damage the Highest Unit by an amount equal to its Power, but no more than 10 (ignoring Armor) and Boost the Lowest other Unit by the same amount. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card008(parent);
        return copy;
    }
};


class Card009: public Card // Geralt Igni
{
public:
    Card009(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/009_GeraltIgni.png"))), parent)
    {
        level = 3; //Gold
        rarity = 4; //Legendary
        loyalty = true; //Loyal
        lane = -1; //all
        power = 5; //None
        cardNumber = 9;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Geralt: Igni</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Witcher</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font>Destroy all the Highest Units on the opposite row if that row totals 25 or more Power. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card009(parent);
        return copy;
    }
};


class Card010: public Card // Dagon
{
public:
    Card010(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/010_Dagon.png"))), parent)
    {
        level = 4; //Leader
        rarity = 4; //Legendary
        loyalty = true; //Loyal
        lane = -1; //all
        power = 6;
        cardNumber = 10;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Dagon</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Leader, Vodyanoi</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Doomed, Stubborn. Deploy: Spawn Biting Frost, Impenetrable Fog or Torrential Rain.</font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card010(parent);
        return copy;
    }
};


class Card011: public Card // Foglet
{
public:
    Card011(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/011_Foglet.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = -1; //all
        power = 4;
        cardNumber = 11;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Foglet</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Foglet</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Whenever you apply Fog to an opposing row, play a Foglet from your Deck on that row on your side. If there are no Foglets in your Deck, Resurrect a Foglet on that row on your side. When all Fog has been cleared from the Board, Destroy all Foglets. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card011(parent);
        return copy;
    }
};


class Card012: public Card // Geels
{
public:
    Card012(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/012_Geels.png"))), parent)
    {
        level = 3; //Gold
        rarity = 4; //Legendary
        loyalty = true; //Loyal
        lane = -1; //all
        power = 1;
        cardNumber = 12;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Ge'els</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Wild Hunt, Officer</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Draw the top Gold card and top Silver card from your Deck. Play one and return the other to the top of your Deck. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card012(parent);
        return copy;
    }
};


class Card013: public Card // Celaeno Harpy
{
public:
    Card013(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/013_CelaenoHarpy.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = -1; //all
        power = 5;
        cardNumber = 13;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Celaeno Harpy</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Beast</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Spawn 2 Harpy Eggs to the left of this Unit. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card013(parent);
        return copy;
    }
};


class Card014: public Card // Roach
{
public:
    Card014(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/014_Roach.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = true; //Loyal
        lane = -1; //all
        power = 4;
        cardNumber = 14;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Roach</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Beast</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Whenever you play a Gold card from your Hand (note: does not include Leaders), play Roach from your Deck on a random row before that card resolves. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card014(parent);
        return copy;
    }
};


class Card015: public Card // Woodland spirit
{
public:
    Card015(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/015_WoodlandSpirit.png"))), parent)
    {
        level = 3; //Gold
        rarity = 4; //Legendary
        loyalty = true; //Loyal
        lane = -1; //all
        power = 5;
        cardNumber = 15;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Woodland spirit</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Relict</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Spawn 3 Rabid Wolves and apply Fog to the opposite row. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card015(parent);
        return copy;
    }
};


class Card016: public Card // Earth Elemental
{
public:
    Card016(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/016_EarthElemental.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = 1; //Melee
        power = 6;
        cardNumber = 16;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Earth Elemental</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Construct</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Give this Unit a Shield. Deathwish: Spawn 2 Lesser Earth Elementals at the end of the row. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card016(parent);
        return copy;
    }
};


class Card017: public Card // Crone Weavess
{
public:
    Card017(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/017_CroneWeavess.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = true; //Loyal
        lane = 3; //Siege
        power = 6;
        cardNumber = 17;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Crone: Weavess</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Mage, Relict</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Play Brewess and Whispess from your Deck. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card017(parent);
        return copy;
    }
};


class Card018: public Card // Crone Whipess
{
public:
    Card018(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/018_CroneWhipess.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = true; //Loyal
        lane = 3; //Siege
        power = 6;
        cardNumber = 18;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Crone: Whispess </font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Mage, Relict</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Play Brewess and Weavess from your Deck. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card018(parent);
        return copy;
    }
};


class Card019: public Card // Crone Brewess
{
public:
    Card019(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/019_CroneBrewess.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = true; //Loyal
        lane = 3; //Siege
        power = 8;
        cardNumber = 19;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Crone: Brewess</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Mage, Relict</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Play Whispess and Weavess from your Deck. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card019(parent);
        return copy;
    }
};


class Card020: public Card // Archgriffin
{
public:
    Card020(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/020_Archgriffin.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = -1; //all
        power = 8;
        cardNumber = 20;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Archgriffin</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Beast</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Clear Weather from the row on your side. Move a Bronze card from one Graveyard to the other.</font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card020(parent);
        return copy;
    }
};


class Card021: public Card // Wild Hunt Rider
{
public:
    Card021(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/021_WildHuntRider.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = -1; //all
        power = 8;
        cardNumber = 21;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Wild Hunt Rider</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Wild Hunt, Soldier</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Increase by 1 the <font color = white><b>Damage</b></font> dealt by Frost on the opposite row.</font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card021(parent);
        return copy;
    }
};


class Card022: public Card // Caranthir
{
public:
    Card022(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/022_Caranthir.png"))), parent)
    {
        level = 3; //Gold
        rarity = 4; //Legendary
        loyalty = true; //Loyal
        lane = -1; //all
        power = 8;
        cardNumber = 22;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Caranthir</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Wild Hunt, Mage</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Move an <font color = white><b>Enemy</b></font> to this row on its side and apply Frost to that row.</font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card022(parent);
        return copy;
    }
};


class Card023: public Card // Frightener
{
public:
    Card023(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/023_Frightener.png"))), parent)
    {
        level = 2; //Silver
        rarity = 3; //Epic
        loyalty = false; //Disloyal
        lane = -1; //all
        power = 12;
        cardNumber = 23;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Caranthir</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Wild Hunt, Mage</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Move an <font color = white><b>Enemy</b></font> to this row on its side and apply Frost to that row.</font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card023(parent);
        return copy;
    }
};


class Card024: public Card // Unseen Elder
{
public:
    Card024(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/024_UnseenElder.png"))), parent)
    {
        level = 4; //Leader
        rarity = 4; //Legendary
        loyalty = false; //None
        lane = -1; //all
        power = 5;
        cardNumber = 24;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Caranthir</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Wild Hunt, Mage</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Move an <font color = white><b>Enemy</b></font> to this row on its side and apply Frost to that row.</font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card024(parent);
        return copy;
    }
};


class Card025: public Card // Arachas
{
public:
    Card025(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/025_Arachas.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 1; //Common
        loyalty = true; //Loyal
        lane = 2; //Ranged
        power = 3;
        cardNumber = 25;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Arachas</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Insectoid</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy:</b></font> Play all Arachasae from your Deck. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card025(parent);
        return copy;
    }
};

class Card026: public Card // Vran Warrior
{
public:
    Card026(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/026_VranWarrior.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 2; //Rare
        loyalty = true; //Loyal
        lane = -1; //all
        power = 6;
        cardNumber = 26;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Vran Warrior</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Draconid</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold><font color = white><b>Deploy: Consume</b></font> the Unit to the right. Every 2 turns, at the start of your turn, Consume the Unit to the right. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card026(parent);
        return copy;
    }
};


class Card027: public Card // Arachas Behemoth
{
public:
    Card027(QObject *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/027_ArachasBehemoth.png"))), parent)
    {
        level = 1; //Bronze
        rarity = 2; //Rare
        loyalty = true; //Loyal
        lane = 3; //Siege
        power = 6;
        cardNumber = 27;
        this->setScale(SCALE);
        name = "<font color = white size = 4 face = HalisGR-Bold>Arachas Behemoth</font>";
        remark = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Insectoid</font>";
        skill = "<font color = #a8a8a8 size = 2 face = HalisGR-Bold>Whenever an Ally Consumes a card, Spawn an Arachas Hatchling on a random row and Damage self by 1 (ignoring Armor). Deploy: Gain 2 Armor. </font> ";
    }

    Card * makeCopy(QObject *parent = nullptr)
    {
        Card *copy = new Card027(parent);
        return copy;
    }
};

extern Card* newCard( int cardNumber,QObject *parent = nullptr);

#endif // CARDDATABASE_H
