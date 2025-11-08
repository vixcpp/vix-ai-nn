#include <cassert>
#include <vix/ai/nn/Layers/Dense.hpp>
#include <vix/ai/nn/Layers/Conv2D.hpp>
#include <vix/ai/nn/Layers/Transformer.hpp>

using namespace vix::ai::nn::layers;

int main()
{
    Dense d(16, 32);
    assert(d.in_features() == 16);
    assert(d.out_features() == 32);

    Conv2D c(5);
    assert(c.kernel() == 5);

    Transformer t(12);
    assert(t.heads() == 12);
    return 0;
}
