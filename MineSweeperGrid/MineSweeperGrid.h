//
// Created by lolmi on 4/6/2025.
//

#ifndef MINESWEEPERGRID_H
#define MINESWEEPERGRID_H
#include <Malena/common.hpp>

//start with a 3x3 board with 5 in the middle and bombs

class MineSweeperGrid : public ml::Application{
private:
    //ml::RectangleButton box;
    //ml::Rectangle rect;
    int n, m;

    //figured out how to make the spacing and boxsize dynamic
    float spacing = 1.f, boxDimension = 20.f;
    std::vector<std::vector<ml::RectangleButton>> mineSweeperGrid;
    std::vector<std::vector<ml::Rectangle>> spriteRects;
    sf::Texture texture;
public:
    MineSweeperGrid();
    MineSweeperGrid(int n, int m);
    void initialization() override;
    void registerEvents() override;
};
#endif //MINESWEEPERGRID_H




