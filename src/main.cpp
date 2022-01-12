#include <pybind11/pybind11.h>

class Simulate {
public:
    Simulate() {};
    Simulate(double, double);
    double _add();
    double _times();
    int say();
private:
    double _parameter1;
    double _parameter2;
};

Simulate::Simulate(double para1, double para2) :_parameter1(para1), _parameter2(para2) {}
double Simulate::_add() { return _parameter1 + _parameter2; }
double Simulate::_times() { return _parameter1 * _parameter2; }
int Simulate::say() { return 2; }

namespace py = pybind11;

PYBIND11_MODULE(classpybind, m) {
    m.doc() = "classpybind";

    py::class_<Simulate>(m, "Simulate")
        .def(py::init<double, double>())
        .def("add", &Simulate::_add)
        .def("times", &Simulate::_times)
        .def("say", &Simulate::say);
}
