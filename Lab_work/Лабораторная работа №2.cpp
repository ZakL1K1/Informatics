#include <SFML/Graphics.hpp>
#include <functional> 
#include <cmath> 

void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); 

        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ïðèëîæåíèå äëÿ âûâîäà ãðàôèêîâ");

    sf::CircleShape userPoint(5); 
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false; 

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
    }

    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);

    sf::Text zoneText;
    zoneText.setFont(font);
    zoneText.setCharacterSize(20);
    zoneText.setFillColor(sf::Color::White);
    zoneText.setPosition(10, 40);

    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300); 
    xAxis[0].color = sf::Color::White; 
    xAxis[1].position = sf::Vector2f(750, 300); 
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50); 
    yAxis[0].color = sf::Color::White; 
    yAxis[1].position = sf::Vector2f(400, 550); 
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    float mathX = (mousePos.x - 400) / 30.0f; 
                    float mathY = -(mousePos.y - 300) / 30.0f; 

                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; 

                    std::string zone = "0";
                    if (mathY > 2 and mathY > mathX + 2) {
                        zone = "1";
                    }
                    else if (mathY < 2 and mathY > mathX + 2) {
                        zone = "2";
                    }
                    else if (mathY < 2 and mathY < mathX + 2) {
                        zone = "3";
                    }
                    else if (mathY > 2 and mathY < mathX + 2) {
                        zone = "4";
                    }
                    else {
                        zone = "Point on the chart";
                    }
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ")");
                    zoneText.setString("Zone " + zone);

                }
            }
        }

        window.clear(sf::Color::Black);

        window.draw(xAxis);
        window.draw(yAxis);

        drawGraph(window, [](float x) { return x + 2; }, -10, 10, 30, 30, sf::Color::Blue);

        drawGraph(window, [](float x) { return 2; }, -10, 10, 30, 30, sf::Color::Red);

        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
            window.draw(zoneText);
        }

        window.display();
    }

    return 0;

}
