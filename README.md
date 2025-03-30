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
   git clone https://github.com/C-JeanDev/RayAlgoViz.git
   cd AlgoVisualizer
2. Makefile:
     ```bash
     make clean && make && ./algo.out

## 📸 Screenshots
![Screenshot from 2025-03-24 13-49-51](https://github.com/user-attachments/assets/51476fd6-e884-4fe4-aed8-61b84167ca26)
![Screenshot from 2025-03-24 13-52-14](https://github.com/user-attachments/assets/8224ff8c-c2cb-432f-b434-dae00e13d63d)
![Screenshot from 2025-03-24 13-54-17](https://github.com/user-attachments/assets/6423e206-91e2-4e78-93b4-c47381139851)

# 💡 Future Implementations
  - Quick Sort Algorithm
  - Red rectangles when accessed and/or compared

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
