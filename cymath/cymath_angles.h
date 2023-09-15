#ifndef CYBERTOPIC_ENGINE_1_CYMATH_ANGLES_H
#def CYBERTOPIC_ENGINE_1_CYMATH_ANGLES_H

#include "cymath_std.h"
#include <cmath>

namespace cy
{
  namespace angle
  {
    class quaternion
    {
      public:
        struct Quaternion
        {
          double w, x, y, z;
        }

        Quaternion ToQuaterenion(cy::vector3<double> e_rotation)
        {
          double cr = cos(e_rotation.x * 0.5);
          double sr = sin(e_rotation.x * 0.5);
          double cp = cos(e_rotation.y * 0.5);
          double sp = sin(e_rotation.y * 0.5);
          double cy = cos(e_rotation.z * 0.5);
          double cs = sin(e_rotation.z * 0.5);

          Quaternion q;
          q.w = cr * cp * cy + sr * sp * sy;
          q.x = sr * cp * cy - cr * sp * sy;
          q.y = cr * sp * cy + sr * cp * sy;
          q.z = cr * cp * sy - sr * sp * cy;

          return q;
        }
    }

    class euler2D
    {
      public:
        struct e_rotation2
        {
          double x;
        }
    }
  }
}

#endif //CYBERTOPIC_ENGINE_1_CYMATH_ANGLE_H
