#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include "godot_cpp/classes/sprite2d.hpp"

namespace godot {

class GDExample : public Sprite2D {
    GDCLASS(GDExample, Sprite2D)

private:
    double time_passed;
    double time_emit;
    Vector2 amplitude;
    double speed;

protected:
    static void _bind_methods();

public:
    GDExample();
    ~GDExample();

    void _process(double delta) override;

    String get_hello();

    /* getter/setter */
    void set_amplitude(const Vector2 p_amplitude);
    Vector2 get_amplitude() const;

    void set_speed(const double p_speed);
    double get_speed() const;
};

}

#endif
