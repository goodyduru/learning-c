#include <math.h>
#include <stdio.h>

struct point{
    int x;
    int y;
};

struct rect {
    struct point top_left;
    struct point top_right;
    struct point bottom_left;
    struct point bottom_right;
};

struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct rect makerect(struct point points[]) {
    struct rect my_rect;
    my_rect.top_left = points[0];
    my_rect.top_right = points[1];
    my_rect.bottom_left = points[2];
    my_rect.bottom_right = points[3];
    return my_rect;
}

double dist(struct point pt1, struct point pt2) {
    return sqrt(pow(pt2.x - pt1.x, 2.0) + pow(pt2.y - pt1.y, 2.0));
}

double area(struct rect my_rect) {
    double width = dist(my_rect.top_right, my_rect.top_left);
    double height = dist(my_rect.top_right, my_rect.bottom_right);
    return width * height;
}


double area_ptr(struct rect *my_rect) {
    double width = dist(my_rect->top_right, my_rect->top_left);
    double height = dist(my_rect->top_right, my_rect->bottom_right);
    return width * height;
}

int main() {
    struct point first_point = makepoint(20, 30);
    struct point second_point = makepoint(30, 30);
    float distance = dist(first_point, second_point);
    printf("Distance between two points: %5.3f\n", distance);

    struct point rect_points[4] = {
        makepoint(20, 50),
        makepoint(50, 50),
        makepoint(20, 10),
        makepoint(50, 10)
    };
    struct rect fine_rect = makerect(rect_points);
    printf("Area of rectangle: %6.2f\n", area(fine_rect));

    struct point arect_points[4] = {
        makepoint(20, 50),
        makepoint(60, 50),
        makepoint(20, 10),
        makepoint(60, 10)
    };
    struct rect another_rect = makerect(arect_points);
    printf("Area of ptr rectange: %6.2f\n", area_ptr(&another_rect));
}