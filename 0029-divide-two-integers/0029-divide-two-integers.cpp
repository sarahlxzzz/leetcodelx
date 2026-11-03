class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        // Determine the sign of the result
        // True if the signs are different, meaning a negative result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both integers to long long to prevent overflow during manipulation
        long long absDividend = std::abs((long long)dividend);
        long long absDivisor = std::abs((long long)divisor);
        
        long long quotient = 0;

        // Perform fast division via bit-shifting
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;
            
            // Double the divisor until it exceeds the remaining dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the chunk from dividend and add the multiple to quotient
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        // Apply sign and cast back to 32-bit integer
        return negative ? -quotient : quotient;
    }
};