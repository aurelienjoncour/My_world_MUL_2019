/*
** EPITECH PROJECT, 2019
** my_world_2019
** File description:
** Perlin Noise
*/

#include "my_world.h"

static const sfVector2i vectors[8] =
{
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1},
    {-1, 1},
    {-1, 0},
    {-1, -1}
};

static void dot_product_vector(sfVector2i *vec, sfVector2i *coord_floor,
sfVector2f *coord, double *dot_pt)
{
    sfVector2f coord_point[4];

    coord_point[0].x = coord->x - coord_floor->x;
    coord_point[0].y = coord->y - coord_floor->y;
    coord_point[1].x = coord->x - (coord_floor->x + 1);
    coord_point[1].y = coord->y - coord_floor->y;
    coord_point[2].x = coord->x - coord_floor->x;
    coord_point[2].y = coord->y - (coord_floor->y + 1);
    coord_point[3].x = coord->x - (coord_floor->x + 1);
    coord_point[3].y = coord->y - (coord_floor->y + 1);
    dot_pt[0] = (vec[0].x * coord_point[0].x) + (vec[0].y * coord_point[0].y);
    dot_pt[1] = (vec[1].x * coord_point[1].x) + (vec[1].y * coord_point[1].y);
    dot_pt[2] = (vec[2].x * coord_point[2].x) + (vec[2].y * coord_point[2].y);
    dot_pt[3] = (vec[3].x * coord_point[3].x) + (vec[3].y * coord_point[3].y);
}

static void select_gradients_vectors(sfVector2i *vect, int *vect_idx,
unsigned int *permu)
{
    vect[0] = vectors[permu[vect_idx[0] + permu[vect_idx[1]]] & 7];
    vect[1] = vectors[permu[vect_idx[0] + 1 + permu[vect_idx[1]]] & 7];
    vect[2] = vectors[permu[vect_idx[0] + permu[vect_idx[1] + 1]] & 7];
    vect[3] = vectors[permu[vect_idx[0] + 1 + permu[vect_idx[1] + 1]] & 7];
}

static double interpolation(sfVector2i *coord_floor, sfVector2f *coord,
double *dot_pt)
{
    double delta_x = coord->x - coord_floor->x;
    double delta_y = coord->y - coord_floor->y;
    double sx = 3 * pow(delta_x, 2) - 2 * pow(delta_x, 3);
    double left_smooth = dot_pt[0] + sx * (dot_pt[1] - dot_pt[0]);
    double right_smooth = dot_pt[2] + sx * (dot_pt[3] - dot_pt[2]);
    double sy = 3 * pow(delta_y, 2) - 2 * pow(delta_y, 3);

    return left_smooth + sy * (right_smooth - left_smooth);
}

double perlin(double x, double y, int res, unsigned int *perm)
{
    sfVector2f coord = {x / res, y / res};
    sfVector2i coord_floor = {(int)coord.x, (int)coord.y};
    int vect_idx[2] = {coord_floor.x & 255, coord_floor.y & 255};
    sfVector2i vect[4];
    double dot_pt[4];

    select_gradients_vectors(vect, vect_idx, perm);
    dot_product_vector(vect, &coord_floor, &coord, dot_pt);
    return interpolation(&coord_floor, &coord, dot_pt);
}

void mix_permutation_table(unsigned int *permutation_table)
{
    unsigned int temp;
    int rand_idx;

    for (int i = 0; i <= 255; i++) {
        rand_idx = rand() % 256;
        temp = permutation_table[i];
        permutation_table[i] = permutation_table[rand_idx];
        permutation_table[rand_idx] = temp;
    }
    for (int i = 256; i < 512; i++)
        permutation_table[i] = permutation_table[i - 256];
}
