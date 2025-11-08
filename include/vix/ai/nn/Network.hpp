#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace vix::ai::nn
{

    // v0 minimal: un "summary" textuel et un compteur de couches
    class Network
    {
    public:
        Network() = default;

        void add_layer(const std::string &kind) { layers_.push_back(kind); }

        std::size_t num_layers() const { return layers_.size(); }

        std::string summary() const
        {
            std::ostringstream oss;
            oss << "Network[" << layers_.size() << " layers]";
            if (!layers_.empty())
            {
                oss << " {";
                for (std::size_t i = 0; i < layers_.size(); ++i)
                {
                    if (i)
                        oss << ", ";
                    oss << layers_[i];
                }
                oss << "}";
            }
            return oss.str();
        }

    private:
        std::vector<std::string> layers_{};
    };

} // namespace vix::ai::nn
