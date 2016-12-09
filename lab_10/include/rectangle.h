#include "figure.h"

class Rectangle : public Figure {
  public:
    Rectangle(int id, int x, int y, int width, int height);
    ~Rectangle();
    
    void print() const;
    bool is_inside(int x, int y) const;
    void zoom(int factor);
    void move(int new_x, int new_y);
    int get_id() const;
  private:
    int w_,h_;
};
