/*
 * @Author: geekli
 * @Date: 2021-01-07 00:22:03
 * @LastEditTime: 2021-01-07 01:03:32
 * @LastEditors: your name
 * @Description: 
 * @FilePath: /ray_tracing/ray_tracing_in_one_week/10-材质/hittable.hpp
 */
#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.hpp"
#include "rtweekend.hpp"
class material;

struct hit_record {
    point3 p;
    vec3 normal;
    shared_ptr<material> mat_ptr;
    double t;
    bool front_face;

    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }
};

class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif