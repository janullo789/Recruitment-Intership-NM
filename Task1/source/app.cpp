#include "app.h"

app::app() {
    // Window SFML
    window.create(sf::VideoMode(800, 600), "Are triangles colliding?");
    window.clear(sf::Color::White);

    // Making triangles 
    t1 = { { { { 100, 400 }, { 300, 400 }, { 200, 259 } } } };
    t2 = { { { { 500, 400 }, { 700, 400 }, { 600, 259 } } } };

    // Making shapes SFML of triangles
    shape1.setPointCount(3);
    shape2.setPointCount(3);
    for (int i = 0; i < 3; ++i) {
        shape1.setPoint(i, sf::Vector2f(t1.points[i].x, t1.points[i].y));
        shape2.setPoint(i, sf::Vector2f(t2.points[i].x, t2.points[i].y));
    }
    shape1.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Blue);
}

void app::events() {
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                // left button of mouse (triangle 1)
                if (event.mouseButton.button == sf::Mouse::Left) {
                    t1.points[0].x = mousePos.x - 100;
                    t1.points[0].y = mousePos.y + 70.5;
                    t1.points[1].x = mousePos.x + 100;
                    t1.points[1].y = mousePos.y + 70.5;
                    t1.points[2].x = mousePos.x;
                    t1.points[2].y = mousePos.y - 70.5;

                    for (int i = 0; i < 3; ++i) {
                        shape1.setPoint(i, sf::Vector2f(t1.points[i].x, t1.points[i].y));
                    }
                }

                // right button of mouse (triangle 2)
                if (event.mouseButton.button == sf::Mouse::Right) {
                    t2.points[0].x = mousePos.x - 100;
                    t2.points[0].y = mousePos.y + 70.5;
                    t2.points[1].x = mousePos.x + 100;
                    t2.points[1].y = mousePos.y + 70.5;
                    t2.points[2].x = mousePos.x;
                    t2.points[2].y = mousePos.y - 70.5;

                    for (int i = 0; i < 3; ++i) {
                        shape2.setPoint(i, sf::Vector2f(t2.points[i].x, t2.points[i].y));
                    }
                }                
            }
        }

        // Widow cleaning and drawing shapes 
        window.clear(sf::Color::White);
        window.draw(shape1);
        window.draw(shape2);
        window.display();
    }
}