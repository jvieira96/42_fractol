# 🌌 Fract-ol - 42 School Project

## 🎨 Project Overview

**Fract-ol** is a graphical project at 42 School designed to introduce students to **graphical programming**, **mathematical visualization**, and **event-driven design**. The goal is to render and explore beautiful **fractal sets** (like Mandelbrot and Julia) using real-time input, zooming, and movement.

This project helped me dive into:

- 🖼 **Graphics programming** using the **MiniLibX** library
- 🔢 **Complex numbers** and how they behave in iterative mathematical functions
- 🧮 The math behind famous fractals like:
  - **Mandelbrot set**
  - **Julia set**
  - *(+ optional custom sets)*
- 🖱 **Event handling** for keyboard and mouse input (zoom, move, switch sets)
- 🧠 **Pixel manipulation** at low level (drawing pixel-by-pixel)
- ⚡️ Real-time rendering and performance optimizations

## 🛠 Technical Concepts Used

- **MiniLibX**:
  - Simple X-Window interface provided by 42
  - Functions like `mlx_init`, `mlx_new_window`, `mlx_put_image_to_window`
  - Handling mouse and keyboard events (`mlx_hook`, `mlx_mouse_hook`, etc.)

- **Image buffers**:
  - Drawing pixels to an off-screen buffer and rendering in one call
  - Using `mlx_get_data_addr` to directly manipulate image memory

- **Mathematics**:
  - Working with **complex numbers** `(a + bi)` in iterative functions
  - Understanding **escape time algorithms**
  - Mapping screen coordinates to the complex plane

- **User input**:
  - Zooming in/out with mouse wheel or scroll
  - Panning the view with arrow keys
  - Changing color palettes or fractal types with keys

## ✨ Fractals Implemented

- 🌀 **Mandelbrot Set**
- 🌱 **Julia Set** (with real-time parameter manipulation)

## 🧠 Key Features

- Dynamic zoom and movement with smooth rendering
- Color gradients based on iteration depth
- Custom hooks for controls, reset, and switch modes

## 🚫 Challenges Overcome

- ✅ Mapping pixels accurately to the complex plane
- ✅ Handling floating point precision in deep zooms
- ✅ Managing performance for high-resolution ren
