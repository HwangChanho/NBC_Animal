#include "Zoo.hpp"

void Zoo::addAnimal(Animal* animal) {
    for (int i = 0; i < 10; i++) {
        if (animals[i] == nullptr) {
            animals[i] = animal;
            cout << animal->getName() << " added to the zoo!" << endl;
            return;
        }
    }
    cout << "Zoo is full." << endl;
}

void Zoo::performActions() {
    for (int i = 0; i < 10; i++) {
        if (animals[i] != nullptr) {
            animals[i]->makeSound();
        }
    }
}

Zoo::~Zoo() {
    for (int i = 0; i < 10; i++) {
        if (animals[i] != nullptr) {
            delete animals[i];
            animals[i] = nullptr;
        }
    }
    cout << "All animals have been deleted." << endl;
}