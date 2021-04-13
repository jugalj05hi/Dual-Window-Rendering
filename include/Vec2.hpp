/*!
   \file "Vec2_h"
   \brief "This is a header file for the Vector2D class."
   \author "Raaghavv Devgon"
   \date "18"/"Feb"/"2021"
*/
#ifndef Vec2_h
#define Vec2_h
/** @class Vec2
 *  @brief Class to define a 2D vector.
 */
class Vec2{

  public :
          float x;/*!< X-coordinate */
          float y;/*!< Y-coordinate */
          /**
        * @brief <Default Constructor.>
        * @details <Default Constructor>
        */
          Vec2();
          /**
        * @brief <defines the postion of the vector on the 2D plane>
        * @param  <float> <coordinate>
        * @details <defines the Position of the Vector2D>
        */
          Vec2(float x,float y);
          /**
        * @brief <operator Overloading>
        * @param <Vec2> <rhs>
        * @details <operator Overloading to add a vector>
        */
          Vec2 operator+(Vec2 const& rhs);
          /**
        * @brief <operator Overloading>
        * @param <Vec2> <rhs>
        * @details <operator Overloading to add a vector>
        */
          Vec2 operator+=(Vec2 const& rhs);
          /**
        * @brief <operator Overloading>
        * @param <Vec2> <rhs>
        * @details <operator Overloading to mulitply a vector>
        */
          Vec2 operator*(float rhs);

};

#endif
