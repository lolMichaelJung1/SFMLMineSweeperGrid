//
// Created by lolmi on 4/6/2025.
//

#include "MineSweeperGrid.h"
#include <iostream>
#include "Malena/Utilities/TextureSlicer.h"

MineSweeperGrid::MineSweeperGrid() : Application(sf::VideoMode({720, 420}, 32), "Mine Sweeper Grid", *this), n(3), m(3){
	texture.loadFromFile("C:/Users/lolmi/CLionProjects/Texture_Slicing/images/minesweep_cut.png");
}
MineSweeperGrid::MineSweeperGrid(int n, int m) : Application(sf::VideoMode({720, 420}, 32), "Mine Sweeper Grid", *this), n(n), m(m){
	texture.loadFromFile("C:/Users/lolmi/CLionProjects/Texture_Slicing/images/minesweep_cut.png");
}

void MineSweeperGrid::initialization(){
    sf::Vector2u windowDimensions = ml::WindowManager::getWindow().getSize();
    float ratioForSpacing = 0.05f;
    float usedWidth = windowDimensions.x * 0.95f;
    float usedHeigth = windowDimensions.y * 0.95f;
    float maxWidthOfBox = usedWidth / m;
    float maxHeightOfBox = usedHeigth / n;
    boxDimension = std::min(maxWidthOfBox, maxHeightOfBox);
    spacing = boxDimension * ratioForSpacing;

    for (int i = 0; i < n; i++) {
         std::vector<ml::RectangleButton> horizontal;
         std::vector<ml::Rectangle> spriteHorizontal;
         for (int j = 0; j < m; j++) {
             horizontal.push_back(ml::RectangleButton());
              spriteHorizontal.push_back(ml::Rectangle());
         }
         mineSweeperGrid.push_back(horizontal);
         spriteRects.push_back(spriteHorizontal);
     }

     for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
             ml::Rectangle& spriteRect = spriteRects[i][j];
             spriteRect.setSize({boxDimension, boxDimension});

             //Splices sprite sheet png to 12 rows, 11 columns
             ml::ImageRects rects = TextureSlicer::getImageRects(texture, 11, 12);
             //this is where the texture is chosen from the sprite sheet, there is a bug where rows and cols are swithced
             // sf::IntRect intRect = rects.getIntRect(0,5);
             sf::IntRect intRect = rects.getIntRect(0,0);
             spriteRect.setTextureRect(intRect);
             spriteRect.setTexture(&texture);
             spriteRect.setPosition({j * (boxDimension + spacing) + spacing, i * (boxDimension + spacing) + spacing});

             ml::RectangleButton& box = mineSweeperGrid[i][j];
             box.setSize({boxDimension, boxDimension});
             box.setFillColor(sf::Color::Transparent);
             box.setPosition({j * (boxDimension + spacing) + spacing, i * (boxDimension + spacing) + spacing});

             addComponent(spriteRect);
             addComponent(box);
         }
     }
}

void MineSweeperGrid::registerEvents() {
    //set the events for when boxes are opened, unopened, flagged, and if bomb is opened.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ml::RectangleButton& box = mineSweeperGrid[i][j];
            ml::Rectangle& spriteRect = spriteRects[i][j];

            /*currently the clicks don't register when I fullscreen the window. I'll have to
             * read up on the SFML 3.0 documentation and the Malena source files.
             */

            //disappear
            //            box.onClick([&box]() {
            //                box.setFillColor(sf::Color::Transparent);
            //            });

            //change color
            box.onClick([&box]() {
                box.setFillColor(sf::Color::Red);
            });
            // //change state to FLAGGED if right clicked
            // box.onClick([&box]() {
            //     box.setState(stateful::FLAGGED);
            // });

            //refactor to use texture slicer class
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ml::RectangleButton& box = mineSweeperGrid[i][j];
                    ml::Rectangle& spriteRect = spriteRects[i][j];

                    /*currently the clicks don't register when I fullscreen the window. I'll have to
                     * read up on the SFML 3.0 documentation and the Malena source files.
                     */

                    //disappear
                    //            box.onClick([&box]() {
                    //                box.setFillColor(sf::Color::Transparent);
                    //            });

                    //change color
                    box.onClick([&box]() {
                        box.setFillColor(sf::Color::Red);
                        std::cout << "Box clicked\n";

                        //if its the first click, reveal all the boxes around it that does not have the bomb,
                        //and set the sprite to the empty one

                        // if a clicked box does not have a bomb, continue the game

                        //if a clicked box does not have a bomb or number, reveal all the boxes around it that does not
                        //have the bomb and the set the sprite to the empty one

                        //if the box is not flagged and clicked, reveal whats under the box, and reveal the sprite under the default sprite

                        //change the state to flagged if flagged, change the sprite to the one with a flag

                        //if the box is marked as flagged and clicked again, remove the flag, change the sprite to the one without the flag
                        if(box.checkState(ml::Stateful::FLAGGED)) {
                            //remove flag
                        }

                        //if the box is revealed and has a bomb, change the sprite to the one with the bomb and reveal all the bombs and end the game

                    });

                    //            I'm starting to appreciate the MALENA EDA framework since it feels like functional programming. Thank you
                    //            professor Smith.



                }
            }


        }
    }
}