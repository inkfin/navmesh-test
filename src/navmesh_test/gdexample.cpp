#include "gdexample.h"
#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/property_info.hpp"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDExample::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("get_hello"), &GDExample::get_hello);

    BIND_SINGLE_PROPERTY(GDExample, Variant::VECTOR2, amplitude);

    BIND_SINGLE_PROPERTY_WITH_HINT(GDExample, Variant::FLOAT, speed, PROPERTY_HINT_RANGE, "0,20,0.01");

    ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::VECTOR2, "new_pos")));
}

GDExample::GDExample()
{
}

GDExample::~GDExample()
{
}

void GDExample::_process(double delta)
{
    time_passed += speed * delta;

    Vector2 new_position = Vector2(
        amplitude.x + (amplitude.x * sin(time_passed * 2.0)),
        amplitude.y + (amplitude.y * cos(time_passed * 1.5)));

    set_position(new_position);

    time_emit += delta;

    if (time_emit >= 1.0) {
        emit_signal("position_changed", this, new_position);

        time_emit = 0.0;
    }
}

String GDExample::get_hello()
{
    return "Hello, world!";
}
