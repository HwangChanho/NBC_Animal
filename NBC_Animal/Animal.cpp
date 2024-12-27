#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include <string>
#include <iostream>

using namespace std;

class Animal {
public:
	Animal() {}
	~Animal() {}

	virtual void makeSound() = 0;
	virtual string getName() = 0;

private:

};

class Dog : public Animal {
public:
	Dog(string word) :m_word(word) {}
	~Dog() {}

	void makeSound() override {
		cout << "Dog: " << m_word << endl;
	}

	string getName() override {
		return "Dog";
	}

private:
	string m_word;
};

class Cat : public Animal {
public:
	Cat(string word) :m_word(word) {}
	~Cat() {}

	void makeSound() override {
		cout << "Cat: " << m_word << endl;
	}

	string getName() override {
		return "Cat";
	}

private:
	string m_word;
};

class Cow : public Animal {
public:
	Cow(string word) :m_word(word) {}
	~Cow() {}

	void makeSound() override {
		cout << "Cow: " << m_word << endl;
	}

	string getName() override {
		return "Cow";
	}

private:
	string m_word;
};

#endif