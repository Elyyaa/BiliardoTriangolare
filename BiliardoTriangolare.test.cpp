#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BiliardoTriangolare.cpp"

#include "doctest.h"

TEST_CASE("Check bounces") {
  Line line;
  SUBCASE("Segmento orizzontale sopra 1") {
    const Parameters s = {0, 5, 1};
    Parameters t_0 = {M_PI_4, 0, 1};
    const auto t_1 = line.Bounce(s, t_0, -1);
    CHECK(t_1.teta == doctest::Approx(-M_PI_4));
    CHECK(t_1.q == doctest::Approx(10));
    CHECK(t_1.dir == 1);
  };
  SUBCASE("Segmento orizzontale sotto 1") {
    const Parameters s = {0, 5, 1};
    Parameters t_0 = {-M_PI_4, 0, 1};
    const auto t_1 = line.Bounce(s, t_0, 1);
    CHECK(t_1.teta == doctest::Approx(M_PI_4));
    CHECK(t_1.q == doctest::Approx(-10));
    CHECK(t_1.dir == 1);
  };
  SUBCASE("Segmento orizzontale sopra 2") {
    const Parameters s = {0, 5, 1};
    Parameters t_0 = {M_PI / 6, 4, 1};
    const auto t_1 = line.Bounce(s, t_0, -1);
    CHECK(t_1.teta == doctest::Approx(-M_PI / 6));
    CHECK(t_1.q == doctest::Approx(6));
    CHECK(t_1.dir == 1);
  };
  SUBCASE("Segmento orizzontale sotto 2") {
    const Parameters s = {0, 5, 1};
    Parameters t_0 = {-M_PI / 3, -3, 1};
    const auto t_1 = line.Bounce(s, t_0, 1);
    CHECK(t_1.teta == doctest::Approx(M_PI / 3));
    CHECK(t_1.q == doctest::Approx(-7));
    CHECK(t_1.dir == 1);
  };
  SUBCASE("Segmento 45 sopra 1") {
    const Parameters s = {M_PI_4, 5, 1};
    Parameters t_0 = {0, 4, 1};
    const auto t_1 = line.Bounce(s, t_0, -1);
    CHECK(t_1.teta == doctest::Approx(0));
    CHECK(t_1.q == doctest::Approx(-4));
    CHECK(t_1.dir == -1);
  };
  SUBCASE("Segmento 45 sotto 1") {
    const Parameters s = {M_PI_4, 5, 1};
    Parameters t_0 = {0, -3, 1};
    const auto t_1 = line.Bounce(s, t_0, 1);
    CHECK(t_1.teta == doctest::Approx(0));
    CHECK(t_1.q == doctest::Approx(3));
    CHECK(t_1.dir == -1);
  };
  SUBCASE("Segmento 45 sopra 2") {
    const Parameters s = {M_PI_4, 5, 1};
    Parameters t_0 = {M_PI / 5, 4, 1};
    const auto t_1 = line.Bounce(s, t_0, -1);
    CHECK(t_1.teta == doctest::Approx(M_PI / 3.3333));
    CHECK(t_1.q == doctest::Approx(3.62362));
    CHECK(t_1.dir == -1);
  };
  SUBCASE("Segmento 45 sotto 2") {
    const Parameters s = {M_PI_4, 5, 1};
    Parameters t_0 = {M_PI / 3, -7, 1};
    const auto t_1 = line.Bounce(s, t_0, 1);
    CHECK(t_1.teta == doctest::Approx(M_PI / 6));
    CHECK(t_1.q == doctest::Approx(-3.8453));
    CHECK(t_1.dir == -1);
  };
  SUBCASE("Segmento 90 sopra 1") {
    const Parameters s = {M_PI_2, 5, 1};
    Parameters t_0 = {0, 4, 1};
    const auto t_1 = line.Bounce(s, t_0, -1);
    CHECK(t_1.teta == doctest::Approx(0));
    CHECK(t_1.q == doctest::Approx(4));
    CHECK(t_1.dir == -1);
  };
  SUBCASE("Segmento 90 sotto 1") {
    const Parameters s = {M_PI_2, 5, 1};
    Parameters t_0 = {M_PI / 3, -3, 1};
    const auto t_1 = line.Bounce(s, t_0, 1);
    CHECK(t_1.teta == doctest::Approx(-M_PI / 3));
    CHECK(t_1.q == doctest::Approx(-3));
    CHECK(t_1.dir == -1);
  };
  SUBCASE("Segmento 90 sopra 2") {
    const Parameters s = {M_PI_2, 5, 1};
    Parameters t_0 = {M_PI / 5, 4, 1};
    const auto t_1 = line.Bounce(s, t_0, -1);
    CHECK(t_1.teta == doctest::Approx(-M_PI / 5));
    CHECK(t_1.q == doctest::Approx(4));
    CHECK(t_1.dir == -1);
  };
  SUBCASE("Segmento 90 sotto 2") {
    const Parameters s = {M_PI_2, 5, 1};
    Parameters t_0 = {-M_PI_4, -3, 1};
    const auto t_1 = line.Bounce(s, t_0, 1);
    CHECK(t_1.teta == doctest::Approx(M_PI_4));
    CHECK(t_1.q == doctest::Approx(-3));
    CHECK(t_1.dir == -1);
  };
  SUBCASE("Segmento obliquo sopra 1") {
    const Parameters s = {M_PI / 3, 7, 1};
    Parameters t_0 = {0, 4, 1};
    const auto t_1 = line.Bounce(s, t_0, -1);
    CHECK(t_1.teta == doctest::Approx(M_PI / 2.99999));
    CHECK(t_1.q == doctest::Approx(1));
    CHECK(t_1.dir == -1);
  };
  SUBCASE("Segmento obliquo sotto 1") {
    const Parameters s = {M_PI / 6, 5, 1};
    Parameters t_0 = {-M_PI / 12, -3, 1};
    const auto t_1 = line.Bounce(s, t_0, 1);
    CHECK(t_1.teta == doctest::Approx(M_PI / 2.39999));
    CHECK(t_1.q == doctest::Approx(-12.4641));
    CHECK(t_1.dir == 1);
  };
  SUBCASE("Segmento obliquo sopra 2") {
    const Parameters s = {M_PI / 3, 7, 1};
    Parameters t_0 = {M_PI / 2.99999, 1, -1};
    const auto t_1 = line.Bounce(s, t_0, -1);
    CHECK(t_1.teta == doctest::Approx(0));
    CHECK(t_1.q == doctest::Approx(4));
    CHECK(t_1.dir == -1);
  };
  SUBCASE("Segmento obliquo sotto 2") {
    const Parameters s = {M_PI / 6, 5, 1};
    Parameters t_0 = {M_PI / 2.39999, -12.4641, -1};
    const auto t_1 = line.Bounce(s, t_0, 1);
    CHECK(t_1.teta == doctest::Approx(-M_PI / 12));
    CHECK(t_1.q == doctest::Approx(-3));
    CHECK(t_1.dir == -1);
  };
};