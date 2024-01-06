//
// Created by Adrian on 06-Jan-24.
//

#include "../headers/Position.hpp"

template<class T>
Position<T>::Position(T localX, T localY) : x(localX), y(localY) {}

template<class T>
T Position<T>::getX() const {
    return this->x;
}

template<class T>
T Position<T>::getY() const {
    return this->y;
}

//template<class T>
//[[maybe_unused]] void Position<T>::setX(T localX) {
//    x = localX;
//}

template<class T>
void Position<T>::setY(T localY) {
    y = localY;
}

template class Position<float>;
template class Position<int>;