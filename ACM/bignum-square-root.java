import java.math.BigDecimal;
import java.math.MathContext;
import java.math.BigInteger;

/**
 *
 * @author Mike Stark
 *
 */
public class BigNum {

	private static MathContext CONTEXT = new MathContext(72);
	private BigDecimal x;

	public static void setPrecision( int precision ) {
		if (precision <= 0) {
			//throw new Exception("invalid precision: " + precision);
		}
		CONTEXT = new MathContext(precision);
	}

	public static BigDecimal sqrt( BigDecimal a, MathContext ctx ) {
		// Compute the initial guess from the value
		if (a.signum() < 0) {
			return BigDecimal.ZERO;
		}

		// Compute the initial guess from the value
		// Start by extracting the unscaled BigInteger of 'a'
		// Note that a = a0*10^(-s)
		BigInteger a0 = a.unscaledValue();
		int s = a.scale();

		// Shift 'a0' to the approximate range of 'int'
		// and convert to a 'double' (this is the approximate "mantissa")
		int m = a0.bitLength();
		int shift = ((m % 2 == 0) ? m - 50 : m - 49); // shift must be even!
		double mant = a0.shiftRight(shift).doubleValue();

		// Now a is approximately mant*2^(shift)*10^-s
		// we need 's' to be a multiple of 2
		if (s % 2 != 0) {
			s++;
			mant *= 10;
		}
		// The square root of a is approximately
		//   sqrt(mant)*2^((shift - m)/2)*10(-s/2)
		BigDecimal sqrt0 = new BigDecimal(Math.sqrt(mant), ctx);
		BigDecimal pow2;
		if (shift < 0)
			pow2 = (new BigDecimal(0.5, ctx)).pow(-shift/2);
		else
			pow2 = (new BigDecimal(2, ctx)).pow(shift/2);
		sqrt0 = sqrt0.multiply(pow2, ctx);
		sqrt0 = sqrt0.scaleByPowerOfTen(-s/2);

	  // ASSERT: 'sqrt0' is a good approximation to the square root of 'a'
		// Use Newton's Method to polish it

		// The number of iterations required should be bounded by
		// the base-two logarithm of the precision divided by the
		// digits of precision in the approximation (about 14)
		int n = (ctx.getPrecision() <= 14 ? 1 :
				  (int)Math.ceil(Math.log(ctx.getPrecision() - 14)/Math.log(2)) + 1);

		BigDecimal two = new BigDecimal(2, ctx);
		for (int k = 0; k < n; k++) {
						sqrt0 = sqrt0.subtract(sqrt0.multiply(sqrt0, ctx).
						subtract(a, ctx).divide(two.multiply(sqrt0, ctx), ctx),
					    ctx);
		}
		return sqrt0;
	}


	public static double log10Approx( BigDecimal x ) {
		int m = x.unscaledValue().bitLength();
		return m/Math.log10(2)*x.scale();
	}

	public static BigDecimal atan( BigDecimal x, MathContext ctx ) {

		BigDecimal sum0 = BigDecimal.ZERO;
		BigDecimal sum = x;
		BigDecimal prod = x;  // just copies the reference!
		BigDecimal sqr = x.multiply(x, ctx).negate();

		int k = 1;
		while (!sum.equals(sum0)) {
			k += 2;
			prod = prod.multiply(sqr, ctx);
			sum0 = sum;
			sum = sum.add(prod.divide(new BigDecimal(k, ctx), ctx), ctx);
			//System.out.println("\t" + sum);
		}

		return sum;
	}


	/*----------------------------------------------------------------------*/

	/**
	 * Default constructor: constructs this to have value 0, in the current
	 * precision.
	 */
	public BigNum() {
		x = new BigDecimal(0, CONTEXT);
	}

	/**
	 * Java <CODE>int</CODE> constructor: constructs this to have the given
	 * (integer) value, in the current precision.
	 * @param value value for this instance
	 */
	public BigNum( int value ) {
		x = new BigDecimal(value, CONTEXT);
	}

	/**
	 * Java <CODE>long</CODE> constructor: constructs this to have the given
	 * (integer) value, in the current precision.
	 * @param value value for this instance
	 */
	public BigNum( long value ) {
		x = new BigDecimal(value, CONTEXT);
	}

	/**
	 * Java <CODE>double</CODE> constructor: constructs this to have the
	 * given value, in the current precision.
	 * @param value value for this instance
	 */
	public BigNum( double value ) {
		x = new BigDecimal(value, CONTEXT);
	}

	/**
	 * Unscaled Java <CODE>BigInteger</CODE> constructor: constructs
	 * this to have the given (integer) value, in the current precision.
	 * The value of this may not include some trailing digits of
	 * <code>unscaledValue</code>
	 * if it has more digits than can be represented in the current
	 * precision.
	 * @param unscaledValue value for this instance
	 */
	public BigNum( BigInteger unscaledValue ) {
		x = new BigDecimal(unscaledValue, CONTEXT);
	}

	/**
	 * Scaled Java<CODE>BigInteger</CODE> constructor: constructs this
	 * to have the given (integer) value scaled by
	 * 10<sup>-<code>scale</code></sup>, in the current precision.
	 * The value of this may not include some trailing digits of
	 * <code>value</code>
	 * if it has more digits than can be represented in the current
	 * precision.
	 *
	 * @param value value for this instance
	 * @param scale scale exponent
	 */
	public BigNum( BigInteger value, int scale ) {
		x = new BigDecimal(value, scale, CONTEXT);
	}

	/**
	 * Java <code>String</code> constructor: constructs this
	 * to have the value expressed in text decimal notation in the
	 * <code>value</code> string, in the current precision
	 * The value of this may not include some trailing digits of
	 * <code>src</code>
	 * if it has more digits than can be represented in the current
	 * precision.
	 *
	 * 	@param src string containing the value
	 */
	public BigNum( String src ) {
		x = new BigDecimal(src, CONTEXT);
	}


	/**
	 * Java <code>BigDecimal</code> constructor: constructs this
	 * to have the specified value.
	 * @param value value for this instance
	 */
	public BigNum( BigDecimal value ) {
		x = new BigDecimal(value.unscaledValue(), value.scale());
	}

	/**
	 * Rational number (fraction) constructor: constructs this to
	 * have the
	 * @param numerator
	 * @param denominator
	 */
	public BigNum ( int numerator, int denominator ) {
		x = new BigDecimal(numerator).divide(new BigDecimal(denominator),
						CONTEXT);
	}

	public BigNum ( long numerator, long denominator ) {
		x = new BigDecimal(numerator).divide(new BigDecimal(denominator),
						CONTEXT);
	}

	public BigNum( BigInteger numerator, BigInteger denominator ) {
		x = new BigDecimal(numerator).divide(new BigDecimal(denominator),
						CONTEXT);

	}

	/* Accessors */
	public BigDecimal getBigDecimal() {
		return x;
	}


	/* BigDecimal Functionality */

	public BigNum abs() {
		return new BigNum(x.abs(CONTEXT));
	}

	public BigNum add( BigNum augend ) {
		return new BigNum(x.add(augend.x, CONTEXT));
	}

	public BigNum add( int n ) {
		return new BigNum(x.add(new BigDecimal(n), CONTEXT));
	}

	public BigNum add( double s ) {
		return new BigNum(x.add(new BigDecimal(s), CONTEXT));
	}


	public int compareTo( BigNum value ) {
		return x.compareTo(value.x);
	}

	public BigNum divide( BigNum divisor ) {
		return new BigNum(x.divide(divisor.x, CONTEXT));
	}

	public BigNum divide( int n ) {
		return new BigNum(x.divide(new BigDecimal(n), CONTEXT));
	}

	public BigNum divide( double s ) {
		return new BigNum(x.divide(new BigDecimal(s), CONTEXT));
	}


	public double doubleValue() {
		return x.doubleValue();
	}

	public boolean equals( BigNum value ) {
		return x.equals(value);
	}

	public int hashCode() {
		return x.hashCode();
	}

	public BigNum max( BigNum value ) {
		return new BigNum(x.max(value.x));
	}

	public BigNum min( BigNum value ) {
		return new BigNum(x.min(value.x));
	}

	public BigNum multiply( int n ) {
		return new BigNum(x.multiply(new BigDecimal(n), CONTEXT));
	}

	public BigNum multiply( double s ) {
		return new BigNum(x.multiply(new BigDecimal(s), CONTEXT));
	}

	public BigNum multiply( BigNum multiplicand ) {
		return new BigNum(x.multiply(multiplicand.x, CONTEXT));
	}

	public BigNum negate() {
		return new BigNum(x.negate(CONTEXT));
	}

	public BigNum pow( int n ) {
		return new BigNum(x.pow(n, CONTEXT));
	}

	public int precision() {
		return x.precision();
	}

	public int scale() {
		return x.scale();
	}

	public BigNum scaleByPowerOfTen( int n ) {
		return new BigNum(x.scaleByPowerOfTen(n));
	}

	public int signum() {
		return x.signum();
	}

	public BigNum subtract( BigNum subtrahend ) {
		return new BigNum(x.subtract(subtrahend.x, CONTEXT));
	}

	public BigNum subtract( int n ) {
		return new BigNum(x.subtract(new BigDecimal(n), CONTEXT));
	}

	public BigNum subtract( double s ) {
		return new BigNum(x.subtract(new BigDecimal(s), CONTEXT));
	}


	public BigNum ulp() {
		return new BigNum(x.ulp());
	}


	public String toString() {
		return x.toString();
	}


	/* New Stuff */
	public BigNum sqrt() {
		//return (BigNum)sqrt((BigDecimal)this, CONTEXT);
		return new BigNum(sqrt(x, CONTEXT));
	}

	public BigNum sqr() {
		return new BigNum(x.multiply(x, CONTEXT));
	}

	public boolean isZero() {
		return x.unscaledValue().equals(BigInteger.ZERO);
	}

	public boolean isSmall( double ulps ) {
		int cmp = x.abs(CONTEXT).compareTo(x.ulp()
					.multiply(new BigDecimal(ulps), CONTEXT));
		return (cmp <= 0);
	}

	public boolean isClose( BigNum value, double ulps ) {
		BigDecimal diff = x.subtract(value.x, CONTEXT).abs(CONTEXT);
		int cmp = diff.compareTo(x.ulp()
					.multiply(new BigDecimal(ulps), CONTEXT));
		return (cmp <= 0);
	}



	public static void main( String args[] ) {

		BigNum.setPrecision(72);
		System.out.println((new BigNum(2)).sqrt());
		System.exit(1);

		MathContext mc = new MathContext(72);
		//BigDecimal x = BigDecimal.ONE.divide(new BigDecimal(3, mc), mc);
		BigDecimal x = new BigDecimal(2, mc);
		BigDecimal sqrtx = sqrt(x, mc);
		BigDecimal sqr = sqrtx.multiply(sqrtx, mc);
		System.out.println(x);
		System.out.println(sqrtx);
		System.out.println(sqr);

		BigDecimal pi1 = atan(new BigDecimal(0.5), mc)
					.add(atan(BigDecimal.ONE.divide(new BigDecimal(3, mc), mc), mc), mc);
		pi1 = pi1.multiply(new BigDecimal(4, mc));
		System.out.println(pi1);
		//System.out.println(Math.atan(0.5));

		//double s = sqrt(2.0);
		//System.out.println(s + ", " + Math.sqrt(2));
	}
}
