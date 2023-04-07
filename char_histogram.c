/* this program will ouput a histogram of words length in (-) format using all
 * 
 *
 *
 *      25 pages informations in C prgramming language second edition
 *
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h> //just a standard input/output library will be enough

#define MAX_WORDS 100 // max of words to input and operate
#define IN 1 // in word
#define OUT 0 // out of word

int main() {
	
	int c; //stores the value of getchar()
	int x, y; //operate (for loop)
	int state; //are inside a word or out the word
	int alphabets; //number of alphabets in each word  
	int n_word; //word
	int length[MAX_WORDS]; //integer array for the number of alphabet in each word
	n_word = alphabets = 0;
	state = OUT; //we start with state OUT which means we're not inside any word yet
	
	for (x = 0; x <= MAX_WORDS; x++)
		length[x] = 0;

	while ((c = getchar()) != '\n' && n_word < MAX_WORDS) {  //loop until we hit the end of file or the max of words (100)
		if (c == ' ' || c == '\t')        //if c represent blank space or tab or newline initialize the state to OUT
			         state = OUT;                 
		else if (n_word == 0) {  		     //start the operation after the first char, add new word, alphabet, and init...to IN 
			++n_word;			
			++alphabets;
			state = IN;			  
			}
		else if (state == IN)			//add only alphbets if we stayed in (IN state)
			++alphabets;
		else if (state == OUT) {		//set the number of alphabet to the specified position in the lengths array			 
			length[n_word] = alphabets;     //and add newword and set the the number of alphabets because we started a word to 1
			++n_word;			//and switch to the IN state
			alphabets = 1;
			state = IN;
			}
		}
	length[n_word] = alphabets;  			

	for (x = 1; x <= n_word; ++x) {			//printf the word position
		printf("%d: ", x);
		
		for (y = 0; y < length[x]; y++)       //putchar - as the number of alphabets per word
			putchar('-');
		putchar('\n');				//and newline to make it clear
	}
	return (0);
	}
