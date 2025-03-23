# AlgoVisualizer 

RayAlgoViz is an interactive sorting algorithm visualizer built with Raylib. It animates various sorting algorithms and provides useful insights such as execution time, number of comparisons, and assignation/swaps performed.

## ✨ Features

- Visualization of sorting algorithms:
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort 
  - Quick Sort (To implement)
- Real-time display of:
  - Number of comparisons
  - Number of assignation/swaps

- Simple and intuitive interface with Raylib
- Makefile support for easy compilation and execution

## 🛠 Requirements

- **Raylib** (latest version recommended)
- **C/C++ Compiler** (GCC, Clang, MinGW, etc.)
- **Make** (to use the Makefile)

## 🚀 Installation & Execution

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/RayAlgoViz.git
   cd AlgoVisualizer
2. Makefile:
     ```bash
     make clean && make && ./algo.out

## 📸 Screenshots
![Screenshot from 2025-03-19 22-53-38](https://github.com/user-attachments/assets/45cc5793-61dd-4030-977a-ed4f2455ded3)
![Screenshot from 2025-03-19 22-55-15](https://github.com/user-attachments/assets/76067f74-295b-4f4d-a752-a6cc2f85a8f0)
![Screenshot from 2025-03-19 22-55-33](https://github.com/user-attachments/assets/06ba9143-51ce-4b80-aa41-06b2685c4c9b)


## 🏗 Project Structure

  ```bash
      AlgoVisualizer/
      │── include/            # Header and utility files
      │   ├── button.c        # Button implementation
      │   ├── button.h        # Button header
      │   ├── rect.c          # Rectangle implementation
      │   ├── rect.h          # Rectangle header
      │   ├── vector.c        # Vector implementation
      │   ├── vector.h        # Vector header
      │── src/                # Source code
      │   ├── main.c          # Main file
      │── LICENSE.txt         # License file
      │── Makefile            # Build file
      │── README.md           # Documentation
