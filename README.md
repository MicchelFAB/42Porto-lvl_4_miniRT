# MiniRT

MiniRT is a lightweight ray tracing renderer written in C, designed for educational purposes to explore the fundamentals of computer graphics and ray tracing.

<p align="center">
<img src="https://github.com/ayogun/42-project-badges/blob/main/badges/minirtm.png" alt="mamaral-'s 42 miniRT Score" /></br>
<a href="https://github.com/Coday-meric/badge42"><img src="https://badge42.coday.fr/api/v2/cltzzvrp61460201p4yeptz0xk/project/3659606" alt="mamaral-'s 42 miniRT Score" /></a>
</p>

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Features

- Simple and clean C codebase.
- Supports rendering of spheres, planes, cylinders, cones, cubes, and triangles.
- Multi-threaded rendering for improved performance.
- Bonus features include support for custom scene files and ambient lighting, textures, reflection and refraction.

   
   [SEE THE DOCUMENTATION](https://micchelfab.github.io/42Porto-lvl_4_miniRT/)

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/MicchelFAB/42Porto-lvl_4_miniRT.git
   ```

2. Navigate to the project directory:

   ```bash
   cd 42Porto-lvl_4_miniRT
   ```

3. Download the minilibx Library and compile the project:

   ```bash
   make download
   make
   ```

4. Compile the bonus:

   ```bash
   make bonus
   ```

## Usage

5. Run MiniRT with a scene file: 

   ```bash
   ./miniRT scenes/mandatory/manual.rt
   ```

	OR

	```bash
	make run
   ```

6. Run the MiniRT Bonus with a file:

   ```bash
   ./miniRT_bonus scenes/bonus/manual_bonus.rt
   ```

	OR


   ```bash
   make brun
   ```

## Examples

The manual.rt scene file contains the instructions to render a simple scene with all the mandatory shapes, camera and light configurations. 

![Manual](https://github.com/MicchelFAB/42Porto-lvl_4_miniRT/blob/main/documentation/mandatory.png)

The manual_bonus.rt scene file contains the instructions to render a more complex scene with all the mandatory shapes, camera and light configurations, as well as the bonus shapes and light configurations, patterns, textures and different materials.

![Manual Bonus](https://github.com/MicchelFAB/42Porto-lvl_4_miniRT/blob/main/documentation/bonus.gif)

## Contributing

This project was developed as part of the 42Porto curriculum. And had the help of my colleagues [@someoneisanna](https://github.com/someoneisanna), [@BelmiroRodrigues](https://github.com/BelmiroRodrigues) and [@aamaral-42](https://github.com/aamaral-42)

## License

This project is licensed under the MIT License - see the LICENSE file for details.