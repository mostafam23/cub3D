# Cub3D

A 3D maze game inspired by Wolfenstein 3D, built using raycasting techniques and the MiniLibX graphics library.

## 👥 Authors

- **Mostafa Al Mohammad** (mel-moha)
- **Carla Kinaan** (ckinaan)

## 📋 Description

Cub3D is a project from the 42 curriculum that implements a simple 3D game engine using raycasting. Players navigate through a maze with textured walls, customizable floor and ceiling colors, and smooth first-person movement controls.

## ✨ Features

- **Raycasting Engine**: Real-time 3D rendering using DDA (Digital Differential Analysis) algorithm
- **Textured Walls**: Four directional wall textures (North, South, East, West)
- **Smooth Movement**: WASD controls with collision detection
- **Camera Rotation**: Arrow keys for looking left and right
- **Customizable Environment**: Configurable colors for floor and ceiling
- **Map Parsing**: Reads and validates `.cub` map files

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `ESC` | Exit game |

## 🛠️ Installation

### Prerequisites

- GCC compiler
- MiniLibX library
- X11 development libraries (Linux)
- Make

### Building the Project

```bash
# Clone the repository
git clone [repository-url]
cd cub3d

# Compile the project
make

# Run the game
./cub3D maps/example.cub
```

## 📁 Project Structure

```
cub3d/
├── main.c                          # Entry point and main game loop setup
├── init.c                          # Game initialization
├── cleanup.c                       # Memory cleanup and exit handling
├── validations_and_parsing/        # Map validation and parsing
│   ├── colors.c                    # RGB color parsing
│   ├── data.c                      # Data structure management
│   ├── fill_map1.c & fill_map2.c   # Map filling logic
│   ├── free_utils.c                # Memory deallocation utilities
│   ├── map.c                       # Map validation
│   └── validations_main.c          # Main validation logic
├── game/                           # Core game logic
│   ├── game.c                      # Main game loop and rendering
│   ├── raycasting_dda.c            # DDA algorithm implementation
│   ├── raycasting_init.c           # Ray initialization
│   ├── rendering.c                 # Pixel rendering and drawing
│   ├── key_handlers.c              # Keyboard input handling
│   ├── movement.c                  # Player movement logic
│   ├── player.c                    # Player initialization
│   ├── position.c                  # Position validation
│   ├── rotations.c                 # Camera rotation
│   └── textures.c                  # Texture loading and management
├── get_next_line/                  # File reading utilities
├── utils/                          # Helper functions
└── maps/                           # Sample map files
```

## 🗺️ Map Format

Maps are defined in `.cub` files with the following format:

```
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
WE ./path/to/west_texture.xpm
EA ./path/to/east_texture.xpm

F 220,100,0
C 225,230,220

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Map Elements

- `1`: Wall
- `0`: Empty space
- `N/S/E/W`: Player starting position and orientation
- `F`: Floor color (RGB format)
- `C`: Ceiling color (RGB format)

## 🔧 Technical Details

### Raycasting Algorithm

The engine uses a DDA-based raycasting algorithm to:
1. Cast rays for each vertical screen column
2. Calculate ray intersections with walls
3. Determine wall distances for proper perspective
4. Apply textures based on wall orientation
5. Render floor and ceiling colors

### Performance Features

- Efficient pixel-by-pixel rendering
- Optimized collision detection
- Smooth movement with frame-independent speed
- Minimal memory footprint

## 🐛 Error Handling

The program validates:
- Map file existence and format
- Map enclosure (surrounded by walls)
- Valid player position
- Texture file accessibility
- RGB color value ranges (0-255)
- Proper map characters

## 📝 Notes

- Window resolution: Configurable via `WIN_W` and `WIN_H` defines
- Movement speed: Adjustable in movement functions (default: 0.05)
- Rotation speed: Adjustable in rotation functions (default: 0.03 radians)

## 🙏 Acknowledgments

- 42 Network for the project specifications
- Lode Vandevenne for raycasting tutorials
- MiniLibX documentation and community

---

*This project is part of the 42 school curriculum.*