#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Animal.cpp"
#include "Zoo.hpp"

void print(Animal* animal);

// ���� ������ �����ϴ� �Լ�
// - 0, 1, 2 �� �ϳ��� ������ �����Ͽ� ���� Dog, Cat, Cow ��ü �� �ϳ��� �������� �����մϴ�.
// - ������ ��ü�� Animal Ÿ���� �����ͷ� ��ȯ�˴ϴ�.
// - �Է� �Ű�����: ����
// - ��ȯ��: Animal* (������ ���� ��ü�� ������)
Animal* createRandomAnimal();

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	Animal* myAnimal[3]; // stack
	Dog myDog("bark bark");
	Cow myCow("moo");
	Cat myCat("mew");

	myAnimal[0] = &myDog;
	myAnimal[1] = &myCow;
	myAnimal[2] = &myCat;

	for (int i = 0; i < 3; i++) {
		print(myAnimal[i]);
	}

	Zoo* myZoo = new Zoo(); // heap, �����Ҵ��ص� �� deinit �غ����� ���
	for (int i = 0; i < 11; i++) {
		myZoo->addAnimal(createRandomAnimal());
	}
	myZoo->performActions();
	myZoo->~Zoo();

	return 0;
}

void print(Animal* animal) {
	animal->makeSound();
}

Animal* createRandomAnimal() {
	int randomNum = rand() % 3;

	if (randomNum == 0) {
		return new Dog("bark bark");
	}
	else if (randomNum == 1) {
		return new Cat("mew");
	}
	else {
		return new Cow("moo");
	}
}