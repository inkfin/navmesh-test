extends Node

@export var is_happy: bool = true

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


func _on_gd_example_position_changed(node, new_pos):
	print("GD example new position is:", new_pos)
