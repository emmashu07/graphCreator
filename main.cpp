#include <iostream>
#include <cstring>

using namespace std;

void addVertex(int array[][20], int count);
void addEdge(int weight, int first, int second, int array[][20]);
void displayMatrix(char labels[], int array[][20], int count);
int toInt(char label, char labels[], int count);

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

			labels[count] = label;
			addVertex(array, count);
			displayMatrix(labels, array, count);
			count++;
		}
		else if (strcmp(input, "ADD EDGE") == 0) {
			char firstLabel;
			char secondLabel;
			int first;
			int second;
			int weight;

			cout << "Please enter the first label: ";
			cin >> firstLabel;
			cin.ignore(2, '\n');
			cout << "Please enter the second label: ";
			cin >> secondLabel;
			cin.ignore(2, '\n');
			cout << "Please enter the weight: ";
			cin >> weight;
			cin.ignore(2, '\n');


			first = toInt(firstLabel, labels, count);
			second = toInt(secondLabel, labels, count);
		
			addEdge(weight, first, second, array);
		
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

void displayMatrix(char labels[], int array[][20], int count) {
	for (int i = 0; i <= count; i++) {
		cout << '\t' << labels[i];
	}
	cout << endl;
	for (int i = 0; i <= count; i++) {
		cout << labels[i] << '\t';
		for (int j = 0; j <= count; j++) {
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
}

void addVertex(int array[][20], int count) {
	for (int i = 0; i <= count; i++) {
		array[i][count] = 0;
	}
	for (int i = 0; i <= count; i++) {
		array[count][i] = 0;
	}
}

int toInt(char label, char labels[], int count) {
	for (int i = 0; i <= count; i++) {
		if (label == labels[i]) {
			return i;
		}
	}
	return -1;
}

void addEdge(int weight, int first, int second, int array[][20]) {
	array[first][second] = weight;
}
