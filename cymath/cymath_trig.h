//
// Created by yanni on 12.09.2023.
//

#ifndef CYBERTOPIC_ENGINE_1_CYMATH_TRIG_H
#define CYBERTOPIC_ENGINE_1_CYMATH_TRIG_H

#include "cymath_std.h"

namespace cy
{
    namespace math
    {
        namespace trig
        {
            char mode[4] = "CBF";
            long double MBF_DOUBLE[100];
            long int MBF_INT[100];
            vector2<long int> MBF_VEC2_INT[100];
            vector3<long int> MBF_VEC3_INT[100];
            vector4<long int> MBF_VEC4_INT[100];
            vector2<long double> MBF_VEC2_DOUBLE[100];
            vector3<long double> MBF_VEC3_DOUBLE[100];
            vector4<long double> MBF_VEC4_DOUBLE[100];
        }
    }
}

#endif //CYBERTOPIC_ENGINE_1_CYMATH_TRIG_H
