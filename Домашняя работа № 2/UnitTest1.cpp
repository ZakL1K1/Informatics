#include "pch.h"
#include "CppUnitTest.h"
#pragma once

inline bool isInside(double x, double y) {
    return (y >= 2.0) && (y <= x) && (y <= -x + 6.0);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AreaCalculationTests
{
    TEST_CLASS(IsInsideTests)
    {
    public:

        TEST_METHOD(VertexPoints)
        {
            Assert::IsTrue(isInside(2.0, 2.0)); 
            Assert::IsTrue(isInside(4.0, 2.0)); 
            Assert::IsTrue(isInside(3.0, 3.0)); 
        }

        TEST_METHOD(PointsInside)
        {
            Assert::IsTrue(isInside(3.0, 2.1)); 
            Assert::IsTrue(isInside(2.5, 2.4)); 
            Assert::IsTrue(isInside(3.5, 2.4)); 
            Assert::IsTrue(isInside(3.0, 2.8)); 
        }


        TEST_METHOD(PointsOutside)
        {
            Assert::IsFalse(isInside(3.0, 1.9)); 
            Assert::IsFalse(isInside(3.0, 3.2)); 
            Assert::IsFalse(isInside(1.5, 2.5)); 
            Assert::IsFalse(isInside(4.5, 2.5)); 
        }

        TEST_METHOD(BoundaryPoints)
        {
            Assert::IsTrue(isInside(2.5, 2.0)); 
            Assert::IsTrue(isInside(2.5, 2.5)); 
            Assert::IsTrue(isInside(3.5, 2.5)); 
        }

        TEST_METHOD(FarPoints)
        {
            Assert::IsFalse(isInside(100.0, 100.0));
            Assert::IsFalse(isInside(-100.0, -100.0));
            Assert::IsFalse(isInside(0.0, 0.0));
        }
    };
}
