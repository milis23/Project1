#ifndef ANIMOWANEASSETY_H
#define ANIMOWANEASSETY_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
class AnimowaneAssety
{
public:
    virtual ~AnimowaneAssety() {}

    virtual void update() = 0;
    virtual void render() = 0;

    float getVelocityX() const { return velocity_x; }
    void setVelocityX(float velocity) { velocity_x = velocity; }

    float getVelocityY() const { return velocity_y; }
    void setVelocityY(float velocity) { velocity_y = velocity; }

private:
    float velocity_x;
    float velocity_y;
};

#endif // ANIMOWANEASSETY_H
