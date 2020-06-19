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
    void returnInput();

    int getLeft() const;

    void setLeft(int left);

    int getRight() const;

    void setRight(int right);

    int getUp() const;

    void setUp(int up);

    int getDown() const;

    void setDown(int down);

    bool isFire() const;

    void setFire(bool fire);

    bool isQuit() const;

    void setQuit(bool quit);


private:
    int left;
    int  right;
    int up;
    int down;
    bool fire;
    bool quit;

};


#endif //GAMEV0_INPUT_H
