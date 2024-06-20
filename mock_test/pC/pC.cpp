class Shape {
public:
    virtual double getArea() = 0; // Pure virtual function
};

class Rectangle : public Shape {
private:
    int length;
    int width;
public:
  	Rectangle(int l = 0, int w = 0) : length(l), width(w) {}
  
    void setLength(int l) {
        length = l;
    }

    void setWidth(int w) {
        width = w;
    }

    int getLength() const {
        return length;
    }

    int getWidth() const {
        return width;
    }

    double getArea() override{
        return  width * length;
    }

    int getPerimeter() {
        return (width + length) * 2;
    }
};
