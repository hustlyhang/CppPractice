#include <string>

class A {
  public:
    A(int x, int y, const std::string &name) : x(x), y(y), name(name) {
        if (x < 0 || y < 0)
            throw std::runtime_error("invalid coordination");
        // other stuff
    }

    A(int x, int y) : x(x), y(y), name("A") {
        if (x < 0 || y < 0)
            throw std::runtime_error("invalid coordination");
        // other stuff
    }

    A() : x(0), y(0), name("A") {
        // other stuff
    }

  private:
    int x;
    int y;
    std::string name;
};

class A {
  public:
    A(int x, int y, const std::string &name) { init(x, y, name); }

    A(int x, int y) { init(x, y, "A"); }

    A() { init(0, 0, "A"); }

  private:
    void init(int x, int y, const std::string &name) {
        if (x < 0 || y < 0)
            throw std::runtime_error("invalid coordination");
        this->x = x;
        this->y = y;

        if (name.empty())
            throw std::runtime_error("empty name");
        this->name = name;

        // other stuff
    }

  private:
    int x;
    int y;
    std::string name;
};

class A {
  public:
    A(int x, int y, const std::string &name) : x(x), y(y), name(name) {
        if (x < 0 || y < 0)
            throw std::runtime_error("invalid coordination");
        if (name.empty())
            throw std::runtime_error("empty name");
        // other stuff
    }

    A(int x, int y) : A(x, y, "A") {}

    A() : A(0, 0) {}

  private:
    int x;
    int y;
    std::string name;
};