#pragma once

#include <vector>
#include <memory>
#include <vector>

#include "IIntersectable.h"

#include <tuple>
#include <Eigen/Core>

class Scene
{
public:
    Scene();
    
    void Render();
    void AddSphere(const Eigen::Vector3f& center, float radius);

private:
    std::tuple<bool, float, IIntersectable*> Trace(const Eigen::Vector3f& origin, const Eigen::Vector3f& direction, const std::vector<std::unique_ptr<IIntersectable>>& sceneObjects);
    Eigen::Vector3f CastRay(const Eigen::Vector3f& origin, const Eigen::Vector3f& direction, const std::vector<std::unique_ptr<IIntersectable>>& sceneObjects);
    void exportToFile(const std::vector<Eigen::Vector3f>& pixels);
    
    int _width;
    int _height;
    float _fov;
    Eigen::Matrix4f _cameraToWorld;

    std::vector<std::unique_ptr<IIntersectable>> _sceneObjects;
};