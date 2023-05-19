#include <cmath>
#include <cstdio>
#ifndef BILIARDOTRIANGOLARE_CPP
#define BILIARDOTRIANGOLARE_CPP

struct Parameters {
  double teta;
  double q;
  double dir;
};

class Line {
  double teta;
  double dir;
  double q;

 public:
  Parameters Bounce(const Parameters s, Parameters t_0, double n) {
    if (-M_PI_2 <= n * t_0.teta && n * t_0.teta < 2 * s.teta - M_PI_2) {
      teta = n * (2 * s.teta - M_PI) - t_0.teta;
      dir = -1;
      q = ((t_0.q + n * s.q) * (n * tan(s.teta) - tan(teta)) /
           (n * tan(s.teta) - tan(t_0.teta))) -
          n * s.q;
    };
    if (n * t_0.teta == 2 * s.teta - M_PI_2) {
      teta = -t_0.teta;
      dir = -1;
      q = -t_0.q;
    };
    if (2 * s.teta - M_PI_2 < n * t_0.teta && n * t_0.teta < s.teta) {
      teta = n * 2 * s.teta - t_0.teta;
      dir = 1;
      q = ((t_0.q + n * s.q) * (n * tan(s.teta) - tan(teta)) /
           (n * tan(s.teta) - tan(t_0.teta))) -
          n * s.q;
    };
    if (s.teta < n * t_0.teta && n * t_0.teta <= M_PI_2) {
      teta = n * 2 * s.teta - t_0.teta;
      dir = -1;
      q = ((t_0.q + n * s.q) * (n * tan(s.teta) - tan(teta)) /
           (n * tan(s.teta) - tan(t_0.teta))) -
          n * s.q;
    };
    return Parameters{teta, q, dir};
  };
};

#endif