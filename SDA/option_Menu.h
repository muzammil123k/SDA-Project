#ifndef option_Menu_h
#define option_Menu_h
#include <SFML/Graphics.hpp>

#include<iostream>

#include<string.h>

#include <vector>
using namespace std;
using namespace sf;
class option_Menu
{
public:
    void Menu(float width = 800, float height = 600) {
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
    option_Menu() {
        Menu();
        vector<string> options = {
            "Choose Level", "Edit Player Profile", "View Leader Board",
            "Select Character", "Adjust Settings", "Save Game",
            "Load Game", "Submit Score", "Manage Inventory","Exit"
        };

        RenderWindow Window(sf::VideoMode(800, 600), "Options Menu");
        push_menu(options); // This will now clear previous options

        while (Window.isOpen()) {
            sf::Event event;
            while (Window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    Window.close();
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
                        // Perform actions based on selectedOption
                        if (selectedOption == 0) {
                            //chooseLevelMenu();

                        }if (selectedOption == 9) {
                            Window.close();
                        }
                    }
                }
            }

            Window.clear();
            draw(Window);
            Window.display();
        }
    }
    
	

private:
    Font font;
    vector < sf::Text > menuItems;
    int selectedItemIndex;
};


#endif
#pragma once
