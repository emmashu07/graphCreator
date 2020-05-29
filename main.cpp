#include <iostream>
#include <cstring>

using namespace std;

void addVertex(int array[20][20], int count);
//void addEdge(int weight, char firstVertex, char secondVertex);
void displayMatrix(char labels[20], int array[20][20], int count);

int main() {
	int array[20][20];
	char labels[20];
	int count = 0;

	char input[20];
	bool running = true;

	while (running) {	
		cout << "Enter add vertex, add edge, remove vertex, remove edge, shortest path, or quit: ";
		cin.get(input, 20);
		cin.ignore(20, '\n');

		if (strcmp(input, "ADD VERTEX") == 0) {
			char label;
			cout << "Enter label (must be a character, e.g. A): ";
			cin >> label;
			cin.ignore(2, '\n');

			count++;
			labels[count] = label;
			addVertex(array, count);
			displayMatrix(labels, array, count);
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

void displayMatrix(char labels[20], int array[20][20], int count) {
	for (int i = 0; i < count; i++) {
		cout << '\t' << labels[i];
	}
	for (int i = 0; i < count; i++) {
		cout << labels[i] << '\t';
		for (int j = 0; j < count; j++) {
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
}

void addVertex(int array[20][20], int count) {
	for (int i = 0; i < count; i++) {
		array[count][i] = 0;
	}
}
