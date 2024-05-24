/**
 * @file structs.h
 * @brief Include file for the structures used in the project.
 * 
 * This file contains the definitions of various structures used 
 * throughout the MiniRT project. These structures include vectors, 
 * matrices, geometric shapes, lighting models, materials, and more.
 * 
 * @version 0.1
 * @date 2024-05-22
 * 
 * @note This file is part of the MiniRT project.
 * @see https://github.com/your-repo-url (replace with actual repo URL)
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef STRUCTS_H
# define STRUCTS_H

# define MATRIX_SIZE 4
# define YES 1
# define NO 0

# include "libft.h"
# include "key_map.h"
# include <stdbool.h>
# include <math.h>

/**
 * @brief 3D vector structure.
 */
typedef struct s_vec3
{
    double x; /**< X coordinate */
    double y; /**< Y coordinate */
    double z; /**< Z coordinate */
    double w; /**< W coordinate (for homogenous coordinates) */
} t_vec3;

/**
 * @brief Matrix structure.
 * 
 * Represents a 4x4 matrix used for transformations.
 */
typedef struct s_matrix
{
    int rows; /**< Number of rows in the matrix */
    int cols; /**< Number of columns in the matrix */
    double data[MATRIX_SIZE][MATRIX_SIZE]; /**< Matrix data */
} t_matrix;

typedef t_vec3 t_color; /**< Color type represented as a vector */
typedef t_vec3 t_point; /**< Point type represented as a vector */

/**
 * @brief Canvas structure.
 * 
 * Represents a drawing surface.
 */
typedef struct s_canvas
{
    int width; /**< Width of the canvas */
    int height; /**< Height of the canvas */
    t_color **pixels; /**< 2D array of pixels */
} t_canvas;

/**
 * @brief Ray structure.
 * 
 * Represents a ray with an origin and direction.
 */
typedef struct s_ray
{
    t_point origin; /**< Origin of the ray */
    t_vec3 direction; /**< Direction of the ray */
} t_ray;

/**
 * @brief Lighting structure.
 * 
 * Contains information about various lighting components.
 */
typedef struct s_lighting
{
    t_color diffuse; /**< Diffuse color */
    t_color specular; /**< Specular color */
    t_color ef_color; /**< Effective color */
    t_vec3 lightv; /**< Light vector */
    t_color amb; /**< Ambient color */
    double light_dot_normal; /**< Dot product of light and normal vectors */
    t_vec3 reflectv; /**< Reflection vector */
    double reflect_dot_eye; /**< Dot product of reflection and eye vectors */
    double factor; /**< Factor for lighting calculations */
    t_color color; /**< Final color after lighting calculations */
} t_lighting;

/**
 * @brief Light source structure.
 * 
 * Represents a point light source.
 */
typedef struct s_light
{
    t_vec3 position; /**< Position of the light */
    double brightness; /**< Brightness of the light */
    t_color intensity; /**< Intensity of the light */
    t_lighting *lighting; /**< Pointer to the lighting details */
    bool in_shadow; /**< Indicates if the light is in shadow */
} t_light;

/**
 * @brief Enumeration for pattern styles.
 */
typedef enum e_style
{
    NONE, /**< No pattern */
    STRIPES, /**< Striped pattern */
    GRADIENT, /**< Gradient pattern */
    RING, /**< Ring pattern */
    CHECKERS, /**< Checkered pattern */
    XPM /**< XPM pattern */
} t_style;

/**
 * @brief Pattern structure.
 * 
 * Represents a pattern with transformation matrices.
 */
typedef struct s_pattern
{
    t_style type; /**< Type of the pattern */
    t_color a; /**< First color of the pattern */
    t_color b; /**< Second color of the pattern */
    t_matrix transform; /**< Transformation matrix for the pattern */
    t_matrix inverted; /**< Inverted transformation matrix */
    t_canvas xpm; /**< XPM canvas for patterns */
} t_pattern;

/**
 * @brief Material structure.
 * 
 * Represents the material properties of an object.
 */
typedef struct s_material
{
    t_color color; /**< Base color of the material */
    t_color ambient; /**< Ambient color component */
    double diffuse; /**< Diffuse reflection coefficient */
    double specular; /**< Specular reflection coefficient */
    double shininess; /**< Shininess factor for specular highlights */
    t_pattern pattern; /**< Pattern applied to the material */
    double reflective; /**< Reflective property */
    double transparency; /**< Transparency property */
    double refractive_index; /**< Refractive index */
} t_material;

/**
 * @brief Bhaskara's formula structure.
 * 
 * Used for solving quadratic equations.
 */
typedef struct s_bhask
{
    double a; /**< Coefficient a */
    double b; /**< Coefficient b */
    double c; /**< Coefficient c */
    double discriminant; /**< Discriminant value */
    double t0; /**< First root */
    double t1; /**< Second root */
} t_bhask;

/**
 * @brief Sphere structure.
 * 
 * Represents a sphere in 3D space.
 */
typedef struct s_sphere
{
    int id; /**< Unique identifier for the sphere */
    t_vec3 center; /**< Center of the sphere */
    double diameter; /**< Diameter of the sphere */
} t_sphere;

/**
 * @brief Plane structure.
 * 
 * Represents a plane in 3D space.
 */
typedef struct s_plane
{
    int id; /**< Unique identifier for the plane */
    t_vec3 point; /**< Point on the plane */
} t_plane;

/**
 * @brief Cylinder structure.
 * 
 * Represents a cylinder in 3D space.
 */
typedef struct s_cylinder
{
    int id; /**< Unique identifier for the cylinder */
    double minimum; /**< Minimum extent of the cylinder */
    double maximum; /**< Maximum extent of the cylinder */
    t_vec3 center; /**< Center of the cylinder */
    double diameter; /**< Diameter of the cylinder */
    double height; /**< Height of the cylinder */
    t_vec3 normal; /**< Normal vector of the cylinder */
    bool closed; /**< Indicates if the cylinder is closed at the ends */
} t_cylinder;

/**
 * @brief Cone structure.
 * 
 * Represents a cone in 3D space.
 */
typedef struct s_cone
{
    int id; /**< Unique identifier for the cone */
    double minimum; /**< Minimum extent of the cone */
    double maximum; /**< Maximum extent of the cone */
    t_vec3 center; /**< Center of the cone */
    double diameter; /**< Diameter of the cone */
    double height; /**< Height of the cone */
    bool closed; /**< Indicates if the cone is closed at the base */
} t_cone;

/**
 * @brief Cube structure.
 * 
 * Represents a cube in 3D space.
 */
typedef struct s_cube
{
    int id; /**< Unique identifier for the cube */
    t_vec3 center; /**< Center of the cube */
    double side; /**< Length of the cube's side */
} t_cube;

/**
 * @brief Triangle structure.
 * 
 * Represents a triangle in 3D space.
 */
typedef struct s_triangle
{
    int id; /**< Unique identifier for the triangle */
    t_point p1; /**< First vertex of the triangle */
    t_point p2; /**< Second vertex of the triangle */
    t_point p3; /**< Third vertex of the triangle */
    t_vec3 e1; /**< Edge vector from p1 to p2 */
    t_vec3 e2; /**< Edge vector from p2 to p3 */
    t_vec3 normal; /**< Normal vector of the triangle */
} t_triangle;

/**
 * @brief Enumeration for geometric shape types.
 */
typedef enum e_type
{
    SPHERE, /**< Sphere type */
    PLANE, /**< Plane type */
    CYLINDER, /**< Cylinder type */
    CONE, /**< Cone type */
    CUBE, /**< Cube type */
    TRIANGLE /**< Triangle type */
} t_type;

/**
 * @brief Geometric shapes structure.
 * 
 * Union of different geometric shapes with common properties.
 */
typedef struct s_shapes
{
    t_type type; /**< Type of the shape */
    union
    {
        t_sphere *sphere; /**< Sphere shape */
        t_plane *plane; /**< Plane shape */
        t_cylinder *cylinder; /**< Cylinder shape */
        t_cone *cone; /**< Cone shape */
        t_cube *cube; /**< Cube shape */
        t_triangle *triangle; /**< Triangle shape */
    };
    t_matrix transform; /**< Transformation matrix */
    t_matrix inverted; /**< Inverted transformation matrix */
    t_material material; /**< Material of the shape */
    t_vec3 normal; /**< Normal vector */
} t_shapes;

/**
 * @brief Intersection structure.
 * 
 * Represents an intersection between a ray and a shape.
 */
typedef struct s_intersection
{
    double t; /**< Distance from the ray origin to the intersection point */
    t_shapes *object; /**< Pointer to the intersected object */
} t_intersection;

typedef t_list t_intersections; /**< List of intersections */

/**
 * @brief Image structure.
 * 
 * Represents an image with its properties.
 */
typedef struct s_image
{
    int line_length; /**< Length of a line in bytes */
    int bpp; /**< Bits per pixel */
    int endian; /**< Endianness of the image */
    int **color; /**< 2D array of colors */
    void *img; /**< Image data */
    char *addr; /**< Address of the image data */
} t_image;

/**
 * @brief Computed values structure.
 * 
 * Contains precomputed values for shading and intersection tests.
 */
typedef struct s_comps
{
    double t; /**< Distance to the intersection point */
    t_shapes *object; /**< Intersected object */
    t_point point; /**< Intersection point */
    t_vec3 eyev; /**< Eye vector */
    t_vec3 normalv; /**< Normal vector at the intersection */
    bool inside; /**< Indicates if the intersection is inside the object */
    t_point over_point; /**< Point slightly above the intersection */
    t_point under_point; /**< Point slightly below the intersection */
    t_vec3 reflectv; /**< Reflection vector */
    double n1; /**< Refractive index before the intersection */
    double n2; /**< Refractive index after the intersection */
} t_comps;

/**
 * @brief Ambient light structure.
 * 
 * Represents ambient lighting in the scene.
 */
typedef struct s_amb
{
    double ratio; /**< Ambient light ratio */
    t_vec3 color; /**< Color of the ambient light */
} t_amb;

/**
 * @brief Camera structure.
 * 
 * Represents a camera in the 3D scene.
 */
typedef struct s_camera
{
    int hsize; /**< Horizontal size of the view */
    int vsize; /**< Vertical size of the view */
    t_matrix transform; /**< Transformation matrix */
    t_matrix inverted; /**< Inverted transformation matrix */
    double half_width; /**< Half width of the view */
    double half_height; /**< Half height of the view */
    double pixel_size; /**< Size of a pixel */
    t_vec3 point; /**< Position of the camera */
    t_vec3 normalized; /**< Normalized view vector */
    double fov; /**< Field of view */
} t_camera;

/**
 * @brief Scene structure.
 * 
 * Represents the entire scene including objects, lights, and camera.
 */
typedef struct s_scene
{
    char *line; /**< Current line being processed */
    char **split; /**< Split line data */
    t_camera *camera; /**< Camera in the scene */
    t_amb ambient; /**< Ambient lighting */
    t_shapes *new; /**< New shape being added */
    t_list *objects; /**< List of objects in the scene */
    t_light *lights; /**< Light source in the scene */
    t_list *lights_list; /**< List of lights in the scene */
    char *msg_error; /**< Error message */
    int qtys[9]; /**< Quantities of various elements */
    int bonus_qtys[4]; /**< Quantities of bonus elements */
} t_scene;

/**
 * @brief World structure.
 * 
 * Represents the entire world including the scene and rendering data.
 */
typedef struct s_world
{
    char **split; /**< Split input data */
    void *mlx; /**< MiniLibX instance */
    void *win; /**< MiniLibX window */
    t_list *objects; /**< List of objects */
    t_image img; /**< Image data */
    t_camera *camera; /**< Camera in the world */
    t_canvas canvas; /**< Canvas for rendering */
    t_list *lights; /**< List of lights */
    t_camera *zero; /**< Default camera */
    t_key_map key; /**< Key mapping */
} t_world;

/**
 * @brief Area structure.
 * 
 * Represents a rectangular area.
 */
typedef struct s_area
{
    int w_l; /**< Left width */
    int w_r; /**< Right width */
    int h_t; /**< Top height */
    int h_b; /**< Bottom height */
} t_area;

#endif /* STRUCTS_H */
