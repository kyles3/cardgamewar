#include <vector>
#include <cstdlib>
#include "player.h"
#include <iomanip> 

using namespace std;

// default constructor
Player::Player() // need to specify the class name
{
    numCards = 0;
};

// alternative constructor
Player::Player(vector<Card> ini_cards) // need to specify the class name
{
    numCards = ini_cards.size();
    cards.insert(cards.begin(), ini_cards.begin(), ini_cards.end());
};

// return how many cards player holds currently
int Player::getNumCards() const // need to specify the class name
{
    return numCards;
};

// player plays one card from the front of cards at hand
Card Player::play_a_card()
{
    Card playerCard = cards.front();
    cards.pop_front();
    numCards--;
    return playerCard;
};

// when the player wins the round, this function will be called
// player adds winning cards to the end of the cards at hand
void Player::addCards(vector<Card> winningCards)
{
    cards.insert(cards.end(), winningCards.begin(), winningCards.end());
    numCards += winningCards.size();
};

// when there is a tie, this function will be called
// player drops THREE cards from the front of cards at hand
vector<Card> Player::dropCards()
{
    vector<Card> droppedCards;
    for(int i=0; i<3; i++){
        droppedCards.push_back(cards.front());
        cards.pop_front();
        numCards--;
    }
    return droppedCards;
};

void Player::print() const {
    cout << "Player's hand: ";
    for (list<Card>::const_iterator i = cards.begin(); i != cards.end(); i++) {
        cout << i->getSuit() << "-";
        int rank = i->rank();
        if (rank == 14) {
            cout << "A";
        } else if (rank == 11) {
            cout << "J";
        } else if (rank == 12) {
            cout << "Q";
        } else if (rank == 13) {
            cout << "K";
        } else {
            cout << rank;
        }
        cout << " ";
    }
    cout << endl;
}
