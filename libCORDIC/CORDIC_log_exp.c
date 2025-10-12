#include "../include/CORDIC.h"
#include "../include/CORDIC_tbls.h"

// inconsitancy when used on cmd line seprtly vs in chain exp $(log 4)= 1.000
// while b= log 4\n 4.00= exp b the second being correct I'm really not sure why
// but may cause issues must work on more latter and test with new sqr and sqrt
// functions z
const int le_shift[11] = {
    8,  //<<8
    4,  //<<4
    2,  //<<2
    1,  //<<1
    -1, // y+y>>1
    -2, // y+y>>2
    -3, // y+y>>3
    -4, // y+y>>4
    -5, // y+y>>5
    -6, // y+y>>6
    -7, // y+y>>7
};

const fix kz[11] = {
    5814564, // 5.5452
    2907282, // 2.7726
    1453641, // 1.3863
    726768,  // 0.6931
    425198,  // 0.4055
    233937,  // 0.2231
    123522,  // 0.1178
    63544,   // 0.0606
    32296,   // 0.0308
    16253,   // 0.0155
    8179     // 0.0078
};
const fix yst[9] = {0,       726817,  1453635, 2180452, 2907270,
                    3634087, 4360905, 5087722, 5814540};

inline fix k_shift(fix target, int shift) {
  fix t1, t2;
  t1 = target;
  t2 = target;
  if (0 < shift) {
    target = t1 << shift;
  } else {
    target = t2 + (t1 >> -shift);
  };
  return target;
}

fix CORDIC_expx(fix x) {
  fix y;
  int uoflg = 0;
  if (x < FIX_ONE) {
    x += 2911376;
    uoflg = 1;
  }
  y = FIX_ONE;
  for (int i = 0; i < K_LEN; i++) {
    if (x > kz[i]) {
      x = x - kz[i];
      y = k_shift(y, le_shift[i]);
    }
  }
  y = (uoflg == 1) ? y >> 4 : y;
  return y;
}

inline float CORDIC_exp(float ex) { return to_float(CORDIC_expx(to_fix(ex))); }

inline fix CORDIC_logx(fix x) {
  fix y;
  int shiftflg, i, uoflg;
  i = 0;
  shiftflg = 0;
  uoflg = 0;
  fix xx = x;
  if (x < FIX_ONE) {
    x = x << 4;
    uoflg = 1;
  }
  while (shiftflg < 1 && i < 9) {
    xx = x >> i;
    if (xx > FIX_ONE) {
      i++;
    } else {
      x = xx;
      y = yst[i];
      shiftflg = 1;
      printf("x %d,xx %d, y %d", x, xx, y);
    }
  }
  for (i = 0; i < K_LEN; i++) {
    xx = k_shift(x, le_shift[i]);
    if (xx < FIX_ONE) {
      x = xx;
      y -= kz[i];
    }
  }

  y -= (x >> 15);
  y = (uoflg == 1) ? y - LOG_OF_16 : y;
  return y;
}

inline float CORDIC_log(float ex) { return to_float(CORDIC_logx(to_fix(ex))); }
