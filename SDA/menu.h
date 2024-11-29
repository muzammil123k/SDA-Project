#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

#include <vector>
#include"option_Menu.h"

using namespace std;
using namespace sf;
class Menu {
private: Font font;
       vector < sf::Text > menuItems;
       int selectedItemIndex;
public:

    //add menu attributes here
    Menu(float width = 800, float height = 600) {
        // Load font
        if (!font.loadFromFile("BebasNeue-Regular.ttf")) {
            std::cerr << "Error loading font!\n";
        }


    }void push_menu(vector<string> options, float width = 800, float height = 600) {
        // Clear the previous menu items
        menuItems.clear();

        selectedItemIndex = 0; // Reset selection index

        for (size_t i = 0; i < options.size(); ++i) {
            sf::Text text;
            text.setFont(font);
            text.setString(options[i]);
            text.setCharacterSize(40);
            text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White); // Highlight the first option
            text.setPosition(
                width / 2 - text.getGlobalBounds().width / 2,
                height / (options.size() + 1) * (i + 1)
            );
            menuItems.push_back(text);
        }
    }

    void draw(sf::RenderWindow& window) {
        for (const auto& item : menuItems) {
            window.draw(item);
        }
    }
    void moveUp() {
        if (selectedItemIndex > 0) {
            menuItems[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex--;
            menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }
    void moveDown() {
        if (selectedItemIndex < menuItems.size() - 1) {
            menuItems[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex++;
            menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }
    int getSelectedItemIndex() const {
        return selectedItemIndex;
    }

    void display_menu() {
        vector < string > options = {
                             "Resume Game",
                             "Options",
                             "Exit",
                             "End Game"
        };

        RenderWindow window(sf::VideoMode(800, 600), "Game Menu");
        push_menu(options);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up) {
                        moveUp();
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        moveDown();
                    }
                    else if (event.key.code == sf::Keyboard::Enter) {
                        int selectedOption = getSelectedItemIndex();
                        if (selectedOption == 0) {
                            std::cout << "Start Game selected\n";
                        }
                        else if (selectedOption == 1) {
                            std::cout << "Options selected\n";
                            
                            option_Menu m;
                            
                        }
                        else if (selectedOption == 2) {
                            std::cout << "Exit selected\n";
                            window.close();
                        }
                        else if (selectedOption == 3) {
                            cout << "End Game selected\n";
                            window.close();
                        }
                    }
                }
            }

            window.clear();
            draw(window);
            window.display();
        }
    }
    void chooseLevelMenu() {
        vector<string> levelOptions = {
            "Level 1",
            "Level 2",
            "Level 3",
            "Difficulty Level"
        };

        RenderWindow window(VideoMode(800, 600), "Choose Level Menu");
        push_menu(levelOptions);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up) {
                        moveUp();
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        moveDown();
                    }
                    else if (event.key.code == sf::Keyboard::Enter) {
                        int selectedOption = getSelectedItemIndex();
                        if (selectedOption == 0) {
                            std::cout << "Level 1 selected\n";
                        }
                        else if (selectedOption == 1) {
                            std::cout << "Level 2 selected\n";
                        }
                        else if (selectedOption == 2) {
                            std::cout << "Level 3 selected\n";
                        }
                        else if (selectedOption == 3) {
                            std::cout << "Difficulty Level selected\n";
                        }
                        // Add functionality for each option as needed
                    }
                }
            }

            window.clear();
            draw(window);
            window.display();
        }
    }
    //void option_Menu() {
    //    vector<string> options = {
    //        "Choose Level", "Edit Player Profile", "View Leader Board",
    //        "Select Character", "Adjust Settings", "Save Game",
    //        "Load Game", "Submit Score", "Manage Inventory","Exit"
    //    };

    //    RenderWindow Window(sf::VideoMode(800, 600), "Options Menu");
    //    push_menu(options); // This will now clear previous options

    //    while (Window.isOpen()) {
    //        sf::Event event;
    //        while (Window.pollEvent(event)) {
    //            if (event.type == sf::Event::Closed) {
    //                Window.close();
    //            }

    //            if (event.type == sf::Event::KeyPressed) {
    //                if (event.key.code == sf::Keyboard::Up) {
    //                    moveUp();
    //                }
    //                else if (event.key.code == sf::Keyboard::Down) {
    //                    moveDown();
    //                }
    //                else if (event.key.code == sf::Keyboard::Enter) {
    //                    int selectedOption = getSelectedItemIndex();
    //                    // Perform actions based on selectedOption
    //                    if (selectedOption == 0) {
    //                        chooseLevelMenu();

    //                    }if (selectedOption == 9) {
    //                        Window.close();
    //                    }
    //                }
    //            }
    //        }

    //        Window.clear();
    //        draw(Window);
    //        Window.display();
    //    }
    //}

    
    /*
       {
        Font font;
      Text text;
        font.loadFromFile("BebasNeue-Regular.ttf");
        text.setFont(font);
                    text.setString("please press 's' to start a new game");
                    text.setPosition(210, 15);
                    text.setCharacterSize(35);
                    text.setFillColor(Color::White);
          RenderWindow window(VideoMode(780, 250), "Menu");
          while (window.isOpen()) {
       Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
                if (Keyboard::isKeyPressed(Keyboard::S))
                 window.close();
        }
        window.clear(); // Clear the window
     window.draw(text);
       window.display(); // Update the window
    }

       }*/
    void displayPausemenu(int score, int lives)

    {
        vector < string > options = {
                                "Resume Game",
                                "Options",
                                "Exit",
                                "End Game"
        };

        RenderWindow window(sf::VideoMode(800, 600), "Game Menu");
        push_menu(options);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up) {
                        moveUp();
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        moveDown();
                    }
                    else if (event.key.code == sf::Keyboard::Enter) {
                        int selectedOption = getSelectedItemIndex();
                        if (selectedOption == 0) {
                            std::cout << "Resume Game selected\n";
                        }
                        else if (selectedOption == 1) {
                            std::cout << "Options selected\n";
                        }
                        else if (selectedOption == 2) {
                            std::cout << "Exit selected\n";
                            window.close();
                        }
                        else if (selectedOption == 3) {
                            cout << "End Game selected\n";
                            window.close();
                        }
                    }
                }
            }

            window.clear();
            draw(window);
            window.display();
        }


    }

};
