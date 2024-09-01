#include <ncurses.h>
void init(void){
	initscr();
	raw();
	cbreak();
	noecho();
}
int main(void){
	init();
	while(1){
		int c = getch();
		clear();
		printw("%d",c);
		refresh();
	}
	return 0;
}
