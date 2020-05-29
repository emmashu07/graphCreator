#include <iostream>
#include <cstring>

using namespace std;

//void addVertex(char name);
//void addEdge(int weight, char firstVertex, char secondVertex);

int main() {
	int array[20][20];
	char input[20];
	bool running = true;

	while (running) {	
		cout << "Enter add vertex, add edge, remove vertex, remove edge, shortest path, or quit: ";
		cin.get(input, 20);
		cin.ignore(20, '\n');
		if (strcmp(input, "ADD VERTEX") == 0) {
		
		}
		else if (strcmp(input, "ADD EDGE") == 0) {
		
		}
		else if (strcmp(input, "REMOVE EDGE") == 0) {
		
		}
		else if (strcmp(input, "REMOVE VERTEX") == 0) {
		
		}
		else if (strcmp(input, "SHORTEST PATH") == 0) {
		
		}
		else if (strcmp(input, "QUIT") == 0) {
			running = false;
		}
	}
	
	
	return 0;
}
