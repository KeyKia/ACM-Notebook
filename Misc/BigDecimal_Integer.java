BigDecimal bd = new BigDecimal("123.3123",mc);//can be negatvie
BigDecimal bd1 = new BigDecimal("151.66");
MathContext mc = new MathContext(212);//number of digits
bd.setScale(31,BigDecimal.ROUND_DOWN);//number of digits of fraction
// all return a BigDecimal
bd.divide(bd1,55,BigDecimal.ROUND_DOWN);//because it may have inifinty fraction we define number of digits of it
bd.add(bd1,mc);
bd.subtract(bd1,mc);
bd.multiply(bd1,mc);
bd.pow(n,mc);
bd.abs();
BigDecimal valueOf(double)
//add & multiply & subtract can have mathcontext so do constructor
//------------------------------------------------------------------
BigInteger bi = new BigInteger("412");
BigInteger bi1 = new BigInteger("555");
//all returns a BigInteger
BigInteger valueOf(long)
bi.abs();
bi.add(bi1);
bi.multiply(bi1);
bi.subtract(bi1);
bi.divide(bi1);
bi.divide(bi1);
bi.remainder(bi1);
bi.modPow(bi1,mod);





