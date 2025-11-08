#include <cassert>
#include <string>
#include <vix/ai/nn/Network.hpp>

using namespace vix::ai::nn;

int main()
{
    Network net;
    assert(net.num_layers() == 0);
    net.add_layer("Dense(16->32)");
    net.add_layer("Conv2D(k=3)");
    auto s = net.summary();
    assert(net.num_layers() == 2);
    assert(s.find("Network[2 layers]") != std::string::npos);
    (void)s; // silence warning in Release
    return 0;
}
