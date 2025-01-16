#include <iostream>
#include <string>
using namespace std;
class DynamicArray {
private:
	int size, capacity;
	string* array;
	void resize() {
		capacity *= 2;
		string* narray = new string[capacity];
		for (int i = 0; i < size; i++) {
			narray[i] = array[i];
		}
		delete[] array;
		array = narray;
	}
public:

	DynamicArray() : size(0), capacity(10), array(new string[capacity]) {}
	~DynamicArray() {
		delete[] array;
	}
	bool insert(string newElement, int position) {
		if (position < 0 || position > size) {
			return false;
		}
		if (size == capacity) {
			resize();
		}
		size++;
		for (int i = size; i > position; i--) {
			array[i] = array[i - 1];
		}
		array[position] = newElement;
		return true;
	}
	bool remove(int position) {
		if (position < 0 || position > size) {
			return false;
		}
		for (int i = position; i < size; i++) {
			array[i] = array[i + 1];
		}
		size--;
		return true;
	}
};
int main() {
	DynamicArray a;

}
