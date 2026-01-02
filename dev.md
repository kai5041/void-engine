> NOTE: where vars are zero, their value is equal to the incremented value of the last item.

## Engine
### Properties
- worlds: Map<String, World*>

### Functions
// Prints to CLI if world_name already exists
- add_world(String world_name, World *world): void

// Updates all worlds in a frame
- update(float dt): void

## World
### Properties
- objects: Map<u32, Object*>

### Functions
- add_object(Object* object = nullptr): u32
- remove_object(u32 id): void
- get_objects(): auto
- get_object(u32 id): Object*
- step(float dt): void