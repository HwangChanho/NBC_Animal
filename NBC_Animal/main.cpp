#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Animal.cpp"
#include "Zoo.hpp"

void print(Animal* animal);

// 랜덤 동물을 생성하는 함수
// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
// - 입력 매개변수: 없음
// - 반환값: Animal* (생성된 동물 객체의 포인터)
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

	Zoo* myZoo = new Zoo(); // heap, 정적할당해도 됨 deinit 해보려고 사용
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