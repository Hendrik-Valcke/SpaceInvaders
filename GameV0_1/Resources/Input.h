//
// Created by hendr on 04/03/2020.
//

#ifndef GAMEV0_INPUT_H
#define GAMEV0_INPUT_H


class Input {
public:
    //Input();
    //~Input();
    void clearInput();
    void setUp(bool status){up=status;}
    void setDown(bool status){down=status;}
    void setLeft(bool status){left=status;}
    void setRight(bool status){right=status;}
    void setFire(bool status){fire=status;}
    void setQuit(bool status){quit=status;}


private:
    bool left;
    bool right;
    bool up;
    bool down;
    bool fire;
    bool quit;

};


#endif //GAMEV0_INPUT_H
