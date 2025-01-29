#ifndef GDEXTENSIONS_HELPERS_H
#define GDEXTENSIONS_HELPERS_H

#define DEFINE_PROPERTY(type, name, ...)                      \
private:                                                      \
    type name __VA_ARGS__;                                    \
                                                              \
public:                                                       \
    void set_##name(const type p_##name) { name = p_##name; } \
    type get_##name() const { return name; }

#define BIND_SINGLE_PROPERTY(class_name, type, name)                                                     \
    ::godot::ClassDB::bind_method(D_METHOD("get_" #name), &::godot::class_name::get_##name);             \
    ::godot::ClassDB::bind_method(D_METHOD("set_" #name, "p_" #name), &::godot::class_name::set_##name); \
    ADD_PROPERTY(PropertyInfo(type, #name), "set_" #name, "get_" #name);

#define BIND_SINGLE_PROPERTY_WITH_HINT(class_name, type, name, ...)                                      \
    ::godot::ClassDB::bind_method(D_METHOD("get_" #name), &::godot::class_name::get_##name);             \
    ::godot::ClassDB::bind_method(D_METHOD("set_" #name, "p_" #name), &::godot::class_name::set_##name); \
    ADD_PROPERTY(PropertyInfo(type, #name, __VA_ARGS__), "set_" #name, "get_" #name);

#endif // GDEXTENSIONS_HELPERS_H