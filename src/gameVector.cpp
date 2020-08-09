#include "gameVector.h"
#include <math.h>
#include <iostream>

GameVector::GameVector(double component_x, double component_y) {
    this->components = Position(component_x, component_y);
    magnitude = pow(components._x, 2) + pow(components._y, 2);
}

GameVector::GameVector(const GameVector& other) {
    auto comp = Position(other.components._x, other.components._y);
    setComponents(comp._x, comp._y);
    setMagnitude(other.magnitude);
}

GameVector & GameVector::operator=(const GameVector& other) {
    if(this == &other) {
        return *this;
    }
    auto comp = Position(other.components._x, other.components._y);
    setComponents(comp._x, comp._y);
    setMagnitude(other.magnitude);
    return *this;
}

GameVector::~GameVector() {
    std::cout << "Game Vector desructor called" << std::endl;
}

GameVector::GameVector(GameVector && other) {
    auto comp = other.getComponents();
    setComponents(comp._x, comp._y);
    setMagnitude(other.magnitude);
}

GameVector& GameVector::operator=(GameVector &&other) {
    if(this == &other) {
        return *this;
    }
    auto comp = other.getComponents();
    setComponents(comp._x, comp._y);
    setMagnitude(other.magnitude);
    return *this;
}

 GameVector GameVector::operator+(GameVector const & other) {
    return GameVector(components._x + other.components._x, components._y + other.components._y);
}

GameVector GameVector::operator *(double constant) {
    return GameVector(components._x * constant, components._y * constant);
}

GameVector & GameVector::operator +=(GameVector const& rhs) {
    components._x += rhs.components._x;
    components._y += rhs.components._y;
    return *this;
}