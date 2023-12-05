class Character {
protected:
    int hp;
    int x;
    int y;
public:
    // Constructor: set the values of x and y and hp to 0
    Character();


    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);


    // Set and get hp
    int getHp();
    void setHp(int hp);


    // Set and get x
    int getX();
    void setX(int x);
    
    // Set and get y
    int getY();
    void setY(int y);


    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
};

Character::Character() {
    // STUDENT ANSWER
    x=0;
    y=0;
    hp=0;
}
Character::Character(int hp, int x, int y) : hp(hp),x(x),y(y) {
    // STUDENT ANSWER
}

int Character::getHp() {
    // STUDENT ANSWER
    return hp;
}

void Character::setHp(int hp) {
    // STUDENT ANSWER
    this->hp = hp;
}

int Character::getX() {
    // STUDENT ANSWER
    return x;
}

void Character::setX(int x) {
    // STUDENT ANSWER
    this->x=x;
}

int Character::getY() {
    // STUDENT ANSWER
    return y;
}

void Character::setY(int y) {
    // STUDENT ANSWER
    this->y=y;
}

int Character::getManhattanDistTo(Character* other) {
    // STUDENT ANSWER
    int dentax = this->x - other->getX();
    int dentay = this->y - other->getY();
    dentax = (dentax > 0) ? dentax : dentax * -1;
    dentay = (dentay > 0) ? dentay : dentay * -1;
    return (dentax + dentay);
}

