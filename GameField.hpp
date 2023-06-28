#include "./Fighter.hpp"

#define BoardSize   20

class GameField {
    private:
        int x, y;
        std::vector<std::vector<int>> board;
    public:
        GameField();
        virtual ~GameField() {};

        void showGameField();
};

inline GameField :: GameField() {
    this->x = 0;
    this->y = 0;
}
