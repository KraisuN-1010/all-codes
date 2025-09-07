import random

def calculate_hand_value(hand):
    """Calculate the best possible value for a hand, handling aces automatically."""
    total = 0
    aces = 0
    
    for card in hand:
        if card == 'A':
            aces += 1
            total += 11  # Start by counting ace as 11
        else:
            total += card
    
    # Convert aces from 11 to 1 if needed to avoid busting
    while total > 21 and aces > 0:
        total -= 10  # Convert an ace from 11 to 1
        aces -= 1
    
    return total

def display_card(card):
    """Display card in a readable format."""
    if card == 'A':
        return 'Ace'
    elif card == 10:
        return '10'
    else:
        return str(card)

def display_hand(hand):
    """Display a hand in readable format."""
    return [display_card(card) for card in hand]

def create_deck():
    """Create a standard deck of cards."""
    # 4 of each card (suits don't matter for blackjack)
    deck = ['A'] * 4 + [2] * 4 + [3] * 4 + [4] * 4 + [5] * 4 + [6] * 4 + \
           [7] * 4 + [8] * 4 + [9] * 4 + [10] * 16  # 16 ten-value cards (10, J, Q, K)
    random.shuffle(deck)
    return deck

def is_blackjack(hand):
    """Check if a hand is a natural blackjack (21 with exactly 2 cards)."""
    if len(hand) != 2:
        return False
    
    # Check if we have an ace and a 10-value card
    has_ace = 'A' in hand
    has_ten = 10 in hand
    
    return has_ace and has_ten

def computer_play(computer_hand, deck):
    """Computer plays according to standard dealer rules."""
    while calculate_hand_value(computer_hand) < 17:
        computer_hand.append(deck.pop())
    return computer_hand

def main():
    print("Welcome to Blackjack!")
    print("=" * 30)
    
    while True:
        # Create and shuffle deck
        deck = create_deck()
        
        # Deal initial cards
        player_hand = [deck.pop(), deck.pop()]
        computer_hand = [deck.pop(), deck.pop()]
        
        print(f"\nYour cards: {display_hand(player_hand)} (Value: {calculate_hand_value(player_hand)})")
        print(f"Dealer's showing: {display_card(computer_hand[0])}")
        
        # Check for natural blackjacks
        player_blackjack = is_blackjack(player_hand)
        computer_blackjack = is_blackjack(computer_hand)
        
        if player_blackjack and computer_blackjack:
            print(f"Dealer's cards: {display_hand(computer_hand)} (Value: {calculate_hand_value(computer_hand)})")
            print("Both have Blackjack! It's a push (tie)!")
        elif player_blackjack:
            print(f"Dealer's cards: {display_hand(computer_hand)} (Value: {calculate_hand_value(computer_hand)})")
            print("BLACKJACK! You win!")
        elif computer_blackjack:
            print(f"Dealer's cards: {display_hand(computer_hand)} (Value: {calculate_hand_value(computer_hand)})")
            print("Dealer has Blackjack! You lose!")
        else:
            # Player's turn
            while True:
                player_value = calculate_hand_value(player_hand)
                
                if player_value > 21:
                    print("You busted! You lose!")
                    break
                
                choice = input("Do you want to (h)it or (s)tand? ").lower().strip()
                
                if choice in ['h', 'hit']:
                    new_card = deck.pop()
                    player_hand.append(new_card)
                    print(f"You drew: {display_card(new_card)}")
                    print(f"Your cards: {display_hand(player_hand)} (Value: {calculate_hand_value(player_hand)})")
                elif choice in ['s', 'stand']:
                    break
                else:
                    print("Please enter 'h' for hit or 's' for stand.")
            
            # Computer's turn (only if player didn't bust)
            player_value = calculate_hand_value(player_hand)
            if player_value <= 21:
                print(f"\nDealer's cards: {display_hand(computer_hand)} (Value: {calculate_hand_value(computer_hand)})")
                
                computer_hand = computer_play(computer_hand, deck)
                computer_value = calculate_hand_value(computer_hand)
                
                print(f"Dealer's final cards: {display_hand(computer_hand)} (Value: {computer_value})")
                
                # Determine winner
                if computer_value > 21:
                    print("Dealer busted! You win!")
                elif player_value > computer_value:
                    print("You win!")
                elif player_value < computer_value:
                    print("Dealer wins!")
                else:
                    print("It's a push (tie)!")
        
        # Ask to play again
        while True:
            play_again = input("\nDo you want to play again? (y/n): ").lower().strip()
            if play_again in ['y', 'yes']:
                break
            elif play_again in ['n', 'no']:
                print("Thanks for playing!")
                return
            else:
                print("Please enter 'y' for yes or 'n' for no.")

if __name__ == "__main__":
    main()