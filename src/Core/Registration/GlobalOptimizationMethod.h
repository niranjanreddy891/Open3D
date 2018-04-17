// ----------------------------------------------------------------------------
// -                        Open3D: www.open-3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Initial project was copyrighted (c) 2016-2018, www.open3d.org
// A fork of their project is avilable at www.github.com/Sahloul/Open3D-legacy
//
// Copyright (c) 2018, Hamdi Sahloul - www.open-3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#pragma once

#include <memory>

namespace three {

class PoseGraph;

class GlobalOptimizationOption;

class GlobalOptimizationConvergenceCriteria;

class GlobalOptimizationOption;

class GlobalOptimizationMethod
{
public:
    GlobalOptimizationMethod() {}
    virtual ~GlobalOptimizationMethod() {}

public:
    virtual void OptimizePoseGraph(
            PoseGraph &pose_graph,
            const GlobalOptimizationConvergenceCriteria &criteria,
            const GlobalOptimizationOption &option) const = 0;
};

class GlobalOptimizationGaussNewton : public GlobalOptimizationMethod
{
public:
    GlobalOptimizationGaussNewton() {}
    ~GlobalOptimizationGaussNewton() override {}

public:
    void OptimizePoseGraph(
            PoseGraph &pose_graph,
            const GlobalOptimizationConvergenceCriteria &criteria,
            const GlobalOptimizationOption &option) const override;
};

class GlobalOptimizationLevenbergMarquardt : public GlobalOptimizationMethod
{
public:
    GlobalOptimizationLevenbergMarquardt() {}
    ~GlobalOptimizationLevenbergMarquardt() override {}

public:
    void OptimizePoseGraph(
            PoseGraph &pose_graph,
            const GlobalOptimizationConvergenceCriteria &criteria,
            const GlobalOptimizationOption &option) const override;
};

}   // namespace three