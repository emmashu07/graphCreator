/*
 * Emma Shu, 5/28/20: Graph creator creates an adjacency matrix that represents a graph.
 */

#include <iostream>
#include <cstring>

using namespace std;

// Functions.
void addVertex(int array[][20], int &count, char labels[], char label);
void addEdge(int weight, int first, int second, int array[][20]);
void removeVertex(int index, int &count, char labels[], int array[][20]);
void removeEdge(int first, int second, int array[][20]);
// Helper functions.
void display(char labels[], int array[][20], int count);
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

			addVertex(array, count, labels, label);
			display(labels, array, count);
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
			display(labels, array, count);
		
		}
		else if (strcmp(input, "REMOVE EDGE") == 0) {
			char firstLabel;
			char secondLabel;
			int first;
			int second;

			cout << "Please enter the first label: ";
			cin >> firstLabel;
			cin.ignore(2, '\n');
			cout << "Please enter the second label: ";
			cin >> secondLabel;
			cin.ignore(2, '\n');


			first = toInt(firstLabel, labels, count);
			second = toInt(secondLabel, labels, count);
		
			removeEdge(first, second, array);
			display(labels, array, count);

		}
		else if (strcmp(input, "REMOVE VERTEX") == 0) {
			char label;
			int index;
			cout << "Enter label (must be a character, e.g. A): ";
			cin >> label;
			cin.ignore(2, '\n');
			
			index = toInt(label, labels, count);

			removeVertex(index, count, labels, array);
			display(labels, array, count);
	
		}
		else if (strcmp(input, "SHORTEST PATH") == 0) {
		
		}
		else if (strcmp(input, "QUIT") == 0) {
			running = false;
		}
	}
	return 0;
}

void display(char labels[], int array[][20], int count) { // Displays the matrix.
	for (int i = 0; i < count; i++) {
		cout << '\t' << labels[i];
	}
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << labels[i] << '\t';
		for (int j = 0; j < count; j++) {
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
}

void addVertex(int array[][20], int &count, char labels[], char label) { // Adds an empty row and column to the ends of the matrix.
	labels[count] = label;
	for (int i = 0; i <= count; i++) {
		array[i][count] = 0;
	}
	for (int i = 0; i <= count; i++) {
		array[count][i] = 0;
	}
	count++;
}

int toInt(char label, char labels[], int count) { // Finds the label and returns its position in the matrix.
	for (int i = 0; i <= count; i++) {
		if (label == labels[i]) {
			return i;
		}
	}
	return -1;
}

void addEdge(int weight, int first, int second, int array[][20]) { // Adds an edge to the matrix.
	if (first < 0 || second < 0) {
		cout << "The vertex is not in the matrix." << endl;
	}
	else {
		array[first][second] = weight;
	}
}

void removeEdge(int first, int second, int array[][20]) { // Removes and edge from the matrix.
	if (first < 0 || second < 0) {
		cout << "The vertex is not in the matrix." << endl;
	}
	else {
		array[first][second] = 0;
	}
}

void removeVertex(int index, int& count, char labels[], int array[][20]) { // Removes the vertex by shifting the matrix.
	for (int i = 0; i < count; i++) {
		if (i >= index && i+1 != count) {
			labels[i] = labels[i+1];
		}
		else if (i+1 == count) {
			labels[i] = '\0';
		}
	}
	/*for (int i = 0; i < count; i++) {
		
		for (int j = 0; j < count; j++) {
			
		}
	}*/
	
		
}
