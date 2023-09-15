//
// Created by yanni on 14.09.2023.
//
#ifndef CYBERTOPIC_ENGINE_1_BUFFER_H
#define CYBERTOPIC_ENGINE_1_BUFFER_H

#include <vector>
#include "../cymath/cymath_main.h"


namespace theta
{
  namespace buffer
  {
    class vertexBuffer2D 
  	{
      int size = 0;
      int[4] linked_Buffers;
      std::vector<cy::vector2<double>> vertexPositions;
      std::vector<double> ivertexRotations;
    }

    class vertexBuffer3D 
  	{
      int size = 0;
      int[4] linked_Buffers;
      std::vector<cy::vector3<double>> vertexPositions;
      std::vector<cy::vector3<double>> eulerRotations;
    }
  }

}
#endif //CYBERTOPIC_ENGINE_1_BUFFER_H
