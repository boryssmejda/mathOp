import unittest
import mathOp
import os

class TestMathOp(unittest.TestCase):
    def setUp(self):
        self.mathOp_arithmetic = mathOp.Arithmetic('./libmathOp_c_api.so')

        self.MIN_32_BIT_INT = -(2**31)
        self.MAX_32_BIT_INT = 2**31 - 1

    def test_add(self):
        self.assertEqual(self.mathOp_arithmetic.add(0, 0), 0)
        self.assertEqual(self.mathOp_arithmetic.add(5, 5), 10)
        self.assertEqual(self.mathOp_arithmetic.add(20, 30), 50)
        self.assertEqual(self.mathOp_arithmetic.add(100, 110), 210)
        self.assertEqual(self.mathOp_arithmetic.add(1200, 1250), 2450)

        # Test for potential overflow/underflow
        self.assertRaises(ValueError, self.mathOp_arithmetic.add, self.MAX_32_BIT_INT, 1)
        self.assertRaises(ValueError, self.mathOp_arithmetic.add, self.MIN_32_BIT_INT, -1)


    def test_subtract(self):
        self.assertEqual(self.mathOp_arithmetic.subtract(0, 0), 0)
        self.assertEqual(self.mathOp_arithmetic.subtract(9, 5), 4)
        self.assertEqual(self.mathOp_arithmetic.subtract(30, 20), 10)
        self.assertEqual(self.mathOp_arithmetic.subtract(310, 100), 210)
        self.assertEqual(self.mathOp_arithmetic.subtract(2450, 1250), 1200)

        # Test for potential overflow/underflow
        self.assertRaises(ValueError, self.mathOp_arithmetic.subtract, self.MAX_32_BIT_INT, -1)
        self.assertRaises(ValueError, self.mathOp_arithmetic.subtract, self.MIN_32_BIT_INT, 1)


    def test_multiply(self):
        self.assertEqual(self.mathOp_arithmetic.multiply(0, 0), 0)
        self.assertEqual(self.mathOp_arithmetic.multiply(0, 1), 0)
        self.assertEqual(self.mathOp_arithmetic.multiply(9, 5), 45)
        self.assertEqual(self.mathOp_arithmetic.multiply(30, 20), 600)
        self.assertEqual(self.mathOp_arithmetic.multiply(310, 120), 37200)
        self.assertEqual(self.mathOp_arithmetic.multiply(2450, 1250), 3062500)

        # Test for potential overflow/underflow
        self.assertRaises(ValueError, self.mathOp_arithmetic.multiply, self.MAX_32_BIT_INT, 2)
        self.assertRaises(ValueError, self.mathOp_arithmetic.multiply, self.MIN_32_BIT_INT, 2)

    def test_divide(self):
        self.assertAlmostEqual(self.mathOp_arithmetic.divide(0, 1), 0)
        self.assertAlmostEqual(self.mathOp_arithmetic.divide(9, 5), 1.8)
        self.assertAlmostEqual(self.mathOp_arithmetic.divide(30, 20), 1.5)
        self.assertAlmostEqual(self.mathOp_arithmetic.divide(310, 120), 2.58333333333333)
        self.assertAlmostEqual(self.mathOp_arithmetic.divide(2450, 1250), 1.96)

        self.assertRaises(ValueError, self.mathOp_arithmetic.divide, 0, 0)
        self.assertRaises(ValueError, self.mathOp_arithmetic.divide, self.MAX_32_BIT_INT, 0)
        self.assertRaises(ValueError, self.mathOp_arithmetic.divide, self.MIN_32_BIT_INT, 0)


if __name__ == "__main__":
    unittest.main()