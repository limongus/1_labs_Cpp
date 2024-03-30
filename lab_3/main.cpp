#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

int main() {

    // начальная задержка (вроде..)
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    std::this_thread::sleep_for(std::chrono::seconds(4));


    // окошко
    sf::RenderWindow window(sf::VideoMode(900, 700), "SFML works!");


    // красный круг
    sf::CircleShape circle(50);//размер
    circle.setFillColor(sf::Color::Red); // цвет
    circle.setPosition(100, 300); // нач. позиция
    float circleSpeed = 100.0f; // скорость
    bool circleStopped = false; // отслеж остановки
    int a = 10;
    circle.setOutlineThickness(a); // толщина контура
    circle.setOutlineColor(sf::Color(220, 20, 20, 180)); // цвет контура

    // зелёный прямоугольник
    sf::RectangleShape rectangle(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(400, 200);
    float rectangleSpeed = 100.0f;
    bool rectangleStopped = false;
    int b = 10;
    rectangle.setOutlineThickness(b);
    rectangle.setOutlineColor(sf::Color(20, 220, 20, 180));

    // синий треугольник
    sf::CircleShape triangle(20);
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPointCount(3); // количество граней у круга
    triangle.setPosition(600, 400);
    float triangleSpeed = 150.0f;
    bool  triangleStopped = false;
    int c = 10;
    triangle.setOutlineThickness(c);
    triangle.setOutlineColor(sf::Color(20, 20, 220, 180));


    sf::Clock clock;
    float deltaTime = 0.0f;

    
    // для пульсации
    float g = 3;
    float h = 1;
    float j = 2;
    

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!circleStopped) {

            circle.move(0, -circleSpeed * deltaTime); // движение вверх, move(x,y)
            if (circle.getPosition().x <= 0 || circle.getPosition().y <= a) // если дошёл до границы
            {

                circleSpeed = 0;
                circleStopped = true;
                circle.setPosition(100, 10); // позиция на границе на случай вылета за её пределы (ЭТУ ЧАСТЬ НУЖНО ПЕРЕДЕЛАТЬ!!!)

            }

        }


        if (!rectangleStopped) {
            rectangle.move(0, -rectangleSpeed * deltaTime);
            if (rectangle.getPosition().x <= 0 || rectangle.getPosition().y <= b)
            {

                rectangleSpeed = 0;
                rectangleStopped = true;
            }
        }

        if (!triangleStopped) {
            triangle.move(0, -triangleSpeed * deltaTime);
            if (triangle.getPosition().x <= 0 || triangle.getPosition().y <= 2 * c)
            {

                triangleSpeed = 0;
                triangleStopped = true;
            }
        }



        window.clear(sf::Color(150,151,253));

        // отрисовка фигур
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        window.setVerticalSyncEnabled(true); // это не надо

        window.display();

        // генерация случайного цвета и изменение цвета фигур один-три раза в секунду
        if (circleStopped)
        {
            srand(time(NULL));
            sf::Color randomColor(rand() % 256, rand() % 40, rand() % 40);
            circle.setFillColor(randomColor);


            g += 0.3;
            // изначальная толщина а + sin увеличивающейся переменной g для пульсации границ,
                // *5 для более видного эффекта; /10 для уменьшения скорости
            circle.setOutlineThickness(a + sin(g / 10) * 5);
            circle.setPosition(100, a + sin(g / 10) * 5); // при утолщении границы круг сдвигается вниз




        }


        if (rectangleStopped)
        {
            srand(time(NULL));
            sf::Color randomColor(rand() % 40, rand() % 256, rand() % 70);

            rectangle.setFillColor(randomColor);


            h += 0.2;

            rectangle.setOutlineThickness(b + sin(h / 5) * 9);
            rectangle.setPosition(400, b + sin(h / 5) * 9);


        }

        if (triangleStopped)
        {
            srand(time(NULL));
            sf::Color randomColor(rand() % 40, rand() % 40, rand() % 256);

            triangle.setFillColor(randomColor);

            j += 0.4;
            triangle.setOutlineThickness(c + sin(j / 11) * 5);
            triangle.setPosition(600, 2 * (c + sin(j / 11) * 5));

        }
    }

    return 0;
} 