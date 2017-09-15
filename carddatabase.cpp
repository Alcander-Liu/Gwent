#include "carddatabase.h"
Card* newCard(int cardNumber,QObject *parent)
{
    Card *temp = nullptr;
    if(cardNumber > 13)
    {
        if(cardNumber > 20)
        {
            switch(cardNumber)
            {
            case 21:
                temp = new Card021(parent);
                break;
            case 22:
                temp = new Card022(parent);
                break;
            case 23:
                temp = new Card023(parent);
                break;
            case 24:
                temp = new Card024(parent);
                break;
            case 25:
                temp = new Card025(parent);
                break;
            case 26:
                temp = new Card026(parent);
                break;
            case 27:
                temp = new Card027(parent);
                break;
            }
        }
        else
        {
            switch(cardNumber)
            {
            case 14:
                temp = new Card014(parent);
                break;
            case 15:
                temp = new Card015(parent);
                break;
            case 16:
                temp = new Card016(parent);
                break;
            case 17:
                temp = new Card017(parent);
                break;
            case 18:
                temp = new Card018(parent);
                break;
            case 19:
                temp = new Card019(parent);
                break;
            case 20:
                temp = new Card020(parent);
                break;
            }
        }
    }
    else
    {
        if(cardNumber >6)
        {
            switch(cardNumber)
            {
            case 7:
                temp = new Card007(parent);
                break;
            case 8:
                temp = new Card008(parent);
                break;
            case 9:
                temp = new Card009(parent);
                break;
            case 10:
                temp = new Card010(parent);
                break;
            case 11:
                temp = new Card011(parent);
                break;
            case 12:
                temp = new Card012(parent);
                break;
            case 13:
                temp = new Card013(parent);
                break;
            }
        }
        else
        {
            switch(cardNumber)
            {
            case 1:
                temp = new Card001(parent);
                break;
            case 2:
                temp = new Card002(parent);
                break;
            case 3:
                temp = new Card003(parent);
                break;
            case 4:
                temp = new Card004(parent);
                break;
            case 5:
                temp = new Card005(parent);
                break;
            case 6:
                temp = new Card006(parent);
                break;
            }
        }
    }
    return temp;
}
