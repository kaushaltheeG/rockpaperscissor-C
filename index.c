#include <stdio.h>
#include <stdlib.h>
/*
	1. get user's input
	2. com will return a randomize answer
	3. return com asnwer and user's victory status
*/


struct CHOICES {
	char rock;
	char paper;
	char scissor;
};
struct OUTCOMES {
	char win;
	char lose;
	char draw;
};
static char rpsarray[3] = {'r', 'p', 's'};
static struct CHOICES choices = {'r', 'p', 's'};
static struct OUTCOMES outcome = {'w', 'l', 'd'};

int generateBotAnswer() {
	int randomidx = rand() % 3; // generates key from 0-2
	return rpsarray[randomidx];
}

char userOutcome(char userinput, char botinput) {
	// win = w | draw = d | lost = l
	if (userinput == botinput) return outcome.draw;
	if (choices.rock == userinput) {
		if (choices.paper == botinput) return outcome.lose;
	} else if (choices.paper == userinput) {
		if (choices.scissor == botinput) return outcome.lose;
	} else {
		if (choices.rock == botinput) return outcome.lose;
	}
	return outcome.win;
}

int main() {
	// init struct
	// create function the will ask user a question and get answer; arg will be the question
	char userinput, botchoice;
	printf("Rock, Paper or Scissor?\n");
	printf("Enter r, p, or s\n");

	scanf("%c", &userinput);
	botchoice = generateBotAnswer();

	printf("You drew %c\n", userinput);
	printf("Bot drew %c\n", botchoice);
	char result = userOutcome(userinput, botchoice);
	if (outcome.win == result) {
		printf("Winner Winner Chicken Dinner!!!\n");
	} else if (outcome.draw == result) {
		printf("Draw!?! Boo!!\n");
	} else {
		printf("Loserrrrrrr!\n");
	}
	return 0;
}
