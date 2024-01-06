/**
 * File name: Position.hpp
 * Author: Banu Constantin-Adrian
 * Date: 06/01/2024
 * Description:
 *
 * \brief Implements a template class used to store data related to position of sprites.
 */

#ifndef OOP_POSITION_HPP
#define OOP_POSITION_HPP

template<class T>
class Position {
private:
    /**
     * \brief Position on X axis.
     */
    T x;

    /**
     * \brief Position on Y axis.
     */
    T y;
public:
    /**
     * \brief Constructs a new position.
     */
    Position() = default;

    /**
     * \brief Constructs a new position using given parameters.
     */
    Position(T localX, T localY);

    /**
     * \brief Getter for the position on X axis.
     */
    T getX() const;

    /**
     * \brief Getter for the position on Y axis.
     */
    T getY() const;

    /**
     * \brief Setter for the position on X axis.
     *
     * @param localX the new X
     */
    [[maybe_unused]] void setX(T localX);

    /**
     * \brief Setter for the position on Y axis.
     *
     * @param localY the new Y
     */
    void setY(T localY);
};


#endif //OOP_POSITION_HPP
