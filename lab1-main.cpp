#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <list>

using namespace std;


list<string> GetDataFromFile(string path) {
	ifstream file(path);
	list<string> data;
	if (!file.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		string str;
		while (getline(file, str)) {
			data.push_back(str);
		}
	}
	return data;
}
list<int> getNumbersFromList(list<string> ls) {
	list<int> nums;
	while (!ls.empty()) {
		string str = ls.front();
		string numStr;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ' || i == str.size() - 1) {
				if (i == str.size() - 1) {
					numStr += str[i];
				}
				nums.push_back(stoi(numStr));
				numStr = "";
			}
			else {
				numStr += str[i];
			}
		}

		ls.pop_front();
	}
	return nums;
}


void printArray(int* arr, const int size) {
	cout << "elements of an array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n\n";
}

void fillArrayStaticRandom(int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 21 - 10;
	}
}
void fillArrayFromConsole(int* arr, const int size) {
	cout << "input elements for help probil or every element from a new line: (size of the array - " << size << "): ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
}
int findMaxElemBetweenNegative(int* arr, const int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) {
			max = arr[i];
			break;
		}
	}
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0 && arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
int findIndexMaxElement(int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == findMaxElemBetweenNegative(arr, size)) return i;
	}
}

void control(int choice, int* arr, const int size) {
	if (choice < 0 || choice > 2) {
		cout << "uncorrect choice. Error! try one more time\n";
		int newChoice;
		cin >> newChoice;
		control(newChoice, arr, size);
	}
	else {
		if (choice == 0) {
			fillArrayStaticRandom(arr, size);

		}
		else if (choice == 1) {
			fillArrayFromConsole(arr, size);
		}
		else {
			string path = "C:/Users/Home/Desktop/";
			string nameFile;
			cout << "input a name file which exists on the Desktop: \n";
			cin.get();
			getline(cin, nameFile);
			path += nameFile;
			list<int> ls = getNumbersFromList(GetDataFromFile(path));
			for (int i = 0; i < size; i++) {
				arr[i] = ls.front();
				ls.pop_front();
			}

		}
	}
}


void controlTask(int taskNumber, int* arr, const int size) {
	if (taskNumber == 1) {
		cout << "task 1:\nmax element between negative elements of the array: " << findMaxElemBetweenNegative(arr, size) << endl;
		cout << "its index: " << findIndexMaxElement(arr, size) << endl;
	}
	else if (taskNumber == 2) {
		int b, min, a, indexA;
		cout << "input number b1: \n";
		cin >> b;
		cout << "input a: \n";
		cin >> a;
		for (int i = 0; i < size; i++) {
			if (arr[i] > a) {
				indexA = i;
				break;
			}
		}
		for (int i = 0; i < size; i++) {
			if (arr[i] < b) {
				min = arr[i];
				break;
			}
		}
		for (int i = 0; i < indexA; i++) {
			if (arr[i] < b && min > arr[i]) {
				min = arr[i];
			}
		}
		cout << "result value: " << min << "\n";
	}
	else if (taskNumber == 3) {
		int countPoints = 0; 
		int r;
		cout << "input radius of the circle: \n"; 
		cin >> r; 
		for (int i = 0; i < size; i++) {
			int pointX = arr[2 * i]; 
			int pointY = arr[2 * i + 1]; 
			int distance = pow(pow(pointX, 2) + pow(pointY, 2), 0.5); // coords of beginning are (0, 0) then there is no need to code it
			if (distance <= r) countPoints++; 
		}
		cout << "count points in the circle: " << countPoints << endl; 
	}
	printArray(arr, size);
}
void main() {
	srand(time(NULL));
	int methodFilling, task;
	cout << "input a method of filling an array: \n0 - filling random numbers\n1 - filling from console\n2 - filling from file\n";
	cin >> methodFilling;

	const int N = 10; // static size for array
	int arr[N]; // random numbers will be used for filling static array
	cout << "choose task (1, 2, 3): " << endl;
	cin >> task;
	vector<int> vec;
	for (int i = 0; i < N; i++) { // copy elements to the and vector to not repeat code (working with vector)
		vec.push_back(arr[i]);
	}
	if (task == 3) {
		int g;
		cout << "input size of a dynamic array: " << endl;
		cin >> g;
		while (g > 200 || g < 1) {
			cout << "try again, size of an array: \n"; 
			cin >> g; 
		}
		int* pArr = new int[g];
		control(methodFilling, pArr, g);
		controlTask(task, pArr, g);
	}
	else {
		control(methodFilling, arr, N);
		controlTask(task, arr, N);
	}

}
// in this part of lab work is used static array, also there is lab with using vector, it has done for 3 task