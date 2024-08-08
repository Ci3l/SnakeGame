# SNAKE

## Description
This is a very basic Snake game implemented in C, created as a learning project to solidify my understanding of the C programming language. The project covers essential programming concepts and demonstrates how to build a simple game from scratch using C.

## Features
- **Basic Snake Gameplay**: Navigate the snake around the screen, collecting apples to grow in length.
- **Score Tracking**: The score increases as the snake consumes apples.
- **Adjustable Speed**: Choose between different speed levels to change the game's difficulty.
- **Boundary Detection**: The game ends if the snake hits the wall or itself.

## How to Use the Project
To compile and run this project on Windows, you'll need MinGW. If you don't already have it, you can download it [here](https://sourceforge.net/projects/mingw/). Make sure to add MinGW to your system's PATH.

### Steps to Compile and Run
1. Clone the repository to your local machine.
2. Open PowerShell and navigate to the `src` directory of the project. Replace the path in the command below with the path where `main.c` is located on your machine:
 ```powershell
 cd "c:\Users\Utilisateur\Documents\SOURCE\GitHub\snake\src\"
 ```
3. Compile and run the game with the following command:
 ```powershell
 gcc main.c -o main ; if ($?) { .\main }
 ```
This command compiles the C code and runs the resulting executable.

### Troubleshooting
If you encounter any issues, feel free to contact me via the email address provided in my profile, or open an issue on GitHub.

### Participation
I welcome contributions and suggestions to improve this project. If you would like to contribute, you can submit a pull request or open an issue on GitHub.

### License
This project is licensed under the MIT License. For more details, see the LICENSE file.
