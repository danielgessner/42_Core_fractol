# 🌀 fractol - The Infinite Beauty of Mathematics

<div align="center">

[![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![MLX42](https://img.shields.io/badge/MLX42-Graphics-FF6B6B?style=for-the-badge)](https://github.com/codam-coding-college/MLX42)
[![Norminette](https://img.shields.io/badge/Norminette-✅_Passing-success?style=for-the-badge)](https://github.com/42School/norminette)
[![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge)]()

*"Mathematics is the art of giving the same name to different things" - Henri Poincaré*

</div>

---

## 🎯 Project Overview

**fractol** is where 42 students discover the mesmerizing world of fractal geometry and computer graphics. This project combines complex mathematics, graphics programming, and interactive visualization to create stunning fractal renderers. It's not just about drawing pretty pictures - it's about understanding the infinite complexity that emerges from simple mathematical rules.

> *"Clouds are not spheres, mountains are not cones, coastlines are not circles, and bark is not smooth, nor does lightning travel in a straight line." - Benoit Mandelbrot*

## 🌟 The Magic of Fractals

Fractals are **infinitely complex patterns** that are self-similar across different scales. They reveal the hidden mathematical beauty in nature and showcase how simple equations can generate infinite complexity.

### 🎨 Fractal Gallery

#### 🌀 Mandelbrot Set
The most famous fractal - a set of complex numbers that remain bounded under iteration.

**Mathematical Formula:**
```
z(n+1) = z(n)² + c
where z(0) = 0 and c is a complex number
```

#### 🌺 Julia Sets  
Beautiful variations where the constant changes, creating diverse and stunning patterns.

**Mathematical Formula:**
```
z(n+1) = z(n)² + c
where z(0) = coordinate and c is a complex constant
```

#### ⚡ Burning Ship
A variation that creates ship-like fractal patterns through absolute value operations.

**Mathematical Formula:**
```
z(n+1) = (|Re(z(n))| + i|Im(z(n))|)² + c
```

---

## 🏗️ Technical Architecture

### 🧠 Core Data Structures

#### Complex Number System
```c
typedef struct s_complex {
    double re;  // Real part
    double im;  // Imaginary part
} t_complex;
```

#### Fractal Engine
```c
typedef struct s_fractal {
    mlx_t       *mlx;       // MLX42 instance
    mlx_image_t *img;       // Render target
    int         type;       // Fractal type
    double      zoom;       // Zoom level
    double      shift_x;    // X offset
    double      shift_y;    // Y offset
    t_complex   c;          // Julia constant
} t_fractal;
```

### 🎭 System Components

| Module | Purpose | Responsibility |
|--------|---------|----------------|
| **Graphics Engine** | Rendering | Pixel manipulation, color generation |
| **Mathematical Core** | Calculations | Complex number operations, iterations |
| **Input Handler** | Interaction | Keyboard and mouse event processing |
| **Fractal Generator** | Algorithms | Mandelbrot, Julia, and custom fractals |

---

## 🎪 Interactive Features

### ⌨️ Keyboard Controls
| Key | Action | Description |
|-----|--------|-------------|
| `ESC` | Exit | Close the program |
| `↑ ↓ ← →` | Pan | Navigate around the fractal |
| `+/-` | Zoom | Zoom in/out of the fractal |
| `R` | Reset | Return to default view |
| `C` | Color | Cycle through color schemes |

### 🖱️ Mouse Controls
| Action | Effect | Description |
|--------|--------|-------------|
| **Scroll Up** | Zoom In | Magnify the fractal |
| **Scroll Down** | Zoom Out | Reduce magnification |
| **Click** | Recenter | Center view on click point |

### 🎨 Color Schemes
- **Classic**: Traditional blue-black gradient
- **Fire**: Red-orange-yellow heat mapping
- **Ocean**: Blue-green aquatic theme
- **Psychedelic**: Rainbow color explosion
- **Monochrome**: Elegant black and white

---

## 🚀 Quick Start

```bash
# Clone this mathematical masterpiece
git clone git@github.com:danielgessner/42_Core_fractol.git
cd 42_Core_fractol

# Build the project (includes MLX42 compilation)
make

# Launch different fractals
./fractol mandelbrot
./fractol julia -0.7 0.27015
./fractol julia -0.8 0.156
./fractol burning_ship
```

## 💡 Usage Examples

### 🎨 Basic Fractal Rendering
```bash
# Render the classic Mandelbrot set
./fractol mandelbrot

# Explore Julia sets with different constants
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
./fractol julia -0.70176 -0.3842

# Generate the Burning Ship fractal
./fractol burning_ship
```

### 🔥 Advanced Julia Exploration
```bash
# Famous Julia set constants
./fractol julia -0.7269 0.1889     # Spiral
./fractol julia -0.8 0.156         # Lightning
./fractol julia -0.74529 0.11307   # Douady Rabbit
./fractol julia 0.3 0.5            # Dendrite
./fractol julia -1.25 0            # Airplane
```

### 🧪 Mathematical Experiments
```bash
# Explore the boundary of convergence
./fractol julia -0.75 0.11
./fractol julia -0.1 0.651
./fractol julia -0.123 0.745

# Study self-similarity at different scales
# Use mouse scroll to zoom deep into patterns
```

---

## 🎨 Color Theory & Visualization

### 🌈 Color Mapping Algorithms

#### Escape Time Coloring
```c
int color_from_iter(int iter) {
    if (iter == MAX_ITER)
        return 0x000000;  // Black for points in set
    
    // Map iteration count to color spectrum
    double t = (double)iter / MAX_ITER;
    int red = (int)(255 * (1 - t));
    int green = (int)(255 * t * (1 - t) * 4);
    int blue = (int)(255 * t);
    
    return (red << 16) | (green << 8) | blue;
}
```

#### Smooth Coloring
```c
// Eliminate color banding with continuous coloring
double smooth_color = iter + 1 - log(log(magnitude)) / log(2);
```

### 🎯 Performance Optimization

#### Optimized Iteration
```c
int mandelbrot(t_complex c) {
    double x = 0, y = 0;
    double x2, y2;
    int iter = 0;
    
    while (iter < MAX_ITER) {
        x2 = x * x;
        y2 = y * y;
        
        if (x2 + y2 > 4.0)  // Escape radius
            break;
            
        y = 2 * x * y + c.im;
        x = x2 - y2 + c.re;
        iter++;
    }
    return iter;
}
```

---

## 🛠️ Build System & Dependencies

### 📦 Project Structure
```
fractol/
├── Makefile                # Build configuration
├── fractol.h              # Main header file
├── main.c                 # Program entry point
├── calculations.c         # Mathematical algorithms
├── graphics.c             # Rendering engine
├── hooks.c                # Event handling
├── atof.c                 # String to float conversion
├── MLX42/                 # Graphics library (submodule)
└── libft_ex/              # Extended libft with printf
```

### 🔧 Compilation Process
```bash
# Automatic dependency building
make        # Build everything
make clean  # Remove object files
make fclean # Remove everything
make re     # Rebuild from scratch

# MLX42 is automatically compiled as dependency
# GLFW and OpenGL libraries are linked
```

### ⚙️ System Requirements
- **OS**: macOS or Linux
- **Graphics**: OpenGL support
- **Libraries**: GLFW, pthread, math library
- **Compiler**: GCC or Clang with C99 support

---

## 🧮 Mathematical Deep Dive

### 🔢 Complex Number Operations

#### Basic Operations
```c
t_complex complex_add(t_complex a, t_complex b) {
    return (t_complex){a.re + b.re, a.im + b.im};
}

t_complex complex_square(t_complex z) {
    return (t_complex){
        z.re * z.re - z.im * z.im,
        2 * z.re * z.im
    };
}

double complex_magnitude_squared(t_complex z) {
    return z.re * z.re + z.im * z.im;
}
```

#### Coordinate Transformations
```c
t_complex screen_to_complex(int x, int y, t_fractal *f) {
    double re = (x - WIDTH/2.0) / (f->zoom * WIDTH/4.0) + f->shift_x;
    double im = (y - HEIGHT/2.0) / (f->zoom * HEIGHT/4.0) + f->shift_y;
    return (t_complex){re, im};
}
```

### 🎯 Fractal Mathematics

#### Mandelbrot Set Theory
The Mandelbrot set consists of all complex numbers `c` for which the sequence:
```
z₀ = 0
z₁ = 0² + c = c
z₂ = c² + c
z₃ = (c² + c)² + c
...
```
remains bounded (doesn't escape to infinity).

#### Julia Set Theory
Julia sets are related to the Mandelbrot set but fix the constant `c` and vary the starting point `z₀`.

---

## 🎮 Interactive Controls Deep Dive

### ⌨️ Advanced Navigation
```c
void key_hook(mlx_key_data_t keydata, void *param) {
    t_fractal *f = (t_fractal *)param;
    
    if (keydata.key == MLX_KEY_ESCAPE)
        mlx_close_window(f->mlx);
    else if (keydata.key == MLX_KEY_UP)
        f->shift_y -= SHIFT_STEP / f->zoom;
    else if (keydata.key == MLX_KEY_EQUAL)
        f->zoom *= ZOOM_FACTOR;
    // ... additional controls
    
    draw_fractal(f);  // Re-render
}
```

### 🖱️ Precision Zooming
```c
void scroll_hook(double xdelta, double ydelta, void *param) {
    t_fractal *f = (t_fractal *)param;
    
    if (ydelta > 0)
        f->zoom *= 1.1;  // Zoom in
    else
        f->zoom /= 1.1;  // Zoom out
        
    draw_fractal(f);
}
```

---

## 🧪 Testing & Exploration

### 🎯 Fractal Parameters
```bash
# Test different zoom levels
./fractol mandelbrot
# Use scroll wheel to zoom from 1x to 1000x+

# Explore Julia set parameter space
for real in -1.0 -0.5 0.0 0.5; do
    for imag in -1.0 -0.5 0.0 0.5; do
        ./fractol julia $real $imag
    done
done
```

### 🔬 Mathematical Verification
```bash
# Verify escape radius calculations
./fractol julia 0 0        # Should show unit circle
./fractol julia -2 0       # Should escape immediately
./fractol julia 0.25 0     # Boundary case
```

### 🏁 Performance Benchmarks
```c
// Measure rendering performance
clock_t start = clock();
draw_fractal(fractal);
clock_t end = clock();
double time = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Render time: %.3f seconds\n", time);
```

---

## 📋 42 Standards Compliance

### ✅ Norminette Perfect
- Maximum 25 lines per function
- Maximum 5 functions per file
- No forbidden constructs (`for`, `switch`, `case`, `goto`)
- Proper 42 header format
- Clean memory management

### 🎯 Project Requirements
- **Graphics**: MLX42 or MiniLibX for rendering
- **Fractals**: Minimum Mandelbrot + Julia sets
- **Interactivity**: Zoom, pan, and parameter controls
- **Mathematics**: Proper complex number handling
- **Performance**: Real-time rendering capabilities

---

## 🌟 Advanced Features & Optimizations

### ⚡ Performance Enhancements
- **Escape radius optimization**: Early termination
- **Symmetry exploitation**: Mirror calculations
- **Adaptive iteration**: Variable max iterations based on zoom
- **Multi-threading**: Parallel pixel calculations

### 🎨 Visual Improvements
- **Smooth coloring**: Eliminate iteration bands
- **Multiple color palettes**: Dynamic color schemes
- **Anti-aliasing**: Smooth fractal edges
- **Animation**: Time-varying parameters

### 🧮 Mathematical Extensions
- **Additional fractals**: Burning Ship, Newton, Tricorn
- **Higher precision**: Extended double or arbitrary precision
- **3D fractals**: Mandelbulb and quaternion fractals
- **Custom equations**: User-defined fractal formulas

---

## 📖 The Philosophy of Fractals

> *"Fractals teach us that infinite complexity can emerge from simple rules, that beauty exists at every scale, and that mathematics is the language of nature's deepest patterns."*

### 🎭 Why Fractals Matter

- **Self-similarity**: Patterns repeat at every scale
- **Infinite detail**: Zoom forever and find new structures
- **Natural modeling**: Describe coastlines, mountains, clouds
- **Computational beauty**: Art emerges from mathematics
- **Chaos theory**: Small changes create dramatic effects

### 🌊 Fractals in Nature
- **Coastlines**: Fractal dimension between 1 and 2
- **Trees**: Branching patterns follow fractal rules
- **Clouds**: Self-similar structure at all scales
- **Lightning**: Fractal pathways through space
- **Blood vessels**: Optimal fractal distribution networks

---

## 🚀 Real-World Applications

This fractal knowledge applies to:

- 🎨 **Computer Graphics**: Procedural texture generation
- 🌍 **Geography**: Modeling natural terrain and coastlines
- 📡 **Antenna Design**: Fractal antennas for compact devices
- 💊 **Medicine**: Understanding lung, blood vessel structures
- 📈 **Finance**: Market analysis using fractal mathematics
- 🎵 **Music**: Compositional techniques based on self-similarity

---

## 🎓 Learning Outcomes

After mastering fractol, you understand:

- **Complex number mathematics**: Operations in the complex plane
- **Graphics programming**: Pixel manipulation and rendering
- **Mathematical visualization**: Translating equations to images
- **Interactive programming**: Real-time user input handling
- **Performance optimization**: Efficient calculation algorithms
- **Mathematical beauty**: The art hidden in equations

---

<div align="center">

**Made with ❤️ at 42 Heilbronn**

*Where mathematics becomes art*

---

*"The beauty of fractals lies not in their complexity, but in the simplicity of their creation"*

</div>
