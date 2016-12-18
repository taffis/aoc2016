#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <set> 

using namespace std;

void exit(int x, int y, FILE* file) {
	fclose(file);
	cout << "result is: " << abs(x)+abs(y) << endl;
	exit(EXIT_SUCCESS);
}

int main(int argc, char* argv[])
{
	FILE* myfile;
	myfile = fopen(argv[1], "r");
	int orientation = 0;
	int x = 0;
	int y = 0;
	char c;
	int myDecimal = 0;

	set< pair<int,int> > myset;
	set< pair<int,int> >::iterator it;
  	pair<set< pair<int,int> >::iterator,bool> ret;
	ret = myset.insert(make_pair(0,0));
	
	while(fscanf(myfile, "%c", &c) != -1) {
		if(c == 'R') {
			orientation += 1;
			if(orientation > 3) orientation = 0;
		} else if(c == 'L') {
			orientation -= 1;
			if(orientation < 0) orientation = 3;
		} else break; //malformed input
 
		if(fscanf(myfile, "%d", &myDecimal) == -1) break;
		else if(orientation == 0) {
			for(int k = 0; k < myDecimal; k++) {
				y++;
				ret = myset.insert(make_pair(x,y));
				if(ret.second==false) exit(x,y,myfile);
			}
		} 	
		else if(orientation == 1) {
			for(int k = 0; k < myDecimal; k++) {
				x++;
				ret = myset.insert(make_pair(x,y));
				if(ret.second==false) exit(x,y,myfile);
			}
		}
		else if(orientation == 2) {
			for(int k = 0; k < myDecimal; k++) {
				y--;
				ret = myset.insert(make_pair(x,y));
				if(ret.second==false) exit(x,y,myfile);
			}
		}
		else if(orientation == 3) {
			for(int k = 0; k < myDecimal; k++) {
				x--;
				ret = myset.insert(make_pair(x,y));
				if(ret.second==false) exit(x,y,myfile);
			}
		}
		//read ',' and ' ' characters away
		fscanf(myfile, "%2c", &c);
	} 
	exit(x, y, myfile);
}
