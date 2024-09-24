# The Maze Project

## Introduction
Welcome to **The Maze Project**! This project showcases a maze game developed using ray casting techniques. The game features dynamic graphics and engaging gameplay.

### Author(s)
- [Marwan Ashraf](https://www.linkedin.com/in/marwan-ashraf-09b840270/)

## Installation
To install this project locally, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/MarwanAshraf03/The-Maze-Project.git
   ```
2. Navigate to the project directory:
   ```bash
   cd The-Maze-Project
   ```
3. Install the necessary dependencies. Ensure you have [SDL2](https://www.libsdl.org/) installed.
4. Compile the project:
   ```bash
   gcc *.c -o Game `sdl2-config --cflags --libs` -lm -Wall -Werror -Wextra -pedantic
   ```
5. Run the game:
   ```bash
   ./Game
   ```

## Usage
Launch the game and navigate through the maze using the keyboard controls. The objective is to find your way to the exit while avoiding obstacles.
## Controls
Here are the keyboard controls for navigating the maze:

| Key                | Action                          |
|--------------------|---------------------------------|
| `M`                | Toggle the minimap              |
| `1` to `6`         | Change the map layout           |
| `Up Arrow`         | Move forward                    |
| `Down Arrow`       | Move backward                   |
| `Right Arrow`      | Rotate clockwise                |
| `Left Arrow`       | Rotate counterclockwise         |
## Contributing
Contributions are welcome! If you would like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature/YourFeature
   ```
3. Make your changes and commit them:
   ```bash
   git commit -m "Add some feature"
   ```
4. Push to the branch:
   ```bash
   git push origin feature/YourFeature
   ```
5. Open a pull request.

## Related Projects
- [MVP](https://github.com/MarwanAshraf03/MVP) - An initial stage of the project.

## Licensing
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
