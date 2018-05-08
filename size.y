Binary file vgcore.7043 matches
Binary file vgcore.5990 matches
Binary file src/destroy/.destroy_scenes.c.swp matches
src/destroy/destroy_scenes.c:	inverse(&map->size.x, &map->size.y);
src/destroy/destroy_scenes.c:	for (unsigned int row = 0; row < map->size.y; row++) {
src/destroy/destroy_scenes.c:		for (unsigned int col = 0; col < map->size.x; col++)
src/destroy/destroy_scenes.c:			destroy_tile(map->tiles[row][col]);
src/destroy/destroy_scenes.c:		free(map->tiles[row]);
src/destroy/destroy_scenes.c:	free(map->tiles);
src/map/light_shader.c:	for (unsigned int x = 0; x < map->size.x; x++) {
src/map/light_shader.c:		for (unsigned int y = 0; y < map->size.y; y++) {
src/map/light_shader.c:			set_light(map->tiles[x][y]->light, map->tiles[x][y]->light_level);
src/map/gen_light_shader.c:	for (unsigned int x = 0; x < map->size.x; x++) {
src/map/gen_light_shader.c:		for (unsigned int y = 0; y < map->size.y; y++) {
src/map/gen_light_shader.c:			set_refresh(map->tiles[x][y]);
src/map/gen_light_shader.c:			map->tiles[(int)pos.x][(int)pos.y]->light_level
src/map/gen_light_shader.c:		map->tiles[(int)pos.x][(int)pos.y]->lighted = 1;
src/map/gen_light_shader.c:	map->tiles[(int)pos.x][(int)pos.y]->light_level = brightness;
src/map/gen_light_shader.c:		map->tiles[(int)pos.x][(int)pos.y]->lighted= 1;
src/map/gen_light_shader.c:		if (map->tiles[(int)pos.x][(int)pos.y]->laser_col)
src/map/apply_on_map.c:	while (map->tiles[i]) {
src/map/apply_on_map.c:		tile = func(rpg, map->tiles[i], data);
src/map/apply_on_map.c:	return (map->tiles[0][0]);
src/map/apply_on_map.c:	while (map->tiles[y]) {
src/map/apply_on_map.c:		x = func(map, map->tiles[y], name);
src/states/draw/draw_scene.c:	for (unsigned int x = 0; x < map->size.x; x++) {
src/states/draw/draw_scene.c:		for (unsigned int y = 0; y < map->size.y; y++) {
src/states/draw/draw_scene.c:			draw_tile(rpg, map->tiles[x][y]);
src/states/draw/draw_scene.c:			draw_light(rpg, map->tiles[x][y]);
src/init/parse/parse_image.c:	for (unsigned int col = 0; col < map->size.x; col++) {
src/init/parse/parse_image.c:		map->tiles[row][col] = malloc(sizeof(tile_t));
src/init/parse/parse_image.c:		if (map->tiles[row][col] == NULL)
src/init/parse/parse_image.c:		set_tile_values(map->tiles[row][col], index, (sfVector2f){row, col}, color);
src/init/parse/parse_image.c:		status = init_tile(rpg, map->tiles[row][col], index,
src/init/init_map.c:	map->tiles[row] = malloc(sizeof(tile_t *) * (map->size.x + 1));
src/init/init_map.c:	if (map->tiles[row] == NULL)
src/init/init_map.c:	map->tiles[row][map->size.x] = NULL;
src/player/player_event.c:		tile = rpg->scenes[rpg->curr_scene]->map->tiles[pos.x][pos.y];
src/player/move_player.c:	else if (pos.x >= (float)map->size.x || pos.y >= (float)(map->size.y))
src/player/move_player.c:		return (map->tiles[(int)pos.x][(int)pos.y]->player_col);
Binary file vgcore.9401 matches
