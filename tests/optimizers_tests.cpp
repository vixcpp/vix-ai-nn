#include <cassert>
#include <vix/ai/nn/Optimizers/Adam.hpp>
#include <vix/ai/nn/Optimizers/SGD.hpp>

using namespace vix::ai::nn::opt;

int main()
{
    Adam a;
    (void)a;
    SGD s;
    (void)s;
    assert(a.lr() == 0.001);
    assert(s.lr() == 0.01);
    return 0;
}
