#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include "gdextension_helpers.h"
#include "godot_cpp/classes/sprite2d.hpp"

namespace godot {

class GDExample : public Sprite2D {
    GDCLASS(GDExample, Sprite2D)

private:
    double time_passed = 0.;
    double time_emit = 0.;

    DEFINE_PROPERTY(Vector2, amplitude, = Vector2(30.0, 10.0));
    DEFINE_PROPERTY(double, speed, = 1.0);

protected:
    static void _bind_methods();

public:
    GDExample();
    ~GDExample();

    void _process(double delta) override;

    String get_hello();
};

}

#endif
