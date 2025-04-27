#include <iostream>
#include <SFML/Graphics.hpp>
#include "MineSweeperAlgorithm\MineSweeperGrid.h"
#include "MineSweeperAlgorithm\TextureSlicingDemo.h"
int main() {

    /**As of 4/23 graphics was updated, need to refactor MineSweeperGrid class
     *MineSweeeperGrid: Draws the minesweeper, places transparent RectangleButton objects that has states, which are placed on
     *top of rects
     *
     *Node: Represents a node in the backtracking process. Hold's the number's coordinate and possible bomb placements. Has
     *a method to generate and return all combinations of bomb placements as a vector of coordinates. Has iterator to traverse t
     *through the combinations.
     *
     *Backtracking: Iterate through the grid and calls the Model's methods to get combinations of bomb placements. Has
     *the backtracking algorithm to test each combination and determine if its a valid solution. Stores each step in a data
     *structure in Model
     *
     *Model: Holds the board in data form (2D vector of characters) and all the nodes. Has getters, setters, and iterators.
     *
     *TextureSlicingDemo: Class where I overlaid parts of the texture sheet on a ml::Rectangle object
     *
     *Malena Application Class: Use SFML to render the Minesweeper grid and update the display (EDA) as it iterates through
     *the data structure that contains the steps in the backtracking
     *Highlights the number squares and shows the flags being placed around them
     *
     *Create a class that inherits ML::Application that ties everything together. Main should only have app.run().
    **/

    MineSweeperGrid app2 = MineSweeperGrid(15, 15);
    app2.run();
    //
    // TextureSlicingDemo app3 = TextureSlicingDemo();
    // app3.run();
    return 0;
}
