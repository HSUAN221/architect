// Copyright (c)
#ifndef SRC_ARCHITECT_VISITOR_HPP_
#define SRC_ARCHITECT_VISITOR_HPP_
/// If your data structure is fixed, use it!!!
namespace architect {

class Circle;
class Square;

class ShapeVisitor {
 public:
using CirclePtrType = std::shared_ptr<Circle>();
    virtual void visit(Circle* const) = 0;
    virtual void visit(Square* const) = 0;
    virtual ~ShapeVisitor() = default;
};

class Shape {
 public:
    virtual void accept(const std::shared_ptr<ShapeVisitor>&) = 0;
};



/// Data structure implement
class Circle : public Shape {
 private:
    std::string name_ = "circle";
    double radius_ = 0.0;

 public:
    explicit Circle(double radius) : radius_(radius) {}

    virtual ~Circle() = default;

    void accept(const std::shared_ptr<ShapeVisitor>& v) override {
        v->visit(this);
    }

    double getRadius() noexcept {
        return radius_;
    }
};

/// Data structure implement
class Square : public Shape {
 private:
    std::string name_ = "square";
    double length_ = 0.0;

 public:
    explicit Square(double length) : length_(length) {}

    virtual ~Square() = default;

    void accept(const std::shared_ptr<ShapeVisitor>& v) override {
        v->visit(this);
    }

    double getLength() const noexcept {
        return length_;
    }
};



/// Algorithm implement
class AreaCalculator : public ShapeVisitor {
 private:
    double circle_area_ = 0.0;
    double square_area_ = 0.0;
    const double pi_ = 3.141592653589793238463;

 public:
    void visit(Circle* const c) override {
        circle_area_ = c->getRadius() * c->getRadius() * pi_;
    }

    void visit(Square* const s) override {
        square_area_ = s->getLength() * s->getLength();
    }

    double getCircleArea() const noexcept {
        return circle_area_;
    }

    double getSquareArea() const noexcept {
        return square_area_;
    }


};




}  // namespace architect
#endif  // SRC_ARCHITECT_VISITOR_HPP_
