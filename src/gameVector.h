#ifndef GAME_VECTOR_H
#define GAME_VECTOR_H
struct Position
{
    double _x;
    double _y;
    Position(){}

    Position(double x, double y) {
        _x = x;
        _y = y;
    }
};

class GameVector {
    public: 
        GameVector(double component_x, double component_y);
        GameVector(const GameVector & other);
        GameVector & operator=(const GameVector & other);
        ~GameVector();
        GameVector(GameVector && other);
        GameVector & operator=(GameVector &&other);

        GameVector operator +(GameVector const& rhs);
        GameVector operator *(double constant);
        GameVector & operator +=(GameVector const& rhs);

        Position getComponents() {
            return components;
        }

        void setComponents(double x, double y) {
            components._x = x;
            components._y = y;
        }

        double getMagnitude() {
            return magnitude;
        }

        void setMagnitude(double m) {
            magnitude = m;
        }

    private:
        Position components;
        double magnitude;
};
#endif